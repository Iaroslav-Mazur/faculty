%{
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token ID TIP BGIN END ASSIGN NR 
%start progr
%%
progr: declaratii bloc {printf("program corect sintactic\n");}
     ;

declaratii :  declaratie ';'
	   | declaratii declaratie ';'
	   ;
declaratie : TIP ID 
           | TIP ID '(' lista_param ')'
           | TIP ID '(' ')'
           ;
lista_param : param
            | lista_param ','  param 
            ;
            
param : TIP ID
      ; 
      
/* bloc */
bloc : BGIN list END  
     ;
     
/* lista instructiuni */
list :  statement ';' 
     | list statement ';'
     ;

EXP : '(' EXP '+' EXP ')'
    | '(' EXP '*' EXP ')'
    | '(' EXP '-' EXP ')'
    | '(' EXP '/' EXP ')'
    | ID
    ;

FCT : TIP ID '(' lista_param ')'
    | TIP ID '('')'
    ;

/* instructiune */
statement: ID ASSIGN NR  		 
         | ID '(' lista_apel ')'
	 | ID ASSIGN EXP
	 | ID ASSIGN FCT
         ;
        
lista_apel : NR
           | lista_apel ',' NR
           ;
%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 
