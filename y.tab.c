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
int para_table[10];
int para_index = 0;
int expr_comma_count = 0;
int expr_table[10];
int errorFlag = 0;
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

#line 56 "hw3.y"
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
#line 84 "y.tab.c"

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
    0,    0,    0,    0,    5,    5,   16,   16,   18,   18,
   18,   18,   20,   20,   20,   20,   20,   20,   20,   20,
   21,   21,    4,   15,   15,   24,   24,   24,   24,   24,
   26,   26,   27,   27,   28,   28,   29,   29,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,   31,
   31,   31,   31,   31,   31,   31,   31,   31,   31,   31,
   31,   31,   31,   31,   31,   31,   31,   31,   31,   32,
   32,   33,   33,   33,   35,   35,   36,   36,   36,   36,
   37,   37,   38,   38,   39,   34,   34,   34,   34,   34,
   34,   34,   42,   43,   44,    9,   10,   46,   10,   47,
   48,    8,    8,   41,   40,   50,   50,   52,   52,   51,
   51,   14,   14,   25,   25,   53,   13,   54,   45,   55,
   49,   30,   30,   56,   56,   57,   57,   58,   58,   59,
    3,   23,   19,   19,   11,   11,   12,   12,   22,   22,
   60,   17,   17,   61,    6,    6,    6,    6,    1,    1,
    1,    1,    1,   62,    7,   63,    7,
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
    1,    2,    1,    3,    0,    1,    2,    1,    3,    3,
    0,    1,    2,    1,    0,    5,    1,    1,    1,    1,
    1,    5,    0,    0,    0,    8,    1,    0,    4,    0,
    0,    7,    7,    9,    8,    2,    1,    4,    4,    0,
    3,    6,    6,    6,    6,    0,    8,    0,    5,    0,
    5,    0,    1,    3,    1,    0,    1,    3,    1,    0,
    3,    4,    0,    1,    3,    1,    3,    2,    2,    1,
    3,    2,    1,    3,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    0,    8,    0,    6,
};
static const short yydefred[] = {                         0,
  155,  156,  158,  157,    0,    0,    0,    0,    0,    0,
    8,    0,    0,    0,    0,    0,    0,    0,    0,   25,
   28,    0,    7,    0,    0,    0,    0,  140,    0,   17,
    0,  150,   11,    0,    0,    0,    0,    0,   24,    0,
    0,    0,  146,    0,    0,   22,   12,    0,    0,    0,
    0,    0,   19,  149,    0,    0,    0,    0,   29,    0,
    0,    0,  163,  160,  162,  159,  161,   23,    0,    0,
    0,    0,    0,    0,   39,    0,    0,  151,    0,   14,
    0,    0,   30,    0,    0,  145,   10,  128,  123,   21,
    9,  126,  122,    0,    0,    0,  153,    0,   58,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   41,   42,    0,    0,    0,    0,   60,
    0,    0,    0,    0,   15,    0,    0,    0,    0,    0,
    0,    0,    0,  152,   59,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   46,   47,   48,    0,   78,
    0,   62,   63,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  142,    0,   27,  125,
   26,  124,    0,    0,    0,    0,   34,    0,   43,    0,
  154,   79,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   66,   67,   68,    0,    0,    0,    0,    0,
    0,  103,    0,    0,    0,    0,    0,    0,   97,   99,
   98,   94,    0,    0,  100,  101,   33,    0,    0,    0,
   35,    0,    0,    0,    0,  110,  130,    0,  164,  166,
   95,  129,   93,    0,   36,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  102,    0,
    0,    0,    0,   88,    0,    0,    0,    0,    0,   96,
  127,    0,    0,  117,  105,    0,    0,  131,    0,    0,
   87,    0,    0,  167,    0,    0,    0,    0,  116,    0,
    0,  112,   90,   89,  113,    0,    0,    0,    0,  115,
  106,    0,    0,  165,  119,    0,   83,  118,  121,  108,
  114,    0,   82,    0,   84,  109,
};
static const short yydgoto[] = {                          7,
   75,  239,   30,   46,   77,   41,  209,  210,  211,  301,
   42,   43,   93,    9,   19,   10,   96,   11,   44,   15,
   26,   31,   53,   20,   21,  175,  176,  177,  240,  131,
  122,  305,  306,  212,  265,  266,  213,  214,  246,  215,
  216,  224,  261,  290,   89,  314,  241,  263,  228,  273,
  288,  274,  129,  128,  242,  132,  123,  124,   50,   32,
   97,  244,  245,
};
static const short yysindex[] = {                       364,
    0,    0,    0,    0, -246,   37,    0, -210,  426,  364,
    0,   15, -198,  263,    2, -194,   37, -159,  426,    0,
    0,  426,    0,   37,   88,   46,   37,    0,  -73,    0,
   60,    0,    0,  -24,  202, -198,  301,   94,    0,  426,
    8,  234,    0,  249,  -20,    0,    0,   83,  344,   17,
  294,  219,    0,    0,  176,   37,  229,   37,    0,  298,
   37,  -26,    0,    0,    0,    0,    0,    0,   88,   18,
  -10,   17,   17,   17,    0,  146, -140,    0,   54,    0,
   60,  350,    0,  360,  298,    0,    0,    0,    0,    0,
    0,    0,    0,   17,   17,  304,    0,  174,    0,   42,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,    0,    0,  304,   54,   54,   54,    0,
   82,  153,  283,  371,    0,  140,  166,  378,  378,  146,
  382,  385,   64,    0,    0,  174,  160,  351,  351,  351,
  351,  351,  351,  296,  296,    0,    0,    0,  181,    0,
   71,    0,    0,   54,   54,   54,   54,   54,   54,   54,
   54,   54,   54,   54,   54,   54,    0,   54,    0,    0,
    0,    0,   37,  179,  437,  378,    0,  437,    0,   17,
    0,    0,  181,  167,  483,  483,  483,  483,  483,  483,
  480,  480,    0,    0,    0,  153, -198,  176,  266,   24,
  410,    0,  412,  419,  341,  425,  432,  405,    0,    0,
    0,    0,  353,  437,    0,    0,    0,  200,  146,  278,
    0,   17,  227,  447,   17,    0,    0,  214,    0,    0,
    0,    0,    0,   17,    0,  452,  456,   17,  146,  440,
   17,  378,  465,   17,   17,   17,   85,  448,  388,  146,
   17,  146,  437,   17,   92,  118,  125,  389,    0,  237,
  474,  478,  497,    0,  399,  496,  132,  281,  482,    0,
    0, -188,  188,    0,    0,   17,  341,    0,  485,  492,
    0,  499,  501,    0,  502,  503,  505,  439,    0,  444,
  529,    0,    0,    0,    0,  516,  437,  437,  437,    0,
    0,  305,  341,    0,    0,  601,    0,    0,    0,    0,
    0,  522,    0,  444,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,  583,    0,
    0,    0,    0,  288,    0,    0,    0,    0,  584,    0,
    0,  591,    0,  554,    0,    0,  554,    0,    0,    0,
  323,    0,    0,    0,    0,    0,  288,    0,    0,  597,
    0,  560,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  324,  554,    0,  554,    0,  322,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -28,    0,    0,    0,    0,  331,    7,    0,  477,    0,
  340,    0,    0,    0,  356,    0,    0,    0,    0,    0,
    0,    0,    0,  567,    0,  -37,    0,  545,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   -2,    0,    0,    0,    0,
   31,  -43,    0,  487,    0,    0,    0,  723,  686,  381,
    0,  569,    0,    0,    0,  562,  -23,  442,  450,  459,
  472,  495,  512,  430,  436,    0,    0,    0,  -15,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  489,  588,    0,  342,    0,    0,
    0,    0,   51,   76,  518,  525,  532,  538,  549,  555,
  261,  383,    0,    0,    0,   -6,    0,  288,    0,  563,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -105,    0,    0,    0,    0,  441,    0,
    0,  567,    0,    0,  557,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  238,    0,
    0,  723,    0,    0,    0,    0,    0,    0,    0,  592,
  557,  593,  511,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  519,    0,    0,    0,    0,
    0,    0,  521,    0,    0,  596,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -88,  -88,  489,    0,
    0,  408,    0,    0,    0,  -39,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  871,  827,  594,  578,  749,  613,    0,    0,    0,    0,
    0,  587,  527,  646,  636,    0,    0,  649,  208,  -16,
  -33,  279,  580,  213,    0, -117,    0,  486, -223,  451,
  933,  366,    0,  354,    0,    0, -151,    0,    0,    0,
    0,    0,    0,    0,  -46,    0,    0,    0, -137,    0,
    0,  393,    0,    0,    0,    0,    0,    0,    0,   65,
  579,    0,    0,
};
#define YYTABLESIZE 1101
static const short yytable[] = {                          5,
  139,   38,   57,    5,    5,    5,    5,    5,    6,    5,
   12,  178,    6,    6,    6,    6,    6,   57,    6,   92,
   57,    5,    5,    5,    5,   75,  218,  262,   75,   94,
    6,    6,   87,    6,    6,   57,   80,  138,    6,    6,
    6,    6,    6,   40,    6,   34,   14,   40,   40,   40,
   40,   40,  291,   40,   24,    5,   74,    6,   25,    6,
   33,   73,   35,  222,    6,   40,   40,   61,   40,   57,
  285,   61,   61,   61,   61,   61,   91,   61,  113,  170,
   95,  139,  135,  111,  109,   81,  110,    5,  112,   48,
   61,   76,   61,  119,   76,   54,   88,   37,  118,   40,
  113,  108,  286,  107,   47,  111,  109,  166,  110,   75,
  112,  182,  164,  162,   95,  163,   77,  165,  138,   77,
   52,  113,    6,  108,  253,  107,  111,  109,  113,  110,
  161,  112,  160,  111,  109,  268,  110,   34,  112,  292,
   92,  114,  115,  258,  108,   54,  107,  309,   45,   54,
   29,  108,   59,  107,  113,   61,  181,  199,  269,  111,
  109,  113,  110,  220,  112,  311,  111,  109,  113,  110,
   92,  112,  282,  111,  109,   76,  110,  108,  112,  107,
   80,   80,  113,  270,  108,   51,  107,  111,  109,  166,
  110,  108,  112,  107,  164,  162,  113,  163,  169,  165,
   77,  111,  109,  166,  110,  108,  112,  107,  164,  162,
  113,  163,  161,  165,  160,  111,  109,  166,  110,  108,
  112,  107,  164,  162,  171,  163,  161,  165,  160,   81,
   81,   39,   55,  108,   49,  107,   28,   63,   64,   65,
  161,   56,  160,  302,    5,    5,    5,    5,    5,    5,
    5,    5,   39,    6,    6,    6,    6,    6,    6,    6,
    6,   57,   88,   82,   60,   84,   29,  316,   75,   75,
   66,   67,   48,   71,   63,   64,   65,   61,   38,    6,
    6,    6,    6,    6,    6,    6,    6,   83,   92,   62,
   40,   40,   40,   40,   40,   40,   38,    1,    2,    3,
    4,   64,   27,   64,   64,   64,   72,   66,   67,   34,
  116,   63,   64,   65,   61,   61,   61,   61,   61,   61,
   64,   48,   64,   28,  221,  101,  102,  103,  104,  105,
  106,   18,  113,   81,   76,   76,  235,  111,   85,   69,
   58,   79,  112,  117,   66,   67,   18,  101,  102,  103,
  104,  105,  106,   29,  154,  155,  156,  157,  158,  159,
   77,   28,  148,  152,  153,  148,   20,   13,  101,  102,
  103,  104,  105,  106,  141,  101,  102,  103,  104,  105,
  106,   20,   13,   16,   70,   64,   78,  113,   29,  141,
  126,   29,  111,  109,   95,  110,  147,  112,   16,  147,
  127,  101,  102,  103,  104,  105,  106,  167,  101,  102,
  103,  104,  105,  106,  168,  101,  102,  103,  104,  105,
  106,  135,  179,   65,  135,   65,   65,   65,  180,  101,
  102,  103,  104,  105,  106,  198,  154,  155,  156,  157,
  158,  159,   65,  101,   65,  103,  104,  105,  106,  223,
  154,  225,  156,  157,  158,  159,  272,  287,  226,  103,
  104,  105,  106,  227,  229,  231,  156,  157,  158,  159,
   44,  230,   44,   44,   44,  234,   45,  232,   45,   45,
   45,  134,   51,  237,  134,   51,  238,  243,   44,   44,
   52,   44,  248,   52,   45,   45,  249,   45,  251,   53,
   51,   51,   53,   51,  254,  272,  259,   65,   52,   52,
  260,   52,   54,  271,  275,   54,  166,   53,   53,  166,
   53,  164,   44,  278,  164,  162,  165,  163,   45,  165,
   54,   54,  107,   54,   51,   49,  276,  277,   49,  283,
  284,  296,   52,  293,   64,   64,   64,   64,   64,   64,
  294,   53,   50,   49,   49,   50,   49,  295,   71,  297,
  298,   71,  299,  300,   54,   72,   88,  233,   72,  303,
   50,   50,   73,   50,  304,   73,  310,   71,   74,   71,
  315,   74,    3,    1,   72,   55,   72,   49,   55,   69,
    4,   73,   69,   73,  143,   70,    2,   74,   70,   74,
  144,  136,   56,   55,   50,   56,  264,  132,   69,  133,
   69,  137,    8,   91,   70,   37,   70,   91,   13,  281,
   56,   18,    8,    6,    1,    2,    3,    4,    5,   36,
    6,   18,  104,  111,   18,   85,   37,   55,    1,    2,
    3,    4,   71,   86,  173,  120,   90,   86,   80,   72,
  307,  307,   18,  172,   56,   22,   73,   40,   23,  313,
  125,  217,   74,  308,  107,  289,   65,   65,   65,   65,
   65,   65,  236,   69,  134,  107,  107,  107,  107,   70,
  107,  107,  107,  107,  107,  107,    1,    2,    3,    4,
   16,    0,   17,  200,    0,    0,    0,    0,    0,    0,
    0,    0,  107,  107,  201,    0,    0,  202,    0,  203,
  204,  205,   32,   44,   44,   44,   44,   44,   44,   45,
   45,   45,   45,   45,   45,   51,   51,   51,   51,   51,
   51,  206,  207,   52,   52,   52,   52,   52,   52,    0,
  174,  174,   53,   53,   53,   53,   53,   53,    0,    0,
    0,    0,  200,    0,    0,   54,   54,   54,   54,   54,
   54,    0,    0,  201,    0,    0,  202,    0,  203,  204,
  205,    0,  279,  280,    0,    0,    0,    0,   49,   49,
   49,   49,   49,   49,    0,  197,    0,    0,  174,    0,
  206,  207,    0,    0,    0,   50,   50,   50,   50,   50,
   50,   71,   71,   71,   71,   71,   71,    0,   72,   72,
   72,   72,   72,   72,    0,   73,   73,   73,   73,   73,
   73,   74,   74,   74,   74,   74,   74,  121,   55,   55,
    0,    0,   69,   69,   69,   69,   69,   69,   70,   70,
   70,   70,   70,   70,   32,   56,   56,   31,    0,    0,
    0,    0,    0,    0,  174,   32,    0,  200,   32,    0,
   32,   32,   32,   32,    0,  121,  121,  121,  201,    0,
    0,  202,    0,  203,  204,  205,   76,    0,  312,    0,
    0,    0,   32,   32,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  206,  207,    0,   98,   99,
  100,    0,  121,  121,  121,  121,  121,  121,  121,  121,
  121,  121,  121,  121,  121,   68,  121,    0,    0,    0,
  130,  133,    0,  208,    0,    0,  208,  136,  137,  138,
  139,  140,  141,  142,  143,  144,  145,  146,  147,  148,
    0,    0,   31,    0,    0,    0,    0,    0,    0,  120,
    0,    0,    0,   31,    0,    0,   31,    0,   31,   31,
   31,   31,  208,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   31,
   31,   31,    0,    0,    0,    0,    0,  120,  120,  120,
   31,    0,    0,   31,    0,   31,   31,   31,    0,    0,
    0,  208,    0,    0,    0,    0,  219,    0,    0,    0,
    0,    0,    0,    0,  208,    0,    0,   31,   31,    0,
    0,    0,    0,    0,  120,  120,  120,  120,  120,  120,
  120,  120,  120,  120,  120,  120,  120,    0,  120,    0,
    0,    0,    0,    0,    0,  208,  208,  208,  130,  149,
  150,  151,    0,    0,  208,    0,    0,    0,    0,    0,
  247,    0,    0,    0,  250,    0,    0,  252,    0,    0,
  255,  256,  257,    0,    0,    0,    0,    0,    0,    0,
  267,    0,    0,    0,    0,    0,  183,  184,  185,  186,
  187,  188,  189,  190,  191,  192,  193,  194,  195,    0,
  196,
};
static const short yycheck[] = {                         37,
   44,   18,   36,   41,   42,   43,   44,   45,   37,   47,
  257,  129,   41,   42,   43,   44,   45,   41,   47,  125,
   44,   59,   60,   61,   62,   41,  178,  251,   44,   40,
   59,   60,   59,   62,   37,   59,  125,   44,   41,   42,
   43,   44,   45,   37,   47,   44,  257,   41,   42,   43,
   44,   45,  276,   47,   40,   93,   40,   60,  257,   62,
   59,   45,  257,   40,   93,   59,   60,   37,   62,   93,
  259,   41,   42,   43,   44,   45,   59,   47,   37,  126,
   91,  125,   41,   42,   43,  125,   45,  125,   47,   44,
   60,   41,   62,   40,   44,   31,  123,  257,   45,   93,
   37,   60,  291,   62,   59,   42,   43,   37,   45,  125,
   47,   41,   42,   43,   91,   45,   41,   47,  125,   44,
   61,   37,  125,   60,  242,   62,   42,   43,   37,   45,
   60,   47,   62,   42,   43,   44,   45,   44,   47,  277,
  123,  282,  283,   59,   60,   81,   62,  299,   61,   85,
   91,   60,   59,   62,   37,  125,   93,  174,   41,   42,
   43,   37,   45,  197,   47,  303,   42,   43,   37,   45,
  276,   47,   41,   42,   43,  125,   45,   60,   47,   62,
  269,  270,   37,   59,   60,  259,   62,   42,   43,   37,
   45,   60,   47,   62,   42,   43,   37,   45,   59,   47,
  125,   42,   43,   37,   45,   60,   47,   62,   42,   43,
   37,   45,   60,   47,   62,   42,   43,   37,   45,   60,
   47,   62,   42,   43,   59,   45,   60,   47,   62,  269,
  270,   19,  257,   60,   27,   62,   61,  258,  259,  260,
   60,   40,   62,  290,  282,  283,  284,  285,  286,  287,
  288,  289,   40,  282,  283,  284,  285,  286,  287,  288,
  289,  285,  123,   56,  257,   58,   91,  314,  284,  285,
  291,  292,   44,  257,  258,  259,  260,   44,   41,  282,
  283,  284,  285,  286,  287,  288,  289,   59,  123,   41,
  284,  285,  286,  287,  288,  289,   59,  261,  262,  263,
  264,   41,   40,   43,   44,   45,  290,  291,  292,   44,
  257,  258,  259,  260,  284,  285,  286,  287,  288,  289,
   60,   44,   62,   61,   59,  284,  285,  286,  287,  288,
  289,   44,   37,   55,  284,  285,   59,   42,   60,  257,
   40,  123,   47,  290,  291,  292,   59,  284,  285,  286,
  287,  288,  289,   91,  284,  285,  286,  287,  288,  289,
  285,   61,   41,  282,  283,   44,   44,   44,  284,  285,
  286,  287,  288,  289,   44,  284,  285,  286,  287,  288,
  289,   59,   59,   44,   41,  125,   93,   37,   91,   59,
   41,   91,   42,   43,   91,   45,   41,   47,   59,   44,
   41,  284,  285,  286,  287,  288,  289,  125,  284,  285,
  286,  287,  288,  289,   44,  284,  285,  286,  287,  288,
  289,   41,   41,   41,   44,   43,   44,   45,   44,  284,
  285,  286,  287,  288,  289,  257,  284,  285,  286,  287,
  288,  289,   60,  284,   62,  286,  287,  288,  289,   40,
  284,   40,  286,  287,  288,  289,  269,  270,   40,  286,
  287,  288,  289,  123,   40,   61,  286,  287,  288,  289,
   41,   40,   43,   44,   45,  276,   41,  125,   43,   44,
   45,   41,   41,  257,   44,   44,   40,  274,   59,   60,
   41,   62,   41,   44,   59,   60,   41,   62,   59,   41,
   59,   60,   44,   62,   40,  269,   59,  125,   59,   60,
  123,   62,   41,  125,   41,   44,   37,   59,   60,   37,
   62,   42,   93,  125,   42,   43,   47,   45,   93,   47,
   59,   60,  125,   62,   93,   41,   59,   41,   44,  259,
   59,   41,   93,   59,  284,  285,  286,  287,  288,  289,
   59,   93,   41,   59,   60,   44,   62,   59,   41,   58,
   58,   44,   58,  125,   93,   41,  123,  214,   44,   41,
   59,   60,   41,   62,   59,   44,  272,   60,   41,   62,
   59,   44,    0,    0,   60,   41,   62,   93,   44,   41,
    0,   60,   44,   62,   41,   41,    0,   60,   44,   62,
   41,  125,   41,   59,   93,   44,  253,   41,   60,   41,
   62,  125,    0,  125,   60,   59,   62,  276,    6,  266,
   59,    9,   10,   61,  261,  262,  263,  264,  265,   17,
  267,   19,   41,   41,   22,  125,   41,   93,  261,  262,
  263,  264,  125,  125,  267,  125,   69,   61,   55,  125,
  297,  298,   40,  127,   93,   10,  125,   22,   10,  306,
   81,  176,  125,  298,  257,  273,  284,  285,  286,  287,
  288,  289,  222,  125,   96,  268,  269,  270,  271,  125,
  273,  274,  275,  276,  277,  278,  261,  262,  263,  264,
  265,   -1,  267,  257,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  295,  296,  268,   -1,   -1,  271,   -1,  273,
  274,  275,  125,  284,  285,  286,  287,  288,  289,  284,
  285,  286,  287,  288,  289,  284,  285,  286,  287,  288,
  289,  295,  296,  284,  285,  286,  287,  288,  289,   -1,
  128,  129,  284,  285,  286,  287,  288,  289,   -1,   -1,
   -1,   -1,  257,   -1,   -1,  284,  285,  286,  287,  288,
  289,   -1,   -1,  268,   -1,   -1,  271,   -1,  273,  274,
  275,   -1,  277,  278,   -1,   -1,   -1,   -1,  284,  285,
  286,  287,  288,  289,   -1,  173,   -1,   -1,  176,   -1,
  295,  296,   -1,   -1,   -1,  284,  285,  286,  287,  288,
  289,  284,  285,  286,  287,  288,  289,   -1,  284,  285,
  286,  287,  288,  289,   -1,  284,  285,  286,  287,  288,
  289,  284,  285,  286,  287,  288,  289,   79,  284,  285,
   -1,   -1,  284,  285,  286,  287,  288,  289,  284,  285,
  286,  287,  288,  289,  257,  284,  285,  125,   -1,   -1,
   -1,   -1,   -1,   -1,  242,  268,   -1,  257,  271,   -1,
  273,  274,  275,  276,   -1,  117,  118,  119,  268,   -1,
   -1,  271,   -1,  273,  274,  275,   50,   -1,  278,   -1,
   -1,   -1,  295,  296,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  295,  296,   -1,   72,   73,
   74,   -1,  154,  155,  156,  157,  158,  159,  160,  161,
  162,  163,  164,  165,  166,   45,  168,   -1,   -1,   -1,
   94,   95,   -1,  175,   -1,   -1,  178,  101,  102,  103,
  104,  105,  106,  107,  108,  109,  110,  111,  112,  113,
   -1,   -1,  257,   -1,   -1,   -1,   -1,   -1,   -1,   79,
   -1,   -1,   -1,  268,   -1,   -1,  271,   -1,  273,  274,
  275,  276,  214,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
  295,  296,   -1,   -1,   -1,   -1,   -1,  117,  118,  119,
  268,   -1,   -1,  271,   -1,  273,  274,  275,   -1,   -1,
   -1,  253,   -1,   -1,   -1,   -1,  180,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  266,   -1,   -1,  295,  296,   -1,
   -1,   -1,   -1,   -1,  154,  155,  156,  157,  158,  159,
  160,  161,  162,  163,  164,  165,  166,   -1,  168,   -1,
   -1,   -1,   -1,   -1,   -1,  297,  298,  299,  222,  117,
  118,  119,   -1,   -1,  306,   -1,   -1,   -1,   -1,   -1,
  234,   -1,   -1,   -1,  238,   -1,   -1,  241,   -1,   -1,
  244,  245,  246,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  254,   -1,   -1,   -1,   -1,   -1,  154,  155,  156,  157,
  158,  159,  160,  161,  162,  163,  164,  165,  166,   -1,
  168,
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
"stmts_switch_x :",
"stmts_switch_x : stmts_switch",
"stmts_switch : stmts_switch stmt",
"stmts_switch : stmt",
"stmts_switch : stmts_switch BREAK ';'",
"stmts_loop_x :",
"stmts_loop_x : stmts_loop",
"stmts_loop : stmts_loop stmt",
"stmts_loop : stmt",
"stmts_loop : stmts_loop BREAK ';'",
"stmts_loop : stmts_loop CONTINUE ';'",
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
"$$2 :",
"$$3 :",
"$$4 :",
"if_stmt : IF $$2 '(' expr $$3 ')' $$4 else_x",
"else_x : compound",
"$$5 :",
"else_x : compound ELSE $$5 compound",
"$$6 :",
"$$7 :",
"while_stmt : WHILE '(' $$6 expr $$7 ')' loop_compound",
"while_stmt : DO loop_compound WHILE '(' expr ')' ';'",
"for_stmt : FOR '(' expr_x ';' expr_x ';' expr_x ')' loop_compound",
"switch_stmt : SWITCH '(' IDEN ')' '{' cases default_x '}'",
"cases : cases case",
"cases : case",
"case : CASE CHAR_LIT ':' stmts_switch_x",
"case : CASE INT_LIT ':' stmts_switch_x",
"default_x :",
"default_x : DEFAULT ':' stmts_x",
"first_func_def : type IDEN '(' para_in ')' nonvoid_compound",
"first_func_def : VOID IDEN '(' para_in ')' compound",
"func_def : type IDEN '(' para_in ')' nonvoid_compound",
"func_def : VOID IDEN '(' para_in ')' compound",
"$$8 :",
"nonvoid_compound : '{' $$8 decs_x stmts_x RETURN expr ';' '}'",
"$$9 :",
"compound : '{' $$9 decs_x stmts_x '}'",
"$$10 :",
"loop_compound : '{' $$10 decs_x stmts_loop_x '}'",
"exprs_comma_x :",
"exprs_comma_x : exprs_comma",
"exprs_comma : exprs_comma ',' expr",
"exprs_comma : expr",
"exprs_comma_no_invoke_x :",
"exprs_comma_no_invoke_x : exprs_comma_no_invoke",
"exprs_comma_no_invoke : exprs_comma_no_invoke ',' expr_no_invoke",
"exprs_comma_no_invoke : expr_no_invoke",
"$$11 :",
"init : '=' $$11 expr",
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
"$$12 :",
"blink : DIGITAL_WRITE '(' $$12 expr ',' INT_LIT ')' ';'",
"$$13 :",
"blink : DELAY '(' $$13 expr ')' ';'",

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
#line 1364 "hw3.y"


int main(void)
{
    reg[0] = 1; // set reg 0, 1 ,5 not usable
    reg[1] = 1;
    reg[5] = 1;   
    init_symbol_table();
    init_ftable();
    int i;
    for(i=0;i<10;i++)
      para_table[i] = -1;
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

void Init_Type_Not_Match(){
  fprintf( stderr ,"Error at line %d : Initialization type not matched with declaration type\n",lineCount);
	errorFlag = 1;
}

int Check_Var_Not_Exist(char* s){
  int i = look_up_symbol(s);
  if(i>=0 && table[i].scope == cur_scope){
    fprintf(stderr, "Error at line %d :Re-declaration of already used variable name in a same scope\n",lineCount);
	errorFlag = 1;
    return 1;
  }
  return 0;
}

void Expr_Int_Double(){
  fprintf(stderr, "Error at line %d : Operand must be either integer or double!\n",lineCount);
	errorFlag = 1;
}

void Expr_Type_Not_Match(){
  fprintf(stderr,"Error at line %d : two operand type doesn't match each other!\n",lineCount);
	errorFlag = 1;
}

void Check_Var_Exist(char *s){
  int i = look_up_symbol(s);
  fprintf(stderr,"check%s\n",s);
  if(i<0){
    fprintf(stderr,"Error at line %d :Use a variable before it is declared!!\n",lineCount);
	errorFlag = 1; 
 }
}

void Function_Defined(){
  fprintf(stderr,"Error at line %d :Declare a function that has already been defined!\n",lineCount);
	errorFlag = 1;
}

void Function_DD_Not_Match(){
  fprintf(stderr,"Error at line %d :Function Declaration doesn't match definition!\n",lineCount);
	errorFlag = 1;
}

void Function_Re_Define(){
    fprintf(stderr,"Error at line %d :Function Re-Defined!!!\n",lineCount);
	errorFlag = 1;
}

void Function_ReDeclare(){
    fprintf(stderr,"Error at line %d :Function Re-declared!!\n",lineCount);
	errorFlag = 1;
}

void Function_Not_Declare(){
 fprintf(stderr,"Error at line %d :Function Defined without previous declaration!!\n",lineCount);
errorFlag = 1;
}

void Function_Not_Install(){
	errorFlag = 1;
    fprintf(stderr,"Error at line %d :Function hasn't been declared or defined before invocation!\n",lineCount);
}

void Function_Return_Not_Match(){
	errorFlag = 1;
    fprintf(stderr,"Error at line %d :Function returned value not match the return type!\n",lineCount);
}

void Function_Arg_Error(){
	errorFlag = 1;
    fprintf(stderr,"Error at line %d :Function argument doesn't match!!\n",lineCount);
}
void Function_No_Define(){
	  fprintf(stderr,"Error at line %d :Function declared but not defined!!\n",lineCount);
	errorFlag = 1;
}
#line 1131 "y.tab.c"

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
#line 101 "hw3.y"
	{
     int i;
     for(i=0;i<cur_fcounter;i++)
	if(ftable[i].declared && !ftable[i].defined)
		Function_No_Define();
     if(!errorFlag){
     printf("No syntax error!\n");
     Write_Assembly();
	}
    }
break;
case 2:
#line 111 "hw3.y"
	{ 
	     int i;
     for(i=0;i<cur_fcounter;i++)
        if(ftable[i].declared && !ftable[i].defined)
                Function_No_Define();

	if(!errorFlag){printf("No syntax error!\n");Write_Assembly();}}
break;
case 3:
#line 118 "hw3.y"
	{
	     int i;
	     for(i=0;i<cur_fcounter;i++)
        	if(ftable[i].declared && !ftable[i].defined)
                Function_No_Define();

	if(!errorFlag){printf("No syntax error!\n");Write_Assembly();}}
break;
case 4:
#line 125 "hw3.y"
	{
		     int i;
	     for(i=0;i<cur_fcounter;i++)
        	if(ftable[i].declared && !ftable[i].defined)
                Function_No_Define();

		if(!errorFlag){printf("No syntax error!\n");Write_Assembly();}}
break;
case 5:
#line 135 "hw3.y"
	{
      Check_Var_Exist(yystack.l_mark[-1].sval);
      /* supposely, there should be no array.........*/
   }
break;
case 6:
#line 139 "hw3.y"
	{
       
       Check_Var_Exist(yystack.l_mark[0].sval);
       yyval.sval = mstrcpy(yystack.l_mark[0].sval);
   }
break;
case 7:
#line 150 "hw3.y"
	{}
break;
case 8:
#line 151 "hw3.y"
	{}
break;
case 9:
#line 155 "hw3.y"
	{
    int i = look_up_function(yystack.l_mark[-4].sval);
    if(i>=0){ 
      if(ftable[i].defined==1){
          Function_Defined();
      }
      if(ftable[i].declared==1){
	  Function_ReDeclare();
      }

    }
    else{
      install_function(yystack.l_mark[-4].sval);
      int j,k;
      k=look_up_function(yystack.l_mark[-4].sval);
      for(j=0;j<para_index;j++){
        ftable[k].argType[j] = para_table[j];
      }
      ftable[k].argSize = j ;
      ftable[k].returnType = yystack.l_mark[-5].ival;
      ftable[k].declared = 1; 
    }
    para_index = 0;
  }
break;
case 10:
#line 179 "hw3.y"
	{
        int i = look_up_function(yystack.l_mark[-4].sval);
    if(i>=0){ 
      if(ftable[i].defined==1){
          Function_Defined();
      }
      if(ftable[i].declared==1){
	  Function_ReDeclare();
	}

    }
    else{
      install_function(yystack.l_mark[-4].sval);
      int j,k;
      k=look_up_function(yystack.l_mark[-4].sval);
      for(j=0;j<para_index;j++){
        ftable[k].argType[j] = para_table[j];
      }
      ftable[k].argSize = j ;
      ftable[k].returnType = 5;  /* 5 --> VOID!!!!*/
    }
    para_index = 0;

  }
break;
case 11:
#line 204 "hw3.y"
	{
     int i;
     for(i=0;i<init_index;i++){
        if(table[cur_counter-1-i].mtype == -1){
           table[cur_counter-1-i].mtype = yystack.l_mark[-2].ival;
	   printf("!!! %d \n",yystack.l_mark[-2].ival);
        }
        else if(table[cur_counter-1-i].mtype != yystack.l_mark[-2].ival){
           Init_Type_Not_Match();
	     table[cur_counter-1-i].mtype = yystack.l_mark[-2].ival;
        }
	printf("OAO\n");
     }
     init_index = 0;
  }
break;
case 12:
#line 219 "hw3.y"
	{
     int i;
     for(i=0;i<init_index;i++){
        if(table[cur_counter-1-i].mtype == -1){
           table[cur_counter-1-i].mtype = yystack.l_mark[-2].ival;
        }
        else if(table[cur_counter-1-i].mtype != yystack.l_mark[-2].ival){
           Init_Type_Not_Match();
	      table[cur_counter-1-i].mtype = yystack.l_mark[-3].ival;
        }
     }
     init_index = 0;
  }
break;
case 13:
#line 238 "hw3.y"
	{
         int c= Check_Var_Not_Exist(yystack.l_mark[0].sval);
          /* put value into stack */
          if(!c){
          install_symbol(yystack.l_mark[0].sval);   
          /*stack_cur_offset++; */
          init_index++;
         stack_cur_offset++;
         }
  }
break;
case 14:
#line 248 "hw3.y"
	{ 
        int c= Check_Var_Not_Exist(yystack.l_mark[-1].sval);
        /* put value into stack */
         if(!c){
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
   }
break;
case 15:
#line 273 "hw3.y"
	{}
break;
case 16:
#line 274 "hw3.y"
	{}
break;
case 17:
#line 275 "hw3.y"
	{ 
	       printf("b\n");
          int c =Check_Var_Not_Exist(yystack.l_mark[-1].sval);
         /* put value into stack*/
          if(!c){
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

          }
break;
case 18:
#line 301 "hw3.y"
	{ 
   
	        int c = Check_Var_Not_Exist(yystack.l_mark[0].sval);
          if(!c){
            /* put value into stack*/
		printf("install symbol\n");
            install_symbol(yystack.l_mark[0].sval);
	  
            init_index++;
            stack_cur_offset++;
          }
          }
break;
case 19:
#line 313 "hw3.y"
	{}
break;
case 20:
#line 314 "hw3.y"
	{}
break;
case 21:
#line 318 "hw3.y"
	{  
           int c= Check_Var_Not_Exist(yystack.l_mark[-1].sval);
        /* put value into stack */
         if(!c){
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

        }
break;
case 22:
#line 344 "hw3.y"
	{ 
            
           int c =Check_Var_Not_Exist(yystack.l_mark[-1].sval);
         /* put value into stack*/
          if(!c){
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
	}
break;
case 23:
#line 372 "hw3.y"
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
#line 396 "hw3.y"
	{}
break;
case 25:
#line 397 "hw3.y"
	{}
break;
case 26:
#line 401 "hw3.y"
	{
    int i = look_up_function(yystack.l_mark[-4].sval);
    if(i>=0){ 
      if(ftable[i].defined==1){
          Function_Defined();
      }
      if(ftable[i].declared==1){
		Function_ReDeclare();
	}
	
    }
    else{
      install_function(yystack.l_mark[-4].sval);
      int j,k;
      k=look_up_function(yystack.l_mark[-4].sval);
      for(j=0;j<para_index;j++){
        ftable[k].argType[j] = para_table[j];
      }
      ftable[k].argSize = j ;
      ftable[k].returnType = yystack.l_mark[-5].ival;
      ftable[k].declared = 1;
    }
    para_index = 0;
  }
break;
case 27:
#line 425 "hw3.y"
	{
        int i = look_up_function(yystack.l_mark[-4].sval);
    if(i>=0){ 
      if(ftable[i].defined==1){
          Function_Defined();
      }
	if(ftable[i].declared==1){
		Function_ReDeclare();
	}
    }
    else{
      install_function(yystack.l_mark[-4].sval);
      int j,k;
      k=look_up_function(yystack.l_mark[-4].sval);
      for(j=0;j<para_index;j++){
        ftable[k].argType[j] = para_table[j];
      }
      ftable[k].argSize = j ;
      ftable[k].returnType = 5;  /* 5 --> VOID!!!!*/
      ftable[k].declared = 1;
    }
    para_index = 0;

  }
break;
case 28:
#line 449 "hw3.y"
	{}
break;
case 29:
#line 450 "hw3.y"
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
case 30:
#line 464 "hw3.y"
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
case 31:
#line 479 "hw3.y"
	{}
break;
case 32:
#line 480 "hw3.y"
	{}
break;
case 33:
#line 484 "hw3.y"
	{}
break;
case 34:
#line 485 "hw3.y"
	{}
break;
case 35:
#line 488 "hw3.y"
	{
     int i;
     for(i=0;i<init_index;i++){
        if(table[cur_counter-1-i].mtype == -1){
           table[cur_counter-1-i].mtype = yystack.l_mark[-2].ival;
           printf("!!! %d \n",yystack.l_mark[-2].ival);
        }
        else if(table[cur_counter-1-i].mtype != yystack.l_mark[-2].ival){
           Init_Type_Not_Match();
	  table[cur_counter-1-i].mtype = yystack.l_mark[-2].ival;

        }
        printf("OAO\n");
     }
     init_index = 0;
  }
break;
case 36:
#line 504 "hw3.y"
	{
     int i;
     for(i=0;i<init_index;i++){
        if(table[cur_counter-1-i].mtype == -1){
           table[cur_counter-1-i].mtype = yystack.l_mark[-2].ival;
        }
        else if(table[cur_counter-1-i].mtype != yystack.l_mark[-2].ival){
           Init_Type_Not_Match();
		  table[cur_counter-1-i].mtype = yystack.l_mark[-3].ival;

        }
     }
     init_index = 0;
  }
break;
case 37:
#line 521 "hw3.y"
	{}
break;
case 38:
#line 522 "hw3.y"
	{}
break;
case 39:
#line 525 "hw3.y"
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
#line 541 "hw3.y"
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
#line 556 "hw3.y"
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
#line 583 "hw3.y"
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
#line 609 "hw3.y"
	{ 

      int i = look_up_function(yystack.l_mark[-3].sval);
      if(i<0){
       Function_Not_Install();
      }
      else{
       yyval.lit.type = ftable[i].returnType;
         int j;
	if(expr_comma_count != ftable[i].argSize){
		Function_Arg_Error();
	}else{
        for(j=0;j<expr_comma_count;j++){
            if(ftable[i].argType[j] != expr_table[j] ){
              Function_Arg_Error();
              break;
            }
        }
	}

      }
      expr_comma_count = 0;

  }
break;
case 44:
#line 634 "hw3.y"
	{ 

    if((yystack.l_mark[-2].lit.type!=0&&yystack.l_mark[-2].lit.type!=1) || (yystack.l_mark[0].lit.type!=0 && yystack.l_mark[0].lit.type!=1) )
      Expr_Int_Double();
    if(yystack.l_mark[-2].lit.type != yystack.l_mark[0].lit.type)
       Expr_Type_Not_Match();  
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
#line 653 "hw3.y"
	{
    if( (yystack.l_mark[-2].lit.type!=0&& yystack.l_mark[-2].lit.type!=1) || ( yystack.l_mark[0].lit.type!=0 && yystack.l_mark[0].lit.type!=1) )
      Expr_Int_Double();
    if(yystack.l_mark[-2].lit.type != yystack.l_mark[0].lit.type)
       Expr_Type_Not_Match();  
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
#line 669 "hw3.y"
	{
   if( (yystack.l_mark[-2].lit.type!=0&& yystack.l_mark[-2].lit.type!=1) || ( yystack.l_mark[0].lit.type!=0 && yystack.l_mark[0].lit.type!=1) )
      Expr_Int_Double();
    if(yystack.l_mark[-2].lit.type != yystack.l_mark[0].lit.type)
       Expr_Type_Not_Match();  
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
#line 685 "hw3.y"
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
#line 698 "hw3.y"
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
#line 709 "hw3.y"
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
#line 720 "hw3.y"
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
#line 730 "hw3.y"
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
#line 741 "hw3.y"
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
#line 752 "hw3.y"
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
#line 764 "hw3.y"
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
#line 776 "hw3.y"
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
#line 798 "hw3.y"
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
#line 815 "hw3.y"
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
#line 835 "hw3.y"
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
#line 856 "hw3.y"
	{
	 yyval.lit.type = yystack.l_mark[-1].lit.type; 
	yyval.lit.ival = yystack.l_mark[-1].lit.ival; 
	yyval.lit.offset = yystack.l_mark[-1].lit.offset;
	 /*gen_lwi(0,$2.offset);*/
	/*gen_swi(0,$$.offset);*/
	}
break;
case 60:
#line 869 "hw3.y"
	{}
break;
case 61:
#line 870 "hw3.y"
	{}
break;
case 62:
#line 871 "hw3.y"
	{}
break;
case 63:
#line 872 "hw3.y"
	{}
break;
case 64:
#line 873 "hw3.y"
	{}
break;
case 65:
#line 874 "hw3.y"
	{}
break;
case 66:
#line 875 "hw3.y"
	{}
break;
case 67:
#line 876 "hw3.y"
	{}
break;
case 68:
#line 877 "hw3.y"
	{}
break;
case 69:
#line 878 "hw3.y"
	{}
break;
case 70:
#line 879 "hw3.y"
	{}
break;
case 71:
#line 880 "hw3.y"
	{}
break;
case 72:
#line 881 "hw3.y"
	{}
break;
case 73:
#line 882 "hw3.y"
	{}
break;
case 74:
#line 883 "hw3.y"
	{}
break;
case 75:
#line 884 "hw3.y"
	{}
break;
case 76:
#line 885 "hw3.y"
	{}
break;
case 77:
#line 886 "hw3.y"
	{}
break;
case 78:
#line 887 "hw3.y"
	{}
break;
case 79:
#line 888 "hw3.y"
	{}
break;
case 80:
#line 894 "hw3.y"
	{}
break;
case 81:
#line 895 "hw3.y"
	{}
break;
case 82:
#line 897 "hw3.y"
	{}
break;
case 83:
#line 898 "hw3.y"
	{}
break;
case 85:
#line 902 "hw3.y"
	{}
break;
case 86:
#line 903 "hw3.y"
	{}
break;
case 87:
#line 905 "hw3.y"
	{}
break;
case 88:
#line 906 "hw3.y"
	{}
break;
case 91:
#line 913 "hw3.y"
	{}
break;
case 92:
#line 914 "hw3.y"
	{}
break;
case 93:
#line 917 "hw3.y"
	{}
break;
case 94:
#line 918 "hw3.y"
	{}
break;
case 95:
#line 921 "hw3.y"
	{  Init_Expr();   }
break;
case 96:
#line 921 "hw3.y"
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
case 97:
#line 935 "hw3.y"
	{}
break;
case 98:
#line 936 "hw3.y"
	{}
break;
case 99:
#line 937 "hw3.y"
	{}
break;
case 100:
#line 938 "hw3.y"
	{}
break;
case 101:
#line 939 "hw3.y"
	{}
break;
case 103:
#line 949 "hw3.y"
	{Init_Expr();}
break;
case 104:
#line 949 "hw3.y"
	{ End_Expr();}
break;
case 105:
#line 949 "hw3.y"
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
case 106:
#line 964 "hw3.y"
	{
   
}
break;
case 107:
#line 969 "hw3.y"
	{
		int L = pop_lstack();
		gen_label(L);
	}
break;
case 108:
#line 974 "hw3.y"
	{
		int L = labelCount;
		labelCount++;		
		gen_j(L);
		int L2 = pop_lstack();
		gen_label(L2);
		push_lstack(L);
	 }
break;
case 109:
#line 982 "hw3.y"
	{
		 int L = pop_lstack();
		 gen_label(L);
	}
break;
case 110:
#line 988 "hw3.y"
	{Init_Expr(); }
break;
case 111:
#line 988 "hw3.y"
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
case 112:
#line 997 "hw3.y"
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
case 113:
#line 1012 "hw3.y"
	{}
break;
case 114:
#line 1015 "hw3.y"
	{}
break;
case 115:
#line 1018 "hw3.y"
	{}
break;
case 116:
#line 1020 "hw3.y"
	{}
break;
case 117:
#line 1021 "hw3.y"
	{}
break;
case 118:
#line 1024 "hw3.y"
	{}
break;
case 119:
#line 1025 "hw3.y"
	{}
break;
case 120:
#line 1028 "hw3.y"
	{}
break;
case 121:
#line 1029 "hw3.y"
	{}
break;
case 122:
#line 1040 "hw3.y"
	{ 

	   
            int i = look_up_function(yystack.l_mark[-4].sval);
	
            if(i>=0 && ftable[i].defined==1){
              Function_Re_Define();
            }
            else{
		

		int j,k;
		if(i<0 && strcmp(yystack.l_mark[-4].sval,"main")){
		 Function_Not_Declare();
		}
		
		if(i<0){
		
                	install_function(yystack.l_mark[-4].sval);
               	 	k=look_up_function(yystack.l_mark[-4].sval);
                	for(j=0;j<para_index;j++){
                  		ftable[k].argType[j] = para_table[j];
                	}
                	ftable[k].argSize = j -1;
                	ftable[k].returnType = yystack.l_mark[-5].ival;
			ftable[k].defined = 1;
		}
	/*	printf("2222 i%d ftable.declared%d\n",i,ftable[i].declared);*/
		if(i>=0&&ftable[i].declared==1){
			fprintf(stderr,"what the fuck\n");	
			int flag = 0;
			if(para_index!=ftable[i].argSize){
				printf("para_index%d ftable.argSize%d\n",para_index,ftable[i].argSize);
				flag = 1;
			}
			if(yystack.l_mark[-5].ival != ftable[i].returnType ){
				flag = 1;
				printf("$1%d returnType%d\n",yystack.l_mark[-5].ival,ftable[i].returnType);
			}
			
			for(j=0;j<ftable[i].argSize;j++){			    
				if(ftable[i].argType[j]!=para_table[j]){
					printf("argType%d  paraType%d\n",ftable[i].argType[j],para_table[j]);
					flag = 1;
				}
			}
			if(flag==1)
			Function_DD_Not_Match();
			ftable[i].defined = 1;
			
		}
		
            
            	if(yystack.l_mark[-5].ival!=yystack.l_mark[0].ival){
              	Function_Return_Not_Match();
             	}
	    }
   	para_index = 0;
        }
break;
case 123:
#line 1099 "hw3.y"
	{  
            int i = look_up_function(yystack.l_mark[-4].sval);
            if(i>=0 && ftable[i].defined==1){
              Function_Re_Define();
            }
            else{ 

		                int j,k;
                if(i<0 && strcmp(yystack.l_mark[-4].sval,"main")){
                 Function_Not_Declare();
                }
                if(i<0){

                        install_function(yystack.l_mark[-4].sval);
                        k=look_up_function(yystack.l_mark[-4].sval);
                        for(j=0;j<para_index;j++){
                                ftable[k].argType[j] = para_table[j];
                        }
                        ftable[k].argSize = j -1;
                        ftable[k].returnType = 5;
			ftable[k].defined =1;
                }
                if(i>=0&&ftable[i].declared==1){
                        int flag = 0;
                        if(para_index!=ftable[i].argSize){
                                flag = 1;
                        }
                        if(5 != ftable[i].returnType ){
                                flag = 1;
                 	}

                        for(j=0;j<ftable[i].argSize;j++){
                                if(ftable[i].argType[j]!=para_table[j]){
                                        flag = 1;
                                }
                        }
			if(flag==1)
			Function_DD_Not_Match();
			ftable[i].defined = 1;
                }
                

            }
            
            para_index = 0;}
break;
case 124:
#line 1146 "hw3.y"
	{
            int i = look_up_function(yystack.l_mark[-4].sval);
            if(i>=0 && ftable[i].defined==1){
              Function_Re_Define();
            }
            else{
		                int j,k;
                if(i<0 && strcmp(yystack.l_mark[-4].sval,"main")){
                 Function_Not_Declare();
                }
                if(i<0){

                        install_function(yystack.l_mark[-4].sval);
                        k=look_up_function(yystack.l_mark[-4].sval);
                        for(j=0;j<para_index;j++){
                                ftable[k].argType[j] = para_table[j];
                        }
                        ftable[k].argSize = j -1;
                        ftable[k].returnType = yystack.l_mark[-5].ival;
			ftable[k].defined = 1;
                }
                if(i>=0&&ftable[i].declared==1){
                        int flag = 0;
                        if(para_index!=ftable[i].argSize){
                                flag = 1;
                        }
                        if(yystack.l_mark[-5].ival != ftable[i].returnType ){
                                flag = 1;
                        }  

                        for(j=0;j<ftable[i].argSize;j++){
                                if(ftable[i].argType[j]!=para_table[j]){
                                        flag = 1;
                                }
                        }
			if(flag==1)
			 Function_DD_Not_Match();
               		 ftable[i].defined = 1;
		 }
                /*ftable[k].defined = 1;*/

                if(yystack.l_mark[-5].ival!=yystack.l_mark[0].ival){
                Function_Return_Not_Match();
                }

	    }
            para_index = 0;
 }
break;
case 125:
#line 1194 "hw3.y"
	{
    	    int i = look_up_function(yystack.l_mark[-4].sval);
            if(i>=0 && ftable[i].defined==1){
              Function_Re_Define();
            }
            else{

		                 int j,k;
                if(i<0 && strcmp(yystack.l_mark[-4].sval,"main")){
                 Function_Not_Declare();
                }
                if(i<0){

                        install_function(yystack.l_mark[-4].sval);
                        k=look_up_function(yystack.l_mark[-4].sval);
                        for(j=0;j<para_index;j++){
                                ftable[k].argType[j] = para_table[j];
                        }
                        ftable[k].argSize = j -1;
                        ftable[k].returnType = 5;
			ftable[k].defined = 1;
                }
                if(i>=0&&ftable[i].declared==1){
                        int flag = 0;
                        if(para_index!=ftable[i].argSize){
                                flag = 1;
                        }
                        if(5 != ftable[i].returnType ){
                                flag = 1;
                        }

                        for(j=0;j<ftable[i].argSize;j++){
                                if(ftable[i].argType[j]!=para_table[j]){
                                        flag = 1;
                                }
                        }
			if(flag==1){
				Function_DD_Not_Match();
			}
                	ftable[i].defined = 1;
		}
                

            }
            
            para_index = 0;
  	}
break;
case 126:
#line 1243 "hw3.y"
	{cur_scope++;}
break;
case 127:
#line 1243 "hw3.y"
	{yyval.ival = yystack.l_mark[-2].lit.type; pop_up_symbol(cur_scope);cur_scope--; }
break;
case 128:
#line 1245 "hw3.y"
	{cur_scope++; }
break;
case 129:
#line 1245 "hw3.y"
	{pop_up_symbol(cur_scope);cur_scope--;}
break;
case 130:
#line 1249 "hw3.y"
	{cur_scope++; }
break;
case 131:
#line 1249 "hw3.y"
	{pop_up_symbol(cur_scope);cur_scope--;}
break;
case 132:
#line 1251 "hw3.y"
	{}
break;
case 133:
#line 1252 "hw3.y"
	{}
break;
case 134:
#line 1255 "hw3.y"
	{expr_table[expr_comma_count++] = yystack.l_mark[0].lit.type;}
break;
case 135:
#line 1256 "hw3.y"
	{expr_table[expr_comma_count++]=yystack.l_mark[0].lit.type;}
break;
case 136:
#line 1259 "hw3.y"
	{}
break;
case 137:
#line 1260 "hw3.y"
	{}
break;
case 138:
#line 1263 "hw3.y"
	{}
break;
case 139:
#line 1264 "hw3.y"
	{}
break;
case 140:
#line 1268 "hw3.y"
	{ Init_Expr(); }
break;
case 141:
#line 1268 "hw3.y"
	{ 
    
    End_Expr();
    yyval.lit.type = yystack.l_mark[0].lit.type;
    yyval.lit.offset = yystack.l_mark[0].lit.offset;
    yyval.lit.ival = yystack.l_mark[0].lit.ival;
    
    /*gen_lwi(0,$2.offset);*/
  }
break;
case 142:
#line 1279 "hw3.y"
	{}
break;
case 143:
#line 1282 "hw3.y"
	{}
break;
case 144:
#line 1283 "hw3.y"
	{}
break;
case 145:
#line 1286 "hw3.y"
	{}
break;
case 146:
#line 1287 "hw3.y"
	{ }
break;
case 147:
#line 1290 "hw3.y"
	{}
break;
case 148:
#line 1291 "hw3.y"
	{ para_table[para_index++]=yystack.l_mark[-1].ival; }
break;
case 149:
#line 1298 "hw3.y"
	{}
break;
case 150:
#line 1299 "hw3.y"
	{}
break;
case 151:
#line 1302 "hw3.y"
	{}
break;
case 152:
#line 1308 "hw3.y"
	{}
break;
case 153:
#line 1309 "hw3.y"
	{}
break;
case 154:
#line 1312 "hw3.y"
	{}
break;
case 155:
#line 1316 "hw3.y"
	{ yyval.ival = 0;}
break;
case 156:
#line 1317 "hw3.y"
	{ yyval.ival = 1;}
break;
case 157:
#line 1318 "hw3.y"
	{ yyval.ival = 2;}
break;
case 158:
#line 1319 "hw3.y"
	{ yyval.ival = 4;}
break;
case 159:
#line 1323 "hw3.y"
	{ yyval.lit.type = 2; yyval.lit.cval = yystack.l_mark[0].cval;}
break;
case 160:
#line 1324 "hw3.y"
	{ yyval.lit.type = 0; yyval.lit.ival = yystack.l_mark[0].ival;}
break;
case 161:
#line 1325 "hw3.y"
	{ yyval.lit.type = 1; yyval.lit.dval = yystack.l_mark[0].dval;}
break;
case 162:
#line 1326 "hw3.y"
	{ yyval.lit.type = 4; yyval.lit.bval = yystack.l_mark[0].ival;}
break;
case 163:
#line 1327 "hw3.y"
	{  /* no array or pointer, so no string */ }
break;
case 164:
#line 1330 "hw3.y"
	{ Init_Expr();}
break;
case 165:
#line 1330 "hw3.y"
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
case 166:
#line 1347 "hw3.y"
	{Init_Expr();}
break;
case 167:
#line 1347 "hw3.y"
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
#line 2934 "y.tab.c"
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
