#include <stdio.h>
#include <string.h>
#include <ctype.h>

void shift();
void reduce(char c);

char stack[100] = ""; 
char input[100];       
int top = -1;         
int i = 0;            

int main() {
    printf("Enter the input string: ");
    scanf("%s", input);

    printf("Stack\t\tInput\t\tAction\n");
    printf("--------------------------------------------\n");

    while (1) {
        if (i < strlen(input)) {
            shift();
        } else {
            break;
        }

        while (1) {
            if (top >= 2 && stack[top-2] == 'E' && stack[top-1] == '+' && stack[top] == 'E') {
                reduce('+');
            } else if (top >= 2 && stack[top-2] == 'E' && stack[top-1] == '*' && stack[top] == 'E') {
                reduce('*');
            } else if (top >= 2 && stack[top-2] == '(' && stack[top-1] == 'E' && stack[top] == ')') {
                reduce(')');
            } else if (top >= 0 && stack[top] == 'i') {
                reduce('i');
            } else {
                break;
            }
        }
    }

    if (top == 0 && stack[top] == 'E' && i == strlen(input)) {
        printf("%s\t\t%s\t\tAccept\n", stack, &input[i]);
    } else {
        printf("Error: Input string cannot be parsed by the grammar.\n");
    }

    return 0;
}

void shift() {
    if(isalpha(input[i])) {
        stack[++top] = 'i';
    } else {
        stack[++top] = input[i];
    }
    i++;
    stack[top+1] = '\0';  
    printf("%s\t\t%s\t\tShift\n", stack, &input[i]);
}

void reduce(char c) {
    if (c == 'i') {
        stack[top] = 'E'; 
        printf("%s\t\t%s\t\tReduce by E->id \n", stack, &input[i]);
    } else if (c == ')') {
        top -= 2; 
        stack[top] = 'E';
        printf("%s\t\t%s\t\tReduce by E->(E)\n", stack, &input[i]);
    } else {
        char temp[4];
        snprintf(temp, 4, "%c%c%c", stack[top-2], stack[top-1], stack[top]);
        top -= 2;  
        stack[top] = 'E';
        printf("%s\t\t%s\t\tReduce E->%s\n", stack, &input[i], temp);
    }
    stack[top+1] = '\0'; 
}
