%{
	#include <stdio.h>
	int comment = 0;
%}

%%
"//".*\n	{ comment++; }
"/*"(.|\n)*"*/" { comment++; }
[ \n\t]		{ ; }

[+-]?[0-9]+(\.[0-9]+)?(E[+-]?[0-9]+) { printf("%s\tExponent Number\n", yytext); }
([+-]?[0-9]+)\.[0-9]+ { printf("%s\tFloating Number\n", yytext); }
[+-]?[0-9]+ { printf("%s\tNumber\n", yytext); }

(void|main|if|else|printf|int|float) { printf("%s\tReserved Keyword\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("%s\tLiteral\n", yytext); }

[=*/+\-%] { printf("%s\tArithmetic Operator\n", yytext); }
(==|<|<=|>|>=|!=) { printf("%s\tRelational Operator\n", yytext); }
[(){};,] {printf("%s\tSpecial Operator\n", yytext); }
%%

void main() {
	yyin = fopen("input.c", "r");
	yylex();
	printf("\n%d Comments Ignored\n", comment);
	fclose(yyin);
}