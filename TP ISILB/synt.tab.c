
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "synt.y"

int nb_ligne = 1;
int nb_colonnes = 1;
char sauvType[20];
char tempVal[20];
char taille[10];
char express[100];


/* Line 189 of yacc.c  */
#line 83 "synt.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     mc_import = 258,
     pvg = 259,
     bib_io = 260,
     bib_lang = 261,
     err = 262,
     mc_public = 263,
     mc_private = 264,
     mc_protected = 265,
     mc_class = 266,
     idf_v = 267,
     aco_ov = 268,
     aco_fr = 269,
     mc_entier = 270,
     mc_reel = 271,
     mc_chaine = 272,
     mc_const = 273,
     vrg = 274,
     idf_tab = 275,
     pls = 276,
     mns = 277,
     mlt = 278,
     divise = 279,
     nb = 280,
     p_ou = 281,
     p_fr = 282,
     aft = 283,
     mc_for = 284,
     sup = 285,
     inf = 286,
     supe = 287,
     infe = 288,
     mc_In = 289,
     g = 290,
     mc_Out = 291,
     br_ov = 292,
     br_fr = 293,
     chaine = 294,
     reel = 295
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 9 "synt.y"

     int entier;
     char* chaine; 
     float floa;



/* Line 214 of yacc.c  */
#line 167 "synt.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 179 "synt.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   120

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNRULES -- Number of states.  */
#define YYNSTATES  137

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    12,    13,    17,    19,    21,    25,
      27,    29,    31,    32,    35,    38,    39,    41,    43,    45,
      50,    54,    56,    60,    66,    68,    70,    72,    76,    78,
      80,    82,    86,    88,    94,    98,   102,   107,   112,   114,
     116,   120,   122,   125,   126,   128,   130,   132,   134,   139,
     143,   145,   149,   151,   153,   155,   157,   159,   161,   163,
     165,   167,   177,   181,   185,   187,   189,   191,   193,   197,
     201,   209,   217,   221,   223,   227
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    43,    46,    13,    48,    14,    -1,    44,
      43,    -1,    -1,     3,    45,     4,    -1,     5,    -1,     6,
      -1,    47,    11,    12,    -1,     8,    -1,     9,    -1,    10,
      -1,    -1,    49,    61,    -1,    50,    49,    -1,    -1,    54,
      -1,    57,    -1,    51,    -1,    18,    55,    52,     4,    -1,
      12,    19,    52,    -1,    12,    -1,    12,    28,    53,    -1,
      12,    28,    53,    19,    52,    -1,    25,    -1,    39,    -1,
      40,    -1,    55,    56,     4,    -1,    15,    -1,    16,    -1,
      17,    -1,    12,    19,    56,    -1,    12,    -1,    12,    28,
      53,    19,    56,    -1,    12,    28,    53,    -1,    55,    60,
       4,    -1,    20,    37,    25,    38,    -1,    20,    37,    59,
      38,    -1,    58,    -1,    12,    -1,    58,    19,    60,    -1,
      58,    -1,    62,    61,    -1,    -1,    63,    -1,    68,    -1,
      74,    -1,    75,    -1,    59,    28,    64,     4,    -1,    65,
      67,    64,    -1,    65,    -1,    65,    24,    25,    -1,    66,
      -1,    58,    -1,    12,    -1,    25,    -1,    40,    -1,    39,
      -1,    21,    -1,    23,    -1,    22,    -1,    29,    26,    69,
       4,    70,     4,    72,    27,    73,    -1,    12,    28,    64,
      -1,    12,    71,    66,    -1,    30,    -1,    31,    -1,    32,
      -1,    33,    -1,    12,    21,    21,    -1,    13,    61,    14,
      -1,    34,    26,    39,    19,    12,    27,     4,    -1,    36,
      26,    76,    19,    77,    27,     4,    -1,    39,    21,    76,
      -1,    39,    -1,    12,    19,    77,    -1,    12,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    21,    21,    24,    25,    27,    32,    33,    35,    40,
      41,    42,    43,    45,    47,    48,    50,    51,    52,    54,
      56,    61,    66,    73,    81,    87,    92,    98,   100,   101,
     102,   104,   110,   116,   131,   147,   149,   161,   170,   171,
     173,   179,   186,   187,   189,   190,   191,   192,   194,   211,
     212,   213,   219,   220,   223,   224,   225,   226,   228,   231,
     234,   238,   240,   242,   244,   245,   246,   247,   249,   251,
     253,   259,   265,   266,   268,   269
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "mc_import", "pvg", "bib_io", "bib_lang",
  "err", "mc_public", "mc_private", "mc_protected", "mc_class", "idf_v",
  "aco_ov", "aco_fr", "mc_entier", "mc_reel", "mc_chaine", "mc_const",
  "vrg", "idf_tab", "pls", "mns", "mlt", "divise", "nb", "p_ou", "p_fr",
  "aft", "mc_for", "sup", "inf", "supe", "infe", "mc_In", "g", "mc_Out",
  "br_ov", "br_fr", "chaine", "reel", "$accept", "S", "LISTE_BIB", "BIB",
  "NOM_BIB", "HEADER_CLASS", "MODIFICATEUR", "CORPS", "LISTE_DEC", "DEC",
  "DEC_CONST", "LISTE_CONST", "VAL", "DEC_VAR", "TYPE", "LISTE_IDF",
  "DEC_TAB", "Idf_tab", "tabID", "LISTE_IDF_TAB", "LISTE_INST", "INST",
  "Affectation", "Expression", "IDF_NB", "IDF_NBB", "OPR", "BOUCLE",
  "init", "condition", "logique", "incre", "BC", "Lecture", "Ecriture",
  "List_chaine", "List_val", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    45,    45,    46,    47,
      47,    47,    47,    48,    49,    49,    50,    50,    50,    51,
      52,    52,    52,    52,    53,    53,    53,    54,    55,    55,
      55,    56,    56,    56,    56,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    62,    62,    63,    64,
      64,    64,    65,    65,    66,    66,    66,    66,    67,    67,
      67,    68,    69,    70,    71,    71,    71,    71,    72,    73,
      74,    75,    76,    76,    77,    77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     0,     3,     1,     1,     3,     1,
       1,     1,     0,     2,     2,     0,     1,     1,     1,     4,
       3,     1,     3,     5,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     5,     3,     3,     4,     4,     1,     1,
       3,     1,     2,     0,     1,     1,     1,     1,     4,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     9,     3,     3,     1,     1,     1,     1,     3,     3,
       7,     7,     3,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,    12,     4,     6,     7,     0,     1,     9,
      10,    11,     0,     0,     3,     5,    15,     0,    28,    29,
      30,     0,     0,    43,    15,    18,    16,     0,    17,     8,
       0,     2,    39,     0,     0,     0,     0,    38,     0,    13,
      43,    44,    45,    46,    47,    14,    32,     0,    41,     0,
      21,     0,     0,     0,     0,     0,     0,    42,     0,     0,
      27,     0,    35,     0,     0,    19,     0,     0,     0,     0,
       0,    73,     0,    54,    55,    57,    56,    53,     0,    50,
      52,    31,    24,    25,    26,    34,    40,    20,    22,    36,
      37,     0,     0,     0,     0,     0,    48,    58,    60,    59,
       0,     0,     0,     0,    62,     0,     0,     0,    72,    75,
       0,    51,    49,    33,    23,    64,    65,    66,    67,     0,
       0,     0,     0,     0,    63,     0,     0,    70,    74,    71,
       0,     0,    68,    43,    61,     0,    69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     7,    12,    13,    22,    23,    24,
      25,    51,    85,    26,    27,    47,    28,    37,    38,    49,
      39,    40,    41,    78,    79,    80,   101,    42,    69,   106,
     119,   126,   134,    43,    44,    72,   110
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -84
static const yytype_int8 yypact[] =
{
      11,     5,    42,    47,    11,   -84,   -84,    17,   -84,   -84,
     -84,   -84,    13,    34,   -84,   -84,    23,    49,   -84,   -84,
     -84,    43,    48,    -7,    23,   -84,   -84,    24,   -84,   -84,
      51,   -84,   -84,    27,    40,    41,    44,   -84,    45,   -84,
      -7,   -84,   -84,   -84,   -84,   -84,    -3,    64,    50,    67,
       9,    68,    -5,    62,    37,    38,    -8,   -84,    66,   -16,
     -84,    59,   -84,    51,   -16,   -84,    46,    52,    53,    76,
      63,    65,    69,   -84,   -84,   -84,   -84,   -84,    79,    26,
     -84,   -84,   -84,   -84,   -84,    70,   -84,   -84,    72,   -84,
     -84,    -8,    73,    75,    38,    80,   -84,   -84,   -84,   -84,
      71,    -8,    66,    51,   -84,    21,    90,    74,   -84,    78,
      77,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,    -6,
      83,    94,    80,    95,   -84,    81,    82,   -84,   -84,   -84,
      84,    87,   -84,    -7,   -84,    89,   -84
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -84,   -84,   102,   -84,   -84,   -84,   -84,   -84,    86,   -84,
     -84,   -60,    54,   -84,    91,   -56,   -84,   -26,    55,    56,
     -40,   -84,   -84,   -83,   -84,   -11,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,    19,    -2
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      57,    48,    81,    87,    73,    32,    73,    32,   104,    82,
       5,     6,    33,    33,     1,    33,    58,    74,   112,    74,
      66,    15,    34,    83,    84,    59,    16,    35,    63,    36,
      77,    75,    76,    75,    76,    48,    46,    64,    18,    19,
      20,    21,     8,   114,    33,    17,   113,    97,    98,    99,
     100,   115,   116,   117,   118,     9,    10,    11,    18,    19,
      20,    29,    31,    50,    52,    77,    53,    54,    60,    61,
      55,    62,    65,    56,    68,    77,    70,    71,    46,    33,
      92,    91,    93,    96,    89,   105,    94,   107,    95,   102,
      90,   103,   109,   135,   120,   125,   111,   122,   127,   129,
     133,   121,   130,   136,   123,   132,    14,    67,   124,   131,
      45,     0,    30,   108,     0,     0,     0,    86,    88,     0,
     128
};

static const yytype_int16 yycheck[] =
{
      40,    27,    58,    63,    12,    12,    12,    12,    91,    25,
       5,     6,    20,    20,     3,    20,    19,    25,   101,    25,
      25,     4,    29,    39,    40,    28,    13,    34,    19,    36,
      56,    39,    40,    39,    40,    61,    12,    28,    15,    16,
      17,    18,     0,   103,    20,    11,   102,    21,    22,    23,
      24,    30,    31,    32,    33,     8,     9,    10,    15,    16,
      17,    12,    14,    12,    37,    91,    26,    26,     4,    19,
      26,     4,     4,    28,    12,   101,    39,    39,    12,    20,
       4,    28,    19,     4,    38,    12,    21,    12,    19,    19,
      38,    19,    12,   133,     4,    12,    25,    19,     4,     4,
      13,    27,    21,    14,    27,    21,     4,    52,   119,    27,
      24,    -1,    21,    94,    -1,    -1,    -1,    61,    64,    -1,
     122
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    42,    43,    44,     5,     6,    45,     0,     8,
       9,    10,    46,    47,    43,     4,    13,    11,    15,    16,
      17,    18,    48,    49,    50,    51,    54,    55,    57,    12,
      55,    14,    12,    20,    29,    34,    36,    58,    59,    61,
      62,    63,    68,    74,    75,    49,    12,    56,    58,    60,
      12,    52,    37,    26,    26,    26,    28,    61,    19,    28,
       4,    19,     4,    19,    28,     4,    25,    59,    12,    69,
      39,    39,    76,    12,    25,    39,    40,    58,    64,    65,
      66,    56,    25,    39,    40,    53,    60,    52,    53,    38,
      38,    28,     4,    19,    21,    19,     4,    21,    22,    23,
      24,    67,    19,    19,    64,    12,    70,    12,    76,    12,
      77,    25,    64,    56,    52,    30,    31,    32,    33,    71,
       4,    27,    19,    27,    66,    12,    72,     4,    77,     4,
      21,    27,    21,    13,    73,    61,    14
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 21 "synt.y"
    {printf("Programme syntaxiquement correct"); 
               YYACCEPT;        ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 27 "synt.y"
    { if(doubleDeclaration((yyvsp[(2) - (3)].chaine))==0)
                                     insererTYPE((yyvsp[(2) - (3)].chaine),"BIB");
							    else printf("Erreur Semantique: double declaration de la bibliotheque %s a la ligne %d , position %d\n",(yyvsp[(1) - (3)].chaine),nb_ligne,nb_colonnes);
					      ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 35 "synt.y"
    { if(doubleDeclaration((yyvsp[(3) - (3)].chaine))==0)
                                     insererTYPE((yyvsp[(3) - (3)].chaine),"Classe");
							    else printf("Erreur Semantique: double declaration  de la classe %s a la ligne %d , position %d\n",(yyvsp[(1) - (3)].chaine),nb_ligne,nb_colonnes);
					      ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 43 "synt.y"
    { strcpy((yyval.chaine), "");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 56 "synt.y"
    {  insererConstante((yyvsp[(1) - (3)].chaine),""); 
                                     if(doubleDeclaration((yyvsp[(1) - (3)].chaine))==0)
                                     insererTYPE((yyvsp[(1) - (3)].chaine),sauvType);
							    else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",(yyvsp[(1) - (3)].chaine),nb_ligne,nb_colonnes);
					      ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 61 "synt.y"
    {                     insererConstante((yyvsp[(1) - (1)].chaine),""); 
                                         if(doubleDeclaration((yyvsp[(1) - (1)].chaine))==0)
                                          insererTYPE((yyvsp[(1) - (1)].chaine),sauvType);
							      else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",(yyvsp[(1) - (1)].chaine),nb_ligne,nb_colonnes);
					      ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 66 "synt.y"
    {   
                                       
                                      insererConstante((yyvsp[(1) - (3)].chaine),(yyvsp[(3) - (3)].chaine));   
                                       if(doubleDeclaration((yyvsp[(1) - (3)].chaine))==0)
                                       insererTYPE((yyvsp[(1) - (3)].chaine),sauvType);
							    else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",(yyvsp[(1) - (3)].chaine),nb_ligne,nb_colonnes);
					      ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 73 "synt.y"
    {
                                            
                                             insererConstante((yyvsp[(1) - (5)].chaine),(yyvsp[(3) - (5)].chaine));                                       
                                             if(doubleDeclaration((yyvsp[(1) - (5)].chaine))==0)
                                             insererTYPE((yyvsp[(1) - (5)].chaine),sauvType);
							          else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",(yyvsp[(1) - (5)].chaine),nb_ligne,nb_colonnes);
					      ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 81 "synt.y"
    {

  sprintf(tempVal,"%d",(yyvsp[(1) - (1)].entier));
   (yyval.chaine) = tempVal;
  /*sprintf(express, "%d", $1);*/ sauvegardeTypeExpression("Entier",tempVal);
;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 87 "synt.y"
    {
  sprintf(tempVal,"%s",(yyvsp[(1) - (1)].chaine));
   (yyval.chaine) = tempVal;
  sauvegardeTypeExpression("Chaine",(yyvsp[(1) - (1)].chaine));
;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 92 "synt.y"
    {
    sprintf(tempVal,"%.3f",(yyvsp[(1) - (1)].floa));
     (yyval.chaine) = tempVal;
    /*sprintf(express,"%d.%02u", (int) $1, (int) (($1 - (int) $1 ) * 100) );*/  sauvegardeTypeExpression("Reel",tempVal);
;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 100 "synt.y"
    {strcpy(sauvType,(yyvsp[(1) - (1)].chaine));;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 101 "synt.y"
    {strcpy(sauvType,(yyvsp[(1) - (1)].chaine));;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 102 "synt.y"
    {strcpy(sauvType,(yyvsp[(1) - (1)].chaine));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 104 "synt.y"
    { if(doubleDeclaration((yyvsp[(1) - (3)].chaine))==0)
                                    insererTYPE((yyvsp[(1) - (3)].chaine),sauvType);
                							    else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n", (yyvsp[(1) - (3)].chaine), nb_ligne, nb_colonnes);
                					        if(MotNonReserver((yyvsp[(1) - (3)].chaine))==-1)
                                    printf("Erreur Semantique: La ligne %d , position %d , le nom de la variable est un mot reserve\n ",nb_ligne,nb_colonnes);
                ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 110 "synt.y"
    { if(doubleDeclaration((yyvsp[(1) - (1)].chaine))==0)
                                    insererTYPE((yyvsp[(1) - (1)].chaine),sauvType);
                							    else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",(yyvsp[(1) - (1)].chaine),nb_ligne,nb_colonnes);
                					        if(MotNonReserver((yyvsp[(1) - (1)].chaine))==-1)
                                    printf("Erreur Semantique: La ligne %d , position %d , le nom de la variable est un mot reserve\n ",nb_ligne,nb_colonnes);
                  ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 116 "synt.y"
    { if(doubleDeclaration((yyvsp[(1) - (5)].chaine))==0)
                                    insererTYPE((yyvsp[(1) - (5)].chaine),sauvType);
                							    else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",(yyvsp[(1) - (5)].chaine),nb_ligne,nb_colonnes);
                					        if(MotNonReserver((yyvsp[(1) - (5)].chaine))==-1)
                                    printf("Erreur Semantique: La ligne %d , position %d , le nom de la variable est un mot reserve\n ",nb_ligne,nb_colonnes);
                                  int V =VerifAffection((yyvsp[(1) - (5)].chaine));
                                        if(V==-1)
                                          printf("Erreur Semantique: La ligne %d , position %d , la valeur affecter n'est pas du meme type que la variable\n ",nb_ligne,nb_colonnes);
                                        else if (V==-2)
                                          printf("Erreur Semantique: La ligne %d , position %d , operation entre chaine non autoriser\n ",nb_ligne,nb_colonnes);
                                        else if (V==-3)
                                          printf("Erreur Semantique: La ligne %d , position %d , variable affecter vide\n ",nb_ligne,nb_colonnes);
                                  insererVal((yyvsp[(1) - (5)].chaine),(yyvsp[(3) - (5)].chaine));
                            
                ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 131 "synt.y"
    { if(doubleDeclaration((yyvsp[(1) - (3)].chaine))==0)
                                    insererTYPE((yyvsp[(1) - (3)].chaine),sauvType);
                					else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",(yyvsp[(1) - (3)].chaine),nb_ligne,nb_colonnes);
                					if(MotNonReserver((yyvsp[(1) - (3)].chaine))==-1)
                            printf("Erreur Semantique: La ligne %d , position %d , le nom de la variable est un mot reserve\n ",nb_ligne,nb_colonnes);
                          int V =VerifAffection((yyvsp[(1) - (3)].chaine));
                                if(V==-1)
                                  printf("Erreur Semantique: La ligne %d , position %d , la valeur affecter n'est pas du meme type que la variable\n ",nb_ligne,nb_colonnes);
                                else if (V==-2)
                                  printf("Erreur Semantique: La ligne %d , position %d , operation entre chaine non autoriser\n ",nb_ligne,nb_colonnes);
                                else if (V==-3)
                                  printf("Erreur Semantique: La ligne %d , position %d , variable affecter vide\n ",nb_ligne,nb_colonnes);
                          insererVal((yyvsp[(1) - (3)].chaine),(yyvsp[(3) - (3)].chaine));
                           
                ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 149 "synt.y"
    { if((yyvsp[(3) - (4)].entier) < 0)
                                     printf("Erreur Semantique, la taille de tableau %s doit etre positive a la ligne %d, position  %d\n",(yyvsp[(1) - (4)].chaine),nb_ligne,nb_colonnes);
                                  else
                                  {
                                    sprintf(taille, "%d", (yyvsp[(3) - (4)].entier));
                                    int V = insererTailleTab((yyvsp[(1) - (4)].chaine),taille);
                                    if(V==-1)
                                      printf("Erreur Semantique, depassement de la taille du tableau %s a la ligne %d, position  %d\n",(yyvsp[(1) - (4)].chaine),nb_ligne,nb_colonnes);
                                    else if(V==-3)
                                      printf("Erreur Semantique, la taille du tableau %s ne peut pas etre egale a 0 a la ligne %d, position  %d\n",(yyvsp[(1) - (4)].chaine),nb_ligne,nb_colonnes);
                                  }              
;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 161 "synt.y"
    {int V =insererTailleTab((yyvsp[(1) - (4)].chaine),(yyvsp[(3) - (4)].chaine)); 
                                                              if(V==-1)
                                                                printf("Erreur Semantique, depassement de la taille du tableau %s a la ligne %d, position  %d\n",(yyvsp[(1) - (4)].chaine),nb_ligne,nb_colonnes);
                                                              else if(V==-2)
                                                                printf("Erreur Syntaxique: La ligne %d , position %d, syntax error \n ",nb_ligne,nb_colonnes);
                                                              else if(V==-3)
                                                                printf("Erreur Semantique, la taille du tableau %s ne peut pas etre egale a 0 a la ligne %d, position  %d\n",(yyvsp[(1) - (4)].chaine),nb_ligne,nb_colonnes);
                                                              ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 173 "synt.y"
    { if(doubleDeclaration((yyvsp[(1) - (3)].chaine))==0)
                                              insererTYPE((yyvsp[(1) - (3)].chaine),sauvType);
							                             else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",(yyvsp[(1) - (3)].chaine),nb_ligne,nb_colonnes);
					                                 if(MotNonReserver((yyvsp[(1) - (3)].chaine))==-1)
                                              printf("Erreur Semantique: La ligne %d , position %d , le nom de la variable est un mot reserve\n ",nb_ligne,nb_colonnes);
                                          ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 179 "synt.y"
    { if(doubleDeclaration((yyvsp[(1) - (1)].chaine))==0)
                                     insererTYPE((yyvsp[(1) - (1)].chaine),sauvType);
							    else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",(yyvsp[(1) - (1)].chaine),nb_ligne,nb_colonnes);
					             if(MotNonReserver((yyvsp[(1) - (1)].chaine))==-1)
                          printf("Erreur Semantique: La ligne %d , position %d , le nom de la variable est un mot reserve\n ",nb_ligne,nb_colonnes);
                ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 194 "synt.y"
    { if(doubleDeclaration((yyvsp[(1) - (4)].chaine))==0)
                                          printf("Erreur semantique, %s non declaree a la ligne %d , position %d\n",(yyvsp[(1) - (4)].chaine),nb_ligne, nb_colonnes);     
                                        if(verifierConstante((yyvsp[(1) - (4)].chaine))==-1)
                                          printf("Erreur semantique, vous ne pouvez pas affecter une deuxime valeur a la constante de la ligne %d , position %d\n", nb_ligne, nb_colonnes);  
                                        if(VerifBib("ISIL.lang")==-1)
                                          printf("Erreur Semantique: La ligne %d , position %d , bibliotheque ISIL.lang non declare\n ",nb_ligne,nb_colonnes); 
                                        if(MotNonReserver((yyvsp[(1) - (4)].chaine))==-1)
                                          printf("Erreur Semantique: La ligne %d , position %d , le nom de la variable est un mot reserve\n ",nb_ligne,nb_colonnes);
                                        int V =VerifAffection((yyvsp[(1) - (4)].chaine));
                                        if(V==-1)
                                          printf("Erreur Semantique: La ligne %d , position %d , la valeur affecter n'est pas du meme type que la variable\n ",nb_ligne,nb_colonnes);
                                        else if (V==-2)
                                          printf("Erreur Semantique: La ligne %d , position %d , operation entre chaine non autoriser\n ",nb_ligne,nb_colonnes);
                                        else if (V==-3)
                                          printf("Erreur Semantique: La ligne %d , position %d , variable affecter vide\n ",nb_ligne,nb_colonnes);
					      ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 213 "synt.y"
    {savOPR((yyvsp[(2) - (3)].chaine)); 
                                sprintf(express, "%d", (yyvsp[(3) - (3)].entier));  sauvegardeTypeExpression("Entier",express);
                               if(VerifBib("ISIL.lang")==-1)
                                printf("Erreur Semantique: La ligne %d , position %d , bibliotheque ISIL.lang non declare\n ",nb_ligne,nb_colonnes);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 223 "synt.y"
    {sauvegardeTypeExpression((yyvsp[(1) - (1)].chaine)," ");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 224 "synt.y"
    {sprintf(express, "%d", (yyvsp[(1) - (1)].entier));  sauvegardeTypeExpression("Entier",express);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 225 "synt.y"
    {/*sprintf(express,"%d.%02u", (int) $1, (int) (($1 - (int) $1 ) * 100) );*/sprintf(tempVal,"%.3f",(yyvsp[(1) - (1)].floa)); sauvegardeTypeExpression("Reel",tempVal);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 226 "synt.y"
    { sauvegardeTypeExpression("Chaine",(yyvsp[(1) - (1)].chaine)); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 228 "synt.y"
    {savOPR((yyvsp[(1) - (1)].chaine)); 
          if(VerifBib("ISIL.lang")==-1)
              printf("Erreur Semantique: La ligne %d , position %d , bibliotheque ISIL.lang non declare\n ",nb_ligne,nb_colonnes);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 231 "synt.y"
    {   savOPR((yyvsp[(1) - (1)].chaine));
              if(VerifBib("ISIL.lang")==-1)
                printf("Erreur Semantique: La ligne %d , position %d , bibliotheque ISIL.lang non declare\n ",nb_ligne,nb_colonnes);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 234 "synt.y"
    {savOPR((yyvsp[(1) - (1)].chaine));
            if(VerifBib("ISIL.lang")==-1)
              printf("Erreur Semantique: La ligne %d , position %d , bibliotheque ISIL.lang non declare\n ",nb_ligne,nb_colonnes);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 253 "synt.y"
    { if(verifierType((yyvsp[(3) - (7)].chaine),(yyvsp[(5) - (7)].chaine)) ==-1)
                                               printf("Erreur Semantique: La ligne %d , position %d , format invalide\n ",nb_ligne,nb_colonnes);
                                               if(VerifBib("ISIL.io")==-1)
                                                 printf("Erreur Semantique: La ligne %d , position %d , bibliotheque ISIL.io non declare\n ",nb_ligne,nb_colonnes); 
                                               ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 259 "synt.y"
    { if(VerifBib("ISIL.io")==-1)
                                                            printf("Erreur Semantique: La ligne %d , position %d , bibliotheque ISIL.io non declare\n ",nb_ligne,nb_colonnes);
                                                          if(ecritureValide()==-1)
                                                            printf("Erreur Semantique: La ligne %d , position %d , format invalide\n ",nb_ligne,nb_colonnes);
                                                     ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 265 "synt.y"
    {savCh((yyvsp[(1) - (3)].chaine));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 266 "synt.y"
    {savCh((yyvsp[(1) - (1)].chaine));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 268 "synt.y"
    {savVal((yyvsp[(1) - (3)].chaine));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 269 "synt.y"
    {savVal((yyvsp[(1) - (1)].chaine));;}
    break;



/* Line 1455 of yacc.c  */
#line 1890 "synt.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 271 "synt.y"

main()
{
     yyparse();
     afficher();
}
yywrap() {}
yyerror(char* msg){
     printf("Erreur Syntaxique: La ligne %d , position %d, %s \n ",nb_ligne,nb_colonnes, msg);
}


