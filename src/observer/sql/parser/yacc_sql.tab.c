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
  //TODO: add subquery
  size_t now_select_dep;//当前查询的深度
  size_t path_to_sub[MAX_NUM];//从第一层定位到当前查询的路径 例如第一个子查询 [0 X X X ...] 基于now_select_dep判断需要徐遍历的位置
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


#line 126 "yacc_sql.tab.c" /* yacc.c:339  */

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
    UNIQUE = 298,
    EQ = 299,
    LT = 300,
    GT = 301,
    LE = 302,
    GE = 303,
    NE = 304,
    ORDER = 305,
    BY = 306,
    ASC = 307,
    INNER = 308,
    JOIN = 309,
    NOT = 310,
    IN_T = 311,
    ISNULL = 312,
    IS = 313,
    NULLABLE = 314,
    NUMBER = 315,
    FLOAT = 316,
    ID = 317,
    PATH = 318,
    SSS = 319,
    STAR = 320,
    STRING_V = 321
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 124 "yacc_sql.y" /* yacc.c:355  */

  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  char *string;
  int number;
  float floats;
	char *position;

#line 243 "yacc_sql.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void *scanner);

#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 259 "yacc_sql.tab.c" /* yacc.c:358  */

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
#define YYLAST   324

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  139
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  334

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   150,   150,   152,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   176,   181,   186,   192,   198,   204,   210,   216,   222,
     229,   234,   242,   249,   258,   260,   264,   275,   287,   298,
     311,   314,   315,   316,   318,   321,   330,   346,   348,   353,
     355,   361,   364,   367,   371,   377,   387,   397,   415,   430,
     437,   439,   444,   449,   454,   459,   464,   469,   475,   477,
     482,   487,   492,   497,   502,   510,   516,   522,   529,   537,
     544,   551,   558,   565,   572,   579,   586,   593,   602,   604,
     612,   622,   624,   631,   638,   645,   652,   659,   666,   673,
     680,   688,   690,   692,   696,   702,   707,   709,   713,   715,
     719,   721,   726,   755,   782,   809,   836,   852,   868,   885,
     910,   926,   942,   959,   986,  1011,  1021,  1031,  1041,  1054,
    1059,  1064,  1069,  1074,  1079,  1084,  1090,  1095,  1100,  1109
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
  "WHERE", "AND", "SET", "ON", "LOAD", "DATA", "INFILE", "UNIQUE", "EQ",
  "LT", "GT", "LE", "GE", "NE", "ORDER", "BY", "ASC", "INNER", "JOIN",
  "NOT", "IN_T", "ISNULL", "IS", "NULLABLE", "NUMBER", "FLOAT", "ID",
  "PATH", "SSS", "STAR", "STRING_V", "$accept", "commands", "command",
  "exit", "help", "sync", "begin", "commit", "rollback", "drop_table",
  "show_tables", "desc_table", "create_index", "drop_index",
  "create_table", "attr_def_list", "attr_def", "number", "type", "ID_get",
  "insert", "value_list", "tuple_list", "value", "delete", "update",
  "select", "head_sub_select", "sub_select", "order", "order_attr",
  "order_list", "select_attr", "attr_list", "agg_list", "rel_list",
  "table_factor", "join_table", "join_on", "where", "condition_list",
  "condition", "comOp", "load_data", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321
};
# endif

#define YYPACT_NINF -234

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-234)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -234,   123,  -234,    86,    31,     9,   -39,    23,    28,    37,
      18,   -18,    42,    43,    80,    96,   109,   102,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,    74,    82,   137,    87,
      88,   138,   140,   141,   144,    89,  -234,   132,   162,   166,
    -234,   122,   125,   155,  -234,  -234,  -234,  -234,  -234,   165,
     180,   171,   149,   214,   217,   159,   161,    52,   163,   164,
      68,  -234,   167,  -234,  -234,   190,   191,   168,   169,   170,
     172,   189,  -234,  -234,     8,    15,    17,   210,    20,   103,
     213,   213,     6,   216,    40,   234,   194,   206,  -234,   218,
     154,   221,   181,   220,   182,   220,   183,   220,   184,   220,
     220,   185,   186,  -234,  -234,  -234,   187,   196,   191,  -234,
    -234,   158,   242,   150,  -234,  -234,   130,  -234,   150,     9,
     150,   215,  -234,   158,   247,   170,   233,  -234,  -234,  -234,
    -234,    -5,   193,   236,   179,  -234,   237,  -234,   238,  -234,
     239,  -234,  -234,   240,   213,     6,   195,   212,  -234,   241,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,   208,  -234,   211,
      95,   203,    46,   152,   232,   207,    40,  -234,   191,   209,
     218,   265,   219,   223,  -234,   249,   222,   252,   253,   254,
     255,   220,   220,   220,   220,  -234,  -234,   243,   225,   274,
     158,   257,  -234,  -234,  -234,  -234,  -234,   150,  -234,  -234,
    -234,  -234,  -234,   251,  -234,   224,   256,   215,   278,   282,
    -234,  -234,  -234,   266,  -234,   286,   269,   229,   230,    69,
     231,  -234,  -234,  -234,  -234,    40,     6,   235,  -234,   241,
     272,    58,   244,     6,   245,  -234,  -234,  -234,  -234,  -234,
     292,    48,    77,    84,   275,    92,   215,  -234,    10,  -234,
    -234,   279,   295,  -234,   268,  -234,  -234,  -234,   191,  -234,
    -234,   220,   246,   220,   248,   220,   250,   220,   220,   258,
    -234,   280,   259,   260,   280,  -234,   158,  -234,   261,   283,
    -234,   284,  -234,   288,  -234,   290,  -234,  -234,   293,  -234,
      11,    12,  -234,   241,  -234,  -234,   220,   220,   220,   220,
     280,   262,   280,  -234,   280,   280,  -234,   294,  -234,  -234,
    -234,  -234,  -234,    13,  -234,  -234,  -234,   272,   280,   280,
    -234,  -234,  -234,  -234
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
       0,     0,     0,     0,     0,    88,    75,     0,     0,     0,
      23,     0,     0,     0,    24,    25,    26,    22,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,     0,    29,    28,     0,   108,     0,     0,     0,
       0,     0,    27,    32,     0,     0,     0,     0,     0,    88,
      88,    88,   101,     0,     0,     0,     0,     0,    45,    34,
       0,     0,     0,    91,     0,    91,     0,    91,     0,    91,
      91,     0,     0,    89,    77,    78,     0,     0,   108,   102,
     103,     0,     0,     0,    51,    52,     0,    53,     0,     0,
       0,   110,    55,     0,     0,     0,     0,    41,    42,    43,
      44,    37,     0,     0,     0,    82,     0,    84,     0,    80,
       0,    79,    86,     0,    88,   101,     0,    60,    54,    47,
      58,   129,   130,   131,   132,   133,   134,     0,   136,   137,
       0,     0,     0,     0,     0,     0,     0,   109,   108,     0,
      34,     0,     0,     0,    39,     0,     0,     0,     0,     0,
       0,    91,    91,    91,    91,    90,   104,   106,     0,     0,
       0,     0,   135,   138,    54,   121,   116,     0,    54,   114,
     112,   125,    54,   115,   113,     0,   127,   110,     0,     0,
      35,    33,    40,     0,    38,     0,     0,     0,     0,     0,
       0,    83,    85,    81,    87,     0,   101,     0,    57,    47,
      49,     0,     0,   101,     0,   111,    56,   139,    36,    30,
       0,     0,     0,     0,     0,     0,   110,   105,    68,    61,
      48,     0,     0,    54,     0,   119,   126,   123,   108,   128,
      31,    91,     0,    91,     0,    91,     0,    91,    91,     0,
     107,    68,     0,     0,    68,    62,     0,    46,     0,     0,
      95,     0,    97,     0,    93,     0,    92,    99,     0,    66,
      68,    68,    64,    47,   124,    59,    91,    91,    91,    91,
      68,     0,    68,    69,    68,    68,    63,     0,    96,    98,
      94,   100,    73,    68,    71,    67,    65,    49,    68,    68,
      70,    50,    74,    72
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,   121,   178,  -234,  -234,  -234,
    -234,  -228,   -24,  -115,  -234,  -234,  -234,  -234,  -165,  -234,
    -234,  -233,   188,   -81,  -105,  -152,  -234,  -234,  -234,  -117,
    -200,  -163,  -114,  -234
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   136,    99,   223,   141,   100,
      31,   201,   262,   128,    32,    33,    34,   129,   130,   199,
     259,   285,    47,    71,   145,   118,   119,   120,   236,    95,
     177,   131,   170,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     147,   157,   149,   196,   151,   152,   159,   211,   113,   114,
     115,   260,   172,   217,   173,   182,   175,   245,   178,    41,
      42,    43,    44,    48,   281,   310,   314,   328,   116,   103,
      49,    50,   282,   282,   282,   282,   105,    39,   107,    40,
     104,   110,   283,   311,    53,    54,    55,   106,   299,   108,
     183,   302,   111,    52,   184,   206,   280,   210,   214,   117,
     122,   218,   284,   312,   315,   329,   122,   313,   316,   271,
      51,    45,   256,   195,    46,   317,   266,   322,   122,   324,
     272,   325,   326,    56,   257,   239,   231,   232,   233,   234,
     330,   268,    36,   241,    37,   332,   333,   123,   273,    57,
     124,   125,   126,   208,   127,   275,   124,   125,   209,   274,
     127,    69,    58,   278,    86,   263,   276,    87,   124,   125,
     264,    70,   127,     2,   279,    69,   265,     3,     4,    38,
      90,   253,     5,    91,   254,   112,    60,     6,     7,     8,
       9,    10,    11,    59,    61,    62,    12,    13,    14,    63,
      64,   289,   204,    15,    16,   124,   125,   205,    65,   127,
      66,    67,   171,    17,    68,    73,   290,    72,   292,    74,
     294,   303,   296,   297,   161,   162,   163,   164,   165,   166,
     137,   138,   139,   140,    75,   167,   168,    76,   169,   187,
     188,   189,   190,    77,   161,   162,   163,   164,   165,   166,
      79,   318,   319,   320,   321,   167,   168,    78,   169,   212,
      80,    81,   124,   125,   213,   158,   127,    82,   124,   125,
      83,    84,   127,    85,    93,    88,    89,    94,   102,    92,
      96,   109,    98,    97,   101,    69,   121,   132,   133,   134,
     135,   142,   144,   143,   146,   148,   150,   153,   154,   155,
     156,   160,   176,   179,   181,   185,   186,   197,   191,   192,
     193,   194,   198,   200,   202,   207,   203,   215,   221,   216,
     225,   219,   227,   228,   229,   230,   237,   238,   240,   222,
     224,   246,   235,   242,   226,   247,   243,   248,   244,   249,
     250,   251,   252,   255,   261,   270,   277,   258,   287,   286,
     288,   220,   282,   331,   305,   306,   267,   269,   291,   307,
     293,   308,   295,   180,   309,   327,     0,   174,     0,     0,
     298,   300,   301,   304,   323
};

static const yytype_int16 yycheck[] =
{
     105,   118,   107,   155,   109,   110,   121,   172,    89,    90,
      91,   239,   126,   176,   128,    20,   130,   217,   133,    10,
      11,    12,    13,    62,    14,    14,    14,    14,    22,    21,
       7,     3,    22,    22,    22,    22,    21,     6,    21,     8,
      32,    21,    32,    32,    62,     3,     3,    32,   281,    32,
      55,   284,    32,    35,    59,   170,   256,   172,   173,    53,
      20,   178,    52,    52,    52,    52,    20,   300,   301,    21,
      33,    62,   235,   154,    65,   303,   241,   310,    20,   312,
      32,   314,   315,     3,   236,   200,   191,   192,   193,   194,
     323,   243,     6,   207,     8,   328,   329,    57,    21,     3,
      60,    61,    62,    57,    64,    21,    60,    61,    62,    32,
      64,    22,     3,    21,    62,    57,    32,    65,    60,    61,
      62,    32,    64,     0,    32,    22,   241,     4,     5,    43,
      62,    62,     9,    65,    65,    32,    62,    14,    15,    16,
      17,    18,    19,    41,    62,     8,    23,    24,    25,    62,
      62,   268,    57,    30,    31,    60,    61,    62,    20,    64,
      20,    20,    32,    40,    20,     3,   271,    35,   273,     3,
     275,   286,   277,   278,    44,    45,    46,    47,    48,    49,
      26,    27,    28,    29,    62,    55,    56,    62,    58,    10,
      11,    12,    13,    38,    44,    45,    46,    47,    48,    49,
      20,   306,   307,   308,   309,    55,    56,    42,    58,    57,
      39,    62,    60,    61,    62,    57,    64,     3,    60,    61,
       3,    62,    64,    62,    34,    62,    62,    36,    39,    62,
      62,    21,    62,    64,    62,    22,    20,     3,    44,    33,
      22,    20,    22,    62,    62,    62,    62,    62,    62,    62,
      54,     9,    37,     6,    21,    62,    20,    62,    21,    21,
      21,    21,    50,    22,    56,    62,    55,    35,     3,    62,
      21,    62,    20,    20,    20,    20,    51,     3,    21,    60,
      57,     3,    39,    32,    62,     3,    62,    21,    32,     3,
      21,    62,    62,    62,    22,     3,    21,    62,     3,    20,
      32,   180,    22,   327,    21,    21,    62,    62,    62,    21,
      62,    21,    62,   135,    21,    21,    -1,   129,    -1,    -1,
      62,    62,    62,    62,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    68,     0,     4,     5,     9,    14,    15,    16,    17,
      18,    19,    23,    24,    25,    30,    31,    40,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    87,    91,    92,    93,   110,     6,     8,    43,     6,
       8,    10,    11,    12,    13,    62,    65,    99,    62,     7,
       3,    33,    35,    62,     3,     3,     3,     3,     3,    41,
      62,    62,     8,    62,    62,    20,    20,    20,    20,    22,
      32,   100,    35,     3,     3,    62,    62,    38,    42,    20,
      39,    62,     3,     3,    62,    62,    62,    65,    62,    62,
      62,    65,    62,    34,    36,   106,    62,    64,    62,    83,
      86,    62,    39,    21,    32,    21,    32,    21,    32,    21,
      21,    32,    32,   100,   100,   100,    22,    53,   102,   103,
     104,    20,    20,    57,    60,    61,    62,    64,    90,    94,
      95,   108,     3,    44,    33,    22,    82,    26,    27,    28,
      29,    85,    20,    62,    22,   101,    62,   101,    62,   101,
      62,   101,   101,    62,    62,    62,    54,   106,    57,    90,
       9,    44,    45,    46,    47,    48,    49,    55,    56,    58,
     109,    32,   109,   109,    99,   109,    37,   107,    90,     6,
      83,    21,    20,    55,    59,    62,    20,    10,    11,    12,
      13,    21,    21,    21,    21,   100,   102,    62,    50,    96,
      22,    88,    56,    55,    57,    62,    90,    62,    57,    62,
      90,    95,    57,    62,    90,    35,    62,   108,   106,    62,
      82,     3,    60,    84,    57,    21,    62,    20,    20,    20,
      20,   101,   101,   101,   101,    39,   105,    51,     3,    90,
      21,   109,    32,    62,    32,   107,     3,     3,    21,     3,
      21,    62,    62,    62,    65,    62,   108,   102,    62,    97,
      88,    22,    89,    57,    62,    90,    95,    62,   102,    62,
       3,    21,    32,    21,    32,    21,    32,    21,    21,    32,
     107,    14,    22,    32,    52,    98,    20,     3,    32,   106,
     101,    62,   101,    62,   101,    62,   101,   101,    62,    98,
      62,    62,    98,    90,    62,    21,    21,    21,    21,    21,
      14,    32,    52,    98,    14,    52,    98,    88,   101,   101,
     101,   101,    98,    62,    98,    98,    98,    21,    14,    52,
      98,    89,    98,    98
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    68,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    79,    80,    81,    82,    82,    83,    83,    83,    83,
      84,    85,    85,    85,    85,    86,    87,    88,    88,    89,
      89,    90,    90,    90,    90,    91,    92,    93,    94,    95,
      96,    96,    97,    97,    97,    97,    97,    97,    98,    98,
      98,    98,    98,    98,    98,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,   100,   100,
     100,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   102,   102,   102,   103,   104,   105,   105,   106,   106,
     107,   107,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   110
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     4,     3,     3,
       9,    10,     4,     8,     0,     3,     5,     2,     4,     3,
       1,     1,     1,     1,     1,     1,    10,     0,     3,     0,
       6,     1,     1,     1,     1,     5,     8,     8,     2,     7,
       0,     3,     2,     4,     3,     5,     3,     5,     0,     3,
       5,     4,     6,     4,     6,     1,     2,     4,     4,     5,
       5,     7,     5,     7,     5,     7,     5,     7,     0,     3,
       5,     0,     6,     6,     8,     6,     8,     6,     8,     6,
       8,     0,     1,     1,     3,     5,     0,     3,     0,     3,
       0,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       3,     3,     5,     5,     7,     3,     5,     3,     5,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     2,     8
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
#line 176 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1570 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 181 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1578 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 186 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1586 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 192 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1594 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 198 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1602 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 204 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1610 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 210 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1619 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 216 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1627 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 222 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1636 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 230 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), 0);
		}
#line 1645 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 235 "yacc_sql.y" /* yacc.c:1646  */
    {
	        CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_unique_index";
	        create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), 1);
	    }
#line 1654 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 243 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1663 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 250 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1675 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 260 "yacc_sql.y" /* yacc.c:1646  */
    {    }
#line 1681 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 265 "yacc_sql.y" /* yacc.c:1646  */
    {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-3].number), (yyvsp[-1].number), 0);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_length++;
		}
#line 1696 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 276 "yacc_sql.y" /* yacc.c:1646  */
    {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[0].number), 8, 0);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
#line 1711 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 288 "yacc_sql.y" /* yacc.c:1646  */
    {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-2].number), 8, 0);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
#line 1726 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 299 "yacc_sql.y" /* yacc.c:1646  */
    {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-1].number), 8, 1);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
#line 1741 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 311 "yacc_sql.y" /* yacc.c:1646  */
    {(yyval.number) = (yyvsp[0].number);}
#line 1747 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 314 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number)=INTS; }
#line 1753 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 315 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number)=CHARS; }
#line 1759 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 316 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number)=FLOATS; }
#line 1765 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 318 "yacc_sql.y" /* yacc.c:1646  */
    {(yyval.number)=DATES;}
#line 1771 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 322 "yacc_sql.y" /* yacc.c:1646  */
    {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1780 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 331 "yacc_sql.y" /* yacc.c:1646  */
    {
			// CONTEXT->values[CONTEXT->value_length++] = *$6;

			CONTEXT->ssql->flag=SCF_INSERT;//"insert";
			// CONTEXT->ssql->sstr.insertion.relation_name = $3;
			// CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
			// for(i = 0; i < CONTEXT->value_length; i++){
			// 	CONTEXT->ssql->sstr.insertion.values[i] = CONTEXT->values[i];
      // }
			inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-7].string), CONTEXT->values, CONTEXT->value_length);

      //临时变量清零
      CONTEXT->value_length=0;
    }
#line 1799 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 348 "yacc_sql.y" /* yacc.c:1646  */
    { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1807 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 355 "yacc_sql.y" /* yacc.c:1646  */
    {
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1815 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 361 "yacc_sql.y" /* yacc.c:1646  */
    {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1823 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 364 "yacc_sql.y" /* yacc.c:1646  */
    {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1831 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 367 "yacc_sql.y" /* yacc.c:1646  */
    {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1840 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 371 "yacc_sql.y" /* yacc.c:1646  */
    {
	    value_init_nullvalue(&CONTEXT->values[CONTEXT->value_length++]);
	    }
#line 1848 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 378 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1860 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 388 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			Value *value = &CONTEXT->values[0];
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-6].string), (yyvsp[-4].string), value, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1872 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 398 "yacc_sql.y" /* yacc.c:1646  */
    {	
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string));
			
			// selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length); 

			CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;

	}
#line 1892 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 415 "yacc_sql.y" /* yacc.c:1646  */
    {
	Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
	//TODO: add sub query
	//判断一下是否有空间存放新遇到的子查询, 如果没有空间
	if(0==st->sub_num){//分配初始空间
		st->sub_select=(Selects *)(malloc(sizeof(Selects)*MAX_NUM));
		st->sub_num=1;
		// path_to_sub[now_select_dep-1]=0;//需要处理的子查询位于index 0
	}else{
		st->sub_num++;//增加一个子查询
	}
	CONTEXT->now_select_dep++;//遇到子查询, 跳入子查询, 深度+1
	CONTEXT->path_to_sub[CONTEXT->now_select_dep-1]=st->sub_num-1;//新增子查询位于index sub_num-1
	}
#line 1911 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 430 "yacc_sql.y" /* yacc.c:1646  */
    {
		//找到子查询, 并做一些收尾工作
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		selects_append_relation(st, (yyvsp[-3].string));
		//处理完一个子查询
		CONTEXT->now_select_dep--;//跳回上一级查询
	}
#line 1923 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 439 "yacc_sql.y" /* yacc.c:1646  */
    {
	//TODO: add order 
	}
#line 1931 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 444 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1941 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 449 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-3].string),(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1951 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 454 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1961 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 459 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1971 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 464 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1981 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 469 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1991 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 477 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2001 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 482 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-3].string),(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2011 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 487 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2021 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 492 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2031 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 497 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2041 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 502 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2051 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 510 "yacc_sql.y" /* yacc.c:1646  */
    {  
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*", 0);
			selects_append_attribute(st, &attr);
		}
#line 2062 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 516 "yacc_sql.y" /* yacc.c:1646  */
    {
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string), 0);
			selects_append_attribute(st, &attr);
		}
#line 2073 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 522 "yacc_sql.y" /* yacc.c:1646  */
    {
		  	Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), 0);
			selects_append_attribute(st, &attr);
		}
#line 2084 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 529 "yacc_sql.y" /* yacc.c:1646  */
    {// add t1.*
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*", 0);
			selects_append_attribute(st, &attr);
	}
#line 2095 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 537 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(*)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*", 5);
			selects_append_attribute(st, &attr);
	}
#line 2106 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 544 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 1);
			selects_append_attribute(st, &attr);
	}
#line 2117 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 551 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 1);
			selects_append_attribute(st, &attr);
	}
#line 2128 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 558 "yacc_sql.y" /* yacc.c:1646  */
    {// add MAX(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 2);
			selects_append_attribute(st, &attr);
	}
#line 2139 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 565 "yacc_sql.y" /* yacc.c:1646  */
    {// add MAX(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 2);
			selects_append_attribute(st, &attr);
	}
#line 2150 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 572 "yacc_sql.y" /* yacc.c:1646  */
    {// add MIN(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 3);
			selects_append_attribute(st, &attr);
	}
#line 2161 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 579 "yacc_sql.y" /* yacc.c:1646  */
    {// add MIN(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 3);
			selects_append_attribute(st, &attr);
	}
#line 2172 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 586 "yacc_sql.y" /* yacc.c:1646  */
    {// add AVG(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 4);
			selects_append_attribute(st, &attr);
	}
#line 2183 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 593 "yacc_sql.y" /* yacc.c:1646  */
    {// add AVG(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 4);
			selects_append_attribute(st, &attr);
	}
#line 2194 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 604 "yacc_sql.y" /* yacc.c:1646  */
    {
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string), 0);
			selects_append_attribute(st, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 2207 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 612 "yacc_sql.y" /* yacc.c:1646  */
    {
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), 0);
			selects_append_attribute(st, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2220 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 624 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(*)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*", 5);
			selects_append_attribute(st, &attr);
	}
#line 2231 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 631 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 1);
			selects_append_attribute(st, &attr);
	}
#line 2242 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 638 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 1);
			selects_append_attribute(st, &attr);
	}
#line 2253 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 645 "yacc_sql.y" /* yacc.c:1646  */
    {// add MAX(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 2);
			selects_append_attribute(st, &attr);
	}
#line 2264 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 652 "yacc_sql.y" /* yacc.c:1646  */
    {// add MAX(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 2);
			selects_append_attribute(st, &attr);
	}
#line 2275 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 659 "yacc_sql.y" /* yacc.c:1646  */
    {// add MIN(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 3);
			selects_append_attribute(st, &attr);
	}
#line 2286 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 666 "yacc_sql.y" /* yacc.c:1646  */
    {// add MIN(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 3);
			selects_append_attribute(st, &attr);
	}
#line 2297 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 673 "yacc_sql.y" /* yacc.c:1646  */
    {// add AVG(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 4);
			selects_append_attribute(st, &attr);
	}
#line 2308 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 680 "yacc_sql.y" /* yacc.c:1646  */
    {// add AVG(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 4);
			selects_append_attribute(st, &attr);
	}
#line 2319 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 690 "yacc_sql.y" /* yacc.c:1646  */
    {	
		}
#line 2326 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 692 "yacc_sql.y" /* yacc.c:1646  */
    {//TODO: add inner join
}
#line 2333 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 696 "yacc_sql.y" /* yacc.c:1646  */
    {
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);	
		selects_append_relation(st, (yyvsp[-1].string));
	}
#line 2342 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 702 "yacc_sql.y" /* yacc.c:1646  */
    {//TODO: add inner join
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		selects_append_relation(st, (yyvsp[-2].string));
	}
#line 2351 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 709 "yacc_sql.y" /* yacc.c:1646  */
    {//TODO: add inner join

	}
#line 2359 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 715 "yacc_sql.y" /* yacc.c:1646  */
    {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2367 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 721 "yacc_sql.y" /* yacc.c:1646  */
    {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2375 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 727 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string), 0);

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;

			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			selects_append_condition(st,&condition);

			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// CONTEXT->conditions[CONTEXT->condition_length++] = condition;
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
#line 2408 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 756 "yacc_sql.y" /* yacc.c:1646  */
    {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			// condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 0, NULL, left_value, 0, NULL, right_value);
			selects_append_condition(st,&condition);

			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
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
#line 2439 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 783 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string), 0);
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string), 0);

			Condition condition;
			// condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			selects_append_condition(st,&condition);

			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
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
#line 2470 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 810 "yacc_sql.y" /* yacc.c:1646  */
    {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string), 0);

			Condition condition;
			// condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			selects_append_condition(st,&condition);
			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
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
#line 2501 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 837 "yacc_sql.y" /* yacc.c:1646  */
    {
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];
            Value left_value;
			value_init_nullvalue(&left_value);
			Condition condition;
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			// condition_init(&condition, CONTEXT->comp, 0, NULL, &left_value, 0, NULL, right_value);
			condition_init(&condition, st->comp, 0, NULL, &left_value, 0, NULL, right_value);
			selects_append_condition(st,&condition);
			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp ,0, NULL, &left_value, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		}
#line 2521 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 853 "yacc_sql.y" /* yacc.c:1646  */
    {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
            Value right_value;
			value_init_nullvalue(&right_value);
			Condition condition;
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 0, NULL, left_value, 0, NULL, &right_value);
			// condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, &right_value);
			selects_append_condition(st,&condition);
			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 0, NULL, left_value, 0, NULL, &right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		}
#line 2541 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 869 "yacc_sql.y" /* yacc.c:1646  */
    {
			Condition condition;
			Value right_value;
			value_init_nullvalue(&right_value);
			Value left_value;
            value_init_nullvalue(&left_value);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 0, NULL, &left_value, 0, NULL, &right_value);
			selects_append_condition(st,&condition);
			// condition_init(&condition, CONTEXT->comp, 0, NULL, &left_value, 0, NULL, &right_value);
			// CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 0, NULL, &left_value, 0, NULL, &right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		}
#line 2562 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 886 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string), 0);
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];
			Condition condition;
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			selects_append_condition(st,&condition);

			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
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
#line 2591 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 911 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string), 0);
            Value right_value;
			value_init_nullvalue(&right_value);
			Condition condition;
			// condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, &right_value);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 1, &left_attr, NULL, 0, NULL, &right_value);
			selects_append_condition(st,&condition);
			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, &right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2611 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 927 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string), 0);
			Value left_value;
			value_init_nullvalue(&left_value);
			Condition condition;
			// condition_init(&condition, CONTEXT->comp, 0, NULL, &left_value, 1, &right_attr, NULL);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 0, NULL, &left_value, 1, &right_attr, NULL);
			selects_append_condition(st,&condition);
			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 0, NULL, &left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		}
#line 2631 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 943 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string), 0);
            Value right_value;
			value_init_nullvalue(&right_value);
			Condition condition;
			// condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, &right_value);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 1, &left_attr, NULL, 0, NULL, &right_value);
			selects_append_condition(st,&condition);
			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, &right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2651 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 960 "yacc_sql.y" /* yacc.c:1646  */
    {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string), 0);

			Condition condition;
			// condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			selects_append_condition(st,&condition);
			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
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
#line 2682 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 987 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string), 0);
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string), 0);

			Condition condition;
			// condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			selects_append_condition(st,&condition);
			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
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
#line 2711 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1011 "yacc_sql.y" /* yacc.c:1646  */
    {
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string), 0);
		RelAttr right_attr;
		relation_attr_init_query(&right_attr,0,st->sub_num-1);
		Condition condition;
		condition_init(&condition, st->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		selects_append_condition(st,&condition);
	}
#line 2726 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1021 "yacc_sql.y" /* yacc.c:1646  */
    {
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string), 0);
		RelAttr right_attr;
		relation_attr_init_query(&right_attr,0,st->sub_num-1);
		Condition condition;
		condition_init(&condition, st->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		selects_append_condition(st,&condition);
	}
#line 2741 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1031 "yacc_sql.y" /* yacc.c:1646  */
    {
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		RelAttr right_attr;
		relation_attr_init(&right_attr, NULL, (yyvsp[0].string), 0);
		RelAttr left_attr;
		relation_attr_init_query(&left_attr,0,st->sub_num-1);
		Condition condition;
		condition_init(&condition, st->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		selects_append_condition(st,&condition);
	}
#line 2756 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1041 "yacc_sql.y" /* yacc.c:1646  */
    {
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		RelAttr right_attr;
		relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string), 0);
		RelAttr left_attr;
		relation_attr_init_query(&left_attr,0,st->sub_num-1);
		Condition condition;
		condition_init(&condition, st->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		selects_append_condition(st,&condition);
	}
#line 2771 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1054 "yacc_sql.y" /* yacc.c:1646  */
    { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		CONTEXT->comp = EQUAL_TO; 
		st->comp=EQUAL_TO;
			}
#line 2781 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1059 "yacc_sql.y" /* yacc.c:1646  */
    { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=LESS_THAN;
		CONTEXT->comp = LESS_THAN; 
		}
#line 2791 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1064 "yacc_sql.y" /* yacc.c:1646  */
    { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=GREAT_THAN;
		CONTEXT->comp = GREAT_THAN; 
		}
#line 2801 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1069 "yacc_sql.y" /* yacc.c:1646  */
    { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=LESS_EQUAL;
		CONTEXT->comp = LESS_EQUAL; 
		}
#line 2811 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1074 "yacc_sql.y" /* yacc.c:1646  */
    { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=GREAT_EQUAL;
		CONTEXT->comp = GREAT_EQUAL; 
		}
#line 2821 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1079 "yacc_sql.y" /* yacc.c:1646  */
    { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=NOT_EQUAL;
		CONTEXT->comp = NOT_EQUAL; 
		}
#line 2831 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1084 "yacc_sql.y" /* yacc.c:1646  */
    {

		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=NOT_IN;
		CONTEXT->comp = NOT_IN; 
		}
#line 2842 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1090 "yacc_sql.y" /* yacc.c:1646  */
    {
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=IN;
		CONTEXT->comp = IN;
		}
#line 2852 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1095 "yacc_sql.y" /* yacc.c:1646  */
    {
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=IS_;
		CONTEXT->comp = IS_;
		}
#line 2862 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1100 "yacc_sql.y" /* yacc.c:1646  */
    {

		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=IS_NOT;
		CONTEXT->comp = IS_NOT;
		}
#line 2873 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1110 "yacc_sql.y" /* yacc.c:1646  */
    {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2882 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;


#line 2886 "yacc_sql.tab.c" /* yacc.c:1646  */
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
#line 1115 "yacc_sql.y" /* yacc.c:1906  */

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
