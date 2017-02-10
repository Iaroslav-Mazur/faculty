%{
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token TIP ID BGINP ENDP WHILE FOR IF ELSE CONST OPRARM ASSIGN CARACTER SIR_CARACTERE INTG INC DEC OPRCOMP OPRLOG RATIONAL DIM_VEC LIBRARIE CLASA BGINB ENDB PRIVATE PUBLIC PROTECTED RETURNAT NEG NUME DO BREAK MINUS
%start program
%left OPRARM
%left OPRLOG
%left NEG
%nonassoc IFX
%nonassoc ELSE
%%
program: BGINP librarii corp ENDP {printf("program corect sintactic\n");}
     ;

librarii: librarii LIBRARIE
	| LIBRARIE
	;

corp : declaratii clase functions
	| clase functions
	| declaratii functions
	| functions
	;

constr: NUME '('')'
	| NUME '(' lista_param ')'
	;

destruct: '~' NUME '(' ')'
	| '~' NUME '(' lista_param ')'
	;

method: function
	| constr ';'
	| destruct ';'
	;

methods : methods method
	| method
	;

TYPE : PRIVATE declaratii methods
	| PRIVATE declaratii
	| PRIVATE methods
	| PUBLIC declaratii methods
	| PUBLIC declaratii
	| PUBLIC methods
	| PROTECTED declaratii methods
	| PROTECTED declaratii
	| PROTECTED methods
	;

TYPES : TYPES TYPE
	| TYPE
	;

clasa : CLASA NUME BGINB TYPES ENDB 
	;

clase : clase clasa
	| clasa
	;

variab : asignare
	| CONST asignare
	| ID
	| CONST ID
	| ID DIM_VEC
	| CONST ID DIM_VEC
	;

variabile : variabile ',' variab
	| variab
	;

object : asignare
	| CONST asignare
	| ID
	| ID '('')'
	| ID '(' lista_apel ')'
	;

objects : objects ',' object
	| object
	;

declaratii :  declaratie ';'
	   | declaratii declaratie ';'
	   ;

declaratie : TIP variabile
	| NUME objects
	   ;

lista_param : param
            | lista_param ','  param 
            ;
            
param : TIP ID
      ; 
      
antet_fct : TIP NUME '('')'
	| TIP NUME '(' lista_param ')'
	| TIP NUME ':' NUME '('')'
	| TIP NUME ':' NUME '(' lista_param ')' 
	;

function : antet_fct ';'
	| antet_fct bloc
	; 

functions : functions function
	| function
	;

RETURN: exp
	| val_adev
	| CARACTER
	| SIR_CARACTERE
	;

comparatie : ID OPRCOMP ID
	| ID OPRCOMP CARACTER
	| ID OPRCOMP SIR_CARACTERE
	| NR OPRCOMP ID
	| ID OPRCOMP NR
	| NR OPRCOMP NR
	;

adev: adev OPRLOG adev
	| comparatie
	| '(' adev ')' 
	| NEG '(' adev ')'
	;

val_adev : adev
	| NEG ID
	;

/* bloc */
bloc : BGINB declaratii list ENDB  
	| BGINB list ENDB
	| statement
     ;

/* lista instructiuni */
list :  statement 
     | list statement 
     ;

/* instructiune */
NR : RATIONAL
	| INTG
	;

statement: asignare ';'
	 | daca
	 | apel_fct ';'
	 | pentru
	 | cat_timp
	 | repeta
	 | ID INC ';'
	 | ID DEC ';'
	 | ID '.' apel_fct ';'
	 | RETURNAT RETURN ';'
	 | BREAK ';'
         ;

exp : MINUS '(' exp ')'
    | '(' exp ')'
    | exp OPRARM exp
    | ID
    | MINUS ID
    | NR
    | ID "." ID
    | ID DIM_VEC 
    | ID "." apel_fct
    | MINUS ID "." ID
    | MINUS ID DIM_VEC 
    | MINUS ID "." apel_fct
    | apel_fct
    ;

element: ID
	| ID DIM_VEC
	;

asignare : element ASSIGN exp
	 | element ASSIGN CARACTER
	 | element ASSIGN SIR_CARACTERE
	 ;

conditie: val_adev
	| ID
	;

daca : IF '(' conditie ')' bloc %prec IFX
	| IF '(' conditie ')' bloc ELSE bloc
	;
	
param_apel: CONST ID
	| exp
	;

lista_apel : param_apel
           | lista_apel ',' param_apel
           ;

apel_fct : NUME '(' lista_apel ')'
    | NUME '('')'
    ;

pas : ID INC
	| ID DEC
	| ID ASSIGN exp
	;

pentru : FOR '(' asignare ';' conditie ';' pas ')' bloc
	| FOR '(' asignare ';' ';' pas ')' bloc
	| FOR '(' ';' conditie ';' pas ')' bloc 
	| FOR '(' asignare ';' conditie ';' ')' bloc
	| FOR '(' asignare ';' ';' ')' bloc
	| FOR '(' ';' conditie ';' ')' bloc
	| FOR '(' ';' ';' pas ')' bloc
	| FOR '(' ';' ';' ')' bloc
	;

cat_timp : WHILE '(' conditie ')' bloc
	| WHILE '(' ')' bloc
	;

repeta : DO bloc WHILE '(' conditie ')' ';'
	| DO bloc WHILE '(' ')' ';'
	;

%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 
