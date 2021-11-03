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
    INNER = 307,
    JOIN = 308,
    NUMBER = 309,
    FLOAT = 310,
    ID = 311,
    PATH = 312,
    SSS = 313,
    STAR = 314,
    STRING_V = 315
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 115 "yacc_sql.y" /* yacc.c:355  */

  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  char *string;
  int number;
  float floats;
	char *position;

#line 234 "yacc_sql.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void *scanner);

#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 250 "yacc_sql.tab.c" /* yacc.c:358  */

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
#define YYLAST   264
=======
#define YYLAST   275
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
<<<<<<< HEAD
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  251
=======
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  283
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
<<<<<<< HEAD
       0,   137,   137,   139,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   163,   168,   173,   179,   185,   191,   197,   203,   209,
     216,   224,   231,   240,   242,   246,   257,   270,   273,   274,
     275,   277,   280,   289,   305,   307,   312,   314,   320,   323,
     326,   333,   343,   353,   372,   377,   382,   388,   395,   401,
     407,   413,   419,   425,   431,   437,   443,   451,   453,   460,
     469,   471,   477,   483,   489,   495,   501,   507,   513,   519,
     526,   528,   532,   534,   538,   540,   545,   566,   586,   606,
     628,   649,   670,   692,   693,   694,   695,   696,   697,   701
=======
       0,   141,   141,   143,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   167,   172,   177,   183,   189,   195,   201,   207,   213,
     220,   228,   235,   244,   246,   250,   261,   274,   277,   278,
     279,   281,   284,   293,   309,   311,   316,   319,   322,   329,
     339,   349,   367,   369,   374,   379,   384,   389,   394,   399,
     405,   407,   412,   417,   422,   427,   432,   440,   445,   450,
     456,   463,   469,   475,   481,   487,   493,   499,   505,   511,
     519,   521,   528,   537,   539,   545,   551,   557,   563,   569,
     575,   581,   587,   594,   596,   599,   603,   605,   609,   611,
     615,   617,   622,   643,   663,   683,   705,   726,   747,   769,
     770,   771,   772,   773,   774,   778
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
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
<<<<<<< HEAD
  "LE", "GE", "NE", "NUMBER", "FLOAT", "ID", "PATH", "SSS", "STAR",
  "STRING_V", "$accept", "commands", "command", "exit", "help", "sync",
  "begin", "commit", "rollback", "drop_table", "show_tables", "desc_table",
  "create_index", "drop_index", "create_table", "attr_def_list",
  "attr_def", "number", "type", "ID_get", "insert", "value_list",
  "tuple_list", "value", "delete", "update", "select", "select_attr",
  "attr_list", "agg_list", "rel_list", "where", "condition_list",
  "condition", "comOp", "load_data", YY_NULLPTR
=======
  "LE", "GE", "NE", "ORDER", "BY", "ASC", "INNER", "JOIN", "NUMBER",
  "FLOAT", "ID", "PATH", "SSS", "STAR", "STRING_V", "$accept", "commands",
  "command", "exit", "help", "sync", "begin", "commit", "rollback",
  "drop_table", "show_tables", "desc_table", "create_index", "drop_index",
  "create_table", "attr_def_list", "attr_def", "number", "type", "ID_get",
  "insert", "value_list", "value", "delete", "update", "select", "order",
  "order_attr", "order_list", "select_attr", "attr_list", "agg_list",
  "rel_list", "join_on", "where", "condition_list", "condition", "comOp",
  "load_data", YY_NULLPTR
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
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
     315
};
# endif

<<<<<<< HEAD
#define YYPACT_NINF (-183)
=======
#define YYPACT_NINF -219
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-219)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
<<<<<<< HEAD
    -183,    19,  -183,    24,   109,     0,   -34,    40,    36,    -7,
      13,     1,    62,    70,    86,   101,   106,    78,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,    61,    76,    81,    87,
     123,   125,   126,   127,    23,  -183,   113,   118,   141,  -183,
      98,    99,   114,  -183,  -183,  -183,  -183,  -183,   111,   131,
     115,   152,   153,   107,   108,    33,   110,   112,    34,  -183,
     116,  -183,  -183,   128,   121,   117,   119,   120,   122,  -183,
    -183,    -5,    -3,    -1,   139,    25,    58,   142,   142,   143,
     146,    52,   166,   132,   137,  -183,   154,    71,   157,   156,
     129,   156,   130,   156,   133,   156,   156,   134,   135,  -183,
    -183,  -183,   136,   121,   -28,  -183,  -183,    31,  -183,    48,
     145,  -183,   -28,   168,   120,   158,  -183,  -183,  -183,  -183,
     163,   138,   124,  -183,   167,  -183,   169,  -183,   170,  -183,
    -183,   171,   142,   143,   190,   172,   144,  -183,  -183,  -183,
    -183,  -183,  -183,    57,    75,    52,  -183,   121,   147,   154,
     193,   148,   178,   180,   181,   182,   183,   156,   156,   156,
     156,  -183,  -183,  -183,   -28,   184,    48,  -183,  -183,   174,
    -183,   145,   201,   204,  -183,  -183,  -183,   187,   206,   159,
     160,    60,   161,  -183,  -183,  -183,  -183,   172,   191,    80,
     164,  -183,  -183,  -183,  -183,  -183,    32,    49,    50,   195,
      51,  -183,   194,   214,   186,  -183,  -183,   156,   173,   156,
     175,   156,   176,   156,   156,   177,   -28,  -183,   179,  -183,
     198,  -183,   199,  -183,   200,  -183,  -183,   202,   172,  -183,
     156,   156,   156,   156,   208,  -183,  -183,  -183,  -183,   191,
    -183
=======
    -219,    72,  -219,   101,   124,     3,   -25,    28,    47,    33,
      43,    23,    77,    97,    98,   105,   110,   104,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,    58,    91,    95,   108,
     151,   152,   154,   155,     8,  -219,   141,   174,   175,  -219,
     123,   125,   142,  -219,  -219,  -219,  -219,  -219,   140,   163,
     145,   182,   183,   131,   132,    -2,   133,   134,    69,  -219,
     135,  -219,  -219,   158,   157,   138,   137,   143,   144,  -219,
    -219,     1,     6,    11,   176,    13,    53,   179,   179,    -5,
     178,    68,   193,   159,   170,  -219,   184,   127,   185,   186,
     148,   186,   153,   186,   160,   186,   186,   161,   162,  -219,
    -219,  -219,   164,   166,   157,   -30,  -219,  -219,    73,  -219,
      93,   173,  -219,   -30,   201,   143,   190,  -219,  -219,  -219,
    -219,   192,   165,   156,  -219,   194,  -219,   202,  -219,   203,
    -219,  -219,   204,   179,    -5,   171,   177,   191,   172,  -219,
    -219,  -219,  -219,  -219,  -219,    88,    94,    68,  -219,   157,
     180,   184,   211,   168,   208,   210,   212,   213,   214,   186,
     186,   186,   186,  -219,  -219,   196,   181,   234,   -30,   217,
      93,  -219,  -219,   207,  -219,   173,   237,   238,  -219,  -219,
    -219,   221,   240,   188,   189,   114,   195,  -219,  -219,  -219,
    -219,    68,    -5,   197,  -219,   191,   243,   107,   198,  -219,
    -219,  -219,  -219,  -219,    52,    62,    78,   226,    83,   173,
    -219,     7,  -219,  -219,  -219,   216,  -219,  -219,   186,   199,
     186,   200,   186,   205,   186,   186,   206,  -219,   227,   209,
     215,   227,  -219,   218,  -219,   229,  -219,   231,  -219,   236,
    -219,  -219,   239,  -219,    60,     4,  -219,  -219,   186,   186,
     186,   186,   227,   219,   227,  -219,   227,   227,  -219,  -219,
    -219,  -219,  -219,  -219,    84,  -219,  -219,  -219,   227,   227,
    -219,  -219,  -219
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
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
       0,     0,     0,     0,    67,    54,     0,     0,     0,    23,
       0,     0,     0,    24,    25,    26,    22,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,    29,    28,     0,    82,     0,     0,     0,     0,    27,
      31,     0,     0,     0,     0,     0,    67,    67,    67,    80,
       0,     0,     0,     0,     0,    42,    33,     0,     0,    70,
       0,    70,     0,    70,     0,    70,    70,     0,     0,    68,
      56,    57,     0,    82,     0,    48,    49,     0,    50,     0,
      84,    51,     0,     0,     0,     0,    38,    39,    40,    41,
      36,     0,     0,    61,     0,    63,     0,    59,     0,    58,
      65,     0,    67,    80,     0,    44,     0,    93,    94,    95,
      96,    97,    98,     0,     0,     0,    83,    82,     0,    33,
       0,     0,     0,     0,     0,     0,     0,    70,    70,    70,
      70,    69,    81,    53,     0,     0,     0,    88,    86,    89,
      87,    84,     0,     0,    34,    32,    37,     0,     0,     0,
       0,     0,     0,    62,    64,    60,    66,    44,    46,     0,
       0,    85,    52,    99,    35,    30,     0,     0,     0,     0,
       0,    45,     0,     0,     0,    90,    91,    70,     0,    70,
       0,    70,     0,    70,    70,     0,     0,    43,     0,    74,
       0,    76,     0,    72,     0,    71,    78,     0,    44,    92,
      70,    70,    70,    70,     0,    75,    77,    73,    79,    46,
      47
=======
       0,     0,     0,     0,    80,    67,     0,     0,     0,    23,
       0,     0,     0,    24,    25,    26,    22,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
       0,    29,    28,     0,    98,     0,     0,     0,     0,    27,
      31,     0,     0,     0,     0,     0,    80,    80,    80,    93,
       0,     0,     0,     0,     0,    42,    33,     0,     0,    83,
       0,    83,     0,    83,     0,    83,    83,     0,     0,    81,
      69,    70,     0,     0,    98,     0,    46,    47,     0,    48,
       0,   100,    49,     0,     0,     0,     0,    38,    39,    40,
      41,    36,     0,     0,    74,     0,    76,     0,    72,     0,
      71,    78,     0,    80,    93,     0,    52,    44,     0,   109,
     110,   111,   112,   113,   114,     0,     0,     0,    99,    98,
       0,    33,     0,     0,     0,     0,     0,     0,     0,    83,
      83,    83,    83,    82,    94,    96,     0,     0,     0,     0,
       0,   104,   102,   105,   103,   100,     0,     0,    34,    32,
      37,     0,     0,     0,     0,     0,     0,    75,    77,    73,
      79,     0,    93,     0,    51,    44,     0,     0,     0,   101,
      50,   115,    35,    30,     0,     0,     0,     0,     0,   100,
      95,    60,    53,    45,    43,     0,   106,   107,    83,     0,
      83,     0,    83,     0,    83,    83,     0,    97,    60,     0,
       0,    60,    54,     0,    87,     0,    89,     0,    85,     0,
      84,    91,     0,    58,    60,    60,    56,   108,    83,    83,
      83,    83,    60,     0,    60,    61,    60,    60,    55,    88,
      90,    86,    92,    65,    60,    63,    59,    57,    60,    60,
      62,    66,    64
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
<<<<<<< HEAD
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,    63,   140,  -183,  -183,  -183,
    -183,  -182,   -24,  -113,  -183,  -183,  -183,  -183,   -80,  -101,
      88,   -99,    53,    77,  -116,  -183
=======
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,   102,   139,  -219,  -219,  -219,
    -219,    54,  -114,  -219,  -219,  -219,  -219,  -219,  -218,  -219,
     -76,  -101,  -137,  -219,  -108,  -166,  -149,  -117,  -219
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
<<<<<<< HEAD
      26,    27,    28,    29,    30,   125,    96,   187,   130,    97,
      31,   175,   213,   119,    32,    33,    34,    46,    69,   133,
     113,    92,   156,   120,   153,    35
=======
      26,    27,    28,    29,    30,   126,    96,   191,   131,    97,
      31,   179,   120,    32,    33,    34,   177,   222,   242,    46,
      69,   134,   114,   202,    92,   158,   121,   155,    35
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
<<<<<<< HEAD
     135,   145,   137,   154,   139,   140,   109,   110,   111,   157,
      40,    41,    42,    43,   144,   211,    99,    47,   101,     2,
     103,   115,   116,     3,     4,   118,    50,   100,     5,   102,
      36,   104,    37,     6,     7,     8,     9,    10,    11,    49,
     178,   180,    12,    13,    14,    67,   106,    48,    51,    15,
      16,    44,    52,   217,    45,    68,   244,   107,   182,    17,
     199,   197,   171,   146,   218,    53,   193,   194,   195,   196,
     219,   221,   224,    54,   147,   148,   149,   150,   151,   152,
      67,   220,   222,   225,    83,    87,   215,    84,    88,    55,
     108,   147,   148,   149,   150,   151,   152,   126,   127,   128,
     129,   115,   116,   117,    56,   118,   115,   116,   177,    57,
     118,   208,    59,   238,   209,    38,   229,    39,   231,    58,
     233,    71,   235,   236,   115,   116,   179,    60,   118,   115,
     116,   214,    61,   118,   163,   164,   165,   166,    62,   245,
     246,   247,   248,    63,    72,    64,    65,    66,    70,    73,
      74,    77,    75,    76,    78,    79,    80,    91,    81,    82,
     105,    85,    90,    86,    67,   112,   114,    89,    93,   121,
     123,    95,    94,    98,   158,   122,   124,   131,   132,   160,
     134,   136,   155,   161,   138,   141,   142,   143,   167,   162,
     168,   169,   170,   173,   174,   176,   185,   186,   183,   188,
     189,   190,   191,   192,   202,   198,   200,   203,   204,   205,
     206,   207,   210,   212,   226,   216,   223,   227,   228,   240,
     241,   242,   184,   243,   230,   250,   232,   234,   237,   249,
     239,   172,   181,     0,   201,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   159
=======
     136,   147,   138,   156,   140,   141,   146,   174,   185,   159,
     109,   110,   111,    40,    41,    42,    43,   112,   266,   209,
     253,   238,    99,   256,   116,   117,   239,   101,   119,   239,
      67,    47,   103,   100,   106,    48,   265,   268,   102,   240,
      68,   182,   184,   104,   273,   107,   275,   113,   276,   277,
      49,   186,   219,   237,    83,   267,   280,    84,   241,    44,
     281,   282,    45,   207,   205,   220,    50,   173,   197,   198,
     199,   200,     2,   228,   262,    67,     3,     4,    51,    52,
      53,     5,   239,   230,   229,   108,     6,     7,     8,     9,
      10,    11,   263,   226,   231,    12,    13,    14,   278,   232,
      54,    55,    15,    16,   235,   148,   239,    36,    56,    37,
     233,   264,    17,    57,    59,   236,   149,   150,   151,   152,
     153,   154,   116,   117,   118,    87,   119,   244,    88,   246,
      38,   248,    39,   250,   251,   279,   149,   150,   151,   152,
     153,   154,   116,   117,   181,    58,   119,    60,   116,   117,
     183,    61,   119,   127,   128,   129,   130,   269,   270,   271,
     272,   116,   117,   225,    62,   119,   165,   166,   167,   168,
     216,    63,    64,   217,    65,    66,    70,    71,    72,    73,
      75,    74,    76,    77,    78,    79,    80,    81,    82,    85,
      86,    89,    90,    91,    93,    94,   122,   105,   115,    95,
      98,    67,   123,   124,   135,   132,   125,   160,   133,   137,
     157,   162,   163,   178,   189,   169,   139,   142,   143,   145,
     144,   164,   190,   170,   171,   172,   176,   175,   180,   192,
     193,   203,   194,   195,   196,   201,   187,   204,   206,   208,
     210,   211,   212,   213,   214,   215,   224,   234,   243,   239,
     258,   218,   259,   221,   227,   245,   247,   260,     0,   223,
     261,   249,   252,   188,   161,   254,     0,     0,     0,     0,
       0,   255,     0,     0,   257,   274
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
};

static const yytype_int16 yycheck[] =
{
<<<<<<< HEAD
     101,   114,   103,   119,   105,   106,    86,    87,    88,   122,
      10,    11,    12,    13,   113,   197,    21,    51,    21,     0,
      21,    49,    50,     4,     5,    53,    33,    32,     9,    32,
       6,    32,     8,    14,    15,    16,    17,    18,    19,     3,
     153,   154,    23,    24,    25,    22,    21,     7,    35,    30,
      31,    51,    51,    21,    54,    32,   238,    32,   157,    40,
     176,   174,   142,    32,    32,     3,   167,   168,   169,   170,
      21,    21,    21,     3,    43,    44,    45,    46,    47,    48,
      22,    32,    32,    32,    51,    51,   199,    54,    54,     3,
      32,    43,    44,    45,    46,    47,    48,    26,    27,    28,
      29,    49,    50,    51,     3,    53,    49,    50,    51,     3,
      53,    51,    51,   226,    54,     6,   217,     8,   219,    41,
     221,     3,   223,   224,    49,    50,    51,    51,    53,    49,
      50,    51,    51,    53,    10,    11,    12,    13,    51,   240,
     241,   242,   243,    20,     3,    20,    20,    20,    35,    51,
      51,    20,    38,    42,    39,     3,     3,    36,    51,    51,
      21,    51,    34,    51,    22,    22,    20,    51,    51,     3,
      33,    51,    53,    51,     6,    43,    22,    20,    22,    21,
      51,    51,    37,    20,    51,    51,    51,    51,    21,    51,
      21,    21,    21,     3,    22,    51,     3,    49,    51,    21,
      20,    20,    20,    20,     3,    21,    32,     3,    21,     3,
      51,    51,    51,    22,    20,    51,    21,     3,    32,    21,
      21,    21,   159,    21,    51,   249,    51,    51,    51,    21,
      51,   143,   155,    -1,   181,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124
=======
     101,   115,   103,   120,   105,   106,   114,   144,   157,   123,
      86,    87,    88,    10,    11,    12,    13,    22,    14,   185,
     238,    14,    21,   241,    54,    55,    22,    21,    58,    22,
      22,    56,    21,    32,    21,     7,   254,   255,    32,    32,
      32,   155,   156,    32,   262,    32,   264,    52,   266,   267,
       3,   159,   201,   219,    56,    51,   274,    59,    51,    56,
     278,   279,    59,   180,   178,   202,    33,   143,   169,   170,
     171,   172,     0,    21,    14,    22,     4,     5,    35,    56,
       3,     9,    22,    21,    32,    32,    14,    15,    16,    17,
      18,    19,    32,   207,    32,    23,    24,    25,    14,    21,
       3,     3,    30,    31,    21,    32,    22,     6,     3,     8,
      32,    51,    40,     3,    56,    32,    43,    44,    45,    46,
      47,    48,    54,    55,    56,    56,    58,   228,    59,   230,
       6,   232,     8,   234,   235,    51,    43,    44,    45,    46,
      47,    48,    54,    55,    56,    41,    58,    56,    54,    55,
      56,    56,    58,    26,    27,    28,    29,   258,   259,   260,
     261,    54,    55,    56,    56,    58,    10,    11,    12,    13,
      56,    20,    20,    59,    20,    20,    35,     3,     3,    56,
      38,    56,    42,    20,    39,     3,     3,    56,    56,    56,
      56,    56,    34,    36,    56,    58,     3,    21,    20,    56,
      56,    22,    43,    33,    56,    20,    22,     6,    22,    56,
      37,    21,    20,    22,     3,    21,    56,    56,    56,    53,
      56,    56,    54,    21,    21,    21,    49,    56,    56,    21,
      20,    50,    20,    20,    20,    39,    56,     3,    21,    32,
       3,     3,    21,     3,    56,    56,     3,    21,    32,    22,
      21,    56,    21,    56,    56,    56,    56,    21,    -1,   205,
      21,    56,    56,   161,   125,    56,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    56,    56
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
<<<<<<< HEAD
       0,    57,     0,     4,     5,     9,    14,    15,    16,    17,
      18,    19,    23,    24,    25,    30,    31,    40,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    76,    80,    81,    82,    91,     6,     8,     6,     8,
      10,    11,    12,    13,    51,    54,    83,    51,     7,     3,
      33,    35,    51,     3,     3,     3,     3,     3,    41,    51,
      51,    51,    51,    20,    20,    20,    20,    22,    32,    84,
      35,     3,     3,    51,    51,    38,    42,    20,    39,     3,
       3,    51,    51,    51,    54,    51,    51,    51,    54,    51,
      34,    36,    87,    51,    53,    51,    72,    75,    51,    21,
      32,    21,    32,    21,    32,    21,    21,    32,    32,    84,
      84,    84,    22,    86,    20,    49,    50,    51,    53,    79,
      89,     3,    43,    33,    22,    71,    26,    27,    28,    29,
      74,    20,    22,    85,    51,    85,    51,    85,    51,    85,
      85,    51,    51,    51,    87,    79,    32,    43,    44,    45,
      46,    47,    48,    90,    90,    37,    88,    79,     6,    72,
      21,    20,    51,    10,    11,    12,    13,    21,    21,    21,
      21,    84,    86,     3,    22,    77,    51,    51,    79,    51,
      79,    89,    87,    51,    71,     3,    49,    73,    21,    20,
      20,    20,    20,    85,    85,    85,    85,    79,    21,    90,
      32,    88,     3,     3,    21,     3,    51,    51,    51,    54,
      51,    77,    22,    78,    51,    79,    51,    21,    32,    21,
      32,    21,    32,    21,    21,    32,    20,     3,    32,    85,
      51,    85,    51,    85,    51,    85,    85,    51,    79,    51,
      21,    21,    21,    21,    77,    85,    85,    85,    85,    21,
      78
=======
       0,    62,     0,     4,     5,     9,    14,    15,    16,    17,
      18,    19,    23,    24,    25,    30,    31,    40,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    81,    84,    85,    86,    99,     6,     8,     6,     8,
      10,    11,    12,    13,    56,    59,    90,    56,     7,     3,
      33,    35,    56,     3,     3,     3,     3,     3,    41,    56,
      56,    56,    56,    20,    20,    20,    20,    22,    32,    91,
      35,     3,     3,    56,    56,    38,    42,    20,    39,     3,
       3,    56,    56,    56,    59,    56,    56,    56,    59,    56,
      34,    36,    95,    56,    58,    56,    77,    80,    56,    21,
      32,    21,    32,    21,    32,    21,    21,    32,    32,    91,
      91,    91,    22,    52,    93,    20,    54,    55,    56,    58,
      83,    97,     3,    43,    33,    22,    76,    26,    27,    28,
      29,    79,    20,    22,    92,    56,    92,    56,    92,    56,
      92,    92,    56,    56,    56,    53,    95,    83,    32,    43,
      44,    45,    46,    47,    48,    98,    98,    37,    96,    83,
       6,    77,    21,    20,    56,    10,    11,    12,    13,    21,
      21,    21,    21,    91,    93,    56,    49,    87,    22,    82,
      56,    56,    83,    56,    83,    97,    95,    56,    76,     3,
      54,    78,    21,    20,    20,    20,    20,    92,    92,    92,
      92,    39,    94,    50,     3,    83,    21,    98,    32,    96,
       3,     3,    21,     3,    56,    56,    56,    59,    56,    97,
      93,    56,    88,    82,     3,    56,    83,    56,    21,    32,
      21,    32,    21,    32,    21,    21,    32,    96,    14,    22,
      32,    51,    89,    32,    92,    56,    92,    56,    92,    56,
      92,    92,    56,    89,    56,    56,    89,    56,    21,    21,
      21,    21,    14,    32,    51,    89,    14,    51,    89,    92,
      92,    92,    92,    89,    56,    89,    89,    89,    14,    51,
      89,    89,    89
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
<<<<<<< HEAD
       0,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    71,    72,    72,    73,    74,    74,
      74,    74,    75,    76,    77,    77,    78,    78,    79,    79,
      79,    80,    81,    82,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    84,    84,    84,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      86,    86,    87,    87,    88,    88,    89,    89,    89,    89,
      89,    89,    89,    90,    90,    90,    90,    90,    90,    91
=======
       0,    61,    62,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    76,    77,    77,    78,    79,    79,
      79,    79,    80,    81,    82,    82,    83,    83,    83,    84,
      85,    86,    87,    87,    88,    88,    88,    88,    88,    88,
      89,    89,    89,    89,    89,    89,    89,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      91,    91,    91,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    93,    93,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    97,    97,    97,    97,    97,    98,
      98,    98,    98,    98,    98,    99
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     4,     3,     3,
       9,     4,     8,     0,     3,     5,     2,     1,     1,     1,
<<<<<<< HEAD
       1,     1,     1,    10,     0,     3,     0,     6,     1,     1,
       1,     5,     8,     7,     1,     2,     4,     4,     5,     5,
       7,     5,     7,     5,     7,     5,     7,     0,     3,     5,
       0,     6,     6,     8,     6,     8,     6,     8,     6,     8,
       0,     3,     0,     3,     0,     3,     3,     3,     3,     3,
       5,     5,     7,     1,     1,     1,     1,     1,     1,     8
=======
       1,     1,     1,     9,     0,     3,     1,     1,     1,     5,
       8,     8,     0,     3,     2,     4,     3,     5,     3,     5,
       0,     3,     5,     4,     6,     4,     6,     1,     2,     4,
       4,     5,     5,     7,     5,     7,     5,     7,     5,     7,
       0,     3,     5,     0,     6,     6,     8,     6,     8,     6,
       8,     6,     8,     0,     3,     5,     0,     3,     0,     3,
       0,     3,     3,     3,     3,     3,     5,     5,     7,     1,
       1,     1,     1,     1,     1,     8
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
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
#line 167 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
<<<<<<< HEAD
#line 1597 "yacc_sql.tab.c"
=======
#line 1525 "yacc_sql.tab.c" /* yacc.c:1646  */
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
    break;

  case 22:
#line 172 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
<<<<<<< HEAD
#line 1605 "yacc_sql.tab.c"
=======
#line 1533 "yacc_sql.tab.c" /* yacc.c:1646  */
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
    break;

  case 23:
#line 177 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
<<<<<<< HEAD
#line 1613 "yacc_sql.tab.c"
=======
#line 1541 "yacc_sql.tab.c" /* yacc.c:1646  */
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
    break;

  case 24:
#line 183 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
<<<<<<< HEAD
#line 1621 "yacc_sql.tab.c"
=======
#line 1549 "yacc_sql.tab.c" /* yacc.c:1646  */
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
    break;

  case 25:
#line 189 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
<<<<<<< HEAD
#line 1629 "yacc_sql.tab.c"
=======
#line 1557 "yacc_sql.tab.c" /* yacc.c:1646  */
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
    break;

  case 26:
#line 195 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
<<<<<<< HEAD
#line 1637 "yacc_sql.tab.c"
=======
#line 1565 "yacc_sql.tab.c" /* yacc.c:1646  */
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
    break;

  case 27:
#line 201 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
<<<<<<< HEAD
#line 1646 "yacc_sql.tab.c"
=======
#line 1574 "yacc_sql.tab.c" /* yacc.c:1646  */
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
    break;

  case 28:
#line 207 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
<<<<<<< HEAD
#line 1654 "yacc_sql.tab.c"
=======
#line 1582 "yacc_sql.tab.c" /* yacc.c:1646  */
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
    break;

  case 29:
#line 213 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
<<<<<<< HEAD
#line 1663 "yacc_sql.tab.c"
=======
#line 1591 "yacc_sql.tab.c" /* yacc.c:1646  */
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
    break;

  case 30:
#line 221 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string));
		}
<<<<<<< HEAD
#line 1672 "yacc_sql.tab.c"
=======
#line 1600 "yacc_sql.tab.c" /* yacc.c:1646  */
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
    break;

  case 31:
#line 229 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
<<<<<<< HEAD
#line 1681 "yacc_sql.tab.c"
=======
#line 1609 "yacc_sql.tab.c" /* yacc.c:1646  */
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
    break;

  case 32:
#line 236 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
<<<<<<< HEAD
#line 1693 "yacc_sql.tab.c"
    break;

  case 34:
#line 242 "yacc_sql.y"
                                   {    }
#line 1699 "yacc_sql.tab.c"
=======
#line 1621 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 246 "yacc_sql.y" /* yacc.c:1646  */
    {    }
#line 1627 "yacc_sql.tab.c" /* yacc.c:1646  */
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
    break;

  case 35:
#line 251 "yacc_sql.y" /* yacc.c:1646  */
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
<<<<<<< HEAD
#line 1714 "yacc_sql.tab.c"
=======
#line 1642 "yacc_sql.tab.c" /* yacc.c:1646  */
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
    break;

  case 36:
#line 262 "yacc_sql.y" /* yacc.c:1646  */
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
<<<<<<< HEAD
#line 1729 "yacc_sql.tab.c"
    break;

  case 37:
#line 270 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1735 "yacc_sql.tab.c"
    break;

  case 38:
#line 273 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1741 "yacc_sql.tab.c"
    break;

  case 39:
#line 274 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1747 "yacc_sql.tab.c"
    break;

  case 40:
#line 275 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1753 "yacc_sql.tab.c"
    break;

  case 41:
#line 277 "yacc_sql.y"
                   {(yyval.number)=DATES;}
#line 1759 "yacc_sql.tab.c"
=======
#line 1657 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 274 "yacc_sql.y" /* yacc.c:1646  */
    {(yyval.number) = (yyvsp[0].number);}
#line 1663 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 277 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number)=INTS; }
#line 1669 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 278 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number)=CHARS; }
#line 1675 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 279 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number)=FLOATS; }
#line 1681 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 281 "yacc_sql.y" /* yacc.c:1646  */
    {(yyval.number)=DATES;}
#line 1687 "yacc_sql.tab.c" /* yacc.c:1646  */
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
    break;

  case 42:
#line 285 "yacc_sql.y" /* yacc.c:1646  */
    {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
<<<<<<< HEAD
#line 1768 "yacc_sql.tab.c"
=======
#line 1696 "yacc_sql.tab.c" /* yacc.c:1646  */
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
    break;

  case 43:
#line 294 "yacc_sql.y" /* yacc.c:1646  */
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
<<<<<<< HEAD
#line 1787 "yacc_sql.tab.c"
=======
#line 1715 "yacc_sql.tab.c" /* yacc.c:1646  */
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
    break;

  case 45:
#line 311 "yacc_sql.y" /* yacc.c:1646  */
    { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
<<<<<<< HEAD
#line 1795 "yacc_sql.tab.c"
    break;

  case 47:
#line 314 "yacc_sql.y"
                                                       {
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1803 "yacc_sql.tab.c"
    break;

  case 48:
#line 320 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1811 "yacc_sql.tab.c"
    break;

  case 49:
#line 323 "yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1819 "yacc_sql.tab.c"
    break;

  case 50:
#line 326 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1828 "yacc_sql.tab.c"
    break;

  case 51:
#line 334 "yacc_sql.y"
                {
=======
#line 1723 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 316 "yacc_sql.y" /* yacc.c:1646  */
    {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1731 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 319 "yacc_sql.y" /* yacc.c:1646  */
    {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1739 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 322 "yacc_sql.y" /* yacc.c:1646  */
    {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1748 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 330 "yacc_sql.y" /* yacc.c:1646  */
    {
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
<<<<<<< HEAD
#line 1840 "yacc_sql.tab.c"
    break;

  case 52:
#line 344 "yacc_sql.y"
                {
=======
#line 1760 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 340 "yacc_sql.y" /* yacc.c:1646  */
    {
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			Value *value = &CONTEXT->values[0];
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-6].string), (yyvsp[-4].string), value, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
<<<<<<< HEAD
#line 1852 "yacc_sql.tab.c"
    break;

  case 53:
#line 354 "yacc_sql.y"
                {
=======
#line 1772 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 350 "yacc_sql.y" /* yacc.c:1646  */
    {
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
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
<<<<<<< HEAD
#line 1872 "yacc_sql.tab.c"
    break;

  case 54:
#line 372 "yacc_sql.y"
         {  
=======
#line 1792 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 369 "yacc_sql.y" /* yacc.c:1646  */
    {
	//TODO: add order 
	}
#line 1800 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 374 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1810 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 379 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-3].string),(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1820 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 384 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1830 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 389 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1840 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 394 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1850 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 399 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1860 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 407 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1870 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 412 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-3].string),(yyvsp[-1].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1880 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 417 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1890 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 422 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1900 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 427 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,NULL,(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1910 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 432 "yacc_sql.y" /* yacc.c:1646  */
    {
		OrderAttr attr;
		order_attr_init(&attr,(yyvsp[-4].string),(yyvsp[-2].string),ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
#line 1920 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 440 "yacc_sql.y" /* yacc.c:1646  */
    {  
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*", 0);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
<<<<<<< HEAD
#line 1882 "yacc_sql.tab.c"
    break;

  case 55:
#line 377 "yacc_sql.y"
                   {
=======
#line 1930 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 445 "yacc_sql.y" /* yacc.c:1646  */
    {
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string), 0);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
<<<<<<< HEAD
#line 1892 "yacc_sql.tab.c"
    break;

  case 56:
#line 382 "yacc_sql.y"
                              {
=======
#line 1940 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 450 "yacc_sql.y" /* yacc.c:1646  */
    {
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), 0);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
<<<<<<< HEAD
#line 1902 "yacc_sql.tab.c"
    break;

  case 57:
#line 388 "yacc_sql.y"
                               {// add t1.*
=======
#line 1950 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 456 "yacc_sql.y" /* yacc.c:1646  */
    {// add t1.*
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*", 0);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
<<<<<<< HEAD
#line 1912 "yacc_sql.tab.c"
    break;

  case 58:
#line 395 "yacc_sql.y"
                                           {// add COUNT(*)
=======
#line 1960 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 463 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(*)
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*", 5);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
<<<<<<< HEAD
#line 1922 "yacc_sql.tab.c"
    break;

  case 59:
#line 401 "yacc_sql.y"
                                         {// add COUNT(id)
=======
#line 1970 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 469 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(id)
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 1);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
<<<<<<< HEAD
#line 1932 "yacc_sql.tab.c"
    break;

  case 60:
#line 407 "yacc_sql.y"
                                                {// add COUNT(t.id)
=======
#line 1980 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 475 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(t.id)
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 1);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
<<<<<<< HEAD
#line 1942 "yacc_sql.tab.c"
    break;

  case 61:
#line 413 "yacc_sql.y"
                                       {// add MAX(id)
=======
#line 1990 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 481 "yacc_sql.y" /* yacc.c:1646  */
    {// add MAX(id)
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 2);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
<<<<<<< HEAD
#line 1952 "yacc_sql.tab.c"
    break;

  case 62:
#line 419 "yacc_sql.y"
                                              {// add MAX(t.id)
=======
#line 2000 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 487 "yacc_sql.y" /* yacc.c:1646  */
    {// add MAX(t.id)
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 2);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
<<<<<<< HEAD
#line 1962 "yacc_sql.tab.c"
    break;

  case 63:
#line 425 "yacc_sql.y"
                                       {// add MIN(id)
=======
#line 2010 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 493 "yacc_sql.y" /* yacc.c:1646  */
    {// add MIN(id)
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 3);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
<<<<<<< HEAD
#line 1972 "yacc_sql.tab.c"
    break;

  case 64:
#line 431 "yacc_sql.y"
                                              {// add MIN(t.id)
=======
#line 2020 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 499 "yacc_sql.y" /* yacc.c:1646  */
    {// add MIN(t.id)
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 3);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
<<<<<<< HEAD
#line 1982 "yacc_sql.tab.c"
    break;

  case 65:
#line 437 "yacc_sql.y"
                                       {// add AVG(id)
=======
#line 2030 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 505 "yacc_sql.y" /* yacc.c:1646  */
    {// add AVG(id)
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 4);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
<<<<<<< HEAD
#line 1992 "yacc_sql.tab.c"
    break;

  case 66:
#line 443 "yacc_sql.y"
                                              {// add AVG(t.id)
=======
#line 2040 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 511 "yacc_sql.y" /* yacc.c:1646  */
    {// add AVG(t.id)
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 4);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
<<<<<<< HEAD
#line 2002 "yacc_sql.tab.c"
    break;

  case 68:
#line 453 "yacc_sql.y"
                         {
=======
#line 2050 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 521 "yacc_sql.y" /* yacc.c:1646  */
    {
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string), 0);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
<<<<<<< HEAD
#line 2014 "yacc_sql.tab.c"
    break;

  case 69:
#line 460 "yacc_sql.y"
                                {
=======
#line 2062 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 528 "yacc_sql.y" /* yacc.c:1646  */
    {
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string), 0);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
<<<<<<< HEAD
#line 2026 "yacc_sql.tab.c"
    break;

  case 71:
#line 471 "yacc_sql.y"
                                                 {// add COUNT(*)
=======
#line 2074 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 539 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(*)
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*", 5);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
<<<<<<< HEAD
#line 2036 "yacc_sql.tab.c"
    break;

  case 72:
#line 477 "yacc_sql.y"
                                               {// add COUNT(id)
=======
#line 2084 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 545 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(id)
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 1);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
<<<<<<< HEAD
#line 2046 "yacc_sql.tab.c"
    break;

  case 73:
#line 483 "yacc_sql.y"
                                                      {// add COUNT(t.id)
=======
#line 2094 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 551 "yacc_sql.y" /* yacc.c:1646  */
    {// add COUNT(t.id)
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 1);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
<<<<<<< HEAD
#line 2056 "yacc_sql.tab.c"
    break;

  case 74:
#line 489 "yacc_sql.y"
                                             {// add MAX(id)
=======
#line 2104 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 557 "yacc_sql.y" /* yacc.c:1646  */
    {// add MAX(id)
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 2);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
<<<<<<< HEAD
#line 2066 "yacc_sql.tab.c"
    break;

  case 75:
#line 495 "yacc_sql.y"
                                                    {// add MAX(t.id)
=======
#line 2114 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 563 "yacc_sql.y" /* yacc.c:1646  */
    {// add MAX(t.id)
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 2);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
<<<<<<< HEAD
#line 2076 "yacc_sql.tab.c"
    break;

  case 76:
#line 501 "yacc_sql.y"
                                             {// add MIN(id)
=======
#line 2124 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 569 "yacc_sql.y" /* yacc.c:1646  */
    {// add MIN(id)
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 3);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
<<<<<<< HEAD
#line 2086 "yacc_sql.tab.c"
    break;

  case 77:
#line 507 "yacc_sql.y"
                                                    {// add MIN(t.id)
=======
#line 2134 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 575 "yacc_sql.y" /* yacc.c:1646  */
    {// add MIN(t.id)
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 3);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
<<<<<<< HEAD
#line 2096 "yacc_sql.tab.c"
    break;

  case 78:
#line 513 "yacc_sql.y"
                                             {// add AVG(id)
=======
#line 2144 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 581 "yacc_sql.y" /* yacc.c:1646  */
    {// add AVG(id)
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string), 4);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
<<<<<<< HEAD
#line 2106 "yacc_sql.tab.c"
    break;

  case 79:
#line 519 "yacc_sql.y"
                                                    {// add AVG(t.id)
=======
#line 2154 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 587 "yacc_sql.y" /* yacc.c:1646  */
    {// add AVG(t.id)
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string), 4);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
	}
<<<<<<< HEAD
#line 2116 "yacc_sql.tab.c"
    break;

  case 81:
#line 528 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2124 "yacc_sql.tab.c"
    break;

  case 83:
#line 534 "yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2132 "yacc_sql.tab.c"
    break;

  case 85:
#line 540 "yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2140 "yacc_sql.tab.c"
    break;

  case 86:
#line 546 "yacc_sql.y"
                {
=======
#line 2164 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 596 "yacc_sql.y" /* yacc.c:1646  */
    {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2172 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 599 "yacc_sql.y" /* yacc.c:1646  */
    {//TODO: add inner join
		selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-2].string));
	}
#line 2180 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 605 "yacc_sql.y" /* yacc.c:1646  */
    {//TODO: add inner join

	}
#line 2188 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 611 "yacc_sql.y" /* yacc.c:1646  */
    {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2196 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 617 "yacc_sql.y" /* yacc.c:1646  */
    {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2204 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 623 "yacc_sql.y" /* yacc.c:1646  */
    {
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
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
<<<<<<< HEAD
#line 2165 "yacc_sql.tab.c"
    break;

  case 87:
#line 567 "yacc_sql.y"
                {
=======
#line 2229 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 644 "yacc_sql.y" /* yacc.c:1646  */
    {
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
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
<<<<<<< HEAD
#line 2189 "yacc_sql.tab.c"
    break;

  case 88:
#line 587 "yacc_sql.y"
                {
=======
#line 2253 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 664 "yacc_sql.y" /* yacc.c:1646  */
    {
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
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
<<<<<<< HEAD
#line 2213 "yacc_sql.tab.c"
    break;

  case 89:
#line 607 "yacc_sql.y"
                {
=======
#line 2277 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 684 "yacc_sql.y" /* yacc.c:1646  */
    {
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
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
<<<<<<< HEAD
#line 2239 "yacc_sql.tab.c"
    break;

  case 90:
#line 629 "yacc_sql.y"
                {
=======
#line 2303 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 706 "yacc_sql.y" /* yacc.c:1646  */
    {
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
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
<<<<<<< HEAD
#line 2264 "yacc_sql.tab.c"
    break;

  case 91:
#line 650 "yacc_sql.y"
                {
=======
#line 2328 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 727 "yacc_sql.y" /* yacc.c:1646  */
    {
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
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
<<<<<<< HEAD
#line 2289 "yacc_sql.tab.c"
    break;

  case 92:
#line 671 "yacc_sql.y"
                {
=======
#line 2353 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 748 "yacc_sql.y" /* yacc.c:1646  */
    {
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
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
<<<<<<< HEAD
#line 2312 "yacc_sql.tab.c"
    break;

  case 93:
#line 692 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 2318 "yacc_sql.tab.c"
    break;

  case 94:
#line 693 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2324 "yacc_sql.tab.c"
    break;

  case 95:
#line 694 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2330 "yacc_sql.tab.c"
    break;

  case 96:
#line 695 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2336 "yacc_sql.tab.c"
    break;

  case 97:
#line 696 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2342 "yacc_sql.tab.c"
    break;

  case 98:
#line 697 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2348 "yacc_sql.tab.c"
    break;

  case 99:
#line 702 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2357 "yacc_sql.tab.c"
    break;


#line 2361 "yacc_sql.tab.c"

=======
#line 2376 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 769 "yacc_sql.y" /* yacc.c:1646  */
    { CONTEXT->comp = EQUAL_TO; }
#line 2382 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 770 "yacc_sql.y" /* yacc.c:1646  */
    { CONTEXT->comp = LESS_THAN; }
#line 2388 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 771 "yacc_sql.y" /* yacc.c:1646  */
    { CONTEXT->comp = GREAT_THAN; }
#line 2394 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 772 "yacc_sql.y" /* yacc.c:1646  */
    { CONTEXT->comp = LESS_EQUAL; }
#line 2400 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 773 "yacc_sql.y" /* yacc.c:1646  */
    { CONTEXT->comp = GREAT_EQUAL; }
#line 2406 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 774 "yacc_sql.y" /* yacc.c:1646  */
    { CONTEXT->comp = NOT_EQUAL; }
#line 2412 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 779 "yacc_sql.y" /* yacc.c:1646  */
    {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2421 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;


#line 2425 "yacc_sql.tab.c" /* yacc.c:1646  */
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29
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
#line 707 "yacc_sql.y"
=======
#line 784 "yacc_sql.y" /* yacc.c:1906  */
>>>>>>> 1aa97dfde021b47a489a251c58b723ad369e9f29

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
