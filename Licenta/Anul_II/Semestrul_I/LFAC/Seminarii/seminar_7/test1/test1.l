%{
int yylinenr=0;
%}
%option noyywrap
%%
^(.*)\n printf("%4d\t%s", ++yylinenr, yytext);
%%
int main(int argc, char *argv[]) {
yyin = fopen(argv[1], "r");
yylex();
fclose(yyin);
}
