%{
    int positive = 0, negative = 0;
%}

%%
"-"[0-9]+       { negative++; }
[0-9]+          { positive++; }
,               { }
\n              { return 0; }

%%

int main() {
    printf("Enter numbers for eg (1,2,-1..) : ");
    yylex();
    printf("Positive numbers: %d\n", positive);
    printf("Negative numbers: %d\n", negative);
    return 0;
}
