/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


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


#line 130 "yacc_sql.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    NUMBER = 316,
    FLOAT = 317,
    ID = 318,
    PATH = 319,
    SSS = 320,
    STAR = 321,
    STRING_V = 322
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 125 "yacc_sql.y"

  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  char *string;
  int number;
  float floats;
	char *position;

#line 260 "yacc_sql.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void *scanner);

#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   344

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  149
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  354

#define YYUNDEFTOK  2
#define YYMAXUTOK   322


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      65,    66,    67
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   151,   151,   153,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   177,   182,   187,   193,   199,   205,   211,   217,   223,
     230,   235,   243,   249,   251,   261,   268,   277,   279,   283,
     294,   306,   317,   330,   333,   334,   335,   337,   340,   349,
     365,   367,   372,   374,   380,   383,   386,   390,   396,   406,
     416,   433,   435,   440,   445,   452,   454,   459,   467,   482,
     489,   491,   496,   501,   506,   511,   516,   521,   527,   529,
     534,   539,   544,   549,   554,   562,   568,   574,   580,   588,
     595,   602,   609,   616,   623,   630,   637,   644,   653,   655,
     663,   671,   678,   685,   692,   699,   706,   713,   720,   727,
     735,   737,   739,   743,   749,   754,   756,   760,   762,   766,
     768,   773,   802,   829,   856,   883,   898,   914,   931,   956,
     972,   988,  1005,  1032,  1057,  1067,  1077,  1087,  1097,  1110,
    1115,  1120,  1125,  1130,  1135,  1140,  1146,  1151,  1156,  1165
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
  "JOIN", "NOT", "IN_T", "ISNULL", "IS", "NULLABLE", "NUMBER", "FLOAT",
  "ID", "PATH", "SSS", "STAR", "STRING_V", "$accept", "commands",
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
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322
};
# endif

#define YYPACT_NINF (-260)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -260,   129,  -260,    58,   149,    13,   -29,    31,    66,    28,
      35,    51,    91,   132,   133,   134,   147,    81,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,    93,    95,   159,   105,
     108,   150,   152,   157,   160,    43,  -260,   144,   179,   180,
    -260,   121,   130,   154,  -260,  -260,  -260,  -260,  -260,   156,
     174,   167,   145,   193,   204,   146,   155,   -27,   158,    17,
     -21,  -260,   166,  -260,  -260,   186,   194,   173,   177,   181,
     182,   201,  -260,  -260,    14,    16,    68,   222,    70,   226,
     227,   228,   229,    45,   230,   230,    -5,   231,    -8,   247,
     209,   221,  -260,   233,   175,   236,   195,   230,   196,   230,
     197,   230,   198,   230,   230,   199,   200,   202,    27,   203,
     205,  -260,  -260,  -260,   206,   212,   194,  -260,  -260,   161,
     248,   168,  -260,  -260,   117,  -260,   168,    13,   168,   234,
    -260,   161,   258,   181,   249,  -260,  -260,  -260,  -260,    -9,
     210,   252,  -260,   253,  -260,   254,  -260,   255,  -260,  -260,
     256,    98,   100,   107,   257,   119,   230,    -5,   216,   232,
    -260,   259,  -260,  -260,  -260,  -260,  -260,  -260,  -260,   223,
    -260,   235,   170,   219,    23,   176,   250,    11,    -8,  -260,
     194,   224,   233,   281,   225,   237,  -260,   266,   268,   210,
     230,   230,   230,   230,   230,   238,   230,   239,   230,   240,
     230,   230,   241,  -260,  -260,   251,   242,   243,   161,   271,
    -260,  -260,  -260,  -260,  -260,   168,  -260,  -260,  -260,  -260,
    -260,   264,  -260,   244,   265,  -260,   234,   295,   296,  -260,
    -260,  -260,   279,  -260,   245,  -260,   302,   285,  -260,  -260,
    -260,  -260,  -260,   288,  -260,   289,  -260,   290,  -260,  -260,
     291,    -8,    -5,   260,   261,   311,   259,   293,    62,   262,
      -5,   263,  -260,  -260,  -260,  -260,   266,  -260,   313,   230,
     230,   230,   230,   234,  -260,    74,  -260,   267,  -260,  -260,
     297,   315,  -260,   287,  -260,  -260,  -260,   194,  -260,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,   269,   270,  -260,    30,
    -260,   161,  -260,   272,   299,   109,   300,   305,   273,   274,
     305,  -260,   259,  -260,  -260,   275,  -260,  -260,  -260,    73,
      18,  -260,   303,   300,   305,   276,   305,  -260,   305,   305,
    -260,   293,  -260,  -260,    19,  -260,  -260,  -260,  -260,   305,
     305,  -260,  -260,  -260
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
       0,     0,     0,     0,     0,    98,    85,     0,     0,     0,
      23,     0,     0,     0,    24,    25,    26,    22,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,     0,    29,    28,     0,   117,     0,     0,     0,
       0,     0,    27,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,    98,    98,   110,     0,     0,     0,
       0,     0,    48,    37,     0,     0,     0,    98,     0,    98,
       0,    98,     0,    98,    98,     0,     0,     0,     0,     0,
       0,    99,    87,    88,     0,     0,   117,   111,   112,     0,
       0,     0,    54,    55,     0,    56,     0,     0,     0,   119,
      58,     0,     0,     0,     0,    44,    45,    46,    47,    40,
       0,     0,    92,     0,    94,     0,    90,     0,    89,    96,
       0,     0,     0,     0,     0,     0,    98,   110,     0,    61,
      57,    50,    68,   139,   140,   141,   142,   143,   144,     0,
     146,   147,     0,     0,     0,     0,     0,     0,     0,   118,
     117,     0,    37,     0,     0,     0,    42,    33,     0,     0,
      98,    98,    98,    98,    98,     0,    98,     0,    98,     0,
      98,    98,     0,   100,   113,   115,     0,    70,     0,     0,
     145,   148,    57,   130,   125,     0,    57,   123,   121,   134,
      57,   124,   122,     0,   136,   138,   119,     0,     0,    38,
      36,    43,     0,    41,     0,    32,     0,     0,    93,    95,
      91,    97,   104,     0,   106,     0,   102,     0,   101,   108,
       0,     0,   110,     0,     0,     0,    50,    52,     0,     0,
     110,     0,   120,    59,   149,    39,    33,    30,     0,    98,
      98,    98,    98,   119,   114,    65,    62,     0,    60,    51,
       0,     0,    57,     0,   128,   135,   132,   117,   137,    34,
      31,   105,   107,   103,   109,   116,     0,     0,    63,    78,
      71,     0,    49,     0,     0,    65,    65,    78,     0,     0,
      78,    72,    50,   133,    69,     0,    66,    64,    76,    78,
      78,    74,     0,    65,    78,     0,    78,    79,    78,    78,
      73,    52,    67,    83,    78,    81,    77,    75,    53,    78,
      78,    80,    84,    82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,   122,    52,  -260,  -260,   137,   188,  -260,
    -260,  -260,  -260,  -259,    -7,  -126,  -260,  -260,  -260,  -260,
    -260,  -217,  -260,  -165,  -260,  -260,  -139,   207,   -93,  -158,
    -260,  -260,  -260,  -122,  -223,  -183,  -128,  -260
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   198,   245,    29,    30,   144,   103,   242,
     149,   104,    31,   219,   291,   136,    32,    33,    34,   217,
     286,   308,   137,   138,   265,   310,   321,    47,    71,   126,
     127,   128,   262,    99,   189,   139,   182,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     121,   122,   123,   171,   169,   236,   184,   289,   185,   214,
     187,   194,   130,   272,   152,   190,   154,   124,   156,   229,
     158,   159,   235,    41,    42,    43,    44,    89,    90,    91,
      92,   130,   338,   349,    48,   107,    86,   109,    49,    87,
     318,   318,    94,   130,   317,    95,   108,   195,   110,   125,
     131,   196,   318,   132,   133,   134,   224,   135,   228,   232,
     305,    51,   319,   332,    36,    69,    37,    69,   237,    50,
      52,   339,   350,   213,   234,    70,    45,   120,   283,    46,
      93,   226,   130,   320,   132,   133,   227,   334,   135,   111,
     163,   114,   266,   164,    54,   318,   306,   268,   326,   327,
     112,    38,   115,   295,   284,   335,   307,   248,   249,   250,
     251,   252,   297,   254,    53,   256,   342,   258,   259,   204,
     292,   206,    59,   132,   133,   293,   336,   135,   208,     2,
     205,   306,   207,     3,     4,    55,    56,    57,     5,   209,
     211,   325,   294,     6,     7,     8,     9,    10,    11,   183,
      58,   212,    12,    13,    14,    39,    60,    40,    61,    15,
      16,   173,   174,   175,   176,   177,   178,    62,    63,    17,
      65,    64,    66,   179,   180,   314,   181,    67,   328,    72,
      68,   331,    73,    74,    75,   322,   301,   302,   303,   304,
     337,   340,    77,    76,    79,   343,    82,   345,    78,   346,
     347,   145,   146,   147,   148,   351,    80,    83,    81,    84,
     352,   353,   173,   174,   175,   176,   177,   178,    85,   170,
      97,    88,   132,   133,   179,   180,   135,   181,   222,    96,
      98,   132,   133,   223,   230,   135,   100,   132,   133,   231,
     106,   135,   101,   113,   102,   105,   116,   117,   118,   119,
     140,   129,    69,   141,   142,   143,   150,   172,   151,   153,
     155,   157,   160,   161,   191,   162,   165,   168,   166,   167,
     193,   188,   199,   197,   200,   201,   202,   203,   210,   215,
     220,   218,   225,   216,   240,   233,   241,   238,   244,   246,
     261,   221,   267,   264,   263,   243,   269,   271,   273,   274,
     275,   253,   255,   257,   260,   277,   278,   270,   276,   279,
     280,   281,   282,   287,   288,   290,   300,   311,   312,   313,
     324,   247,   306,   285,   341,   296,   298,   318,   299,   239,
     309,   192,   315,   316,   348,   323,   329,   330,   333,   344,
       0,     0,     0,     0,   186
};

static const yytype_int16 yycheck[] =
{
      93,    94,    95,   129,   126,   188,   134,   266,   136,   167,
     138,    20,    20,   236,   107,   141,   109,    22,   111,   184,
     113,   114,   187,    10,    11,    12,    13,    10,    11,    12,
      13,    20,    14,    14,    63,    21,    63,    21,     7,    66,
      22,    22,    63,    20,    14,    66,    32,    56,    32,    54,
      58,    60,    22,    61,    62,    63,   182,    65,   184,   185,
     283,    33,    32,   322,     6,    22,     8,    22,   190,     3,
      35,    53,    53,   166,    63,    32,    63,    32,   261,    66,
      63,    58,    20,    53,    61,    62,    63,    14,    65,    21,
      63,    21,   218,    66,     3,    22,    22,   225,   315,   316,
      32,    43,    32,   268,   262,    32,    32,   200,   201,   202,
     203,   204,   270,   206,    63,   208,   333,   210,   211,    21,
      58,    21,    41,    61,    62,    63,    53,    65,    21,     0,
      32,    22,    32,     4,     5,     3,     3,     3,     9,    32,
      21,    32,   268,    14,    15,    16,    17,    18,    19,    32,
       3,    32,    23,    24,    25,     6,    63,     8,    63,    30,
      31,    44,    45,    46,    47,    48,    49,     8,    63,    40,
      20,    63,    20,    56,    57,   297,    59,    20,   317,    35,
      20,   320,     3,     3,    63,   311,   279,   280,   281,   282,
     329,   330,    38,    63,    20,   334,     3,   336,    42,   338,
     339,    26,    27,    28,    29,   344,    39,     3,    63,    63,
     349,   350,    44,    45,    46,    47,    48,    49,    63,    58,
      34,    63,    61,    62,    56,    57,    65,    59,    58,    63,
      36,    61,    62,    63,    58,    65,    63,    61,    62,    63,
      39,    65,    65,    21,    63,    63,    20,    20,    20,    20,
       3,    20,    22,    44,    33,    22,    20,     9,    63,    63,
      63,    63,    63,    63,     6,    63,    63,    55,    63,    63,
      21,    37,    20,    63,    21,    21,    21,    21,    21,    63,
      57,    22,    63,    51,     3,    35,    61,    63,    22,    21,
      39,    56,    21,    50,    52,    58,    32,    32,     3,     3,
      21,    63,    63,    63,    63,     3,    21,    63,    63,    21,
      21,    21,    21,    52,     3,    22,     3,    20,     3,    32,
      21,   199,    22,    63,    21,    63,    63,    22,   276,   192,
      63,   143,    63,    63,   341,    63,    63,    63,    63,    63,
      -1,    -1,    -1,    -1,   137
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    69,     0,     4,     5,     9,    14,    15,    16,    17,
      18,    19,    23,    24,    25,    30,    31,    40,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    83,
      84,    90,    94,    95,    96,   115,     6,     8,    43,     6,
       8,    10,    11,    12,    13,    63,    66,   105,    63,     7,
       3,    33,    35,    63,     3,     3,     3,     3,     3,    41,
      63,    63,     8,    63,    63,    20,    20,    20,    20,    22,
      32,   106,    35,     3,     3,    63,    63,    38,    42,    20,
      39,    63,     3,     3,    63,    63,    63,    66,    63,    10,
      11,    12,    13,    63,    63,    66,    63,    34,    36,   111,
      63,    65,    63,    86,    89,    63,    39,    21,    32,    21,
      32,    21,    32,    21,    21,    32,    20,    20,    20,    20,
      32,   106,   106,   106,    22,    54,   107,   108,   109,    20,
      20,    58,    61,    62,    63,    65,    93,   100,   101,   113,
       3,    44,    33,    22,    85,    26,    27,    28,    29,    88,
      20,    63,   106,    63,   106,    63,   106,    63,   106,   106,
      63,    63,    63,    63,    66,    63,    63,    63,    55,   111,
      58,    93,     9,    44,    45,    46,    47,    48,    49,    56,
      57,    59,   114,    32,   114,   114,   105,   114,    37,   112,
      93,     6,    86,    21,    20,    56,    60,    63,    81,    20,
      21,    21,    21,    21,    21,    32,    21,    32,    21,    32,
      21,    21,    32,   106,   107,    63,    51,    97,    22,    91,
      57,    56,    58,    63,    93,    63,    58,    63,    93,   101,
      58,    63,    93,    35,    63,   101,   113,   111,    63,    85,
       3,    61,    87,    58,    22,    82,    21,    81,   106,   106,
     106,   106,   106,    63,   106,    63,   106,    63,   106,   106,
      63,    39,   110,    52,    50,   102,    93,    21,   114,    32,
      63,    32,   112,     3,     3,    21,    63,     3,    21,    21,
      21,    21,    21,   113,   107,    63,    98,    52,     3,    91,
      22,    92,    58,    63,    93,   101,    63,   107,    63,    82,
       3,   106,   106,   106,   106,   112,    22,    32,    99,    63,
     103,    20,     3,    32,   111,    63,    63,    14,    22,    32,
      53,   104,    93,    63,    21,    32,    99,    99,   104,    63,
      63,   104,    91,    63,    14,    32,    53,   104,    14,    53,
     104,    21,    99,   104,    63,   104,   104,   104,    92,    14,
      53,   104,   104,   104
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    68,    69,    69,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    80,    81,    82,    82,    83,    84,    85,    85,    86,
      86,    86,    86,    87,    88,    88,    88,    88,    89,    90,
      91,    91,    92,    92,    93,    93,    93,    93,    94,    95,
      96,    97,    97,    98,    98,    99,    99,    99,   100,   101,
     102,   102,   103,   103,   103,   103,   103,   103,   104,   104,
     104,   104,   104,   104,   104,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     107,   107,   107,   108,   109,   110,   110,   111,   111,   112,
     112,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     4,     3,     3,
       9,    10,     2,     0,     3,     4,     8,     0,     3,     5,
       2,     4,     3,     1,     1,     1,     1,     1,     1,    10,
       0,     3,     0,     6,     1,     1,     1,     1,     5,     8,
       9,     0,     3,     2,     4,     0,     3,     5,     2,     7,
       0,     3,     2,     4,     3,     5,     3,     5,     0,     3,
       5,     4,     6,     4,     6,     1,     2,     4,     4,     5,
       5,     7,     5,     7,     5,     7,     5,     7,     0,     3,
       5,     6,     6,     8,     6,     8,     6,     8,     6,     8,
       0,     1,     1,     3,     5,     0,     3,     0,     3,     0,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     3,
       3,     5,     5,     7,     3,     5,     3,     5,     3,     1,
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

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, void *scanner)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, void *scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, void *scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 177 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1681 "yacc_sql.tab.c"
    break;

  case 22:
#line 182 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1689 "yacc_sql.tab.c"
    break;

  case 23:
#line 187 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1697 "yacc_sql.tab.c"
    break;

  case 24:
#line 193 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1705 "yacc_sql.tab.c"
    break;

  case 25:
#line 199 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1713 "yacc_sql.tab.c"
    break;

  case 26:
#line 205 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1721 "yacc_sql.tab.c"
    break;

  case 27:
#line 211 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1730 "yacc_sql.tab.c"
    break;

  case 28:
#line 217 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1738 "yacc_sql.tab.c"
    break;

  case 29:
#line 223 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1747 "yacc_sql.tab.c"
    break;

  case 30:
#line 231 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), 0);
		}
#line 1756 "yacc_sql.tab.c"
    break;

  case 31:
#line 236 "yacc_sql.y"
            {
	        CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_unique_index";
	        create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), 1);
	    }
#line 1765 "yacc_sql.tab.c"
    break;

  case 32:
#line 243 "yacc_sql.y"
                      {
        IndexColumn iColumn;
        IndexColumn_attr_init(&iColumn,(yyvsp[-1].string));
        create_index_append_attribute(&CONTEXT->ssql->sstr.create_index,&iColumn);
    }
#line 1775 "yacc_sql.tab.c"
    break;

  case 34:
#line 251 "yacc_sql.y"
                              {
        IndexColumn iColumn;
        IndexColumn_attr_init(&iColumn,(yyvsp[-1].string));
        create_index_append_attribute(&CONTEXT->ssql->sstr.create_index,&iColumn);
    }
#line 1785 "yacc_sql.tab.c"
    break;

  case 35:
#line 262 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1794 "yacc_sql.tab.c"
    break;

  case 36:
#line 269 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1806 "yacc_sql.tab.c"
    break;

  case 38:
#line 279 "yacc_sql.y"
                                   {    }
#line 1812 "yacc_sql.tab.c"
    break;

  case 39:
#line 284 "yacc_sql.y"
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
#line 1827 "yacc_sql.tab.c"
    break;

  case 40:
#line 295 "yacc_sql.y"
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
#line 1842 "yacc_sql.tab.c"
    break;

  case 41:
#line 307 "yacc_sql.y"
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
#line 1857 "yacc_sql.tab.c"
    break;

  case 42:
#line 318 "yacc_sql.y"
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
#line 1872 "yacc_sql.tab.c"
    break;

  case 43:
#line 330 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1878 "yacc_sql.tab.c"
    break;

  case 44:
#line 333 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1884 "yacc_sql.tab.c"
    break;

  case 45:
#line 334 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1890 "yacc_sql.tab.c"
    break;

  case 46:
#line 335 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1896 "yacc_sql.tab.c"
    break;

  case 47:
#line 337 "yacc_sql.y"
                   {(yyval.number)=DATES;}
#line 1902 "yacc_sql.tab.c"
    break;

  case 48:
#line 341 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1911 "yacc_sql.tab.c"
    break;

  case 49:
#line 350 "yacc_sql.y"
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
#line 1930 "yacc_sql.tab.c"
    break;

  case 51:
#line 367 "yacc_sql.y"
                              { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1938 "yacc_sql.tab.c"
    break;

  case 53:
#line 374 "yacc_sql.y"
                                                       {
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1946 "yacc_sql.tab.c"
    break;

  case 54:
#line 380 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1954 "yacc_sql.tab.c"
    break;

  case 55:
#line 383 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1962 "yacc_sql.tab.c"
    break;

  case 56:
#line 386 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1971 "yacc_sql.tab.c"
    break;

  case 57:
#line 390 "yacc_sql.y"
               {
	    value_init_nullvalue(&CONTEXT->values[CONTEXT->value_length++]);
	    }
#line 1979 "yacc_sql.tab.c"
    break;

  case 58:
#line 397 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1991 "yacc_sql.tab.c"
    break;

  case 59:
#line 407 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			Value *value = &CONTEXT->values[0];
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-6].string), (yyvsp[-4].string), value, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 2003 "yacc_sql.tab.c"
    break;

  case 60:
#line 417 "yacc_sql.y"
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
#line 2023 "yacc_sql.tab.c"
    break;

  case 62:
#line 435 "yacc_sql.y"
                         {
    //TODO: add group
    }
#line 2031 "yacc_sql.tab.c"
    break;

  case 63:
#line 440 "yacc_sql.y"
                 {
        GroupAttr attr;
        group_attr_init(&attr,NULL,(yyvsp[-1].string));
        selects_append_group(&CONTEXT->ssql->sstr.selection,&attr);
    }
#line 2041 "yacc_sql.tab.c"
    break;

  case 64:
#line 445 "yacc_sql.y"
                          {
        GroupAttr attr;
        group_attr_init(&attr,(yyvsp[-3].string),(yyvsp[-1].string));
        selects_append_group(&CONTEXT->ssql->sstr.selection,&attr);
    }
#line 2051 "yacc_sql.tab.c"
    break;

  case 66:
#line 454 "yacc_sql.y"
                         {
        GroupAttr attr;
        group_attr_init(&attr,NULL,(yyvsp[-1].string));
        selects_append_group(&CONTEXT->ssql->sstr.selection,&attr);
    }
#line 2061 "yacc_sql.tab.c"
    break;

  case 67:
#line 459 "yacc_sql.y"
                                {
        GroupAttr attr;
        group_attr_init(&attr,(yyvsp[-3].string),(yyvsp[-1].string));
        selects_append_group(&CONTEXT->ssql->sstr.selection,&attr);
    }
#line 2071 "yacc_sql.tab.c"
    break;

  case 68:
#line 467 "yacc_sql.y"
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
#line 2090 "yacc_sql.tab.c"
    break;

  case 69:
#line 482 "yacc_sql.y"
                                                                 {
		//找到子查询, 并做一些收尾工作
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		selects_append_relation(st, (yyvsp[-3].string));
		//处理完一个子查询
		CONTEXT->now_select_dep--;//跳回上一级查询
	}
#line 2102 "yacc_sql.tab.c"
    break;

  case 71:
#line 491 "yacc_sql.y"
                             {
	//TODO: add order 
	}
#line 2110 "yacc_sql.tab.c"
    break;

  case 72:
#line 496 "yacc_sql.y"
                     {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2120 "yacc_sql.tab.c"
    break;

  case 73:
#line 501 "yacc_sql.y"
                              {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-3].string),(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2130 "yacc_sql.tab.c"
    break;

  case 74:
#line 506 "yacc_sql.y"
                          {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2140 "yacc_sql.tab.c"
    break;

  case 75:
#line 511 "yacc_sql.y"
                                 {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2150 "yacc_sql.tab.c"
    break;

  case 76:
#line 516 "yacc_sql.y"
                           {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2160 "yacc_sql.tab.c"
    break;

  case 77:
#line 521 "yacc_sql.y"
                                  {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2170 "yacc_sql.tab.c"
    break;

  case 79:
#line 529 "yacc_sql.y"
                             {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2180 "yacc_sql.tab.c"
    break;

  case 80:
#line 534 "yacc_sql.y"
                                    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-3].string),(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2190 "yacc_sql.tab.c"
    break;

  case 81:
#line 539 "yacc_sql.y"
                                 {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2200 "yacc_sql.tab.c"
    break;

  case 82:
#line 544 "yacc_sql.y"
                                        {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2210 "yacc_sql.tab.c"
    break;

  case 83:
#line 549 "yacc_sql.y"
                                  {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2220 "yacc_sql.tab.c"
    break;

  case 84:
#line 554 "yacc_sql.y"
                                         {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 2230 "yacc_sql.tab.c"
    break;

  case 85:
#line 562 "yacc_sql.y"
         {  
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*", 0);
			selects_append_attribute(st, &attr);
		}
#line 2241 "yacc_sql.tab.c"
    break;

  case 86:
#line 568 "yacc_sql.y"
                   {
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string), 0);
			selects_append_attribute(st, &attr);
		}
#line 2252 "yacc_sql.tab.c"
    break;

  case 87:
#line 574 "yacc_sql.y"
                              {
		  	Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), 0);
			selects_append_attribute(st, &attr);
		}
#line 2263 "yacc_sql.tab.c"
    break;

  case 88:
#line 580 "yacc_sql.y"
                               {// add t1.*
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*", 0);
			selects_append_attribute(st, &attr);
	}
#line 2274 "yacc_sql.tab.c"
    break;

  case 89:
#line 588 "yacc_sql.y"
                                            {// add COUNT(*)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*", 5);
			selects_append_attribute(st, &attr);
	}
#line 2285 "yacc_sql.tab.c"
    break;

  case 90:
#line 595 "yacc_sql.y"
                                          {// add COUNT(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 1);
			selects_append_attribute(st, &attr);
	}
#line 2296 "yacc_sql.tab.c"
    break;

  case 91:
#line 602 "yacc_sql.y"
                                                 {// add COUNT(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 1);
			selects_append_attribute(st, &attr);
	}
#line 2307 "yacc_sql.tab.c"
    break;

  case 92:
#line 609 "yacc_sql.y"
                                        {// add MAX(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 2);
			selects_append_attribute(st, &attr);
	}
#line 2318 "yacc_sql.tab.c"
    break;

  case 93:
#line 616 "yacc_sql.y"
                                               {// add MAX(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 2);
			selects_append_attribute(st, &attr);
	}
#line 2329 "yacc_sql.tab.c"
    break;

  case 94:
#line 623 "yacc_sql.y"
                                        {// add MIN(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 3);
			selects_append_attribute(st, &attr);
	}
#line 2340 "yacc_sql.tab.c"
    break;

  case 95:
#line 630 "yacc_sql.y"
                                               {// add MIN(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 3);
			selects_append_attribute(st, &attr);
	}
#line 2351 "yacc_sql.tab.c"
    break;

  case 96:
#line 637 "yacc_sql.y"
                                        {// add AVG(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 4);
			selects_append_attribute(st, &attr);
	}
#line 2362 "yacc_sql.tab.c"
    break;

  case 97:
#line 644 "yacc_sql.y"
                                               {// add AVG(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 4);
			selects_append_attribute(st, &attr);
	}
#line 2373 "yacc_sql.tab.c"
    break;

  case 99:
#line 655 "yacc_sql.y"
                         {
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string), 0);
			selects_append_attribute(st, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 2386 "yacc_sql.tab.c"
    break;

  case 100:
#line 663 "yacc_sql.y"
                                {
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), 0);
			selects_append_attribute(st, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
#line 2399 "yacc_sql.tab.c"
    break;

  case 101:
#line 671 "yacc_sql.y"
                                              {// add COUNT(*)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, NULL, "*", 5);
            selects_append_attribute(st, &attr);
    }
#line 2410 "yacc_sql.tab.c"
    break;

  case 102:
#line 678 "yacc_sql.y"
                                            {// add COUNT(id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, NULL, (yyvsp[-2].string), 1);
            selects_append_attribute(st, &attr);
    }
#line 2421 "yacc_sql.tab.c"
    break;

  case 103:
#line 685 "yacc_sql.y"
                                                   {// add COUNT(t.id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 1);
            selects_append_attribute(st, &attr);
    }
#line 2432 "yacc_sql.tab.c"
    break;

  case 104:
#line 692 "yacc_sql.y"
                                          {// add MAX(id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, NULL, (yyvsp[-2].string), 2);
            selects_append_attribute(st, &attr);
    }
#line 2443 "yacc_sql.tab.c"
    break;

  case 105:
#line 699 "yacc_sql.y"
                                                 {// add MAX(t.id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 2);
            selects_append_attribute(st, &attr);
    }
#line 2454 "yacc_sql.tab.c"
    break;

  case 106:
#line 706 "yacc_sql.y"
                                          {// add MIN(id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, NULL, (yyvsp[-2].string), 3);
            selects_append_attribute(st, &attr);
    }
#line 2465 "yacc_sql.tab.c"
    break;

  case 107:
#line 713 "yacc_sql.y"
                                                 {// add MIN(t.id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 3);
            selects_append_attribute(st, &attr);
    }
#line 2476 "yacc_sql.tab.c"
    break;

  case 108:
#line 720 "yacc_sql.y"
                                          {// add AVG(id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, NULL, (yyvsp[-2].string), 4);
            selects_append_attribute(st, &attr);
    }
#line 2487 "yacc_sql.tab.c"
    break;

  case 109:
#line 727 "yacc_sql.y"
                                                 {// add AVG(t.id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 4);
            selects_append_attribute(st, &attr);
    }
#line 2498 "yacc_sql.tab.c"
    break;

  case 111:
#line 737 "yacc_sql.y"
               {	
		}
#line 2505 "yacc_sql.tab.c"
    break;

  case 112:
#line 739 "yacc_sql.y"
            {//TODO: add inner join
}
#line 2512 "yacc_sql.tab.c"
    break;

  case 113:
#line 743 "yacc_sql.y"
                          {
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);	
		selects_append_relation(st, (yyvsp[-1].string));
	}
#line 2521 "yacc_sql.tab.c"
    break;

  case 114:
#line 749 "yacc_sql.y"
                                      {//TODO: add inner join
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		selects_append_relation(st, (yyvsp[-2].string));
	}
#line 2530 "yacc_sql.tab.c"
    break;

  case 116:
#line 756 "yacc_sql.y"
                                     {//TODO: add inner join

	}
#line 2538 "yacc_sql.tab.c"
    break;

  case 118:
#line 762 "yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2546 "yacc_sql.tab.c"
    break;

  case 120:
#line 768 "yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2554 "yacc_sql.tab.c"
    break;

  case 121:
#line 774 "yacc_sql.y"
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
#line 2587 "yacc_sql.tab.c"
    break;

  case 122:
#line 803 "yacc_sql.y"
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
#line 2618 "yacc_sql.tab.c"
    break;

  case 123:
#line 830 "yacc_sql.y"
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
#line 2649 "yacc_sql.tab.c"
    break;

  case 124:
#line 857 "yacc_sql.y"
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
#line 2680 "yacc_sql.tab.c"
    break;

  case 125:
#line 884 "yacc_sql.y"
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
#line 2699 "yacc_sql.tab.c"
    break;

  case 126:
#line 899 "yacc_sql.y"
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
#line 2719 "yacc_sql.tab.c"
    break;

  case 127:
#line 915 "yacc_sql.y"
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
#line 2740 "yacc_sql.tab.c"
    break;

  case 128:
#line 932 "yacc_sql.y"
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
#line 2769 "yacc_sql.tab.c"
    break;

  case 129:
#line 957 "yacc_sql.y"
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
#line 2789 "yacc_sql.tab.c"
    break;

  case 130:
#line 973 "yacc_sql.y"
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
#line 2809 "yacc_sql.tab.c"
    break;

  case 131:
#line 989 "yacc_sql.y"
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
#line 2829 "yacc_sql.tab.c"
    break;

  case 132:
#line 1006 "yacc_sql.y"
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
#line 2860 "yacc_sql.tab.c"
    break;

  case 133:
#line 1033 "yacc_sql.y"
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
#line 2889 "yacc_sql.tab.c"
    break;

  case 134:
#line 1057 "yacc_sql.y"
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
#line 2904 "yacc_sql.tab.c"
    break;

  case 135:
#line 1067 "yacc_sql.y"
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
#line 2919 "yacc_sql.tab.c"
    break;

  case 136:
#line 1077 "yacc_sql.y"
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
#line 2934 "yacc_sql.tab.c"
    break;

  case 137:
#line 1087 "yacc_sql.y"
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
#line 2949 "yacc_sql.tab.c"
    break;

  case 138:
#line 1097 "yacc_sql.y"
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
#line 2964 "yacc_sql.tab.c"
    break;

  case 139:
#line 1110 "yacc_sql.y"
             { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		CONTEXT->comp = EQUAL_TO; 
		st->comp=EQUAL_TO;
			}
#line 2974 "yacc_sql.tab.c"
    break;

  case 140:
#line 1115 "yacc_sql.y"
         { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=LESS_THAN;
		CONTEXT->comp = LESS_THAN; 
		}
#line 2984 "yacc_sql.tab.c"
    break;

  case 141:
#line 1120 "yacc_sql.y"
         { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=GREAT_THAN;
		CONTEXT->comp = GREAT_THAN; 
		}
#line 2994 "yacc_sql.tab.c"
    break;

  case 142:
#line 1125 "yacc_sql.y"
         { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=LESS_EQUAL;
		CONTEXT->comp = LESS_EQUAL; 
		}
#line 3004 "yacc_sql.tab.c"
    break;

  case 143:
#line 1130 "yacc_sql.y"
         { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=GREAT_EQUAL;
		CONTEXT->comp = GREAT_EQUAL; 
		}
#line 3014 "yacc_sql.tab.c"
    break;

  case 144:
#line 1135 "yacc_sql.y"
         { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=NOT_EQUAL;
		CONTEXT->comp = NOT_EQUAL; 
		}
#line 3024 "yacc_sql.tab.c"
    break;

  case 145:
#line 1140 "yacc_sql.y"
                  {

		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=NOT_IN;
		CONTEXT->comp = NOT_IN; 
		}
#line 3035 "yacc_sql.tab.c"
    break;

  case 146:
#line 1146 "yacc_sql.y"
              {
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=IN;
		CONTEXT->comp = IN;
		}
#line 3045 "yacc_sql.tab.c"
    break;

  case 147:
#line 1151 "yacc_sql.y"
             {
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=IS_;
		CONTEXT->comp = IS_;
		}
#line 3055 "yacc_sql.tab.c"
    break;

  case 148:
#line 1156 "yacc_sql.y"
                {

		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=IS_NOT;
		CONTEXT->comp = IS_NOT;
		}
#line 3066 "yacc_sql.tab.c"
    break;

  case 149:
#line 1166 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 3075 "yacc_sql.tab.c"
    break;


#line 3079 "yacc_sql.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp, scanner);
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
#line 1171 "yacc_sql.y"

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
