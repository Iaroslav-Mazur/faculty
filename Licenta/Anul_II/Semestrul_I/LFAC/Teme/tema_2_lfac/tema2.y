%{
#include <stdio.h>
#include "functii.h" 
int errors=0;
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token TIP ID BGINP ENDP ASSIGN INTG INC DEC LIBRARIE BGINB ENDB MINUS PRINT AVG PALINDROM OGLINDIT CIFRA_CONTROL POWER2
%union {int val; char *nume;}
%type<nume> ID
%type<val> INTG function exp
%start program
%left '+' '-'
%left '*' '/' '%'
%left MINUS
%nonassoc P
%nonassoc ')'
%%
program: BGINP librarii corp ENDP {if (errors==0) { afisare_buffer(); printf("program corect sintactic si semantic\n");} else printf("Programul are %d erori!\n", errors);}
     ;

librarii: librarii LIBRARIE
	| LIBRARIE
	;

corp : declaratii_globale 'v''o''i''d' 'm''a''i''n''('')' bloc
	| 'v''o''i''d' 'm''a''i''n''('')' bloc
	;

variab_globala : ID ASSIGN exp { if(variabila_este_declarata((char*) $1)==-1) declarare_cu_initializare((char *)$1,(int)$3); else yyerror("Variabila a fost deja declarata!");}
	| ID { if(variabila_este_declarata((char*) $1)==-1) declarare_cu_initializare((char *)$1,0); else yyerror("Variabila a fost deja declarata!");}
	;

variabile_globale : variabile_globale ',' variab_globala
	| variab_globala
	;

declaratii_globale :  declaratie_globala ';'
	   | declaratii_globale declaratie_globala ';'
	   ;

declaratie_globala : TIP variabile_globale
	   ;

variab : ID ASSIGN exp { if(variabila_este_declarata((char*) $1)==-1) declarare_cu_initializare((char *)$1,$3); else yyerror("Variabila a fost deja declarata!");}
	| ID { if(variabila_este_declarata((char*) $1)==-1) declarare_fara_initializare((char *)$1); else yyerror("Variabila a fost deja declarata!");}
	;

variabile : variabile ',' variab
	| variab
	;

declaratii :  declaratie
	   | declaratii declaratie
	   ;

declaratie : TIP variabile
	   ;

/* bloc */
bloc : BGINB list ENDB
	| statement
     ;

/* lista instructiuni */
list :  statement 
     | list statement 
     ;

/* instructiune */

statement: declaratii ';'
	 | ID ASSIGN exp ';' { if(variabila_este_declarata((char*) $1)==-1) yyerror("Variabila nu a fost declarata!"); else atrib((char *)$1,$3);}
	 | ID INC ';' {int ok=variabila_este_declarata((char*)$1); if(ok==-1) yyerror("Variabila nu a fost declarata!"); else if (variabile[ok].initializat==0) yyerror("Variabila nu a fost initializata!"); else atrib((char *)$1,variabile[ok].valoare+1);}
	 | ID DEC ';' {int ok=variabila_este_declarata((char*)$1); if(ok==-1) yyerror("Variabila nu a fost declarata!"); else if (variabile[ok].initializat==0) yyerror("Variabila nu a fost initializata!"); else atrib((char *)$1,variabile[ok].valoare-1);}
	 | PRINT '(' exp ')' ';' { print_int($3);}
	 | PRINT '(' ID ')'  ';' { print($3);} 
	 ;

exp : '(' exp ')' {$$=$2;} 
    | '-' '(' exp ')' {$$=-$3;}
    | exp '+' exp {$$=$1+$3;}
    | exp '-' exp {$$=$1-$3;}
    | exp '*' exp {$$=$1*$3;}
    | exp '/' exp {$$=$1/$3;}
    | exp '%' exp {$$=$1%$3;}
    | ID %prec P {int ok=variabila_este_declarata((char*)$1); if(ok==-1) yyerror("Variabila nu a fost declarata!"); else if (variabile[ok].initializat==0) yyerror("Variabila nu a fost initializata!"); else $$=variabile[ok].valoare;}
    | ID INC {int ok=variabila_este_declarata((char*)$1); if(ok==-1) yyerror("Variabila nu a fost declarata!"); else if (variabile[ok].initializat==0) yyerror("Variabila nu a fost initializata!"); else {variabile[ok].valoare=variabile[ok].valoare+1; $$=variabile[ok].valoare;}}
    | ID DEC {int ok=variabila_este_declarata((char*)$1); if(ok==-1) yyerror("Variabila nu a fost declarata!"); else if (variabile[ok].initializat==0) yyerror("Variabila nu a fost initializata!"); else {variabile[ok].valoare=variabile[ok].valoare-1; $$=variabile[ok].valoare;}}
    | '-' ID {int ok=variabila_este_declarata((char*)$2); if(ok==-1) yyerror("Variabila nu a fost declarata!"); else if (variabile[ok].initializat==0) yyerror("Variabila nu a fost initializata!"); else $$=-variabile[ok].valoare;}
    | INTG {$$=$1;}
    | function {$$=$1;}
    ;

function: AVG '(' exp ',' exp ')' {$$=medie_aritmetica($3,$5);}
    | PALINDROM '(' exp ')' {$$=palindrom($3);}
    | OGLINDIT '(' exp ')' {$$=oglindit($3);}
    | POWER2 '(' exp ')' {$$=putere_a_lui_2($3);}
    | CIFRA_CONTROL '(' exp ')' {$$=cifra_control($3);} 
    ;

%%
int yyerror(char * s){
errors++;
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 
