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
    GROUP = 306,
    BY = 307,
    ASC = 308,
    INNER = 309,
    JOIN = 310,
    NOT = 311,
    IN_T = 312,
    ISNULL = 313,
    IS = 314,
    NULLABLE = 315,
    TEXT = 316,
    NUMBER = 317,
    FLOAT = 318,
    ID = 319,
    PATH = 320,
    SSS = 321,
    STAR = 322,
    STRING_V = 323
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 126 "yacc_sql.y" /* yacc.c:355  */

  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  char *string;
  int number;
  float floats;
	char *position;

#line 245 "yacc_sql.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void *scanner);

#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 261 "yacc_sql.tab.c" /* yacc.c:358  */

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
#define YYLAST   347

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  150
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  355

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   323

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
      65,    66,    67,    68
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   152,   152,   154,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   178,   183,   188,   194,   200,   206,   212,   218,   224,
     231,   236,   244,   250,   252,   262,   269,   278,   280,   284,
     295,   307,   318,   331,   334,   335,   336,   338,   339,   342,
     351,   367,   369,   374,   376,   382,   385,   388,   392,   398,
     408,   418,   435,   437,   442,   447,   454,   456,   461,   469,
     484,   491,   493,   498,   503,   508,   513,   518,   523,   529,
     531,   536,   541,   546,   551,   556,   564,   570,   576,   582,
     590,   597,   604,   611,   618,   625,   632,   639,   646,   655,
     657,   665,   673,   680,   687,   694,   701,   708,   715,   722,
     729,   737,   739,   741,   745,   751,   756,   758,   762,   764,
     768,   770,   775,   804,   831,   858,   885,   900,   916,   933,
     958,   974,   990,  1007,  1034,  1059,  1069,  1079,  1089,  1099,
    1112,  1117,  1122,  1127,  1132,  1137,  1142,  1148,  1153,  1158,
    1167
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
  "LT", "GT", "LE", "GE", "NE", "ORDER", "GROUP", "BY", "ASC", "INNER",
  "JOIN", "NOT", "IN_T", "ISNULL", "IS", "NULLABLE", "TEXT", "NUMBER",
  "FLOAT", "ID", "PATH", "SSS", "STAR", "STRING_V", "$accept", "commands",
  "command", "exit", "help", "sync", "begin", "commit", "rollback",
  "drop_table", "show_tables", "desc_table", "create_index", "index_attr",
  "index_attr_list", "drop_index", "create_table", "attr_def_list",
  "attr_def", "number", "type", "ID_get", "insert", "value_list",
  "tuple_list", "value", "delete", "update", "select", "group",
  "group_attr", "group_list", "head_sub_select", "sub_select", "order",
  "order_attr", "order_list", "select_attr", "attr_list", "rel_list",
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
     315,   316,   317,   318,   319,   320,   321,   322,   323
};
# endif

#define YYPACT_NINF -256

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-256)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -256,   121,  -256,    59,   141,    13,   -42,    31,    52,    28,
      64,    56,   138,   139,   145,   151,   152,    92,  -256,  -256,
    -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,
    -256,  -256,  -256,  -256,  -256,  -256,    96,   109,   158,   115,
     142,   144,   165,   188,   189,    69,  -256,   177,   212,   213,
    -256,   153,   159,   186,  -256,  -256,  -256,  -256,  -256,   190,
     208,   191,   167,   230,   231,   171,   172,    39,   173,    17,
     101,  -256,   174,  -256,  -256,   205,   204,   178,   175,   179,
     180,   206,  -256,  -256,    10,    11,    14,   225,    18,   227,
     228,   229,   232,    85,   233,   233,    12,   234,    20,   247,
     207,   220,  -256,   235,   130,   236,   194,   233,   195,   233,
     196,   233,   197,   233,   233,   198,   199,   200,   117,   201,
     202,  -256,  -256,  -256,   203,   214,   204,  -256,  -256,   112,
     259,   154,  -256,  -256,   148,  -256,   154,    13,   154,   237,
    -256,   112,   264,   179,   250,  -256,  -256,  -256,  -256,  -256,
      -7,   209,   252,  -256,   254,  -256,   255,  -256,   256,  -256,
    -256,   257,    26,    41,    68,   258,    83,   233,    12,   216,
     238,  -256,   260,  -256,  -256,  -256,  -256,  -256,  -256,  -256,
     224,  -256,   239,   156,   219,    32,   163,   249,    -1,    20,
    -256,   204,   221,   235,   283,   226,   240,  -256,   265,   269,
     209,   233,   233,   233,   233,   233,   241,   233,   242,   233,
     243,   233,   233,   244,  -256,  -256,   253,   245,   246,   112,
     270,  -256,  -256,  -256,  -256,  -256,   154,  -256,  -256,  -256,
    -256,  -256,   261,  -256,   248,   262,  -256,   237,   296,   297,
    -256,  -256,  -256,   280,  -256,   251,  -256,   299,   282,  -256,
    -256,  -256,  -256,  -256,   288,  -256,   289,  -256,   290,  -256,
    -256,   292,    20,    12,   263,   266,   301,   260,   294,    65,
     267,    12,   268,  -256,  -256,  -256,  -256,   265,  -256,   311,
     233,   233,   233,   233,   237,  -256,   100,  -256,   271,  -256,
    -256,   300,   314,  -256,   287,  -256,  -256,  -256,   204,  -256,
    -256,  -256,  -256,  -256,  -256,  -256,  -256,   272,   273,  -256,
      19,  -256,   112,  -256,   274,   302,   102,   303,   304,   275,
     276,   304,  -256,   260,  -256,  -256,   277,  -256,  -256,  -256,
      22,    23,  -256,   307,   303,   304,   278,   304,  -256,   304,
     304,  -256,   294,  -256,  -256,    34,  -256,  -256,  -256,  -256,
     304,   304,  -256,  -256,  -256
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
       0,     0,     0,     0,     0,    99,    86,     0,     0,     0,
      23,     0,     0,     0,    24,    25,    26,    22,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,     0,    29,    28,     0,   118,     0,     0,     0,
       0,     0,    27,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,    99,    99,   111,     0,     0,     0,
       0,     0,    49,    37,     0,     0,     0,    99,     0,    99,
       0,    99,     0,    99,    99,     0,     0,     0,     0,     0,
       0,   100,    88,    89,     0,     0,   118,   112,   113,     0,
       0,     0,    55,    56,     0,    57,     0,     0,     0,   120,
      59,     0,     0,     0,     0,    44,    45,    46,    47,    48,
      40,     0,     0,    93,     0,    95,     0,    91,     0,    90,
      97,     0,     0,     0,     0,     0,     0,    99,   111,     0,
      62,    58,    51,    69,   140,   141,   142,   143,   144,   145,
       0,   147,   148,     0,     0,     0,     0,     0,     0,     0,
     119,   118,     0,    37,     0,     0,     0,    42,    33,     0,
       0,    99,    99,    99,    99,    99,     0,    99,     0,    99,
       0,    99,    99,     0,   101,   114,   116,     0,    71,     0,
       0,   146,   149,    58,   131,   126,     0,    58,   124,   122,
     135,    58,   125,   123,     0,   137,   139,   120,     0,     0,
      38,    36,    43,     0,    41,     0,    32,     0,     0,    94,
      96,    92,    98,   105,     0,   107,     0,   103,     0,   102,
     109,     0,     0,   111,     0,     0,     0,    51,    53,     0,
       0,   111,     0,   121,    60,   150,    39,    33,    30,     0,
      99,    99,    99,    99,   120,   115,    66,    63,     0,    61,
      52,     0,     0,    58,     0,   129,   136,   133,   118,   138,
      34,    31,   106,   108,   104,   110,   117,     0,     0,    64,
      79,    72,     0,    50,     0,     0,    66,    66,    79,     0,
       0,    79,    73,    51,   134,    70,     0,    67,    65,    77,
      79,    79,    75,     0,    66,    79,     0,    79,    80,    79,
      79,    74,    53,    68,    84,    79,    82,    78,    76,    54,
      79,    79,    81,    85,    83
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,
    -256,  -256,  -256,   122,    44,  -256,  -256,   131,   187,  -256,
    -256,  -256,  -256,  -255,   -13,  -126,  -256,  -256,  -256,  -256,
    -256,  -246,  -256,  -177,  -256,  -256,  -168,   210,   -93,  -158,
    -256,  -256,  -256,  -122,  -220,  -183,  -129,  -256
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   199,   246,    29,    30,   144,   103,   243,
     150,   104,    31,   220,   292,   136,    32,    33,    34,   218,
     287,   309,   137,   138,   266,   311,   322,    47,    71,   126,
     127,   128,   263,    99,   190,   139,   183,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     121,   122,   123,   172,   170,   185,   237,   186,   230,   188,
     215,   236,   290,   195,   153,   191,   155,   273,   157,   130,
     159,   160,    48,    41,    42,    43,    44,    89,    90,    91,
      92,   107,   109,   318,   124,   111,   335,   339,    49,   114,
     130,   319,   108,   110,   319,   319,   112,   205,   350,   196,
     115,   320,   130,   197,   336,    50,   319,   225,   206,   229,
     233,    51,   207,   235,   306,    36,   125,    37,   333,   238,
     327,   328,   321,   208,   214,   337,   340,    45,   131,   284,
      46,    93,   132,   133,   134,   130,   135,   351,   343,   209,
     227,    69,   296,   267,   132,   133,   228,   269,   135,    52,
     210,    70,    38,    86,   212,   285,    87,    69,   249,   250,
     251,   252,   253,   298,   255,   213,   257,   120,   259,   260,
      53,     2,   307,   293,   307,     3,     4,   132,   133,   294,
       5,   135,   308,    59,   326,     6,     7,     8,     9,    10,
      11,    54,    55,   295,    12,    13,    14,    39,    56,    40,
     329,    15,    16,   332,    57,    58,   145,   146,   147,   148,
      60,    17,   338,   341,    65,    94,    62,   344,    95,   346,
     171,   347,   348,    61,   132,   133,   315,   352,   135,    63,
     184,   164,   353,   354,   165,    66,   323,   302,   303,   304,
     305,   149,   174,   175,   176,   177,   178,   179,   174,   175,
     176,   177,   178,   179,   180,   181,    64,   182,    67,    68,
     180,   181,    72,   182,   223,    73,    74,    75,   132,   133,
     224,   231,   135,    76,    77,   132,   133,   232,    79,   135,
      80,    81,    78,    82,    83,    84,    85,    88,    96,    97,
      98,   101,   100,   102,   105,   106,   113,   116,   117,   118,
     140,   141,   119,   142,   129,    69,   151,   143,   152,   154,
     156,   158,   161,   162,   163,   166,   167,   168,   173,   169,
     192,   194,   200,   198,   189,   201,   202,   203,   204,   211,
     216,   221,   219,   226,   234,   239,   241,   245,   242,   217,
     247,   268,   262,   270,   272,   222,   265,   264,   244,   274,
     275,   276,   278,   279,   289,   254,   256,   258,   261,   280,
     281,   282,   271,   283,   301,   277,   291,   313,   288,   314,
     312,   300,   248,   325,   240,   307,   319,   286,   342,   349,
     193,   297,   299,     0,     0,   310,   316,   317,   324,   330,
     331,   334,   345,     0,     0,     0,     0,   187
};

static const yytype_int16 yycheck[] =
{
      93,    94,    95,   129,   126,   134,   189,   136,   185,   138,
     168,   188,   267,    20,   107,   141,   109,   237,   111,    20,
     113,   114,    64,    10,    11,    12,    13,    10,    11,    12,
      13,    21,    21,    14,    22,    21,    14,    14,     7,    21,
      20,    22,    32,    32,    22,    22,    32,    21,    14,    56,
      32,    32,    20,    60,    32,     3,    22,   183,    32,   185,
     186,    33,    21,    64,   284,     6,    54,     8,   323,   191,
     316,   317,    53,    32,   167,    53,    53,    64,    58,   262,
      67,    64,    62,    63,    64,    20,    66,    53,   334,    21,
      58,    22,   269,   219,    62,    63,    64,   226,    66,    35,
      32,    32,    43,    64,    21,   263,    67,    22,   201,   202,
     203,   204,   205,   271,   207,    32,   209,    32,   211,   212,
      64,     0,    22,    58,    22,     4,     5,    62,    63,    64,
       9,    66,    32,    41,    32,    14,    15,    16,    17,    18,
      19,     3,     3,   269,    23,    24,    25,     6,     3,     8,
     318,    30,    31,   321,     3,     3,    26,    27,    28,    29,
      64,    40,   330,   331,    20,    64,     8,   335,    67,   337,
      58,   339,   340,    64,    62,    63,   298,   345,    66,    64,
      32,    64,   350,   351,    67,    20,   312,   280,   281,   282,
     283,    61,    44,    45,    46,    47,    48,    49,    44,    45,
      46,    47,    48,    49,    56,    57,    64,    59,    20,    20,
      56,    57,    35,    59,    58,     3,     3,    64,    62,    63,
      64,    58,    66,    64,    38,    62,    63,    64,    20,    66,
      39,    64,    42,     3,     3,    64,    64,    64,    64,    34,
      36,    66,    64,    64,    64,    39,    21,    20,    20,    20,
       3,    44,    20,    33,    20,    22,    20,    22,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,     9,    55,
       6,    21,    20,    64,    37,    21,    21,    21,    21,    21,
      64,    57,    22,    64,    35,    64,     3,    22,    62,    51,
      21,    21,    39,    32,    32,    56,    50,    52,    58,     3,
       3,    21,     3,    21,     3,    64,    64,    64,    64,    21,
      21,    21,    64,    21,     3,    64,    22,     3,    52,    32,
      20,   277,   200,    21,   193,    22,    22,    64,    21,   342,
     143,    64,    64,    -1,    -1,    64,    64,    64,    64,    64,
      64,    64,    64,    -1,    -1,    -1,    -1,   137
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    70,     0,     4,     5,     9,    14,    15,    16,    17,
      18,    19,    23,    24,    25,    30,    31,    40,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    84,
      85,    91,    95,    96,    97,   116,     6,     8,    43,     6,
       8,    10,    11,    12,    13,    64,    67,   106,    64,     7,
       3,    33,    35,    64,     3,     3,     3,     3,     3,    41,
      64,    64,     8,    64,    64,    20,    20,    20,    20,    22,
      32,   107,    35,     3,     3,    64,    64,    38,    42,    20,
      39,    64,     3,     3,    64,    64,    64,    67,    64,    10,
      11,    12,    13,    64,    64,    67,    64,    34,    36,   112,
      64,    66,    64,    87,    90,    64,    39,    21,    32,    21,
      32,    21,    32,    21,    21,    32,    20,    20,    20,    20,
      32,   107,   107,   107,    22,    54,   108,   109,   110,    20,
      20,    58,    62,    63,    64,    66,    94,   101,   102,   114,
       3,    44,    33,    22,    86,    26,    27,    28,    29,    61,
      89,    20,    64,   107,    64,   107,    64,   107,    64,   107,
     107,    64,    64,    64,    64,    67,    64,    64,    64,    55,
     112,    58,    94,     9,    44,    45,    46,    47,    48,    49,
      56,    57,    59,   115,    32,   115,   115,   106,   115,    37,
     113,    94,     6,    87,    21,    20,    56,    60,    64,    82,
      20,    21,    21,    21,    21,    21,    32,    21,    32,    21,
      32,    21,    21,    32,   107,   108,    64,    51,    98,    22,
      92,    57,    56,    58,    64,    94,    64,    58,    64,    94,
     102,    58,    64,    94,    35,    64,   102,   114,   112,    64,
      86,     3,    62,    88,    58,    22,    83,    21,    82,   107,
     107,   107,   107,   107,    64,   107,    64,   107,    64,   107,
     107,    64,    39,   111,    52,    50,   103,    94,    21,   115,
      32,    64,    32,   113,     3,     3,    21,    64,     3,    21,
      21,    21,    21,    21,   114,   108,    64,    99,    52,     3,
      92,    22,    93,    58,    64,    94,   102,    64,   108,    64,
      83,     3,   107,   107,   107,   107,   113,    22,    32,   100,
      64,   104,    20,     3,    32,   112,    64,    64,    14,    22,
      32,    53,   105,    94,    64,    21,    32,   100,   100,   105,
      64,    64,   105,    92,    64,    14,    32,    53,   105,    14,
      53,   105,    21,   100,   105,    64,   105,   105,   105,    93,
      14,    53,   105,   105,   105
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    70,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    81,    82,    83,    83,    84,    85,    86,    86,    87,
      87,    87,    87,    88,    89,    89,    89,    89,    89,    90,
      91,    92,    92,    93,    93,    94,    94,    94,    94,    95,
      96,    97,    98,    98,    99,    99,   100,   100,   100,   101,
     102,   103,   103,   104,   104,   104,   104,   104,   104,   105,
     105,   105,   105,   105,   105,   105,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   108,   108,   108,   109,   110,   111,   111,   112,   112,
     113,   113,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     116
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     4,     3,     3,
       9,    10,     2,     0,     3,     4,     8,     0,     3,     5,
       2,     4,     3,     1,     1,     1,     1,     1,     1,     1,
      10,     0,     3,     0,     6,     1,     1,     1,     1,     5,
       8,     9,     0,     3,     2,     4,     0,     3,     5,     2,
       7,     0,     3,     2,     4,     3,     5,     3,     5,     0,
       3,     5,     4,     6,     4,     6,     1,     2,     4,     4,
       5,     5,     7,     5,     7,     5,     7,     5,     7,     0,
       3,     5,     6,     6,     8,     6,     8,     6,     8,     6,
       8,     0,     1,     1,     3,     5,     0,     3,     0,     3,
       0,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       3,     3,     5,     5,     7,     3,     5,     3,     5,     3,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     2,
       8
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
#line 178 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1589 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 183 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1597 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 188 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1605 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 194 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1613 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 200 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1621 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 206 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1629 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 212 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1638 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 218 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1646 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 224 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1655 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 232 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), 0);
		}
#line 1664 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 237 "yacc_sql.y" /* yacc.c:1646  */
    {
	        CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_unique_index";
	        create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), 1);
	    }
#line 1673 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 244 "yacc_sql.y" /* yacc.c:1646  */
    {
        IndexColumn iColumn;
        IndexColumn_attr_init(&iColumn,(yyvsp[-1].string));
        create_index_append_attribute(&CONTEXT->ssql->sstr.create_index,&iColumn);
    }
#line 1683 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 252 "yacc_sql.y" /* yacc.c:1646  */
    {
        IndexColumn iColumn;
        IndexColumn_attr_init(&iColumn,(yyvsp[-1].string));
        create_index_append_attribute(&CONTEXT->ssql->sstr.create_index,&iColumn);
    }
#line 1693 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 263 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1702 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 270 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1714 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 280 "yacc_sql.y" /* yacc.c:1646  */
    {    }
#line 1720 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 285 "yacc_sql.y" /* yacc.c:1646  */
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
#line 1735 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 296 "yacc_sql.y" /* yacc.c:1646  */
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
#line 1750 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 308 "yacc_sql.y" /* yacc.c:1646  */
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
#line 1765 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 319 "yacc_sql.y" /* yacc.c:1646  */
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
#line 1780 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 331 "yacc_sql.y" /* yacc.c:1646  */
    {(yyval.number) = (yyvsp[0].number);}
#line 1786 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 334 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number)=INTS; }
#line 1792 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 335 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number)=CHARS; }
#line 1798 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 336 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number)=FLOATS; }
#line 1804 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 338 "yacc_sql.y" /* yacc.c:1646  */
    {(yyval.number)=DATES;}
#line 1810 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 339 "yacc_sql.y" /* yacc.c:1646  */
    {(yyval.number)=TEXTS;}
#line 1816 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 343 "yacc_sql.y" /* yacc.c:1646  */
    {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1825 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 352 "yacc_sql.y" /* yacc.c:1646  */
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
#line 1844 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 369 "yacc_sql.y" /* yacc.c:1646  */
    { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1852 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 376 "yacc_sql.y" /* yacc.c:1646  */
    {
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1860 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 382 "yacc_sql.y" /* yacc.c:1646  */
    {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1868 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 385 "yacc_sql.y" /* yacc.c:1646  */
    {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1876 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 388 "yacc_sql.y" /* yacc.c:1646  */
    {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1885 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 392 "yacc_sql.y" /* yacc.c:1646  */
    {
	    value_init_nullvalue(&CONTEXT->values[CONTEXT->value_length++]);
	    }
#line 1893 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 399 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1905 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 409 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			Value *value = &CONTEXT->values[0];
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-6].string), (yyvsp[-4].string), value, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1917 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 419 "yacc_sql.y" /* yacc.c:1646  */
    {
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string));
			
			// selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length); 

			CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;

	}
#line 1937 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 437 "yacc_sql.y" /* yacc.c:1646  */
    {
    //TODO: add group
    }
#line 1945 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 442 "yacc_sql.y" /* yacc.c:1646  */
    {
        GroupAttr attr;
        group_attr_init(&attr,NULL,(yyvsp[-1].string));
        selects_append_group(&CONTEXT->ssql->sstr.selection,&attr);
    }
#line 1955 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 447 "yacc_sql.y" /* yacc.c:1646  */
    {
        GroupAttr attr;
        group_attr_init(&attr,(yyvsp[-3].string),(yyvsp[-1].string));
        selects_append_group(&CONTEXT->ssql->sstr.selection,&attr);
    }
#line 1965 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 456 "yacc_sql.y" /* yacc.c:1646  */
    {
        GroupAttr attr;
        group_attr_init(&attr,NULL,(yyvsp[-1].string));
        selects_append_group(&CONTEXT->ssql->sstr.selection,&attr);
    }
#line 1975 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 461 "yacc_sql.y" /* yacc.c:1646  */
    {
        GroupAttr attr;
        group_attr_init(&attr,(yyvsp[-3].string),(yyvsp[-1].string));
        selects_append_group(&CONTEXT->ssql->sstr.selection,&attr);
    }
#line 1985 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 469 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2004 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 484 "yacc_sql.y" /* yacc.c:1646  */
    {
		//找到子查询, 并做一些收尾工作
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		selects_append_relation(st, (yyvsp[-3].string));
		//处理完一个子查询
		CONTEXT->now_select_dep--;//跳回上一级查询
	}
#line 2016 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 493 "yacc_sql.y" /* yacc.c:1646  */
    {
	//TODO: add order 
	}
#line 2024 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 498 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2034 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 503 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-3].string),(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2044 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 508 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2054 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 513 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2064 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 518 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2074 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 523 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2084 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 531 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2094 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 536 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-3].string),(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2104 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 541 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2114 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 546 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2124 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 551 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2134 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 556 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2144 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 564 "yacc_sql.y" /* yacc.c:1646  */
    {  
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*", 0);
			selects_append_attribute(st, &attr);
		}
#line 2155 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 570 "yacc_sql.y" /* yacc.c:1646  */
    {
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string), 0);
			selects_append_attribute(st, &attr);
		}
#line 2166 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 576 "yacc_sql.y" /* yacc.c:1646  */
    {
		  	Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), 0);
			selects_append_attribute(st, &attr);
		}
#line 2177 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 582 "yacc_sql.y" /* yacc.c:1646  */
    {// add t1.*
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*", 0);
			selects_append_attribute(st, &attr);
	}
#line 2188 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 590 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(*)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*", 5);
			selects_append_attribute(st, &attr);
	}
#line 2199 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 597 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 1);
			selects_append_attribute(st, &attr);
	}
#line 2210 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 604 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 1);
			selects_append_attribute(st, &attr);
	}
#line 2221 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 611 "yacc_sql.y" /* yacc.c:1646  */
    {// add MAX(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 2);
			selects_append_attribute(st, &attr);
	}
#line 2232 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 618 "yacc_sql.y" /* yacc.c:1646  */
    {// add MAX(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 2);
			selects_append_attribute(st, &attr);
	}
#line 2243 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 625 "yacc_sql.y" /* yacc.c:1646  */
    {// add MIN(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 3);
			selects_append_attribute(st, &attr);
	}
#line 2254 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 632 "yacc_sql.y" /* yacc.c:1646  */
    {// add MIN(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 3);
			selects_append_attribute(st, &attr);
	}
#line 2265 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 639 "yacc_sql.y" /* yacc.c:1646  */
    {// add AVG(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 4);
			selects_append_attribute(st, &attr);
	}
#line 2276 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 646 "yacc_sql.y" /* yacc.c:1646  */
    {// add AVG(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 4);
			selects_append_attribute(st, &attr);
	}
#line 2287 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 657 "yacc_sql.y" /* yacc.c:1646  */
    {
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string), 0);
			selects_append_attribute(st, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 2300 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 665 "yacc_sql.y" /* yacc.c:1646  */
    {
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), 0);
			selects_append_attribute(st, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2313 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 673 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(*)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, NULL, "*", 5);
            selects_append_attribute(st, &attr);
    }
#line 2324 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 680 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, NULL, (yyvsp[-2].string), 1);
            selects_append_attribute(st, &attr);
    }
#line 2335 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 687 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(t.id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 1);
            selects_append_attribute(st, &attr);
    }
#line 2346 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 694 "yacc_sql.y" /* yacc.c:1646  */
    {// add MAX(id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, NULL, (yyvsp[-2].string), 2);
            selects_append_attribute(st, &attr);
    }
#line 2357 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 701 "yacc_sql.y" /* yacc.c:1646  */
    {// add MAX(t.id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 2);
            selects_append_attribute(st, &attr);
    }
#line 2368 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 708 "yacc_sql.y" /* yacc.c:1646  */
    {// add MIN(id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, NULL, (yyvsp[-2].string), 3);
            selects_append_attribute(st, &attr);
    }
#line 2379 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 715 "yacc_sql.y" /* yacc.c:1646  */
    {// add MIN(t.id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 3);
            selects_append_attribute(st, &attr);
    }
#line 2390 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 722 "yacc_sql.y" /* yacc.c:1646  */
    {// add AVG(id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, NULL, (yyvsp[-2].string), 4);
            selects_append_attribute(st, &attr);
    }
#line 2401 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 729 "yacc_sql.y" /* yacc.c:1646  */
    {// add AVG(t.id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 4);
            selects_append_attribute(st, &attr);
    }
#line 2412 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 739 "yacc_sql.y" /* yacc.c:1646  */
    {	
		}
#line 2419 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 741 "yacc_sql.y" /* yacc.c:1646  */
    {//TODO: add inner join
}
#line 2426 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 745 "yacc_sql.y" /* yacc.c:1646  */
    {
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);	
		selects_append_relation(st, (yyvsp[-1].string));
	}
#line 2435 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 751 "yacc_sql.y" /* yacc.c:1646  */
    {//TODO: add inner join
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		selects_append_relation(st, (yyvsp[-2].string));
	}
#line 2444 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 758 "yacc_sql.y" /* yacc.c:1646  */
    {//TODO: add inner join

	}
#line 2452 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 764 "yacc_sql.y" /* yacc.c:1646  */
    {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2460 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 770 "yacc_sql.y" /* yacc.c:1646  */
    {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2468 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 776 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2501 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 805 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2532 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 832 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2563 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 859 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2594 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 886 "yacc_sql.y" /* yacc.c:1646  */
    {
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];
            Value left_value;
			value_init_nullvalue(&left_value);
			Condition condition;
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 0, NULL, &left_value, 0, NULL, right_value);
			selects_append_condition(st,&condition);
			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp ,0, NULL, &left_value, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		}
#line 2613 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 901 "yacc_sql.y" /* yacc.c:1646  */
    {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
            Value right_value;
			value_init_nullvalue(&right_value);
			Condition condition;
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 0, NULL, left_value, 0, NULL, &right_value);
			selects_append_condition(st,&condition);

			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 0, NULL, left_value, 0, NULL, &right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		}
#line 2633 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 917 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2654 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 934 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2683 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 959 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2703 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 975 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2723 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 991 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2743 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1008 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2774 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1035 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2803 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1059 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2818 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1069 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2833 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1079 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2848 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1089 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2863 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1099 "yacc_sql.y" /* yacc.c:1646  */
    {
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		RelAttr right_attr;
		relation_attr_init_query(&right_attr,0,st->sub_num-1);
		RelAttr left_attr;
		relation_attr_init_query(&left_attr,0,st->sub_num-2);
		Condition condition;
		condition_init(&condition, st->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		selects_append_condition(st,&condition);
	}
#line 2878 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1112 "yacc_sql.y" /* yacc.c:1646  */
    { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		CONTEXT->comp = EQUAL_TO; 
		st->comp=EQUAL_TO;
			}
#line 2888 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1117 "yacc_sql.y" /* yacc.c:1646  */
    { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=LESS_THAN;
		CONTEXT->comp = LESS_THAN; 
		}
#line 2898 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1122 "yacc_sql.y" /* yacc.c:1646  */
    { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=GREAT_THAN;
		CONTEXT->comp = GREAT_THAN; 
		}
#line 2908 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1127 "yacc_sql.y" /* yacc.c:1646  */
    { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=LESS_EQUAL;
		CONTEXT->comp = LESS_EQUAL; 
		}
#line 2918 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1132 "yacc_sql.y" /* yacc.c:1646  */
    { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=GREAT_EQUAL;
		CONTEXT->comp = GREAT_EQUAL; 
		}
#line 2928 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1137 "yacc_sql.y" /* yacc.c:1646  */
    { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=NOT_EQUAL;
		CONTEXT->comp = NOT_EQUAL; 
		}
#line 2938 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1142 "yacc_sql.y" /* yacc.c:1646  */
    {

		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=NOT_IN;
		CONTEXT->comp = NOT_IN; 
		}
#line 2949 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1148 "yacc_sql.y" /* yacc.c:1646  */
    {
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=IN;
		CONTEXT->comp = IN;
		}
#line 2959 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1153 "yacc_sql.y" /* yacc.c:1646  */
    {
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=IS_;
		CONTEXT->comp = IS_;
		}
#line 2969 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1158 "yacc_sql.y" /* yacc.c:1646  */
    {

		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=IS_NOT;
		CONTEXT->comp = IS_NOT;
		}
#line 2980 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1168 "yacc_sql.y" /* yacc.c:1646  */
    {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2989 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;


#line 2993 "yacc_sql.tab.c" /* yacc.c:1646  */
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
#line 1173 "yacc_sql.y" /* yacc.c:1906  */

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
