// Programmation de la table des symboles
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 //Déclatarion de la structure
		typedef struct
		{
		char NomEntite[20];
		char CodeEntite[20];
		char TypeEntite[20];
		char Constante[20];
		char valeur[20];
		int taille;
		} TypeTS;

		//Déclaration de la table des symboles sous forme de liste chainee
		typedef struct TS
		{
    		TypeTS tabS;
    		struct TS *svt;
		}TS;

		//Liste contenant le type des valeurs qui ne sont pas des variables exp : 5 est de type reel "faux" est de type chaine...
		typedef struct TE
		{
    		char *te,*ve;
    		struct TE *svt;
		}TE;

		//Liste contenant les chaines a afficher ainsi que leur types
		typedef struct OUT
		{
    		char *ch,*val;
    		struct OUT *svt;
		}OUT;
		//Initialisation de la table des symboles
        TS *TableSymbole=NULL,*r,*q; 
		//Declarer un compteur global
        int CompteurTS=0;
        //Initialisation de la liste des expression
        TE *typeExp=NULL,*qq,*rr;
        //Initialisation de la liste des valeurs a afficher dans out()
        OUT *o;
        //table des mots reserver
        char *mr[] = {"$Entier","$Reel","$Chaine","$CONST","$For","$Out","$In","$public","$private","$protected","$class","$Import"};
		
  //Definir la fonction recherche
		TS *recherche(char entite[])
		{
		int i=0;
		TS *ll=TableSymbole;
		
		while(ll!=NULL)
		{
		if (strcmp(entite,ll->tabS.NomEntite)==0) return ll;
		ll=ll->svt;
		}
		return NULL;
		}

		TS *recherchepre(char entite[])
		{
		int i=0;
		TS *ll=TableSymbole,*pr=NULL;
		
		while(ll!=NULL)
		{
			if (strcmp(entite,ll->tabS.NomEntite)==0) return pr;
				pr=ll;
				ll=ll->svt;
		}
		return NULL;
		}

  //Verifie si la variable n'a pas le meme qu'un mot reserver
  int MotNonReserver(char entite[])
  {
  	int i;
  	for(i=0;i<12;i++)
  	{
  		if(strcmp(entite,mr[i])==0){
  			TS *supp = recherche(entite),*pre=recherchepre(entite);
  			//dans le cas ou la variable a le meme qu'un mot reserver on le supprime de la table des symboles
  			if((pre!=NULL))
  			{
  				pre->svt = NULL;
  				q=pre;
  			}
  			else
  			{
  				TableSymbole=NULL;
  			}
  			return -1;
  		}		
  	}
  	return 1;
  }		
  //Definir la fonction insertion
  void inserer(char entite[], char code[])
	{
		if ((recherche(entite)==NULL))
		{
			
			if(TableSymbole==NULL)
			{
				TableSymbole = (TS *) malloc(sizeof (TS));
				strcpy(TableSymbole->tabS.NomEntite,entite); 
				strcpy(TableSymbole->tabS.CodeEntite,code);
				strcpy(TableSymbole->tabS.Constante,"non");
				strcpy(TableSymbole->tabS.TypeEntite,"type");
				strcpy(TableSymbole->tabS.valeur,"");
				if(strcmp(TableSymbole->tabS.CodeEntite,"idf_tab")==0)
					TableSymbole->tabS.taille =0;
				else
					TableSymbole->tabS.taille =1;
				CompteurTS++;
				TableSymbole->svt = NULL;
				q = TableSymbole;
			}
			else
			{
				r = (TS *) malloc(sizeof (TS));
				strcpy(r->tabS.NomEntite,entite); 
				strcpy(r->tabS.CodeEntite,code);
				strcpy(r->tabS.Constante,"non");
				strcpy(r->tabS.TypeEntite,"type");
				strcpy(r->tabS.valeur,"");
				if(strcmp(r->tabS.CodeEntite,"idf_tab")==0)
					r->tabS.taille =0;
				else
					r->tabS.taille =1;
				CompteurTS++;
				r->svt = NULL;
				q->svt = r;
				q = r;
			}
		}
	}
  //Definir la fonction affichage
	  void afficher ()
	{
	printf("\n/************************Table des symboles**********************************/\n");
	printf("___________________________________________________________________________________\n");
	printf("\t| NomEntite |  CodeEntite | TyepEntite  | Constante     | Valeur | Taille  \n");
	printf("___________________________________________________________________________________\n");
	int i=0;
	   TS *ll=TableSymbole;
	   while(ll!=NULL)
	   {
	   	printf("\t|%10s |%12s | %12s | %12s | %10s | %d\n",ll->tabS.NomEntite,ll->tabS.CodeEntite,ll->tabS.TypeEntite, ll->tabS.Constante, ll->tabS.valeur, ll->tabS.taille);
	   	ll=ll->svt;
	   }
	}
	
	//Definir la fonction d'insertion du type
	
	 void insererTYPE(char entite[], char type[])
	{
		
       TS *pos=recherche(entite);
	if(pos!=NULL){
	   strcpy(pos->tabS.TypeEntite,type); 	}
	}

    //Definir la fonction de la double declaration
	int doubleDeclaration(char entite[])
	{
	TS *pos;
	pos=recherche(entite);
	if(strcmp(pos->tabS.TypeEntite,"type")==0) return 0;
	   else return -1;
	}
	//inserer la constante 

	void insererConstante(char entite[], char valeur[])
	{
	TS *pos;
	pos=recherche(entite);
	strcpy(pos->tabS.Constante,"oui");
	if(valeur[0]=='\"'){
          strncpy(pos->tabS.valeur,valeur+1,strlen(valeur)-2);
	}else	strcpy(pos->tabS.valeur,valeur);

	}


	int verifierConstante(char entite[]){
         TS *pos;
	     pos = recherche(entite);
		 if(strcmp(pos->tabS.Constante,"oui") == 0){
            if(strcmp(pos->tabS.valeur," ") != 0){
                   return -1;
			}
		 }
			return 0;
	}

	int verifierType(char format[], char entite[]){
		TS *pos;
	        pos=recherche(entite);
        if(strlen(format) != 4) return -1;
		  else{
		        if(format[1] != '%') return -1;
		           else{
                         switch(format[2]){
				               case'f': 
							           if(strcmp(pos->tabS.TypeEntite,"Reel") !=0) return -1;
				                        break;
				               case'd': 
							           if(strcmp(pos->tabS.TypeEntite,"Entier") !=0) return -1;
				                        break;
				               case's' :
							           if(strcmp(pos->tabS.TypeEntite,"Chaine") !=0) return -1;
				                        break; 
				              default : return -1;
			                               }             
		                 }
             }
                                                  }


//insere la' taille des variable et des tableau dans ma table des symboles
int insererTailleTab(char entite[],char taille[])
	{
		TS *pos = recherche(entite);
		TS *pos1 = recherche(taille);

		if(pos1==NULL){
			int t = atoi(taille);
		
			if(pos!=NULL){
				if(pos->tabS.taille==0)
				{
					
					if(t!=0){pos->tabS.taille = t;

					return 1;}
					else
						return-3;
				}else{
					if(pos->tabS.taille<=t)
						return -1;
				}
				return 1;
			}
		}
		else
		{
			if(strcmp(pos1->tabS.TypeEntite,"Reel")==0)
				return-2;
			int t = atoi(pos1->tabS.valeur);

			if(pos!=NULL){
				if(pos->tabS.taille==0)
				{
					if(t!=0){pos->tabS.taille = t;

					return 1;}
					else
						return-3;
				}else{
					if(pos->tabS.taille<=t)
						return -1;
				}
				return 1;
		}
	}}

//Verifie si la bib a ete declarer ou non
int VerifBib(char BIB[])
{
	if(recherche(BIB)==NULL)
		return -1;
	else return 1;
}

//sauvegarde le type d'une expression (fontion utiliser au niveau de l'affectation)
void sauvegardeTypeExpression(char entite[],char val[])
{
	if(strcmp(entite,"Chaine")==0)
	{
		char *inter = (char*) malloc((strlen(val)-2)*sizeof(char));
		int l = 0;
		while(l<(strlen(val)-2))
		{
			inter[l] = val[l+1];
			l++;
		}
		strcpy(val,inter);
	}
	if(typeExp==NULL)
	{
		typeExp = (TE *) malloc(sizeof (TE));
		typeExp->te = (char*) malloc(strlen(entite)*sizeof(char));
		typeExp->ve = (char*) malloc(strlen(val)*sizeof(char));
		strcpy(typeExp->te,entite);
		strcpy(typeExp->ve,val);
		typeExp->svt = NULL;
		qq=typeExp;
	}
	else{
		rr =(TE *) malloc(sizeof (TE));
		rr->te = (char*) malloc(strlen(entite)*sizeof(char));
		rr->ve = (char*) malloc(strlen(val)*sizeof(char));
		strcpy(rr->te,entite);
		strcpy(rr->ve,val);
		rr->svt = NULL;
		qq->svt=rr;
		qq=rr;
	}
	
}

//vide la liste des expression
void videTypeExp()
{
	TE *e=typeExp->svt;
	while(typeExp->svt!=NULL)
	{
		free(typeExp);
		typeExp=e;
		e=typeExp->svt;
	}
	typeExp = NULL;

}

//sauvegarde l operation utiliser dans l'affectation
//Liste contenant les chaines a afficher ainsi que leur types
typedef struct PILEOPR
{
    char *o;
    struct PILEOPR *svt;
}PILEOPR;
PILEOPR *opr,*qopr,*ropr;
void savOPR(char entite[])
{
	if(opr==NULL)
	{
		opr = (PILEOPR*) malloc(sizeof(PILEOPR));
		opr->o=(char*) malloc(strlen(entite)*sizeof(char));
	    strcpy(opr->o,entite);
	    qopr = opr;
	}
	else
	{
		ropr = (PILEOPR*) malloc(sizeof(PILEOPR));
		ropr->o=(char*) malloc(strlen(entite)*sizeof(char));
	    strcpy(ropr->o,entite);
	    qopr->svt = ropr;
	    qopr = ropr;
	}
}

void insererVal(char entite[],char val[])
{
	TS *pos = recherche(entite);
	if(strcmp(pos->tabS.CodeEntite,"idf_tab")!=0)
		strcpy(pos->tabS.valeur,val);
}

//verifie si l'affectation est valide ou non
int VerifAffection(char entite[])
{
	TE *e=typeExp;
	TS *pos = recherche(entite),*pos2; 
	char *typeAffect,ac[1000] = "",final[1000];
	int ae=0;
	float ar=0;

	if(opr!=NULL){
		pos2 = recherche(e->te);
		if((pos2!=NULL)&&(strcmp(pos2->tabS.TypeEntite,"Entier")==0))
			ae = ae+atoi(pos2->tabS.valeur);
		else if (strcmp(e->te,"Entier")==0)
			ae = ae+atoi(e->ve);
		e = e->svt;
	}
	
	while(e!=NULL){
		pos2 = recherche(e->te);
		if(pos2!=NULL)
		{
			if(strcmp(pos->tabS.TypeEntite,pos2->tabS.TypeEntite)!=0)
			{
				videTypeExp();
				opr = NULL;
				return -1;
			}
			else{
				if(strcmp(pos2->tabS.valeur,"")!=0)
				{
					if(strcmp(pos2->tabS.TypeEntite,"Entier")==0)
					{
						if(opr!=NULL){
							if(strcmp(opr->o,"*")==0)
								ae=ae*atoi(pos2->tabS.valeur);
							else if(strcmp(opr->o,"+")==0)
								ae=ae+atoi(pos2->tabS.valeur);
							else if(strcmp(opr->o,"-")==0)
								ae=ae-atoi(pos2->tabS.valeur);
							else
								ae=ae/atoi(pos2->tabS.valeur);
						}else
						{
							ae=ae+atoi(pos2->tabS.valeur);
						}
					}
					else if(strcmp(pos2->tabS.TypeEntite,"Reel")==0)
					{
						if(opr!=NULL){
							if(strcmp(opr->o,"*")==0)
								ar=ar*atoi(pos2->tabS.valeur);
							else if(strcmp(opr->o,"+")==0)
								ar=ar+atoi(pos2->tabS.valeur);
							else if(strcmp(opr->o,"-")==0)
								ar=ar-atoi(pos2->tabS.valeur);
							else
								ar=ar/atoi(pos2->tabS.valeur);
						}else
						{
							ar=ar+atoi(pos2->tabS.valeur);
						}
					}
					else
					{
						strcat(ac,pos2->tabS.valeur);
					}
					typeAffect = (char*) malloc(strlen(pos2->tabS.TypeEntite)*sizeof(char));
					strcpy(typeAffect,pos2->tabS.TypeEntite);
				}
				else
				{
					opr = NULL;
					return-3;
				}
			}
		}
		else{
			if(strcmp(pos->tabS.TypeEntite,e->te)!=0)
			{
				videTypeExp();
				opr = NULL;
				return -1;
			}
			else{
					if(strcmp(e->te,"Entier")==0)
					{
						if(opr!=NULL){
							if(strcmp(opr->o,"*")==0)
								ae=ae*atoi(e->ve);
							else if(strcmp(opr->o,"+")==0)
								ae=ae+atoi(e->ve);
							else if(strcmp(opr->o,"-")==0)
								ae=ae-atoi(e->ve);
							else if(strcmp(opr->o,"/")==0)
							{
								ae=ae/atoi(e->ve);
							}
						}else
						{
							ae=ae+atoi(e->ve);
						}
					}
					else if(strcmp(e->te,"Reel")==0)
					{
						if(opr!=NULL){
							if(strcmp(opr->o,"*")==0)
								ar=ar*atoi(e->ve);
							else if(strcmp(opr->o,"+")==0)
								ar=ar+atoi(e->ve);
							else if(strcmp(opr->o,"-")==0)
								ar=ar-atoi(e->ve);
							else if(strcmp(opr->o,"/")==0)
							{
								ar=ar/atoi(e->ve);
							}
						}else
						{
							ar=ar+atoi(e->ve);
						}
					}
					else
					{
						strcat(ac,e->ve);
					}
					typeAffect = (char*) malloc(strlen(e->te)*sizeof(char));
					strcpy(typeAffect,e->te);
			}
		}
		if(opr!=NULL){
		if((strcmp(opr->o,"*")==0)||(strcmp(opr->o,"-")==0))
		{
		if(pos2!=NULL)
		{

			if(strcmp(pos2->tabS.TypeEntite,"Chaine")==0)
			{
				videTypeExp();
				opr = NULL;
				return -2;
			}
		}
		else{
			if(strcmp(e->te,"Chaine")==0)
			{
				videTypeExp();
				opr = NULL;
				return -2;
			}
		}
		}}
		e=e->svt;
		if(opr!=NULL)
			opr = opr->svt;
	}
	if(strcmp(typeAffect,"Entier")==0)
		sprintf(final, "%d", ae);
	else if(strcmp(typeAffect,"Reel")==0)
		sprintf(final, "%f", ar);
	else
		strcpy(final,ac);
	
	insererVal(entite,final);
	videTypeExp();
	opr = NULL;
	return 1;
}

int nbidf=0,nbch=0;

int savCh(char entite[])
{
	nbch++;
	OUT *u,*q;
	if(o==NULL){
		o = (OUT*) malloc(sizeof(OUT));
		o->ch = (char*) malloc(strlen(entite)*sizeof(char));
		strcpy(o->ch,entite);
		o->svt = NULL;
		o->val=NULL;
		q=o;
	}
	else
	{
		u = (OUT*) malloc(sizeof(OUT));
		u->ch = (char*) malloc(strlen(entite)*sizeof(char));
		strcpy(u->ch,entite);
		u->svt = NULL;
		u->val=NULL;
		q->svt=u;
		q=u;
	}
		
}

int savVal(char entite[])
{
	nbidf++;
	int i=1;
	OUT *u;
	if(o!=NULL){
		u=o;
		while((i<nbidf)&&(u->svt!=NULL))
		{
			u=u->svt;
			i++;
		}
		if(u->val==NULL)
		{
			u->val = (char*) malloc(strlen(entite)*sizeof(char));
			strcpy(u->val,entite);
		}
		else{
			OUT *ou = (OUT*) malloc(sizeof(OUT));
			ou->val = (char*) malloc(strlen(entite)*sizeof(char));
			strcpy(ou->val,entite);
			u->svt = ou;
		}
	}
	else{
		o = (OUT*) malloc(sizeof(OUT));
		o->val = (char*) malloc(strlen(entite)*sizeof(char));
		strcpy(o->val,entite);
		o->svt = NULL;
	}
}

//verifie si l'operation out est valide
int ecritureValide()
{
	OUT *u;
	u=o;
	if(nbidf!=nbch) 
		return -1;
	
	while(u!=NULL)
	{
		if(verifierType(u->ch,u->val) ==-1)
			return-1;
		u=u->svt;
	}
	return 1;
}

