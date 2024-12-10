
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "matrix_calc.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <assert.h>
    #include <math.h>
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


/* Line 189 of yacc.c  */
#line 117 "matrix_calc.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ELEMENT = 258,
     NAME = 259,
     FUNCTION = 260,
     ADD = 261,
     SUB = 262,
     MUL = 263,
     DIV = 264,
     COMMA = 265,
     LBRACKET = 266,
     RBRACKET = 267,
     SEMICOLON = 268,
     LC = 269,
     RC = 270,
     TRSNAPOSE = 271,
     EQUAL = 272,
     PRINT = 273
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 45 "matrix_calc.y"

    double fp; // float point
    char * str; // string
    Matrix * mat; // matrix



/* Line 214 of yacc.c  */
#line 179 "matrix_calc.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 191 "matrix_calc.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   38

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  19
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  26
/* YYNRULES -- Number of states.  */
#define YYNSTATES  46

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   273

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    15,    17,    21,
      24,    26,    30,    32,    36,    40,    44,    48,    50,    54,
      58,    60,    64,    67,    69,    74,    77
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      20,     0,    -1,    -1,    20,    21,    -1,    22,    13,    -1,
      23,    13,    -1,    23,    -1,    22,    -1,     4,    17,    27,
      -1,    18,    27,    -1,     3,    -1,    24,    10,     3,    -1,
      26,    -1,    25,    10,    26,    -1,    11,    24,    12,    -1,
      27,     6,    28,    -1,    27,     7,    28,    -1,    28,    -1,
      28,     8,    29,    -1,    28,     9,    29,    -1,    29,    -1,
      14,    27,    15,    -1,     7,    29,    -1,     4,    -1,     5,
      14,    27,    15,    -1,    29,    16,    -1,    11,    25,    12,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    67,    67,    69,    73,    74,    75,    76,    80,    86,
      93,    98,   111,   114,   138,   144,   147,   150,   156,   159,
     162,   167,   168,   176,   179,   183,   186
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ELEMENT", "NAME", "FUNCTION", "ADD",
  "SUB", "MUL", "DIV", "COMMA", "LBRACKET", "RBRACKET", "SEMICOLON", "LC",
  "RC", "TRSNAPOSE", "EQUAL", "PRINT", "$accept", "input", "line",
  "matrix_definition", "print_expr", "elements", "rows", "row", "expr",
  "term", "factor", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    19,    20,    20,    21,    21,    21,    21,    22,    23,
      24,    24,    25,    25,    26,    27,    27,    27,    28,    28,
      28,    29,    29,    29,    29,    29,    29
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     1,     1,     3,     2,
       1,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     2,     1,     4,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     3,     7,     6,     0,    23,
       0,     0,     0,     0,     9,    17,    20,     4,     5,     8,
       0,    22,     0,     0,    12,     0,     0,     0,     0,     0,
      25,     0,    10,     0,     0,    26,    21,    15,    16,    18,
      19,    24,     0,    14,    13,    11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     5,     6,     7,    33,    23,    24,    14,    15,
      16
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -15
static const yytype_int8 yypact[] =
{
     -15,     0,   -15,   -14,     3,   -15,    -8,    21,     3,   -15,
      -2,     3,    22,     3,    20,    23,    19,   -15,   -15,    20,
       3,    19,    33,    -1,   -15,     9,     3,     3,     3,     3,
     -15,    15,   -15,    13,    22,   -15,   -15,    23,    23,    19,
      19,   -15,    34,   -15,   -15,   -15
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -15,   -15,   -15,   -15,   -15,   -15,   -15,     4,    -7,     2,
      -9
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       2,    19,    21,     8,     3,    17,    25,     9,    10,    34,
      11,    35,    20,    31,    12,    26,    27,    13,     4,    39,
      40,    26,    27,    42,    36,    43,    26,    27,    37,    38,
      41,    28,    29,    22,    18,    30,    32,    45,    44
};

static const yytype_uint8 yycheck[] =
{
       0,     8,    11,    17,     4,    13,    13,     4,     5,    10,
       7,    12,    14,    20,    11,     6,     7,    14,    18,    28,
      29,     6,     7,    10,    15,    12,     6,     7,    26,    27,
      15,     8,     9,    11,    13,    16,     3,     3,    34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,     0,     4,    18,    21,    22,    23,    17,     4,
       5,     7,    11,    14,    27,    28,    29,    13,    13,    27,
      14,    29,    11,    25,    26,    27,     6,     7,     8,     9,
      16,    27,     3,    24,    10,    12,    15,    28,    28,    29,
      29,    15,    10,    12,    26,     3
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:

/* Line 1455 of yacc.c  */
#line 75 "matrix_calc.y"
    { print_semicolon_hint(); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 76 "matrix_calc.y"
    { print_semicolon_hint(); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 80 "matrix_calc.y"
    {
        register_matrix((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].mat));
    ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 86 "matrix_calc.y"
    {
        print_matrix((yyvsp[(2) - (2)].mat));
        printf("\n");
    ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 93 "matrix_calc.y"
    {
        // printf("Got element: %lf", $1);
        (yyval.mat) = malloc_matrix(1, 1);
        *(get_ele((yyval.mat), 0, 0)) = (yyvsp[(1) - (1)].fp);
      ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 98 "matrix_calc.y"
    {
        int new_length = (yyvsp[(1) - (3)].mat)->columns + 1;
        (yyval.mat) = malloc_matrix(1, new_length);
        for(int i = 0; i < new_length - 1; i++) {
            *(get_ele((yyval.mat), 0, i)) = *(get_ele((yyvsp[(1) - (3)].mat), 0, i));
            // printf("Copy ele %lf\n", *(get_ele($1, 0, i)));
        }
        *(get_ele((yyval.mat), 0, new_length - 1)) = (yyvsp[(3) - (3)].fp);
        free_matrix((yyvsp[(1) - (3)].mat));
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 111 "matrix_calc.y"
    {
        (yyval.mat) = (yyvsp[(1) - (1)].mat);
     ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 114 "matrix_calc.y"
    {
        if((yyvsp[(1) - (3)].mat)->columns != (yyvsp[(3) - (3)].mat)->columns) {
            yyerror("Rows must have the same number of columns.");
            _YYABORT;
        }
        int new_r = (yyvsp[(1) - (3)].mat)->rows + 1;
        int new_c = (yyvsp[(1) - (3)].mat)->columns;
        (yyval.mat) = malloc_matrix(new_r, new_c);
        for(int i = 0; i < (yyvsp[(1) - (3)].mat)->rows; i++)
            for(int j = 0; j < (yyvsp[(1) - (3)].mat)->columns; j++)
                *(get_ele((yyval.mat), i, j)) = *(get_ele((yyvsp[(1) - (3)].mat), i, j));

        assert((yyvsp[(3) - (3)].mat)->rows == 1);

        for(int j = 0; j < (yyvsp[(1) - (3)].mat)->columns; j++) {
            *(get_ele((yyval.mat), (yyvsp[(1) - (3)].mat)->rows, j)) = *(get_ele((yyvsp[(3) - (3)].mat), 0, j));
        }

        free_matrix((yyvsp[(1) - (3)].mat));
        free_matrix((yyvsp[(3) - (3)].mat));
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 138 "matrix_calc.y"
    {
        (yyval.mat) = (yyvsp[(2) - (3)].mat);
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 144 "matrix_calc.y"
    {
        (yyval.mat) = handle_function("add", (yyvsp[(1) - (3)].mat), (yyvsp[(3) - (3)].mat));
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 147 "matrix_calc.y"
    {
        (yyval.mat) = handle_function("sub", (yyvsp[(1) - (3)].mat), (yyvsp[(3) - (3)].mat));
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 150 "matrix_calc.y"
    {
        (yyval.mat) = (yyvsp[(1) - (1)].mat);
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 156 "matrix_calc.y"
    {
        (yyval.mat) = handle_function("mul", (yyvsp[(1) - (3)].mat), (yyvsp[(3) - (3)].mat));
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 159 "matrix_calc.y"
    {
        (yyval.mat) = handle_function("div", (yyvsp[(1) - (3)].mat), (yyvsp[(3) - (3)].mat));
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 162 "matrix_calc.y"
    { (yyval.mat) = (yyvsp[(1) - (1)].mat); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 167 "matrix_calc.y"
    { (yyval.mat) = (yyvsp[(2) - (3)].mat); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 168 "matrix_calc.y"
    {
        (yyval.mat) = (yyvsp[(2) - (2)].mat);
        for(int i = 0; i < (yyval.mat)->rows; i++) {
            for(int j = 0; j < (yyval.mat)->columns; j++) {
                *(get_ele((yyval.mat), i, j)) *= -1.0d;
            }
        }
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 176 "matrix_calc.y"
    {
        (yyval.mat) = find_matrix((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 179 "matrix_calc.y"
    {
        (yyval.mat) = handle_function((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].mat), NULL);
        free((yyvsp[(1) - (4)].str));
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 183 "matrix_calc.y"
    {
        (yyval.mat) = handle_function("trans", (yyvsp[(1) - (2)].mat), NULL);
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 186 "matrix_calc.y"
    {
        (yyval.mat) = (yyvsp[(2) - (3)].mat);
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 1625 "matrix_calc.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 192 "matrix_calc.y"


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
    printf("[");
    for(int i = 0; i < mat->rows; i++) {
        printf("%s", i == 0 ? "[" : " [");
        for(int j = 0; j < mat->columns; j++) {
            double x = *(get_ele(mat, i, j));
            if(fabs(x) < 1e-6) x = 0;
            printf("% 7.3lf", x);
            printf("%s", j == mat->columns - 1 ? "" : ", ");
        }
        printf("%s", i == mat->rows - 1 ? "]" : "],\n");
    }
    printf("]\n");
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
        int found = 0;

        for (int i = row; i < rows; i++) {
            if (fabs(*get_ele(temp, i, row)) > EPS) {
                if (i != row) {

                    for (int j = 0; j < cols; j++) {
                        swap_double(get_ele(temp, row, j), get_ele(temp, i, j));
                    }
                }
                found = 1;
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
            swap_double(get_ele(result, i, j), get_ele(mat, j, i));
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
        result = handle_matrix_add(mat0, mat1);
    } else if(strcmp("sub", operation_name) == 0) {
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
    fprintf(stderr, "Error: %s\n", s);
}
