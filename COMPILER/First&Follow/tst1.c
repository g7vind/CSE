#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define max_prod 10

typedef struct {
    char lhs;
    char rhs[100];
} production;

typedef struct {
    char nonTerminal;
    char firstSet[20];
    char followSet[20];
    int hasEpsilon;
} nonTerminal;

bool isNonTerminal(char ch) {
    return (ch >= 'A' && ch <= 'Z') ? true : false;
}

int findNonTerminalIndex(nonTerminal nt[], int nonTerminalCount, char target) {
    for (int i = 0; i < nonTerminalCount; i++) {
        if (nt[i].nonTerminal == target) {
            return i;
        }
    }
    return -1; 
}

void addToFirstSet(nonTerminal nt[], char lhs, char rhs, int count) {
    for (int i = 0; i < count; i++) {
        if (nt[i].nonTerminal == lhs) {
            int len = strlen(nt[i].firstSet);
            if (strchr(nt[i].firstSet, rhs) == NULL) {
                nt[i].firstSet[len] = rhs;
                nt[i].firstSet[len + 1] = '\0';
            }
            break;
        }
    }
}



void printFirstSet(nonTerminal nt[], int count) {
    for (int i = 0; i < count; i++) {
        printf("First(%c) = {", nt[i].nonTerminal);
        for (int j = 0; j < strlen(nt[i].firstSet); j++) {
            printf("%c", nt[i].firstSet[j]);
            if (j < strlen(nt[i].firstSet) - 1) {
                printf(", ");
            }
        }
        printf("}\n");
    }
}

void markEpsilon(nonTerminal nt[], char lhs, int nonTerminalCount) {
    for (int i = 0; i < nonTerminalCount; i++) {
        if (nt[i].nonTerminal == lhs) {
            nt[i].hasEpsilon = 1;
            break;
        }
    }
}

void printFollowSet(nonTerminal nt[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Follow(%c) = {", nt[i].nonTerminal);
        for (int j = 0; j < strlen(nt[i].followSet); j++) {
            printf("%c", nt[i].followSet[j]);
            if (j < strlen(nt[i].followSet) - 1) {
                printf(", ");
            }
        }
        printf("}\n");
    }
}

void parseProduction(production prod, nonTerminal nt[], int nonTerminalCount, int index) {
    if (isNonTerminal(prod.rhs[index])) {
        int rhsIndex = findNonTerminalIndex(nt, nonTerminalCount, prod.rhs[index]);
        if (rhsIndex != -1) {
            for (int j = 0; j < strlen(nt[rhsIndex].firstSet); j++) {
                if (nt[rhsIndex].firstSet[j] != '#') {
                    addToFirstSet(nt, prod.lhs, nt[rhsIndex].firstSet[j], nonTerminalCount);
                }
            }
            if (nt[rhsIndex].hasEpsilon) {
                parseProduction(prod, nt, nonTerminalCount, index + 1);
            }
        }
    } else {
        addToFirstSet(nt, prod.lhs, prod.rhs[index], nonTerminalCount);
    }
}

void calculateFirst(production prod[], nonTerminal nt[], int count, int nonTerminalCount) {
    for (int i = 0; i < count; i++) {
        if (!isNonTerminal(prod[i].rhs[0]) && prod[i].rhs[0] != '#') {
            addToFirstSet(nt, prod[i].lhs, prod[i].rhs[0], nonTerminalCount);
        } else if (prod[i].rhs[0] == '#') {
            addToFirstSet(nt, prod[i].lhs, '#', nonTerminalCount);
            markEpsilon(nt, prod[i].lhs, nonTerminalCount);
        }
    }
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < count; i++) {
            int lhsIndex = findNonTerminalIndex(nt, nonTerminalCount, prod[i].lhs);
            int initialLength = strlen(nt[lhsIndex].firstSet);
            parseProduction(prod[i], nt, nonTerminalCount, 0);
            if (strlen(nt[lhsIndex].firstSet) > initialLength) {
                changed = true;
            }
        }
    }
    printFirstSet(nt, nonTerminalCount);
}

bool isNonterminalAlreadyPresent(nonTerminal nt[], char ch, int count) {
    for (int i = 0; i < count; i++) {
        if (nt[i].nonTerminal == ch) {
            return true;
        }
    }
    return false;
}

void addToFollowSet(nonTerminal nt[], char lhs, char rhs, int count) {
    for (int i = 0; i < count; i++) {
        if (nt[i].nonTerminal == lhs) {
            int len = strlen(nt[i].followSet);
            if (strchr(nt[i].followSet, rhs) == NULL) {
                nt[i].followSet[len] = rhs;
                nt[i].followSet[len + 1] = '\0';
            }
            break;
        }
    }
}

void parseFollow(production prod[], nonTerminal nt[], int nonTerminalCount, int prodIndex, int matchNonTermIndex, int jumpIndex) {
    if (prod[prodIndex].rhs[matchNonTermIndex + jumpIndex] == '\0') {
        int lhsIndex = findNonTerminalIndex(nt, nonTerminalCount, prod[prodIndex].lhs);
        int rhsIndex = findNonTerminalIndex(nt, nonTerminalCount, prod[prodIndex].rhs[matchNonTermIndex]);
        if (rhsIndex != -1) {
            for (int j = 0; j < strlen(nt[lhsIndex].followSet); j++) {
                if (nt[lhsIndex].followSet[j] != '#') {
                    addToFollowSet(nt, prod[prodIndex].rhs[matchNonTermIndex], nt[lhsIndex].followSet[j], nonTerminalCount);
                }
            }
        }
    } else {
        if (isNonTerminal(prod[prodIndex].rhs[matchNonTermIndex + jumpIndex])) {
            int rhsIndex = findNonTerminalIndex(nt, nonTerminalCount, prod[prodIndex].rhs[matchNonTermIndex + jumpIndex]);
            for (int j = 0; j < strlen(nt[rhsIndex].firstSet); j++) {
                if (nt[rhsIndex].firstSet[j] != '#') {
                    addToFollowSet(nt, prod[prodIndex].rhs[matchNonTermIndex], nt[rhsIndex].firstSet[j], nonTerminalCount);
                }
            }
            if (nt[rhsIndex].hasEpsilon) {
                parseFollow(prod, nt, nonTerminalCount, prodIndex, matchNonTermIndex, jumpIndex + 1);
            }
        } else {
            addToFollowSet(nt, prod[prodIndex].rhs[matchNonTermIndex], prod[prodIndex].rhs[matchNonTermIndex + jumpIndex], nonTerminalCount);
        }
    }
}

void calculateFollow(production prod[], nonTerminal nt[], int count, int nonTerminalCount) {
    nt[0].followSet[0] = '$';
    nt[0].followSet[1] = '\0';
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < nonTerminalCount; i++) {
            for (int j = 0; j < count; j++) {
                for (int k = 0; prod[j].rhs[k] != '\0'; k++) {
                    if (prod[j].rhs[k] == nt[i].nonTerminal) {
                        int initialLength = strlen(nt[i].followSet);
                        parseFollow(prod, nt, nonTerminalCount, j, k, 1);
                        if (strlen(nt[i].followSet) > initialLength) {
                            changed = true;
                        }
                    }
                }
            }
        }
    }

    printFollowSet(nt, nonTerminalCount);
}

int main() {
    FILE *fp = fopen("gram.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file gram.txt\n");
        return 1;
    }

    int nonTerminalCount = 0;
    char temp[100];
    int count = 0;
    production prod[max_prod];
    nonTerminal nt[max_prod] = {0};
    while (fscanf(fp, "%s", temp) != EOF) {
        prod[count].lhs = temp[0];
        strcpy(prod[count].rhs, &temp[2]);
        printf("Production %d: %c -> %s\n", count, prod[count].lhs, prod[count].rhs);
        count++;
    }

    for (int i = 0; i < count; i++) {
        if (!isNonterminalAlreadyPresent(nt, prod[i].lhs, nonTerminalCount)) {
            nt[nonTerminalCount].nonTerminal = prod[i].lhs;
            nt[nonTerminalCount].hasEpsilon = 0;
            nonTerminalCount++;
        }
    }
    calculateFirst(prod, nt, count, nonTerminalCount);
    calculateFollow(prod, nt, count, nonTerminalCount);
    fclose(fp);
    return 0;
}