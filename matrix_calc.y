%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <assert.h>
    #include <math.h>
    #include <stdbool.h>
    #include "matrix.h"

    #define N_MATRIX_MAX    100
    #define MSG_BUFFER_MAX  2000
    #define EPS             1E-9

    double * get_ele(Matrix * mat, int i, int j) {
        assert(i < mat->rows && j < mat->columns);
        return (mat->data + (i * mat->columns + j));
    }

    struct MatrixPair{
        char * name;
        Matrix * mat;
    } matrix_pair[N_MATRIX_MAX];

    int matrix_pair_ptr = 0;

    Matrix * malloc_matrix(int r, int c);
    void free_matrix(Matrix * mat);
    void register_matrix(char * name, Matrix * mat);
    void print_matrix(Matrix * mat);
    Matrix * handle_function(const char * operation_name, Matrix * mat0, Matrix * mat1);
    Matrix * find_matrix(char * name);
    void yyerror(const char *s);
    char msg[MSG_BUFFER_MAX];

    #define _YYABORT exit(-1)

    void print_semicolon_hint() {
        yyerror("I think u forget the ';' at the end of line. :)");
        _YYABORT;
    }

    int yylex();
%}


%union {
    double fp; // float point
    char * str; // string
    Matrix * mat; // matrix
}

%token <fp> ELEMENT
%token <str> NAME
%token <str> FUNCTION

%token ADD SUB MUL DIV
%token COMMA LBRACKET RBRACKET SEMICOLON LC RC TRSNAPOSE EQUAL PRINT

%type <mat> elements row rows expr term factor

%right SUB
%right TRSNAPOSE

%debug

%%

input:
    /* only for null input */
    | input line
;

line:
      matrix_definition SEMICOLON
    | print_expr SEMICOLON
    | print_expr { print_semicolon_hint(); }
    | matrix_definition { print_semicolon_hint(); }
;

matrix_definition:
    NAME EQUAL expr {
        register_matrix($1, $3);
    }
;

print_expr:
    PRINT expr {
        print_matrix($2);
        printf("\n");
    }
;

elements: // a row of number like `1, 2, 3, 4`
      ELEMENT {
        // printf("Got element: %lf", $1);
        $$ = malloc_matrix(1, 1);
        *(get_ele($$, 0, 0)) = $1;
      }
    | elements COMMA ELEMENT {
        int new_length = $1->columns + 1;
        $$ = malloc_matrix(1, new_length);
        for(int i = 0; i < new_length - 1; i++) {
            *(get_ele($$, 0, i)) = *(get_ele($1, 0, i));
            // printf("Copy ele %lf\n", *(get_ele($1, 0, i)));
        }
        *(get_ele($$, 0, new_length - 1)) = $3;
        free_matrix($1);
    }
;

rows:
     row {
        $$ = $1;
     }
    | rows COMMA row {
        if($1->columns != $3->columns) {
            yyerror("Rows must have the same number of columns.");
            _YYABORT;
        }
        int new_r = $1->rows + 1;
        int new_c = $1->columns;
        $$ = malloc_matrix(new_r, new_c);
        for(int i = 0; i < $1->rows; i++)
            for(int j = 0; j < $1->columns; j++)
                *(get_ele($$, i, j)) = *(get_ele($1, i, j));

        assert($3->rows == 1);

        for(int j = 0; j < $1->columns; j++) {
            *(get_ele($$, $1->rows, j)) = *(get_ele($3, 0, j));
        }

        free_matrix($1);
        free_matrix($3);
    }
;

row:
     LBRACKET elements RBRACKET {
        $$ = $2;
    }
;

expr:
    expr ADD term {
        $$ = handle_function("add", $1, $3);
    }
    | expr SUB term {
        $$ = handle_function("sub", $1, $3);
    }
    | term {
        $$ = $1;
    }
;

term:
    term MUL factor {
        $$ = handle_function("mul", $1, $3);
    }
    | term DIV factor {
        $$ = handle_function("div", $1, $3);
    }
    | factor { $$ = $1; }
;


factor:
    LC expr RC { $$ = $2; }
    | SUB factor %prec SUB {
        $$ = $2;
        for(int i = 0; i < $$->rows; i++) {
            for(int j = 0; j < $$->columns; j++) {
                *(get_ele($$, i, j)) *= -1.0d;
            }
        }
    }
    | NAME {
        $$ = find_matrix($1);
    }
    | FUNCTION LC expr RC {
        $$ = handle_function($1, $3, NULL);
        free($1);
    }
    | factor TRSNAPOSE %prec TRSNAPOSE {
        $$ = handle_function("trans", $1, NULL);
    }
    | LBRACKET rows RBRACKET {
        $$ = $2;
    }
;


%%

Matrix * malloc_matrix(int r, int c) {
    // printf("Malloc [%d x %d]\n", r, c);
    Matrix * new_mat = (Matrix *)malloc(sizeof(Matrix));
    new_mat->rows = r;
    new_mat->columns = c;
    new_mat->data = (double *)malloc(sizeof(double) * (r * c));
    return new_mat;
}

void free_matrix(Matrix * mat) {
    free(mat->data);
    free(mat);
}

void register_matrix(char * name, Matrix * mat) {
    int exist = 0;
    for(int i = 0; i < matrix_pair_ptr; i++) {
        if(strcmp(matrix_pair[i].name, name) == 0) {
            matrix_pair[i].mat = mat;
            exist = 1;
        }
    }
    if(!exist) {
        matrix_pair[matrix_pair_ptr].name = name;
        matrix_pair[matrix_pair_ptr].mat = mat;
        matrix_pair_ptr++;
    }
}

void print_matrix(Matrix * mat) {
    printf("\033[1;34m[\033[0m");
    for(int i = 0; i < mat->rows; i++) {
        printf("%s", i == 0 ? "\033[34m[\033[0m" : " \033[34m[\033[0m");
        for(int j = 0; j < mat->columns; j++) {
            double x = *(get_ele(mat, i, j));
            if(fabs(x) < 1e-6) x = 0;
            printf("\033[1;32m% 7.3lf\033[0m", x);
            printf("\033[35m%s\033[0m", j == mat->columns - 1 ? "" : ", ");
        }
        printf("%s", i == mat->rows - 1 ? "\033[34m]\033[0m" : "\033[34m]\033[0m\033[35m,\033[0m\n");
    }
    printf("\033[1;34m]\033[0m\n");
}

Matrix * find_matrix(char * name) {
    for(int i = 0; i < matrix_pair_ptr; i++) {
        if(strcmp(matrix_pair[i].name, name) == 0) {
            return matrix_pair[i].mat;
        }
    }
    sprintf(msg, "Matrix named %s not defined.", name);
    yyerror(msg);
    _YYABORT;
}

void assert_matrix_same_size(Matrix * mat0, Matrix * mat1) {
    if(mat0->rows != mat1->rows || mat0->columns != mat1->columns) {
        sprintf(msg, "(%d x %d) != (%d x %d), these two matrixs can not be added.",
                mat0->rows, mat0->columns, mat1->rows, mat1->columns);
        yyerror(msg);
        _YYABORT;
    }
}

Matrix * handle_matrix_add(Matrix * mat0, Matrix * mat1) {
    assert_matrix_same_size(mat0, mat1);
    Matrix * result = malloc_matrix(mat0->rows, mat0->columns);
    for(int i = 0; i < mat0->rows; i++) {
        for(int j = 0; j < mat0->columns; j++) {
            *(get_ele(result, i, j)) = *(get_ele(mat0, i, j)) + *(get_ele(mat1, i, j));
        }
    }
    return result;
}

Matrix * handle_matrix_sub(Matrix * mat0, Matrix * mat1) {
    assert_matrix_same_size(mat0, mat1);
    Matrix * result = malloc_matrix(mat0->rows, mat0->columns);
    for(int i = 0; i < mat0->rows; i++) {
        for(int j = 0; j < mat0->columns; j++) {
            *(get_ele(result, i, j)) = *(get_ele(mat0, i, j)) - *(get_ele(mat1, i, j));
        }
    }
    return result;
}

void swap_double(double * a, double * b) { double t = *a; *a = *b; *b = t; }

Matrix * matrix_gauss(Matrix * raw_mat) {
    if(raw_mat->rows != raw_mat->columns){
        sprintf(msg, "Matrix is not square row: %d != column: %d.\n", raw_mat->rows, raw_mat->columns);
        yyerror(msg);
        _YYABORT;
    }

    int n = raw_mat->rows;

    Matrix * mat = malloc_matrix(n, n << 1);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            *get_ele(mat, i, j) = *get_ele(raw_mat, i, j);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i == j) *get_ele(mat, i, j + n) = 1.0d;
            else       *get_ele(mat, i, j + n) = 0.0d;

    int valid = 1;

    for (int i = 0; i < n; i++) {
        // printf("i = %d\n", i);
        // print_matrix(mat);
        int k = i;
        for (int j = i + 1; j < n; j++)
            if (fabs(*get_ele(mat, j, i)) > fabs(*get_ele(mat, k, i))) k = j;

        if (fabs(*get_ele(mat, k, i)) < EPS) {
            valid = 0;
            break;
        }

        for(int j = 0; j < (n << 1); j++)
            swap_double(get_ele(mat, i, j), get_ele(mat, k, j));

        double x = *get_ele(mat, i, i);
        for (int j = i; j < (n << 1); j++) *get_ele(mat, i, j) /= x;

        // printf("iii = %d\n", i);
        // print_matrix(mat);

        for (int j = 0; j < n; j++) {
            // printf("FLAG1 i = %d, j = %d, abs_mat= %.2lf\n", i, j, fabs(*get_ele(mat, j, i)));
            if (j != i && fabs(*get_ele(mat, j, i)) > EPS) {
                x = *get_ele(mat, j, i);

                // printf("x = %.3lf j = %d i = %d\n", x, j, i);

                for (int k = i; k < (n << 1); ++k)
                    *get_ele(mat, j, k) -= (*get_ele(mat, i, k)) * x;
            }
        }
    }
    if(!valid) {
        sprintf(msg, "The matrix do not have inv. matrix: ");
        yyerror(msg);
        print_matrix(raw_mat);
        _YYABORT;
    }
    // printf("inv matrix: raw matrix: \n");
    // print_matrix(raw_mat);
    // printf("inverted matrix:\n");
    // print_matrix(mat);
    return mat;
}

Matrix * handle_matrix_inv(Matrix * mat) {
    Matrix * gaussed_matrix = matrix_gauss(mat);
    int n = mat->rows;
    Matrix * result = malloc_matrix(n, n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            *get_ele(result, i, j) = *get_ele(gaussed_matrix, i, j + n);
    return result;
}


Matrix * handle_matrix_mul(Matrix * mat0, Matrix * mat1) {
    if(mat0->columns != mat1->rows) {
        sprintf(msg, "(%d x %d) x (%d x %d), %d != %d. these two matrixs can not be multiplied.",
                mat0->rows, mat0->columns, mat1->rows, mat1->columns, mat0->columns, mat1->rows);
        yyerror(msg);
        _YYABORT;
    }
    Matrix * result = malloc_matrix(mat0->rows, mat1->columns);
    int inner = mat0->columns;
    for(int i = 0; i < mat0->rows; i++) {
        for(int j = 0; j < mat1->columns; j++) {
            *get_ele(result, i, j) = 0.0d;
            for(int k = 0; k < inner; k++) {
                *get_ele(result, i, j) += (*get_ele(mat0, i, k)) * (*get_ele(mat1, k, j));
            }
        }
    }
    return result;
}



//WYS Segment

Matrix * handle_matrix_det(Matrix * mat) {
    if(mat->rows != mat->columns){
        sprintf(msg, "Matrix is not square row: %d != column: %d.\n", mat->rows, mat->columns);
        yyerror(msg);
        _YYABORT;
    }

    int n = mat->rows;
    Matrix * temp = malloc_matrix(n, n);
    Matrix * result = malloc_matrix(1, 1);
    *get_ele(result, 0, 0) = 1.0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            *get_ele(temp, i, j) = *get_ele(mat, i, j);

    for (int i = 0; i < n; i++) {
        if (fabs(*get_ele(temp, i, i)) < EPS) {
            int row = i + 1;
            while (row < n && fabs(*get_ele(temp, row, i)) < EPS) row++;
            if (row == n) {
                *get_ele(result, 0, 0) = 0.0;
                free_matrix(temp);
                return result;
            }
            for (int j = 0; j < n; j++)
                swap_double(get_ele(temp, i, j), get_ele(temp, row, j));
            *get_ele(result, 0, 0) *= -1;
        }
        for (int j = i + 1; j < n; j++) {
            double f = *get_ele(temp, j, i) / *get_ele(temp, i, i);
            for (int k = i; k < n; k++)
                *get_ele(temp, j, k) -= f * *get_ele(temp, i, k);
        }
        *get_ele(result, 0, 0) *= *get_ele(temp, i, i);
    }

    free_matrix(temp);
    return result;
}


Matrix* handle_matrix_rank(Matrix* mat) {
    int rank = 0;
    int rows = mat->rows;
    int cols = mat->columns;
    Matrix* temp = malloc_matrix(rows, cols);
    Matrix* result = malloc_matrix(1, 1);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            *get_ele(temp, i, j) = *get_ele(mat, i, j);

    for (int row = 0; row < rows; row++) {
        bool found = false;

        for (int i = row; i < rows; i++) {
            if (fabs(*get_ele(temp, i, row)) > EPS) {
                if (i != row) {

                    for (int j = 0; j < cols; j++) {
                        swap_double(get_ele(temp, row, j), get_ele(temp, i, j));
                    }
                }
                found = true;
                break;
            }
        }

        if (!found) {
            continue;
        }

        double pivot = *get_ele(temp, row, row);
        for (int j = 0; j < cols; j++) {
            *get_ele(temp, row, j) /= pivot;
        }

        for (int i = 0; i < rows; i++) {
            if (i != row) {
                double factor = *get_ele(temp, i, row);
                for (int j = 0; j < cols; j++) {
                    *get_ele(temp, i, j) -= factor * *get_ele(temp, row, j);
                }
            }
        }

        rank++;
    }

    free_matrix(temp);
    *get_ele(result, 0, 0) = rank;
    return result;
}


Matrix* handle_matrix_eigval(Matrix* mat) {
    if(mat->rows != mat->columns){
        sprintf(msg, "Matrix is not square row: %d != column: %d.\n", mat->rows, mat->columns);
        yyerror(msg);
        _YYABORT;
    }

    int n = mat->rows;
    Matrix* temp = malloc_matrix(n, 1);
    int eigval_index = 0;

    double lambda_min = -100.0, lambda_max = 100.0;
    double step = 0.01;

    for (double lambda = lambda_min; lambda <= lambda_max; lambda += step) {
        Matrix* detmat = malloc_matrix(n, n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                *get_ele(detmat, i, j) = *get_ele(mat, i, j);
                if (i == j) {
                    *get_ele(detmat, i, j) -= lambda;
                }
            }
        }

        Matrix* det_result = handle_matrix_det(detmat);
        double det_val = *get_ele(det_result, 0, 0);
        free_matrix(detmat);
        free_matrix(det_result);

        if (fabs(det_val) < EPS) {
            *get_ele(temp, eigval_index, 0) = lambda;
            eigval_index++;

            if (eigval_index == n) {
                break;
            }
        }
    }

    Matrix* result = malloc_matrix(eigval_index, 1);
    for (int i = 0; i < eigval_index; i++) {
        *get_ele(result, i, 0) = *get_ele(temp, i, 0);
    }

    free_matrix(temp);
    return result;
}


Matrix* handle_matrix_eigvec(Matrix* mat) {
    if(mat->rows != mat->columns){
        sprintf(msg, "Matrix is not square row: %d != column: %d.\n", mat->rows, mat->columns);
        yyerror(msg);
        _YYABORT;
    }

    int n = mat->rows;
    int eigval_index = 0;

    double lambda_min = -100.0, lambda_max = 100.0;
    double step = 0.01;

    Matrix* temp = malloc_matrix(n, n);

    for (double lambda = lambda_min; lambda <= lambda_max; lambda += step) {
        Matrix* detmat = malloc_matrix(n, n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                *get_ele(detmat, i, j) = *get_ele(mat, i, j);
                if (i == j) {
                    *get_ele(detmat, i, j) -= lambda;
                }
            }
        }
        Matrix* det_result = handle_matrix_det(detmat);
        double det_val = *get_ele(det_result, 0, 0);
        free_matrix(detmat);
        free_matrix(det_result);

        if (fabs(det_val) < EPS) {

            Matrix* aug_matrix = malloc_matrix(n, n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    *get_ele(aug_matrix, i, j) = *get_ele(mat, i, j);
                    if (i == j) {
                        *get_ele(aug_matrix, i, j) -= lambda;
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                int first_nonzero = -1;
                for (int j = 0; j < n; j++) {
                    if (fabs(*get_ele(aug_matrix, i, j)) > EPS) {
                        first_nonzero = j;
                        break;
                    }
                }
                if (first_nonzero == -1) continue;

                double factor = *get_ele(aug_matrix, i, first_nonzero);
                for (int j = 0; j < n; j++) {
                    *get_ele(aug_matrix, i, j) /= factor;
                }

                for (int k = 0; k < n; k++) {
                    if (k == i) continue;
                    double coef = *get_ele(aug_matrix, k, first_nonzero);
                    for (int j = 0; j < n; j++) {
                        *get_ele(aug_matrix, k, j) -= coef * *get_ele(aug_matrix, i, j);
                    }
                }
            }

            Matrix* eigvec = malloc_matrix(n, 1);
            for (int i = 0; i < n; i++) {
                *get_ele(eigvec, i, 0) = 1.0;
            }
            for (int i = 0; i < n; i++) {
                int first_nonzero = -1;
                for (int j = 0; j < n; j++) {
                    if (fabs(*get_ele(aug_matrix, i, j)) > EPS) {
                        first_nonzero = j;
                        break;
                    }
                }
                if (first_nonzero == -1) continue;

                double sum = 0.0;
                for (int j = first_nonzero + 1; j < n; j++) {
                    sum += *get_ele(aug_matrix, i, j) * *get_ele(eigvec, j, 0);
                }
                *get_ele(eigvec, first_nonzero, 0) = -sum;
            }

            for (int i = 0; i < n; i++) {
                *get_ele(temp, eigval_index, i) = *get_ele(eigvec, i, 0);
            }

            free_matrix(aug_matrix);
            free_matrix(eigvec);

            eigval_index++;
            if (eigval_index == n) {
                break;
            }
        }
    }

    Matrix* result = malloc_matrix(eigval_index, n);
    for (int i = 0; i < eigval_index; i++) {
        for (int j = 0; j < n; j++) {
            *get_ele(result, i, j) = *get_ele(temp, i, j);
        }
    }

    free_matrix(temp);
    return result;
}


Matrix * handle_matrix_trans(Matrix * mat) {
    Matrix * result = malloc_matrix(mat->columns, mat->rows);
    for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
            *get_ele(result, i, j) = *get_ele(mat, j, i);
        }
    }
    return result;
}

// Segment End



Matrix * handle_function(const char * operation_name, Matrix * mat0, Matrix * mat1) {
    // 1. 单目运算 （参数只有一个矩阵）
    // 对于 det / r(求 rank) / eigval(特征值) 返回一个 1x1 的矩阵。
    // 对于 inv / eigvec 返回一个合适大小的矩阵。

    // 2. 双目运算 （参数有两个矩阵）
    // add / sub / mul / div

    // u can define sperate function to impl. each operator as u wish :).
    // DO NOT change the content of original matrix `mat0` and `mat1`.

    Matrix * result = NULL; // use `malloc_matrix` to create.

    if(strcmp("det", operation_name) == 0) {
        result = handle_matrix_det(mat0);
    } else if(strcmp("r", operation_name) == 0) {
        result = handle_matrix_rank(mat0);
    } else if(strcmp("eigval", operation_name) == 0) {
        result = handle_matrix_eigval(mat0);
    } else if(strcmp("inv", operation_name) == 0) {
        result = handle_matrix_inv(mat0);
    } else if(strcmp("eigvec", operation_name) == 0) {
        result = handle_matrix_eigvec(mat0);
    } else if(strcmp("trans", operation_name) == 0) {
        result = handle_matrix_trans(mat0);
    } else if(strcmp("add", operation_name) == 0) {
        // example by ShuYuMo.
        result = handle_matrix_add(mat0, mat1);
    } else if(strcmp("sub", operation_name) == 0) {
        // example by ShuYuMo.
        result = handle_matrix_sub(mat0, mat1);
    } else if(strcmp("mul", operation_name) == 0) {
        result = handle_matrix_mul(mat0, mat1);
    } else if(strcmp("div", operation_name) == 0) {
        return handle_function("mul", mat0, handle_function("inv", mat1, NULL));
    } else {
        sprintf(msg, "Unknow operator name: %s.", operation_name);
        yyerror(msg);
        _YYABORT;
    }

    return result;
}

int main() {
    // yydebug = 1;
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "\033[7;31mError:\033[0m \033[1;31m%s\n\033[0m\n", s);
}