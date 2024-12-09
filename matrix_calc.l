%{
    #include <string.h>
    #include "matrix.h"
    #include "matrix_calc.tab.h"
%}

%%
"PRINT"                                         { return PRINT; }
[+-]?[0-9]+(\.[0-9]*)?([eE][+-]?[0-9]+)?        { yylval.fp = atof(yytext); return ELEMENT; }
[Mm][0-9]+                                      { yylval.str = strdup(yytext); return NAME; }
("r"|"det"|"eigval"|"inv"|"eigvec")             { yylval.str = strdup(yytext); return FUNCTION; }
\(                                              { return LC; }
\)                                              { return RC; }
"'"                                             { return TRSNAPOSE; }
"+"                                             { return ADD; }
"-"                                             { return SUB; }
"*"                                             { return MUL; }
"/"                                             { return DIV; }
"["                                             { return LBRACKET; }
"]"                                             { return RBRACKET; }
","                                             { return COMMA; }
";"                                             { return SEMICOLON; }
"="                                             { return EQUAL; }
[ \t\n]+                                        ;
.                                               { printf("Unknow token string: %s.\n", yytext);
                                                  return yytext[0]; }

%%

int yywrap() {
    return 1;
}