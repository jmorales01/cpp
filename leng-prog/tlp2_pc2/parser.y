%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void yyerror(const char *s);
int yylex(void);
%}

%union {
    double num;
}

%token <num> NUMBER
%token EOL
%token SIN COS TAN
%type <num> expr line

%left '+' '-'
%left '*' '/'
%left UMINUS

%%

input:
    /* vacío */
    | input line
    ;

line:
    '\n'
    | expr EOL { printf("Resultado: %f\n", $1); }
    ;

expr:
    NUMBER                     { $$ = $1; }
    | expr '+' expr            { $$ = $1 + $3; }
    | expr '-' expr            { $$ = $1 - $3; }
    | expr '*' expr            { $$ = $1 * $3; }
    | expr '/' expr            { $$ = $1 / $3; }
    | '-' expr %prec UMINUS    { $$ = -$2; }
    | '(' expr ')'             { $$ = $2; }
    | SIN '(' expr ')'         { $$ = sin($3); }
    | COS '(' expr ')'         { $$ = cos($3); }
    | TAN '(' expr ')'         { $$ = tan($3); }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    printf("Ingrese una operacion:\n");
    return yyparse();
}