// Programmation de la table des symboles
 //Déclatarion de la structure
 
		typedef struct
		{
		char NomEntite[20];
		char CodeEntite[20];
		char TypeEntite[20];
		} TypeTS;
		//Initialisation de la structure
        TypeTS ts[100]; 
		//Declarer un compteur global
        int CompteurTS=0;
		
  //Definir la fonction recherche
		int recherche(char entite[])
		{
		int i=0;
		while(i<CompteurTS)
		{
		if (strcmp(entite,ts[i].NomEntite)==0) return i;
		i++;
		}

		return -1;
		}
		
  //Definir la fonction insertion
  void inserer(char entite[], char code[])
	{

	if ( recherche(entite)==-1)
	{
	strcpy(ts[CompteurTS].NomEntite,entite); 
	strcpy(ts[CompteurTS].CodeEntite,code);
	CompteurTS++;
	}
	}
  //Definir la fonction affichage
	  void afficher ()
	{
	printf("\n/***************Table des symboles ******************/\n");
	printf("_____________________________________________________\n");
	printf("\t| NomEntite |  CodeEntite | TyepEntite\n");
	printf("_____________________________________________________\n");
	int i=0;
	  while(i<CompteurTS)
	  {
		printf("\t|%10s |%12s | %12s\n",ts[i].NomEntite,ts[i].CodeEntite,ts[i].TypeEntite);
		 i++;
	   }
	}
	
	//Definir la fonction d'insertion du type
	
	 void insererTYPE(char entite[], char type[])
	{
       int pos=recherche(entite);
	if(pos!=-1)
	   strcpy(ts[pos].TypeEntite,type); 	
	}

    //Definir la fonction de la double declaration
	int doubleDeclaration(char entite[])
	{
	int pos;
	pos=recherche(entite);
	if(strcmp(ts[pos].TypeEntite,"")==0) return 0;
	   else return -1;
	}
	 

     