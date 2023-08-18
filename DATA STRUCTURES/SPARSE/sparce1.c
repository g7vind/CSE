#include<stdio.h>
void main()
{
	int a[50][50],s[50][50],i,j,row,col,n_zero;
	printf("\nEnter the number of rows of the matrix : ");
	scanf("%d",&row);
	printf("\nEnter the number of cols of the matrix : ");
	scanf("%d",&col);
	printf("\nEnter the matrix elements : \n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nThe sparse matrix is : ");
	for(i=0;i<row;i++)
	{
		printf("\n");
		for(j=0;j<col;j++)
		{
			printf("\t%d",a[i][j]);
		}
	}
	n_zero=1;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(a[i][j]!=0)
			{
				s[n_zero][0]=i;
				s[n_zero][1]=j;
				s[n_zero][2]=a[i][j];
				n_zero=n_zero+1;
			}
		}
	}
	s[0][0]=row;
	s[0][1]=col;
	s[0][2]=n_zero-1;
	printf("\nThe tripple representation is : ");
	for(i=0;i<n_zero;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf("\t%d",s[i][j]);
		}
	}
	printf("\n");
	
	
	
}
/*output
Enter the number of rows of the matrix : 3

Enter the number of cols of the matrix : 3

Enter the matrix elements : 
0
1
0
0
0
2
3
0
0

The sparse matrix is : 
	0	1	0
	0	0	2
	3	0	0
The tripple representation is : 
	3	3	3
	0	1	1
	1	2	2
	2	0	3
*/
