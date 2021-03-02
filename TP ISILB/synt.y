%{
int nb_ligne = 1;
int nb_colonnes = 1;
char sauvType[20];
%}
%union{
     int entier;
     char* chaine; 
}

%type <chaine> Idf_tab tabID
%token mc_import pvg bib_io bib_lang err mc_public 
       mc_private mc_protected mc_class <chaine>idf_v aco_ov aco_fr
	   <chaine>mc_entier <chaine>mc_reel <chaine>mc_chaine mc_const vrg <chaine>idf_tab
	   pls mns mlt divise <entier>nb p_ou p_fr aft mc_for sup inf supe infe  
	   mc_In g sfi sfr sfs mc_Out br_ov br_fr
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
TYPE: mc_entier {strcpy(sauvType,$1);}
      |mc_reel {strcpy(sauvType,$1);}
	 |mc_chaine {strcpy(sauvType,$1);}
;
LISTE_IDF: idf_v vrg LISTE_IDF { if(doubleDeclaration($1)==0)
                                     insererTYPE($1,sauvType);
							    else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n", $1, nb_ligne, nb_colonnes);
					      }
          |idf_v { if(doubleDeclaration($1)==0)
                                     insererTYPE($1,sauvType);
							    else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",$1,nb_ligne,nb_colonnes);
					      }
;	
DEC_TAB: TYPE LISTE_IDF_TAB pvg
;
Idf_tab: idf_tab br_ov nb br_fr{ if($3 < 0)
                                     printf("Erreur Semantique, la taille de tableau %s doit etre positive a la ligne %d, position  %d\n",$1,nb_ligne,nb_colonnes);              
}
         |idf_tab br_ov tabID br_fr
;
tabID: Idf_tab
       |idf_v
;
LISTE_IDF_TAB: Idf_tab vrg LISTE_IDF_TAB { if(doubleDeclaration($1)==0)
                                     insererTYPE($1,sauvType);
							    else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",$1,nb_ligne,nb_colonnes);
					      }
              |Idf_tab { if(doubleDeclaration($1)==0)
                                     insererTYPE($1,sauvType);
							    else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",$1,nb_ligne,nb_colonnes);
					      }
;			 			 
LISTE_INST: INST LISTE_INST
           |
;
INST: Affectation
      |BOUCLE
      |Lecture
      |Ecriture
;
Affectation: tabID aft Expression pvg { if(doubleDeclaration($1)==0)
                                          printf("Erreur semantique, %s non declaree a la ligne %d , position %d\n",$1,nb_ligne, nb_colonnes);
					      }
;
Expression: IDF_NB OPR Expression
            |IDF_NB
            |IDF_NB divise nb{ if($3 == 0)
                               printf("Erreur semantique, DIVISION PAR ZERO a la ligne %d , position %d\n", nb_ligne, nb_colonnes);}
;
IDF_NB: IDF_NBB
        |Idf_tab

;
IDF_NBB: idf_v
         |nb
; 
OPR: pls
     |mlt
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
BC: aco_ov LISTE_INST aco_fr
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
     afficher();
}
yywrap() {}
yyerror(char* msg){
     printf("Erreur Syntaxique: La ligne %d , position %d \n ",nb_ligne,nb_colonnes);
}
