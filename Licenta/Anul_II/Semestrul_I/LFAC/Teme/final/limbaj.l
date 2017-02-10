%{
#include <stdio.h>
#include "y.tab.h"
%}
cifra0 (1|2|3|4|5|6|7|8|9)
cifra (0|1|2|3|4|5|6|7|8|9)
numar {cifra0}{cifra}*
semn ("-"|"+")
numar_semn {semn}{numar}
comentariu "//"
operatori_int ("+"|"-"|"*"|"/")
operatori_bool ("&&"|"||")
tipuri ("char"|"int")
main "main"
%%
{main} {printf("Am gasit main \n"); return MAIN; }
{tipuri} {printf("Am gasit tip %s \n", yytext); return TIP;}
"{" {printf("Am gasit BGIN \n;");return BGIN;}
"}" {printf("Am gasit END \n");return END;}
"=" {printf("Am  gasit asignare \n");return ASSIGN;}
({semn}|''){numar} {printf("Am gasit numar %s \n", yytext); return NR; }
"if" {printf("Am gasit if \n");return IF;}
"else" {printf("Am gasit else \n");return ELSE;}
"for" {printf("Am gasit for \n ");return FOR;}
"while" {printf("Am gasit while \n");return WHILE;}
[a-zA-Z][a-zA-Z0-9]* {printf("Am gasit var %s \n", yytext);return ID;}
\".*\" {printf("Am gasit string %s \n", yytext);return STRING;}
\n {yylineno++;}
[\t ] 
. 
%%
/* int main(int argc, char** argv) */
/* { */
/*     yyin=fopen(argv[1],"r"); */
/*     yylex(); */
/* } */
