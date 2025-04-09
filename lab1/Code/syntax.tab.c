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
#line 1 "./bison.y"

#include "syn_tree.h"
#include <stdio.h>
#include "lex.yy.c"
// extern int yylex();
// extern void yyrestart(FILE *input_file);
// extern int yylineno;
// extern bool flex_has_error;
// extern bool is_flex_error[9999];
void yyerror(const char *s);
extern Node* root;
bool bison_has_error = 0;

#line 84 "./syntax.tab.c"

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
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
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
    FLOAT = 258,
    INT = 259,
    TYPE = 260,
    STRUCT = 261,
    RETURN = 262,
    IF = 263,
    ELSE = 264,
    WHILE = 265,
    ID = 266,
    SEMI = 267,
    COMMA = 268,
    ASSIGNOP = 269,
    RELOP = 270,
    PLUS = 271,
    MINUS = 272,
    STAR = 273,
    DIV = 274,
    AND = 275,
    OR = 276,
    DOT = 277,
    NOT = 278,
    LP = 279,
    RP = 280,
    LB = 281,
    RB = 282,
    LC = 283,
    RC = 284,
    UMINUS = 285,
    LOWER_THAN_ELSE = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "./bison.y"

    Node* node_ins;

#line 172 "./syntax.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */



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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   947

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  177

#define YYUNDEFTOK  2
#define YYMAXUTOK   286


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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    63,    63,    71,    75,    81,    85,    89,    93,    94,
      95,    99,   103,   107,   108,   112,   116,   123,   127,   134,
     138,   144,   151,   155,   159,   160,   164,   168,   172,   173,
     177,   181,   185,   186,   190,   197,   201,   205,   209,   212,
     216,   220,   224,   228,   232,   236,   240,   241,   249,   256,
     257,   258,   262,   266,   269,   273,   277,   278,   279,   283,
     287,   291,   295,   299,   303,   307,   311,   315,   319,   323,
     327,   331,   335,   339,   343,   347,   351,   355,   359,   363,
     367,   371,   375,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   397,   401,   405
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FLOAT", "INT", "TYPE", "STRUCT",
  "RETURN", "IF", "ELSE", "WHILE", "ID", "SEMI", "COMMA", "ASSIGNOP",
  "RELOP", "PLUS", "MINUS", "STAR", "DIV", "AND", "OR", "DOT", "NOT", "LP",
  "RP", "LB", "RB", "LC", "RC", "UMINUS", "LOWER_THAN_ELSE", "$accept",
  "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "OptTag", "Tag", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
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
     285,   286
};
# endif

#define YYPACT_NINF (-125)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-99)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     111,   170,  -125,    -8,     8,  -125,   111,   155,  -125,    18,
      26,    31,    54,   115,  -125,  -125,  -125,   168,    97,  -125,
      42,   126,    31,    61,   145,  -125,    66,  -125,    34,    77,
    -125,  -125,  -125,    77,    77,    56,  -125,  -125,   119,  -125,
      73,   120,     1,    96,   107,   212,   125,   154,   118,  -125,
    -125,   113,   136,  -125,   146,  -125,    16,    16,  -125,    67,
    -125,   173,    11,   180,    24,   183,  -125,  -125,   794,   156,
      29,   174,   798,   809,   824,  -125,   172,   212,   682,  -125,
    -125,  -125,   176,  -125,  -125,  -125,   214,  -125,    73,    73,
    -125,  -125,  -125,  -125,  -125,   187,   704,   214,   112,   214,
     783,  -125,   241,  -125,   269,   179,   726,  -125,  -125,   214,
    -125,   833,   842,   851,   860,   869,   878,   887,   896,   194,
     905,  -125,   638,  -125,  -125,  -125,   214,  -125,   748,  -125,
    -125,   575,   189,  -125,   660,   196,  -125,  -125,   297,  -125,
     325,  -125,   353,  -125,   381,  -125,   409,  -125,   437,  -125,
     465,  -125,   493,  -125,   521,  -125,   197,   616,   601,   185,
     914,   601,  -125,  -125,   923,  -125,  -125,  -125,   198,   217,
     768,   549,  -125,  -125,  -125,   601,  -125
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    15,    20,     0,     2,     0,     0,    16,     0,
       0,     0,    21,     0,    18,     1,     3,     0,     0,     6,
       0,     0,     0,     0,     0,     9,     0,    10,     0,     0,
      22,    14,     5,     0,     0,     0,     7,    28,     0,    27,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      12,     0,     0,    29,    34,    26,    33,     0,    36,     0,
      54,     0,     0,     0,     0,     0,    82,    81,     0,     0,
       0,    80,     0,     0,     0,    41,     0,     0,     0,    52,
      17,    25,    23,    32,    30,    64,     0,    56,     0,     0,
      58,    57,    55,    51,    39,     0,     0,     0,     0,     0,
       0,    84,     0,    86,     0,     0,     0,    35,    37,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,     0,    61,    60,    50,    49,    42,     0,    46,
      47,     0,     0,    77,     0,     0,    83,    73,     0,    88,
       0,    91,     0,    92,     0,    93,     0,    94,     0,    95,
       0,    89,     0,    90,     0,    79,     0,     0,     0,     0,
       0,     0,    48,    85,     0,    76,    87,    78,     0,    43,
      84,     0,    45,    99,    97,     0,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -125,  -125,   221,  -125,    -6,     9,  -125,  -125,  -125,   -27,
     223,    58,  -125,    53,    57,  -124,    59,  -125,   -33,  -125,
     -68,    64
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    31,    44,     8,    13,    14,    21,
      11,    41,    42,    75,    76,    77,    60,    46,    61,    62,
      78,   135
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      96,    20,    56,    12,   102,   104,   106,   162,    15,     7,
      10,    64,    88,    54,    57,     7,    59,    59,   122,    23,
      59,     2,     3,   -59,    89,    91,   -31,    49,    50,   128,
      98,   131,   134,    40,   169,    47,    92,   172,    25,     2,
       3,   138,    24,   140,   142,   144,   146,   148,   150,   152,
     154,   176,   157,    99,    32,   123,   124,    51,   138,    26,
      52,    59,    59,   -53,    27,    40,    40,    43,    85,   -53,
     -53,     2,     3,   -53,   -53,    36,   -53,   -53,    29,   -62,
     -62,    86,   -19,   -53,    30,    45,    37,    48,    30,   -53,
     -53,   138,   171,    35,   -53,   -53,   134,    47,    23,   -53,
     -53,     2,     3,   -53,   -53,    79,   -53,    30,    63,   -22,
     -22,    -4,     1,   -53,    83,    84,     2,     3,    30,   -53,
     -53,    24,    94,   -22,   -53,    58,    47,    33,   -53,   -53,
       2,     3,   -53,   -53,   108,   -53,   -53,   129,   -11,    34,
      81,   130,   -53,    28,    53,    55,    38,    80,   -53,   -53,
       2,     3,    35,   -53,   -53,    47,    17,   -53,   -53,     2,
       3,   -53,   -53,    82,   -53,    30,    18,    19,    -8,    29,
      39,   -53,    35,    -8,    -8,     2,     3,   -53,   -53,    30,
      97,     9,   -53,   -53,    65,    87,    66,    67,    66,    67,
      68,    69,    90,    70,    71,    93,    71,    93,   100,   125,
      72,   107,    72,   121,   136,   155,    73,    74,    73,    74,
      93,    26,   -38,    65,   163,    66,    67,    66,    67,    68,
      69,   165,    70,    71,   166,    71,   175,    16,   174,    72,
      22,    72,     0,     0,     0,    73,    74,    73,    74,     0,
      26,   -38,   109,     0,   -74,   -74,     0,     0,   -74,   -74,
       0,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   119,   -74,   -74,   -74,   120,   -74,   -74,
     109,     0,   -75,   -75,     0,     0,   -75,   -75,     0,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   119,   -75,   -75,   -75,   120,   -75,   -75,   109,     0,
     -96,   -96,     0,     0,   -96,   -96,     0,   -96,   -96,   -96,
     -96,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     -96,   -96,   -96,   120,   -96,   -96,   109,     0,   -65,   -65,
       0,     0,   -65,   -65,     0,   -65,   -65,   -65,   -65,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   -65,   -65,
     -65,   120,   -65,   -65,   109,     0,   -68,   -68,     0,     0,
     -68,   -68,     0,   -68,   -68,   -68,   -68,   -68,   -68,   113,
     114,   115,   116,   -68,   -68,   119,   -68,   -68,   -68,   120,
     -68,   -68,   109,     0,   -69,   -69,     0,     0,   -69,   -69,
       0,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   115,
     116,   -69,   -69,   119,   -69,   -69,   -69,   120,   -69,   -69,
     109,     0,   -70,   -70,     0,     0,   -70,   -70,     0,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   115,   116,   -70,
     -70,   119,   -70,   -70,   -70,   120,   -70,   -70,   109,     0,
     -71,   -71,     0,     0,   -71,   -71,     0,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   119,
     -71,   -71,   -71,   120,   -71,   -71,   109,     0,   -72,   -72,
       0,     0,   -72,   -72,     0,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   119,   -72,   -72,
     -72,   120,   -72,   -72,   109,     0,   -66,   -66,     0,     0,
     -66,   -66,     0,   -66,   -66,   -66,   -66,   -66,   112,   113,
     114,   115,   116,   -66,   -66,   119,   -66,   -66,   -66,   120,
     -66,   -66,   109,     0,   -67,   -67,     0,     0,   -67,   -67,
       0,   -67,   -67,   -67,   -67,   -67,   112,   113,   114,   115,
     116,   117,   -67,   119,   -67,   -67,   -67,   120,   -67,   -67,
     109,     0,   -70,   -70,     0,     0,   -70,   -70,     0,   -70,
     -70,   -74,     0,   -70,   -70,   -70,   -70,   -74,   -74,   -70,
     -70,   119,   -70,   -70,   -70,   120,   159,   -70,    66,    67,
       0,     0,    68,    69,     0,    70,    71,     0,     0,   111,
     112,   113,   160,   115,   116,   117,   118,   119,    73,    74,
     161,   120,   168,    26,    66,    67,     0,     0,    68,    69,
       0,    70,    71,     0,     0,     0,     0,   109,    72,     0,
       0,     0,     0,     0,    73,    74,     0,     0,     0,    26,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   109,
       0,     0,   120,   167,     0,     0,     0,     0,     0,     0,
     -63,   -63,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   109,     0,     0,   120,     0,     0,     0,     0,     0,
       0,     0,     0,   164,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   109,     0,   -98,   120,     0,     0,     0,
       0,     0,     0,     0,   110,     0,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   126,     0,     0,   120,     0,
       0,     0,     0,     0,     0,     0,   127,     0,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   109,     0,     0,
     120,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   109,
       0,   137,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   -93,   -93,   158,   120,   -93,   -93,     0,   -93,   -93,
       0,     0,     0,     0,   132,     0,    66,    67,     0,     0,
       0,   -93,   -93,   -93,    71,    95,   -93,    66,    67,   101,
      72,    66,    67,     0,     0,    71,    73,    74,   133,    71,
     103,    72,    66,    67,     0,    72,     0,    73,    74,     0,
      71,    73,    74,     0,     0,   105,    72,    66,    67,     0,
       0,     0,    73,    74,   139,    71,    66,    67,     0,     0,
       0,    72,     0,   141,    71,    66,    67,    73,    74,     0,
      72,     0,   143,    71,    66,    67,    73,    74,     0,    72,
       0,   145,    71,    66,    67,    73,    74,     0,    72,     0,
     147,    71,    66,    67,    73,    74,     0,    72,     0,   149,
      71,    66,    67,    73,    74,     0,    72,     0,   151,    71,
      66,    67,    73,    74,     0,    72,     0,   153,    71,    66,
      67,    73,    74,     0,    72,     0,   156,    71,    66,    67,
      73,    74,     0,    72,     0,   170,    71,    66,    67,    73,
      74,     0,    72,     0,   173,    71,    66,    67,    73,    74,
       0,    72,     0,     0,    71,     0,     0,    73,    74,     0,
      72,     0,     0,     0,     0,     0,    73,    74
};

static const yytype_int16 yycheck[] =
{
      68,     7,     1,    11,    72,    73,    74,   131,     0,     0,
       1,    44,     1,    40,    13,     6,    43,    44,    86,     1,
      47,     5,     6,    12,    13,     1,    25,    33,    34,    97,
       1,    99,   100,    24,   158,     1,    12,   161,    12,     5,
       6,   109,    24,   111,   112,   113,   114,   115,   116,   117,
     118,   175,   120,    24,    12,    88,    89,     1,   126,    28,
       4,    88,    89,    29,    11,    56,    57,     1,     1,     3,
       4,     5,     6,     7,     8,    22,    10,    11,     1,    12,
      13,    14,    28,    17,    11,    26,    25,    28,    11,    23,
      24,   159,   160,    26,    28,    29,   164,     1,     1,     3,
       4,     5,     6,     7,     8,    46,    10,    11,     1,    12,
      13,     0,     1,    17,    56,    57,     5,     6,    11,    23,
      24,    24,    65,    26,    28,    29,     1,     1,     3,     4,
       5,     6,     7,     8,    77,    10,    11,    25,    12,    13,
      27,    29,    17,    28,    25,    25,     1,    29,    23,    24,
       5,     6,    26,    28,    29,     1,     1,     3,     4,     5,
       6,     7,     8,    27,    10,    11,    11,    12,     0,     1,
      25,    17,    26,     5,     6,     5,     6,    23,    24,    11,
      24,    11,    28,    29,     1,    12,     3,     4,     3,     4,
       7,     8,    12,    10,    11,    12,    11,    12,    24,    12,
      17,    29,    17,    27,    25,    11,    23,    24,    23,    24,
      12,    28,    29,     1,    25,     3,     4,     3,     4,     7,
       8,    25,    10,    11,    27,    11,     9,     6,   164,    17,
       7,    17,    -1,    -1,    -1,    23,    24,    23,    24,    -1,
      28,    29,     1,    -1,     3,     4,    -1,    -1,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       1,    -1,     3,     4,    -1,    -1,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     1,    -1,
       3,     4,    -1,    -1,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     1,    -1,     3,     4,
      -1,    -1,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     1,    -1,     3,     4,    -1,    -1,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     1,    -1,     3,     4,    -1,    -1,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       1,    -1,     3,     4,    -1,    -1,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     1,    -1,
       3,     4,    -1,    -1,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     1,    -1,     3,     4,
      -1,    -1,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     1,    -1,     3,     4,    -1,    -1,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     1,    -1,     3,     4,    -1,    -1,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       1,    -1,     3,     4,    -1,    -1,     7,     8,    -1,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     1,    28,     3,     4,
      -1,    -1,     7,     8,    -1,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     1,    28,     3,     4,    -1,    -1,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,     1,    17,    -1,
      -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    28,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     1,
      -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,     1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     1,    -1,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     1,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,     1,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     1,
      -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,     3,     4,    25,    26,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,    -1,    -1,
      -1,    23,    24,    25,    11,     1,    28,     3,     4,     1,
      17,     3,     4,    -1,    -1,    11,    23,    24,    25,    11,
       1,    17,     3,     4,    -1,    17,    -1,    23,    24,    -1,
      11,    23,    24,    -1,    -1,     1,    17,     3,     4,    -1,
      -1,    -1,    23,    24,     1,    11,     3,     4,    -1,    -1,
      -1,    17,    -1,     1,    11,     3,     4,    23,    24,    -1,
      17,    -1,     1,    11,     3,     4,    23,    24,    -1,    17,
      -1,     1,    11,     3,     4,    23,    24,    -1,    17,    -1,
       1,    11,     3,     4,    23,    24,    -1,    17,    -1,     1,
      11,     3,     4,    23,    24,    -1,    17,    -1,     1,    11,
       3,     4,    23,    24,    -1,    17,    -1,     1,    11,     3,
       4,    23,    24,    -1,    17,    -1,     1,    11,     3,     4,
      23,    24,    -1,    17,    -1,     1,    11,     3,     4,    23,
      24,    -1,    17,    -1,     1,    11,     3,     4,    23,    24,
      -1,    17,    -1,    -1,    11,    -1,    -1,    23,    24,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    23,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     5,     6,    33,    34,    35,    37,    38,    11,
      37,    42,    11,    39,    40,     0,    34,     1,    11,    12,
      36,    41,    42,     1,    24,    12,    28,    45,    28,     1,
      11,    36,    12,     1,    13,    26,    45,    25,     1,    25,
      37,    43,    44,     1,    37,    48,    49,     1,    48,    36,
      36,     1,     4,    25,    41,    25,     1,    13,    29,    41,
      48,    50,    51,     1,    50,     1,     3,     4,     7,     8,
      10,    11,    17,    23,    24,    45,    46,    47,    52,    48,
      29,    27,    27,    43,    43,     1,    14,    12,     1,    13,
      12,     1,    12,    12,    46,     1,    52,    24,     1,    24,
      24,     1,    52,     1,    52,     1,    52,    29,    46,     1,
      12,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      26,    27,    52,    50,    50,    12,     1,    12,    52,    25,
      29,    52,     1,    25,    52,    53,    25,    25,    52,     1,
      52,     1,    52,     1,    52,     1,    52,     1,    52,     1,
      52,     1,    52,     1,    52,    11,     1,    52,    25,     1,
      17,    25,    47,    25,    13,    25,    27,    27,     1,    47,
       1,    52,    47,     1,    53,     9,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    35,
      35,    36,    36,    36,    36,    37,    37,    38,    38,    39,
      39,    40,    41,    41,    41,    41,    42,    42,    42,    42,
      43,    43,    43,    43,    44,    45,    45,    46,    46,    46,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    48,    48,    48,    49,    49,    49,    49,    50,
      50,    50,    51,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    53,    53,    53
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     2,     3,
       3,     1,     3,     3,     2,     1,     1,     5,     2,     1,
       0,     1,     1,     4,     5,     4,     4,     3,     3,     4,
       3,     1,     3,     2,     2,     4,     3,     2,     0,     2,
       2,     1,     3,     5,     7,     5,     3,     3,     4,     3,
       3,     2,     2,     0,     2,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     4,     3,     4,     3,
       1,     1,     1,     3,     2,     4,     2,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 63 "./bison.y"
          {
    (yyval.node_ins) = create_node("Program", UNTERMINAL, "\0", (yyloc).first_line);
    set_root((yyval.node_ins));
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 1732 "./syntax.tab.c"
    break;

  case 3:
#line 71 "./bison.y"
                 {
    (yyval.node_ins) = create_node("ExtDefList", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 2, (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1741 "./syntax.tab.c"
    break;

  case 4:
#line 75 "./bison.y"
              {
    (yyval.node_ins) = NULL;
}
#line 1749 "./syntax.tab.c"
    break;

  case 5:
#line 81 "./bison.y"
                         {
    (yyval.node_ins) = create_node("ExtDef", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1758 "./syntax.tab.c"
    break;

  case 6:
#line 85 "./bison.y"
                {
    (yyval.node_ins) = create_node("ExtDef", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 2, (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1767 "./syntax.tab.c"
    break;

  case 7:
#line 89 "./bison.y"
                         {
    (yyval.node_ins) = create_node("ExtDef", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1776 "./syntax.tab.c"
    break;

  case 8:
#line 93 "./bison.y"
                 {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid ExtDef1\n");}
#line 1782 "./syntax.tab.c"
    break;

  case 9:
#line 94 "./bison.y"
                      {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid ExtDef2\n");}
#line 1788 "./syntax.tab.c"
    break;

  case 10:
#line 95 "./bison.y"
                     {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid ExtDef3\n");}
#line 1794 "./syntax.tab.c"
    break;

  case 11:
#line 99 "./bison.y"
      {
    (yyval.node_ins) = create_node("ExtDecList", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 1803 "./syntax.tab.c"
    break;

  case 12:
#line 103 "./bison.y"
                         {
    (yyval.node_ins) = create_node("ExtDecList", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1812 "./syntax.tab.c"
    break;

  case 13:
#line 107 "./bison.y"
                         {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid ExtDecList1\n");}
#line 1818 "./syntax.tab.c"
    break;

  case 14:
#line 108 "./bison.y"
                  {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid ExtDecList2\n");}
#line 1824 "./syntax.tab.c"
    break;

  case 15:
#line 112 "./bison.y"
    {
    (yyval.node_ins) = create_node("Specifier", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 1833 "./syntax.tab.c"
    break;

  case 16:
#line 116 "./bison.y"
                 {
    (yyval.node_ins) = create_node("Specifier", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 1842 "./syntax.tab.c"
    break;

  case 17:
#line 123 "./bison.y"
                           {
    (yyval.node_ins) = create_node("StructSpecifier", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 5, (yyvsp[-4].node_ins), (yyvsp[-3].node_ins), (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1851 "./syntax.tab.c"
    break;

  case 18:
#line 127 "./bison.y"
            {
    (yyval.node_ins) = create_node("StructSpecifier", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 2, (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1860 "./syntax.tab.c"
    break;

  case 19:
#line 134 "./bison.y"
  {
    (yyval.node_ins) = create_node("OptTag", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 1869 "./syntax.tab.c"
    break;

  case 20:
#line 138 "./bison.y"
              {
    (yyval.node_ins) = NULL;
}
#line 1877 "./syntax.tab.c"
    break;

  case 21:
#line 144 "./bison.y"
  {
    (yyval.node_ins) = create_node("Tag", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 1886 "./syntax.tab.c"
    break;

  case 22:
#line 151 "./bison.y"
  {
    (yyval.node_ins) = create_node("VarDec", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 1895 "./syntax.tab.c"
    break;

  case 23:
#line 155 "./bison.y"
                  {
    (yyval.node_ins) = create_node("VarDec", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 4, (yyvsp[-3].node_ins), (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1904 "./syntax.tab.c"
    break;

  case 24:
#line 159 "./bison.y"
                     {yyerror("syntax error");(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid VarDec1\n");}
#line 1910 "./syntax.tab.c"
    break;

  case 25:
#line 160 "./bison.y"
                    {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid VarDec2\n");}
#line 1916 "./syntax.tab.c"
    break;

  case 26:
#line 164 "./bison.y"
                {
    (yyval.node_ins) = create_node("FunDec", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 4, (yyvsp[-3].node_ins), (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1925 "./syntax.tab.c"
    break;

  case 27:
#line 168 "./bison.y"
          {
    (yyval.node_ins) = create_node("FunDec", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1934 "./syntax.tab.c"
    break;

  case 28:
#line 172 "./bison.y"
             {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid FunDec1\n");}
#line 1940 "./syntax.tab.c"
    break;

  case 29:
#line 173 "./bison.y"
                {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid FunDec2\n");}
#line 1946 "./syntax.tab.c"
    break;

  case 30:
#line 177 "./bison.y"
                      {
    (yyval.node_ins) = create_node("VarList", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1955 "./syntax.tab.c"
    break;

  case 31:
#line 181 "./bison.y"
          {
    (yyval.node_ins) = create_node("VarList", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 1964 "./syntax.tab.c"
    break;

  case 32:
#line 185 "./bison.y"
                        {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid VarList1\n");}
#line 1970 "./syntax.tab.c"
    break;

  case 33:
#line 186 "./bison.y"
                {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid VarList2\n");}
#line 1976 "./syntax.tab.c"
    break;

  case 34:
#line 190 "./bison.y"
                {
    (yyval.node_ins) = create_node("ParamDec", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 2, (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1985 "./syntax.tab.c"
    break;

  case 35:
#line 197 "./bison.y"
                      {
    (yyval.node_ins) = create_node("CompSt", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 4, (yyvsp[-3].node_ins), (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1994 "./syntax.tab.c"
    break;

  case 36:
#line 201 "./bison.y"
             {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Compst\n");}
#line 2000 "./syntax.tab.c"
    break;

  case 37:
#line 205 "./bison.y"
             {
    (yyval.node_ins) = create_node("StmtList", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 2, (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2009 "./syntax.tab.c"
    break;

  case 38:
#line 209 "./bison.y"
              {
    (yyval.node_ins) = NULL;
}
#line 2017 "./syntax.tab.c"
    break;

  case 39:
#line 212 "./bison.y"
                {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid StmtList\n");}
#line 2023 "./syntax.tab.c"
    break;

  case 40:
#line 216 "./bison.y"
        {
    (yyval.node_ins) = create_node("Stmt", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 2, (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2032 "./syntax.tab.c"
    break;

  case 41:
#line 220 "./bison.y"
        {
    (yyval.node_ins) = create_node("Stmt", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 2041 "./syntax.tab.c"
    break;

  case 42:
#line 224 "./bison.y"
                 {
    (yyval.node_ins) = create_node("Stmt", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2050 "./syntax.tab.c"
    break;

  case 43:
#line 228 "./bison.y"
                                         {
    (yyval.node_ins) = create_node("Stmt", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 5, (yyvsp[-4].node_ins), (yyvsp[-3].node_ins), (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2059 "./syntax.tab.c"
    break;

  case 44:
#line 232 "./bison.y"
                             {
    (yyval.node_ins) = create_node("Stmt", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 7, (yyvsp[-6].node_ins), (yyvsp[-5].node_ins), (yyvsp[-4].node_ins), (yyvsp[-3].node_ins), (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2068 "./syntax.tab.c"
    break;

  case 45:
#line 236 "./bison.y"
                      {
    (yyval.node_ins) = create_node("Stmt", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 5, (yyvsp[-4].node_ins), (yyvsp[-3].node_ins), (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2077 "./syntax.tab.c"
    break;

  case 46:
#line 240 "./bison.y"
                {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Stmt1\n");}
#line 2083 "./syntax.tab.c"
    break;

  case 47:
#line 241 "./bison.y"
                {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Stmt2\n");}
#line 2089 "./syntax.tab.c"
    break;

  case 48:
#line 249 "./bison.y"
                   {
    if(!is_flex_error[yylineno]){
        printf("Error type B at Line %d: syntax error, ", (yylsp[-3]).first_line);
        bison_has_error = 1;
    }
    (yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Stmt4\n");
}
#line 2101 "./syntax.tab.c"
    break;

  case 49:
#line 256 "./bison.y"
                  {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Stmt5\n");}
#line 2107 "./syntax.tab.c"
    break;

  case 50:
#line 257 "./bison.y"
                   {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Stmt6\n");}
#line 2113 "./syntax.tab.c"
    break;

  case 51:
#line 258 "./bison.y"
            {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Stmt7\n");}
#line 2119 "./syntax.tab.c"
    break;

  case 52:
#line 262 "./bison.y"
           {
    (yyval.node_ins) = create_node("DefList", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 2, (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2128 "./syntax.tab.c"
    break;

  case 53:
#line 266 "./bison.y"
              {
    (yyval.node_ins) = NULL;
}
#line 2136 "./syntax.tab.c"
    break;

  case 54:
#line 269 "./bison.y"
               {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid DefList\n");}
#line 2142 "./syntax.tab.c"
    break;

  case 55:
#line 273 "./bison.y"
                      {
    (yyval.node_ins) = create_node("Def", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2151 "./syntax.tab.c"
    break;

  case 56:
#line 277 "./bison.y"
                    {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Def1\n");}
#line 2157 "./syntax.tab.c"
    break;

  case 57:
#line 278 "./bison.y"
                         {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Def2\n");}
#line 2163 "./syntax.tab.c"
    break;

  case 58:
#line 279 "./bison.y"
                      {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Def3\n");}
#line 2169 "./syntax.tab.c"
    break;

  case 59:
#line 283 "./bison.y"
   {
    (yyval.node_ins) = create_node("DecList", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 2178 "./syntax.tab.c"
    break;

  case 60:
#line 287 "./bison.y"
                   {
    (yyval.node_ins) = create_node("DecList", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2187 "./syntax.tab.c"
    break;

  case 61:
#line 291 "./bison.y"
                   {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid DecList\n");}
#line 2193 "./syntax.tab.c"
    break;

  case 62:
#line 295 "./bison.y"
      {
    (yyval.node_ins) = create_node("Dec", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 2202 "./syntax.tab.c"
    break;

  case 63:
#line 299 "./bison.y"
                     {
    (yyval.node_ins) = create_node("Dec", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2211 "./syntax.tab.c"
    break;

  case 64:
#line 303 "./bison.y"
             {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Dec\n");}
#line 2217 "./syntax.tab.c"
    break;

  case 65:
#line 307 "./bison.y"
                {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2226 "./syntax.tab.c"
    break;

  case 66:
#line 311 "./bison.y"
             {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2235 "./syntax.tab.c"
    break;

  case 67:
#line 315 "./bison.y"
            {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2244 "./syntax.tab.c"
    break;

  case 68:
#line 319 "./bison.y"
               {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2253 "./syntax.tab.c"
    break;

  case 69:
#line 323 "./bison.y"
              {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2262 "./syntax.tab.c"
    break;

  case 70:
#line 327 "./bison.y"
               {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2271 "./syntax.tab.c"
    break;

  case 71:
#line 331 "./bison.y"
              {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2280 "./syntax.tab.c"
    break;

  case 72:
#line 335 "./bison.y"
             {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2289 "./syntax.tab.c"
    break;

  case 73:
#line 339 "./bison.y"
           {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2298 "./syntax.tab.c"
    break;

  case 74:
#line 343 "./bison.y"
                        {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 2, (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2307 "./syntax.tab.c"
    break;

  case 75:
#line 347 "./bison.y"
         {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 2, (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2316 "./syntax.tab.c"
    break;

  case 76:
#line 351 "./bison.y"
               {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 4, (yyvsp[-3].node_ins), (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2325 "./syntax.tab.c"
    break;

  case 77:
#line 355 "./bison.y"
          {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2334 "./syntax.tab.c"
    break;

  case 78:
#line 359 "./bison.y"
               {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 4, (yyvsp[-3].node_ins), (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2343 "./syntax.tab.c"
    break;

  case 79:
#line 363 "./bison.y"
            {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2352 "./syntax.tab.c"
    break;

  case 80:
#line 367 "./bison.y"
    {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 2361 "./syntax.tab.c"
    break;

  case 81:
#line 371 "./bison.y"
     {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 2370 "./syntax.tab.c"
    break;

  case 82:
#line 375 "./bison.y"
       {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 2379 "./syntax.tab.c"
    break;

  case 83:
#line 379 "./bison.y"
             {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Exp1\n");}
#line 2385 "./syntax.tab.c"
    break;

  case 84:
#line 380 "./bison.y"
             {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Exp2\n");}
#line 2391 "./syntax.tab.c"
    break;

  case 85:
#line 381 "./bison.y"
                {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Exp3\n");}
#line 2397 "./syntax.tab.c"
    break;

  case 86:
#line 382 "./bison.y"
           {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Exp4\n");}
#line 2403 "./syntax.tab.c"
    break;

  case 87:
#line 383 "./bison.y"
                 {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Exp5\n");}
#line 2409 "./syntax.tab.c"
    break;

  case 88:
#line 384 "./bison.y"
                    {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Exp6\n");}
#line 2415 "./syntax.tab.c"
    break;

  case 89:
#line 385 "./bison.y"
               {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Exp7\n");}
#line 2421 "./syntax.tab.c"
    break;

  case 90:
#line 386 "./bison.y"
              {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Exp8\n");}
#line 2427 "./syntax.tab.c"
    break;

  case 91:
#line 387 "./bison.y"
                 {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Exp9\n");}
#line 2433 "./syntax.tab.c"
    break;

  case 92:
#line 388 "./bison.y"
                {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Exp10\n");}
#line 2439 "./syntax.tab.c"
    break;

  case 93:
#line 389 "./bison.y"
                 {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Exp11\n");}
#line 2445 "./syntax.tab.c"
    break;

  case 94:
#line 390 "./bison.y"
                {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Exp12\n");}
#line 2451 "./syntax.tab.c"
    break;

  case 95:
#line 391 "./bison.y"
               {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Exp13\n");}
#line 2457 "./syntax.tab.c"
    break;

  case 96:
#line 392 "./bison.y"
               {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Exp15\n");}
#line 2463 "./syntax.tab.c"
    break;

  case 97:
#line 397 "./bison.y"
              {
    (yyval.node_ins) = create_node("Args", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2472 "./syntax.tab.c"
    break;

  case 98:
#line 401 "./bison.y"
     {
    (yyval.node_ins) = create_node("Args", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 2481 "./syntax.tab.c"
    break;

  case 99:
#line 405 "./bison.y"
                 {(yyval.node_ins) = NULL; bison_has_error = 1;printf("Invalid Args\n");}
#line 2487 "./syntax.tab.c"
    break;


#line 2491 "./syntax.tab.c"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 413 "./bison.y"


int main(int argc, char **argv) {
    if (argc <= 1) return 1;
    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);

    //use bison
    yyparse();
    if(!flex_has_error && !bison_has_error){
       print_tree();
    }


    //unuse bison
    // int token;
    // while ((token = yylex()) != 0) {
    // }


    fclose(f);
    return 0;
}

void yyerror(const char *s) {
    if(!is_flex_error[yylineno]){
        printf("Error type B at Line %d: %s, \n", yylineno, s);
        bison_has_error = 1;
    }
}
