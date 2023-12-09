#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	char label[10],opcode[10],operand[10],la[10],arg[10],def1[10],def2[10];
	FILE *fin,*fe,*fn,*fdef,*farg;
	int in=1,i,flag=0;
	fin=fopen("minp2.txt","r");
	fe=fopen("expanded.txt","w+");
	fn=fopen("namtab.txt","w+");
	fdef=fopen("definition.txt","w+");
	farg=fopen("argtab.txt","w+");
	fscanf(fin,"%s%s%s",label,opcode,operand);
	while(!feof(fin))
	{	
		if(strcmp(opcode,"MACRO")==0)
		{
			fprintf(fn,"%s\n",label);
			fprintf(fdef,"%s\t%s\n",label,operand);
			fscanf(fin,"%s%s%s",label,opcode,operand);
			while(strcmp(opcode,"MEND")!=0)
			{
			if(operand[0]=='&')
			{
				fprintf(fdef,"%s\t?%d\n",opcode,in);
				in++;
			}
			else
				fprintf(fdef,"%s\t%s\n",opcode,operand);
			fscanf(fin,"%s%s%s",label,opcode,operand);
			}
			fprintf(fdef,"%s\t**\n",opcode);
		}
		else
		{
			rewind(fn);
			fscanf(fn,"%s",la);
			while(!feof(fn))
			{	
				if(strcmp(la,opcode)==0)
				{
					flag=1;
                    freopen("argtab.txt","w+",farg);
					for(i=0;i<strlen(operand);i++)
					{
						if(operand[i]!=','){
                            
							fprintf(farg,"%c",operand[i]);
                    }
                        else
                            fprintf(farg,"\n");
					}
					rewind(fdef);
					fscanf(fdef,"%s%s",def1,def2);
                    printf("def1 = %s\tdef2 = %s\n",def1,def2);
                    while (!feof(fdef))
                    {
                        printf("la = %s\tdef1 = %s\n",la,def1);
                        if(strcmp(def1,la)==0)
                        {
                            printf("Inside if \n");
                            fscanf(fdef,"%s\t%s",def1,def2);
                            rewind(farg);
                            fscanf(farg,"%s",arg);
                            while(strcmp(def1,"MEND")!=0)
                            {
                                fprintf(fe,"-\t%s\t%s\n",def1,arg);
                                fscanf(fdef,"%s%s",def1,def2);
                                fscanf(farg,"%s",arg);
                            }
                            break;
                        }
                        fscanf(fdef,"%s\t%s",def1,def2);
                    }
				}
				fscanf(fn,"%s",la);
			}
			if(flag==0)
			{
				fprintf(fe,"%s\t%s\t%s\n",label,opcode,operand);
			}
			flag=0;
		}	
		fscanf(fin,"%s%s%s",label,opcode,operand);
	}
    fprintf(fe,"%s\t%s\t%s\n",label,opcode,operand);
    printf("Single Pass macro processor successful\n");
	fclose(fin);
	fclose(fn);
	fclose(fdef);
	fclose(fe);
	fclose(farg);
}
