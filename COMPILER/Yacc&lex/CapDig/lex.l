%{
    int capitals = 0, digits = 0;
%}

%%
[A-Z]           { capitals++; }
[0-9]           { digits++; }
.               {}
\n              { return 0; }
%%
int main() {
    yylex();
    printf("Capital Letters: %d\n", capitals);
    printf("Digits: %d\n", digits);
    return 0;
}
