#include<stdio.h>
int c[50],b[50],n,x=0;
void merge(int a,int x, int d)
{
	int i,j,k;
	i=a;
	j=x+1;
	k=a;
	while(i<=x && j<=d)
	{
		if(c[i]<=c[j])
		{
			b[k]=c[i];
			i++;
		}
		else
		{
			b[k]=c[j];
			j++;
		}
		k++;
	}
	while(i<=x)
	{
		b[k]=c[i];
		i++;
		k++;
	}
	while(j<=d)
	{
		b[k]=c[j];
		j++;
		k++;
	}
	for(i=a;i<=d;i++)
	{
		c[i]=b[i];
	}
}
void merge_sort(int a,int b)
{
	int mid,k;
	if(a<b)
	{
		mid=(a+b)/2;
		merge_sort(a,mid);
		merge_sort(mid+1,b);
		merge(a,mid,b);
		x++;
		printf("\nIteration %d: ",x);
		for (k = 0; k < n; k++)
		{
			printf("%d ", c[k]);
		}	
	}
}
void main()
{
    int i,l,h;
    printf("\nEnter the limit of the array : ");
	scanf("%d",&n);
    printf("\nEnter the array elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
	}
	printf("\nThe array is : ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",c[i]);
	}
	l=0;
	h=n-1;
	merge_sort(l,h);
	printf("\nThe array after sorting : ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",c[i]);
	}
	printf("\n");
}