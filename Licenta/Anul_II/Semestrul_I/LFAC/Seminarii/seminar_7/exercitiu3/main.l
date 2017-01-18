%{
# include <stdio.h>
int space = 0;
%}
litera [a-zA-Z]
cifra [0-9]
cifre ({cifra})+
semn [+-]
operator [+*/<>=-]
spatiu [' ’’\t’’\n’]

%%
"if" | "then" | "else“         {printf("%s cuvant rezervat\n", yytext);}
({litera})({litera}|{cifra})*  {printf("%s identificator\n", yytext);}
{cifre}|({semn})({cifre})      {printf("%s numar intreg\n", yytext);}
{operator}                     {printf("%s operator\n", yytext);}
\:\=                           {printf("%s asignare\n", yytext);}
\:                             {printf("%s doua puncte\n", yytext);}
(\()|(\))                      {printf("%s paranteza\n", yytext);}
{spatiu}                       {space++;}
.                              {printf("%c caracter ilegal\n", yytext[0]);}
%%

int main( ){
yylex( );
printf("Spatii %d", space);
return 0;
}
