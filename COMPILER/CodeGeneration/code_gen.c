#include <stdio.h>
#include <ctype.h>
#include <string.h>
int tmpCount = 0;
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
void infixToPostfix(char* expr, char* postfix) {
    char stack[100];
    int top = -1;
    int k = 0;
    int i;
    for (i = 0; expr[i]; i++) {
        if (isalnum(expr[i])) {
            postfix[k++] = expr[i];
        } else if (expr[i] == '(') {
            stack[++top] = expr[i];
        } else if (expr[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--;
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(expr[i])) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = expr[i];
        }
    }
    while (top != -1) {
        postfix[k++] = stack[top--];
    }
    postfix[k] = '\0';
    printf("Postfix expression: %s", postfix);
}
void parsePostfix(char *postfix,FILE *fp) {
    char stack[100][10];
    int top = -1;
    int i = 0;
    char result[10];
    while (postfix[i] != '\0') {
        if (isalnum(postfix[i])) {
            stack[++top][0] = postfix[i];
            stack[top][1] = '\0';
        } else {
            char arg2[10], arg1[10];
            strcpy(arg2, stack[top--]);
            strcpy(arg1, stack[top--]);
            sprintf(result, "T%d", tmpCount++);
            fprintf(fp,"%c %s %s %s\n", postfix[i], arg1, arg2, result);
            printf("%-9c %-9s %-9s %-9s\n", postfix[i], arg1, arg2, result);
            strcpy(stack[++top], result);
        }
        i++;
    }
}

int main() {
    FILE *fp = fopen("output.txt","w");
    char expr[100];
    char postfix[100];
    char arg1[10], arg2[10], result[10],op;
    printf("Enter an infix expression: ");
    scanf("%s", expr);
    infixToPostfix(expr, postfix);
    printf("\nIntermediate code:\n");
    printf("%-9s %-9s %-9s %-9s\n", "Operator", "Arg1", "Arg2", "Result");
    printf("---------------------------------------\n");
    parsePostfix(postfix,fp);
    freopen("output.txt","r",fp);
    printf("\nThe Assembly code is:\n");
    while(fscanf(fp,"%c %s %s %s\n",&op,arg1,arg2,result)!=EOF){
        printf("MOV R0,%s\n", arg1);
        switch (op) {
        case '+': printf("ADD R0,%s\n", arg2); break;
        case '-': printf("SUB R0,%s\n", arg2); break;
        case '*': printf("MUL R0,%s\n", arg2); break;
        case '/': printf("DIV R0,%s\n", arg2); break;
        }
    printf("MOV %s,R0\n", result);
    }
    return 0;
}