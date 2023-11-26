#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

char l[10];

struct symhash
{
    char name[10];
    int addr;
    struct symhash *next;
} p[10];
int generateKey(char *label) {
    int sum = 0;
    for (int i = 0; label[i] != '\0'; i++) {
        sum += label[i];
    }
    return sum % MAX;
}
void displaySymbolTable() {
    printf("Symbol table\n");
    printf("Key\tName\tAddress\n");
    for (int i = 0; i < MAX; i++) {
        if (p[i].addr != -1) {
            printf("%d\t%s\t%d\n", i, p[i].name, p[i].addr);
            if (p[i].next != NULL) {
                struct symhash *current = p[i].next;
                while (current != NULL) {
                    printf("%d\t%s\t%d\n", i, current->name, current->addr);
                    current = current->next;
                }
            }
        }
    }
}
void searchLabel(char *label) {
    int key = generateKey(label);
    if (strcmp(p[key].name, label) == 0) {
        printf("Label found at index %d\n", key);
    } else if (p[key].next != NULL) {
        struct symhash *current = p[key].next;
        while (current != NULL) {
            if (strcmp(current->name, label) == 0) {
                printf("Label found at index %d\n", key);
                return;
            }
            current = current->next;
        }
    }
    printf("Label not found\n");
}
void main() {
    int choice, k;
    char exitCommand[] = "exit";
    do {
        printf("Choose an option:\n");
        printf("1) Create a symbol table\n");
        printf("2) Search in the symbol table\n");
        printf("3) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                for (int i = 0; i < MAX; i++) {
                    p[i].addr = -1;
                    strcpy(p[i].name, "NULL");
                    p[i].next = NULL;
                }
                printf("\n---------------------------------------------------------------\n");
                printf("You have choosen to create a symbol table\n");
                do {
                    printf("\n1) Add a new label\n");
                    printf("2) End operation\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    if (choice == 1) {
                        printf("\nEnter the label name: ");
                        scanf("%s", l);
                        printf("Enter the address: ");
                        scanf("%d", &k);
                        int key = generateKey(l);
                        while (1) {
                            if (p[key].addr == -1) {
                                p[key].addr = k;
                                strcpy(p[key].name, l);
                                break;
                            } else {
                                if (strcmp(p[key].name, l) == 0) {
                                    printf("\tDuplicate label\n");
                                    exit(0);
                                } else {
                                    if (p[key].next == NULL) {
                                        p[key].next = (struct symhash *)malloc(sizeof(struct symhash));
                                        p[key].next->addr = k;
                                        strcpy(p[key].next->name, l);
                                        p[key].next->next = NULL;
                                        break;
                                    } else {
                                        p[key].next = p[key].next->next;
                                    }
                                }
                            }
                        }
                    } else if (choice != 2) {
                        printf("Invalid choice\n");
                    }
                } while (choice != 2);
                printf("\n");
                displaySymbolTable();
                printf("\n");
                break;
            case 2:
                printf("\n---------------------------------------------------------------\n");
                printf("You have choosen to search in the symbol table\n");
                printf("Enter label to search (or type 'exit' to stop): ");
                scanf("%s", l);
                if (strcmp(l, exitCommand) != 0) {
                    searchLabel(l);
                }
                printf("\n");
                break;
            case 3:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 0);
}