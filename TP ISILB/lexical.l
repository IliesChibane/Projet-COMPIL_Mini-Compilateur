%{
#include "synt.tab.h"
#include "stdio.h"
int nb_ligne=1;
int nb_colonnes = 1;
%}
lettreMin [a-z]
lettreMax [A-Z]
lettres {lettreMin}|{lettreMax}
chiffres [0-9]
loc {lettres}|{chiffres}
idf {lettres}({loc}|_?{loc})*
idf_v "$"{idf}
chiffres1 [1-9]
idf_tab "@"{idf}"["{chiffres1}"]"
nombre {chiffres}+|"("[-]{chiffres1}{chiffres}*")"
/*nombre {chiffres}+*/
commentaire ##([^#]+|(#[^#]+)+)*##
/*fSigne (\"%[dfs]\")*/

%%
"Import" { nb_colonnes =nb_colonnes+ yyleng; return mc_import; }
"ISIL.io" { nb_colonnes = nb_colonnes+ yyleng; return bib_io;}
"ISIL.lang" { nb_colonnes =nb_colonnes+ yyleng;return bib_lang;}
"public" { nb_colonnes =nb_colonnes+ yyleng;return mc_public;}
"private" { nb_colonnes =nb_colonnes+ yyleng;return mc_private;}
"protected" { nb_colonnes =nb_colonnes+ yyleng;return mc_protected;}
"class" { nb_colonnes =nb_colonnes+ yyleng;return mc_class;}
"Entier" { nb_colonnes =nb_colonnes+ yyleng;return mc_entier;}
"Reel" { nb_colonnes =nb_colonnes+ yyleng;return mc_reel;}
"Chaine" { nb_colonnes =nb_colonnes+ yyleng;return mc_chaine;}
"CONST" { nb_colonnes =nb_colonnes+ yyleng;return mc_const;}
"For" { nb_colonnes =nb_colonnes+ yyleng;return mc_for;}
"In" { nb_colonnes =nb_colonnes+ yyleng;return mc_In;}
"Out" { nb_colonnes =nb_colonnes+ yyleng;return mc_Out;}
{idf_v} { if(yyleng > 25) { printf("\nErreur lexicale: Identificateur a la ligne %d et position %d a une taille de %d , ceci est trop long \n",nb_ligne, nb_colonnes, yyleng); }nb_colonnes =nb_colonnes+ yyleng; return idf_v; }
{idf_tab} { if(yyleng > 25) { printf("\nErreur lexicale: Identificateur a la ligne %d et position %d a une taille de %d , ceci est trop long \n",nb_ligne, nb_colonnes, yyleng); }nb_colonnes =nb_colonnes+ yyleng;return idf_tab;}
{nombre} { nb_colonnes =nb_colonnes+ yyleng;return nb;}
{commentaire}
"\"" { nb_colonnes =nb_colonnes+ yyleng;return g;}
"," { nb_colonnes =nb_colonnes+ yyleng;return vrg;}
"{" { nb_colonnes =nb_colonnes+ yyleng;return aco_ov;}
"}" { nb_colonnes =nb_colonnes+ yyleng;return aco_fr;}
"(" { nb_colonnes =nb_colonnes+ yyleng;return p_ou;}
")" { nb_colonnes =nb_colonnes+ yyleng;return p_fr;}
"+" { nb_colonnes =nb_colonnes+ yyleng;return pls;}
"-" { nb_colonnes =nb_colonnes+ yyleng;return mns;}
"*" { nb_colonnes =nb_colonnes+ yyleng;return mlt;}
"/" { nb_colonnes =nb_colonnes+ yyleng;return divise;}
":=" { nb_colonnes =nb_colonnes+ yyleng; return aft;}
">" { nb_colonnes =nb_colonnes+ yyleng;return sup;}
"<" { nb_colonnes =nb_colonnes+ yyleng;return inf;}
"<=" { nb_colonnes =nb_colonnes+ yyleng; return infe;}
">=" { nb_colonnes =nb_colonnes+ yyleng; return supe;} 
"%c" { nb_colonnes =nb_colonnes+ yyleng; return sfs;}
"%d" { nb_colonnes =nb_colonnes+ yyleng; return sfi;}
"%f" { nb_colonnes =nb_colonnes+ yyleng; return sfr;}
; { nb_colonnes =nb_colonnes+ yyleng; return pvg;}
[ \t]  nb_colonnes++;
[\n] { nb_ligne++;  nb_colonnes=1;}
. {printf("Erreur lexicale a ligne %d et la colonne %d sur l'entite %s\n",nb_ligne,nb_colonnes,yytext);
   return err;  }
