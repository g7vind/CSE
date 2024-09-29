#include <ctype.h>
#include <stdio.h>
#include <string.h>

int iskeyword(char *b) {
    const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue",
        "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "inline", "int",
        "long", "register", "restrict", "return", "short",
        "signed", "sizeof", "static", "struct", "switch",
        "typedef", "union", "unsigned", "void", "while"
    };
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < num_keywords; ++i) {
        if (strcmp(b, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isspecial(char ch) {
    return ch == '{' || ch == '}' || ch == '(' || ch == ')' || ch == ',' || ch == ';';
}

void classify(char *buf, int state) {
    if (state == 1) {
        printf("Number: %s\n", buf);
    } else if (state == 2) {
        if (iskeyword(buf))
            printf("Keyword: %s\n", buf);
        else
            printf("Identifier: %s\n", buf);
    } else if (state == 3) {
        printf("Special character: %s\n", buf);
    } else if (state == 4 || state == 5) {
        if (buf[1] == '+' || buf[1] == '-')
            printf("Increment/Decrement operator: %s\n", buf);
        else
            printf("Arithmetic operator: %s\n", buf);
    } else if (state == 6) {
        if (buf[1] == '=')
            printf("Relational operator: %s\n", buf);
        else
            printf("Assignment operator: %s\n", buf);
    } else if (state == 7) {
        printf("Relational operator: %s\n", buf);
    } else if (state == 8) {
        printf("Arithmetic operator: %s\n", buf);
    }
}

int main() {
    FILE *fp;
    char ch, buf[100];
    int c = 0, state = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        buf[c++] = ch;
        switch (state) {
            case 0:
                if (isdigit(ch))
                    state = 1;
                else if (isalpha(ch) || ch == '_')
                    state = 2;
                else if (isspecial(ch))
                    state = 3;
                else if (ch == '+')
                    state = 4;
                else if (ch == '-')
                    state = 5;
                else if (ch == '=')
                    state = 6;
                else if (ch == '<' || ch == '>' || ch == '!')
                    state = 7;
                else if (ch == '/' || ch == '*' || ch == '%')
                    state = 8;
                else if (ch == ' ' || ch == '\n' || ch == '\t')
                    c = 0;
                break;
            case 1:
                if (!isdigit(ch) && ch != '.') {
                    buf[--c] = '\0';
                    classify(buf, state);
                    c = 0;
                    state = 0;
                    fseek(fp, -1, SEEK_CUR);
                }
                break;
            case 2:
                if (!isalnum(ch) && ch != '_') {
                    buf[--c] = '\0';
                    classify(buf, state);
                    c = 0;
                    state = 0;
                    fseek(fp, -1, SEEK_CUR);
                }
                break;
            case 3:
                buf[--c] = '\0';
                classify(buf, state);
                c = 0;
                state = 0;
                fseek(fp, -1, SEEK_CUR);
                break;
            case 4:
            case 5:
                if (ch != '+' && ch != '-') {
                    buf[--c] = '\0';
                    classify(buf, state);
                    c = 0;
                    state = 0;
                    fseek(fp, -1, SEEK_CUR);
                }
                break;
            case 6:
            case 7:
                if (ch != '=') {
                    buf[--c] = '\0';
                    classify(buf, state);
                    c = 0;
                    state = 0;
                    fseek(fp, -1, SEEK_CUR);
                }
                break;
            case 8:
                buf[--c] = '\0';
                classify(buf, state);
                c = 0;
                state = 0;
                fseek(fp, -1, SEEK_CUR);
                break;
        }
    }
    if (c > 0) {
        buf[c] = '\0';
        classify(buf, state);
    }

    fclose(fp);
    return 0;
}
