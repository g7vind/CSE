#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct statement {
    char op[2], a1[4], a2[4], res[4];
    int ignore; 
};

struct statement st[32];
int cnt = 0;

int is_constant(char *str) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] < '0' || str[i] > '9') return 0;
    }
    return 1;
}

void replace(char *targ, char *repl, int i) {
    for(int j = i + 1; j < cnt; j++) {
        if(!strcmp(targ, st[j].a1)) sprintf(st[j].a1, "%s", repl);
        if(!strcmp(targ, st[j].a2)) sprintf(st[j].a2, "%s", repl);
    }
}

void fold_and_propagate() {
    for(int i = 0; i < cnt; i++) {
        if(st[i].op[0] == '=') {
            replace(st[i].res, st[i].a1, i);
        }
    }
    for(int i = 0; i < cnt; i++) {
        if(st[i].op[0] != '=' && is_constant(st[i].a1) && is_constant(st[i].a2)) {
            int a1 = atoi(st[i].a1);
            int a2 = atoi(st[i].a2);
            int result;

            if(st[i].op[0] == '+') result = a1 + a2;
            else if(st[i].op[0] == '-') result = a1 - a2;
            else if(st[i].op[0] == '*') result = a1 * a2;
            else if(st[i].op[0] == '/') result = a1 / a2;

            char result_str[4];
            sprintf(result_str, "%d", result);
            replace(st[i].res, result_str, i); 
            sprintf(st[i].res, "%d", result);  
        }
    }
}

int main() {
    FILE *fp;
    fp = fopen("cin.txt", "r");
    if (!fp) {
        printf("Error opening file.\n");
        return 1;
    }
    while(fscanf(fp, "%s %s %s %s", st[cnt].op, st[cnt].a1, st[cnt].a2, st[cnt].res) != EOF) cnt++;
    fclose(fp);
    fold_and_propagate();
    printf("Constant propagated and folded code: \n");
    printf("OPR\tA1\tA2\tRES\n");
    for(int i = 0; i < cnt; i++) {
        printf("%s\t%s\t%s\t%s\n", st[i].op, st[i].a1[0] ? st[i].a1 : "-", st[i].a2[0] ? st[i].a2 : "-", st[i].res);
    }
    
    return 0;
}
