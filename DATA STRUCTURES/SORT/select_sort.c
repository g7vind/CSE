#include<stdio.h>
void sel_sort()
{
	int i,n,min,loc,j,t,a[50],x=0;
	printf("\nEnter the limit of the array : ");
	scanf("%d",&n);
	printf("\nEnter the array elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nThe array is : ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		min=a[i];
		loc=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<min)
			{
				min=a[j];
				loc=j;
			}
		}
		if(loc!=i)
		{
			t=a[i];
			a[i]=a[loc];
			a[loc]=t;
			x++;
			printf("\nIteration %d: ",x);
			for (int k = 0; k < n; k++)
			{
				printf("%d ", a[k]);
			}
		}
	}
	printf("\nThe array after sorting : ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	
}
void main()
{
    sel_sort();
}