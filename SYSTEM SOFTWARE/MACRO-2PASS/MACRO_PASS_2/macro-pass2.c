#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
    FILE *finput, *fnamTab, *fdefTab, *fargTab, *fexpTab;
    int i, len;
    char mne[20], opnd[20], la[20], name[20], mne1[20], opnd1[20], arg[20];
    finput = fopen("minp2.txt", "r");
    fnamTab = fopen("ntab2.txt", "r");
    fdefTab = fopen("dtab2.txt", "r");
    fargTab = fopen("atab2.txt", "w+");
    fexpTab = fopen("op2.txt", "w");
    fscanf(finput, "%s%s%s", la, mne, opnd);
    while (strcmp(mne, "END") != 0)
    {
        if (strcmp(mne, "MACRO") == 0)
        {
            fscanf(finput, "%s%s%s", la, mne, opnd);
            while (strcmp(mne, "MEND") != 0)
                fscanf(finput, "%s%s%s", la, mne, opnd);
        }
        else
        {
            fscanf(fnamTab, "%s", name);
            if (strcmp(mne, name) == 0)
            {
                len = strlen(opnd);
                for (i = 0; i < len; i++)
                {
                    if (opnd[i] != ',')
                        fprintf(fargTab, "%c", opnd[i]);
                    else
                        fprintf(fargTab, "\n");
                }
                rewind(fnamTab);
                rewind(fargTab);
                fscanf(fdefTab, "%s%s", mne1, opnd1);
                fscanf(fdefTab, "%s%s", mne1, opnd1);
                while (strcmp(mne1, "MEND") != 0)
                {
                    if ((opnd1[0] == '&'))
                    {
                        fscanf(fargTab, "%s", arg);
                        fprintf(fexpTab, "-\t%s\t%s\n", mne1, arg);
                    }
                    else
                        fprintf(fexpTab, "-\t%s\t%s\n", mne1, opnd1);
                    fscanf(fdefTab, "%s%s", mne1, opnd1);
                }
            }
            else
                fprintf(fexpTab, "%s\t%s\t%s\n", la, mne, opnd);
        }
        fscanf(finput, "%s%s%s", la, mne, opnd);
    }
    fprintf(fexpTab, "%s\t%s\t%s", la, mne, opnd);
    fclose(finput);
    fclose(fnamTab);
    fclose(fdefTab);
    fclose(fargTab);
    fclose(fexpTab);
    printf("Pass 2 is successful");
}