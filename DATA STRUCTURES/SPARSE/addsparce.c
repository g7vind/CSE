
#include<stdio.h>
void main()
{
	int a[50][50],b[50][50],s[50][50],s1[50][50],c[50][50],i,j,m,n,p,q,n_zero,r,t1,t2,k;
	printf("\nEnter the number of rows 1st  matrix : ");
	scanf("%d",&m);
	printf("\nEnter the number of cols 1st matrix : ");
	scanf("%d",&n);
	printf("\nEnter the matrix elements : \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nThe sparse matrix is 1 : ");
	for(i=0;i<m;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("\t%d",a[i][j]);
		}
	}
	n_zero=1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
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
	s[0][0]=m;
	s[0][1]=n;
	s[0][2]=n_zero-1;
	t1=s[0][2];
	printf("\nThe tripple representation of matrix 1 is : ");
	for(i=0;i<n_zero;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf("\t%d",s[i][j]);
		}
	}
	printf("\nEnter the number of rows 2nd  matrix : ");
	scanf("%d",&p);
	printf("\nEnter the number of cols 2nd matrix : ");
	scanf("%d",&q);
	printf("\nEnter the matrix elements : \n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	printf("\nThe sparse matrix is 1 : ");
	for(i=0;i<p;i++)
	{
		printf("\n");
		for(j=0;j<q;j++)
		{
			printf("\t%d",b[i][j]);
		}
	}
	n_zero=1;
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			if(b[i][j]!=0)
			{
				s1[n_zero][0]=i;
				s1[n_zero][1]=j;
				s1[n_zero][2]=b[i][j];
				n_zero=n_zero+1;
			}
		}
	}
	s1[0][0]=p;
	s1[0][1]=q;
	s1[0][2]=n_zero-1;
	t2=s1[0][2];
	printf("\nThe tripple representation of matrix 2 is : ");
	for(i=0;i<n_zero;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf("\t%d",s1[i][j]);
		}
	}
	printf("\n");
	i=1;
	j=1;
	k=1;
	if(s[0][0]==s1[0][0] && s[0][1]==s1[0][1])
	{
		while(i<=t1 && j<=t2)
		{
			if(s[i][0]==s1[j][0] && s[i][1]==s1[j][1])
			{
				c[k][0]=s[i][0];
				c[k][1]=s[i][1];
				c[k][2]=s[i][2]+s1[j][2];
				i++;
				j++;
				k++;
			}
			else if(s[i][0]==s1[j][0])
			{
				if(s[i][1]<s1[j][1])
				{
					c[k][0]=s[i][0];
					c[k][1]=s[i][1];
					c[k][2]=s[i][2];
					i++;
					k++;
				}
				else if(s[i][1]>s1[j][1])
					{
						c[k][0]=s1[j][0];
						c[k][1]=s1[j][1];
						c[k][2]=s1[j][2];
						j++;
						k++;
					}
			}
			else if(s[i][0]<s1[j][0])
			{
				c[k][0]=s[i][0];
				c[k][1]=s[i][1];
				c[k][2]=s[i][2];
				i++;
				k++;
			}
			else if(s[i][0]>s1[j][0])
				{
					c[k][0]=s1[j][0];
					c[k][1]=s1[j][1];
					c[k][2]=s1[j][2];
					j++;
					k++;
				}
			
		}
		while(i<=t1)
		{
			c[k][0]=s[i][0];
			c[k][1]=s[i][1];
			c[k][2]=s[i][2];
			i++;
			k++;
		}
		while(j<=t2)
		{
			c[k][0]=s1[j][0];
			c[k][1]=s1[j][1];
			c[k][2]=s1[j][2];
			j++;
			k++;
		}
		c[0][0]=m;
		c[0][1]=n;
		c[0][2]=k-1;
		printf("The sparse matrix after addition : ");
		for(i=0;i<k;i++)
		{
			printf("\n");
			for(j=0;j<3;j++)
			{
				printf("\t%d",c[i][j]);
			}
		}
		printf("\n");
	}
	else
	{
		printf("\nAddition not possible\n");
	}	

/*output
Enter the number of rows 1st  matrix : 4

Enter the number of cols 1st matrix : 4

Enter the matrix elements : 
0
1
0
0
0
4
0
0
0
0
0
0
2
0 
0
0

The sparse matrix is 1 : 
	0	1	0	0
	0	4	0	0
	0	0	0	0
	2	0	0	0
The tripple representation of matrix 1 is : 
	4	4	3
	0	1	1
	1	1	4
	3	0	2
Enter the number of rows 2nd  matrix : 4

Enter the number of cols 2nd matrix : 4

Enter the matrix elements : 
0
0
0
0
0
3
0
0
3
2
0
0
0
0
0
4

The sparse matrix is 1 : 
	0	0	0	0
	0	3	0	0
	3	2	0	0
	0	0	0	4
The tripple representation of matrix 2 is : 
	4	4	4
	1	1	3
	2	0	3
	2	1	2
	3	3	4
The sparse matrix after addition : 
	4	4	6
	0	1	1
	1	1	7
	2	0	3
	2	1	2
	3	0	2
	3	3	4
	*/

