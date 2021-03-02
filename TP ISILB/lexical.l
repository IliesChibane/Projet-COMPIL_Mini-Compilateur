%{
#include "synt.tab.h"
#include "stdio.h"
#include "string.h"
#include "fonctions.h"
extern nb_ligne;
extern nb_colonnes;
extern YYSTYPE yylval;
%}

lettreMin [a-z]
lettreMax [A-Z]
lettres {lettreMin}|{lettreMax}
chiffres [0-9]
loc {lettres}|{chiffres}
idf {lettres}({loc}|_?{loc})*
idf_v "$"{idf}
chiffres1 [1-9]
idf_tab "@"{idf}
nombre {chiffres}+|"("?[-]{chiffres1}{chiffres}*")"?
/*nombre {chiffres}+*/
commentaire ##([^#]+|(#[^#]+)+)*##
/*fSigne (\"%[dfs]\")*/

%%
"Import" {yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng; return mc_import; }
"ISIL.io" {yylval.chaine=strdup(yytext); nb_colonnes = nb_colonnes+ yyleng; return bib_io;}
"ISIL.lang" {yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return bib_lang;}
"public" {yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return mc_public;}
"private" {yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return mc_private;}
"protected" {yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return mc_protected;}
"class" {yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return mc_class;}
"Entier" {yylval.chaine=strdup(yytext);  nb_colonnes =nb_colonnes+ yyleng;return mc_entier;}
"Reel" {yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return mc_reel;}
"Chaine" {yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return mc_chaine;}
"CONST" {yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return mc_const;}
"For" {yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return mc_for;}
"In" {yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return mc_In;}
"Out" {yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return mc_Out;}
{idf_v} {inserer(yytext,"idf_v"); yylval.chaine=strdup(yytext); if(yyleng > 25) { printf("\nErreur lexicale: Identificateur %s a la ligne %d et position %d a une taille de %d , ceci est trop long \n",yytext,nb_ligne, nb_colonnes, yyleng); }nb_colonnes =nb_colonnes+ yyleng; return idf_v; }
{idf_tab} {inserer(yytext,"idf_tab"); yylval.chaine=strdup(yytext); if(yyleng > 25) { printf("\nErreur lexicale: Identificateur %s a la ligne %d et position %d a une taille de %d , ceci est trop long \n",yytext, nb_ligne, nb_colonnes, yyleng); }nb_colonnes =nb_colonnes+ yyleng;return idf_tab;}
{nombre} { 
   if(yytext[0]!='(')
      yylval.entier = atoi(yytext); 
   else{
      int x;
      sscanf(yytext,"(%d)",&yylval.entier);
   }
   nb_colonnes =nb_colonnes+ yyleng;return nb;} 
{commentaire}
"\"" { yylval.chaine=strdup(yytext);  nb_colonnes =nb_colonnes+ yyleng;return g;}
"," {  yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return vrg;}
"{" {  yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return aco_ov;}
"}" {  yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return aco_fr;}
"[" {  yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return br_ov;}
"]" {  yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return br_fr;}
"(" {  yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return p_ou;}   
")" {  yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return p_fr;}
"+" {  yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return pls;}
"-" {  yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return mns;}
"*" {  yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return mlt;}
"/" {  yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return divise;}
":=" { yylval.chaine=strdup(yytext);  nb_colonnes =nb_colonnes+ yyleng; return aft;}
">" {  yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return sup;}
"<" {  yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng;return inf;}
"<=" { yylval.chaine=strdup(yytext);  nb_colonnes =nb_colonnes+ yyleng; return infe;}
">=" { yylval.chaine=strdup(yytext);  nb_colonnes =nb_colonnes+ yyleng; return supe;} 
"%c" { yylval.chaine=strdup(yytext);  nb_colonnes =nb_colonnes+ yyleng; return sfs;}
"%d" { yylval.chaine=strdup(yytext);  nb_colonnes =nb_colonnes+ yyleng; return sfi;}
"%f" { yylval.chaine=strdup(yytext);  nb_colonnes =nb_colonnes+ yyleng; return sfr;}
";" {  yylval.chaine=strdup(yytext); nb_colonnes =nb_colonnes+ yyleng; return pvg;}
[ \t]  nb_colonnes++;
[\n] { nb_ligne++;  nb_colonnes=1;}
. {printf("Erreur lexicale a ligne %d et la colonne %d sur l'entite %s\n",nb_ligne,nb_colonnes,yytext);
   return err;  }
