%{
#include <stdio.h>
%}
%%
\.a(aa)*[bc]*c[bc]*bb\. {ECHO;}
%%

int main(int argc, char** argv){
FILE *g;
if(argc>0)
 yyin = fopen(argv[1],"r");

if(!(g = fopen("out.txt","w")))
    fprintf(stderr,"eroare creare fisier!");
else
 yyout=g;

yylex();

}

