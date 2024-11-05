%{
	#include <stdio.h>
	#include "y.tab.h"
	extern int yylval;
%}

%%
[0-9] { return digit; }
[a-zA-Z] { return alpha; }
. { return other; }
\n { return '\n'; }
%%
