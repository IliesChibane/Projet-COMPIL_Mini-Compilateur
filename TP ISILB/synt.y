%{
int nb_ligne = 1;
int nb_colonnes = 1;
char sauvType[20];
char tempVal[20];
char taille[10];
char express[100];
%}
%union{
     int entier;
     char* chaine; 
     float floa;
}
%type <chaine> Idf_tab tabID NOM_BIB MODIFICATEUR VAL
%token <chaine>mc_import pvg <chaine>bib_io <chaine>bib_lang err <chaine>mc_public 
       <chaine>mc_private <chaine>mc_protected <chaine>mc_class <chaine>idf_v aco_ov aco_fr
	   <chaine>mc_entier <chaine>mc_reel <chaine>mc_chaine mc_const vrg <chaine>idf_tab
	   pls mns mlt divise <entier>nb p_ou p_fr aft mc_for sup inf supe infe  
	   mc_In g    mc_Out br_ov br_fr <chaine>chaine <floa>reel
%%
S: LISTE_BIB HEADER_CLASS aco_ov CORPS aco_fr{printf("Programme syntaxiquement correct"); 
               YYACCEPT;        }
;
LISTE_BIB: BIB LISTE_BIB
          |
;		  
BIB: mc_import NOM_BIB pvg { if(doubleDeclaration($2)==0)
                                     insererTYPE($2,"BIB");
							    else printf("Erreur Semantique: double declaration de la bibliotheque %s a la ligne %d , position %d\n",$1,nb_ligne,nb_colonnes);
					      }
;
NOM_BIB: bib_io
         |bib_lang
;
HEADER_CLASS: MODIFICATEUR mc_class idf_v{ if(doubleDeclaration($3)==0)
                                     insererTYPE($3,"Classe");
							    else printf("Erreur Semantique: double declaration  de la classe %s a la ligne %d , position %d\n",$1,nb_ligne,nb_colonnes);
					      }
;
MODIFICATEUR: mc_public
              |mc_private
		      |mc_protected
              |{ strcpy($$, "");}
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
DEC_CONST: mc_const TYPE LISTE_CONST pvg
;			
LISTE_CONST: idf_v vrg LISTE_CONST{  insererConstante($1,""); 
                                     if(doubleDeclaration($1)==0)
                                     insererTYPE($1,sauvType);
							    else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",$1,nb_ligne,nb_colonnes);
					      }
             |idf_v{                     insererConstante($1,""); 
                                         if(doubleDeclaration($1)==0)
                                          insererTYPE($1,sauvType);
							      else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",$1,nb_ligne,nb_colonnes);
					      }
             |idf_v aft VAL{   
                                       
                                      insererConstante($1,$3);   
                                       if(doubleDeclaration($1)==0)
                                       insererTYPE($1,sauvType);
							    else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",$1,nb_ligne,nb_colonnes);
					      }
             |idf_v aft VAL vrg LISTE_CONST{
                                            
                                             insererConstante($1,$3);                                       
                                             if(doubleDeclaration($1)==0)
                                             insererTYPE($1,sauvType);
							          else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",$1,nb_ligne,nb_colonnes);
					      }
;
VAL: nb {

  sprintf(tempVal,"%d",$1);
   $$ = tempVal;
  /*sprintf(express, "%d", $1);*/ sauvegardeTypeExpression("Entier",tempVal);
}
     |chaine {
  sprintf(tempVal,"%s",$1);
   $$ = tempVal;
  sauvegardeTypeExpression("Chaine",$1);
}
     |reel {
    sprintf(tempVal,"%.3f",$1);
     $$ = tempVal;
    /*sprintf(express,"%d.%02u", (int) $1, (int) (($1 - (int) $1 ) * 100) );*/  sauvegardeTypeExpression("Reel",tempVal);
}
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
                					        if(MotNonReserver($1)==-1)
                                    printf("Erreur Semantique: La ligne %d , position %d , le nom de la variable est un mot reserve\n ",nb_ligne,nb_colonnes);
                }
          |idf_v { if(doubleDeclaration($1)==0)
                                    insererTYPE($1,sauvType);
                							    else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",$1,nb_ligne,nb_colonnes);
                					        if(MotNonReserver($1)==-1)
                                    printf("Erreur Semantique: La ligne %d , position %d , le nom de la variable est un mot reserve\n ",nb_ligne,nb_colonnes);
                  }
          |idf_v aft VAL vrg LISTE_IDF{ if(doubleDeclaration($1)==0)
                                    insererTYPE($1,sauvType);
                							    else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",$1,nb_ligne,nb_colonnes);
                					        if(MotNonReserver($1)==-1)
                                    printf("Erreur Semantique: La ligne %d , position %d , le nom de la variable est un mot reserve\n ",nb_ligne,nb_colonnes);
                                  int V =VerifAffection($1);
                                        if(V==-1)
                                          printf("Erreur Semantique: La ligne %d , position %d , la valeur affecter n'est pas du meme type que la variable\n ",nb_ligne,nb_colonnes);
                                        else if (V==-2)
                                          printf("Erreur Semantique: La ligne %d , position %d , operation entre chaine non autoriser\n ",nb_ligne,nb_colonnes);
                                        else if (V==-3)
                                          printf("Erreur Semantique: La ligne %d , position %d , variable affecter vide\n ",nb_ligne,nb_colonnes);
                                  insererVal($1,$3);
                            
                }
          |idf_v aft VAL{ if(doubleDeclaration($1)==0)
                                    insererTYPE($1,sauvType);
                					else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",$1,nb_ligne,nb_colonnes);
                					if(MotNonReserver($1)==-1)
                            printf("Erreur Semantique: La ligne %d , position %d , le nom de la variable est un mot reserve\n ",nb_ligne,nb_colonnes);
                          int V =VerifAffection($1);
                                if(V==-1)
                                  printf("Erreur Semantique: La ligne %d , position %d , la valeur affecter n'est pas du meme type que la variable\n ",nb_ligne,nb_colonnes);
                                else if (V==-2)
                                  printf("Erreur Semantique: La ligne %d , position %d , operation entre chaine non autoriser\n ",nb_ligne,nb_colonnes);
                                else if (V==-3)
                                  printf("Erreur Semantique: La ligne %d , position %d , variable affecter vide\n ",nb_ligne,nb_colonnes);
                          insererVal($1,$3);
                           
                }
;	
DEC_TAB: TYPE LISTE_IDF_TAB pvg
;
Idf_tab: idf_tab br_ov nb br_fr{ if($3 < 0)
                                     printf("Erreur Semantique, la taille de tableau %s doit etre positive a la ligne %d, position  %d\n",$1,nb_ligne,nb_colonnes);
                                  else
                                  {
                                    sprintf(taille, "%d", $3);
                                    int V = insererTailleTab($1,taille);
                                    if(V==-1)
                                      printf("Erreur Semantique, depassement de la taille du tableau %s a la ligne %d, position  %d\n",$1,nb_ligne,nb_colonnes);
                                    else if(V==-3)
                                      printf("Erreur Semantique, la taille du tableau %s ne peut pas etre egale a 0 a la ligne %d, position  %d\n",$1,nb_ligne,nb_colonnes);
                                  }              
}
                                 |idf_tab br_ov tabID br_fr {int V =insererTailleTab($1,$3); 
                                                              if(V==-1)
                                                                printf("Erreur Semantique, depassement de la taille du tableau %s a la ligne %d, position  %d\n",$1,nb_ligne,nb_colonnes);
                                                              else if(V==-2)
                                                                printf("Erreur Syntaxique: La ligne %d , position %d, syntax error \n ",nb_ligne,nb_colonnes);
                                                              else if(V==-3)
                                                                printf("Erreur Semantique, la taille du tableau %s ne peut pas etre egale a 0 a la ligne %d, position  %d\n",$1,nb_ligne,nb_colonnes);
                                                              }
;
tabID: Idf_tab 
       |idf_v
;
LISTE_IDF_TAB: Idf_tab vrg LISTE_IDF_TAB { if(doubleDeclaration($1)==0)
                                              insererTYPE($1,sauvType);
							                             else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",$1,nb_ligne,nb_colonnes);
					                                 if(MotNonReserver($1)==-1)
                                              printf("Erreur Semantique: La ligne %d , position %d , le nom de la variable est un mot reserve\n ",nb_ligne,nb_colonnes);
                                          }
               |Idf_tab { if(doubleDeclaration($1)==0)
                                     insererTYPE($1,sauvType);
							    else printf("Erreur Semantique: double declaration  de %s a la ligne %d , position %d\n",$1,nb_ligne,nb_colonnes);
					             if(MotNonReserver($1)==-1)
                          printf("Erreur Semantique: La ligne %d , position %d , le nom de la variable est un mot reserve\n ",nb_ligne,nb_colonnes);
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
                                        if(verifierConstante($1)==-1)
                                          printf("Erreur semantique, vous ne pouvez pas affecter une deuxime valeur a la constante de la ligne %d , position %d\n", nb_ligne, nb_colonnes);  
                                        if(VerifBib("ISIL.lang")==-1)
                                          printf("Erreur Semantique: La ligne %d , position %d , bibliotheque ISIL.lang non declare\n ",nb_ligne,nb_colonnes); 
                                        if(MotNonReserver($1)==-1)
                                          printf("Erreur Semantique: La ligne %d , position %d , le nom de la variable est un mot reserve\n ",nb_ligne,nb_colonnes);
                                        int V =VerifAffection($1);
                                        if(V==-1)
                                          printf("Erreur Semantique: La ligne %d , position %d , la valeur affecter n'est pas du meme type que la variable\n ",nb_ligne,nb_colonnes);
                                        else if (V==-2)
                                          printf("Erreur Semantique: La ligne %d , position %d , operation entre chaine non autoriser\n ",nb_ligne,nb_colonnes);
                                        else if (V==-3)
                                          printf("Erreur Semantique: La ligne %d , position %d , variable affecter vide\n ",nb_ligne,nb_colonnes);
					      }
;
Expression: IDF_NB OPR Expression 
            |IDF_NB
            |IDF_NB divise nb {savOPR($2); 
                               if(VerifBib("ISIL.lang")==-1)
                                printf("Erreur Semantique: La ligne %d , position %d , bibliotheque ISIL.lang non declare\n ",nb_ligne,nb_colonnes);}
;
 
IDF_NB: IDF_NBB
        |Idf_tab

;
IDF_NBB: idf_v {sauvegardeTypeExpression($1," ");}
         |nb {sprintf(express, "%d", $1);  sauvegardeTypeExpression("Entier",express);}
         |reel {/*sprintf(express,"%d.%02u", (int) $1, (int) (($1 - (int) $1 ) * 100) );*/sprintf(tempVal,"%.3f",$1); sauvegardeTypeExpression("Reel",tempVal);}
         |chaine { sauvegardeTypeExpression("Chaine",$1); }
; 
OPR: pls {savOPR($1); 
          if(VerifBib("ISIL.lang")==-1)
              printf("Erreur Semantique: La ligne %d , position %d , bibliotheque ISIL.lang non declare\n ",nb_ligne,nb_colonnes);}
     |mlt {   savOPR($1);
              if(VerifBib("ISIL.lang")==-1)
                printf("Erreur Semantique: La ligne %d , position %d , bibliotheque ISIL.lang non declare\n ",nb_ligne,nb_colonnes);}
     |mns {savOPR($1);
            if(VerifBib("ISIL.lang")==-1)
              printf("Erreur Semantique: La ligne %d , position %d , bibliotheque ISIL.lang non declare\n ",nb_ligne,nb_colonnes);}
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
Lecture: mc_In p_ou chaine vrg idf_v p_fr pvg{ if(verifierType($3,$5) ==-1)
                                               printf("Erreur Semantique: La ligne %d , position %d , format invalide\n ",nb_ligne,nb_colonnes);
                                               if(VerifBib("ISIL.io")==-1)
                                                 printf("Erreur Semantique: La ligne %d , position %d , bibliotheque ISIL.io non declare\n ",nb_ligne,nb_colonnes); 
                                               }
;
Ecriture: mc_Out p_ou List_chaine vrg List_val p_fr pvg { if(VerifBib("ISIL.io")==-1)
                                                            printf("Erreur Semantique: La ligne %d , position %d , bibliotheque ISIL.io non declare\n ",nb_ligne,nb_colonnes);
                                                          if(ecritureValide()==-1)
                                                            printf("Erreur Semantique: La ligne %d , position %d , format invalide\n ",nb_ligne,nb_colonnes);
                                                     }
;	
List_chaine: chaine pls List_chaine {savCh($1);}
              | chaine {savCh($1);}
;
List_val: idf_v  vrg List_val {savVal($1);}
          | idf_v {savVal($1);}
;
%%
main()
{
     yyparse();
     afficher();
}
yywrap() {}
yyerror(char* msg){
     printf("Erreur Syntaxique: La ligne %d , position %d, %s \n ",nb_ligne,nb_colonnes, msg);
}

