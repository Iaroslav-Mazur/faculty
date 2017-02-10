%option noyywrap
%{
#include <stdio.h>
%}
%x pas
%x pas1
cifra (0|1|2|3|4|5|6|7|8|9)
litera (a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|r|s|t|u|v|x|y|w|q|z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z)
numar ((1|2|3|4|5|6|7|8|9){cifra}*)|0
cuvant {litera}({litera}|{cifra})*
tip ("int"|"float"|"char"|"double"|"long"|"long long"|"void")
cuvantrezervat ("if"|"return"|"else"|"while"|"do"|"for"|"NULL"|"new")
operatorart ("+"|"-"|"/"|"*")
operatorasg ("="|"<-")
operatorlog ("||"|"&&"|"=="|"!=")
begcomm ("//"|"/*")
endcomm ("*/")
%%
\[ {fprintf(yyout,"<%s LRPAR>\n",yytext);}
\] {fprintf(yyout,"<%s RRPAR>\n",yytext);}
{tip} {fprintf(yyout,"<%s TIP>\n",yytext);}
{cuvantrezervat} {fprintf(yyout,"<%s REZ>\n",yytext);}
\*{cuvant} {fprintf(yyout,"<%s POINTER>\n",yytext);}
{cuvant} {fprintf(yyout,"<%s ID>\n",yytext);}
{numar} {fprintf(yyout,"<%s NR>\n",yytext);}
{operatorart} {fprintf(yyout,"<%s OPARITM>\n",yytext);}
{operatorasg} {fprintf(yyout,"<%s OPASSIGN>\n",yytext);}
{operatorlog} {fprintf(yyout,"<%s OPLOGIC>\n",yytext);}
# {fprintf(yyout,"<#"); BEGIN pas1;}
<pas1>\> {fprintf(yyout,"%s LYB>\n",yytext); BEGIN 0;}
{begcomm} {BEGIN pas;}
<pas>{endcomm}|\n {BEGIN 0;}
<pas>. ;
; {fprintf(yyout,"<%s PV>\n",yytext);}
\{ {fprintf(yyout,"<%s LAC>\n",yytext);}
\} {fprintf(yyout,"<%s RAC>\n",yytext);}
\( {fprintf(yyout,"<%s LPAR>\n",yytext);}
\) {fprintf(yyout,"<%s PPAR>\n",yytext);}
.|\n ;
%%

int main()
{
	FILE *f,*g;
	f=fopen("Ctext.txt","r");
	yyin=f;
	g=fopen("out.txt","w");
	yyout=g;
	yylex();
	return 0;
}

