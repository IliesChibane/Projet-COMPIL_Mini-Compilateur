%token mc_import pvg bib_io bib_lang err mc_public 
       mc_private mc_protected mc_class idf_v aco_ov aco_fr
	   mc_entier mc_reel mc_chaine mc_const vrg idf_tab
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
HEADER_CLASS: MODIFICATEUR mc_class idf_v
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
DEC_CONST: mc_const DEC_VAR
;			  
DEC_VAR: TYPE LISTE_IDF pvg
;
TYPE: mc_entier
      |mc_reel
	 |mc_chaine
;
LISTE_IDF: idf_v vrg LISTE_IDF
          |idf_v
;	
DEC_TAB: TYPE LISTE_IDF_TAB pvg
;
LISTE_IDF_TAB: idf_tab vrg LISTE_IDF_TAB
              |idf_tab
;			 			 
LISTE_INST: INST LISTE_INST
           |
;
INST: Affectation
      |BOUCLE
      |Lecture
      |Ecriture
;
Affectation: idf_v aft Expression pvg
		   | idf_tab aft  Expression pvg
;
Expression: IDF_NB OPR Expression 
            |IDF_NB
;
IDF_NB: IDF_NBB
        |idf_tab

;
IDF_NBB: idf_v
         |nb
; 
OPR: pls
     |mlt
     |divise
     |mns
;
BOUCLE: mc_for p_ou init pvg condition pvg incre p_fr BC 
;
init: idf_v aft Expression 
;
condition:idf_v logique IDF_NBB 
;
logique:   sup
		 |inf
           |supe
           |infe
;
incre: idf_v pls pls 
;      
BC: aco_ov INST aco_fr
;
Lecture: mc_In p_ou g SDF g vrg idf_v p_fr pvg
;
Ecriture: mc_Out p_ou g SDF g vrg idf_v p_fr pvg
;
SDF: sfi
     |sfr
     |sfs
; 	

%%
main()
{
     yyparse();
}
yywrap() {}
