#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 6 "hw3.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboltable.h"
#include "type.h"
char output[300000];

extern char* yytext;
extern int lineCount;
extern char lineBuffer[50000];
char   *install_symbol();
/*void mstrcpy(char * s1, char* s2);*/
char* mstrcpy(char* s2);
int init_index = 0;
int now_reg = 0;
int expr_stack_offset;
int expr_temp_offset;
int needed_space = 0;
int reg[11] = {0};
int labelCount = 0;
int labelIndex[1000] = {0};
int claimed_label;
FILE* f_asm ;

#define EXPR_LOAD \
    int r1 , r2; \
    r1 =load_expr(o1,0); \
    if(r1==1){ \
     r1 = 0; \
    } \
    else{ \
     r1 = -o1; \
    } \
    r2= load_expr(o3,1);\
    if(r2==1){ \
     r2 = 1; \
    } \
    else{ \
     r2 = -o3; \
    }

#line 51 "hw3.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { 
         int       ival ;
         char      cval ;
         char      * sval;
         double     dval;
	 int	    bval;
         lit_type   lit;
     
       } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 79 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define IDEN 257
#define STRING_LIT 258
#define INT_LIT 259
#define BOOL_LIT 260
#define INT 261
#define DOUBLE 262
#define BOOL 263
#define CHAR 264
#define VOID 265
#define STRUCT 266
#define CONST 267
#define SWITCH 268
#define CASE 269
#define DEFAULT 270
#define IF 271
#define ELSE 272
#define FOR 273
#define WHILE 274
#define DO 275
#define RETURN 276
#define CONTINUE 277
#define BREAK 278
#define NUL 279
#define TRUE 280
#define FALSE 281
#define PLUSPLUS 282
#define MINUSMINUS 283
#define ANDAND 284
#define OROR 285
#define GE 286
#define LE 287
#define EQUAL 288
#define NOTEQUAL 289
#define NOT 290
#define CHAR_LIT 291
#define DOUBLE_LIT 292
#define HIGH 293
#define LOW 294
#define DIGITAL_WRITE 295
#define DELAY 296
#define UMINUS 297
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    0,    5,    5,   13,   13,   15,   15,
   15,   15,   17,   17,   17,   17,   17,   17,   17,   17,
   18,   18,    4,   12,   12,   21,   21,   21,   21,   21,
   23,   23,   24,   24,   25,   25,   26,   26,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,   28,
   28,   28,   28,   28,   28,   28,   28,   28,   28,   28,
   28,   28,   28,   28,   28,   28,   28,   28,   28,   29,
   29,   30,   30,   32,   31,   31,   31,   31,   31,   31,
   31,   31,   31,   31,   35,   36,   37,    9,   10,   39,
   10,   40,   41,    8,    8,   34,   33,   42,   42,   44,
   44,   43,   43,   11,   11,   22,   22,   38,   27,   27,
   45,   45,   46,   46,   47,   47,   48,    3,   20,   16,
   16,   49,   49,   50,   50,   19,   19,   51,   14,   14,
   52,    6,    6,    6,    6,    1,    1,    1,    1,    1,
   53,    7,   54,    7,
};
static const short yylen[] = {                            2,
    2,    3,    1,    2,    2,    1,    2,    1,    6,    6,
    3,    4,    3,    4,    5,    4,    2,    1,    3,    2,
    4,    2,    2,    2,    1,    6,    6,    1,    3,    4,
    0,    1,    2,    1,    3,    4,    0,    1,    1,    1,
    2,    2,    4,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    2,    3,    3,    2,    3,    1,
    1,    2,    2,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    2,    3,    3,    2,    3,    0,
    1,    2,    1,    0,    5,    1,    1,    1,    1,    1,
    5,    3,    2,    2,    0,    0,    0,    8,    1,    0,
    4,    0,    0,    7,    7,    9,    8,    2,    1,    4,
    4,    0,    3,    6,    6,    6,    6,    4,    0,    1,
    3,    1,    0,    1,    3,    1,    0,    3,    4,    0,
    1,    3,    1,    3,    2,    2,    1,    3,    2,    1,
    3,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    0,    8,    0,    6,
};
static const short yydefred[] = {                         0,
  142,  143,  145,  144,    0,    0,    0,    0,    0,    0,
    8,    0,    0,    0,    0,    0,    0,    0,    0,   25,
   28,    0,    7,    0,    0,    0,    0,  127,    0,   17,
    0,  137,   11,    0,    0,    0,    0,    0,   24,    0,
    0,    0,    0,  133,    0,   22,   12,    0,    0,    0,
    0,    0,   19,  136,    0,    0,    0,    0,   29,    0,
    0,    0,  150,  147,  149,  146,  148,   23,    0,    0,
    0,    0,    0,    0,   39,    0,    0,  138,    0,   14,
    0,    0,   30,    0,    0,   10,    0,  115,  132,   21,
    9,  114,    0,    0,    0,  140,    0,   58,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   41,   42,    0,    0,    0,    0,   60,    0,
    0,    0,    0,   15,    0,    0,    0,    0,    0,    0,
   34,    0,    0,    0,    0,  139,   59,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   46,   47,   48,
    0,   78,    0,   62,   63,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  129,    0,
   27,  117,   26,  116,    0,    0,    0,    0,    0,   95,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   86,
   88,   87,    0,    0,   83,   89,   90,   33,   43,    0,
  141,   79,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   66,   67,   68,    0,    0,   35,    0,    0,
    0,    0,  102,    0,    0,   94,   93,  151,  153,   84,
  118,   82,    0,   36,    0,    0,    0,    0,    0,    0,
    0,   92,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   91,    0,    0,    0,    0,    0,
    0,    0,   85,    0,    0,  109,   97,    0,    0,    0,
    0,  154,    0,    0,    0,    0,  108,    0,    0,  104,
  105,    0,    0,    0,    0,  107,   98,    0,    0,  152,
  111,  110,  113,  100,  106,    0,  101,
};
static const short yydgoto[] = {                          7,
   75,  238,   30,   46,   77,   41,  190,  191,  192,  287,
    9,   19,   10,   95,   11,   42,   15,   26,   31,   53,
   20,   21,  129,  130,  131,  239,  133,  121,  193,  194,
  195,  245,  196,  197,  221,  257,  278,   88,  296,  240,
  259,  265,  276,  266,  134,  122,  123,   50,   43,   44,
   32,   96,  243,  244,
};
static const short yysindex[] = {                       362,
    0,    0,    0,    0, -254,  101,    0, -211,  384,  362,
    0,   15, -177,  249,   37, -142,  101,  -71,  384,    0,
    0,  384,    0,  101,  138,   46,  101,    0,  -34,    0,
  172,    0,    0,  -25,  204, -177,  263,   94,    0,  384,
   11,  231,  234,    0,    6,    0,    0,   22,  258,   17,
  197,  177,    0,    0,  176,  101,  107,  101,    0,  210,
  -26,  101,    0,    0,    0,    0,    0,    0,  138,    2,
  -38,   17,   17,   17,    0,  146, -219,    0,   54,    0,
  172,  284,    0,  292,  210,    0,  373,    0,    0,    0,
    0,    0,   17,   17,  243,    0,  174,    0,   42,   17,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,    0,    0,  243,   54,   54,   54,    0, -141,
  153,  214,  297,    0,   23,  112,  101,   86,  696,  373,
    0,  146,  325,  345,   64,    0,    0,  174,  160,  350,
  350,  350,  350,  350,  350,  354,  354,    0,    0,    0,
  181,    0,   71,    0,    0,   54,   54,   54,   54,   54,
   54,   54,   54,   54,   54,   54,   54,   54,    0,   54,
    0,    0,    0,    0, -177,  176,  194,  -20,  358,    0,
  360,  368,  271,   17,  356,  364,  389,  396,  391,    0,
    0,    0,  332,  696,    0,    0,    0,    0,    0,   17,
    0,    0,  181,  167,  483,  483,  483,  483,  483,  483,
  480,  480,    0,    0,    0,  153,  278,    0,   17,  193,
  418,   17,    0,  185,   85,    0,    0,    0,    0,    0,
    0,    0,  146,    0,  423,  424,   17,  146,  407,   17,
  432,    0,   17,   17,   17,  417,  355,  146,   17,  146,
   17,   92,  118,  125,    0,  224,  456,  440,  464,  132,
  247,  448,    0, -232,  -30,    0,    0,   17,  271,  452,
  473,    0,  457,  466,  475,  415,    0,  271,  500,    0,
    0,  485,  696,  696,  696,    0,    0,  270,  271,    0,
    0,    0,    0,    0,    0,  271,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,  551,    0,
    0,    0,    0,  288,    0,    0,    0,    0,  558,    0,
    0,  560,    0,  520,    0,    0,  520,    0,    0,    0,
  323,    0,    0,    0,    0,    0,  288,    0,    0,  563,
    0,    0,  523,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  324,  520,    0,  520,    0,  344,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -28,    0,    0,    0,    0,  331,    7,    0,  445,    0,
  340,    0,    0,    0,  381,    0,  670,    0,    0,    0,
    0,    0,  526,    0,  -37,    0,  545,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   -2,    0,    0,    0,    0,   31,
   -6,    0,  458,    0,    0,    0,    0,    0,  476,  683,
    0,  443,    0,  527,    0,    0,    0,  562,  -23,  442,
  450,  459,  472,  495,  512,  430,  436,    0,    0,    0,
  -15,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  288,    0,  514,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -88,    0,    0,    0,    0,    0,    0,
    0,    0,   51,   76,  518,  525,  532,  538,  549,  555,
  261,  383,    0,    0,    0,   33,    0,    0,  526,    0,
    0,  522,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  444,    0,    0,    0,    0,  -29,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  536,  522,  543,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  477,    0,    0,  550,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -39,  -39,  476,    0,    0,  494,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  910,  814,  542,  539,  736,  622,    0,    0,    0,    0,
  597,  588,    0,    0,  602,  215,   -7,  -35,   43,  533,
  124,    0,    0,    0,  486, -221,  394,  878, -135,    0,
  426,    0,    0,    0,    0,    0,    0,  412,    0,    0,
    0,    0,    0,  353,    0,    0,    0,    0,    0,  568,
  257,  547,    0,    0,
};
#define YYTABLESIZE 1080
static const short yytable[] = {                          5,
   57,   93,   12,    5,    5,    5,    5,    5,    6,    5,
   38,   38,    6,    6,    6,    6,    6,   57,    6,  219,
   57,    5,    5,    5,    5,   75,  273,  258,   75,   38,
    6,    6,   86,    6,    6,   57,   81,  126,    6,    6,
    6,    6,    6,   40,    6,   14,  279,   40,   40,   40,
   40,   40,   94,   40,   24,    5,   74,    6,  274,    6,
   91,   73,  113,  114,    6,   40,   40,   61,   40,   57,
   94,   61,   61,   61,   61,   61,  125,   61,  112,   25,
   34,  171,  137,  110,  108,   80,  109,    5,  111,   48,
   61,   76,   61,  118,   76,   33,   87,   81,  117,   40,
  112,  107,   85,  106,   47,  110,  108,  168,  109,   75,
  111,  202,  166,  164,   35,  165,   77,  167,  126,   77,
  177,  112,    6,  107,   87,  106,  110,  108,  112,  109,
  163,  111,  162,  110,  108,  261,  109,   34,  111,  217,
  154,  155,   39,  242,  107,   87,  106,  291,  292,  293,
   48,  107,   59,  106,  112,   61,  201,  125,  262,  110,
  108,  112,  109,   39,  111,   83,  110,  108,  112,  109,
  173,  111,  270,  110,  108,   76,  109,  107,  111,  106,
   81,   81,  112,  263,  107,   37,  106,  110,  108,  168,
  109,  107,  111,  106,  166,  164,  112,  165,   45,  167,
   77,  110,  108,  168,  109,  107,  111,  106,  166,  164,
  112,  165,  163,  167,  162,  110,  108,  168,  109,  107,
  111,  106,  166,  164,   51,  165,  163,  167,  162,   80,
   80,   55,   52,  107,   87,  106,   28,   34,  264,  275,
  163,   49,  162,   56,    5,    5,    5,    5,    5,    5,
    5,    5,  218,    6,    6,    6,    6,    6,    6,    6,
    6,   57,   29,   63,   64,   65,   29,   60,   75,   75,
   82,   61,   84,   71,   63,   64,   65,   62,   69,    6,
    6,    6,    6,    6,    6,    6,    6,   54,   27,   78,
   40,   40,   40,   40,   40,   40,   66,   67,   70,   79,
   29,   64,   58,   64,   64,   64,   72,   66,   67,   28,
  115,   63,   64,   65,   61,   61,   61,   61,   61,   61,
   64,   48,   64,   28,  125,  100,  101,  102,  103,  104,
  105,   18,  126,   94,   76,   76,  234,   54,  169,   29,
  170,   54,  176,  116,   66,   67,   18,  100,  101,  102,
  103,  104,  105,   29,  156,  157,  158,  159,  160,  161,
   77,    1,    2,    3,    4,  199,   20,   13,  100,  101,
  102,  103,  104,  105,  128,  100,  101,  102,  103,  104,
  105,   20,   13,   16,  135,   64,  112,  135,  200,  128,
  112,  110,  108,   87,  109,  110,  111,  220,   16,  222,
  111,  100,  101,  102,  103,  104,  105,  223,  100,  101,
  102,  103,  104,  105,  226,  100,  101,  102,  103,  104,
  105,  134,  227,   65,  134,   65,   65,   65,  228,  100,
  101,  102,  103,  104,  105,  229,  156,  157,  158,  159,
  160,  161,   65,  100,   65,  102,  103,  104,  105,  236,
  156,  230,  158,  159,  160,  161,  231,  237,  241,  102,
  103,  104,  105,  246,  247,  249,  158,  159,  160,  161,
   44,  251,   44,   44,   44,  255,   45,  256,   45,   45,
   45,   92,   51,  122,  121,   51,  122,  121,   44,   44,
   52,   44,  264,   52,   45,   45,  267,   45,  268,   53,
   51,   51,   53,   51,  269,  271,  272,   65,   52,   52,
  281,   52,   54,  282,  283,   54,  168,   53,   53,  168,
   53,  166,   44,  284,  166,  164,  167,  165,   45,  167,
   54,   54,  285,   54,   51,   49,  172,  174,   49,  286,
  289,  294,   52,  290,   64,   64,   64,   64,   64,   64,
    3,   53,   50,   49,   49,   50,   49,    1,   71,    4,
  130,   71,    2,  131,   54,   72,  119,  120,   72,  123,
   50,   50,   73,   50,    6,   73,   96,   71,   74,   71,
   37,   74,  124,  103,   72,   55,   72,   49,   55,   69,
   37,   73,   69,   73,  224,   70,   80,   74,   70,   74,
   80,  112,   56,   55,   50,   56,   22,   90,   69,   40,
   69,   23,  235,  124,   70,  198,   70,  277,   99,  232,
   56,    8,    1,    2,    3,    4,    5,   13,    6,   89,
   18,    8,    0,    1,    2,    3,    4,   55,   36,  127,
   18,  136,   71,   18,    1,    2,    3,    4,   16,   72,
   17,    0,    0,    0,   56,    0,   73,    0,    0,    0,
    0,   18,   74,    0,    0,    0,   65,   65,   65,   65,
   65,   65,    0,   69,    0,    0,    0,    0,    0,   70,
  280,    0,    0,    0,    0,    0,    0,    0,    0,  288,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  295,    0,    0,    0,    0,    0,    0,  297,  128,    0,
    0,    0,    0,   44,   44,   44,   44,   44,   44,   45,
   45,   45,   45,   45,   45,   51,   51,   51,   51,   51,
   51,    0,    0,   52,   52,   52,   52,   52,   52,    0,
    0,    0,   53,   53,   53,   53,   53,   53,  175,    0,
   99,  128,    0,    0,    0,   54,   54,   54,   54,   54,
   54,   99,   99,   99,   99,    0,   99,   99,   99,   99,
   99,   99,    0,    0,    0,    0,    0,    0,   49,   49,
   49,   49,   49,   49,    0,    0,    0,    0,   99,   99,
    0,    0,    0,    0,   31,   50,   50,   50,   50,   50,
   50,   71,   71,   71,   71,   71,   71,   32,   72,   72,
   72,   72,   72,   72,  120,   73,   73,   73,   73,   73,
   73,   74,   74,   74,   74,   74,   74,    0,   55,   55,
    0,    0,   69,   69,   69,   69,   69,   69,   70,   70,
   70,   70,   70,   70,    0,   56,   56,    0,    0,    0,
    0,  120,  120,  120,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   76,  189,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   97,   98,   99,    0,    0,
    0,  120,  120,  120,  120,  120,  120,  120,  120,  120,
  120,  120,  120,  120,    0,  120,  132,  135,    0,    0,
    0,    0,    0,  138,  139,  140,  141,  142,  143,  144,
  145,  146,  147,  148,  149,  150,   31,    0,    0,  189,
    0,    0,    0,    0,    0,    0,    0,   31,    0,   32,
   31,    0,   31,   31,   31,   31,   31,   31,    0,    0,
   32,    0,  178,   32,   68,   32,   32,   32,   32,   32,
   32,    0,    0,  179,   31,   31,  180,    0,  181,  182,
  183,  184,  185,  186,    0,    0,    0,   32,   32,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  119,    0,
  187,  188,    0,  151,  152,  153,    0,  225,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  233,    0,    0,    0,    0,  189,  189,
  189,    0,    0,    0,    0,  119,  119,  119,    0,    0,
    0,    0,  132,  203,  204,  205,  206,  207,  208,  209,
  210,  211,  212,  213,  214,  215,    0,  216,    0,    0,
  248,    0,    0,  250,    0,    0,  252,  253,  254,    0,
    0,    0,    0,    0,  260,  119,  119,  119,  119,  119,
  119,  119,  119,  119,  119,  119,  119,  119,    0,  119,
};
static const short yycheck[] = {                         37,
   36,   40,  257,   41,   42,   43,   44,   45,   37,   47,
   18,   41,   41,   42,   43,   44,   45,   41,   47,   40,
   44,   59,   60,   61,   62,   41,  259,  249,   44,   59,
   59,   60,   59,   62,   37,   59,  125,   44,   41,   42,
   43,   44,   45,   37,   47,  257,  268,   41,   42,   43,
   44,   45,   91,   47,   40,   93,   40,   60,  291,   62,
   59,   45,  282,  283,   93,   59,   60,   37,   62,   93,
   91,   41,   42,   43,   44,   45,   44,   47,   37,  257,
   44,   59,   41,   42,   43,  125,   45,  125,   47,   44,
   60,   41,   62,   40,   44,   59,  123,   55,   45,   93,
   37,   60,   60,   62,   59,   42,   43,   37,   45,  125,
   47,   41,   42,   43,  257,   45,   41,   47,  125,   44,
  128,   37,  125,   60,  123,   62,   42,   43,   37,   45,
   60,   47,   62,   42,   43,   44,   45,   44,   47,  175,
  282,  283,   19,   59,   60,  123,   62,  283,  284,  285,
   44,   60,   59,   62,   37,  125,   93,  125,   41,   42,
   43,   37,   45,   40,   47,   59,   42,   43,   37,   45,
   59,   47,   41,   42,   43,  125,   45,   60,   47,   62,
  269,  270,   37,   59,   60,  257,   62,   42,   43,   37,
   45,   60,   47,   62,   42,   43,   37,   45,   61,   47,
  125,   42,   43,   37,   45,   60,   47,   62,   42,   43,
   37,   45,   60,   47,   62,   42,   43,   37,   45,   60,
   47,   62,   42,   43,  259,   45,   60,   47,   62,  269,
  270,  257,   61,   60,  123,   62,   61,   44,  269,  270,
   60,   27,   62,   40,  282,  283,  284,  285,  286,  287,
  288,  289,   59,  282,  283,  284,  285,  286,  287,  288,
  289,  285,   91,  258,  259,  260,   91,  257,  284,  285,
   56,   41,   58,  257,  258,  259,  260,   44,  257,  282,
  283,  284,  285,  286,  287,  288,  289,   31,   40,   93,
  284,  285,  286,  287,  288,  289,  291,  292,   41,  123,
   91,   41,   40,   43,   44,   45,  290,  291,  292,   61,
  257,  258,  259,  260,  284,  285,  286,  287,  288,  289,
   60,   44,   62,   61,   41,  284,  285,  286,  287,  288,
  289,   44,   41,   91,  284,  285,   59,   81,  125,   91,
   44,   85,  257,  290,  291,  292,   59,  284,  285,  286,
  287,  288,  289,   91,  284,  285,  286,  287,  288,  289,
  285,  261,  262,  263,  264,   41,   44,   44,  284,  285,
  286,  287,  288,  289,   44,  284,  285,  286,  287,  288,
  289,   59,   59,   44,   41,  125,   37,   44,   44,   59,
   37,   42,   43,  123,   45,   42,   47,   40,   59,   40,
   47,  284,  285,  286,  287,  288,  289,   40,  284,  285,
  286,  287,  288,  289,   59,  284,  285,  286,  287,  288,
  289,   41,   59,   41,   44,   43,   44,   45,   40,  284,
  285,  286,  287,  288,  289,   40,  284,  285,  286,  287,
  288,  289,   60,  284,   62,  286,  287,  288,  289,  257,
  284,   61,  286,  287,  288,  289,  125,   40,  274,  286,
  287,  288,  289,   41,   41,   59,  286,  287,  288,  289,
   41,   40,   43,   44,   45,   59,   41,  123,   43,   44,
   45,   70,   41,   41,   41,   44,   44,   44,   59,   60,
   41,   62,  269,   44,   59,   60,   41,   62,   59,   41,
   59,   60,   44,   62,   41,  259,   59,  125,   59,   60,
   59,   62,   41,   41,   58,   44,   37,   59,   60,   37,
   62,   42,   93,   58,   42,   43,   47,   45,   93,   47,
   59,   60,   58,   62,   93,   41,  125,  126,   44,  125,
   41,  272,   93,   59,  284,  285,  286,  287,  288,  289,
    0,   93,   41,   59,   60,   44,   62,    0,   41,    0,
   41,   44,    0,   41,   93,   41,   41,   41,   44,  125,
   59,   60,   41,   62,   61,   44,   41,   60,   41,   62,
   59,   44,  125,   41,   60,   41,   62,   93,   44,   41,
   41,   60,   44,   62,  183,   41,   55,   60,   44,   62,
  125,  125,   41,   59,   93,   44,   10,   69,   60,   22,
   62,   10,  219,   81,   60,  130,   62,  265,  125,  194,
   59,    0,  261,  262,  263,  264,  265,    6,  267,   62,
    9,   10,   -1,  261,  262,  263,  264,   93,   17,  267,
   19,   95,  125,   22,  261,  262,  263,  264,  265,  125,
  267,   -1,   -1,   -1,   93,   -1,  125,   -1,   -1,   -1,
   -1,   40,  125,   -1,   -1,   -1,  284,  285,  286,  287,
  288,  289,   -1,  125,   -1,   -1,   -1,   -1,   -1,  125,
  269,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  278,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  289,   -1,   -1,   -1,   -1,   -1,   -1,  296,   87,   -1,
   -1,   -1,   -1,  284,  285,  286,  287,  288,  289,  284,
  285,  286,  287,  288,  289,  284,  285,  286,  287,  288,
  289,   -1,   -1,  284,  285,  286,  287,  288,  289,   -1,
   -1,   -1,  284,  285,  286,  287,  288,  289,  127,   -1,
  257,  130,   -1,   -1,   -1,  284,  285,  286,  287,  288,
  289,  268,  269,  270,  271,   -1,  273,  274,  275,  276,
  277,  278,   -1,   -1,   -1,   -1,   -1,   -1,  284,  285,
  286,  287,  288,  289,   -1,   -1,   -1,   -1,  295,  296,
   -1,   -1,   -1,   -1,  125,  284,  285,  286,  287,  288,
  289,  284,  285,  286,  287,  288,  289,  125,  284,  285,
  286,  287,  288,  289,   79,  284,  285,  286,  287,  288,
  289,  284,  285,  286,  287,  288,  289,   -1,  284,  285,
   -1,   -1,  284,  285,  286,  287,  288,  289,  284,  285,
  286,  287,  288,  289,   -1,  284,  285,   -1,   -1,   -1,
   -1,  116,  117,  118,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   50,  129,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   72,   73,   74,   -1,   -1,
   -1,  156,  157,  158,  159,  160,  161,  162,  163,  164,
  165,  166,  167,  168,   -1,  170,   93,   94,   -1,   -1,
   -1,   -1,   -1,  100,  101,  102,  103,  104,  105,  106,
  107,  108,  109,  110,  111,  112,  257,   -1,   -1,  194,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  268,   -1,  257,
  271,   -1,  273,  274,  275,  276,  277,  278,   -1,   -1,
  268,   -1,  257,  271,   45,  273,  274,  275,  276,  277,
  278,   -1,   -1,  268,  295,  296,  271,   -1,  273,  274,
  275,  276,  277,  278,   -1,   -1,   -1,  295,  296,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   79,   -1,
  295,  296,   -1,  116,  117,  118,   -1,  184,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  200,   -1,   -1,   -1,   -1,  283,  284,
  285,   -1,   -1,   -1,   -1,  116,  117,  118,   -1,   -1,
   -1,   -1,  219,  156,  157,  158,  159,  160,  161,  162,
  163,  164,  165,  166,  167,  168,   -1,  170,   -1,   -1,
  237,   -1,   -1,  240,   -1,   -1,  243,  244,  245,   -1,
   -1,   -1,   -1,   -1,  251,  156,  157,  158,  159,  160,
  161,  162,  163,  164,  165,  166,  167,  168,   -1,  170,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 297
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"IDEN","STRING_LIT","INT_LIT","BOOL_LIT",
"INT","DOUBLE","BOOL","CHAR","VOID","STRUCT","CONST","SWITCH","CASE","DEFAULT",
"IF","ELSE","FOR","WHILE","DO","RETURN","CONTINUE","BREAK","NUL","TRUE","FALSE",
"PLUSPLUS","MINUSMINUS","ANDAND","OROR","GE","LE","EQUAL","NOTEQUAL","NOT",
"CHAR_LIT","DOUBLE_LIT","HIGH","LOW","DIGITAL_WRITE","DELAY","UMINUS",
"illegal-symbol",
};
static const char *yyrule[] = {
"$accept : program",
"program : first_func_def extdefs",
"program : extdefs_no_func first_func_def extdefs",
"program : first_func_def",
"program : extdefs_no_func first_func_def",
"var : IDEN indexs",
"var : IDEN",
"extdefs_no_func : extdefs_no_func extdef_no_func",
"extdefs_no_func : extdef_no_func",
"extdef_no_func : type IDEN '(' para_in ')' ';'",
"extdef_no_func : VOID IDEN '(' para_in ')' ';'",
"extdef_no_func : type iden_list_init ';'",
"extdef_no_func : CONST type const_iden_list ';'",
"iden_list_init : iden_list_init ',' IDEN",
"iden_list_init : iden_list_init ',' IDEN init",
"iden_list_init : iden_list_init ',' IDEN indexs_dec array_init",
"iden_list_init : iden_list_init ',' IDEN indexs_dec",
"iden_list_init : IDEN init",
"iden_list_init : IDEN",
"iden_list_init : IDEN indexs_dec array_init",
"iden_list_init : IDEN indexs_dec",
"const_iden_list : const_iden_list ',' IDEN const_init",
"const_iden_list : IDEN const_init",
"const_init : '=' literal",
"extdefs : extdefs extdef",
"extdefs : extdef",
"extdef : type IDEN '(' para_in ')' ';'",
"extdef : VOID IDEN '(' para_in ')' ';'",
"extdef : func_def",
"extdef : type iden_list_init ';'",
"extdef : CONST type const_iden_list ';'",
"decs_x :",
"decs_x : decs",
"decs : decs dec",
"decs : dec",
"dec : type iden_list_init ';'",
"dec : CONST type const_iden_list ';'",
"expr_x :",
"expr_x : expr",
"expr : literal",
"expr : var",
"expr : var PLUSPLUS",
"expr : var MINUSMINUS",
"expr : IDEN '(' exprs_comma_x ')'",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '>' expr",
"expr : expr '<' expr",
"expr : expr GE expr",
"expr : expr LE expr",
"expr : expr EQUAL expr",
"expr : expr NOTEQUAL expr",
"expr : NOT expr",
"expr : expr ANDAND expr",
"expr : expr OROR expr",
"expr : '-' expr",
"expr : '(' expr ')'",
"expr_no_invoke : literal",
"expr_no_invoke : var",
"expr_no_invoke : var PLUSPLUS",
"expr_no_invoke : var MINUSMINUS",
"expr_no_invoke : expr_no_invoke '+' expr_no_invoke",
"expr_no_invoke : expr_no_invoke '-' expr_no_invoke",
"expr_no_invoke : expr_no_invoke '*' expr_no_invoke",
"expr_no_invoke : expr_no_invoke '/' expr_no_invoke",
"expr_no_invoke : expr_no_invoke '%' expr_no_invoke",
"expr_no_invoke : expr_no_invoke '>' expr_no_invoke",
"expr_no_invoke : expr_no_invoke '<' expr_no_invoke",
"expr_no_invoke : expr_no_invoke GE expr_no_invoke",
"expr_no_invoke : expr_no_invoke LE expr_no_invoke",
"expr_no_invoke : expr_no_invoke EQUAL expr_no_invoke",
"expr_no_invoke : expr_no_invoke NOTEQUAL expr_no_invoke",
"expr_no_invoke : NOT expr_no_invoke",
"expr_no_invoke : expr_no_invoke ANDAND expr_no_invoke",
"expr_no_invoke : expr_no_invoke OROR expr_no_invoke",
"expr_no_invoke : '-' expr_no_invoke",
"expr_no_invoke : '(' expr_no_invoke ')'",
"stmts_x :",
"stmts_x : stmts",
"stmts : stmts stmt",
"stmts : stmt",
"$$1 :",
"stmt : var '=' $$1 expr ';'",
"stmt : blink",
"stmt : if_stmt",
"stmt : while_stmt",
"stmt : switch_stmt",
"stmt : for_stmt",
"stmt : IDEN '(' exprs_comma_x ')' ';'",
"stmt : RETURN expr ';'",
"stmt : BREAK ';'",
"stmt : CONTINUE ';'",
"$$2 :",
"$$3 :",
"$$4 :",
"if_stmt : IF $$2 '(' expr $$3 ')' $$4 else_x",
"else_x : compound",
"$$5 :",
"else_x : compound ELSE $$5 compound",
"$$6 :",
"$$7 :",
"while_stmt : WHILE '(' $$6 expr $$7 ')' compound",
"while_stmt : DO compound WHILE '(' expr ')' ';'",
"for_stmt : FOR '(' expr_x ';' expr_x ';' expr_x ')' compound",
"switch_stmt : SWITCH '(' IDEN ')' '{' cases default_x '}'",
"cases : cases case",
"cases : case",
"case : CASE CHAR_LIT ':' stmts_x",
"case : CASE INT_LIT ':' stmts_x",
"default_x :",
"default_x : DEFAULT ':' stmts_x",
"first_func_def : type IDEN '(' para_in ')' compound",
"first_func_def : VOID IDEN '(' para_in ')' compound",
"func_def : type IDEN '(' para_in ')' compound",
"func_def : VOID IDEN '(' para_in ')' compound",
"compound : '{' decs_x stmts_x '}'",
"exprs_comma_x :",
"exprs_comma_x : exprs_comma",
"exprs_comma : exprs_comma ',' expr",
"exprs_comma : expr",
"exprs_comma_no_invoke_x :",
"exprs_comma_no_invoke_x : exprs_comma_no_invoke",
"exprs_comma_no_invoke : exprs_comma_no_invoke ',' expr_no_invoke",
"exprs_comma_no_invoke : expr_no_invoke",
"$$8 :",
"init : '=' $$8 expr",
"array_init : '=' '{' exprs_comma_no_invoke_x '}'",
"para_in :",
"para_in : paras",
"paras : paras ',' para",
"paras : para",
"para : type IDEN indexs_dec",
"para : type IDEN",
"indexs_dec : indexs_dec index_dec",
"indexs_dec : index_dec",
"index_dec : '[' INT_LIT ']'",
"indexs : indexs index",
"indexs : index",
"index : '[' expr ']'",
"type : INT",
"type : DOUBLE",
"type : CHAR",
"type : BOOL",
"literal : CHAR_LIT",
"literal : INT_LIT",
"literal : DOUBLE_LIT",
"literal : BOOL_LIT",
"literal : STRING_LIT",
"$$9 :",
"blink : DIGITAL_WRITE '(' $$9 expr ',' INT_LIT ')' ';'",
"$$10 :",
"blink : DELAY '(' $$10 expr ')' ';'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 878 "hw3.y"


int main(void)
{
    reg[0] = 1; // set reg 0, 1 ,5 not usable
    reg[1] = 1;
    reg[5] = 1;   
    init_symbol_table();
    yyparse();
    return 0;
}

/*
 *	  s - the error message to be printed
 */
void  yyerror(char* msg)
{

   fprintf( stderr, "*** Error at line %d: %s\n", lineCount, lineBuffer );
   fprintf( stderr, "\n" );
   fprintf( stderr, "Unmatched token: %s\n", yytext );
   fprintf( stderr, "*** syntax error\n"); 
   exit(-1); 
}

void Write_Assembly(){
     f_asm = fopen("assembly","w");
     fprintf(f_asm,"\n");
     fprintf(f_asm," addi $sp, $sp, -%d\n",(stack_cur_offset + needed_space + 10)*4);
     fprintf(f_asm,"%s",output);
     fprintf(f_asm," addi $sp, $sp, %d\n",(stack_cur_offset + needed_space +10)*4 );
}

void Init_Expr(){
  expr_stack_offset = stack_cur_offset;
}

void End_Expr(){
    int i;
    for(i=2;i<11;i++){
      reg[i] = 0;
    }
    reg[5] = 1;
    if( expr_stack_offset - stack_cur_offset + 1 > needed_space){
    needed_space = expr_stack_offset - stack_cur_offset + 1; 
    }
    
}


void Init_Type_Not_Match(){
  fprintf( stderr ,"Error at line %d : Initialization type not matched with declaration type\n",lineCount);
}

void Check_Var_Not_Exist(char* s){
  int i = look_up_symbol(s);
  if(i>=0 && table[i].scope == cur_scope){
    fprintf(stderr, " Error at line %d :Re-declaration of already used variable name in a same scope\n",lineCount);
  }
}

void Check_Var_Exist(char *s){
  int i = look_up_symbol(s);
  if(i<0){
    fprintf(stderr,"Error ar line %d :Use a variable before it is declared!!\n",lineCount);
  }
}

void gen_add(int r0 , int r1 , int r2){
  char temp[1000];
  sprintf(temp," add $r%d, $r%d, $r%d\n",r0,r1,r2);
  strcat(output,temp);
}

void gen_addi(int r0, int r1, int con){
    char temp[1000];
    sprintf(temp," addi $r%d, $r%d, %d\n",r0,r1,con);
    strcat(output, temp);
}

void gen_subi(int r0, int r1, int con){
    char temp[1000];
    sprintf(temp," subi $r%d, $r%d, %d\n",r0,r1,con);
    strcat(output, temp);
}

void gen_sub(int r0 , int r1 , int r2){
    char temp[1000];
    sprintf(temp," sub $r%d, $r%d, $r%d\n",r0,r1,r2);
   strcat(output,temp);
}

void gen_mul(int r0 , int r1 , int r2){
  char temp[1000];
  sprintf(temp," mul $r%d, $r%d, $r%d\n",r0,r1,r2);
  strcat(output,temp);
}

void gen_divsr(int r0 , int r1 , int r2 , int r3){
   char temp[1000];
   sprintf(temp," divsr $r%d, $r%d, $r%d, $r%d\n",r0,r1,r2,r3);
  strcat(output,temp);
}

void gen_movi(int r0,int con){
    char temp[1000];
    sprintf(temp," movi $r%d, %d\n",r0,con);
    strcat(output,temp);
}

void gen_lwi(int r0,int offset){
    char temp[1000];
    sprintf(temp," lwi $r%d, [$sp+(%d)]\n",r0,offset*4);
    strcat(output,temp);
}

void gen_swi(int r0,int offset){
    char temp[1000];
    sprintf(temp," swi $r%d, [$sp+(%d)]\n",r0,offset*4);
    strcat(output,temp);
}

void gen_jal(char *s){
    char temp[1000];
    sprintf(temp," jal %s\n",s);
    strcat(output,temp);
}

void gen_ret(){
    strcat(output," ret\n");
}

void gen_bal(char* s){
   char temp[1000];
    sprintf(temp," bal %s\n",s);
    strcat(output,temp);
}
void gen_ori(int r1,int r2, int cons){
    char temp[1000];
    sprintf(temp," ori $r%d, $r%d, %d\n",r1,r2,cons);
    strcat(output,temp);

}

void gen_beqc(int r1,int cons,int i){
    char temp[1000];
    sprintf(temp," beqc $r%d, %d, L%d\n",r1,cons,i);
    strcat(output,temp);
}

void gen_bnec(int r1,int cons,int i){
    char temp[1000];
    sprintf(temp," bnec $r%d, %d, L%d\n",r1,cons,i);
    strcat(output,temp);
}

void gen_beq(int r1,int r2,int i){
    char temp[1000];
    sprintf(temp," beq $r%d, $r%d, L%d\n",r1,r2,i);
    strcat(output,temp);
}

void gen_bne(int r1,int r2,int i){
  char temp[1000];
    sprintf(temp," bne $r%d, $r%d, L%d\n",r1,r2,i);
    strcat(output,temp);
}

void gen_bnez(int q,int i){
  char temp[1000];
   sprintf(temp," bnez $r%d, L%d\n",q,i);
   strcat(output,temp);
}

void gen_sltsi(int q ,int r , int cons){
  char temp[1000];
   sprintf(temp," sltsi $r%d, $r%d,  %d\n",q,r,cons);
   strcat(output,temp);
}

void gen_slts(int q,int r1,int r2){
   char temp[1000];
   sprintf(temp," slts $r%d, $r%d, $r%d\n",q,r1,r2);
   strcat(output,temp);
}


void gen_slt(int q,int r1,int r2){
   char temp[1000];
   sprintf(temp," slt $r%d, $r%d, $r%d\n",q,r1,r2);
   strcat(output,temp);
}

void gen_slti(int r0,int r1,int cons){
  char temp[1000];
  sprintf(temp," slti $r%d, $r%d, %d\n",r0,r1,cons);
  strcat(output,temp);
}

void gen_beqz(int q,int i){
  char temp[1000];
   sprintf(temp," beqz $r%d, L%d\n",q,i);
   strcat(output,temp);
}

void gen_j(int i){
   char temp[1000];
   sprintf(temp," j L%d\n",i);
   strcat(output,temp);
}

void gen_zeb(int r1,int r2){
   char temp[1000];
   sprintf(temp," zeb $r%d, $r%d\n",r1,r2);
   strcat(output,temp);
}
 
void gen_subri(int r1,int r2,int cons){
  char temp[1000];
   sprintf(temp," subri $r%d, $r%d, %d\n",r1,r2,cons);
   strcat(output,temp);
}

void gen_xor(int r0,int r1,int r2){
  char temp[1000];
   sprintf(temp," xor $r%d, $r%d, $r%d\n",r0,r1,r2);
   strcat(output,temp);
}

void gen_label(int i){
   char temp[1000];
   sprintf(temp,"L%d:\n",i);
   strcat(output,temp);
}


int get_reg(){
  int i=0;
  for(i=2;i<5;i++){
      if(reg[i]==0){
        reg[i] = 1;
        return i;
      }
  }
  return -1;
}

void pop_instruction(){
   int i;
   i = strlen(output)-1;
   char c ;
   do{
	c = output[i];
	output[i] = '\0';
	
   }while(c!='\n');
   c= output[strlen(output)-1];
   while(c!='\n'){
	output[strlen(output)-1] = '\0';
	c = output[strlen(output)-1];
   }
}

int load_expr(int x , int r){
    //if(x<0){
  //    gen_addi(r,-x);
//	}
    //else{
      if(x>=0){
	gen_lwi(r,x);
      	return 1;
      }
   return 0;
  //  }
}


int  save_expr(int x , int y){
    if(x<0){
        gen_ori(-x,0,0);
        reg[-y] = 0; 
	return x;
    }
    else if(y<0){
        gen_ori(-y,0,0);
        reg[-x] = 0;
	return y;
    }
    else{
        gen_swi(0,x);
	return x;
    }
}

#line 1033 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 96 "hw3.y"
	{
     printf("No syntax error!\n");
     Write_Assembly();
    }
break;
case 2:
#line 100 "hw3.y"
	{printf("No syntax error!\n");Write_Assembly();}
break;
case 3:
#line 101 "hw3.y"
	{printf("No syntax error!\n");Write_Assembly();}
break;
case 4:
#line 102 "hw3.y"
	{printf("No syntax error!\n");Write_Assembly();}
break;
case 5:
#line 106 "hw3.y"
	{
      Check_Var_Exist(yystack.l_mark[-1].sval);
      /* supposely, there should be no array.........*/
   }
break;
case 6:
#line 110 "hw3.y"
	{
      Check_Var_Exist(yystack.l_mark[0].sval);
       yyval.sval = mstrcpy(yystack.l_mark[0].sval);
   }
break;
case 7:
#line 120 "hw3.y"
	{}
break;
case 8:
#line 121 "hw3.y"
	{}
break;
case 9:
#line 124 "hw3.y"
	{}
break;
case 10:
#line 125 "hw3.y"
	{}
break;
case 11:
#line 126 "hw3.y"
	{
     int i;
     for(i=0;i<init_index;i++){
        if(table[cur_counter-1-i].mtype == -1){
           table[cur_counter-1-i].mtype = yystack.l_mark[-2].ival;
        }
        else if(table[cur_counter-1-i].mtype != yystack.l_mark[-2].ival){
           Init_Type_Not_Match();
        }
     }
     init_index = 0;
  }
break;
case 12:
#line 138 "hw3.y"
	{}
break;
case 13:
#line 141 "hw3.y"
	{
          Check_Var_Not_Exist(yystack.l_mark[0].sval);
          /* put value into stack */
          install_symbol(yystack.l_mark[0].sval);   
          /*stack_cur_offset++; */
          init_index++;
         stack_cur_offset++;
  }
break;
case 14:
#line 149 "hw3.y"
	{ 
        Check_Var_Not_Exist(yystack.l_mark[-1].sval);
        /* put value into stack */
         install_symbol(yystack.l_mark[-1].sval);
          int i = look_up_symbol(yystack.l_mark[-1].sval); 
          table[i].mtype  = yystack.l_mark[0].lit.type;
	  table[i].ival = yystack.l_mark[0].lit.ival;  
          init_index++;
           /* gen code*/
          if(yystack.l_mark[0].lit.offset>=0){
            gen_lwi(0,yystack.l_mark[0].lit.offset);
            gen_swi(0,stack_cur_offset);
            stack_cur_offset ++;
          }
          else{
            gen_swi(yystack.l_mark[0].lit.offset*(-1),stack_cur_offset);
            stack_cur_offset++;
          }

          gen_lwi(0,yystack.l_mark[0].lit.offset);
          gen_swi(0,stack_cur_offset);
          stack_cur_offset ++;
   }
break;
case 15:
#line 172 "hw3.y"
	{}
break;
case 16:
#line 173 "hw3.y"
	{}
break;
case 17:
#line 174 "hw3.y"
	{ 
	       printf("b\n");
         Check_Var_Not_Exist(yystack.l_mark[-1].sval);
         /* put value into stack*/
     
         install_symbol(yystack.l_mark[-1].sval);
	
          int i = look_up_symbol(yystack.l_mark[-1].sval); 
	        table[i].ival = yystack.l_mark[0].lit.ival;
          table[i].mtype  = yystack.l_mark[0].lit.type;  

          init_index++;
          /* gen code*/
	          printf("qq%d\n",yystack.l_mark[0].lit.offset);
	        if(yystack.l_mark[0].lit.offset>=0){
            gen_lwi(0,yystack.l_mark[0].lit.offset);
            gen_swi(0,stack_cur_offset);
            stack_cur_offset ++;
          }
          else{
            gen_swi(yystack.l_mark[0].lit.offset*(-1),stack_cur_offset);
	    stack_cur_offset++;
          }
	  
          }
break;
case 18:
#line 199 "hw3.y"
	{ 
   
	        Check_Var_Not_Exist(yystack.l_mark[0].sval);
          /* put value into stack*/
          install_symbol(yystack.l_mark[0].sval);
          init_index++;
          stack_cur_offset++;

          }
break;
case 19:
#line 208 "hw3.y"
	{}
break;
case 20:
#line 209 "hw3.y"
	{}
break;
case 21:
#line 213 "hw3.y"
	{  
          Check_Var_Not_Exist(yystack.l_mark[-1].sval);
          install_symbol(yystack.l_mark[-1].sval);
          /* put value into stack*/
          stack_cur_offset++; 
          int i = look_up_symbol(yystack.l_mark[-1].sval); 
          table[i].mtype  = yystack.l_mark[0].lit.type;  
          init_index++;
          /* gen code*/
          gen_movi(0,yystack.l_mark[0].lit.ival);
          gen_swi(0,stack_cur_offset);
          stack_cur_offset ++;

        }
break;
case 22:
#line 227 "hw3.y"
	{ 
            
          Check_Var_Not_Exist(yystack.l_mark[-1].sval);
          install_symbol(yystack.l_mark[-1].sval);
          /* put value into stack*/
          stack_cur_offset++; 
          int i = look_up_symbol(yystack.l_mark[-1].sval); 
          table[i].mtype  = yystack.l_mark[0].lit.type;  
          init_index++;
           /* gen code*/
          gen_movi(0,yystack.l_mark[0].lit.ival);
          gen_swi(0,stack_cur_offset);
          stack_cur_offset ++;

          }
break;
case 23:
#line 244 "hw3.y"
	{
  
  yyval.lit.type = yystack.l_mark[0].lit.type; 
  if(yyval.lit.type==0){
    yyval.lit.ival = yystack.l_mark[0].lit.ival;
  } 
  else if(yyval.lit.type==1){
    yyval.lit.dval = yystack.l_mark[0].lit.dval;
  }
  else if(yyval.lit.type==2){
    yyval.lit.cval = yystack.l_mark[0].lit.cval;
  }
  else if(yyval.lit.type==4){
    yyval.lit.bval = yystack.l_mark[0].lit.bval;
  }

  }
break;
case 24:
#line 268 "hw3.y"
	{}
break;
case 25:
#line 269 "hw3.y"
	{}
break;
case 26:
#line 273 "hw3.y"
	{}
break;
case 27:
#line 274 "hw3.y"
	{}
break;
case 28:
#line 275 "hw3.y"
	{}
break;
case 29:
#line 276 "hw3.y"
	{}
break;
case 30:
#line 277 "hw3.y"
	{}
break;
case 31:
#line 280 "hw3.y"
	{}
break;
case 32:
#line 281 "hw3.y"
	{}
break;
case 33:
#line 285 "hw3.y"
	{}
break;
case 34:
#line 286 "hw3.y"
	{}
break;
case 35:
#line 289 "hw3.y"
	{}
break;
case 36:
#line 290 "hw3.y"
	{}
break;
case 37:
#line 293 "hw3.y"
	{}
break;
case 38:
#line 294 "hw3.y"
	{}
break;
case 39:
#line 297 "hw3.y"
	{
      yyval.lit.type = yystack.l_mark[0].lit.type; 
      yyval.lit.ival = yystack.l_mark[0].lit.ival; 
      int r = get_reg();
	printf("rrrr%d\n",r);
      if(r<0){
        yyval.lit.offset = expr_stack_offset++;
        gen_movi(0,yyval.lit.ival);
        gen_swi(0,yyval.lit.offset);
      }
      else{
	yyval.lit.offset = -r;
 	gen_movi(r,yyval.lit.ival);
      }
      
    }
break;
case 40:
#line 313 "hw3.y"
	{ 
      yyval.lit.sval = mstrcpy(yystack.l_mark[0].sval);
      int i = look_up_symbol(yystack.l_mark[0].sval); 
      yyval.lit.type = table[i].mtype; 
      yyval.lit.ival=  table[i].ival;  
      /*$$.offset = table[i].stack_offset; */
      int r = get_reg();
      if(r<0){
         yyval.lit.offset = table[i].stack_offset;
      }
      else{
         gen_lwi(r,table[i].stack_offset);
         yyval.lit.offset = -r;
      }
  }
break;
case 41:
#line 328 "hw3.y"
	{ 
    yyval.lit.sval = mstrcpy(yystack.l_mark[-1].sval);

    int i = look_up_symbol(yystack.l_mark[-1].sval);
    yyval.lit.type = table[i].mtype; 
    yyval.lit.ival = table[i].ival;
    table[i].ival++; 
    /* add origin var &  */ 
    int r = get_reg();
    if(r<0){
        yyval.lit.offset = expr_stack_offset++;
        gen_lwi(0,table[i].stack_offset);
        gen_swi(0,yyval.lit.offset);

        gen_addi(0,0,1);
        gen_swi(0,table[i].stack_offset);

    }
    else{
        yyval.lit.offset = -r;
        gen_lwi(0,table[i].stack_offset);
        gen_addi(0,0,1);
        gen_swi(0,table[i].stack_offset);
    }


  }
break;
case 42:
#line 355 "hw3.y"
	{ 
    yyval.lit.sval = mstrcpy(yystack.l_mark[-1].sval);
    int i = look_up_symbol(yystack.l_mark[-1].sval);
    yyval.lit.type = table[i].mtype; 
    yyval.lit.ival = table[i].ival;
    table[i].ival--; 
    /* add origin var &  */ 
    int r  = get_reg();
    if(r<0){
        yyval.lit.offset = expr_stack_offset++;
        gen_lwi(0,table[i].stack_offset);
        gen_swi(0,yyval.lit.offset);

        gen_subi(0,0,1);
        gen_swi(0,table[i].stack_offset);

    }
    else{
        yyval.lit.offset = -r;
        gen_lwi(0,table[i].stack_offset);
        gen_subi(0,0,1);  /* maybe there isn't negative addi ?????*/
        gen_swi(0,table[i].stack_offset);
    }

    }
break;
case 43:
#line 381 "hw3.y"
	{ }
break;
case 44:
#line 383 "hw3.y"
	{ 

    yyval.lit.type = yystack.l_mark[-2].lit.type; 
    yyval.lit.ival = yystack.l_mark[-2].lit.ival + yystack.l_mark[0].lit.ival; 
    /*$$.offset = expr_stack_offset++; */
    /* generate code*/
    int o1 = yystack.l_mark[-2].lit.offset;
    int o3 = yystack.l_mark[0].lit.offset;
    EXPR_LOAD
    gen_add(0,r1,r2);
    int x = save_expr(yystack.l_mark[-2].lit.offset,yystack.l_mark[0].lit.offset);
    yyval.lit.offset = x;
    }
break;
case 45:
#line 396 "hw3.y"
	{
    yyval.lit.type = yystack.l_mark[-2].lit.type; 
    yyval.lit.ival = yystack.l_mark[-2].lit.ival - yystack.l_mark[0].lit.ival;
    /*$$.offset = expr_stack_offset++;*/
    int o1 = yystack.l_mark[-2].lit.offset;
    int o3 = yystack.l_mark[0].lit.offset;
    EXPR_LOAD

    gen_sub(0,r1,r2);
    int x = save_expr(yystack.l_mark[-2].lit.offset,yystack.l_mark[0].lit.offset);
    yyval.lit.offset =x;
    }
break;
case 46:
#line 408 "hw3.y"
	{
   yyval.lit.type = yystack.l_mark[-2].lit.type; 
   yyval.lit.ival = yystack.l_mark[-2].lit.ival * yystack.l_mark[0].lit.ival; 
  /* $$.offset = expr_stack_offset++;*/
  int o1 = yystack.l_mark[-2].lit.offset;
    int o3 = yystack.l_mark[0].lit.offset;
    EXPR_LOAD

    gen_mul(0,r1,r2);
    int x=save_expr(yystack.l_mark[-2].lit.offset,yystack.l_mark[0].lit.offset);
    yyval.lit.offset = x; 
  }
break;
case 47:
#line 420 "hw3.y"
	{ 
  yyval.lit.type = yystack.l_mark[-2].lit.type;
 /* printf("!!!!%d\n",$3.ival);*/
  yyval.lit.ival = yystack.l_mark[-2].lit.ival / yystack.l_mark[0].lit.ival; 
  /*$$.offset = expr_stack_offset++;*/
  int o1 = yystack.l_mark[-2].lit.offset;
    int o3 = yystack.l_mark[0].lit.offset;
    EXPR_LOAD

    gen_divsr(0,1,r1,r2);
    int x= save_expr(yystack.l_mark[-2].lit.offset,yystack.l_mark[0].lit.offset);
    yyval.lit.offset = x;
  }
break;
case 48:
#line 433 "hw3.y"
	{ 
    yyval.lit.type = yystack.l_mark[-2].lit.type; 
    yyval.lit.ival = yystack.l_mark[-2].lit.ival % yystack.l_mark[0].lit.ival;  
    int o1 = yystack.l_mark[-2].lit.offset;
    int o3 = yystack.l_mark[0].lit.offset;
    EXPR_LOAD

    gen_divsr(1,0,r1,r2);
    int x=save_expr(yystack.l_mark[-2].lit.offset,yystack.l_mark[0].lit.offset);
    yyval.lit.offset = x;
  }
break;
case 49:
#line 444 "hw3.y"
	{
    yyval.lit.type = 4;
     int o1 = yystack.l_mark[-2].lit.offset;
    int o3 = yystack.l_mark[0].lit.offset;
    EXPR_LOAD
    gen_slts(0,r2,r1);
    gen_zeb(0,0);                           /* IS  THIS REEEEEEEEEEEEEEEEEEALLY NEEDED??????*/
    int x = save_expr(yystack.l_mark[-2].lit.offset,yystack.l_mark[0].lit.offset);
    yyval.lit.offset = x;

   }
break;
case 50:
#line 455 "hw3.y"
	{
     yyval.lit.type = 4;
     int o1 = yystack.l_mark[-2].lit.offset;
    int o3 = yystack.l_mark[0].lit.offset;
    EXPR_LOAD
    gen_slts(0,r1,r2);
    gen_zeb(0,0);            /* IS  THIS REEEEEEEEEEEEEEEEEEALLY NEEDED??????*/
    int x = save_expr(yystack.l_mark[-2].lit.offset,yystack.l_mark[0].lit.offset);
    yyval.lit.offset = x;
  }
break;
case 51:
#line 465 "hw3.y"
	{ 
    yyval.lit.type = 4;
    int o1 = yystack.l_mark[-2].lit.offset;
    int o3 = yystack.l_mark[0].lit.offset;
    EXPR_LOAD
    gen_slts(0,r1,r2);
    gen_sltsi(0,0,1);
    gen_zeb(0,0);            /* IS  THIS REEEEEEEEEEEEEEEEEEALLY NEEDED??????*/
    int x = save_expr(yystack.l_mark[-2].lit.offset,yystack.l_mark[0].lit.offset);
    yyval.lit.offset = x;
  }
break;
case 52:
#line 476 "hw3.y"
	{ 
    yyval.lit.type = 4;
    int o1 = yystack.l_mark[-2].lit.offset;
    int o3 = yystack.l_mark[0].lit.offset;
    EXPR_LOAD
    gen_slts(0,r2,r1);
    gen_sltsi(0,15,1);  
    gen_zeb(0,0);                  /* IS  THIS REEEEEEEEEEEEEEEEEEALLY NEEDED??????*/
    int x = save_expr(yystack.l_mark[-2].lit.offset,yystack.l_mark[0].lit.offset);
    yyval.lit.offset = x;
  }
break;
case 53:
#line 487 "hw3.y"
	{ 
    yyval.lit.type = 4;
    int o1 = yystack.l_mark[-2].lit.offset;
    int o3 = yystack.l_mark[0].lit.offset;
    EXPR_LOAD
    gen_xor(0,r1,r2);
    gen_slti(0,0,1);
    gen_zeb(0,0);
    int x = save_expr(yystack.l_mark[-2].lit.offset,yystack.l_mark[0].lit.offset);
    yyval.lit.offset = x;
    
  }
break;
case 54:
#line 499 "hw3.y"
	{ yyval.lit.type = 4; 
    yyval.lit.type = 4;
    int o1 = yystack.l_mark[-2].lit.offset;
    int o3 = yystack.l_mark[0].lit.offset;
    EXPR_LOAD
    gen_xor(0,r1,r2);
    gen_movi(1,0);
    gen_slt(0,1,0);
    gen_zeb(0,0);
    int x = save_expr(yystack.l_mark[-2].lit.offset,yystack.l_mark[0].lit.offset);
    yyval.lit.offset = x;
  }
break;
case 55:
#line 511 "hw3.y"
	{ 
     yyval.lit.type = 4;
     int r = load_expr(yystack.l_mark[0].lit.offset,0);
     if(r==1){
       r= 0;
     }
     else{
       r= -yystack.l_mark[0].lit.offset;
     }
     gen_slti(0,r,1);
     gen_zeb(0,0);
     
     if( r==0 ){
        gen_swi(0,yystack.l_mark[0].lit.offset);
     }
     else{
        gen_ori(r,0,0);
     }

     yyval.lit.offset = yystack.l_mark[0].lit.offset;

  }
break;
case 56:
#line 533 "hw3.y"
	{ 
      yyval.lit.type = 4; 
      int o1 = yystack.l_mark[-2].lit.offset;
    int o3 = yystack.l_mark[0].lit.offset;
      EXPR_LOAD
      int l = labelCount;
      labelCount += 2;
      gen_beqz(r1,l);
      gen_beqz(r2,l);
      gen_movi(0,1);
      gen_j(l+1);
      gen_label(l);
      gen_movi(0,0);
      gen_label(l+1);
      int x = save_expr(yystack.l_mark[-2].lit.offset,yystack.l_mark[0].lit.offset);
      yyval.lit.offset = x;
  }
break;
case 57:
#line 550 "hw3.y"
	{
     yyval.lit.type = 4;  
     int o1 = yystack.l_mark[-2].lit.offset;
    int o3 = yystack.l_mark[0].lit.offset;
     EXPR_LOAD
     int l = labelCount;
     labelCount +=3;
     gen_bnez(r1,l);
     gen_beqz(r2,l+1);
     gen_label(l);
     gen_movi(0,1);
     gen_j(l+2);
     gen_label(l+1);
     gen_movi(0,0);
     gen_label(l+2);
    
     int x = save_expr(yystack.l_mark[-2].lit.offset,yystack.l_mark[0].lit.offset);
     yyval.lit.offset = x;

  }
break;
case 58:
#line 570 "hw3.y"
	{
    yyval.lit.type = yystack.l_mark[0].lit.type; 
    yyval.lit.ival = yystack.l_mark[0].lit.ival * (-1);
     int r = load_expr(yystack.l_mark[0].lit.offset,0);
     if(r==1){
       r= 0;
     }
     else{
       r= -yystack.l_mark[0].lit.offset;
     }
     gen_subri(0,r,0);

     if( r==0 ){
        gen_swi(0,yystack.l_mark[0].lit.offset);
     }
     else{
        gen_ori(r,0,0);
     }

     yyval.lit.offset = yystack.l_mark[0].lit.offset;
  }
break;
case 59:
#line 591 "hw3.y"
	{
	 yyval.lit.type = yystack.l_mark[-1].lit.type; 
	yyval.lit.ival = yystack.l_mark[-1].lit.ival; 
	yyval.lit.offset = yystack.l_mark[-1].lit.offset;
	 /*gen_lwi(0,$2.offset);*/
	/*gen_swi(0,$$.offset);*/
	}
break;
case 60:
#line 604 "hw3.y"
	{}
break;
case 61:
#line 605 "hw3.y"
	{}
break;
case 62:
#line 606 "hw3.y"
	{}
break;
case 63:
#line 607 "hw3.y"
	{}
break;
case 64:
#line 608 "hw3.y"
	{}
break;
case 65:
#line 609 "hw3.y"
	{}
break;
case 66:
#line 610 "hw3.y"
	{}
break;
case 67:
#line 611 "hw3.y"
	{}
break;
case 68:
#line 612 "hw3.y"
	{}
break;
case 69:
#line 613 "hw3.y"
	{}
break;
case 70:
#line 614 "hw3.y"
	{}
break;
case 71:
#line 615 "hw3.y"
	{}
break;
case 72:
#line 616 "hw3.y"
	{}
break;
case 73:
#line 617 "hw3.y"
	{}
break;
case 74:
#line 618 "hw3.y"
	{}
break;
case 75:
#line 619 "hw3.y"
	{}
break;
case 76:
#line 620 "hw3.y"
	{}
break;
case 77:
#line 621 "hw3.y"
	{}
break;
case 78:
#line 622 "hw3.y"
	{}
break;
case 79:
#line 623 "hw3.y"
	{}
break;
case 80:
#line 630 "hw3.y"
	{}
break;
case 81:
#line 631 "hw3.y"
	{}
break;
case 82:
#line 634 "hw3.y"
	{}
break;
case 83:
#line 635 "hw3.y"
	{}
break;
case 84:
#line 638 "hw3.y"
	{  Init_Expr();   }
break;
case 85:
#line 638 "hw3.y"
	{ 
 int i = look_up_symbol(yystack.l_mark[-4].sval); 
 table[i].ival = yystack.l_mark[-1].lit.ival;
 End_Expr(); 
 /* should  implicit type conversion ??*/  
 if(yystack.l_mark[-1].lit.offset>=0){
  gen_lwi(0,yystack.l_mark[-1].lit.offset);
 }
 else{
  gen_ori(0,yystack.l_mark[-1].lit.offset*(-1),0);
 }
 gen_swi(0,table[i].stack_offset);
 /* push var back*/ 
 }
break;
case 86:
#line 652 "hw3.y"
	{}
break;
case 87:
#line 653 "hw3.y"
	{}
break;
case 88:
#line 654 "hw3.y"
	{}
break;
case 89:
#line 655 "hw3.y"
	{}
break;
case 90:
#line 656 "hw3.y"
	{}
break;
case 92:
#line 660 "hw3.y"
	{}
break;
case 93:
#line 661 "hw3.y"
	{}
break;
case 94:
#line 662 "hw3.y"
	{}
break;
case 95:
#line 666 "hw3.y"
	{Init_Expr();}
break;
case 96:
#line 666 "hw3.y"
	{ End_Expr();}
break;
case 97:
#line 666 "hw3.y"
	{
   
   int L = labelCount;
   labelCount ++;
   push_lstack(L);
   if(yystack.l_mark[-2].lit.offset>=0){
        gen_lwi(0,yystack.l_mark[-2].lit.offset);
        gen_slti(0,0,1);
        gen_bnez(0,L);
   }
   else{
      gen_slti(0,-yystack.l_mark[-2].lit.offset,1);
      gen_bnez(0,L);
   }

}
break;
case 98:
#line 681 "hw3.y"
	{
   
}
break;
case 99:
#line 686 "hw3.y"
	{
		int L = pop_lstack();
		gen_label(L);
	}
break;
case 100:
#line 691 "hw3.y"
	{
		int L = labelCount;
		labelCount++;		
		gen_j(L);
		int L2 = pop_lstack();
		gen_label(L2);
		push_lstack(L);
	 }
break;
case 101:
#line 699 "hw3.y"
	{
		 int L = pop_lstack();
		 gen_label(L);
	}
break;
case 102:
#line 705 "hw3.y"
	{Init_Expr(); }
break;
case 103:
#line 705 "hw3.y"
	{
	End_Expr(); 
	int L  = labelCount++;
	int L2 = labelCount++; 
	gen_j(L2);
	 gen_label(L) ;
	 push_lstack(L);
	 push_lstack(L2);
	}
break;
case 104:
#line 714 "hw3.y"
	{
	int L2 = pop_lstack();
	int L =  pop_lstack(); 
        gen_label(L2);
        if(yystack.l_mark[-3].lit.offset>=0){
           gen_lwi(0,yystack.l_mark[-3].lit.offset);
           gen_slti(0,0,1);
           gen_beqz(0,L);
        }
        else{
           gen_slti(0,-yystack.l_mark[-3].lit.offset,1);
           gen_beqz(0,L);
        }
      
      }
break;
case 105:
#line 729 "hw3.y"
	{}
break;
case 106:
#line 732 "hw3.y"
	{}
break;
case 107:
#line 734 "hw3.y"
	{}
break;
case 108:
#line 736 "hw3.y"
	{}
break;
case 109:
#line 737 "hw3.y"
	{}
break;
case 110:
#line 740 "hw3.y"
	{}
break;
case 111:
#line 741 "hw3.y"
	{}
break;
case 112:
#line 744 "hw3.y"
	{}
break;
case 113:
#line 745 "hw3.y"
	{}
break;
case 114:
#line 756 "hw3.y"
	{}
break;
case 115:
#line 757 "hw3.y"
	{}
break;
case 116:
#line 759 "hw3.y"
	{}
break;
case 117:
#line 760 "hw3.y"
	{}
break;
case 118:
#line 762 "hw3.y"
	{}
break;
case 119:
#line 765 "hw3.y"
	{}
break;
case 120:
#line 766 "hw3.y"
	{}
break;
case 121:
#line 769 "hw3.y"
	{}
break;
case 122:
#line 770 "hw3.y"
	{}
break;
case 123:
#line 773 "hw3.y"
	{}
break;
case 124:
#line 774 "hw3.y"
	{}
break;
case 125:
#line 777 "hw3.y"
	{}
break;
case 126:
#line 778 "hw3.y"
	{}
break;
case 127:
#line 782 "hw3.y"
	{ Init_Expr(); }
break;
case 128:
#line 782 "hw3.y"
	{ 
    
    End_Expr();
    yyval.lit.type = yystack.l_mark[0].lit.type;
    yyval.lit.offset = yystack.l_mark[0].lit.offset;
    yyval.lit.ival = yystack.l_mark[0].lit.ival;
    
    /*gen_lwi(0,$2.offset);*/
  }
break;
case 129:
#line 793 "hw3.y"
	{}
break;
case 130:
#line 796 "hw3.y"
	{}
break;
case 131:
#line 797 "hw3.y"
	{}
break;
case 132:
#line 800 "hw3.y"
	{}
break;
case 133:
#line 801 "hw3.y"
	{}
break;
case 134:
#line 804 "hw3.y"
	{}
break;
case 136:
#line 812 "hw3.y"
	{}
break;
case 137:
#line 813 "hw3.y"
	{}
break;
case 138:
#line 816 "hw3.y"
	{}
break;
case 139:
#line 822 "hw3.y"
	{}
break;
case 140:
#line 823 "hw3.y"
	{}
break;
case 141:
#line 826 "hw3.y"
	{}
break;
case 142:
#line 830 "hw3.y"
	{ yyval.ival = 0;}
break;
case 143:
#line 831 "hw3.y"
	{ yyval.ival = 1;}
break;
case 144:
#line 832 "hw3.y"
	{ yyval.ival = 2;}
break;
case 145:
#line 833 "hw3.y"
	{ yyval.ival = 4;}
break;
case 146:
#line 837 "hw3.y"
	{ yyval.lit.type = 2; yyval.lit.cval = yystack.l_mark[0].cval;}
break;
case 147:
#line 838 "hw3.y"
	{ yyval.lit.type = 0; yyval.lit.ival = yystack.l_mark[0].ival;}
break;
case 148:
#line 839 "hw3.y"
	{ yyval.lit.type = 1; yyval.lit.dval = yystack.l_mark[0].dval;}
break;
case 149:
#line 840 "hw3.y"
	{ yyval.lit.type = 4; yyval.lit.bval = yystack.l_mark[0].ival;}
break;
case 150:
#line 841 "hw3.y"
	{  /* no array or pointer, so no string */ }
break;
case 151:
#line 844 "hw3.y"
	{ Init_Expr();}
break;
case 152:
#line 844 "hw3.y"
	{
        End_Expr();
        if(yystack.l_mark[-4].lit.offset>=0){
        gen_lwi(0,yystack.l_mark[-4].lit.offset);
        }
        else{
        gen_ori(0,yystack.l_mark[-4].lit.offset*(-1),0);
        }
      	if(yystack.l_mark[-2].ival == 1){
              gen_movi(1,1);
      	}
	     else{
	         gen_movi(1,0);
	     }
        gen_bal("digitalWrite");

        }
break;
case 153:
#line 861 "hw3.y"
	{Init_Expr();}
break;
case 154:
#line 861 "hw3.y"
	{
        End_Expr();
	if(yystack.l_mark[-2].lit.offset>=0){
        gen_lwi(0,yystack.l_mark[-2].lit.offset);
        }
        else{
        gen_ori(0,yystack.l_mark[-2].lit.offset*(-1),0);
        }
	gen_bal("delay");
        
     }
break;
#line 2344 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
