typedef struct
{
char NomEntite[20];
char CodeEntite[20];
char TypeEntite[20];
} TypeTS;

//initiation d'un tableau qui va contenir les elements de la table de symbole
TypeTS ts[100]; 

// un compteur global pour la table de symbole
int CpTabSym=0;


//une fonctione recherche: pour chercher est ce que l'entité existe ou non déjà dans la table de symbole.
// i: l'entite existe dejà dans la table de symbole, et sa position est i, -1: l'entité n'existe pas dans la table de symbole.

int recherche(char entite[])
{
int i=0;
while(i<CpTabSym)
{
if (strcmp(entite,ts[i].NomEntite)==0) return i;
i++;
}

return -1;
}

//une fontion qui va insérer les entités de programme dans la table de symbole
void inserer(char entite[], char code[])
{

if ( recherche(entite)==-1)
{
strcpy(ts[CpTabSym].NomEntite,entite); 
strcpy(ts[CpTabSym].CodeEntite,code);


//printf("lentite est %s, sont type est %s %d\n",ts[CpTabSym].NomEntite,ts[CpTabSym].TypeEntite,CpTabSym);
CpTabSym++;
}
}

//une fonction pour afficher la table de symbole
void afficher ()
{
printf("\n/***************Table des symboles ******************/\n");
printf("________________________________________________\n");
printf("\t| NomEntite |  CodeEntite  |  TypeEntite   \n");
printf("________________________________________________\n");
int i=0;
while(i<CpTabSym)
{

printf("\t|%10s |%12s  |%12s   |\n",ts[i].NomEntite,ts[i].CodeEntite,ts[i].TypeEntite);

i++;
}
}


// fonction qui change le type d'une etité une fois il va être reconu dans la syntaxe 

void insererType(char entite[], char type[])
{

int posEntite=recherche(entite);
if (posEntite!=-1)
{ 

strcpy(ts[posEntite].TypeEntite,type);

//printf("lentite est %s, sont type est %s %d\n",ts[CpTabSym].NomEntite,ts[CpTabSym].TypeEntite,CpTabSym);

}
}





//////////////////////////////////////////////////////
////Les routines sémantiques

int doubleDeclaration (char entite[])
{
int posEntite=recherche(entite);

//printf ("\nposi %d\n",posEntite);
if (strcmp(ts[posEntite].TypeEntite,"")==0) return 1;  // j'ai pas trouvé le type associé à l'entité dans le table de symbole et donc elle est pas encore déclarée
else return 0; // le type de l'entité existe dejà dans la TS et donc c'est une double déclaration

}

int nonDeclaration (char entite[])
{
int posEntite=recherche(entite);

//printf ("\nposi %d\n",posEntite);
if (strcmp(ts[posEntite].TypeEntite,"")==0) return 1;  // j'ai pas trouvé le type associé à l'entité dans le table de symbole et donc elle est pas encore déclarée
else return 0; // le type de l'entité existe dejà dans la TS et donc c'est une double déclaration

}
