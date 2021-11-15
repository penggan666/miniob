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
<<<<<<< HEAD
    IN_T = 311,
    NUMBER = 312,
    FLOAT = 313,
    ID = 314,
    PATH = 315,
    SSS = 316,
    STAR = 317,
    STRING_V = 318
=======
    ISNULL = 311,
    IS = 312,
    NULLABLE = 313,
    NUMBER = 314,
    FLOAT = 315,
    ID = 316,
    PATH = 317,
    SSS = 318,
    STAR = 319,
    STRING_V = 320
>>>>>>> master
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
<<<<<<< HEAD
#line 121 "yacc_sql.y" /* yacc.c:355  */
=======
#line 120 "yacc_sql.y"
>>>>>>> master

  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  char *string;
  int number;
  float floats;
	char *position;

<<<<<<< HEAD
#line 240 "yacc_sql.tab.c" /* yacc.c:355  */
=======
#line 255 "yacc_sql.tab.c"

>>>>>>> master
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void *scanner);

#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 256 "yacc_sql.tab.c" /* yacc.c:358  */

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
<<<<<<< HEAD
#define YYLAST   309

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
=======
#define YYLAST   306

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
>>>>>>> master
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
<<<<<<< HEAD
#define YYNRULES  126
=======
#define YYNRULES  131
>>>>>>> master
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  315

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
<<<<<<< HEAD
#define YYMAXUTOK   318
=======
#define YYMAXUTOK   320
>>>>>>> master

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
<<<<<<< HEAD
      55,    56,    57,    58,    59,    60,    61,    62,    63
=======
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
>>>>>>> master
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
<<<<<<< HEAD
       0,   147,   147,   149,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   173,   178,   183,   189,   195,   201,   207,   213,   219,
     226,   231,   239,   246,   255,   257,   261,   272,   285,   288,
     289,   290,   292,   295,   304,   320,   322,   327,   329,   335,
     338,   341,   348,   358,   368,   386,   401,   408,   410,   415,
     420,   425,   430,   435,   440,   446,   448,   453,   458,   463,
     468,   473,   481,   487,   493,   500,   508,   515,   522,   529,
     536,   543,   550,   557,   564,   573,   575,   583,   593,   595,
     602,   609,   616,   623,   630,   637,   644,   651,   659,   661,
     663,   667,   673,   678,   680,   684,   686,   690,   692,   697,
     720,   741,   762,   785,   806,   828,   848,   858,   871,   872,
     873,   874,   875,   876,   877,   878,   882
=======
       0,   146,   146,   148,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   172,   177,   182,   188,   194,   200,   206,   212,   218,
     225,   230,   238,   245,   254,   256,   260,   271,   283,   294,
     307,   310,   311,   312,   314,   317,   326,   342,   344,   349,
     351,   357,   360,   363,   367,   373,   383,   393,   411,   413,
     418,   423,   428,   433,   438,   443,   449,   451,   456,   461,
     466,   471,   476,   484,   489,   494,   500,   507,   513,   519,
     525,   531,   537,   543,   549,   555,   563,   565,   572,   581,
     583,   589,   595,   601,   607,   613,   619,   625,   631,   638,
     640,   642,   646,   651,   655,   657,   661,   663,   667,   669,
     674,   695,   715,   735,   757,   766,   775,   785,   806,   816,
     826,   837,   858,   880,   881,   882,   883,   884,   885,   886,
     887,   891
>>>>>>> master
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
<<<<<<< HEAD
  "NOT", "IN_T", "NUMBER", "FLOAT", "ID", "PATH", "SSS", "STAR",
  "STRING_V", "$accept", "commands", "command", "exit", "help", "sync",
  "begin", "commit", "rollback", "drop_table", "show_tables", "desc_table",
  "create_index", "drop_index", "create_table", "attr_def_list",
  "attr_def", "number", "type", "ID_get", "insert", "value_list",
  "tuple_list", "value", "delete", "update", "select", "head_sub_select",
  "sub_select", "order", "order_attr", "order_list", "select_attr",
=======
  "NOT", "ISNULL", "IS", "NULLABLE", "NUMBER", "FLOAT", "ID", "PATH",
  "SSS", "STAR", "STRING_V", "$accept", "commands", "command", "exit",
  "help", "sync", "begin", "commit", "rollback", "drop_table",
  "show_tables", "desc_table", "create_index", "drop_index",
  "create_table", "attr_def_list", "attr_def", "number", "type", "ID_get",
  "insert", "value_list", "tuple_list", "value", "delete", "update",
  "select", "order", "order_attr", "order_list", "select_attr",
>>>>>>> master
  "attr_list", "agg_list", "rel_list", "table_factor", "join_table",
  "join_on", "where", "condition_list", "condition", "comOp", "load_data", YY_NULLPTR
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
<<<<<<< HEAD
     315,   316,   317,   318
};
# endif

#define YYPACT_NINF -213
=======
     315,   316,   317,   318,   319,   320
};
# endif

#define YYPACT_NINF (-252)
>>>>>>> master

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-213)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
<<<<<<< HEAD
    -213,   113,  -213,    48,   127,     5,   -33,    30,    41,    12,
      33,    24,   101,   107,   118,   131,   136,    99,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,    87,    89,   133,   104,
     112,   157,   158,   159,   166,     0,  -213,   154,   187,   188,
    -213,   134,   135,   160,  -213,  -213,  -213,  -213,  -213,   150,
     175,   161,   137,   194,   196,   142,   143,   -23,   144,   145,
     125,  -213,   146,  -213,  -213,   172,   171,   149,   148,   151,
     152,   173,  -213,  -213,    -2,     8,    21,   192,    25,     2,
     193,   193,    -1,   197,   103,   211,   174,   183,  -213,   198,
      97,   199,   162,   200,   164,   200,   165,   200,   167,   200,
     200,   168,   169,  -213,  -213,  -213,   170,   176,   171,  -213,
    -213,    58,  -213,  -213,   110,  -213,    50,   195,  -213,    58,
     219,   151,   210,  -213,  -213,  -213,  -213,   213,   177,   214,
     163,  -213,   216,  -213,   217,  -213,   218,  -213,  -213,   220,
     193,    -1,   181,   185,   221,   186,  -213,  -213,  -213,  -213,
    -213,  -213,   190,  -213,    23,   111,   103,  -213,   171,   189,
     198,   239,   201,   223,   191,   227,   229,   231,   232,   200,
     200,   200,   200,  -213,  -213,   215,   202,   252,    58,   235,
      50,  -213,   248,  -213,  -213,     5,  -213,   228,  -213,   195,
     256,   258,  -213,  -213,  -213,   241,   260,   243,   206,   207,
     126,   208,  -213,  -213,  -213,  -213,   103,    -1,   209,  -213,
     221,   247,    28,  -213,   236,   222,  -213,  -213,  -213,  -213,
    -213,   267,    34,    79,    80,   251,    82,   195,  -213,     6,
    -213,  -213,   253,   271,   244,  -213,  -213,   224,  -213,  -213,
     200,   225,   200,   226,   200,   230,   200,   200,   233,  -213,
     255,   234,   237,   255,  -213,    58,  -213,   238,    -1,  -213,
     254,  -213,   257,  -213,   259,  -213,  -213,   261,  -213,     9,
      11,  -213,   221,  -213,   171,   200,   200,   200,   200,   255,
     240,   255,  -213,   255,   255,  -213,   265,   266,  -213,  -213,
    -213,  -213,  -213,    13,  -213,  -213,  -213,   247,  -213,   255,
     255,  -213,  -213,  -213,  -213
=======
    -252,    85,  -252,    33,    42,     7,   -47,    23,    52,    29,
      21,    31,    90,    94,   103,   108,   124,    88,  -252,  -252,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,  -252,  -252,  -252,  -252,  -252,    67,    78,   132,    97,
      98,   126,   128,   145,   155,     6,  -252,   117,   168,   178,
    -252,   127,   137,   149,  -252,  -252,  -252,  -252,  -252,   162,
     185,   167,   146,   205,   206,   150,   152,    27,   153,   154,
      86,  -252,   156,  -252,  -252,   176,   180,   157,   158,   159,
     161,   173,  -252,  -252,    51,    54,    63,   198,    66,    14,
     201,   201,     1,   204,    82,   222,   182,   194,  -252,   207,
     151,   208,   169,   209,   171,   209,   172,   209,   174,   209,
     209,   175,   177,  -252,  -252,  -252,   179,   183,   180,  -252,
    -252,   136,    87,  -252,  -252,    73,  -252,    87,   197,  -252,
     136,   233,   159,   220,  -252,  -252,  -252,  -252,     2,   181,
     223,   190,  -252,   224,  -252,   225,  -252,   226,  -252,  -252,
     227,   201,     1,   188,   200,  -252,   229,  -252,  -252,  -252,
    -252,  -252,  -252,   189,   101,   191,   107,   113,    82,  -252,
     180,   192,   207,   251,   196,   202,  -252,   235,   199,   237,
     239,   241,   242,   209,   209,   209,   209,  -252,  -252,   228,
     212,   261,   136,   244,  -252,  -252,  -252,  -252,    87,  -252,
    -252,  -252,  -252,   234,  -252,   197,   265,   266,  -252,  -252,
    -252,   249,  -252,   268,   252,   211,   213,   133,   214,  -252,
    -252,  -252,  -252,    82,     1,   215,  -252,   229,   255,   130,
     217,  -252,  -252,  -252,  -252,  -252,   276,    75,    91,    92,
     259,   105,   197,  -252,    11,  -252,  -252,   262,   278,  -252,
     253,  -252,  -252,  -252,   209,   230,   209,   231,   209,   232,
     209,   209,   236,  -252,   264,   238,   240,   264,  -252,   136,
    -252,   243,  -252,   263,  -252,   267,  -252,   269,  -252,  -252,
     273,  -252,    15,    12,  -252,   229,  -252,   209,   209,   209,
     209,   264,   245,   264,  -252,   264,   264,  -252,   274,  -252,
    -252,  -252,  -252,  -252,    13,  -252,  -252,  -252,   255,   264,
     264,  -252,  -252,  -252,  -252
>>>>>>> master
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
<<<<<<< HEAD
       0,     0,     0,     0,     0,    85,    72,     0,     0,     0,
      23,     0,     0,     0,    24,    25,    26,    22,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,     0,    29,    28,     0,   105,     0,     0,     0,
       0,     0,    27,    32,     0,     0,     0,     0,     0,    85,
      85,    85,    98,     0,     0,     0,     0,     0,    43,    34,
       0,     0,     0,    88,     0,    88,     0,    88,     0,    88,
      88,     0,     0,    86,    74,    75,     0,     0,   105,    99,
     100,     0,    49,    50,     0,    51,     0,   107,    52,     0,
       0,     0,     0,    39,    40,    41,    42,    37,     0,     0,
       0,    79,     0,    81,     0,    77,     0,    76,    83,     0,
      85,    98,     0,    57,    45,     0,   118,   119,   120,   121,
     122,   123,     0,   125,     0,     0,     0,   106,   105,     0,
      34,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      88,    88,    88,    87,   101,   103,     0,     0,     0,     0,
       0,   124,     0,   111,   109,     0,   116,   112,   110,   107,
       0,     0,    35,    33,    38,     0,     0,     0,     0,     0,
       0,     0,    80,    82,    78,    84,     0,    98,     0,    54,
      45,    47,     0,    55,     0,     0,   108,    53,   126,    36,
      30,     0,     0,     0,     0,     0,     0,   107,   102,    65,
      58,    46,     0,     0,     0,   113,   117,     0,   114,    31,
      88,     0,    88,     0,    88,     0,    88,    88,     0,   104,
      65,     0,     0,    65,    59,     0,    44,     0,    98,    92,
       0,    94,     0,    90,     0,    89,    96,     0,    63,    65,
      65,    61,    45,   115,   105,    88,    88,    88,    88,    65,
       0,    65,    66,    65,    65,    60,     0,     0,    93,    95,
      91,    97,    70,    65,    68,    64,    62,    47,    56,    65,
      65,    67,    48,    71,    69
=======
       0,     0,     0,     0,     0,    86,    73,     0,     0,     0,
      23,     0,     0,     0,    24,    25,    26,    22,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,     0,    29,    28,     0,   106,     0,     0,     0,
       0,     0,    27,    32,     0,     0,     0,     0,     0,    86,
      86,    86,    99,     0,     0,     0,     0,     0,    45,    34,
       0,     0,     0,    89,     0,    89,     0,    89,     0,    89,
      89,     0,     0,    87,    75,    76,     0,     0,   106,   100,
     101,     0,     0,    51,    52,     0,    53,     0,   108,    55,
       0,     0,     0,     0,    41,    42,    43,    44,    37,     0,
       0,     0,    80,     0,    82,     0,    78,     0,    77,    84,
       0,    86,    99,     0,    58,    54,    47,   123,   124,   125,
     126,   127,   128,   129,     0,     0,     0,     0,     0,   107,
     106,     0,    34,     0,     0,     0,    39,     0,     0,     0,
       0,     0,     0,    89,    89,    89,    89,    88,   102,   104,
       0,     0,     0,     0,   130,    54,   119,   114,     0,    54,
     112,   110,    54,   113,   111,   108,     0,     0,    35,    33,
      40,     0,    38,     0,     0,     0,     0,     0,     0,    81,
      83,    79,    85,     0,    99,     0,    57,    47,    49,     0,
       0,   109,    56,   131,    36,    30,     0,     0,     0,     0,
       0,     0,   108,   103,    66,    59,    48,     0,     0,    54,
       0,   117,   121,    31,    89,     0,    89,     0,    89,     0,
      89,    89,     0,   105,    66,     0,     0,    66,    60,     0,
      46,     0,    93,     0,    95,     0,    91,     0,    90,    97,
       0,    64,    66,    66,    62,    47,   122,    89,    89,    89,
      89,    66,     0,    66,    67,    66,    66,    61,     0,    94,
      96,    92,    98,    71,    66,    69,    65,    63,    49,    66,
      66,    68,    50,    72,    70
>>>>>>> master
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
<<<<<<< HEAD
    -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,   109,   178,  -213,  -213,  -213,
    -213,  -212,   -19,  -115,  -213,  -213,  -213,  -213,    68,  -213,
    -213,  -201,    96,   -78,  -105,  -148,  -213,  -213,  -213,  -117,
    -190,  -156,  -119,  -213
=======
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,  -252,  -252,  -252,  -252,   111,   164,  -252,  -252,  -252,
    -252,  -215,   -21,  -115,  -252,  -252,  -252,  -252,  -252,  -251,
    -252,   -82,  -105,  -142,  -252,  -252,  -252,   -97,  -181,  -157,
    -124,  -252
>>>>>>> master
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
<<<<<<< HEAD
      26,    27,    28,    29,    30,   132,    99,   205,   137,   100,
      31,   189,   243,   126,    32,    33,    34,   195,   196,   187,
     240,   264,    47,    71,   141,   118,   119,   120,   217,    95,
     167,   127,   164,    35
=======
      26,    27,    28,    29,    30,   133,    99,   211,   138,   100,
      31,   193,   248,   127,    32,    33,    34,   191,   245,   268,
      47,    71,   142,   118,   119,   120,   224,    95,   169,   128,
     164,    35
>>>>>>> master
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
<<<<<<< HEAD
     143,   153,   145,   184,   147,   148,   154,   165,   241,   226,
     199,   113,   114,   115,   168,    41,    42,    43,    44,   103,
     260,   116,    69,   289,    69,   293,    48,   309,   261,   105,
     104,   261,    70,   261,   112,   261,    86,    49,   262,    87,
     106,   290,   107,   192,    50,    51,   110,   259,   192,   194,
     198,   200,   117,   108,    36,   250,    37,   111,   263,   278,
     237,   291,   281,   294,    45,   310,   251,    46,    52,   238,
     296,   222,   183,   220,   212,   213,   214,   215,   292,   295,
     122,   123,   193,    53,   125,   122,   123,   244,   302,   125,
     304,    38,   305,   306,   156,   157,   158,   159,   160,   161,
     252,   254,   311,   257,    54,   162,   163,   245,   313,   314,
      55,   253,   255,     2,   258,   122,   123,     3,     4,   125,
     284,    56,     5,   133,   134,   135,   136,     6,     7,     8,
       9,    10,    11,    39,    57,    40,    12,    13,    14,    58,
      59,    62,   155,    15,    16,   269,    60,   271,    61,   273,
     282,   275,   276,    17,   156,   157,   158,   159,   160,   161,
     122,   123,   124,    63,   125,   162,   163,   297,   122,   123,
     197,    64,   125,   175,   176,   177,   178,    65,    66,    67,
     298,   299,   300,   301,    90,   234,    68,    91,   235,    72,
      73,    74,    78,    75,    76,    79,    81,    82,    77,    83,
      80,    84,    85,    88,    89,    92,    93,    94,    96,    97,
      98,   101,   102,   109,   128,    69,   130,   121,   129,   138,
     131,   139,   140,   142,   144,   169,   146,   149,   150,   151,
     152,   171,   166,   172,   174,   186,   173,   179,   180,   181,
     185,   182,   203,   188,   206,   190,   191,   208,   201,   209,
     207,   210,   211,   218,   216,   219,   221,   223,   204,   227,
     225,   228,   229,   230,   231,   232,   233,   236,   239,   242,
     249,   247,   256,   265,   266,   285,   267,   261,   286,   202,
     287,   248,   288,   268,   270,   272,   307,   308,   312,   274,
     246,   224,   277,   279,     0,     0,   280,   283,     0,   303,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   170
=======
     144,   166,   146,   167,   148,   149,   156,   113,   114,   115,
     188,   205,   246,   281,    48,   170,   284,    41,    42,    43,
      44,   154,   174,   116,   231,   264,   295,   309,    69,   291,
      49,   294,   297,   265,   265,   265,    69,   265,    70,    36,
     303,    37,   305,   266,   306,   307,   112,   292,    39,   197,
      40,   201,   204,   311,   117,    50,    52,   175,   313,   314,
     176,   263,    51,   267,   296,   310,   242,   293,    45,   187,
     298,    46,   103,   206,   229,   105,    38,   227,   219,   220,
     221,   222,   243,   104,   107,     2,   106,   110,    86,     3,
       4,    87,    53,    54,     5,   108,   254,    55,   111,     6,
       7,     8,     9,    10,    11,   165,    56,   255,    12,    13,
      14,    57,   256,   258,   251,    15,    16,   157,   158,   159,
     160,   161,   162,   257,   259,    17,   261,    58,    60,    59,
     163,   157,   158,   159,   160,   161,   162,   262,   122,    61,
      62,   123,   124,   125,   163,   126,    65,    90,    66,   272,
      91,   274,    72,   276,   285,   278,   279,   195,    63,    64,
     123,   124,   196,   199,   126,    67,   123,   124,   200,   202,
     126,    73,   123,   124,   203,    68,   126,   134,   135,   136,
     137,    74,   299,   300,   301,   302,   249,    77,    75,   123,
     124,   250,   155,   126,   239,   123,   124,   240,    76,   126,
     179,   180,   181,   182,    78,    79,    80,    81,    82,    83,
      93,    84,   102,    85,    88,    89,    94,    92,    96,   109,
      98,    97,   101,    69,   121,   129,   130,   131,   139,   132,
     140,   141,   143,   145,   168,   147,   150,   153,   151,   171,
     152,   173,   177,   178,   194,   183,   184,   185,   186,   189,
     190,   192,   198,   207,   209,   210,   213,   215,   212,   216,
     214,   217,   218,   225,   226,   228,   230,   223,   232,   233,
     234,   235,   237,   236,   238,   241,   244,   247,   252,   253,
     260,   270,   269,   208,   287,   271,   265,   312,   288,     0,
     289,   273,   275,   277,   290,   308,   172,   280,     0,   282,
       0,   283,     0,     0,   286,     0,   304
>>>>>>> master
};

static const yytype_int16 yycheck[] =
{
<<<<<<< HEAD
     105,   118,   107,   151,   109,   110,   121,   126,   220,   199,
     166,    89,    90,    91,   129,    10,    11,    12,    13,    21,
      14,    22,    22,    14,    22,    14,    59,    14,    22,    21,
      32,    22,    32,    22,    32,    22,    59,     7,    32,    62,
      32,    32,    21,    20,     3,    33,    21,   237,    20,   164,
     165,   168,    53,    32,     6,    21,     8,    32,    52,   260,
     216,    52,   263,    52,    59,    52,    32,    62,    35,   217,
     282,   190,   150,   188,   179,   180,   181,   182,   279,   280,
      57,    58,    59,    59,    61,    57,    58,    59,   289,    61,
     291,    43,   293,   294,    44,    45,    46,    47,    48,    49,
      21,    21,   303,    21,     3,    55,    56,   222,   309,   310,
       3,    32,    32,     0,    32,    57,    58,     4,     5,    61,
     268,     3,     9,    26,    27,    28,    29,    14,    15,    16,
      17,    18,    19,     6,     3,     8,    23,    24,    25,     3,
      41,     8,    32,    30,    31,   250,    59,   252,    59,   254,
     265,   256,   257,    40,    44,    45,    46,    47,    48,    49,
      57,    58,    59,    59,    61,    55,    56,   284,    57,    58,
      59,    59,    61,    10,    11,    12,    13,    20,    20,    20,
     285,   286,   287,   288,    59,    59,    20,    62,    62,    35,
       3,     3,    42,    59,    59,    20,    59,     3,    38,     3,
      39,    59,    59,    59,    59,    59,    34,    36,    59,    61,
      59,    59,    39,    21,     3,    22,    33,    20,    44,    20,
      22,    59,    22,    59,    59,     6,    59,    59,    59,    59,
      54,    21,    37,    20,    20,    50,    59,    21,    21,    21,
      59,    21,     3,    22,    21,    59,    56,    20,    59,    20,
      59,    20,    20,    51,    39,     3,    21,     9,    57,     3,
      32,     3,    21,     3,    21,    59,    59,    59,    59,    22,
       3,    35,    21,    20,     3,    21,    32,    22,    21,   170,
      21,    59,    21,    59,    59,    59,    21,    21,   307,    59,
     222,   195,    59,    59,    -1,    -1,    59,    59,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131
=======
     105,   125,   107,   127,   109,   110,   121,    89,    90,    91,
     152,   168,   227,   264,    61,   130,   267,    10,    11,    12,
      13,   118,    20,    22,   205,    14,    14,    14,    22,    14,
       7,   282,   283,    22,    22,    22,    22,    22,    32,     6,
     291,     8,   293,    32,   295,   296,    32,    32,     6,   164,
       8,   166,   167,   304,    53,     3,    35,    55,   309,   310,
      58,   242,    33,    52,    52,    52,   223,    52,    61,   151,
     285,    64,    21,   170,   198,    21,    43,   192,   183,   184,
     185,   186,   224,    32,    21,     0,    32,    21,    61,     4,
       5,    64,    61,     3,     9,    32,    21,     3,    32,    14,
      15,    16,    17,    18,    19,    32,     3,    32,    23,    24,
      25,     3,    21,    21,   229,    30,    31,    44,    45,    46,
      47,    48,    49,    32,    32,    40,    21,     3,    61,    41,
      57,    44,    45,    46,    47,    48,    49,    32,    56,    61,
       8,    59,    60,    61,    57,    63,    20,    61,    20,   254,
      64,   256,    35,   258,   269,   260,   261,    56,    61,    61,
      59,    60,    61,    56,    63,    20,    59,    60,    61,    56,
      63,     3,    59,    60,    61,    20,    63,    26,    27,    28,
      29,     3,   287,   288,   289,   290,    56,    38,    61,    59,
      60,    61,    56,    63,    61,    59,    60,    64,    61,    63,
      10,    11,    12,    13,    42,    20,    39,    61,     3,     3,
      34,    61,    39,    61,    61,    61,    36,    61,    61,    21,
      61,    63,    61,    22,    20,     3,    44,    33,    20,    22,
      61,    22,    61,    61,    37,    61,    61,    54,    61,     6,
      61,    21,    61,    20,    55,    21,    21,    21,    21,    61,
      50,    22,    61,    61,     3,    59,    21,    20,    56,    20,
      61,    20,    20,    51,     3,    21,    32,    39,     3,     3,
      21,     3,    61,    21,    61,    61,    61,    22,    61,     3,
      21,     3,    20,   172,    21,    32,    22,   308,    21,    -1,
      21,    61,    61,    61,    21,    21,   132,    61,    -1,    61,
      -1,    61,    -1,    -1,    61,    -1,    61
>>>>>>> master
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
<<<<<<< HEAD
       0,    65,     0,     4,     5,     9,    14,    15,    16,    17,
      18,    19,    23,    24,    25,    30,    31,    40,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    84,    88,    89,    90,   107,     6,     8,    43,     6,
       8,    10,    11,    12,    13,    59,    62,    96,    59,     7,
       3,    33,    35,    59,     3,     3,     3,     3,     3,    41,
      59,    59,     8,    59,    59,    20,    20,    20,    20,    22,
      32,    97,    35,     3,     3,    59,    59,    38,    42,    20,
      39,    59,     3,     3,    59,    59,    59,    62,    59,    59,
      59,    62,    59,    34,    36,   103,    59,    61,    59,    80,
      83,    59,    39,    21,    32,    21,    32,    21,    32,    21,
      21,    32,    32,    97,    97,    97,    22,    53,    99,   100,
     101,    20,    57,    58,    59,    61,    87,   105,     3,    44,
      33,    22,    79,    26,    27,    28,    29,    82,    20,    59,
      22,    98,    59,    98,    59,    98,    59,    98,    98,    59,
      59,    59,    54,   103,    87,    32,    44,    45,    46,    47,
      48,    49,    55,    56,   106,   106,    37,   104,    87,     6,
      80,    21,    20,    59,    20,    10,    11,    12,    13,    21,
      21,    21,    21,    97,    99,    59,    50,    93,    22,    85,
      59,    56,    20,    59,    87,    91,    92,    59,    87,   105,
     103,    59,    79,     3,    57,    81,    21,    59,    20,    20,
      20,    20,    98,    98,    98,    98,    39,   102,    51,     3,
      87,    21,   106,     9,    96,    32,   104,     3,     3,    21,
       3,    21,    59,    59,    59,    62,    59,   105,    99,    59,
      94,    85,    22,    86,    59,    87,    92,    35,    59,     3,
      21,    32,    21,    32,    21,    32,    21,    21,    32,   104,
      14,    22,    32,    52,    95,    20,     3,    32,    59,    98,
      59,    98,    59,    98,    59,    98,    98,    59,    95,    59,
      59,    95,    87,    59,    99,    21,    21,    21,    21,    14,
      32,    52,    95,    14,    52,    95,    85,   103,    98,    98,
      98,    98,    95,    59,    95,    95,    95,    21,    21,    14,
      52,    95,    86,    95,    95
=======
       0,    67,     0,     4,     5,     9,    14,    15,    16,    17,
      18,    19,    23,    24,    25,    30,    31,    40,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    86,    90,    91,    92,   107,     6,     8,    43,     6,
       8,    10,    11,    12,    13,    61,    64,    96,    61,     7,
       3,    33,    35,    61,     3,     3,     3,     3,     3,    41,
      61,    61,     8,    61,    61,    20,    20,    20,    20,    22,
      32,    97,    35,     3,     3,    61,    61,    38,    42,    20,
      39,    61,     3,     3,    61,    61,    61,    64,    61,    61,
      61,    64,    61,    34,    36,   103,    61,    63,    61,    82,
      85,    61,    39,    21,    32,    21,    32,    21,    32,    21,
      21,    32,    32,    97,    97,    97,    22,    53,    99,   100,
     101,    20,    56,    59,    60,    61,    63,    89,   105,     3,
      44,    33,    22,    81,    26,    27,    28,    29,    84,    20,
      61,    22,    98,    61,    98,    61,    98,    61,    98,    98,
      61,    61,    61,    54,   103,    56,    89,    44,    45,    46,
      47,    48,    49,    57,   106,    32,   106,   106,    37,   104,
      89,     6,    82,    21,    20,    55,    58,    61,    20,    10,
      11,    12,    13,    21,    21,    21,    21,    97,    99,    61,
      50,    93,    22,    87,    55,    56,    61,    89,    61,    56,
      61,    89,    56,    61,    89,   105,   103,    61,    81,     3,
      59,    83,    56,    21,    61,    20,    20,    20,    20,    98,
      98,    98,    98,    39,   102,    51,     3,    89,    21,   106,
      32,   104,     3,     3,    21,     3,    21,    61,    61,    61,
      64,    61,   105,    99,    61,    94,    87,    22,    88,    56,
      61,    89,    61,     3,    21,    32,    21,    32,    21,    32,
      21,    21,    32,   104,    14,    22,    32,    52,    95,    20,
       3,    32,    98,    61,    98,    61,    98,    61,    98,    98,
      61,    95,    61,    61,    95,    89,    61,    21,    21,    21,
      21,    14,    32,    52,    95,    14,    52,    95,    87,    98,
      98,    98,    98,    95,    61,    95,    95,    95,    21,    14,
      52,    95,    88,    95,    95
>>>>>>> master
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
<<<<<<< HEAD
       0,    64,    65,    65,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    76,    77,    78,    79,    79,    80,    80,    81,    82,
      82,    82,    82,    83,    84,    85,    85,    86,    86,    87,
      87,    87,    88,    89,    90,    91,    92,    93,    93,    94,
      94,    94,    94,    94,    94,    95,    95,    95,    95,    95,
      95,    95,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    97,    97,    97,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    99,    99,
      99,   100,   101,   102,   102,   103,   103,   104,   104,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   106,   106,
     106,   106,   106,   106,   106,   106,   107
=======
       0,    66,    67,    67,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    78,    79,    80,    81,    81,    82,    82,    82,    82,
      83,    84,    84,    84,    84,    85,    86,    87,    87,    88,
      88,    89,    89,    89,    89,    90,    91,    92,    93,    93,
      94,    94,    94,    94,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    97,    97,    97,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    99,
      99,    99,   100,   101,   102,   102,   103,   103,   104,   104,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   106,   106,   106,   106,   106,   106,   106,
     106,   107
>>>>>>> master
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     4,     3,     3,
<<<<<<< HEAD
       9,    10,     4,     8,     0,     3,     5,     2,     1,     1,
       1,     1,     1,     1,    10,     0,     3,     0,     6,     1,
       1,     1,     5,     8,     8,     2,     7,     0,     3,     2,
       4,     3,     5,     3,     5,     0,     3,     5,     4,     6,
       4,     6,     1,     2,     4,     4,     5,     5,     7,     5,
       7,     5,     7,     5,     7,     0,     3,     5,     0,     6,
       6,     8,     6,     8,     6,     8,     6,     8,     0,     1,
       1,     3,     5,     0,     3,     0,     3,     0,     3,     3,
       3,     3,     3,     5,     5,     7,     3,     5,     1,     1,
       1,     1,     1,     1,     2,     1,     8
=======
       9,    10,     4,     8,     0,     3,     5,     2,     4,     3,
       1,     1,     1,     1,     1,     1,    10,     0,     3,     0,
       6,     1,     1,     1,     1,     5,     8,     8,     0,     3,
       2,     4,     3,     5,     3,     5,     0,     3,     5,     4,
       6,     4,     6,     1,     2,     4,     4,     5,     5,     7,
       5,     7,     5,     7,     5,     7,     0,     3,     5,     0,
       6,     6,     8,     6,     8,     6,     8,     6,     8,     0,
       1,     1,     3,     5,     0,     3,     0,     3,     0,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     3,     3,
       5,     5,     7,     1,     1,     1,     1,     1,     1,     1,
       2,     8
>>>>>>> master
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
<<<<<<< HEAD
        case 21:
#line 173 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1552 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 178 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1560 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 183 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1568 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 189 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1576 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 195 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1584 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 201 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1592 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 207 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1601 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 213 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1609 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 219 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1618 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 227 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), 0);
		}
#line 1627 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 232 "yacc_sql.y" /* yacc.c:1646  */
    {
	        CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_unique_index";
	        create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), 1);
	    }
#line 1636 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 240 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1645 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 247 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
  case 21:
#line 172 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1651 "yacc_sql.tab.c"
    break;

  case 22:
#line 177 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1659 "yacc_sql.tab.c"
    break;

  case 23:
#line 182 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1667 "yacc_sql.tab.c"
    break;

  case 24:
#line 188 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1675 "yacc_sql.tab.c"
    break;

  case 25:
#line 194 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1683 "yacc_sql.tab.c"
    break;

  case 26:
#line 200 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1691 "yacc_sql.tab.c"
    break;

  case 27:
#line 206 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1700 "yacc_sql.tab.c"
    break;

  case 28:
#line 212 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1708 "yacc_sql.tab.c"
    break;

  case 29:
#line 218 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1717 "yacc_sql.tab.c"
    break;

  case 30:
#line 226 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), 0);
		}
#line 1726 "yacc_sql.tab.c"
    break;

  case 31:
#line 231 "yacc_sql.y"
            {
	        CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_unique_index";
	        create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), 1);
	    }
#line 1735 "yacc_sql.tab.c"
    break;

  case 32:
#line 239 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1744 "yacc_sql.tab.c"
    break;

  case 33:
#line 246 "yacc_sql.y"
                {
>>>>>>> master
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
<<<<<<< HEAD
#line 1657 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 257 "yacc_sql.y" /* yacc.c:1646  */
    {    }
#line 1663 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 262 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 1756 "yacc_sql.tab.c"
    break;

  case 35:
#line 256 "yacc_sql.y"
                                   {    }
#line 1762 "yacc_sql.tab.c"
    break;

  case 36:
#line 261 "yacc_sql.y"
                {
>>>>>>> master
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-3].number), (yyvsp[-1].number), 0);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_length++;
		}
<<<<<<< HEAD
#line 1678 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 273 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 1777 "yacc_sql.tab.c"
    break;

  case 37:
#line 272 "yacc_sql.y"
                {
>>>>>>> master
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[0].number), 8, 0);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
<<<<<<< HEAD
#line 1693 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 285 "yacc_sql.y" /* yacc.c:1646  */
    {(yyval.number) = (yyvsp[0].number);}
#line 1699 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 288 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number)=INTS; }
#line 1705 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 289 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number)=CHARS; }
#line 1711 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 290 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number)=FLOATS; }
#line 1717 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 292 "yacc_sql.y" /* yacc.c:1646  */
    {(yyval.number)=DATES;}
#line 1723 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 296 "yacc_sql.y" /* yacc.c:1646  */
    {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1732 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 305 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 1792 "yacc_sql.tab.c"
    break;

  case 38:
#line 284 "yacc_sql.y"
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
#line 1807 "yacc_sql.tab.c"
    break;

  case 39:
#line 295 "yacc_sql.y"
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
#line 1822 "yacc_sql.tab.c"
    break;

  case 40:
#line 307 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1828 "yacc_sql.tab.c"
    break;

  case 41:
#line 310 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1834 "yacc_sql.tab.c"
    break;

  case 42:
#line 311 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1840 "yacc_sql.tab.c"
    break;

  case 43:
#line 312 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1846 "yacc_sql.tab.c"
    break;

  case 44:
#line 314 "yacc_sql.y"
                   {(yyval.number)=DATES;}
#line 1852 "yacc_sql.tab.c"
    break;

  case 45:
#line 318 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1861 "yacc_sql.tab.c"
    break;

  case 46:
#line 327 "yacc_sql.y"
                {
>>>>>>> master
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
<<<<<<< HEAD
#line 1751 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 322 "yacc_sql.y" /* yacc.c:1646  */
    { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1759 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 329 "yacc_sql.y" /* yacc.c:1646  */
    {
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1767 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 335 "yacc_sql.y" /* yacc.c:1646  */
    {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1775 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 338 "yacc_sql.y" /* yacc.c:1646  */
    {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1783 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 341 "yacc_sql.y" /* yacc.c:1646  */
    {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1792 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 349 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 1880 "yacc_sql.tab.c"
    break;

  case 48:
#line 344 "yacc_sql.y"
                              { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1888 "yacc_sql.tab.c"
    break;

  case 50:
#line 351 "yacc_sql.y"
                                                       {
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1896 "yacc_sql.tab.c"
    break;

  case 51:
#line 357 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1904 "yacc_sql.tab.c"
    break;

  case 52:
#line 360 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1912 "yacc_sql.tab.c"
    break;

  case 53:
#line 363 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1921 "yacc_sql.tab.c"
    break;

  case 54:
#line 367 "yacc_sql.y"
               {
	    value_init_nullvalue(&CONTEXT->values[CONTEXT->value_length++]);
	    }
#line 1929 "yacc_sql.tab.c"
    break;

  case 55:
#line 374 "yacc_sql.y"
                {
>>>>>>> master
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
<<<<<<< HEAD
#line 1804 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 359 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 1941 "yacc_sql.tab.c"
    break;

  case 56:
#line 384 "yacc_sql.y"
                {
>>>>>>> master
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			Value *value = &CONTEXT->values[0];
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-6].string), (yyvsp[-4].string), value, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
<<<<<<< HEAD
#line 1816 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 369 "yacc_sql.y" /* yacc.c:1646  */
    {	
=======
#line 1953 "yacc_sql.tab.c"
    break;

  case 57:
#line 394 "yacc_sql.y"
                {
>>>>>>> master
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
<<<<<<< HEAD
#line 1836 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 386 "yacc_sql.y" /* yacc.c:1646  */
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
#line 1855 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 401 "yacc_sql.y" /* yacc.c:1646  */
    {
		//找到子查询, 并做一些收尾工作
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		selects_append_relation(st, (yyvsp[-3].string));
		//处理完一个子查询
		CONTEXT->now_select_dep--;//跳回上一级查询
	}
#line 1867 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 410 "yacc_sql.y" /* yacc.c:1646  */
    {
	//TODO: add order 
	}
#line 1875 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 415 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 1973 "yacc_sql.tab.c"
    break;

  case 59:
#line 413 "yacc_sql.y"
                             {
	//TODO: add order 
	}
#line 1981 "yacc_sql.tab.c"
    break;

  case 60:
#line 418 "yacc_sql.y"
                     {
>>>>>>> master
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
<<<<<<< HEAD
#line 1885 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 420 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 1991 "yacc_sql.tab.c"
    break;

  case 61:
#line 423 "yacc_sql.y"
                              {
>>>>>>> master
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-3].string),(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
<<<<<<< HEAD
#line 1895 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 425 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 2001 "yacc_sql.tab.c"
    break;

  case 62:
#line 428 "yacc_sql.y"
                          {
>>>>>>> master
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
<<<<<<< HEAD
#line 1905 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 430 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 2011 "yacc_sql.tab.c"
    break;

  case 63:
#line 433 "yacc_sql.y"
                                 {
>>>>>>> master
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
<<<<<<< HEAD
#line 1915 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 435 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 2021 "yacc_sql.tab.c"
    break;

  case 64:
#line 438 "yacc_sql.y"
                           {
>>>>>>> master
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
<<<<<<< HEAD
#line 1925 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 440 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 2031 "yacc_sql.tab.c"
    break;

  case 65:
#line 443 "yacc_sql.y"
                                  {
>>>>>>> master
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
<<<<<<< HEAD
#line 1935 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 448 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 2041 "yacc_sql.tab.c"
    break;

  case 67:
#line 451 "yacc_sql.y"
                             {
>>>>>>> master
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
<<<<<<< HEAD
#line 1945 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 453 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 2051 "yacc_sql.tab.c"
    break;

  case 68:
#line 456 "yacc_sql.y"
                                    {
>>>>>>> master
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-3].string),(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
<<<<<<< HEAD
#line 1955 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 458 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 2061 "yacc_sql.tab.c"
    break;

  case 69:
#line 461 "yacc_sql.y"
                                 {
>>>>>>> master
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
<<<<<<< HEAD
#line 1965 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 463 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 2071 "yacc_sql.tab.c"
    break;

  case 70:
#line 466 "yacc_sql.y"
                                        {
>>>>>>> master
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
<<<<<<< HEAD
#line 1975 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 468 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 2081 "yacc_sql.tab.c"
    break;

  case 71:
#line 471 "yacc_sql.y"
                                  {
>>>>>>> master
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
<<<<<<< HEAD
#line 1985 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 473 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 2091 "yacc_sql.tab.c"
    break;

  case 72:
#line 476 "yacc_sql.y"
                                         {
>>>>>>> master
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
<<<<<<< HEAD
#line 1995 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 481 "yacc_sql.y" /* yacc.c:1646  */
    {  
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2101 "yacc_sql.tab.c"
    break;

  case 73:
#line 484 "yacc_sql.y"
         {  
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*", 0);
			selects_append_attribute(st, &attr);
		}
<<<<<<< HEAD
#line 2006 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 487 "yacc_sql.y" /* yacc.c:1646  */
    {
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2111 "yacc_sql.tab.c"
    break;

  case 74:
#line 489 "yacc_sql.y"
                   {
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string), 0);
			selects_append_attribute(st, &attr);
		}
<<<<<<< HEAD
#line 2017 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 493 "yacc_sql.y" /* yacc.c:1646  */
    {
		  	Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2121 "yacc_sql.tab.c"
    break;

  case 75:
#line 494 "yacc_sql.y"
                              {
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), 0);
			selects_append_attribute(st, &attr);
		}
<<<<<<< HEAD
#line 2028 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 500 "yacc_sql.y" /* yacc.c:1646  */
    {// add t1.*
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2131 "yacc_sql.tab.c"
    break;

  case 76:
#line 500 "yacc_sql.y"
                               {// add t1.*
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*", 0);
			selects_append_attribute(st, &attr);
	}
<<<<<<< HEAD
#line 2039 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 508 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(*)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2141 "yacc_sql.tab.c"
    break;

  case 77:
#line 507 "yacc_sql.y"
                                           {// add COUNT(*)
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*", 5);
			selects_append_attribute(st, &attr);
	}
<<<<<<< HEAD
#line 2050 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 515 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2151 "yacc_sql.tab.c"
    break;

  case 78:
#line 513 "yacc_sql.y"
                                         {// add COUNT(id)
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 1);
			selects_append_attribute(st, &attr);
	}
<<<<<<< HEAD
#line 2061 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 522 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2161 "yacc_sql.tab.c"
    break;

  case 79:
#line 519 "yacc_sql.y"
                                                {// add COUNT(t.id)
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 1);
			selects_append_attribute(st, &attr);
	}
<<<<<<< HEAD
#line 2072 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 529 "yacc_sql.y" /* yacc.c:1646  */
    {// add MAX(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2171 "yacc_sql.tab.c"
    break;

  case 80:
#line 525 "yacc_sql.y"
                                       {// add MAX(id)
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 2);
			selects_append_attribute(st, &attr);
	}
<<<<<<< HEAD
#line 2083 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 536 "yacc_sql.y" /* yacc.c:1646  */
    {// add MAX(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2181 "yacc_sql.tab.c"
    break;

  case 81:
#line 531 "yacc_sql.y"
                                              {// add MAX(t.id)
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 2);
			selects_append_attribute(st, &attr);
	}
<<<<<<< HEAD
#line 2094 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 543 "yacc_sql.y" /* yacc.c:1646  */
    {// add MIN(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2191 "yacc_sql.tab.c"
    break;

  case 82:
#line 537 "yacc_sql.y"
                                       {// add MIN(id)
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 3);
			selects_append_attribute(st, &attr);
	}
<<<<<<< HEAD
#line 2105 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 550 "yacc_sql.y" /* yacc.c:1646  */
    {// add MIN(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2201 "yacc_sql.tab.c"
    break;

  case 83:
#line 543 "yacc_sql.y"
                                              {// add MIN(t.id)
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 3);
			selects_append_attribute(st, &attr);
	}
<<<<<<< HEAD
#line 2116 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 557 "yacc_sql.y" /* yacc.c:1646  */
    {// add AVG(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2211 "yacc_sql.tab.c"
    break;

  case 84:
#line 549 "yacc_sql.y"
                                       {// add AVG(id)
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 4);
			selects_append_attribute(st, &attr);
	}
<<<<<<< HEAD
#line 2127 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 564 "yacc_sql.y" /* yacc.c:1646  */
    {// add AVG(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2221 "yacc_sql.tab.c"
    break;

  case 85:
#line 555 "yacc_sql.y"
                                              {// add AVG(t.id)
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 4);
			selects_append_attribute(st, &attr);
	}
<<<<<<< HEAD
#line 2138 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 575 "yacc_sql.y" /* yacc.c:1646  */
    {
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2231 "yacc_sql.tab.c"
    break;

  case 87:
#line 565 "yacc_sql.y"
                         {
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string), 0);
			selects_append_attribute(st, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
<<<<<<< HEAD
#line 2151 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 583 "yacc_sql.y" /* yacc.c:1646  */
    {
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2243 "yacc_sql.tab.c"
    break;

  case 88:
#line 572 "yacc_sql.y"
                                {
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), 0);
			selects_append_attribute(st, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
<<<<<<< HEAD
#line 2164 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 595 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(*)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2255 "yacc_sql.tab.c"
    break;

  case 90:
#line 583 "yacc_sql.y"
                                                 {// add COUNT(*)
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*", 5);
			selects_append_attribute(st, &attr);
	}
<<<<<<< HEAD
#line 2175 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 602 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2265 "yacc_sql.tab.c"
    break;

  case 91:
#line 589 "yacc_sql.y"
                                               {// add COUNT(id)
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 1);
			selects_append_attribute(st, &attr);
	}
<<<<<<< HEAD
#line 2186 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 609 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2275 "yacc_sql.tab.c"
    break;

  case 92:
#line 595 "yacc_sql.y"
                                                      {// add COUNT(t.id)
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 1);
			selects_append_attribute(st, &attr);
	}
<<<<<<< HEAD
#line 2197 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 616 "yacc_sql.y" /* yacc.c:1646  */
    {// add MAX(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2285 "yacc_sql.tab.c"
    break;

  case 93:
#line 601 "yacc_sql.y"
                                             {// add MAX(id)
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 2);
			selects_append_attribute(st, &attr);
	}
<<<<<<< HEAD
#line 2208 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 623 "yacc_sql.y" /* yacc.c:1646  */
    {// add MAX(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2295 "yacc_sql.tab.c"
    break;

  case 94:
#line 607 "yacc_sql.y"
                                                    {// add MAX(t.id)
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 2);
			selects_append_attribute(st, &attr);
	}
<<<<<<< HEAD
#line 2219 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 630 "yacc_sql.y" /* yacc.c:1646  */
    {// add MIN(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2305 "yacc_sql.tab.c"
    break;

  case 95:
#line 613 "yacc_sql.y"
                                             {// add MIN(id)
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 3);
			selects_append_attribute(st, &attr);
	}
<<<<<<< HEAD
#line 2230 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 637 "yacc_sql.y" /* yacc.c:1646  */
    {// add MIN(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2315 "yacc_sql.tab.c"
    break;

  case 96:
#line 619 "yacc_sql.y"
                                                    {// add MIN(t.id)
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 3);
			selects_append_attribute(st, &attr);
	}
<<<<<<< HEAD
#line 2241 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 644 "yacc_sql.y" /* yacc.c:1646  */
    {// add AVG(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2325 "yacc_sql.tab.c"
    break;

  case 97:
#line 625 "yacc_sql.y"
                                             {// add AVG(id)
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 4);
			selects_append_attribute(st, &attr);
	}
<<<<<<< HEAD
#line 2252 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 651 "yacc_sql.y" /* yacc.c:1646  */
    {// add AVG(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
=======
#line 2335 "yacc_sql.tab.c"
    break;

  case 98:
#line 631 "yacc_sql.y"
                                                    {// add AVG(t.id)
>>>>>>> master
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 4);
			selects_append_attribute(st, &attr);
	}
<<<<<<< HEAD
#line 2263 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 661 "yacc_sql.y" /* yacc.c:1646  */
    {	
		}
#line 2270 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 663 "yacc_sql.y" /* yacc.c:1646  */
    {//TODO: add inner join
}
#line 2277 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 667 "yacc_sql.y" /* yacc.c:1646  */
    {
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);	
		selects_append_relation(st, (yyvsp[-1].string));
	}
#line 2286 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 673 "yacc_sql.y" /* yacc.c:1646  */
    {//TODO: add inner join
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		selects_append_relation(st, (yyvsp[-2].string));
	}
#line 2295 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 680 "yacc_sql.y" /* yacc.c:1646  */
    {//TODO: add inner join

	}
#line 2303 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 686 "yacc_sql.y" /* yacc.c:1646  */
    {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2311 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 692 "yacc_sql.y" /* yacc.c:1646  */
    {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2319 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 698 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 2345 "yacc_sql.tab.c"
    break;

  case 100:
#line 640 "yacc_sql.y"
               {	
		}
#line 2352 "yacc_sql.tab.c"
    break;

  case 101:
#line 642 "yacc_sql.y"
            {//TODO: add inner join
}
#line 2359 "yacc_sql.tab.c"
    break;

  case 102:
#line 646 "yacc_sql.y"
                          {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
	}
#line 2367 "yacc_sql.tab.c"
    break;

  case 103:
#line 651 "yacc_sql.y"
                                      {//TODO: add inner join
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string));
	}
#line 2375 "yacc_sql.tab.c"
    break;

  case 105:
#line 657 "yacc_sql.y"
                                     {//TODO: add inner join

	}
#line 2383 "yacc_sql.tab.c"
    break;

  case 107:
#line 663 "yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2391 "yacc_sql.tab.c"
    break;

  case 109:
#line 669 "yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2399 "yacc_sql.tab.c"
    break;

  case 110:
#line 675 "yacc_sql.y"
                {
>>>>>>> master
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string), 0);

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			selects_append_condition(st,&condition);
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
<<<<<<< HEAD
#line 2346 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 721 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 2424 "yacc_sql.tab.c"
    break;

  case 111:
#line 696 "yacc_sql.y"
                {
>>>>>>> master
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			selects_append_condition(st,&condition);
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
<<<<<<< HEAD
#line 2371 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 742 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 2448 "yacc_sql.tab.c"
    break;

  case 112:
#line 716 "yacc_sql.y"
                {
>>>>>>> master
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string), 0);
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string), 0);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			selects_append_condition(st,&condition);
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;

		}
<<<<<<< HEAD
#line 2396 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 763 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 2472 "yacc_sql.tab.c"
    break;

  case 113:
#line 736 "yacc_sql.y"
                {
>>>>>>> master
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string), 0);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			selects_append_condition(st,&condition);

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
<<<<<<< HEAD
#line 2423 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 786 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 2498 "yacc_sql.tab.c"
    break;

  case 114:
#line 758 "yacc_sql.y"
            {
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];
            Value left_value;
			value_init_nullvalue(&left_value);
			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, &left_value, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		}
#line 2511 "yacc_sql.tab.c"
    break;

  case 115:
#line 767 "yacc_sql.y"
            {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
            Value right_value;
			value_init_nullvalue(&right_value);
			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, &right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		}
#line 2524 "yacc_sql.tab.c"
    break;

  case 116:
#line 776 "yacc_sql.y"
                {
			Condition condition;
			Value right_value;
			value_init_nullvalue(&right_value);
			Value left_value;
            value_init_nullvalue(&left_value);
			condition_init(&condition, CONTEXT->comp, 0, NULL, &left_value, 0, NULL, &right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		}
#line 2538 "yacc_sql.tab.c"
    break;

  case 117:
#line 786 "yacc_sql.y"
                {
>>>>>>> master
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string), 0);
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			selects_append_condition(st,&condition);
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
<<<<<<< HEAD
#line 2448 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 807 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 2563 "yacc_sql.tab.c"
    break;

  case 118:
#line 807 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string), 0);
            Value right_value;
			value_init_nullvalue(&right_value);
			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, &right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2577 "yacc_sql.tab.c"
    break;

  case 119:
#line 817 "yacc_sql.y"
                {
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string), 0);
			Value left_value;
			value_init_nullvalue(&left_value);
			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, &left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		}
#line 2591 "yacc_sql.tab.c"
    break;

  case 120:
#line 827 "yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string), 0);
            Value right_value;
			value_init_nullvalue(&right_value);
			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, &right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
#line 2605 "yacc_sql.tab.c"
    break;

  case 121:
#line 838 "yacc_sql.y"
                {
>>>>>>> master
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string), 0);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			selects_append_condition(st,&condition);
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
<<<<<<< HEAD
#line 2474 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 829 "yacc_sql.y" /* yacc.c:1646  */
    {
=======
#line 2630 "yacc_sql.tab.c"
    break;

  case 122:
#line 859 "yacc_sql.y"
                {
>>>>>>> master
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string), 0);
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string), 0);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			selects_append_condition(st,&condition);
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;		//属性
			// $$->left_attr.relation_name=$1;
			// $$->left_attr.attribute_name=$3;
			// $$->comp =CONTEXT->comp;
			// $$->right_is_attr = 1;		//属性
			// $$->right_attr.relation_name=$5;
			// $$->right_attr.attribute_name=$7;
    }
<<<<<<< HEAD
#line 2498 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 848 "yacc_sql.y" /* yacc.c:1646  */
    {
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, (yyvsp[-2].string), 0);
		RelAttr right_attr;
		relation_attr_init_query(&right_attr,0,st->sub_num-1);
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		selects_append_condition(st,&condition);
	}
#line 2513 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 858 "yacc_sql.y" /* yacc.c:1646  */
    {
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		RelAttr left_attr;
		relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string), 0);
		RelAttr right_attr;
		relation_attr_init_query(&right_attr,0,st->sub_num-1);
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		selects_append_condition(st,&condition);
	}
#line 2528 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 871 "yacc_sql.y" /* yacc.c:1646  */
    { CONTEXT->comp = EQUAL_TO; }
#line 2534 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 872 "yacc_sql.y" /* yacc.c:1646  */
    { CONTEXT->comp = LESS_THAN; }
#line 2540 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 873 "yacc_sql.y" /* yacc.c:1646  */
    { CONTEXT->comp = GREAT_THAN; }
#line 2546 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 874 "yacc_sql.y" /* yacc.c:1646  */
    { CONTEXT->comp = LESS_EQUAL; }
#line 2552 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 875 "yacc_sql.y" /* yacc.c:1646  */
    { CONTEXT->comp = GREAT_EQUAL; }
#line 2558 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 876 "yacc_sql.y" /* yacc.c:1646  */
    { CONTEXT->comp = NOT_EQUAL; }
#line 2564 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 877 "yacc_sql.y" /* yacc.c:1646  */
    {CONTEXT->comp = NOT_IN; }
#line 2570 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 878 "yacc_sql.y" /* yacc.c:1646  */
    {CONTEXT->comp = IN;}
#line 2576 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 883 "yacc_sql.y" /* yacc.c:1646  */
    {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2585 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;


#line 2589 "yacc_sql.tab.c" /* yacc.c:1646  */
=======
#line 2653 "yacc_sql.tab.c"
    break;

  case 123:
#line 880 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 2659 "yacc_sql.tab.c"
    break;

  case 124:
#line 881 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2665 "yacc_sql.tab.c"
    break;

  case 125:
#line 882 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2671 "yacc_sql.tab.c"
    break;

  case 126:
#line 883 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2677 "yacc_sql.tab.c"
    break;

  case 127:
#line 884 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2683 "yacc_sql.tab.c"
    break;

  case 128:
#line 885 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2689 "yacc_sql.tab.c"
    break;

  case 129:
#line 886 "yacc_sql.y"
             { CONTEXT->comp = IS_;}
#line 2695 "yacc_sql.tab.c"
    break;

  case 130:
#line 887 "yacc_sql.y"
                { CONTEXT->comp = IS_NOT;}
#line 2701 "yacc_sql.tab.c"
    break;

  case 131:
#line 892 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2710 "yacc_sql.tab.c"
    break;


#line 2714 "yacc_sql.tab.c"

>>>>>>> master
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
<<<<<<< HEAD
#line 888 "yacc_sql.y" /* yacc.c:1906  */
=======
#line 897 "yacc_sql.y"
>>>>>>> master

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
