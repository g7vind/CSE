#include <stdio.h>
int a[50];
void bubble_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void main()
{
    int n,i;
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
    bubble_sort(a,n);
    printf("\nThe array after sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}
