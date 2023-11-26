#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
    FILE *fint,*flen,*fsym,*fop;
    int op1[10],len1,len2,j=0,len;
    char addr[5],symaddr[5],op[5] ,start[10],temp[30],line[20],label[20],opcode[10],operand[10],symtab[10],code[10];
    fint=fopen("pass1.txt","r");
    flen=fopen("len.txt","r");
    fsym=fopen("symtab.txt","r");
    fop=fopen("optab.txt","r");
    fscanf(fint,"%s%s%s",label,opcode,operand);
    if(strcmp(opcode,"START")==0)
    {
        strcpy(start,operand);
        fscanf(flen,"%d",&len);
    }
    printf("H^%s^00%s^00%d\nT^00%s^00%d^",label,start,len,start,len);
    fscanf(fint,"%s%s%s%s",addr,label,opcode,operand);
    while(strcmp(opcode,"END")!=0)
    {
        fscanf(fop,"%s%s",code,op);
        while(!feof(fop))
        {
            if(strcmp(opcode,code)==0)
            {
                fclose(fop);
                fscanf(fsym,"%s%s",symtab,symaddr);
                while(!feof(fsym))
                {
                    if(strcmp(operand,symtab)==0)
                    {
                        printf("%s%s^",op,symaddr);
                        break;
                    }
                    fscanf(fsym,"%s%s",symtab,symaddr);
                }
                break;
            }
            rewind(fsym);
            fscanf(fop,"%s%s",code,op);
        }
        if((strcmp(opcode,"BYTE")==0) || (strcmp(opcode,"WORD"))==0)
        {
            if(strcmp(opcode,"WORD")==0)
                printf("00000%s^",operand);
            if(strcmp(opcode,"BYTE")==0)
            {
                len=strlen(operand);
                for(int i=2;i<len-1;i++)
                    printf("%c",operand[i]);
            }
        }
        fscanf(fint,"%s%s%s%s",addr,label,opcode,operand);
        fop=fopen("optab.txt","r");
        rewind(fop);
    }
    printf("\nE^00%s\n",start);
    printf("Pass-2 completed successfully\n");
    fclose(fint);
    fclose(fop);
    fclose(fsym);
    fclose(flen);
}


