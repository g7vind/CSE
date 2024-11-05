%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);
%}

%token NUMBER PLUS MINUS MULTIPLY DIVIDE LPAREN RPAREN

%%

calculation:
    calculation expression '\n' { printf("Result: %d\n", $2); }
    | /* empty */
;

expression:
    expression PLUS term    { $$ = $1 + $3; }
    | expression MINUS term { $$ = $1 - $3; }
    | term
;

term:
    term MULTIPLY factor    { $$ = $1 * $3; }
    | term DIVIDE factor    { 
        if ($3 == 0) {
            yyerror("Error: Division by zero");
            $$ = 0;
        } else {
            $$ = $1 / $3;
        }
    }
    | factor
;

factor:
    NUMBER
    | LPAREN expression RPAREN { $$ = $2; }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter expressions to calculate (Ctrl+D to exit):\n");
    return yyparse();
}
