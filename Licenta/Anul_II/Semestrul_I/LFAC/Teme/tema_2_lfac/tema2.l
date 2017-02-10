%{
#include <stdio.h>
#include "y.tab.h"
#include <string.h>
%}

%x comentariu
%x comentariu_linie

%%
"intreg" {return TIP;}
"begin_progr" {return BGINP;}
"end_progr" {return ENDP;}
"<>:" {BEGIN comentariu_linie;}
<comentariu_linie>\n {BEGIN 0;}
<comentariu_linie>. ;
"<*>" {BEGIN comentariu;} 
<comentariu>"<*>" {BEGIN 0;}
<comentariu>.|\n ;
":=" {return ASSIGN;}
0|"-"?([1-9][0-9]*) {yylval.val=atoi(yytext); return INTG;}
":++" {return INC;}
":--" {return DEC;}
">"[a-zA-z]+"<" {return LIBRARIE;}
"inceput:" { return BGINB;}
"final." {return ENDB;}
"$"[a-zA-Z][a-zA-Z0-9]* {yylval.nume=strdup(yytext); return ID;}
"medie_aritmetica" {return AVG;}
"palindrom" {return PALINDROM;}
"oglindit" {return OGLINDIT;}
"cifra_control" {return CIFRA_CONTROL;}
"putere_a_lui_2" {return POWER2;}
"print" {return PRINT;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
