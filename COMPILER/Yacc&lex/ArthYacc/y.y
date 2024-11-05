%{
	#include <stdio.h>
	int yylex();
	void yyerror();
%}

%token NUM ID other
%left '+' '-'
%left '*' '/'

%%
start	: T '\n' 	{ printf("Valid Arithmetic Expression\n"); return 0; };
T		: T '+' T 	
		| T '-' T 	
		| T '*' T 	
		| T '/' T 	
		| '(' T ')' 
		| NUM
		| ID
		;
%%

void yyerror() {
	printf("Error. Failed to parse. or invalid expression \n");
}

void main() {
	printf("Enter arithmetic expression: ");
	yyparse();
}