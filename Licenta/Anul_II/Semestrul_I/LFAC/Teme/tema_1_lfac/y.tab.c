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

#line 2 "tema1.y"
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
#line 24 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

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

#define TIP 257
#define ID 258
#define BGINP 259
#define ENDP 260
#define WHILE 261
#define FOR 262
#define IF 263
#define ELSE 264
#define CONST 265
#define OPRARM 266
#define ASSIGN 267
#define CARACTER 268
#define SIR_CARACTERE 269
#define INTG 270
#define INC 271
#define DEC 272
#define OPRCOMP 273
#define OPRLOG 274
#define RATIONAL 275
#define DIM_VEC 276
#define LIBRARIE 277
#define CLASA 278
#define BGINB 279
#define ENDB 280
#define PRIVATE 281
#define PUBLIC 282
#define PROTECTED 283
#define RETURNAT 284
#define NEG 285
#define NUME 286
#define DO 287
#define BREAK 288
#define MINUS 289
#define IFX 290
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    2,    2,    6,    6,    8,
    8,    9,    9,    9,   11,   11,   12,   12,   12,   12,
   12,   12,   12,   12,   12,   13,   13,   14,    4,    4,
   15,   15,   15,   15,   15,   15,   17,   17,   18,   18,
   18,   18,   18,   20,   20,    3,    3,   21,   21,    7,
    7,   22,   23,   23,   23,   23,   10,   10,    5,    5,
   25,   25,   25,   25,   28,   28,   28,   28,   28,   28,
   30,   30,   30,   30,   27,   27,   24,   24,   24,   31,
   31,   29,   29,   32,   32,   32,   32,   32,   32,   32,
   32,   32,   32,   32,   26,   26,   26,   26,   26,   26,
   26,   26,   26,   26,   26,   26,   26,   38,   38,   16,
   16,   16,   39,   39,   33,   33,   40,   40,   19,   19,
   34,   34,   41,   41,   41,   35,   35,   35,   35,   35,
   35,   35,   35,   36,   36,   37,   37,
};
static const short yylen[] = {                            2,
    4,    2,    1,    3,    2,    2,    1,    3,    4,    4,
    5,    1,    2,    2,    2,    1,    3,    2,    2,    3,
    2,    2,    3,    2,    2,    2,    1,    5,    2,    1,
    1,    2,    1,    2,    2,    3,    3,    1,    1,    2,
    1,    3,    4,    3,    1,    2,    3,    2,    2,    1,
    3,    2,    4,    5,    6,    7,    2,    2,    2,    1,
    1,    1,    1,    1,    3,    3,    3,    3,    3,    3,
    3,    1,    3,    4,    1,    2,    4,    3,    1,    1,
    2,    1,    1,    2,    1,    2,    1,    1,    1,    3,
    3,    4,    3,    2,    4,    3,    3,    1,    2,    1,
    3,    2,    3,    4,    3,    4,    1,    1,    2,    3,
    3,    3,    1,    1,    5,    7,    2,    1,    1,    3,
    4,    3,    2,    2,    3,    9,    8,    8,    8,    7,
    7,    7,    6,    5,    4,    7,    6,
};
static const short yydefred[] = {                         0,
    0,    0,    3,    0,    0,    2,    0,    0,    0,    0,
    0,    0,   60,   30,    0,    0,    0,    0,    0,   38,
   31,    0,    0,    0,    0,    0,   39,   45,    0,    1,
    0,    0,    0,    0,    0,   29,   59,   46,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   57,    0,   58,
   79,   85,    0,   87,   88,   89,    0,    0,   32,    0,
    0,    0,    0,    0,  109,    0,    0,   40,    0,    0,
   47,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   80,    0,   63,   64,   83,   82,    0,    0,    0,
    0,    0,   62,   72,    0,    0,  107,    0,    0,   94,
   84,   86,    0,    0,   53,    0,   50,    0,   37,    0,
  111,  112,    0,    0,  100,    0,    0,    0,   27,    0,
    0,   42,    0,    0,  119,   44,   90,   91,    0,    0,
    0,    0,  113,    0,    0,    0,    0,    0,    0,   78,
   81,    0,  102,    0,   76,    0,    0,    0,    0,    0,
    0,   93,    0,    0,    0,  122,    0,    0,   52,   54,
    0,    0,    0,    0,    0,    0,    0,   16,   12,    0,
    0,    0,    0,    0,   28,   26,  117,   43,    0,   92,
    0,  135,    0,    0,    0,    0,    0,   77,   65,   66,
   67,   69,  101,  103,    0,  105,    0,    0,   96,   73,
   97,   68,   70,   71,  121,    0,   51,   55,    0,    0,
    0,    0,   13,   14,    0,   15,    0,    0,  120,  134,
    0,    0,    0,    0,    0,    0,    0,   74,  104,  106,
   95,    0,    0,   56,    8,    0,    0,    0,  123,  124,
  133,    0,    0,    0,    0,    0,    0,    0,  137,    0,
    9,   10,    0,    0,  132,  131,    0,  130,    0,    0,
    0,  116,  136,   11,  128,  127,  129,    0,  126,
};
static const short yydgoto[] = {                          2,
    4,    9,   10,   11,   12,  166,  106,  167,  168,  169,
  170,  119,  120,   14,   20,   49,   22,   28,  123,   29,
   15,  107,   16,   50,   91,  124,  133,   94,  115,   96,
   81,   51,   52,   53,   54,   55,   56,   23,  135,  125,
  223,
};
static const short yysindex[] = {                      -240,
 -257,    0,    0, -148, -211,    0, -256, -236, -195, -133,
 -241, -180,    0,    0,   31,   58, -182, -160,   23,    0,
    0,   82, -152, -131,  -39, -127,    0,    0,  125,    0,
 -241, -180,  131,  -97, -180,    0,    0,    0,   11,  156,
  157,  179,  105,  -40,  180,  165,  153,    0,  249,    0,
    0,    0,  271,    0,    0,    0,    0,   73,    0,  -30,
   66, -126,  -36,  115,    0,  -34,   81,    0, -236, -180,
    0,  275,  288,   79,   19,  -54,   30, -126,   49,  105,
  185,    0,  -13,    0,    0,    0,    0,  -37,    8,  -16,
  314,   92,    0,    0,  101,  104,    0,  -14,  126,    0,
    0,    0,    0,  128,    0,  113,    0,  348,    0,  -38,
    0,    0,    4,   92,    0, -114, -114, -114,    0, -118,
  132,    0,  130,   92,    0,    0,    0,    0,  325,  121,
   48,  165,    0,  101,  360,   26,  349,  366,  199,    0,
    0,  -60,    0, -230,    0,   48,  -28,    4,  370,  -26,
  -31,    0,    4, -100,   48,    0,  172,  373,    0,    0,
  164,   70,   52,  138, -114,  371,  374,    0,    0, -101,
 -114, -101, -114, -101,    0,    0,    0,    0,    6,    0,
  121,    0,  165,  -32,  379,   27,  165,    0,    0,    0,
    0,    0,    0,    0,  -27,    0, -224,    1,    0,    0,
    0,    0,    0,    0,    0,   28,    0,    0,  173,   71,
  389, -101,    0,    0,  392,    0, -101, -101,    0,    0,
  -84,  165,  398,   10,   33,  382,  178,    0,    0,    0,
    0,  391,  413,    0,    0,  291,   72,    4,    0,    0,
    0,  165,  165,  414,  165,  415,   67,  165,    0,  399,
    0,    0,  295,   92,    0,    0,  165,    0,  165,  165,
  418,    0,    0,    0,    0,    0,    0,  165,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  203,    0,    0,    0,    0,  -42,    0,    0,    0,
    0,  405,    0,    0,   32,    0,    0,    0,  408,    0,
    0,  210,    0,    0,  218,    0,    0,    0,  201,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   55,   57,    0,    0,
    0,    0,    0,    0,    0,    0,  201,    0,    0,  220,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   12,    0,    0,    0,    0,    0,    0,    0,
    0,  422,    0,    0,   14,   61,    0,    0,    0,    0,
    0,    0,   59,    0,    0,    0,    0,    0,    0,   -9,
    0,    0,    0,  -23,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  299,    0,    0,    0,    0,    0,   87,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   -1,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -88,    0,    0,    0,    0,   89,
  100,  123,  135,  194,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  208,    0,    0,    0,    0,  212,  217,    0,    0,
    0,    0,    0,    0,    0,    0,  -81,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  441,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  -12,  491,  124,    0, -110,    0,  -51,  344,
  -21,  383,    0,   76,  440,  333,    0,  435,  407,    0,
   13,  345,    0,  177,    0,   20,  463,    0,    5,   -6,
  428,   -2,    0,  287,    0,    0,    0,    0,  -64,  330,
 -186,
};
#define YYTABLESIZE 525
static const short yytable[] = {                         90,
   66,   33,  146,  113,  136,  113,  122,  144,  222,  200,
  105,  164,  138,  228,  199,   34,   33,  197,    1,    3,
  110,   25,   33,   90,  164,  113,  156,  193,   26,   24,
   80,   98,  144,  229,   98,  110,    7,  244,  246,   99,
   82,  231,   99,  113,  115,  113,   17,  148,   95,   98,
  243,  209,   98,   18,  100,   45,   74,   99,  131,  132,
  261,   45,   60,   92,   30,  131,  131,  131,  232,  131,
   98,  185,  100,  245,   19,   41,   34,   82,  141,  134,
   61,  134,  114,  151,  184,  225,   36,  131,   98,   38,
   41,  210,   33,   57,   95,  172,  174,   58,   35,  236,
   34,   75,   36,  165,  171,  173,   36,  260,    5,  150,
  208,  235,  252,   35,   63,   34,   48,   36,  216,   75,
  216,  226,  216,    5,  151,   62,  253,  114,    6,    7,
   67,   17,  150,   32,   35,  134,  141,    8,   18,  195,
  134,  233,    5,  212,    7,  114,  192,   64,  204,  217,
  134,  218,    8,  160,   70,   34,  161,  202,  203,  134,
  216,  175,  116,  117,  118,  216,  216,  198,   69,   86,
  178,  163,  201,  179,   87,  115,  115,   33,  115,  115,
  115,  115,  238,   33,  215,   33,  239,  240,   19,   71,
  134,   18,   18,   18,   18,   75,   76,  189,  115,  115,
  115,  115,  115,   67,  115,  115,  115,  190,  191,   86,
  134,  100,  205,  234,   87,  179,  161,   83,   77,   98,
  145,  110,   99,  110,  108,  221,  104,   84,   85,   86,
  121,  111,  112,   86,   87,   86,   65,  143,   87,  153,
   87,   83,  155,  110,   88,   45,  155,  196,   89,   45,
  121,   45,   89,   86,   89,   86,   98,  254,   87,  142,
   87,  110,  143,  110,   99,  147,  153,  221,  149,   45,
  121,   45,   89,   86,   89,   86,  130,   98,   87,  100,
   87,   72,   73,  130,  130,  130,   65,  130,   86,   45,
  221,   45,   89,   87,   89,   86,   86,   86,  108,   86,
   87,   87,   87,   88,   87,  181,   25,  101,  182,   25,
   88,   88,   88,   26,   88,   39,   26,   86,   40,   41,
   42,  109,   87,  108,  221,  109,  104,  104,  104,  102,
   97,  251,  149,  127,  161,  264,   43,   21,  161,  118,
   27,   44,  118,   45,   46,   47,  128,   13,  103,   97,
   59,  108,   97,   13,   13,   37,   65,  153,   68,  220,
  129,   78,   39,  227,   45,   40,   41,   42,   19,   19,
   19,   19,  152,  154,   13,   37,   97,  155,   37,   21,
   21,   21,   21,  180,   97,  159,  158,  162,   44,  177,
   79,   46,   47,  142,   21,  116,  117,  118,  241,   97,
  183,   27,   22,   22,   22,   22,  187,  186,  137,  146,
   21,   27,  206,   37,   24,   24,   24,   24,  255,  256,
  104,  258,   39,  211,  262,   40,   41,   42,  237,  213,
  194,  210,  214,  265,   97,  266,  267,  224,  242,   97,
  247,  248,   39,   43,  269,   40,   41,   42,   44,  249,
   45,   46,   47,  250,  257,  259,   39,  263,  268,   40,
   41,   42,    7,   48,  140,   97,   49,  108,   44,    6,
   45,   46,   47,   25,   25,   25,   25,    5,  188,    4,
   61,  125,   44,  230,   45,   46,   47,   17,   17,   17,
   17,   20,   20,   20,   20,   27,   23,   23,   23,   23,
   31,  109,  176,  126,  157,  207,   93,  139,  219,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   97,
};
static const short yycheck[] = {                         40,
   40,   44,   40,   40,   59,   40,   41,   46,   41,   41,
   41,  126,   77,   41,   41,  257,   59,   46,  259,  277,
   44,  258,   10,   40,  126,   40,   41,  258,  265,  286,
   43,   41,   46,  258,   44,   59,  278,  224,  225,   41,
   43,   41,   44,   40,  126,   40,  258,   40,   44,   59,
   41,  162,   41,  265,   41,  286,   46,   59,   40,   41,
  247,  286,   40,   44,  260,   40,   40,   40,   41,   40,
   59,  136,   59,   41,  286,   44,  257,   80,   81,   75,
   58,   77,   63,   90,   59,   59,   11,   40,   40,   59,
   59,   40,   80,  276,   90,  117,  118,  258,   44,  210,
   44,   41,   44,  116,  117,  118,   31,   41,  257,   90,
   41,   41,   41,   59,  267,   59,   59,   59,  170,   59,
  172,  186,  174,  257,  131,   44,  237,   41,  277,  278,
  258,  258,  113,   10,   11,  131,  139,  286,  265,  146,
  136,  206,  257,  165,  278,   59,  142,  279,  155,  171,
  146,  173,  286,   41,   31,  257,   44,  258,  154,  155,
  212,  280,  281,  282,  283,  217,  218,  148,   44,  270,
   41,  286,  153,   44,  275,  257,  258,  165,  260,  261,
  262,  263,  267,  171,  286,  173,  271,  272,  286,   59,
  186,  280,  281,  282,  283,   40,   40,  258,  280,  281,
  282,  283,  284,  258,  286,  287,  288,  268,  269,  270,
  206,   59,   41,   41,  275,   44,   44,  258,   40,   40,
  258,  258,   46,  258,  267,  258,  257,  268,  269,  270,
  265,  268,  269,  270,  275,  270,  276,  276,  275,  266,
  275,  258,  274,  258,  285,  286,  274,  276,  289,  286,
  265,  286,  289,  270,  289,  270,  266,  238,  275,  273,
  275,  258,  276,  258,  266,  258,  266,  258,  285,  286,
  265,  286,  289,  270,  289,  270,  258,  266,  275,  266,
  275,  271,  272,  258,  258,  258,  276,  258,  270,  286,
  258,  286,  289,  275,  289,  270,  270,  270,  267,  270,
  275,  275,  275,  285,  275,  258,  258,   59,  132,  258,
  285,  285,  285,  265,  285,  258,  265,  270,  261,  262,
  263,  267,  275,  267,  258,  267,  257,  257,  257,   59,
   44,   41,  285,   59,   44,   41,  279,    5,   44,   41,
    8,  284,   44,  286,  287,  288,   59,    4,  276,   63,
   18,  286,   66,   10,   11,   12,  276,  266,   26,  183,
   74,  257,  258,  187,  286,  261,  262,  263,  280,  281,
  282,  283,   59,  273,   31,   32,   90,  274,   35,  280,
  281,  282,  283,   59,   98,  258,  261,   40,  284,  258,
  286,  287,  288,  273,   62,  281,  282,  283,  222,  113,
   41,   69,  280,  281,  282,  283,   41,   59,   76,   40,
   78,   79,   40,   70,  280,  281,  282,  283,  242,  243,
  257,  245,  258,  286,  248,  261,  262,  263,   40,   59,
  144,   40,   59,  257,  148,  259,  260,   59,   41,  153,
   59,  264,  258,  279,  268,  261,  262,  263,  284,   59,
  286,  287,  288,   41,   41,   41,  258,   59,   41,  261,
  262,  263,  260,   59,  280,  179,   59,  267,  284,  260,
  286,  287,  288,  280,  281,  282,  283,  260,  280,  260,
   59,   41,  284,  197,  286,  287,  288,  280,  281,  282,
  283,  280,  281,  282,  283,  163,  280,  281,  282,  283,
   10,   62,  120,   69,   98,  161,   44,   80,  179,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  238,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,"'.'",0,0,0,0,0,0,0,0,0,0,0,"':'","';'",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"TIP",
"ID","BGINP","ENDP","WHILE","FOR","IF","ELSE","CONST","OPRARM","ASSIGN",
"CARACTER","SIR_CARACTERE","INTG","INC","DEC","OPRCOMP","OPRLOG","RATIONAL",
"DIM_VEC","LIBRARIE","CLASA","BGINB","ENDB","PRIVATE","PUBLIC","PROTECTED",
"RETURNAT","NEG","NUME","DO","BREAK","MINUS","IFX","illegal-symbol",
};
static const char *yyrule[] = {
"$accept : program",
"program : BGINP librarii corp ENDP",
"librarii : librarii LIBRARIE",
"librarii : LIBRARIE",
"corp : declaratii clase functions",
"corp : clase functions",
"corp : declaratii functions",
"corp : functions",
"constr : NUME '(' ')'",
"constr : NUME '(' lista_param ')'",
"destruct : '~' NUME '(' ')'",
"destruct : '~' NUME '(' lista_param ')'",
"method : function",
"method : constr ';'",
"method : destruct ';'",
"methods : methods method",
"methods : method",
"TYPE : PRIVATE declaratii methods",
"TYPE : PRIVATE declaratii",
"TYPE : PRIVATE methods",
"TYPE : PUBLIC declaratii methods",
"TYPE : PUBLIC declaratii",
"TYPE : PUBLIC methods",
"TYPE : PROTECTED declaratii methods",
"TYPE : PROTECTED declaratii",
"TYPE : PROTECTED methods",
"TYPES : TYPES TYPE",
"TYPES : TYPE",
"clasa : CLASA NUME BGINB TYPES ENDB",
"clase : clase clasa",
"clase : clasa",
"variab : asignare",
"variab : CONST asignare",
"variab : ID",
"variab : CONST ID",
"variab : ID DIM_VEC",
"variab : CONST ID DIM_VEC",
"variabile : variabile ',' variab",
"variabile : variab",
"object : asignare",
"object : CONST asignare",
"object : ID",
"object : ID '(' ')'",
"object : ID '(' lista_apel ')'",
"objects : objects ',' object",
"objects : object",
"declaratii : declaratie ';'",
"declaratii : declaratii declaratie ';'",
"declaratie : TIP variabile",
"declaratie : NUME objects",
"lista_param : param",
"lista_param : lista_param ',' param",
"param : TIP ID",
"antet_fct : TIP NUME '(' ')'",
"antet_fct : TIP NUME '(' lista_param ')'",
"antet_fct : TIP NUME ':' NUME '(' ')'",
"antet_fct : TIP NUME ':' NUME '(' lista_param ')'",
"function : antet_fct ';'",
"function : antet_fct bloc",
"functions : functions function",
"functions : function",
"RETURN : exp",
"RETURN : val_adev",
"RETURN : CARACTER",
"RETURN : SIR_CARACTERE",
"comparatie : ID OPRCOMP ID",
"comparatie : ID OPRCOMP CARACTER",
"comparatie : ID OPRCOMP SIR_CARACTERE",
"comparatie : NR OPRCOMP ID",
"comparatie : ID OPRCOMP NR",
"comparatie : NR OPRCOMP NR",
"adev : adev OPRLOG adev",
"adev : comparatie",
"adev : '(' adev ')'",
"adev : NEG '(' adev ')'",
"val_adev : adev",
"val_adev : NEG ID",
"bloc : BGINB declaratii list ENDB",
"bloc : BGINB list ENDB",
"bloc : statement",
"list : statement",
"list : list statement",
"NR : RATIONAL",
"NR : INTG",
"statement : asignare ';'",
"statement : daca",
"statement : apel_fct ';'",
"statement : pentru",
"statement : cat_timp",
"statement : repeta",
"statement : ID INC ';'",
"statement : ID DEC ';'",
"statement : ID '.' apel_fct ';'",
"statement : RETURNAT RETURN ';'",
"statement : BREAK ';'",
"exp : MINUS '(' exp ')'",
"exp : '(' exp ')'",
"exp : exp OPRARM exp",
"exp : ID",
"exp : MINUS ID",
"exp : NR",
"exp : ID '.' ID",
"exp : ID DIM_VEC",
"exp : ID '.' apel_fct",
"exp : MINUS ID '.' ID",
"exp : MINUS ID DIM_VEC",
"exp : MINUS ID '.' apel_fct",
"exp : apel_fct",
"element : ID",
"element : ID DIM_VEC",
"asignare : element ASSIGN exp",
"asignare : element ASSIGN CARACTER",
"asignare : element ASSIGN SIR_CARACTERE",
"conditie : val_adev",
"conditie : ID",
"daca : IF '(' conditie ')' bloc",
"daca : IF '(' conditie ')' bloc ELSE bloc",
"param_apel : CONST ID",
"param_apel : exp",
"lista_apel : param_apel",
"lista_apel : lista_apel ',' param_apel",
"apel_fct : NUME '(' lista_apel ')'",
"apel_fct : NUME '(' ')'",
"pas : ID INC",
"pas : ID DEC",
"pas : ID ASSIGN exp",
"pentru : FOR '(' asignare ';' conditie ';' pas ')' bloc",
"pentru : FOR '(' asignare ';' ';' pas ')' bloc",
"pentru : FOR '(' ';' conditie ';' pas ')' bloc",
"pentru : FOR '(' asignare ';' conditie ';' ')' bloc",
"pentru : FOR '(' asignare ';' ';' ')' bloc",
"pentru : FOR '(' ';' conditie ';' ')' bloc",
"pentru : FOR '(' ';' ';' pas ')' bloc",
"pentru : FOR '(' ';' ';' ')' bloc",
"cat_timp : WHILE '(' conditie ')' bloc",
"cat_timp : WHILE '(' ')' bloc",
"repeta : DO bloc WHILE '(' conditie ')' ';'",
"repeta : DO bloc WHILE '(' ')' ';'",

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
#line 240 "tema1.y"
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 
#line 545 "y.tab.c"

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
#line 15 "tema1.y"
	{printf("program corect sintactic\n");}
break;
#line 751 "y.tab.c"
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
