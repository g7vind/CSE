#include <stdio.h>
#include <string.h>

struct statement {
    char op[2], a1[4], a2[4], res[4];
    int ignore; 
};

struct statement st[32];
int cnt = 0;

int find(char targ[4], int k) {
    for(int i = k + 1; i < cnt; i++)
        if(!strcmp(st[i].a1, targ) || !strcmp(st[i].a2, targ))
            return 1;
    return 0;
}

int main() {
    FILE *fp;
    fp = fopen("cin.txt", "r");
    while(fscanf(fp, "%s %s %s %s", st[cnt].op, st[cnt].a1, st[cnt].a2, st[cnt].res) != EOF) cnt++;
    fclose(fp);

    for(int i = 0; i < cnt - 1; i++) 
        if(!find(st[i].res, i))
            st[i].ignore = 1;

    printf("Dead code eliminated: \n");
    printf("OPR\tA1\tA2\tRES\n");
    for(int i = 0; i < cnt; i++) {
        if(st[i].ignore == 1) continue;
        printf("%s\t%s\t%s\t%s\n", st[i].op, st[i].a1, st[i].a2, st[i].res);
    }
    return 0;
}