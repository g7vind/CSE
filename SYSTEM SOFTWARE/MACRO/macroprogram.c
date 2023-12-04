//program to implement macro processor
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char label[10],opcode[10],operand[10],la[10],arg[10],def1[10],def2[10];
	FILE *fin,*fe,*fn,*fdef,*farg;
	int in=1,i;
	fin=fopen("source.txt","r");
	fe=fopen("expanded.txt","w+");
	fn=fopen("namtab.txt","w+");
	fdef=fopen("deftab.txt","w+");
	farg=fopen("argtab.txt","w+");
	fscanf(fin,"%s%s%s",label,opcode,operand);
	if(strcmp(opcode,"START")==0)
	{
		fprintf(fe,"%s\t%s\t%s\n",label,opcode,operand);
	}
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
			fprintf(fdef,"%s\n",opcode);
		}
		else
		{
			
			rewind(fn);
			fscanf(fn,"%s",la);
			while(!feof(fn))
			{	
				
				
				if(strcmp(la,opcode)==0)
				{
					
					for(i=0;i<strlen(operand);i++)
					{
						if(operand[i]!=',')
							fprintf(farg,"%c\n",operand[i]);
					}
					fprintf(fe,".\t%s\t%s\n",opcode,operand);
					rewind(fdef);
					fscanf(fdef,"%s%s",def1,def2);
					printf("def1=%s la=%s",def1,la);
					if(strcmp(def1,la)==0)
					{
						fscanf(fdef,"%s%s",def1,def2);
						rewind(farg);
						fscanf(farg,"%s",arg);
						printf("arg=%s",arg);
						while(strcmp(def1,"MEND")!=0)
						{
							fprintf(fe,"*\t%s\t%s\n",def1,arg);
							
							fscanf(fdef,"%s%s",def1,def2);
							fscanf(farg,"%s",arg);
						}
						fseek(farg,SEEK_SET,0);
					}
					
					
				}
				fscanf(fn,"%s",la);
				
				

			
			}
			
			
				
		}	
		fscanf(fin,"%s%s%s",label,opcode,operand);
	}
	fprintf(fe,"%s\t%s\t%s\n",label,opcode,operand);
	fclose(fin);
	fclose(fn);
	fclose(fdef);
	fclose(fe);
	fclose(farg);
	return 0;
}
