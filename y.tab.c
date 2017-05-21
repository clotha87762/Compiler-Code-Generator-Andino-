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
FILE* f_asm ;

#line 31 "hw3.y"
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
#line 59 "y.tab.c"

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
#define lowhigh 297
#define UMINUS 298
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    0,    5,    5,   10,   10,   12,   12,
   12,   12,   14,   14,   14,   14,   14,   14,   14,   14,
   15,   15,    4,    9,    9,   18,   18,   18,   18,   18,
   20,   20,   21,   21,   22,   22,   23,   23,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,   25,
   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,
   25,   25,   25,   25,   25,   25,   25,   25,   25,   26,
   26,   27,   27,   29,   28,   28,   28,   28,   28,   28,
   28,   28,   28,   28,   30,   30,   31,   31,   33,   32,
   35,   35,   37,   37,   36,   36,    8,    8,   19,   19,
   34,   24,   24,   38,   38,   39,   39,   40,   40,   41,
    3,   17,   13,   13,   42,   42,   43,   43,   16,   16,
   44,   11,   11,   45,    6,    6,    6,    6,    1,    1,
    1,    1,    1,   46,    7,   47,    7,
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
    5,    3,    2,    2,    7,    5,    5,    7,    9,    8,
    2,    1,    4,    4,    0,    3,    6,    6,    6,    6,
    4,    0,    1,    3,    1,    0,    1,    3,    1,    0,
    3,    4,    0,    1,    3,    1,    3,    2,    2,    1,
    3,    2,    1,    3,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    0,    8,    0,    6,
};
static const short yydefred[] = {                         0,
  135,  136,  138,  137,    0,    0,    0,    0,    0,    0,
    8,    0,    0,    0,    0,    0,    0,    0,    0,   25,
   28,    0,    7,    0,    0,    0,    0,  120,    0,   17,
    0,  130,   11,    0,    0,    0,    0,    0,   24,    0,
    0,    0,    0,  126,    0,   22,   12,    0,    0,    0,
    0,    0,   19,  129,    0,    0,    0,    0,   29,    0,
    0,    0,  143,  140,  142,  139,  141,   23,    0,    0,
    0,    0,    0,    0,   39,    0,    0,  131,    0,   14,
    0,    0,   30,    0,    0,   10,    0,  108,  125,   21,
    9,  107,    0,    0,    0,  133,    0,   58,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   41,   42,    0,    0,    0,    0,   60,    0,
    0,    0,    0,   15,    0,    0,    0,    0,    0,    0,
   34,    0,    0,    0,    0,  132,   59,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   46,   47,   48,
    0,   78,    0,   62,   63,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  122,    0,
   27,  110,   26,  109,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   86,
    0,    0,   83,   87,   88,   89,   90,   33,   43,    0,
  134,   79,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   66,   67,   68,    0,    0,   35,    0,    0,
    0,    0,    0,    0,    0,   94,   93,  144,  146,   84,
  111,   82,    0,   36,    0,    0,    0,    0,    0,    0,
    0,   92,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   91,    0,    0,    0,   97,    0,
    0,    0,   85,    0,    0,  102,    0,    0,    0,    0,
  147,    0,    0,    0,    0,  101,   95,    0,   98,    0,
    0,    0,    0,  100,    0,  145,  104,  103,  106,   99,
};
static const short yydgoto[] = {                          7,
   75,  238,   30,   46,   77,   41,  190,    9,   19,   10,
   95,   11,   42,   15,   26,   31,   53,   20,   21,  129,
  130,  131,  239,  133,  121,  191,  192,  193,  245,  194,
  195,  196,  197,   88,  265,  275,  266,  134,  122,  123,
   50,   43,   44,   32,   96,  243,  244,
};
static const short yysindex[] = {                       303,
    0,    0,    0,    0, -254,  383,    0, -245,  478,  303,
    0,    6, -219,   79,    3, -161,  383, -152,  478,    0,
    0,  478,    0,  383,   73,  194,  383,    0, -109,    0,
   38,    0,    0,  -94,  177, -219,  176,  230,    0,  478,
  -69,  170,  187,    0,  171,    0,    0,  -36,  184,   19,
  140,  121,    0,    0,   81,  383,  253,  383,    0,  149,
  -31,  383,    0,    0,    0,    0,    0,    0,   73,  -29,
  -20,   19,   19,   19,    0,  181,  -14,    0,   75,    0,
   38,  231,    0,  264,  149,    0,  197,    0,    0,    0,
    0,    0,   19,   19,  211,    0,  434,    0,   42,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,    0,    0,  211,   75,   75,   75,    0,   18,
  228,  188,  300,    0,  -26,   -6,  383,   97,  834,  197,
    0,  181,  322,  324,   64,    0,    0,  434,  261,  651,
  651,  651,  651,  651,  651,  438,  438,    0,    0,    0,
  441,    0,   71,    0,    0,   75,   75,   75,   75,   75,
   75,   75,   75,   75,   75,   75,   75,   75,    0,   75,
    0,    0,    0,    0, -219,   81,  255,   46,  336,  337,
  342,  346,  265,   19,  328,  334,  354,  357,  353,    0,
  307,  834,    0,    0,    0,    0,    0,    0,    0,   19,
    0,    0,  441,  338,  665,  665,  665,  665,  665,  665,
  453,  453,    0,    0,    0,  228,  263,    0,   19,  178,
   19,   19,   19,  159,   85,    0,    0,    0,    0,    0,
    0,    0,  181,    0,  393,  402,  117,  181,  391,  124,
  417,    0,   19,   19,   19,  413,  350,  265,   19,  265,
   19,  131,  153,  160,    0,  205,  210,  428,    0,  167,
  238,  439,    0, -196,   72,    0,  265,   19,  440,  461,
    0,  446,  447,  451,  381,    0,    0,  470,    0,  460,
  834,  834,  834,    0,  265,    0,    0,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,  523,    0,
    0,    0,    0,  280,    0,    0,    0,    0,  524,    0,
    0,  526,    0,  489,    0,    0,  489,    0,    0,    0,
  281,    0,    0,    0,    0,    0,  280,    0,    0,  531,
    0,    0,  491,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  340,  489,    0,  489,    0,   95,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -28,    0,    0,    0,    0,  363,    7,    0,  410,    0,
  377,    0,    0,    0,  148,    0,  709,    0,    0,    0,
    0,    0,  497,    0,  -37,    0,   94,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   -2,    0,    0,    0,    0,   31,
  -43,    0,  430,    0,    0,    0,    0,    0,  432,  724,
    0,  198,    0,  501,    0,    0,    0,  562,  -23,  492,
  499,  512,  519,  536,  556,  302,  448,    0,    0,    0,
  105,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  280,    0,  508,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -88,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  107,  111,  139,  570,  576,  590,  599,  613,
  477,  484,    0,    0,    0,  -15,    0,    0,  497,    0,
    0,  503,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  222,    0,    0,    0,    0,   84,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  503,    0,
    0,    0,    0,    0,    0,    0,  409,    0,    0,    0,
    0,    0,    0,    0,  450,    0,    0,  532,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -35,  -35,  432,    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  774,  853,  521,  513,  751, 1006,    0,  573,  571,    0,
    0,  574,   -1,   -7,  -34,   43,  518,  166,    0,    0,
    0,  464, -188,  382,  922,   55,    0,  412,    0,    0,
    0,    0,    0,  543,    0,    0,  343,    0,    0,    0,
    0,    0,  545,   -4,  515,    0,    0,
};
#define YYTABLESIZE 1136
static const short yytable[] = {                          5,
  119,   57,   12,    5,    5,    5,    5,    5,    6,    5,
   38,   14,    6,    6,    6,    6,    6,   57,    6,   93,
   57,    5,    5,    5,    5,   49,   54,   86,  118,   91,
    6,    6,  171,    6,    6,   57,   81,   25,    6,    6,
    6,    6,    6,   40,    6,   24,   34,   40,   40,   40,
   40,   40,  173,   40,   82,    5,   84,    6,   74,    6,
  258,   33,  272,   73,    6,   40,   40,   61,   40,   57,
   94,   61,   61,   61,   61,   61,   54,   61,  112,  278,
   54,  119,  137,  110,  108,  219,  109,    5,  111,   80,
   61,   87,   61,   87,  273,   35,   87,   81,   52,   40,
  112,  107,   85,  106,   37,  110,  108,  168,  109,  118,
  111,  202,  166,  164,  118,  165,   87,  167,   27,  117,
  177,  112,    6,  107,   38,  106,  110,  108,   29,  109,
  163,  111,  162,   45,   55,  128,   94,   55,  128,   28,
  217,   28,   38,  242,  107,   75,  106,   76,   75,   51,
   76,   77,   55,  112,   77,   61,  201,  248,  110,  108,
  112,  109,   55,  111,  250,  110,  108,  112,  109,   29,
  111,   29,  110,  108,  261,  109,  107,  111,  106,   71,
   81,   81,   71,  107,   39,  106,   55,   60,  127,  112,
  107,  127,  106,  262,  110,  108,  112,  109,   71,  111,
   71,  110,  108,  112,  109,   39,  111,  269,  110,  108,
   61,  109,  107,  111,  106,   58,   56,  112,  263,  107,
   69,  106,  110,  108,   70,  109,  107,  111,  106,   75,
   62,   76,   78,   80,   80,   77,   28,   48,  115,   29,
  107,  115,  106,   79,    5,    5,    5,    5,    5,    5,
    5,    5,   47,    6,    6,    6,    6,    6,    6,    6,
    6,   57,  114,   71,  168,  114,   29,  113,  114,  166,
  164,  125,  165,   34,  167,   71,   63,   64,   65,    6,
    6,    6,    6,    6,    6,    6,    6,  163,   59,  162,
   40,   40,   40,   40,   40,   40,   48,  112,   34,  154,
  155,   94,  110,  108,  126,  109,   48,  111,   72,   66,
   67,   83,  169,  218,   61,   61,   61,   61,   61,   61,
  107,  234,  106,   18,   20,  100,  101,  102,  103,  104,
  105,  115,   63,   64,   65,  287,  288,  289,   18,   20,
  264,  274,   44,  170,   44,   44,   44,  100,  101,  102,
  103,  104,  105,  176,  156,  157,  158,  159,  160,  161,
   44,   44,  199,   44,  116,   66,   67,  200,  100,  101,
  102,  103,  104,  105,  168,  220,  221,   55,   55,  166,
  164,  222,  165,   13,  167,  223,  226,   87,   75,   75,
   76,   76,  227,  228,   44,   77,  229,  163,   13,  162,
  100,  101,  102,  103,  104,  105,  121,  100,  101,  102,
  103,  104,  105,  230,  100,  101,  102,  103,  104,  105,
   16,  121,   71,   71,   71,   71,   71,   71,   63,   64,
   65,  231,  241,  246,  236,   16,  100,  101,  102,  103,
  104,  105,  247,  100,  101,  102,  103,  104,  105,  249,
  100,  101,  102,  103,  104,  105,  251,    1,    2,    3,
    4,   66,   67,  127,  100,  101,  102,  103,  104,  105,
  112,  255,  256,  264,  112,  110,  108,  168,  109,  110,
  111,  267,  166,  164,  111,  165,  268,  167,   45,  168,
   45,   45,   45,  107,  166,  106,  270,  271,  279,  167,
  163,  280,  162,  281,  282,  284,   45,   45,  283,   45,
  285,  156,  157,  158,  159,  160,  161,   64,  286,   64,
   64,   64,    3,    1,   65,    4,   65,   65,   65,  123,
    2,  124,   51,   96,  116,   51,   64,  112,   64,   52,
   45,  113,   52,   65,  100,   65,  102,  103,  104,  105,
   51,   51,   53,   51,  117,   53,   80,   52,   52,   54,
   52,   37,   54,    1,    2,    3,    4,    5,    6,    6,
   53,   53,   37,   53,  105,   80,   49,   54,   54,   49,
   54,   90,   22,   23,   51,   44,   44,   44,   44,   44,
   44,   52,   40,  198,   49,   49,   50,   49,  124,   50,
  235,   64,   56,  232,   53,   56,   89,  276,   65,  136,
   72,   54,   92,   72,   50,   50,   73,   50,    0,   73,
   56,  156,    0,  158,  159,  160,  161,    0,   49,   72,
   74,   72,    0,   74,    0,   73,    0,   73,    0,   69,
    0,    0,   69,    1,    2,    3,    4,    0,   50,   74,
    0,   74,    0,   70,   56,    0,   70,    0,   69,    0,
   69,    0,    0,    0,    0,   96,    0,  172,  174,    0,
    0,    0,   70,    0,   70,    0,   96,   96,   96,   96,
    0,   96,   96,   96,   96,   96,   96,  112,    0,    0,
    0,    0,  110,  108,   72,  109,    0,  111,    0,    0,
   73,  168,    0,   96,   96,    0,  166,  164,    0,  165,
    0,  167,    0,    0,   74,    0,    0,    0,    0,  102,
  103,  104,  105,   69,    0,  224,  158,  159,  160,  161,
    0,   45,   45,   45,   45,   45,   45,   70,    1,    2,
    3,    4,   16,    0,   17,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   64,   64,   64,   64,   64,   64,    0,   65,   65,   65,
   65,   65,   65,    0,    0,   51,   51,   51,   51,   51,
   51,    0,   52,   52,   52,   52,   52,   52,    0,    0,
  257,    0,  259,    0,    0,   53,   53,   53,   53,   53,
   53,    0,   54,   54,   54,   54,   54,   54,    0,  277,
    0,    0,    0,    0,    0,    0,    0,    0,   68,   49,
   49,   49,   49,   49,   49,    0,    0,  290,    0,  120,
    0,    0,    0,   31,    0,    0,    0,    0,    0,   50,
   50,   50,   50,   50,   50,   56,   56,    0,   32,    0,
    0,    0,  119,   72,   72,   72,   72,   72,   72,   73,
   73,   73,   73,   73,   73,    0,  120,  120,  120,    0,
    0,    0,    0,   74,   74,   74,   74,   74,   74,  189,
    0,    0,   69,   69,   69,   69,   69,   69,    0,  119,
  119,  119,    0,    0,    0,    0,   70,   70,   70,   70,
   70,   70,   76,    0,    0,    0,  120,  120,  120,  120,
  120,  120,  120,  120,  120,  120,  120,  120,  120,    0,
  120,    0,    0,    0,   97,   98,   99,    0,    0,  119,
  119,  119,  119,  119,  119,  119,  119,  119,  119,  119,
  119,  119,  189,  119,    0,  132,  135,    0,    0,    0,
    0,    0,  138,  139,  140,  141,  142,  143,  144,  145,
  146,  147,  148,  149,  150,   31,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   31,    0,    0,   31,
   32,   31,   31,   31,   31,   31,   31,    0,    0,    0,
    0,   32,    0,    0,   32,    0,   32,   32,   32,   32,
   32,   32,    0,   31,   31,    8,    0,    0,    0,    0,
    0,   13,    0,    0,   18,    8,    0,    0,   32,   32,
    0,    0,   36,    0,   18,    0,    0,   18,    0,    0,
    0,  189,  189,  189,    0,    0,  225,  151,  152,  153,
    0,    0,    0,    0,    0,   18,    0,    0,    0,    0,
    0,    0,  233,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  132,    0,  237,    0,  240,    0,  203,  204,  205,
  206,  207,  208,  209,  210,  211,  212,  213,  214,  215,
  178,  216,  128,    0,    0,  252,  253,  254,    0,    0,
    0,  179,    0,  260,  180,    0,  181,  182,  183,  184,
  185,  186,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  187,  188,
    0,    0,  175,    0,    0,  128,
};
static const short yycheck[] = {                         37,
   44,   36,  257,   41,   42,   43,   44,   45,   37,   47,
   18,  257,   41,   42,   43,   44,   45,   41,   47,   40,
   44,   59,   60,   61,   62,   27,   31,   59,   44,   59,
   59,   60,   59,   62,   37,   59,  125,  257,   41,   42,
   43,   44,   45,   37,   47,   40,   44,   41,   42,   43,
   44,   45,   59,   47,   56,   93,   58,   60,   40,   62,
  249,   59,  259,   45,   93,   59,   60,   37,   62,   93,
   91,   41,   42,   43,   44,   45,   81,   47,   37,  268,
   85,  125,   41,   42,   43,   40,   45,  125,   47,  125,
   60,  123,   62,  123,  291,  257,  123,   55,   61,   93,
   37,   60,   60,   62,  257,   42,   43,   37,   45,  125,
   47,   41,   42,   43,   40,   45,  123,   47,   40,   45,
  128,   37,  125,   60,   41,   62,   42,   43,   91,   45,
   60,   47,   62,   61,   41,   41,   91,   44,   44,   61,
  175,   61,   59,   59,   60,   41,   62,   41,   44,  259,
   44,   41,   59,   37,   44,  125,   93,   41,   42,   43,
   37,   45,  257,   47,   41,   42,   43,   37,   45,   91,
   47,   91,   42,   43,   44,   45,   60,   47,   62,   41,
  269,  270,   44,   60,   19,   62,   93,  257,   41,   37,
   60,   44,   62,   41,   42,   43,   37,   45,   60,   47,
   62,   42,   43,   37,   45,   40,   47,   41,   42,   43,
   41,   45,   60,   47,   62,   40,   40,   37,   59,   60,
  257,   62,   42,   43,   41,   45,   60,   47,   62,  125,
   44,  125,   93,  269,  270,  125,   61,   44,   41,   91,
   60,   44,   62,  123,  282,  283,  284,  285,  286,  287,
  288,  289,   59,  282,  283,  284,  285,  286,  287,  288,
  289,  285,   41,  125,   37,   44,   91,  282,  283,   42,
   43,   41,   45,   44,   47,  257,  258,  259,  260,  282,
  283,  284,  285,  286,  287,  288,  289,   60,   59,   62,
  284,  285,  286,  287,  288,  289,   44,   37,   44,  282,
  283,   91,   42,   43,   41,   45,   44,   47,  290,  291,
  292,   59,  125,   59,  284,  285,  286,  287,  288,  289,
   60,   59,   62,   44,   44,  284,  285,  286,  287,  288,
  289,  257,  258,  259,  260,  281,  282,  283,   59,   59,
  269,  270,   41,   44,   43,   44,   45,  284,  285,  286,
  287,  288,  289,  257,  284,  285,  286,  287,  288,  289,
   59,   60,   41,   62,  290,  291,  292,   44,  284,  285,
  286,  287,  288,  289,   37,   40,   40,  284,  285,   42,
   43,   40,   45,   44,   47,   40,   59,  123,  284,  285,
  284,  285,   59,   40,   93,  285,   40,   60,   59,   62,
  284,  285,  286,  287,  288,  289,   44,  284,  285,  286,
  287,  288,  289,   61,  284,  285,  286,  287,  288,  289,
   44,   59,  284,  285,  286,  287,  288,  289,  258,  259,
  260,  125,  274,   41,  257,   59,  284,  285,  286,  287,
  288,  289,   41,  284,  285,  286,  287,  288,  289,   59,
  284,  285,  286,  287,  288,  289,   40,  261,  262,  263,
  264,  291,  292,  267,  284,  285,  286,  287,  288,  289,
   37,   59,  123,  269,   37,   42,   43,   37,   45,   42,
   47,  272,   42,   43,   47,   45,   59,   47,   41,   37,
   43,   44,   45,   60,   42,   62,  259,   59,   59,   47,
   60,   41,   62,   58,   58,  125,   59,   60,   58,   62,
   41,  284,  285,  286,  287,  288,  289,   41,   59,   43,
   44,   45,    0,    0,   41,    0,   43,   44,   45,   41,
    0,   41,   41,  125,  125,   44,   60,   41,   62,   41,
   93,   41,   44,   60,  284,   62,  286,  287,  288,  289,
   59,   60,   41,   62,  125,   44,  125,   59,   60,   41,
   62,   59,   44,  261,  262,  263,  264,  265,   61,  267,
   59,   60,   41,   62,  125,   55,   41,   59,   60,   44,
   62,   69,   10,   10,   93,  284,  285,  286,  287,  288,
  289,   93,   22,  130,   59,   60,   41,   62,   81,   44,
  219,  125,   41,  192,   93,   44,   62,  265,  125,   95,
   41,   93,   70,   44,   59,   60,   41,   62,   -1,   44,
   59,  284,   -1,  286,  287,  288,  289,   -1,   93,   60,
   41,   62,   -1,   44,   -1,   60,   -1,   62,   -1,   41,
   -1,   -1,   44,  261,  262,  263,  264,   -1,   93,   60,
   -1,   62,   -1,   41,   93,   -1,   44,   -1,   60,   -1,
   62,   -1,   -1,   -1,   -1,  257,   -1,  125,  126,   -1,
   -1,   -1,   60,   -1,   62,   -1,  268,  269,  270,  271,
   -1,  273,  274,  275,  276,  277,  278,   37,   -1,   -1,
   -1,   -1,   42,   43,  125,   45,   -1,   47,   -1,   -1,
  125,   37,   -1,  295,  296,   -1,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,  125,   -1,   -1,   -1,   -1,  286,
  287,  288,  289,  125,   -1,  183,  286,  287,  288,  289,
   -1,  284,  285,  286,  287,  288,  289,  125,  261,  262,
  263,  264,  265,   -1,  267,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  284,  285,  286,  287,  288,  289,   -1,  284,  285,  286,
  287,  288,  289,   -1,   -1,  284,  285,  286,  287,  288,
  289,   -1,  284,  285,  286,  287,  288,  289,   -1,   -1,
  248,   -1,  250,   -1,   -1,  284,  285,  286,  287,  288,
  289,   -1,  284,  285,  286,  287,  288,  289,   -1,  267,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   45,  284,
  285,  286,  287,  288,  289,   -1,   -1,  285,   -1,   79,
   -1,   -1,   -1,  125,   -1,   -1,   -1,   -1,   -1,  284,
  285,  286,  287,  288,  289,  284,  285,   -1,  125,   -1,
   -1,   -1,   79,  284,  285,  286,  287,  288,  289,  284,
  285,  286,  287,  288,  289,   -1,  116,  117,  118,   -1,
   -1,   -1,   -1,  284,  285,  286,  287,  288,  289,  129,
   -1,   -1,  284,  285,  286,  287,  288,  289,   -1,  116,
  117,  118,   -1,   -1,   -1,   -1,  284,  285,  286,  287,
  288,  289,   50,   -1,   -1,   -1,  156,  157,  158,  159,
  160,  161,  162,  163,  164,  165,  166,  167,  168,   -1,
  170,   -1,   -1,   -1,   72,   73,   74,   -1,   -1,  156,
  157,  158,  159,  160,  161,  162,  163,  164,  165,  166,
  167,  168,  192,  170,   -1,   93,   94,   -1,   -1,   -1,
   -1,   -1,  100,  101,  102,  103,  104,  105,  106,  107,
  108,  109,  110,  111,  112,  257,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  268,   -1,   -1,  271,
  257,  273,  274,  275,  276,  277,  278,   -1,   -1,   -1,
   -1,  268,   -1,   -1,  271,   -1,  273,  274,  275,  276,
  277,  278,   -1,  295,  296,    0,   -1,   -1,   -1,   -1,
   -1,    6,   -1,   -1,    9,   10,   -1,   -1,  295,  296,
   -1,   -1,   17,   -1,   19,   -1,   -1,   22,   -1,   -1,
   -1,  281,  282,  283,   -1,   -1,  184,  116,  117,  118,
   -1,   -1,   -1,   -1,   -1,   40,   -1,   -1,   -1,   -1,
   -1,   -1,  200,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  219,   -1,  221,   -1,  223,   -1,  156,  157,  158,
  159,  160,  161,  162,  163,  164,  165,  166,  167,  168,
  257,  170,   87,   -1,   -1,  243,  244,  245,   -1,   -1,
   -1,  268,   -1,  251,  271,   -1,  273,  274,  275,  276,
  277,  278,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  295,  296,
   -1,   -1,  127,   -1,   -1,  130,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 298
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
"CHAR_LIT","DOUBLE_LIT","HIGH","LOW","DIGITAL_WRITE","DELAY","lowhigh","UMINUS",
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
"if_stmt : IF '(' expr ')' compound ELSE compound",
"if_stmt : IF '(' expr ')' compound",
"while_stmt : WHILE '(' expr ')' compound",
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
"$$2 :",
"init : '=' $$2 expr",
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
"$$3 :",
"blink : DIGITAL_WRITE '(' $$3 expr ',' INT_LIT ')' ';'",
"$$4 :",
"blink : DELAY '(' $$4 expr ')' ';'",

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
#line 733 "hw3.y"


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

#line 904 "y.tab.c"

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
#line 75 "hw3.y"
	{
     printf("No syntax error!\n");
     Write_Assembly();
    }
break;
case 2:
#line 79 "hw3.y"
	{printf("No syntax error!\n");Write_Assembly();}
break;
case 3:
#line 80 "hw3.y"
	{printf("No syntax error!\n");Write_Assembly();}
break;
case 4:
#line 81 "hw3.y"
	{printf("No syntax error!\n");Write_Assembly();}
break;
case 5:
#line 85 "hw3.y"
	{
      Check_Var_Exist(yystack.l_mark[-1].sval);
      /* supposely, there should be no array.........*/
   }
break;
case 6:
#line 89 "hw3.y"
	{
      Check_Var_Exist(yystack.l_mark[0].sval);
       yyval.sval = mstrcpy(yystack.l_mark[0].sval);
   }
break;
case 7:
#line 99 "hw3.y"
	{}
break;
case 8:
#line 100 "hw3.y"
	{}
break;
case 9:
#line 103 "hw3.y"
	{}
break;
case 10:
#line 104 "hw3.y"
	{}
break;
case 11:
#line 105 "hw3.y"
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
#line 117 "hw3.y"
	{}
break;
case 13:
#line 120 "hw3.y"
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
#line 128 "hw3.y"
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
#line 151 "hw3.y"
	{}
break;
case 16:
#line 152 "hw3.y"
	{}
break;
case 17:
#line 153 "hw3.y"
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
#line 178 "hw3.y"
	{ 
   
	        Check_Var_Not_Exist(yystack.l_mark[0].sval);
          /* put value into stack*/
          install_symbol(yystack.l_mark[0].sval);
          init_index++;
          stack_cur_offset++;

          }
break;
case 19:
#line 187 "hw3.y"
	{}
break;
case 20:
#line 188 "hw3.y"
	{}
break;
case 21:
#line 192 "hw3.y"
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
#line 206 "hw3.y"
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
#line 223 "hw3.y"
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
#line 247 "hw3.y"
	{}
break;
case 25:
#line 248 "hw3.y"
	{}
break;
case 26:
#line 252 "hw3.y"
	{}
break;
case 27:
#line 253 "hw3.y"
	{}
break;
case 28:
#line 254 "hw3.y"
	{}
break;
case 29:
#line 255 "hw3.y"
	{}
break;
case 30:
#line 256 "hw3.y"
	{}
break;
case 31:
#line 259 "hw3.y"
	{}
break;
case 32:
#line 260 "hw3.y"
	{}
break;
case 33:
#line 264 "hw3.y"
	{}
break;
case 34:
#line 265 "hw3.y"
	{}
break;
case 35:
#line 268 "hw3.y"
	{}
break;
case 36:
#line 269 "hw3.y"
	{}
break;
case 37:
#line 272 "hw3.y"
	{}
break;
case 38:
#line 273 "hw3.y"
	{}
break;
case 39:
#line 276 "hw3.y"
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
#line 292 "hw3.y"
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
#line 307 "hw3.y"
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
#line 334 "hw3.y"
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
#line 360 "hw3.y"
	{ }
break;
case 44:
#line 362 "hw3.y"
	{ 

    yyval.lit.type = yystack.l_mark[-2].lit.type; 
    yyval.lit.ival = yystack.l_mark[-2].lit.ival + yystack.l_mark[0].lit.ival; 
    /*$$.offset = expr_stack_offset++; */
    /* generate code*/
    int r1 , r2;
    r1 =load_expr(yystack.l_mark[-2].lit.offset,0);
    if(r1==1){
     r1 = 0;
    }
    else{
     r1 = -yystack.l_mark[-2].lit.offset;
    }
   
    r2= load_expr(yystack.l_mark[0].lit.offset,1);
    if(r2==1){
     r2 = 1;
    } 
    else{
     r2 = -yystack.l_mark[0].lit.offset;
    }
    gen_add(0,r1,r2);
    int x = save_expr(yystack.l_mark[-2].lit.offset,yystack.l_mark[0].lit.offset);
    yyval.lit.offset = x;
    }
break;
case 45:
#line 388 "hw3.y"
	{
    yyval.lit.type = yystack.l_mark[-2].lit.type; 
    yyval.lit.ival = yystack.l_mark[-2].lit.ival - yystack.l_mark[0].lit.ival;
    /*$$.offset = expr_stack_offset++;*/
    
    int r1 , r2;
    r1 =load_expr(yystack.l_mark[-2].lit.offset,0);
    if(r1==1){
     r1 = 0;
    }
    else{
     r1 = -yystack.l_mark[-2].lit.offset;
    }

    r2= load_expr(yystack.l_mark[0].lit.offset,1);
    if(r2==1){
     r2 = 1;
    }
    else{
     r2 = -yystack.l_mark[0].lit.offset;
    }

    gen_sub(0,r1,r2);
    int x = save_expr(yystack.l_mark[-2].lit.offset,yystack.l_mark[0].lit.offset);
    yyval.lit.offset =x;
    }
break;
case 46:
#line 414 "hw3.y"
	{
   yyval.lit.type = yystack.l_mark[-2].lit.type; 
   yyval.lit.ival = yystack.l_mark[-2].lit.ival * yystack.l_mark[0].lit.ival; 
  /* $$.offset = expr_stack_offset++;*/

      int r1 , r2;
    r1 =load_expr(yystack.l_mark[-2].lit.offset,0);
    if(r1==1){
     r1 = 0;
    }
    else{
     r1 = -yystack.l_mark[-2].lit.offset;
    }

    r2= load_expr(yystack.l_mark[0].lit.offset,1);
    if(r2==1){
     r2 = 1;
    }
    else{
     r2 = -yystack.l_mark[0].lit.offset;
    }

    gen_mul(0,r1,r2);
    int x=save_expr(yystack.l_mark[-2].lit.offset,yystack.l_mark[0].lit.offset);
    yyval.lit.offset = x; 
  }
break;
case 47:
#line 440 "hw3.y"
	{ 
  yyval.lit.type = yystack.l_mark[-2].lit.type;
 /* printf("!!!!%d\n",$3.ival);*/
  yyval.lit.ival = yystack.l_mark[-2].lit.ival / yystack.l_mark[0].lit.ival; 
  /*$$.offset = expr_stack_offset++;*/

     int r1 , r2;
    r1 =load_expr(yystack.l_mark[-2].lit.offset,0);
    if(r1==1){
     r1 = 0;
    }
    else{
     r1 = -yystack.l_mark[-2].lit.offset;
    }

    r2= load_expr(yystack.l_mark[0].lit.offset,1);
    if(r2==1){
     r2 = 1;
    }
    else{
     r2 = -yystack.l_mark[0].lit.offset;
    }

    gen_divsr(0,1,r1,r2);
    int x= save_expr(yystack.l_mark[-2].lit.offset,yystack.l_mark[0].lit.offset);
    yyval.lit.offset = x;
  }
break;
case 48:
#line 467 "hw3.y"
	{ 
    yyval.lit.type = yystack.l_mark[-2].lit.type; 
    yyval.lit.ival = yystack.l_mark[-2].lit.ival % yystack.l_mark[0].lit.ival;  
     /*$$.offset = expr_stack_offset++;*/

      int r1 , r2;
    r1 =load_expr(yystack.l_mark[-2].lit.offset,0);
    if(r1==1){
     r1 = 0;
    }
    else{
     r1 = -yystack.l_mark[-2].lit.offset;
    }

    r2= load_expr(yystack.l_mark[0].lit.offset,1);
    if(r2==1){
     r2 = 1;
    }
    else{
     r2 = -yystack.l_mark[0].lit.offset;
    }

    gen_divsr(1,0,r1,r2);
    int x=save_expr(yystack.l_mark[-2].lit.offset,yystack.l_mark[0].lit.offset);
    yyval.lit.offset = x;
  }
break;
case 49:
#line 493 "hw3.y"
	{ yyval.lit.type = 4; if(yystack.l_mark[-2].lit.ival > yystack.l_mark[0].lit.ival){yyval.lit.ival = 1;}else{yyval.lit.ival = 0;} yyval.lit.offset = expr_stack_offset++;}
break;
case 50:
#line 494 "hw3.y"
	{ yyval.lit.type = 4; if(yystack.l_mark[-2].lit.ival < yystack.l_mark[0].lit.ival){yyval.lit.ival = 1;}else{yyval.lit.ival = 0;} yyval.lit.offset = expr_stack_offset++;}
break;
case 51:
#line 495 "hw3.y"
	{ yyval.lit.type = 4; if(yystack.l_mark[-2].lit.ival >= yystack.l_mark[0].lit.ival){yyval.lit.ival = 1;}else{yyval.lit.ival = 0;} yyval.lit.offset = expr_stack_offset++;}
break;
case 52:
#line 496 "hw3.y"
	{ yyval.lit.type = 4;  if(yystack.l_mark[-2].lit.ival <= yystack.l_mark[0].lit.ival){yyval.lit.ival = 1;}else{yyval.lit.ival = 0;} yyval.lit.offset = expr_stack_offset++;}
break;
case 53:
#line 497 "hw3.y"
	{ yyval.lit.type = 4;  if(yystack.l_mark[-2].lit.ival == yystack.l_mark[0].lit.ival){yyval.lit.ival = 1;}else{yyval.lit.ival = 0;} yyval.lit.offset = expr_stack_offset++;}
break;
case 54:
#line 498 "hw3.y"
	{ yyval.lit.type = 4;   if(yystack.l_mark[-2].lit.ival != yystack.l_mark[0].lit.ival){yyval.lit.ival = 1;}else{yyval.lit.ival = 0;} yyval.lit.offset = expr_stack_offset++;}
break;
case 55:
#line 499 "hw3.y"
	{ yyval.lit.type = 4;   if(yystack.l_mark[0].lit.ival !=0){yyval.lit.ival = 0;}else{yyval.lit.ival = 1;} yyval.lit.offset = expr_stack_offset++;}
break;
case 56:
#line 500 "hw3.y"
	{ yyval.lit.type = 4;   if(yystack.l_mark[-2].lit.ival && yystack.l_mark[0].lit.ival){yyval.lit.ival = 1;}else{yyval.lit.ival = 0;} yyval.lit.offset = expr_stack_offset++;}
break;
case 57:
#line 501 "hw3.y"
	{yyval.lit.type = 4;   if(yystack.l_mark[-2].lit.ival || yystack.l_mark[0].lit.ival){yyval.lit.ival = 1;}else{yyval.lit.ival = 0;} yyval.lit.offset = expr_stack_offset++;}
break;
case 58:
#line 502 "hw3.y"
	{yyval.lit.type = yystack.l_mark[0].lit.type; yyval.lit.ival = yystack.l_mark[0].lit.ival * (-1); yyval.lit.offset = expr_stack_offset++;}
break;
case 59:
#line 503 "hw3.y"
	{
	 yyval.lit.type = yystack.l_mark[-1].lit.type; 
	yyval.lit.ival = yystack.l_mark[-1].lit.ival; 
	yyval.lit.offset = yystack.l_mark[-1].lit.offset;
	 /*gen_lwi(0,$2.offset);*/
	/*gen_swi(0,$$.offset);*/
	}
break;
case 60:
#line 516 "hw3.y"
	{}
break;
case 61:
#line 517 "hw3.y"
	{}
break;
case 62:
#line 518 "hw3.y"
	{}
break;
case 63:
#line 519 "hw3.y"
	{}
break;
case 64:
#line 520 "hw3.y"
	{}
break;
case 65:
#line 521 "hw3.y"
	{}
break;
case 66:
#line 522 "hw3.y"
	{}
break;
case 67:
#line 523 "hw3.y"
	{}
break;
case 68:
#line 524 "hw3.y"
	{}
break;
case 69:
#line 525 "hw3.y"
	{}
break;
case 70:
#line 526 "hw3.y"
	{}
break;
case 71:
#line 527 "hw3.y"
	{}
break;
case 72:
#line 528 "hw3.y"
	{}
break;
case 73:
#line 529 "hw3.y"
	{}
break;
case 74:
#line 530 "hw3.y"
	{}
break;
case 75:
#line 531 "hw3.y"
	{}
break;
case 76:
#line 532 "hw3.y"
	{}
break;
case 77:
#line 533 "hw3.y"
	{}
break;
case 78:
#line 534 "hw3.y"
	{}
break;
case 79:
#line 535 "hw3.y"
	{}
break;
case 80:
#line 542 "hw3.y"
	{}
break;
case 81:
#line 543 "hw3.y"
	{}
break;
case 82:
#line 546 "hw3.y"
	{}
break;
case 83:
#line 547 "hw3.y"
	{}
break;
case 84:
#line 550 "hw3.y"
	{  Init_Expr();   }
break;
case 85:
#line 550 "hw3.y"
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
#line 564 "hw3.y"
	{}
break;
case 87:
#line 565 "hw3.y"
	{}
break;
case 88:
#line 566 "hw3.y"
	{}
break;
case 89:
#line 567 "hw3.y"
	{}
break;
case 90:
#line 568 "hw3.y"
	{}
break;
case 92:
#line 572 "hw3.y"
	{}
break;
case 93:
#line 573 "hw3.y"
	{}
break;
case 94:
#line 574 "hw3.y"
	{}
break;
case 95:
#line 578 "hw3.y"
	{}
break;
case 96:
#line 579 "hw3.y"
	{}
break;
case 97:
#line 583 "hw3.y"
	{}
break;
case 98:
#line 584 "hw3.y"
	{}
break;
case 99:
#line 587 "hw3.y"
	{}
break;
case 100:
#line 589 "hw3.y"
	{}
break;
case 101:
#line 591 "hw3.y"
	{}
break;
case 102:
#line 592 "hw3.y"
	{}
break;
case 103:
#line 595 "hw3.y"
	{}
break;
case 104:
#line 596 "hw3.y"
	{}
break;
case 105:
#line 599 "hw3.y"
	{}
break;
case 106:
#line 600 "hw3.y"
	{}
break;
case 107:
#line 611 "hw3.y"
	{}
break;
case 108:
#line 612 "hw3.y"
	{}
break;
case 109:
#line 614 "hw3.y"
	{}
break;
case 110:
#line 615 "hw3.y"
	{}
break;
case 111:
#line 617 "hw3.y"
	{}
break;
case 112:
#line 620 "hw3.y"
	{}
break;
case 113:
#line 621 "hw3.y"
	{}
break;
case 114:
#line 624 "hw3.y"
	{}
break;
case 115:
#line 625 "hw3.y"
	{}
break;
case 116:
#line 628 "hw3.y"
	{}
break;
case 117:
#line 629 "hw3.y"
	{}
break;
case 118:
#line 632 "hw3.y"
	{}
break;
case 119:
#line 633 "hw3.y"
	{}
break;
case 120:
#line 637 "hw3.y"
	{ Init_Expr(); }
break;
case 121:
#line 637 "hw3.y"
	{ 
    
    End_Expr();
    yyval.lit.type = yystack.l_mark[0].lit.type;
    yyval.lit.offset = yystack.l_mark[0].lit.offset;
    yyval.lit.ival = yystack.l_mark[0].lit.ival;
    
    /*gen_lwi(0,$2.offset);*/
  }
break;
case 122:
#line 648 "hw3.y"
	{}
break;
case 123:
#line 651 "hw3.y"
	{}
break;
case 124:
#line 652 "hw3.y"
	{}
break;
case 125:
#line 655 "hw3.y"
	{}
break;
case 126:
#line 656 "hw3.y"
	{}
break;
case 127:
#line 659 "hw3.y"
	{}
break;
case 129:
#line 667 "hw3.y"
	{}
break;
case 130:
#line 668 "hw3.y"
	{}
break;
case 131:
#line 671 "hw3.y"
	{}
break;
case 132:
#line 677 "hw3.y"
	{}
break;
case 133:
#line 678 "hw3.y"
	{}
break;
case 134:
#line 681 "hw3.y"
	{}
break;
case 135:
#line 685 "hw3.y"
	{ yyval.ival = 0;}
break;
case 136:
#line 686 "hw3.y"
	{ yyval.ival = 1;}
break;
case 137:
#line 687 "hw3.y"
	{ yyval.ival = 2;}
break;
case 138:
#line 688 "hw3.y"
	{ yyval.ival = 4;}
break;
case 139:
#line 692 "hw3.y"
	{ yyval.lit.type = 2; yyval.lit.cval = yystack.l_mark[0].cval;}
break;
case 140:
#line 693 "hw3.y"
	{ yyval.lit.type = 0; yyval.lit.ival = yystack.l_mark[0].ival;}
break;
case 141:
#line 694 "hw3.y"
	{ yyval.lit.type = 1; yyval.lit.dval = yystack.l_mark[0].dval;}
break;
case 142:
#line 695 "hw3.y"
	{ yyval.lit.type = 4; yyval.lit.bval = yystack.l_mark[0].ival;}
break;
case 143:
#line 696 "hw3.y"
	{  /* no array or pointer, so no string */ }
break;
case 144:
#line 699 "hw3.y"
	{ Init_Expr();}
break;
case 145:
#line 699 "hw3.y"
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
case 146:
#line 716 "hw3.y"
	{Init_Expr();}
break;
case 147:
#line 716 "hw3.y"
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
#line 2068 "y.tab.c"
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
