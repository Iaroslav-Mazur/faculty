%{
#include <stdio.h>
%}
%start s
%token SMB

%left '+'
%left '*'

%%
s : e  {printf("s->e\n");}
  ;
e : e '+' e   {printf("e->e+e\n");}
  | e '*' e   {printf("e->e*e\n");}
  |'(' e ')' {printf("e->(e)\n");  }
  | SMB  {printf("e->SMB\n"); }
  ;
  
%%

int main(){
 yyparse();
}
