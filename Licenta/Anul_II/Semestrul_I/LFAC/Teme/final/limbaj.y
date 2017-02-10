%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aux.c"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;

struct variabila
{
    char* id;
    void* valoare;
    char* tip;
    int initializat;
}VARS[100];

int a_mai_fost_declarat(char* id)
{
    int i;
    for(i = 0; i < 100 && VARS[i].id != NULL; i++)
    {
        if(strcmp(VARS[i].id, id) == 0)
        {
            /* Am gasit id-ul */
            char str[] = "Id-ul a fost deja declarat :%s \n";
            char str2[1000];
            sprintf(str2,str,id);
            yyerror(str2);
            return 1;
        }
    }
    return 0;
}

void add_var_fara_asignare(char* id, char* tip)
{
    /* Adaugam o noua variabila */
    if(a_mai_fost_declarat(id) == 1)
    {
        return;
    }
    int i;
    for(i=0; i<100; i++)
    {
        /* Cautam un loc liber */
        VARS[i].id = malloc(strlen(id));
        strcpy(VARS[i].valoare, id);


        if(strcmp(tip, "char") || strcmp(tip, "int"))
        {
            return;
        }

        /* daca am ajuns aici nu am recunoscut tipul */
        yyerror("Nu recunoastem tipul!");
    }
    yyerror("Nu mai avem loc in bufferul cu variabile.");
}

void add_var_asignare(char* id, void* valoare, char* tip)
{
    /* Adaugam o noua variabila */

    if(a_mai_fost_declarat(id) == 1)
    {
        return;
    }
    int i;
    for(i=0; i<100; i++)
    {
        /* Cautam un loc liber */
        VARS[i].id = malloc(strlen(id));
        strcpy(VARS[i].valoare, id);


        VARS[i].tip= malloc(strlen(valoare));
        strcpy(VARS[i].valoare, valoare);

        if(strcmp(tip, "char"))
        {
            VARS[i].tip= malloc(strlen(valoare));
            strcpy(VARS[i].valoare, valoare);
            VARS[i].initializat = 1;

            return;
        }

        if(strcmp(tip, "int"))
        {
            VARS[i].tip= malloc(sizeof(int));
            strncpy(VARS[i].valoare, valoare, sizeof(int));
            VARS[i].initializat = 1;

            return;
        }

        /* daca am ajuns aici nu am recunoscut tipul */
        yyerror("Nu recunoastem tipul!");
    }
    yyerror("Nu mai avem loc in bufferul cu variabile.");
}

void asigneaza(char* id, char* valoare)
{
    int i;
    for(i = 0; i < 100 && VARS[i].id != NULL; i++)
    {
        if(strcmp(VARS[i].id, id) == 0)
        {
            /* Am gasit id-ul */
            if(strcmp(VARS[i].tip, "char"))
            {
                char* aux_c = malloc(strlen(valoare));
                strcpy(aux_c, valoare);
                VARS[i].valoare = aux_c;
                VARS[i].initializat = 1;
                return;
            }

            if(strcmp(VARS[i].tip, "int"))
            {
                VARS[i].tip= malloc(sizeof(int));
                int aux_i = atoi(valoare);
                VARS[i].valoare = (void*)&aux_i;
                VARS[i].initializat = 1;
                return;
            }

        }
    }
    char str[] = "Nu exista o variabila cu id-ul :%s \n";
    char str2[1000];
    sprintf(str2,str,id);
    yyerror(str2);
}

%}
%left '+'
%left '*'
%union {char* string; int in_val;}
%type<string> ID TIP NR STRING
%token ID TIP BGIN END ASSIGN NR MAIN STRING FOR WHILE IF ELSE
%start progr
%%
progr :declaratie MAIN bloc { printf("Progam corect"); }
      ;

declaratie : TIP ID  ';' {add_var_fara_asignare($1, $2);}
           | TIP ID ASSIGN STRING ';' {add_var_asignare($2, $4, $1);}
           | TIP ID ASSIGN NR ';' {add_var_asignare($2, $4, $1);}
           | TIP ID '(' lista_param ')' ';'
           | TIP ID '(' ')' ';'
           ;
lista_param : param
            | lista_param ','  param 
            ;

param : TIP ID {}
      ; 

/* bloc */
bloc : BGIN list END  
bloc : BGIN END  
     ;
     
/* lista instructiuni */
list :  statement ';' 
     | list statement ';'
     ;

/* instructiune */
statement: ID ASSIGN ID ';'
         | ID ASSIGN expr ';'
         ;

expr: expr '+' expr 
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | NR
    ;

%%
int yyerror(char * s){
    printf("eroare: %s la linia:%d\n",s,yylineno);
}



int main(int argc, char** argv){
    yyin=fopen(argv[1],"r");

    int i;
    /* Initializam tot cu null */
    for(i = 0; i < 100; i++)
    {
        VARS[i].id = NULL;
        VARS[i].valoare= NULL;
        VARS[i].tip = NULL;
    }
    yyparse();
} 
