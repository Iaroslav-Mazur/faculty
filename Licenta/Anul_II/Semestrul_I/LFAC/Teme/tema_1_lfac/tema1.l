%{
#include <stdio.h>
#include "y.tab.h"
%}

%x comentariu
%x comentariu_linie

%%
"intreg"|"charac"|"sir"|"af"|"real"|"rat"|"vid" {return TIP;}
"begin_progr" {return BGINP;}
"end_progr" {return ENDP;}
"<>:" {BEGIN comentariu_linie;}
<comentariu_linie>\n {BEGIN 0;}
<comentariu_linie>. ;
"<*>" {BEGIN comentariu;} 
<comentariu>"<*>" {BEGIN 0;}
<comentariu>.|\n ;
"-" {return MINUS;}
"executa" {return DO;}
"cat_timp" { return WHILE;}
"pentru" {return FOR;}
"daca" {return IF;}
"altfel" { return ELSE;}
"const" {return CONST;}
"escape" {return BREAK;}
":+"|":-"|":*"|":/"|":%" {return OPRARM;}
":=" {return ASSIGN;}
\'.\' {return CARACTER;}
\".*\" {return SIR_CARACTERE;}
0|"-"?([1-9][0-9]*) {return INTG;}
":++" {return INC;}
":--" {return DEC;}
"_==_"|"_!=_"|"_<=_"|"_>=_"|"_<_"|"_>_" {return OPRCOMP;}
"_&&_"|"_||_" {return OPRLOG;}
"_!_" {return NEG;}
(0|"-"?([1-9][0-9]*))"."[0-9]+ {return RATIONAL;}
("["(0|([1-9][0-9]*))"]")+ { return DIM_VEC;}
">"[a-zA-z]+"<" {return LIBRARIE;}
"class" {return CLASA;}
"inceput:" { return BGINB;}
"final." {return ENDB;}
"priv" {return PRIVATE;}
"pub" {return PUBLIC;}
"prot" {return PROTECTED;}
"ret" {return RETURNAT;}
"$"[a-zA-Z][a-zA-Z0-9]* {return ID;}
[a-zA-Z][a-zA-Z0-9]* {return NUME;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
