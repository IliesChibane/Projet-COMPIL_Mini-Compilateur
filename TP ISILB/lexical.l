%{
#include "synt.tab.h"
int nb_ligne=1;
%}
lettreMin [a-z]
lettreMax [A-Z]
lettres {lettreMin}|{lettreMax}
chiffres [0-9]
idf "$"{lettres}({lettres}|{chiffres}|_)*
idf_tab "@"{lettres}({lettres}|{chiffres}|_)*
idf_const "$"{lettres}({lettres}|{chiffres}|_)*
nombre {chiffres}+
text ({lettres}|{chiffres})+

%%
import return mc_import;
ISIL.io return bib_io;
ISIL.lang return bib_lang;
public return mc_public;
private return mc_private;
protected return mc_protected;
class return mc_class;
Entier return mc_entier;
Reel return mc_reel;
Chaine return mc_chaine;
Const return mc_const;
Forr return mc_for;
In return mc_In;
Out return mc_Out;
{idf} return idf;
{idf_tab} return idf_tab;
{nombre} return nb;
{text} return text;
"\"" return g;
"##" return commentaire;
"[" return cr_ov;
"]" return cr_fm;
"," return vrg;
"{" return aco_ov;
"}" return aco_fr;
"(" return p_ou;
")" return p_fr;
"+" return pls;
"-" return mns;
"*" return mlt;
"/" return divise;
":=" return aft;
">" return sup;
"<" return inf;
"==" return equal;
"<=" return infe;
">=" return supe;
"%c" return sfs;
"%d" return sfi;
"%f" return sfr;
; return pvg;
[ \t] 
[\n] nb_ligne++;
. {printf("erreur lexicale a ligne %d sur l'entite %s\n",nb_ligne,yytext);
   return err;  }
