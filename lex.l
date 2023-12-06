%{
#include "synt.tab.h"
#include "compFonction.h"
extern nb_ligne;
%}


idf [a-zA-Z]([a-zA-Z]|[0-9])*
cst [1-9][0-9]*|0
%%
begin {return mc_begin;}
end {return mc_end;}
program {return mc_program;}
integer {  yylval.str=strdup(yytext); 
         return mc_integer;}
real { yylval.str=strdup(yytext); 
      return mc_real;}

[ \t]
\n nb_ligne++;
[{}()=,;<>/"] {return yytext[0];}
{cst}   { yylval.num=atoi(yytext);
            return cst;}	
{idf}  {if (yyleng<=10)  {yylval.str=strdup(yytext);
                          inserer(yytext,"idf");
                                           return idf;}
              else printf("erreur lexical: IDF trop long ");
       }
. printf ("erreur lexical à la ligne %d",nb_ligne);
