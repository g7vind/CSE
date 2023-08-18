#include<stdio.h>
int a[50];
void quick_sort(int f,int l)
{
	int i,j,pivot,temp;
	if(f<l)
	{
		pivot=a[f];
		i=f;
		j=l;
		while(i<j)
		{
			while(a[i]<=pivot && i<l)
			{
				i++;
			}
			while(a[j]>=pivot && j>f)
			{
				j--;
			}
			if(i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		temp=a[j];
		a[j]=a[f];
		a[f]=temp;
		quick_sort(f,j-1);
		quick_sort(j+1,l);
	}

}
void main()
{
	int n,i;
	printf("\nEnter the number of terms of the array : ");
	scanf("%d",&n);
	printf("\nEnter the array elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nThe array elements : ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	quick_sort(0,n-1);
	printf("\nThe array after sorting  : ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	printf("\n");
	
	
}

