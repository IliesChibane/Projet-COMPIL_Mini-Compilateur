// Programmation de la table des symboles
 //Déclatarion de la structure
		typedef struct
		{
		char NomEntite[20];
		char CodeEntite[20];
		char TypeEntite[20];
		char Constante[20];
		char valeur[20];
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
	strcpy(ts[CompteurTS].Constante,"non");
	strcpy(ts[CompteurTS].valeur,"");
	CompteurTS++;
	}
	}
  //Definir la fonction affichage
	  void afficher ()
	{
	printf("\n/************************Table des symboles**********************************/\n");
	printf("___________________________________________________________________________________\n");
	printf("\t| NomEntite |  CodeEntite | TyepEntite  | Constante     | Valeur  \n");
	printf("___________________________________________________________________________________\n");
	int i=0;
	  while(i<CompteurTS)
	  {
		printf("\t|%10s |%12s | %12s | %12s | %10s\n",ts[i].NomEntite,ts[i].CodeEntite,ts[i].TypeEntite, ts[i].Constante, ts[i].valeur);
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
	//inserer la constante 

	void insererConstante(char entite[], char valeur[])
	{
	int pos;
	pos=recherche(entite);
	strcpy(ts[pos].Constante,"oui");
	strcpy(ts[pos].valeur,valeur);
	}


	int verifierConstante(char entite[]){
         int pos;
	     pos = recherche(entite);
		 if(strcmp(ts[pos].Constante,"oui") == 0){
            if(strcmp(ts[pos].valeur," ") != 0){
                   return -1;
			}
		 }
			return 0;
	}

	int verifierType(char format[], char entite[]){
		int pos;
	        pos=recherche(entite);
        if(strlen(format) != 4) return -1;
		  else{
		        if(format[1] != '%') return -1;
		           else{
                         switch(format[2]){
				               case'f': 
							           if(strcmp(ts[pos].TypeEntite,"Reel") !=0) return -1;
				                        break;
				               case'd': 
							           if(strcmp(ts[pos].TypeEntite,"Entier") !=0) return -1;
				                        break;
				               case's': 
							           if(strcmp(ts[pos].TypeEntite,"Chaine") !=0) return -1;
				                        break; 
				              default : return -1;
			                               }             
		                 }
             }
                                                  }

     