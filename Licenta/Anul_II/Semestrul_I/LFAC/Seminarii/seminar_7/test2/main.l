%{
int count=0;
%}
letter [A-Za-z]
digit [0-9]
%option noyywrap
%%
{letter}({letter}|{digit})* {count++;}
. {}
%%
int main(void) {
yylex();
printf("number of identifiers = %d\n", count);
return 0;
}
