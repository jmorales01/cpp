%{
#include "parser.tab.h"
#include <math.h>
%}

%%
[0-9]+(\.[0-9]+)?   { yylval.num = atof(yytext); return NUMBER; }
"sin"               { return SIN; }
"cos"               { return COS; }
"tan"               { return TAN; }
"("                 { return '('; }
")"                 { return ')'; }
[ \t]+              { /* Ignorar espacios en blanco */ }
\n                  { return EOL; }
[-+*/]              { return yytext[0]; }
.                   { return yytext[0]; }
%%

int yywrap() {
    return 1;
}