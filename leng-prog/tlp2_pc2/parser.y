%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);

void yyerror(const char *s);

%}

%union {
    double num;
}

%token <num> NUMBER
%token EOL
%type <num> expr line

%left '+' '-'
%left '*' '/'

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
    NUMBER             { $$ = $1; }
    | expr '+' expr    { $$ = $1 + $3; }
    | expr '-' expr    { $$ = $1 - $3; }
    | expr '*' expr    { $$ = $1 * $3; }
    | expr '/' expr    { $$ = $1 / $3; }
    | '(' expr ')'     { $$ = $2; }
    ;

%%

int main() {
    printf("Ingrese una operacion:\n");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: en la operacion ingresada %s\n", s);
}
