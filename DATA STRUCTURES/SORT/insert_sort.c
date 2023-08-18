#include<stdio.h>
void main()
{
	int i,n,min,loc,j,t,b[50],x=0;
	printf("\nEnter the limit of the array : ");
	scanf("%d",&n);
	printf("Enter the array elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	printf("\nThe array is : ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",b[i]);
	}
	for(i=1;i<n;i++)
	{
		min=b[i];
		for(j=i-1;j>=0;j--)
		{
			if(min<b[j])
			{
				b[j+1]=b[j];
			}
			else
			{
				break;
			}
		}
		b[j+1]=min;
		x++;
		printf("\nIteration %d: ",x);
		for (int k = 0; k < n; k++)
		{
			printf("%d ", b[k]);
		}
	}
	printf("\nThe array after sorting : ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",b[i]);
	}
}
