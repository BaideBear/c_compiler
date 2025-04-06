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
#define YYLAST   869

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

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
     138,   144,   151,   155,   159,   163,   167,   171,   172,   176,
     180,   184,   185,   189,   196,   200,   204,   208,   211,   215,
     219,   223,   227,   231,   235,   239,   240,   241,   242,   243,
     244,   245,   249,   253,   256,   260,   264,   265,   266,   270,
     274,   278,   282,   286,   290,   294,   298,   302,   306,   310,
     314,   318,   322,   326,   330,   334,   338,   342,   346,   350,
     354,   358,   362,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   384,   388,   392
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

#define YYPACT_NINF (-69)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-99)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     169,   166,   -69,    10,    30,   -69,   169,   135,   -69,    36,
      57,    61,    88,   101,   -69,   -69,   -69,   113,    12,   -69,
     133,    99,    61,    85,    14,   -69,    69,   -69,    11,    84,
     -69,   -69,   -69,    84,    84,   119,   -69,   -69,   118,   -69,
     141,   140,    65,    98,   106,   214,   127,   156,   129,   -69,
     -69,   149,   151,   -69,   142,   -69,    82,    82,   -69,    70,
     -69,   170,    21,   171,    50,   185,   -69,   -69,   708,   157,
      41,   163,   713,   737,   741,   -69,   165,   214,   590,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   187,   -69,   141,   141,
     -69,   -69,   -69,   -69,   -69,   188,   612,   187,    39,   187,
     704,   -69,   260,   -69,   282,   174,   634,   -69,   -69,   187,
     -69,   746,   770,   774,   779,   803,   807,   812,   836,   190,
     840,   524,   -69,   -69,   -69,   187,   -69,   656,   -69,   -69,
     678,   178,   -69,   546,   180,   187,   -69,   -69,   304,   -69,
     326,   -69,   348,   -69,   370,   -69,   392,   -69,   414,   -69,
     436,   -69,   458,   -69,   480,   -69,   179,   502,   243,   243,
     243,   -69,   845,   -69,   -69,   -69,   195,   203,   -69,   568,
     -69,   -69,   -69,   243,   -69
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    15,    20,     0,     2,     0,     0,    16,     0,
       0,     0,    21,     0,    18,     1,     3,     0,     0,     6,
       0,     0,     0,     0,     0,     9,     0,    10,     0,     0,
      22,    14,     5,     0,     0,     0,     7,    27,     0,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      12,     0,     0,    28,    33,    25,    32,     0,    35,     0,
      54,     0,     0,     0,     0,     0,    82,    81,     0,     0,
       0,    80,     0,     0,     0,    40,     0,     0,     0,    52,
      17,    24,    23,    31,    29,    64,     0,    56,     0,     0,
      58,    57,    55,    51,    38,     0,     0,     0,     0,     0,
       0,    84,     0,    86,     0,     0,     0,    34,    36,    47,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,    60,    50,    49,    41,     0,    45,    46,
       0,     0,    77,     0,     0,     0,    83,    73,     0,    88,
       0,    91,     0,    92,     0,    93,     0,    94,     0,    95,
       0,    89,     0,    90,     0,    79,     0,     0,     0,     0,
       0,    85,     0,    76,    87,    78,     0,    42,    48,     0,
      44,    99,    97,     0,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -69,   -69,   210,   -69,    -6,     2,   -69,   -69,   -69,   -33,
     212,    92,   -69,   131,   -42,   -19,    35,   -69,   -35,   -69,
     -68,    58
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    31,    44,     8,    13,    14,    21,
      11,    41,    42,    75,    76,    77,    60,    46,    61,    62,
      78,   134
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      96,    20,     7,    10,   102,   104,   106,    54,     7,    64,
      59,    59,    47,    23,    59,    38,     2,     3,   121,     2,
       3,    12,    88,    94,   -22,   -22,    40,    49,    50,   127,
      15,   130,   133,   -59,    89,   108,    24,    23,   -22,    39,
     -53,   138,    98,   140,   142,   144,   146,   148,   150,   152,
     154,    91,   157,   122,   123,    59,    59,   138,    40,    40,
      24,    45,    92,    48,   128,    99,    56,   138,   129,    25,
      43,    85,   -53,   -53,     2,     3,   -53,   -53,    57,   -53,
     -53,    79,   -62,   -62,    86,    29,   -53,     2,     3,    26,
     -30,   169,   -53,   -53,   133,    30,    35,   -53,   -53,    47,
      33,   -53,   -53,     2,     3,   -53,   -53,    63,   -53,    30,
      37,   -11,    34,    -8,    29,   -53,   -19,    30,    -8,    -8,
      51,   -53,   -53,    52,    30,    35,   -53,    58,    47,    28,
     -53,   -53,     2,     3,   -53,   -53,    17,   -53,   -53,   167,
     168,   170,    27,    53,   -53,    32,    18,    19,    83,    84,
     -53,   -53,    30,    36,   174,   -53,   -53,    47,    80,   -53,
     -53,     2,     3,   -53,   -53,    55,   -53,    30,    35,    -4,
       1,     2,     3,   -53,     2,     3,    81,     9,    82,   -53,
     -53,    97,    87,    90,   -53,   -53,    65,   100,    66,    67,
      66,    67,    68,    69,   107,    70,    71,    93,    71,   136,
     124,   155,    72,   161,    72,   163,   164,    93,    73,    74,
      73,    74,   173,    26,   -37,    65,    16,    66,    67,    22,
     172,    68,    69,     0,    70,    71,     0,     0,     0,     0,
       0,    72,     0,     0,     0,     0,     0,    73,    74,     0,
       0,     0,    26,   -37,   166,     0,    66,    67,     0,     0,
      68,    69,     0,    70,    71,     0,     0,     0,     0,     0,
      72,   135,     0,     0,     0,     0,    73,    74,     0,     0,
       0,    26,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   119,   135,     0,   -74,   120,   -74,     0,     0,
       0,     0,     0,     0,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   119,   135,     0,   -75,   120,   -75,
       0,     0,     0,     0,     0,     0,   -96,   -96,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   135,     0,   -96,
     120,   -96,     0,     0,     0,     0,     0,     0,   -65,   -65,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   135,
       0,   -65,   120,   -65,     0,     0,     0,     0,     0,     0,
     -68,   -68,   -68,   -68,   113,   114,   115,   116,   -68,   -68,
     119,   135,     0,   -68,   120,   -68,     0,     0,     0,     0,
       0,     0,   -69,   -69,   -69,   -69,   -69,   -69,   115,   116,
     -69,   -69,   119,   135,     0,   -69,   120,   -69,     0,     0,
       0,     0,     0,     0,   -70,   -70,   -70,   -70,   -70,   -70,
     115,   116,   -70,   -70,   119,   135,     0,   -70,   120,   -70,
       0,     0,     0,     0,     0,     0,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   119,   135,     0,   -71,
     120,   -71,     0,     0,     0,     0,     0,     0,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   119,   135,
       0,   -72,   120,   -72,     0,     0,     0,     0,     0,     0,
     -66,   -66,   -66,   112,   113,   114,   115,   116,   -66,   -66,
     119,   135,     0,   -66,   120,   -66,     0,     0,     0,     0,
       0,     0,   -67,   -67,   -67,   112,   113,   114,   115,   116,
     117,   -67,   119,   135,     0,   -67,   120,   -67,     0,     0,
       0,     0,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   135,     0,     0,   120,   165,
       0,     0,     0,     0,     0,     0,   -63,   -63,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   135,     0,     0,
     120,     0,     0,     0,     0,     0,     0,     0,     0,   162,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   109,
       0,   -98,   120,     0,     0,     0,     0,     0,     0,     0,
     110,     0,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   109,     0,   -96,   120,     0,     0,     0,     0,     0,
       0,     0,   110,     0,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   125,     0,     0,   120,     0,     0,     0,
       0,     0,     0,     0,   126,     0,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   135,     0,     0,   120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   135,     0,   137,
     120,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   159,
       0,   158,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
     119,     0,     0,   160,   120,   131,     0,    66,    67,    95,
       0,    66,    67,     0,   101,    71,    66,    67,     0,    71,
       0,    72,     0,     0,    71,    72,     0,    73,    74,   132,
      72,    73,    74,     0,     0,     0,    73,    74,   103,     0,
      66,    67,   105,     0,    66,    67,     0,   139,    71,    66,
      67,     0,    71,     0,    72,     0,     0,    71,    72,     0,
      73,    74,     0,    72,    73,    74,     0,     0,     0,    73,
      74,   141,     0,    66,    67,   143,     0,    66,    67,     0,
     145,    71,    66,    67,     0,    71,     0,    72,     0,     0,
      71,    72,     0,    73,    74,     0,    72,    73,    74,     0,
       0,     0,    73,    74,   147,     0,    66,    67,   149,     0,
      66,    67,     0,   151,    71,    66,    67,     0,    71,     0,
      72,     0,     0,    71,    72,     0,    73,    74,     0,    72,
      73,    74,     0,     0,     0,    73,    74,   153,     0,    66,
      67,   156,     0,    66,    67,     0,   171,    71,    66,    67,
       0,    71,     0,    72,     0,     0,    71,    72,     0,    73,
      74,     0,    72,    73,    74,     0,     0,     0,    73,    74
};

static const yytype_int16 yycheck[] =
{
      68,     7,     0,     1,    72,    73,    74,    40,     6,    44,
      43,    44,     1,     1,    47,     1,     5,     6,    86,     5,
       6,    11,     1,    65,    12,    13,    24,    33,    34,    97,
       0,    99,   100,    12,    13,    77,    24,     1,    26,    25,
      29,   109,     1,   111,   112,   113,   114,   115,   116,   117,
     118,     1,   120,    88,    89,    88,    89,   125,    56,    57,
      24,    26,    12,    28,    25,    24,     1,   135,    29,    12,
       1,     1,     3,     4,     5,     6,     7,     8,    13,    10,
      11,    46,    12,    13,    14,     1,    17,     5,     6,    28,
      25,   159,    23,    24,   162,    11,    26,    28,    29,     1,
       1,     3,     4,     5,     6,     7,     8,     1,    10,    11,
      25,    12,    13,     0,     1,    17,    28,    11,     5,     6,
       1,    23,    24,     4,    11,    26,    28,    29,     1,    28,
       3,     4,     5,     6,     7,     8,     1,    10,    11,   158,
     159,   160,    11,    25,    17,    12,    11,    12,    56,    57,
      23,    24,    11,    22,   173,    28,    29,     1,    29,     3,
       4,     5,     6,     7,     8,    25,    10,    11,    26,     0,
       1,     5,     6,    17,     5,     6,    27,    11,    27,    23,
      24,    24,    12,    12,    28,    29,     1,    24,     3,     4,
       3,     4,     7,     8,    29,    10,    11,    12,    11,    25,
      12,    11,    17,    25,    17,    25,    27,    12,    23,    24,
      23,    24,     9,    28,    29,     1,     6,     3,     4,     7,
     162,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,
      -1,    -1,    28,    29,     1,    -1,     3,     4,    -1,    -1,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      17,     1,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,
      -1,    28,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     1,    -1,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     1,    -1,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,     1,    -1,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     1,
      -1,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,     1,    -1,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     1,    -1,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     1,    -1,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,     1,    -1,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     1,
      -1,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,     1,    -1,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     1,    -1,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     1,    -1,    -1,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,     1,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     1,
      -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,     1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     1,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     1,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,     1,    -1,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     1,
      -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    25,    26,     1,    -1,     3,     4,     1,
      -1,     3,     4,    -1,     1,    11,     3,     4,    -1,    11,
      -1,    17,    -1,    -1,    11,    17,    -1,    23,    24,    25,
      17,    23,    24,    -1,    -1,    -1,    23,    24,     1,    -1,
       3,     4,     1,    -1,     3,     4,    -1,     1,    11,     3,
       4,    -1,    11,    -1,    17,    -1,    -1,    11,    17,    -1,
      23,    24,    -1,    17,    23,    24,    -1,    -1,    -1,    23,
      24,     1,    -1,     3,     4,     1,    -1,     3,     4,    -1,
       1,    11,     3,     4,    -1,    11,    -1,    17,    -1,    -1,
      11,    17,    -1,    23,    24,    -1,    17,    23,    24,    -1,
      -1,    -1,    23,    24,     1,    -1,     3,     4,     1,    -1,
       3,     4,    -1,     1,    11,     3,     4,    -1,    11,    -1,
      17,    -1,    -1,    11,    17,    -1,    23,    24,    -1,    17,
      23,    24,    -1,    -1,    -1,    23,    24,     1,    -1,     3,
       4,     1,    -1,     3,     4,    -1,     1,    11,     3,     4,
      -1,    11,    -1,    17,    -1,    -1,    11,    17,    -1,    23,
      24,    -1,    17,    23,    24,    -1,    -1,    -1,    23,    24
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
      26,    52,    50,    50,    12,     1,    12,    52,    25,    29,
      52,     1,    25,    52,    53,     1,    25,    25,    52,     1,
      52,     1,    52,     1,    52,     1,    52,     1,    52,     1,
      52,     1,    52,     1,    52,    11,     1,    52,    25,     1,
      25,    25,    13,    25,    27,    27,     1,    47,    47,    52,
      47,     1,    53,     9,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    35,
      35,    36,    36,    36,    36,    37,    37,    38,    38,    39,
      39,    40,    41,    41,    41,    42,    42,    42,    42,    43,
      43,    43,    43,    44,    45,    45,    46,    46,    46,    47,
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
       0,     1,     1,     4,     4,     4,     3,     3,     4,     3,
       1,     3,     2,     2,     4,     3,     2,     0,     2,     2,
       1,     3,     5,     7,     5,     3,     3,     2,     5,     3,
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
#line 1716 "./syntax.tab.c"
    break;

  case 3:
#line 71 "./bison.y"
                 {
    (yyval.node_ins) = create_node("ExtDefList", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 2, (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1725 "./syntax.tab.c"
    break;

  case 4:
#line 75 "./bison.y"
              {
    (yyval.node_ins) = NULL;
}
#line 1733 "./syntax.tab.c"
    break;

  case 5:
#line 81 "./bison.y"
                         {
    (yyval.node_ins) = create_node("ExtDef", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1742 "./syntax.tab.c"
    break;

  case 6:
#line 85 "./bison.y"
                {
    (yyval.node_ins) = create_node("ExtDef", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 2, (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1751 "./syntax.tab.c"
    break;

  case 7:
#line 89 "./bison.y"
                         {
    (yyval.node_ins) = create_node("ExtDef", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1760 "./syntax.tab.c"
    break;

  case 8:
#line 93 "./bison.y"
                 {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 1766 "./syntax.tab.c"
    break;

  case 9:
#line 94 "./bison.y"
                      {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 1772 "./syntax.tab.c"
    break;

  case 10:
#line 95 "./bison.y"
                     {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 1778 "./syntax.tab.c"
    break;

  case 11:
#line 99 "./bison.y"
      {
    (yyval.node_ins) = create_node("ExtDecList", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 1787 "./syntax.tab.c"
    break;

  case 12:
#line 103 "./bison.y"
                         {
    (yyval.node_ins) = create_node("ExtDecList", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1796 "./syntax.tab.c"
    break;

  case 13:
#line 107 "./bison.y"
                         {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 1802 "./syntax.tab.c"
    break;

  case 14:
#line 108 "./bison.y"
                  {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 1808 "./syntax.tab.c"
    break;

  case 15:
#line 112 "./bison.y"
    {
    (yyval.node_ins) = create_node("Specifier", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 1817 "./syntax.tab.c"
    break;

  case 16:
#line 116 "./bison.y"
                 {
    (yyval.node_ins) = create_node("Specifier", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 1826 "./syntax.tab.c"
    break;

  case 17:
#line 123 "./bison.y"
                           {
    (yyval.node_ins) = create_node("StructSpecifier", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 5, (yyvsp[-4].node_ins), (yyvsp[-3].node_ins), (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1835 "./syntax.tab.c"
    break;

  case 18:
#line 127 "./bison.y"
            {
    (yyval.node_ins) = create_node("StructSpecifier", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 2, (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1844 "./syntax.tab.c"
    break;

  case 19:
#line 134 "./bison.y"
  {
    (yyval.node_ins) = create_node("OptTag", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 1853 "./syntax.tab.c"
    break;

  case 20:
#line 138 "./bison.y"
              {
    (yyval.node_ins) = NULL;
}
#line 1861 "./syntax.tab.c"
    break;

  case 21:
#line 144 "./bison.y"
  {
    (yyval.node_ins) = create_node("Tag", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 1870 "./syntax.tab.c"
    break;

  case 22:
#line 151 "./bison.y"
  {
    (yyval.node_ins) = create_node("VarDec", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 1879 "./syntax.tab.c"
    break;

  case 23:
#line 155 "./bison.y"
                  {
    (yyval.node_ins) = create_node("VarDec", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 4, (yyvsp[-3].node_ins), (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1888 "./syntax.tab.c"
    break;

  case 24:
#line 159 "./bison.y"
                    {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 1894 "./syntax.tab.c"
    break;

  case 25:
#line 163 "./bison.y"
                {
    (yyval.node_ins) = create_node("FunDec", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 4, (yyvsp[-3].node_ins), (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1903 "./syntax.tab.c"
    break;

  case 26:
#line 167 "./bison.y"
          {
    (yyval.node_ins) = create_node("FunDec", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1912 "./syntax.tab.c"
    break;

  case 27:
#line 171 "./bison.y"
             {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 1918 "./syntax.tab.c"
    break;

  case 28:
#line 172 "./bison.y"
                {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 1924 "./syntax.tab.c"
    break;

  case 29:
#line 176 "./bison.y"
                      {
    (yyval.node_ins) = create_node("VarList", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1933 "./syntax.tab.c"
    break;

  case 30:
#line 180 "./bison.y"
          {
    (yyval.node_ins) = create_node("VarList", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 1942 "./syntax.tab.c"
    break;

  case 31:
#line 184 "./bison.y"
                        {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 1948 "./syntax.tab.c"
    break;

  case 32:
#line 185 "./bison.y"
                {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 1954 "./syntax.tab.c"
    break;

  case 33:
#line 189 "./bison.y"
                {
    (yyval.node_ins) = create_node("ParamDec", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 2, (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1963 "./syntax.tab.c"
    break;

  case 34:
#line 196 "./bison.y"
                      {
    (yyval.node_ins) = create_node("CompSt", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 4, (yyvsp[-3].node_ins), (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1972 "./syntax.tab.c"
    break;

  case 35:
#line 200 "./bison.y"
             {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 1978 "./syntax.tab.c"
    break;

  case 36:
#line 204 "./bison.y"
             {
    (yyval.node_ins) = create_node("StmtList", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 2, (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 1987 "./syntax.tab.c"
    break;

  case 37:
#line 208 "./bison.y"
              {
    (yyval.node_ins) = NULL;
}
#line 1995 "./syntax.tab.c"
    break;

  case 38:
#line 211 "./bison.y"
                {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2001 "./syntax.tab.c"
    break;

  case 39:
#line 215 "./bison.y"
        {
    (yyval.node_ins) = create_node("Stmt", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 2, (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2010 "./syntax.tab.c"
    break;

  case 40:
#line 219 "./bison.y"
        {
    (yyval.node_ins) = create_node("Stmt", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 2019 "./syntax.tab.c"
    break;

  case 41:
#line 223 "./bison.y"
                 {
    (yyval.node_ins) = create_node("Stmt", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2028 "./syntax.tab.c"
    break;

  case 42:
#line 227 "./bison.y"
                                         {
    (yyval.node_ins) = create_node("Stmt", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 5, (yyvsp[-4].node_ins), (yyvsp[-3].node_ins), (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2037 "./syntax.tab.c"
    break;

  case 43:
#line 231 "./bison.y"
                             {
    (yyval.node_ins) = create_node("Stmt", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 7, (yyvsp[-6].node_ins), (yyvsp[-5].node_ins), (yyvsp[-4].node_ins), (yyvsp[-3].node_ins), (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2046 "./syntax.tab.c"
    break;

  case 44:
#line 235 "./bison.y"
                      {
    (yyval.node_ins) = create_node("Stmt", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 5, (yyvsp[-4].node_ins), (yyvsp[-3].node_ins), (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2055 "./syntax.tab.c"
    break;

  case 45:
#line 239 "./bison.y"
                {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2061 "./syntax.tab.c"
    break;

  case 46:
#line 240 "./bison.y"
                {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2067 "./syntax.tab.c"
    break;

  case 47:
#line 241 "./bison.y"
           {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2073 "./syntax.tab.c"
    break;

  case 48:
#line 242 "./bison.y"
                         {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2079 "./syntax.tab.c"
    break;

  case 49:
#line 243 "./bison.y"
                  {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2085 "./syntax.tab.c"
    break;

  case 50:
#line 244 "./bison.y"
                   {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2091 "./syntax.tab.c"
    break;

  case 51:
#line 245 "./bison.y"
            {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2097 "./syntax.tab.c"
    break;

  case 52:
#line 249 "./bison.y"
           {
    (yyval.node_ins) = create_node("DefList", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 2, (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2106 "./syntax.tab.c"
    break;

  case 53:
#line 253 "./bison.y"
              {
    (yyval.node_ins) = NULL;
}
#line 2114 "./syntax.tab.c"
    break;

  case 54:
#line 256 "./bison.y"
               {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2120 "./syntax.tab.c"
    break;

  case 55:
#line 260 "./bison.y"
                      {
    (yyval.node_ins) = create_node("Def", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2129 "./syntax.tab.c"
    break;

  case 56:
#line 264 "./bison.y"
                    {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2135 "./syntax.tab.c"
    break;

  case 57:
#line 265 "./bison.y"
                         {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2141 "./syntax.tab.c"
    break;

  case 58:
#line 266 "./bison.y"
                      {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2147 "./syntax.tab.c"
    break;

  case 59:
#line 270 "./bison.y"
   {
    (yyval.node_ins) = create_node("DecList", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 2156 "./syntax.tab.c"
    break;

  case 60:
#line 274 "./bison.y"
                   {
    (yyval.node_ins) = create_node("DecList", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2165 "./syntax.tab.c"
    break;

  case 61:
#line 278 "./bison.y"
                   {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2171 "./syntax.tab.c"
    break;

  case 62:
#line 282 "./bison.y"
      {
    (yyval.node_ins) = create_node("Dec", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 2180 "./syntax.tab.c"
    break;

  case 63:
#line 286 "./bison.y"
                     {
    (yyval.node_ins) = create_node("Dec", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2189 "./syntax.tab.c"
    break;

  case 64:
#line 290 "./bison.y"
             {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2195 "./syntax.tab.c"
    break;

  case 65:
#line 294 "./bison.y"
                {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2204 "./syntax.tab.c"
    break;

  case 66:
#line 298 "./bison.y"
             {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2213 "./syntax.tab.c"
    break;

  case 67:
#line 302 "./bison.y"
            {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2222 "./syntax.tab.c"
    break;

  case 68:
#line 306 "./bison.y"
               {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2231 "./syntax.tab.c"
    break;

  case 69:
#line 310 "./bison.y"
              {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2240 "./syntax.tab.c"
    break;

  case 70:
#line 314 "./bison.y"
               {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2249 "./syntax.tab.c"
    break;

  case 71:
#line 318 "./bison.y"
              {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2258 "./syntax.tab.c"
    break;

  case 72:
#line 322 "./bison.y"
             {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2267 "./syntax.tab.c"
    break;

  case 73:
#line 326 "./bison.y"
           {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2276 "./syntax.tab.c"
    break;

  case 74:
#line 330 "./bison.y"
                        {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 2, (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2285 "./syntax.tab.c"
    break;

  case 75:
#line 334 "./bison.y"
         {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 2, (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2294 "./syntax.tab.c"
    break;

  case 76:
#line 338 "./bison.y"
               {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 4, (yyvsp[-3].node_ins), (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2303 "./syntax.tab.c"
    break;

  case 77:
#line 342 "./bison.y"
          {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2312 "./syntax.tab.c"
    break;

  case 78:
#line 346 "./bison.y"
               {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 4, (yyvsp[-3].node_ins), (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2321 "./syntax.tab.c"
    break;

  case 79:
#line 350 "./bison.y"
            {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2330 "./syntax.tab.c"
    break;

  case 80:
#line 354 "./bison.y"
    {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 2339 "./syntax.tab.c"
    break;

  case 81:
#line 358 "./bison.y"
     {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 2348 "./syntax.tab.c"
    break;

  case 82:
#line 362 "./bison.y"
       {
    (yyval.node_ins) = create_node("Exp", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 2357 "./syntax.tab.c"
    break;

  case 83:
#line 366 "./bison.y"
             {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2363 "./syntax.tab.c"
    break;

  case 84:
#line 367 "./bison.y"
             {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2369 "./syntax.tab.c"
    break;

  case 85:
#line 368 "./bison.y"
                {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2375 "./syntax.tab.c"
    break;

  case 86:
#line 369 "./bison.y"
           {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2381 "./syntax.tab.c"
    break;

  case 87:
#line 370 "./bison.y"
                 {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2387 "./syntax.tab.c"
    break;

  case 88:
#line 371 "./bison.y"
                    {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2393 "./syntax.tab.c"
    break;

  case 89:
#line 372 "./bison.y"
               {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2399 "./syntax.tab.c"
    break;

  case 90:
#line 373 "./bison.y"
              {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2405 "./syntax.tab.c"
    break;

  case 91:
#line 374 "./bison.y"
                 {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2411 "./syntax.tab.c"
    break;

  case 92:
#line 375 "./bison.y"
                {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2417 "./syntax.tab.c"
    break;

  case 93:
#line 376 "./bison.y"
                 {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2423 "./syntax.tab.c"
    break;

  case 94:
#line 377 "./bison.y"
                {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2429 "./syntax.tab.c"
    break;

  case 95:
#line 378 "./bison.y"
               {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2435 "./syntax.tab.c"
    break;

  case 96:
#line 379 "./bison.y"
               {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2441 "./syntax.tab.c"
    break;

  case 97:
#line 384 "./bison.y"
              {
    (yyval.node_ins) = create_node("Args", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 3, (yyvsp[-2].node_ins), (yyvsp[-1].node_ins), (yyvsp[0].node_ins));
}
#line 2450 "./syntax.tab.c"
    break;

  case 98:
#line 388 "./bison.y"
     {
    (yyval.node_ins) = create_node("Args", UNTERMINAL, "\0", (yyloc).first_line);
    build_cfg((yyval.node_ins), 1, (yyvsp[0].node_ins));
}
#line 2459 "./syntax.tab.c"
    break;

  case 99:
#line 392 "./bison.y"
                 {(yyval.node_ins) = NULL; bison_has_error = 1;}
#line 2465 "./syntax.tab.c"
    break;


#line 2469 "./syntax.tab.c"

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
#line 400 "./bison.y"


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
        printf("Error type B at Line %d: %s\n", yylineno, s);
        bison_has_error = 1;
    }
}
