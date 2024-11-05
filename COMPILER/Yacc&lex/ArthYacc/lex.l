%{
	#include <stdio.h>
	#include "y.tab.h"
	extern int yylval;
%}

%%
[0-9]+ { return NUM; }
[a-zA-Z] { return ID; }
[+\-*/()] { return yytext[0]; }
. { return other; }
\n { return '\n'; }
%%