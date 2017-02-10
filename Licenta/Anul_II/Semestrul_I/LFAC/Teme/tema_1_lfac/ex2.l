%{
#include <stdio.h>
#include "y.tab.h"
%}
%%
[a-zA-z]+ {return SMB;}
[ \t] ;
\n {return 0;}
. {return yytext[0];}
