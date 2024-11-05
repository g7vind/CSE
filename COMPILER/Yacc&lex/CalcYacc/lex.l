%{
#include "y.tab.h"
%}

%%

[0-9]+    { yylval = atoi(yytext); return NUMBER; }
"+"       { return PLUS; }
"-"       { return MINUS; }
"*"       { return MULTIPLY; }
"/"       { return DIVIDE; }
"("       { return LPAREN; }
")"       { return RPAREN; }
[\t ]+  ; 
\n         { return '\n' ;}
.         { printf("Unknown character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}
