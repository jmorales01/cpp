%{
#include "parser.tab.h"
%}

%%

[ \t];
\n                         return EOL;
[-+]?([0-9]*[.])?[0-9]+    { yylval.num = atof(yytext); return NUMBER; }
"+"                        return '+';
"-"                        return '-';
"*"                        return '*';
"/"                        return '/';
"("                        return '(';
")"                        return ')';

%%

int yywrap() {
    return 1;
}
