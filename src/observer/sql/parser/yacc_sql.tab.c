/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "yacc_sql.y" /* yacc.c:339  */


#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.tab.h"
#include "sql/parser/lex.yy.h"
// #include "common/log/log.h" // 包含C++中的头文件

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ParserContext {
  Query * ssql;
  size_t select_length;
  size_t condition_length;
  size_t from_length;
  size_t value_length;
  Value values[MAX_NUM];
  Condition conditions[MAX_NUM];
  CompOp comp;
	char id[MAX_NUM];
} ParserContext;

//获取子串
char *substr(const char *s,int n1,int n2)/*从s中提取下标为n1~n2的字符组成一个新字符串，然后返回这个新串的首地址*/
{
  char *sp = malloc(sizeof(char) * (n2 - n1 + 2));
  int i, j = 0;
  for (i = n1; i <= n2; i++) {
    sp[j++] = s[i];
  }
  sp[j] = 0;
  return sp;
}

void yyerror(yyscan_t scanner, const char *str)
{
  ParserContext *context = (ParserContext *)(yyget_extra(scanner));
  query_reset(context->ssql);
  context->ssql->flag = SCF_ERROR;
  context->condition_length = 0;
  context->from_length = 0;
  context->select_length = 0;
  context->value_length = 0;
  context->ssql->sstr.insertion.value_num = 0;
  printf("parse sql failed. error=%s", str);
}

ParserContext *get_context(yyscan_t scanner)
{
  return (ParserContext *)yyget_extra(scanner);
}

#define CONTEXT get_context(scanner)


#line 123 "yacc_sql.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yacc_sql.tab.h".  */
#ifndef YY_YY_YACC_SQL_TAB_H_INCLUDED
# define YY_YY_YACC_SQL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON = 258,
    CREATE = 259,
    DROP = 260,
    TABLE = 261,
    TABLES = 262,
    INDEX = 263,
    SELECT = 264,
    MAX = 265,
    MIN = 266,
    COUNT = 267,
    AVG = 268,
    DESC = 269,
    SHOW = 270,
    SYNC = 271,
    INSERT = 272,
    DELETE = 273,
    UPDATE = 274,
    LBRACE = 275,
    RBRACE = 276,
    COMMA = 277,
    TRX_BEGIN = 278,
    TRX_COMMIT = 279,
    TRX_ROLLBACK = 280,
    INT_T = 281,
    STRING_T = 282,
    FLOAT_T = 283,
    DATE_T = 284,
    HELP = 285,
    EXIT = 286,
    DOT = 287,
    INTO = 288,
    VALUES = 289,
    FROM = 290,
    WHERE = 291,
    AND = 292,
    SET = 293,
    ON = 294,
    LOAD = 295,
    DATA = 296,
    INFILE = 297,
    EQ = 298,
    LT = 299,
    GT = 300,
    LE = 301,
    GE = 302,
    NE = 303,
    ORDER = 304,
    BY = 305,
    ASC = 306,
    NUMBER = 307,
    FLOAT = 308,
    ID = 309,
    PATH = 310,
    SSS = 311,
    STAR = 312,
    STRING_V = 313
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 114 "yacc_sql.y" /* yacc.c:355  */

  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  char *string;
  int number;
  float floats;
	char *position;

#line 232 "yacc_sql.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void *scanner);

#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 248 "yacc_sql.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  275

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   140,   140,   142,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   166,   171,   176,   182,   188,   194,   200,   206,   212,
     219,   227,   234,   243,   245,   249,   260,   273,   276,   277,
     278,   280,   283,   292,   308,   310,   315,   318,   321,   328,
     338,   348,   366,   368,   373,   378,   383,   388,   393,   398,
     404,   406,   411,   416,   421,   426,   431,   439,   444,   449,
     455,   462,   468,   474,   480,   486,   492,   498,   504,   510,
     518,   520,   527,   536,   538,   544,   550,   556,   562,   568,
     574,   580,   586,   593,   595,   599,   601,   605,   607,   612,
     633,   653,   673,   695,   716,   737,   759,   760,   761,   762,
     763,   764,   768
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "CREATE", "DROP", "TABLE",
  "TABLES", "INDEX", "SELECT", "MAX", "MIN", "COUNT", "AVG", "DESC",
  "SHOW", "SYNC", "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE",
  "COMMA", "TRX_BEGIN", "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T",
  "FLOAT_T", "DATE_T", "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM",
  "WHERE", "AND", "SET", "ON", "LOAD", "DATA", "INFILE", "EQ", "LT", "GT",
  "LE", "GE", "NE", "ORDER", "BY", "ASC", "NUMBER", "FLOAT", "ID", "PATH",
  "SSS", "STAR", "STRING_V", "$accept", "commands", "command", "exit",
  "help", "sync", "begin", "commit", "rollback", "drop_table",
  "show_tables", "desc_table", "create_index", "drop_index",
  "create_table", "attr_def_list", "attr_def", "number", "type", "ID_get",
  "insert", "value_list", "value", "delete", "update", "select", "order",
  "order_attr", "order_list", "select_attr", "attr_list", "agg_list",
  "rel_list", "where", "condition_list", "condition", "comOp", "load_data", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313
};
# endif

#define YYPACT_NINF -212

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-212)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -212,    76,  -212,   113,   117,     0,   -46,    17,    22,    -3,
      16,   -22,    53,    69,    71,    75,    81,    23,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,    25,    42,    63,    80,
      84,   118,   123,   136,     1,  -212,    70,   162,   163,  -212,
     107,   120,   134,  -212,  -212,  -212,  -212,  -212,   131,   155,
     137,   174,   175,   125,   126,    -5,   127,   128,    29,  -212,
     129,  -212,  -212,   150,   149,   132,   133,   138,   139,  -212,
    -212,   -14,    -4,    -1,   166,    21,     5,   168,   168,   169,
     176,    83,   185,   151,   164,  -212,   173,   119,   178,   177,
     146,   177,   147,   177,   148,   177,   177,   152,   153,  -212,
    -212,  -212,   154,   149,   111,  -212,  -212,    65,  -212,    85,
     167,  -212,   111,   197,   138,   184,  -212,  -212,  -212,  -212,
     189,   156,   158,  -212,   190,  -212,   191,  -212,   192,  -212,
    -212,   193,   168,   169,   170,   194,   161,  -212,  -212,  -212,
    -212,  -212,  -212,    88,   101,    83,  -212,   149,   171,   173,
     214,   172,   199,   198,   201,   202,   203,   177,   177,   177,
     177,  -212,  -212,   179,   223,   111,   206,    85,  -212,  -212,
     196,  -212,   167,   227,   228,  -212,  -212,  -212,   211,   230,
     180,   181,    61,   182,  -212,  -212,  -212,  -212,   183,  -212,
     194,   235,   106,   186,  -212,  -212,  -212,  -212,  -212,    50,
      56,    66,   218,    82,     7,  -212,  -212,  -212,   209,  -212,
    -212,   177,   188,   177,   195,   177,   200,   177,   177,   204,
     221,   205,   207,   221,  -212,   208,  -212,   224,  -212,   225,
    -212,   226,  -212,  -212,   229,  -212,    12,    24,  -212,  -212,
     177,   177,   177,   177,   221,   210,   221,  -212,   221,   221,
    -212,  -212,  -212,  -212,  -212,  -212,    51,  -212,  -212,  -212,
     221,   221,  -212,  -212,  -212
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,    20,
      19,    14,    15,    16,    17,     9,    10,    11,    12,    13,
       8,     5,     7,     6,     4,    18,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    67,     0,     0,     0,    23,
       0,     0,     0,    24,    25,    26,    22,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
       0,    29,    28,     0,    95,     0,     0,     0,     0,    27,
      31,     0,     0,     0,     0,     0,    80,    80,    80,    93,
       0,     0,     0,     0,     0,    42,    33,     0,     0,    83,
       0,    83,     0,    83,     0,    83,    83,     0,     0,    81,
      69,    70,     0,    95,     0,    46,    47,     0,    48,     0,
      97,    49,     0,     0,     0,     0,    38,    39,    40,    41,
      36,     0,     0,    74,     0,    76,     0,    72,     0,    71,
      78,     0,    80,    93,    52,    44,     0,   106,   107,   108,
     109,   110,   111,     0,     0,     0,    96,    95,     0,    33,
       0,     0,     0,     0,     0,     0,     0,    83,    83,    83,
      83,    82,    94,     0,     0,     0,     0,     0,   101,    99,
     102,   100,    97,     0,     0,    34,    32,    37,     0,     0,
       0,     0,     0,     0,    75,    77,    73,    79,     0,    51,
      44,     0,     0,     0,    98,    50,   112,    35,    30,     0,
       0,     0,     0,     0,    60,    53,    45,    43,     0,   103,
     104,    83,     0,    83,     0,    83,     0,    83,    83,     0,
      60,     0,     0,    60,    54,     0,    87,     0,    89,     0,
      85,     0,    84,    91,     0,    58,    60,    60,    56,   105,
      83,    83,    83,    83,    60,     0,    60,    61,    60,    60,
      55,    88,    90,    86,    92,    65,    60,    63,    59,    57,
      60,    60,    62,    66,    64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,    89,   141,  -212,  -212,  -212,
    -212,    44,  -113,  -212,  -212,  -212,  -212,  -212,  -211,  -212,
     -72,  -101,   108,  -107,    73,    97,  -116,  -212
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   125,    96,   188,   130,    97,
      31,   176,   119,    32,    33,    34,   174,   215,   234,    46,
      69,   133,   113,    92,   156,   120,   153,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     135,   145,   137,   154,   139,   140,   144,    99,    47,   157,
      40,    41,    42,    43,   109,   110,   111,   101,   100,   245,
     103,   230,   248,    67,    48,    49,   254,    67,   102,   231,
      50,   104,    52,    68,   231,   257,   260,   108,   258,   232,
     179,   181,   106,   265,   255,   267,   231,   268,   269,    83,
     183,    51,    84,   107,    44,   272,    53,    45,   233,   273,
     274,   202,   200,   256,    58,   270,   194,   195,   196,   197,
     171,   221,    54,   231,    55,   259,     2,   223,    56,    59,
       3,     4,   222,    87,    57,     5,    88,   225,   224,   219,
       6,     7,     8,     9,    10,    11,    60,   146,   226,    12,
      13,    14,   271,   228,    63,    70,    15,    16,   147,   148,
     149,   150,   151,   152,   229,   211,    17,    61,   212,    36,
     236,    37,   238,    38,   240,    39,   242,   243,   147,   148,
     149,   150,   151,   152,    62,   115,   116,   117,    64,   118,
     115,   116,   178,    65,   118,   126,   127,   128,   129,   261,
     262,   263,   264,   115,   116,   180,    66,   118,   115,   116,
     218,    73,   118,   115,   116,    71,    72,   118,   163,   164,
     165,   166,    75,    76,    74,    77,    78,    79,    80,    81,
      82,    85,    86,    89,    90,    91,    93,   105,   121,    94,
      67,   112,    95,    98,   122,   124,   114,   123,   131,   132,
     134,   136,   138,   158,   155,   160,   141,   142,   143,   161,
     162,   167,   168,   169,   170,   177,   175,   186,   190,   173,
     189,   191,   192,   193,   187,   184,   199,   201,   203,   198,
     205,   206,   207,   208,   209,   210,   213,   214,   217,   227,
     220,   235,   237,   231,   216,   250,   251,   252,   185,   239,
     253,   172,   182,     0,   241,   204,     0,     0,   244,   246,
       0,   247,   249,     0,   266,   159
};

static const yytype_int16 yycheck[] =
{
     101,   114,   103,   119,   105,   106,   113,    21,    54,   122,
      10,    11,    12,    13,    86,    87,    88,    21,    32,   230,
      21,    14,   233,    22,     7,     3,    14,    22,    32,    22,
      33,    32,    54,    32,    22,   246,   247,    32,    14,    32,
     153,   154,    21,   254,    32,   256,    22,   258,   259,    54,
     157,    35,    57,    32,    54,   266,     3,    57,    51,   270,
     271,   177,   175,    51,    41,    14,   167,   168,   169,   170,
     142,    21,     3,    22,     3,    51,     0,    21,     3,    54,
       4,     5,    32,    54,     3,     9,    57,    21,    32,   202,
      14,    15,    16,    17,    18,    19,    54,    32,    32,    23,
      24,    25,    51,    21,    20,    35,    30,    31,    43,    44,
      45,    46,    47,    48,    32,    54,    40,    54,    57,     6,
     221,     8,   223,     6,   225,     8,   227,   228,    43,    44,
      45,    46,    47,    48,    54,    52,    53,    54,    20,    56,
      52,    53,    54,    20,    56,    26,    27,    28,    29,   250,
     251,   252,   253,    52,    53,    54,    20,    56,    52,    53,
      54,    54,    56,    52,    53,     3,     3,    56,    10,    11,
      12,    13,    38,    42,    54,    20,    39,     3,     3,    54,
      54,    54,    54,    54,    34,    36,    54,    21,     3,    56,
      22,    22,    54,    54,    43,    22,    20,    33,    20,    22,
      54,    54,    54,     6,    37,    21,    54,    54,    54,    20,
      54,    21,    21,    21,    21,    54,    22,     3,    20,    49,
      21,    20,    20,    20,    52,    54,     3,    21,    32,    50,
       3,     3,    21,     3,    54,    54,    54,    54,     3,    21,
      54,    32,    54,    22,   200,    21,    21,    21,   159,    54,
      21,   143,   155,    -1,    54,   182,    -1,    -1,    54,    54,
      -1,    54,    54,    -1,    54,   124
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    60,     0,     4,     5,     9,    14,    15,    16,    17,
      18,    19,    23,    24,    25,    30,    31,    40,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    79,    82,    83,    84,    96,     6,     8,     6,     8,
      10,    11,    12,    13,    54,    57,    88,    54,     7,     3,
      33,    35,    54,     3,     3,     3,     3,     3,    41,    54,
      54,    54,    54,    20,    20,    20,    20,    22,    32,    89,
      35,     3,     3,    54,    54,    38,    42,    20,    39,     3,
       3,    54,    54,    54,    57,    54,    54,    54,    57,    54,
      34,    36,    92,    54,    56,    54,    75,    78,    54,    21,
      32,    21,    32,    21,    32,    21,    21,    32,    32,    89,
      89,    89,    22,    91,    20,    52,    53,    54,    56,    81,
      94,     3,    43,    33,    22,    74,    26,    27,    28,    29,
      77,    20,    22,    90,    54,    90,    54,    90,    54,    90,
      90,    54,    54,    54,    92,    81,    32,    43,    44,    45,
      46,    47,    48,    95,    95,    37,    93,    81,     6,    75,
      21,    20,    54,    10,    11,    12,    13,    21,    21,    21,
      21,    89,    91,    49,    85,    22,    80,    54,    54,    81,
      54,    81,    94,    92,    54,    74,     3,    52,    76,    21,
      20,    20,    20,    20,    90,    90,    90,    90,    50,     3,
      81,    21,    95,    32,    93,     3,     3,    21,     3,    54,
      54,    54,    57,    54,    54,    86,    80,     3,    54,    81,
      54,    21,    32,    21,    32,    21,    32,    21,    21,    32,
      14,    22,    32,    51,    87,    32,    90,    54,    90,    54,
      90,    54,    90,    90,    54,    87,    54,    54,    87,    54,
      21,    21,    21,    21,    14,    32,    51,    87,    14,    51,
      87,    90,    90,    90,    90,    87,    54,    87,    87,    87,
      14,    51,    87,    87,    87
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    74,    75,    75,    76,    77,    77,
      77,    77,    78,    79,    80,    80,    81,    81,    81,    82,
      83,    84,    85,    85,    86,    86,    86,    86,    86,    86,
      87,    87,    87,    87,    87,    87,    87,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      89,    89,    89,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    91,    91,    92,    92,    93,    93,    94,
      94,    94,    94,    94,    94,    94,    95,    95,    95,    95,
      95,    95,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     4,     3,     3,
       9,     4,     8,     0,     3,     5,     2,     1,     1,     1,
       1,     1,     1,     9,     0,     3,     1,     1,     1,     5,
       8,     8,     0,     3,     2,     4,     3,     5,     3,     5,
       0,     3,     5,     4,     6,     4,     6,     1,     2,     4,
       4,     5,     5,     7,     5,     7,     5,     7,     5,     7,
       0,     3,     5,     0,     6,     6,     8,     6,     8,     6,
       8,     6,     8,     0,     3,     0,     3,     0,     3,     3,
       3,     3,     3,     5,     5,     7,     1,     1,     1,     1,
       1,     1,     8
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (scanner, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void *scanner)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void *scanner)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, scanner);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, void *scanner)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, void *scanner)
{
  YYUSE (yyvaluep);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, scanner);
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 21:
#line 166 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1516 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 171 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1524 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 176 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1532 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 182 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1540 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 188 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1548 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 194 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1556 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 200 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1565 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 206 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1573 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 212 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1582 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 220 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string));
		}
#line 1591 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 228 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1600 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 235 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1612 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 245 "yacc_sql.y" /* yacc.c:1646  */
    {    }
#line 1618 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 250 "yacc_sql.y" /* yacc.c:1646  */
    {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-3].number), (yyvsp[-1].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_length++;
		}
#line 1633 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 261 "yacc_sql.y" /* yacc.c:1646  */
    {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[0].number), 4);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
#line 1648 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 273 "yacc_sql.y" /* yacc.c:1646  */
    {(yyval.number) = (yyvsp[0].number);}
#line 1654 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 276 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number)=INTS; }
#line 1660 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 277 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number)=CHARS; }
#line 1666 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 278 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number)=FLOATS; }
#line 1672 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 280 "yacc_sql.y" /* yacc.c:1646  */
    {(yyval.number)=DATES;}
#line 1678 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 284 "yacc_sql.y" /* yacc.c:1646  */
    {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1687 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 293 "yacc_sql.y" /* yacc.c:1646  */
    {
			// CONTEXT->values[CONTEXT->value_length++] = *$6;

			CONTEXT->ssql->flag=SCF_INSERT;//"insert";
			// CONTEXT->ssql->sstr.insertion.relation_name = $3;
			// CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
			// for(i = 0; i < CONTEXT->value_length; i++){
			// 	CONTEXT->ssql->sstr.insertion.values[i] = CONTEXT->values[i];
      // }
			inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-6].string), CONTEXT->values, CONTEXT->value_length);

      //临时变量清零
      CONTEXT->value_length=0;
    }
#line 1706 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 310 "yacc_sql.y" /* yacc.c:1646  */
    { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1714 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 315 "yacc_sql.y" /* yacc.c:1646  */
    {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1722 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 318 "yacc_sql.y" /* yacc.c:1646  */
    {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1730 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 321 "yacc_sql.y" /* yacc.c:1646  */
    {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1739 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 329 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1751 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 339 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			Value *value = &CONTEXT->values[0];
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-6].string), (yyvsp[-4].string), value, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1763 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 349 "yacc_sql.y" /* yacc.c:1646  */
    {
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string));

			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);

			CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;

			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
	}
#line 1783 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 368 "yacc_sql.y" /* yacc.c:1646  */
    {
	//TODO: add order 
	}
#line 1791 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 373 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1801 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 378 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-3].string),(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1811 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 383 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1821 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 388 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1831 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 393 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1841 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 398 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1851 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 406 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1861 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 411 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-3].string),(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1871 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 416 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1881 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 421 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1891 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 426 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1901 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 431 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1911 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 439 "yacc_sql.y" /* yacc.c:1646  */
    {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*", 0);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1921 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 444 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string), 0);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1931 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 449 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), 0);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1941 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 455 "yacc_sql.y" /* yacc.c:1646  */
    {// add t1.*
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*", 0);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 1951 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 462 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(*)
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*", 5);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 1961 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 468 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(id)
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 1);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 1971 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 474 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(t.id)
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 1);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 1981 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 480 "yacc_sql.y" /* yacc.c:1646  */
    {// add MAX(id)
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 2);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 1991 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 486 "yacc_sql.y" /* yacc.c:1646  */
    {// add MAX(t.id)
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 2);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2001 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 492 "yacc_sql.y" /* yacc.c:1646  */
    {// add MIN(id)
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 3);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2011 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 498 "yacc_sql.y" /* yacc.c:1646  */
    {// add MIN(t.id)
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 3);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2021 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 504 "yacc_sql.y" /* yacc.c:1646  */
    {// add AVG(id)
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 4);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2031 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 510 "yacc_sql.y" /* yacc.c:1646  */
    {// add AVG(t.id)
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 4);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2041 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 520 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string), 0);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 2053 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 527 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), 0);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2065 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 538 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(*)
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*", 5);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2075 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 544 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(id)
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 1);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2085 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 550 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(t.id)
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 1);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2095 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 556 "yacc_sql.y" /* yacc.c:1646  */
    {// add MAX(id)
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 2);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2105 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 562 "yacc_sql.y" /* yacc.c:1646  */
    {// add MAX(t.id)
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 2);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2115 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 568 "yacc_sql.y" /* yacc.c:1646  */
    {// add MIN(id)
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 3);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2125 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 574 "yacc_sql.y" /* yacc.c:1646  */
    {// add MIN(t.id)
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 3);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2135 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 580 "yacc_sql.y" /* yacc.c:1646  */
    {// add AVG(id)
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 4);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2145 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 586 "yacc_sql.y" /* yacc.c:1646  */
    {// add AVG(t.id)
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 4);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
#line 2155 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 595 "yacc_sql.y" /* yacc.c:1646  */
    {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2163 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 601 "yacc_sql.y" /* yacc.c:1646  */
    {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2171 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 607 "yacc_sql.y" /* yacc.c:1646  */
    {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2179 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 613 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string), 0);

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$ = ( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name = NULL;
			// $$->left_attr.attribute_name= $1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 0;
			// $$->right_attr.relation_name = NULL;
			// $$->right_attr.attribute_name = NULL;
			// $$->right_value = *$3;

		}
#line 2204 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 634 "yacc_sql.y" /* yacc.c:1646  */
    {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$ = ( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 0;
			// $$->right_attr.relation_name = NULL;
			// $$->right_attr.attribute_name = NULL;
			// $$->right_value = *$3;

		}
#line 2228 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 654 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string), 0);
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string), 0);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;

		}
#line 2252 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 674 "yacc_sql.y" /* yacc.c:1646  */
    {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string), 0);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp=CONTEXT->comp;
			
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;
		
		}
#line 2278 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 696 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string), 0);
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=$1;
			// $$->left_attr.attribute_name=$3;
			// $$->comp=CONTEXT->comp;
			// $$->right_is_attr = 0;   //属性值
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=NULL;
			// $$->right_value =*$5;			
							
    }
#line 2303 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 717 "yacc_sql.y" /* yacc.c:1646  */
    {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string), 0);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;//属性值
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp =CONTEXT->comp;
			// $$->right_is_attr = 1;//属性
			// $$->right_attr.relation_name = $3;
			// $$->right_attr.attribute_name = $5;
									
    }
#line 2328 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 738 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string), 0);
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string), 0);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;		//属性
			// $$->left_attr.relation_name=$1;
			// $$->left_attr.attribute_name=$3;
			// $$->comp =CONTEXT->comp;
			// $$->right_is_attr = 1;		//属性
			// $$->right_attr.relation_name=$5;
			// $$->right_attr.attribute_name=$7;
    }
#line 2351 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 759 "yacc_sql.y" /* yacc.c:1646  */
    { CONTEXT->comp = EQUAL_TO; }
#line 2357 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 760 "yacc_sql.y" /* yacc.c:1646  */
    { CONTEXT->comp = LESS_THAN; }
#line 2363 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 761 "yacc_sql.y" /* yacc.c:1646  */
    { CONTEXT->comp = GREAT_THAN; }
#line 2369 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 762 "yacc_sql.y" /* yacc.c:1646  */
    { CONTEXT->comp = LESS_EQUAL; }
#line 2375 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 763 "yacc_sql.y" /* yacc.c:1646  */
    { CONTEXT->comp = GREAT_EQUAL; }
#line 2381 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 764 "yacc_sql.y" /* yacc.c:1646  */
    { CONTEXT->comp = NOT_EQUAL; }
#line 2387 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 769 "yacc_sql.y" /* yacc.c:1646  */
    {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2396 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;


#line 2400 "yacc_sql.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (scanner, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
                      yytoken, &yylval, scanner);
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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
                  yystos[yystate], yyvsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, scanner);
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
  return yyresult;
}
#line 774 "yacc_sql.y" /* yacc.c:1906  */

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, Query *sqls){
	ParserContext context;
	memset(&context, 0, sizeof(context));

	yyscan_t scanner;
	yylex_init_extra(&context, &scanner);
	context.ssql = sqls;
	scan_string(s, scanner);
	int result = yyparse(scanner);
	yylex_destroy(scanner);
	return result;
}
