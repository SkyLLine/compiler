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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/main.y"

    #include"common.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    Field* rootf;
    extern int lineno;
    int yylex();
    int yyerror( char const * );

#line 80 "src/main.tab.cpp"

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
#ifndef YY_YY_SRC_MAIN_TAB_H_INCLUDED
# define YY_YY_SRC_MAIN_TAB_H_INCLUDED
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
    IF = 258,
    ELSE = 259,
    WHILE = 260,
    FOR = 261,
    RETURN = 262,
    PRINTF = 263,
    SCANF = 264,
    T_INT = 265,
    T_BOOL = 266,
    T_CHAR = 267,
    T_STRING = 268,
    T_VOID = 269,
    T_STRUCT = 270,
    T_INT_POINTER = 271,
    T_CHAR_POINTER = 272,
    LOP_ASSIGN = 273,
    ADD_ASSIGN = 274,
    SUB_ASSIGN = 275,
    MUL_ASSIGN = 276,
    DIV_ASSIGN = 277,
    MOD_ASSIGN = 278,
    IDENTIFIER = 279,
    INTEGER = 280,
    CHAR = 281,
    BOOL = 282,
    STRING = 283,
    SEMICOLON = 284,
    COMMA = 285,
    POINT = 286,
    LPAREN = 287,
    RPAREN = 288,
    LBRACK = 289,
    RBRACK = 290,
    LBRACE = 291,
    RBRACE = 292,
    GT = 293,
    LT = 294,
    GE = 295,
    LE = 296,
    EQ = 297,
    NE = 298,
    ADD = 299,
    SUB = 300,
    MUL = 301,
    DIV = 302,
    MOD = 303,
    LOG_AND = 304,
    LOG_OR = 305,
    NOT = 306,
    NEG = 307,
    POS = 308,
    SELF_INC = 309,
    SELF_DEC = 310,
    GET_ADDRESS = 311
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_MAIN_TAB_H_INCLUDED  */



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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  55
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   266

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

#define YYUNDEFTOK  2
#define YYMAXUTOK   311


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
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    40,    40,    44,    45,    49,    50,    54,    57,    63,
      64,    68,    72,    73,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    90,    94,    97,   101,   102,   106,
     107,   111,   115,   116,   119,   123,   127,   128,   131,   132,
     133,   134,   138,   139,   142,   143,   156,   157,   158,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   175,
     176,   179,   180,   181,   182,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   201,   202,   203,   204,
     209,   212,   215,   218,   221
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "FOR", "RETURN",
  "PRINTF", "SCANF", "T_INT", "T_BOOL", "T_CHAR", "T_STRING", "T_VOID",
  "T_STRUCT", "T_INT_POINTER", "T_CHAR_POINTER", "LOP_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "IDENTIFIER", "INTEGER", "CHAR", "BOOL", "STRING", "SEMICOLON", "COMMA",
  "POINT", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE",
  "GT", "LT", "GE", "LE", "EQ", "NE", "ADD", "SUB", "MUL", "DIV", "MOD",
  "LOG_AND", "LOG_OR", "NOT", "NEG", "POS", "SELF_INC", "SELF_DEC",
  "GET_ADDRESS", "$accept", "program", "parts", "part",
  "function_declaration", "parameters", "parameter", "statements",
  "statement", "field", "for_stmt", "assign_stmt", "if_else_stmt",
  "printf_stmt", "scanf_stmt", "exprs", "while_stmt", "declare_stmt",
  "simple_instructions", "simple_instruction", "instructions",
  "instruction", "variable", "bool_expr", "all_values", "all_value",
  "expr", "number_list", "type", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311
};
# endif

#define YYPACT_NINF (-119)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      85,     2,    20,    36,   -12,    40,    57,  -119,  -119,  -119,
    -119,    14,   114,  -119,  -119,   -16,    18,    18,   -16,   104,
    -119,    85,  -119,  -119,  -119,   119,  -119,   128,   133,  -119,
     136,  -119,   140,    72,   129,   154,   134,   -16,   -16,   -16,
    -119,    18,    84,   106,   143,   176,  -119,   -16,   -31,    26,
     170,  -119,  -119,  -119,   154,  -119,  -119,  -119,  -119,  -119,
    -119,   -16,   -16,   -16,   -16,   182,    18,    18,    18,    18,
      18,    18,    18,    18,    18,    18,    18,    18,   173,  -119,
     211,   187,    16,    52,   213,   186,  -119,    86,   214,     6,
     137,   207,  -119,  -119,  -119,  -119,  -119,  -119,    72,   154,
    -119,   191,    95,    95,    95,    95,    95,    95,   181,   181,
    -119,  -119,  -119,    18,    93,   218,   221,   222,   212,   212,
     -16,    18,  -119,   -18,   -16,   -16,  -119,  -119,    95,   215,
     216,   220,   228,   219,    19,  -119,   223,    85,   242,  -119,
      -3,   224,   142,  -119,   -18,   226,   -27,  -119,  -119,    85,
     217,   210,  -119,  -119,  -119,   225,    85,   221,   212,   -16,
    -119,    18,    26,  -119,   -18,   227,    85,  -119,  -119,  -119,
    -119,   230,  -119,  -119,  -119,   229,   212,  -119,  -119
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    80,    81,    83,
      82,     0,    61,    65,    23,     0,     0,     0,     0,     0,
       2,     4,     6,     5,    16,     0,    18,     0,     0,    17,
       0,    26,    37,    41,    66,    40,     0,     0,     0,     0,
      22,     0,    66,     0,     0,     0,    84,     0,     0,    66,
       0,    75,    74,    58,     0,     1,     3,    15,    19,    20,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,    35,
      43,    45,     0,     0,     0,     0,    21,     0,     0,    77,
      76,     0,    49,    62,    68,    36,    56,    57,    39,    38,
      64,     0,    55,    54,    52,    53,    50,    51,    72,    73,
      70,    71,    69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,     0,     0,     0,    67,    63,    44,     0,
       0,     9,     0,     0,    46,    42,     0,     0,    28,    34,
       0,     0,    33,    61,     0,     0,    60,    78,    79,     0,
       0,     0,    11,    47,    48,     0,    12,     0,     0,     0,
      29,     0,     0,    31,     0,     0,     0,    10,    24,    13,
      27,     0,    32,    59,     8,     0,     0,     7,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -119,  -119,   234,  -119,  -119,   105,  -119,   -11,    30,  -118,
    -119,  -119,  -119,  -119,  -119,    99,  -119,  -119,   -34,  -119,
     145,  -119,  -119,    49,   101,     0,     7,     9,    10
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    21,    22,   130,   131,   155,   156,   138,
      24,    25,    26,    27,    28,   141,    29,    30,    31,    32,
      79,    80,    81,    33,   145,    42,    35,    91,   157
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      34,   139,    92,   164,    65,    84,   143,    66,    12,    13,
      36,    43,    12,    13,   144,    49,    15,    40,    62,    63,
      41,    34,    50,    51,    52,    54,   159,    95,    16,    17,
      23,    36,    16,    17,    37,    18,   124,   113,    46,    34,
     170,    49,    12,    13,    54,    54,    62,    63,    85,   118,
      41,    23,    38,   115,    90,    62,    63,    65,   178,    93,
      66,    34,    16,    17,    48,    62,    63,    53,    39,    54,
      54,    99,    44,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   119,    82,    83,     1,    45,
       2,     3,     4,     5,     6,     7,    89,     8,     9,    10,
      11,    62,    63,     7,    55,     8,     9,    10,    11,    12,
      13,    96,    97,    98,    14,    65,   121,    15,    66,   122,
     128,    62,    63,   146,   132,   171,   129,    54,   142,    16,
      17,    90,    90,   147,   148,    86,    18,    34,   165,    73,
      74,    75,    76,    77,   162,   169,    47,    64,    57,    34,
      73,    74,    75,    76,    77,   175,    34,    58,    78,    34,
      65,   132,    59,    66,   146,    60,    34,   125,   142,   140,
      61,    87,   161,    89,    89,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    73,    74,    75,    76,
      77,   113,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    94,    88,   114,   100,   115,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    94,
       7,   117,     8,     9,    10,    11,   127,    75,    76,    77,
      73,    74,    75,    76,    77,    73,    74,    75,    76,    77,
     126,   116,   120,   133,   123,   134,   158,   136,   137,   150,
     151,   149,   152,   166,   153,    56,   167,   160,   154,   163,
     172,   135,   168,   176,   174,   173,   177
};

static const yytype_uint8 yycheck[] =
{
       0,   119,    33,    30,    31,    39,    24,    34,    24,    25,
       0,     4,    24,    25,    32,    15,    32,    29,    49,    50,
      32,    21,    15,    16,    17,    18,    29,    61,    44,    45,
       0,    21,    44,    45,    32,    51,    30,    18,    24,    39,
     158,    41,    24,    25,    37,    38,    49,    50,    41,    33,
      32,    21,    32,    34,    47,    49,    50,    31,   176,    33,
      34,    61,    44,    45,    15,    49,    50,    18,    32,    62,
      63,    64,    32,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    33,    37,    38,     3,    32,
       5,     6,     7,     8,     9,    10,    47,    12,    13,    14,
      15,    49,    50,    10,     0,    12,    13,    14,    15,    24,
      25,    62,    63,    64,    29,    31,    30,    32,    34,    33,
     113,    49,    50,   123,   114,   159,    33,   120,   121,    44,
      45,   124,   125,   124,   125,    29,    51,   137,   149,    44,
      45,    46,    47,    48,   144,   156,    32,    18,    29,   149,
      44,    45,    46,    47,    48,   166,   156,    29,    24,   159,
      31,   151,    29,    34,   164,    29,   166,    30,   161,   120,
      30,    28,    30,   124,   125,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    44,    45,    46,    47,
      48,    18,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    33,    28,    32,    24,    34,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    33,
      10,    34,    12,    13,    14,    15,    35,    46,    47,    48,
      44,    45,    46,    47,    48,    44,    45,    46,    47,    48,
      33,    30,    29,    25,    30,    24,     4,    25,    36,    33,
      30,    36,    24,    36,    35,    21,   151,    33,    35,    33,
     161,   116,    37,    33,    37,   164,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    10,    12,    13,
      14,    15,    24,    25,    29,    32,    44,    45,    51,    58,
      59,    60,    61,    65,    67,    68,    69,    70,    71,    73,
      74,    75,    76,    80,    82,    83,    85,    32,    32,    32,
      29,    32,    82,    83,    32,    32,    24,    32,    80,    82,
      83,    83,    83,    80,    83,     0,    59,    29,    29,    29,
      29,    30,    49,    50,    18,    31,    34,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    24,    77,
      78,    79,    80,    80,    75,    83,    29,    28,    28,    80,
      83,    84,    33,    33,    33,    75,    80,    80,    80,    83,
      24,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    18,    32,    34,    30,    34,    33,    33,
      29,    30,    33,    30,    30,    30,    33,    35,    83,    33,
      62,    63,    85,    25,    24,    77,    25,    36,    66,    66,
      80,    72,    83,    24,    32,    81,    82,    84,    84,    36,
      33,    30,    24,    35,    35,    64,    65,    85,     4,    29,
      33,    30,    82,    33,    30,    64,    36,    62,    37,    64,
      66,    75,    72,    81,    37,    64,    33,    37,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    63,    64,    64,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    66,    67,    68,    69,    69,    70,
      70,    71,    72,    72,    73,    74,    75,    75,    76,    76,
      76,    76,    77,    77,    78,    78,    79,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    81,
      81,    82,    82,    82,    82,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    84,    84,    84,    84,
      85,    85,    85,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     8,     7,     1,
       3,     2,     1,     2,     2,     2,     1,     1,     1,     2,
       2,     3,     2,     1,     3,     9,     1,     7,     5,     6,
       4,     6,     3,     1,     5,     2,     3,     1,     3,     3,
       1,     1,     3,     1,     3,     1,     1,     4,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       1,     1,     3,     4,     3,     1,     1,     4,     3,     3,
       3,     3,     3,     3,     2,     2,     1,     1,     3,     3,
       1,     1,     1,     1,     2
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
        yyerror (YY_("syntax error: cannot back up")); \
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
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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
      yychar = yylex ();
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
  case 2:
#line 40 "src/main.y"
           {root = new TreeNode(0, NODE_PROG);root->addChild(yyvsp[0]);}
#line 1501 "src/main.tab.cpp"
    break;

  case 3:
#line 44 "src/main.y"
                {yyvsp[-1]->addsibLing(yyvsp[0]);}
#line 1507 "src/main.tab.cpp"
    break;

  case 4:
#line 45 "src/main.y"
          {yyval = yyvsp[0];}
#line 1513 "src/main.tab.cpp"
    break;

  case 5:
#line 49 "src/main.y"
               {yyval = yyvsp[0];}
#line 1519 "src/main.tab.cpp"
    break;

  case 6:
#line 50 "src/main.y"
                          {yyval = yyvsp[0];}
#line 1525 "src/main.tab.cpp"
    break;

  case 7:
#line 54 "src/main.y"
                                                                       {yyval = new TreeNode(lineno, NODE_STMT);yyval->stmtType = STMT_FUNC_DECL;
    yyval->addChild(yyvsp[-7]);yyval->addChild(yyvsp[-6]);yyval->addChild(yyvsp[-4]);TreeNode *tmp = new TreeNode(lineno, NODE_STMT);tmp->stmtType = STMT_FUNC_DEF;
    yyval->addChild(tmp);tmp->addChild(yyvsp[-1]);}
#line 1533 "src/main.tab.cpp"
    break;

  case 8:
#line 57 "src/main.y"
                                                            {yyval = new TreeNode(lineno, NODE_STMT);yyval->stmtType = STMT_FUNC_DECL;
    yyval->addChild(yyvsp[-6]);yyval->addChild(yyvsp[-5]);TreeNode *tmp = new TreeNode(lineno, NODE_STMT);tmp->stmtType = STMT_FUNC_DEF;
    yyval->addChild(tmp);tmp->addChild(yyvsp[-1]);}
#line 1541 "src/main.tab.cpp"
    break;

  case 9:
#line 63 "src/main.y"
               {yyval = yyvsp[0];}
#line 1547 "src/main.tab.cpp"
    break;

  case 10:
#line 64 "src/main.y"
                                {yyval = yyvsp[-2];yyvsp[-2]->addsibLing(yyvsp[0]);}
#line 1553 "src/main.tab.cpp"
    break;

  case 11:
#line 68 "src/main.y"
                     {yyval = new TreeNode(lineno, NODE_STMT);yyval->stmtType = STMT_PARA;yyval->addChild(yyvsp[-1]);yyval->addChild(yyvsp[0]);}
#line 1559 "src/main.tab.cpp"
    break;

  case 12:
#line 72 "src/main.y"
               {yyval = yyvsp[0];}
#line 1565 "src/main.tab.cpp"
    break;

  case 13:
#line 73 "src/main.y"
                          {yyval = yyvsp[-1]; yyval->addsibLing(yyvsp[0]);}
#line 1571 "src/main.tab.cpp"
    break;

  case 14:
#line 77 "src/main.y"
                            {yyval = yyvsp[-1];}
#line 1577 "src/main.tab.cpp"
    break;

  case 15:
#line 78 "src/main.y"
                           {yyval = yyvsp[-1];}
#line 1583 "src/main.tab.cpp"
    break;

  case 16:
#line 79 "src/main.y"
               {yyval = yyvsp[0];}
#line 1589 "src/main.tab.cpp"
    break;

  case 17:
#line 80 "src/main.y"
                 {yyval = yyvsp[0];}
#line 1595 "src/main.tab.cpp"
    break;

  case 18:
#line 81 "src/main.y"
                   {yyval = yyvsp[0];}
#line 1601 "src/main.tab.cpp"
    break;

  case 19:
#line 82 "src/main.y"
                           {yyval = yyvsp[-1];}
#line 1607 "src/main.tab.cpp"
    break;

  case 20:
#line 83 "src/main.y"
                          {yyval = yyvsp[-1];}
#line 1613 "src/main.tab.cpp"
    break;

  case 21:
#line 84 "src/main.y"
                           {yyval = new TreeNode(lineno, NODE_STMT);yyval->stmtType = STMT_RET; yyval->addChild(yyvsp[-1]);}
#line 1619 "src/main.tab.cpp"
    break;

  case 22:
#line 85 "src/main.y"
                      {yyval = new TreeNode(lineno, NODE_STMT);yyval->stmtType = STMT_RET;}
#line 1625 "src/main.tab.cpp"
    break;

  case 23:
#line 86 "src/main.y"
               {}
#line 1631 "src/main.tab.cpp"
    break;

  case 24:
#line 90 "src/main.y"
                              {yyval = new TreeNode(lineno, NODE_STMT);yyval->stmtType = STMT_FIELD; yyval->addChild(yyvsp[-1]);}
#line 1637 "src/main.tab.cpp"
    break;

  case 25:
#line 94 "src/main.y"
                                                                                                   {yyval = new TreeNode(lineno, NODE_STMT);yyval->stmtType = STMT_FOR;yyval->addChild(yyvsp[-6]);yyval->addChild(yyvsp[-4]);yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1643 "src/main.tab.cpp"
    break;

  case 26:
#line 97 "src/main.y"
                          {yyval = new TreeNode(lineno, NODE_STMT);yyval->addChild(yyvsp[0]);yyval->stmtType = STMT_ASSIGN;}
#line 1649 "src/main.tab.cpp"
    break;

  case 27:
#line 101 "src/main.y"
                                                 {yyval = new TreeNode(lineno, NODE_STMT);yyval->stmtType = STMT_IF_ELSE;yyval->addChild(yyvsp[-4]);yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1655 "src/main.tab.cpp"
    break;

  case 28:
#line 102 "src/main.y"
                                       {yyval = new TreeNode(lineno, NODE_STMT);yyval->stmtType = STMT_IF;yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1661 "src/main.tab.cpp"
    break;

  case 29:
#line 106 "src/main.y"
                                             {yyval = new TreeNode(lineno, NODE_STMT);yyval->stmtType = STMT_PRTF;yyval->addChild(yyvsp[-3]);yyval->addChild(yyvsp[-1]);}
#line 1667 "src/main.tab.cpp"
    break;

  case 30:
#line 107 "src/main.y"
                                 {yyval = new TreeNode(lineno, NODE_STMT);yyval->stmtType = STMT_PRTF;yyval->addChild(yyvsp[-1]);}
#line 1673 "src/main.tab.cpp"
    break;

  case 31:
#line 111 "src/main.y"
                                                  {yyval = new TreeNode(lineno, NODE_STMT);yyval->stmtType = STMT_SCF;}
#line 1679 "src/main.tab.cpp"
    break;

  case 32:
#line 115 "src/main.y"
                      {yyvsp[-2]->addsibLing(yyvsp[0]);yyval = yyvsp[-2];}
#line 1685 "src/main.tab.cpp"
    break;

  case 33:
#line 116 "src/main.y"
          {yyval = yyvsp[0];}
#line 1691 "src/main.tab.cpp"
    break;

  case 34:
#line 119 "src/main.y"
                                         {yyval = new TreeNode(lineno, NODE_STMT);yyval->stmtType = STMT_WHILE;yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1697 "src/main.tab.cpp"
    break;

  case 35:
#line 123 "src/main.y"
                       {yyval = new TreeNode(lineno, NODE_STMT);yyval->stmtType = STMT_DECL;yyval->addChild(yyvsp[-1]);yyval->addChild(yyvsp[0]);}
#line 1703 "src/main.tab.cpp"
    break;

  case 36:
#line 127 "src/main.y"
                                                  {yyvsp[-2]->addsibLing(yyvsp[0]);yyval = yyvsp[-2];}
#line 1709 "src/main.tab.cpp"
    break;

  case 37:
#line 128 "src/main.y"
                         {yyval = yyvsp[0];}
#line 1715 "src/main.tab.cpp"
    break;

  case 38:
#line 131 "src/main.y"
                                {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_ASSIGN; yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1721 "src/main.tab.cpp"
    break;

  case 39:
#line 132 "src/main.y"
                                     {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_ASSIGN;yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1727 "src/main.tab.cpp"
    break;

  case 40:
#line 133 "src/main.y"
          {yyval = yyvsp[0];}
#line 1733 "src/main.tab.cpp"
    break;

  case 41:
#line 134 "src/main.y"
               {yyval = yyvsp[0];}
#line 1739 "src/main.tab.cpp"
    break;

  case 42:
#line 138 "src/main.y"
                                     {yyvsp[-2]->addsibLing(yyvsp[0]);}
#line 1745 "src/main.tab.cpp"
    break;

  case 43:
#line 139 "src/main.y"
                  {yyval = yyvsp[0];}
#line 1751 "src/main.tab.cpp"
    break;

  case 44:
#line 142 "src/main.y"
                                 {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_ASSIGN;yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1757 "src/main.tab.cpp"
    break;

  case 45:
#line 143 "src/main.y"
              {yyval = yyvsp[0];}
#line 1763 "src/main.tab.cpp"
    break;

  case 46:
#line 156 "src/main.y"
                {yyval = yyvsp[0];}
#line 1769 "src/main.tab.cpp"
    break;

  case 47:
#line 157 "src/main.y"
                                      {yyval = yyvsp[-3];yyval->array = true; yyval->array_length[0] = yyvsp[-1]->int_val;}
#line 1775 "src/main.tab.cpp"
    break;

  case 48:
#line 158 "src/main.y"
                                    {yyval = yyvsp[-3];yyval->array_length[yyval->dim_num++]=yyvsp[-1]->int_val;}
#line 1781 "src/main.tab.cpp"
    break;

  case 49:
#line 162 "src/main.y"
                             {yyval = yyvsp[-1];}
#line 1787 "src/main.tab.cpp"
    break;

  case 50:
#line 163 "src/main.y"
                  {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_EQ;yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1793 "src/main.tab.cpp"
    break;

  case 51:
#line 164 "src/main.y"
                  {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_NE;yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1799 "src/main.tab.cpp"
    break;

  case 52:
#line 165 "src/main.y"
                  {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_GE;yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1805 "src/main.tab.cpp"
    break;

  case 53:
#line 166 "src/main.y"
                  {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_LE;yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1811 "src/main.tab.cpp"
    break;

  case 54:
#line 167 "src/main.y"
                  {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_LT;yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1817 "src/main.tab.cpp"
    break;

  case 55:
#line 168 "src/main.y"
                  {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_GT;yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1823 "src/main.tab.cpp"
    break;

  case 56:
#line 169 "src/main.y"
                                 {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_LOG_AND;yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1829 "src/main.tab.cpp"
    break;

  case 57:
#line 170 "src/main.y"
                                {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_LOG_OR;yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1835 "src/main.tab.cpp"
    break;

  case 58:
#line 171 "src/main.y"
                   {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_NOT;yyval->addChild(yyvsp[0]);}
#line 1841 "src/main.tab.cpp"
    break;

  case 59:
#line 175 "src/main.y"
                                 {yyval = yyvsp[-2];yyval->addsibLing(yyvsp[0]);}
#line 1847 "src/main.tab.cpp"
    break;

  case 60:
#line 176 "src/main.y"
                {yyval = yyvsp[0];}
#line 1853 "src/main.tab.cpp"
    break;

  case 61:
#line 179 "src/main.y"
                {yyval = yyvsp[0];}
#line 1859 "src/main.tab.cpp"
    break;

  case 62:
#line 180 "src/main.y"
                             {yyval = yyvsp[-1];}
#line 1865 "src/main.tab.cpp"
    break;

  case 63:
#line 181 "src/main.y"
                                  {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_ARRAY_NUM;yyval->addChild(yyvsp[-3]);yyval->addChild(yyvsp[-1]);}
#line 1871 "src/main.tab.cpp"
    break;

  case 64:
#line 182 "src/main.y"
                                {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_STRUCT_MEMBER;yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1877 "src/main.tab.cpp"
    break;

  case 65:
#line 187 "src/main.y"
             {yyval = yyvsp[0];}
#line 1883 "src/main.tab.cpp"
    break;

  case 66:
#line 188 "src/main.y"
               {yyval = yyvsp[0];}
#line 1889 "src/main.tab.cpp"
    break;

  case 67:
#line 189 "src/main.y"
                                          {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_FUNC;yyval->func_name = yyvsp[-3]->variable_name;yyval->addChild(yyvsp[-1]);}
#line 1895 "src/main.tab.cpp"
    break;

  case 68:
#line 190 "src/main.y"
                        {yyval = yyvsp[-1];}
#line 1901 "src/main.tab.cpp"
    break;

  case 69:
#line 191 "src/main.y"
                   {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_MOD;yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1907 "src/main.tab.cpp"
    break;

  case 70:
#line 192 "src/main.y"
                   {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_MUL;yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1913 "src/main.tab.cpp"
    break;

  case 71:
#line 193 "src/main.y"
                   {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_DIV;yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1919 "src/main.tab.cpp"
    break;

  case 72:
#line 194 "src/main.y"
                   {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_ADD;yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1925 "src/main.tab.cpp"
    break;

  case 73:
#line 195 "src/main.y"
                   {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_SUB;yyval->addChild(yyvsp[-2]);yyval->addChild(yyvsp[0]);}
#line 1931 "src/main.tab.cpp"
    break;

  case 74:
#line 196 "src/main.y"
                        {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_NEG;yyval->addChild(yyvsp[0]);}
#line 1937 "src/main.tab.cpp"
    break;

  case 75:
#line 197 "src/main.y"
                        {yyval = new TreeNode(lineno, NODE_EXPR);yyval->operatorType = OP_POS;yyval->addChild(yyvsp[0]);}
#line 1943 "src/main.tab.cpp"
    break;

  case 76:
#line 201 "src/main.y"
          {yyval = yyvsp[0];}
#line 1949 "src/main.tab.cpp"
    break;

  case 77:
#line 202 "src/main.y"
               {yyval = yyvsp[0];}
#line 1955 "src/main.tab.cpp"
    break;

  case 78:
#line 203 "src/main.y"
                                 {yyval = yyvsp[-2];yyval->addsibLing(yyvsp[0]);}
#line 1961 "src/main.tab.cpp"
    break;

  case 79:
#line 204 "src/main.y"
                            {yyval = yyvsp[-2];yyval->addsibLing(yyvsp[0]);}
#line 1967 "src/main.tab.cpp"
    break;

  case 80:
#line 209 "src/main.y"
           {
        yyval = new TreeNode(lineno, NODE_TYPE);yyval->type = TYPE_INT;
    }
#line 1975 "src/main.tab.cpp"
    break;

  case 81:
#line 212 "src/main.y"
            {
        yyval = new TreeNode(lineno, NODE_TYPE);yyval->type = TYPE_CHAR;
    }
#line 1983 "src/main.tab.cpp"
    break;

  case 82:
#line 215 "src/main.y"
            {
        yyval = new TreeNode(lineno, NODE_TYPE);yyval->type = TYPE_VOID;
    }
#line 1991 "src/main.tab.cpp"
    break;

  case 83:
#line 218 "src/main.y"
              {
        yyval = new TreeNode(lineno, NODE_TYPE);yyval->type = TYPE_STRING;
    }
#line 1999 "src/main.tab.cpp"
    break;

  case 84:
#line 221 "src/main.y"
                         {
        yyval = new TreeNode(lineno, NODE_TYPE);yyval->type = TYPE_STRUCT;
    }
#line 2007 "src/main.tab.cpp"
    break;


#line 2011 "src/main.tab.cpp"

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
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
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
                      yytoken, &yylval);
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
                  yystos[yystate], yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
#line 225 "src/main.y"


int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
