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
        /* This code block is checking if the value of the variable `mne` is equal to the string
        "MACRO". If it is, it means that a macro definition is encountered in the input file. */
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
                /* The code block is calculating the length of the string `opnd` using the `strlen`
                function and storing it in the variable `len`. */
                len = strlen(opnd);
                for (i = 0; i < len; i++)
                {
                    /* The code block is checking each character of the `opnd` string. If the character
                    is not a comma (','), it is written to the file `fargTab` using the `fprintf`
                    function. If the character is a comma, a newline character ('\n') is written to
                    the file `fargTab` using `fprintf`. This code is essentially separating the
                    operands in `opnd` by writing them on separate lines in the `fargTab` file. */
                    if (opnd[i] != ',')
                        fprintf(fargTab, "%c", opnd[i]);
                    else
                        fprintf(fargTab, "\n");
                }
                rewind(fnamTab);
                rewind(fargTab);
                fscanf(fdefTab, "%s%s", mne1, opnd1);
                fscanf(fdefTab, "%s%s", mne1, opnd1);
                /* The code block is responsible for expanding the macro definition. It reads the lines
                from the definition table (`fdefTab`) until it encounters the "MEND" directive,
                indicating the end of the macro definition. */
                while (strcmp(mne1, "MEND") != 0)
                {
                    /* This code block is checking if the first character of the `opnd1` string is '&'.
                    If it is, it means that the operand is a macro parameter. */
                    if ((opnd1[0] == '&'))
                    {
                        fscanf(fargTab, "%s", arg);
                        fprintf(fexpTab, "-\t%s\t%s\n", mne1, arg);
                    }
                   /* The line `else fprintf(fexpTab, "-\t%s\t%s\n", mne1, opnd1);` is responsible for
                   writing the expanded macro definition to the output file `fexpTab`. */
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