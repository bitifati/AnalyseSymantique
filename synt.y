%{
char suavType [20];

int nb_ligne=1;

%}

%union {
int num;
char* str;
   }

%token  <str>idf mc_begin mc_end mc_program mc_integer mc_real <num>cst


%%

S: entete declaration mc_begin corps mc_end { printf ("programme syntaxiquement juste\n"); YYACCEPT;}                    
;

entete: mc_program  idf
;

declaration: type listeparam ';' declaration | type listeparam ';'
;

listeparam: listeparam ',' idf { if (doubleDeclaration($3)==0){ printf("erreur Sémantique: double déclation de %s, à la ligne %d\n", $3, nb_ligne); }
        
           | idf               { if ( doubleDeclaration($1)==1)insererType($1,suavType);
                                 else printf("erreur Sémantique: double déclation de %s, à la ligne %d\n", $1, nb_ligne);}
;


type: mc_integer { strcpy(suavType,$1);  }
     | mc_real {strcpy(suavType,$1);}
;

corps: corps inst | inst
;

inst : instaff| instdiv
;

instaff: idf '=' idf ';'{if (nonDeclaration($1)==1) printf("erreur Semantique: non declation de %s, à la ligne %d\n", $1, nb_ligne);
                         else {
						 if (nonDeclaration($3)==1) printf("erreur Semantique: non declation de %s, à la ligne %d\n", $3, nb_ligne);
						}}
         |idf '=' cst ';' {if (nonDeclaration($1)==1) printf("erreur Semantique: non declation de %s, à la ligne %d\n", $1, nb_ligne);}   	   
;

instdiv: idf '=' idf '/' cst ';' { if ($5==0) printf("Erreur sémantique: Division par zero à la ligne %d\n",nb_ligne);
                                  else {
								         //créer le code intermédaire
										 }
							  
							  } 
	 

           
								
;



%%
main ()
{
yyparse();
afficher();

}
yywrap()
{}

