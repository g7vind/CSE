%{

    int flag = 0;
%}

%%

^[aAeEiIoOuU][a-zA-Z]*   { flag = 1; }
^[^aAeEiIoOuU][a-zA-Z]*  { flag = 2; }
\n                       { return 0;}
.                        { }

%%

int main() {
    printf("Enter the string to check: ");
    yylex();  
    if (flag == 1) {
        printf("Valid string starting with vowel\n");
    } else if (flag == 2) {
        printf("Does not start with vowel\n");
    }

    return 0;
}

