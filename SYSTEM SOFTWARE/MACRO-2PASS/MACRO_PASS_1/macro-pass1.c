#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *finput, *fnamTab, *fdefTab;
    char mne[20], opnd[20], la[20];
    finput = fopen("minp2.txt", "r");
    fnamTab = fopen("ntab2.txt", "w+");
    fdefTab = fopen("dtab2.txt", "w+");
    if(finput == NULL || fnamTab == NULL || fdefTab == NULL) {
        printf("Error opening file\n");
        exit(0);
    }
    while (fscanf(finput, "%s%s%s", la, mne, opnd) != EOF) {
        if (strcmp(mne, "MACRO") == 0) {
            fprintf(fnamTab, "%s\n", la);
            fprintf(fdefTab, "%s\t%s\n", la, opnd);
            fscanf(finput, "%s%s%s", la, mne, opnd); 
            while (strcmp(mne, "MEND") != 0) {
                fprintf(fdefTab, "%s\t%s\n", mne, opnd);
                fscanf(finput, "%s%s%s", la, mne, opnd);
            }
            fprintf(fdefTab, "%s **\n", mne); 
        }
    }
    fclose(finput);
    fclose(fnamTab);
    fclose(fdefTab);  
    printf("PASS 1 is successful\n");
    return 0;
}