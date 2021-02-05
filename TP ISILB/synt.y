%token mc_import pvg bib_io bib_lang err mc_public 
       mc_private mc_protected mc_class idf aco_ov aco_fr
	   mc_entier mc_reel mc_chaine mc_const vrg idf_tab cr_ov cr_fm
	   pls mns mlt divise nb p_ou p_fr aft mc_for sup inf supe infe  
	   mc_In g sfi sfr sfs mc_Out
%%
S: LISTE_BIB HEADER_CLASS aco_ov CORPS aco_fr{printf("Programme syntaxiquement correct"); 
               YYACCEPT;        }
;
LISTE_BIB: BIB LISTE_BIB
          |
;		  
BIB: mc_import NOM_BIB pvg
;
NOM_BIB: bib_io
         |bib_lang
;

HEADER_CLASS: MODIFICATEUR mc_class idf
;
MODIFICATEUR: mc_public
              |mc_private
		    |mc_protected
              |
; 
CORPS:LISTE_DEC LISTE_INST
;
LISTE_DEC: DEC LISTE_DEC
          |
;
DEC: DEC_VAR
     |DEC_TAB
     |DEC_CONST
;
DEC_VAR: TYPE LISTE_IDF pvg
;
LISTE_IDF: idf vrg LISTE_IDF
          |idf
;	
DEC_TAB: TYPE LISTE_IDF_TAB pvg
;
LISTE_IDF_TAB: idf_tab cr_ov nb cr_fm vrg LISTE_IDF_TAB
              |idf_tab cr_ov nb cr_fm
;
DEC_CONST: mc_const TYPE LISTE_IDF_CONST pvg
;			  
LISTE_IDF_CONST: idf vrg LISTE_IDF_CONST
                |idf
;
	  
TYPE:mc_entier
    |mc_reel
	|mc_chaine
;	
			 			 
LISTE_INST: INST LISTE_INST
;           |

INST:Affection
 |BOUCLE
 |Lecture
 |Ecriture
;

Lecture: mc_In p_ou g SDF g vrg idf p_fr pvg
;
SDF: sfi
     |sfr
     |sfs
; 
Ecriture: mc_Out p_ou g SDF g vrg idf p_fr pvg
;
BOUCLE: mc_for p_ou init condition incre p_fr BC 
;
init: idf aft Expression pvg
;
condition:idf logique IDF_NB pvg
;
logique:   sup
		 |inf
           |supe
           |infe
;
incre: idf pls pls 
;
BC: aco_ov INST aco_fr
;
Affection: idf aft Expression pvg
		   | idf_tab aft  Expression pvg
;

Expression: IDF_NB OPR Expression 
            | IDF_NB
;

IDF_NB: idf
|idf_tab
| nb
;

OPR: pls
     |mlt
     |divise
     |mns
;

		  
%%
main()
{yyparse();}
yywrap() {}
