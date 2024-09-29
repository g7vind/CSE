#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>

void E();
void E_prime();
void T();
void T_prime();
void F();

char *input;
char lookahead;

void print_action(const char *rule) {
    printf("%s\t\t %s\n", input, rule);
}

void E() {
    print_action("E -> T E'");
    T();
    E_prime();
}

void E_prime() {
    if (lookahead == '+') {
        print_action("E' -> + T E'");
        lookahead = *++input;
        T();
        E_prime();
    } else {
        print_action("E' -> $");
    }
}

void T() {
    print_action("T -> F T'");
    F();
    T_prime();
}

void T_prime() {
    if (lookahead == '*') {
        print_action("T' -> * F T'");
        lookahead = *++input;
        F();
        T_prime();
    } else {
        print_action("T' -> $");
    }
}

void F() {
    if (lookahead == '(') {
        print_action("F -> ( E )");
        lookahead = *++input;
        E();
        lookahead = *++input;
    } else if (isalpha(lookahead)) {
        print_action("F -> id");
        lookahead = *++input;
    } else {
        printf("Error: Unexpected character '%c'\n", lookahead);
        exit(1);   
    }
}
int main() {
    char expression[100];
    printf("Enter an arithmetic expression: ");
    scanf("%s", expression);
    input = expression;
    lookahead = *input;
    printf("Input\t\t Action\n");
    printf("----------------------------\n");
    E();
    if (lookahead == '\0') {
        printf("Parsing completed successfully.\n");
    } else {
        printf("Error: Unmatched input at the end.\n");
    }
    return 0;
}