#include<stdio.h>
#include<stdlib.h>
int a[50],b[50],n;
/**
 * It takes an array of numbers and creates a heap out of it
 */
void createHeap()
{
    int i = 1,j,x,temp;
    while(i<=n)
    {
        x = a[i];
        b[i] = x;
        j=i;
        while (j!=1)
        {
            if (b[j] > b[j/2])
            {
                temp = b[j];
                b[j] = b[j/2];
                b[j/2] = temp;
            }
            j/=2;            
        }
        i++;
    }
}
/**
 * It removes the maximum element from the heap.
 * 
 * @param x the index of the element to be removed
 */
void removeMax(int i)
{
    int temp;
    temp = b[i];
    b[i] = b[1];
    b[1] = temp;
}
/**
 * It takes an array of integers and a number of elements in the array as input and returns the array
 * with the largest element removed
 * 
 * @param x the number of elements in the heap
 */
void rebuildHeap(int x)
{
    int j=1,flag=1,temp,lChild,rChild;
    if (x!=1)
    {
        while (flag==1)
        {
            lChild = 2*j, rChild = 2*j+1;
            if (rChild <= x)
            {
                if (b[j] < b[lChild] && b[lChild] > b[rChild])
                {
                    temp = b[j];
                    b[j] = b[lChild];
                    b[lChild] = temp;
                    j = lChild;
                }
                else if(b[j] < b[rChild] && b[rChild] > b[lChild])
                {
                        temp = b[j];
                        b[j] = b[rChild];
                        b[rChild] = temp;
                        j = rChild;
                }
                else
                {
                    flag = 0;
                }  
            }            
            else 
            if (lChild <= x)
            {
                if (b[j] < b[lChild] && b[lChild] > b[rChild])
                {
                    temp = b[j];
                    b[j] = b[lChild];
                    b[lChild] = temp;
                    j = lChild;
                }
                else
                {
                    flag = 0;
                }
                
            }
            else
            {
                flag = 0;
            }
        }
    }
}
void main()
{
    int i;
    printf("\nEnter the limit of the array : ");
    scanf("%d",&n);
    printf("\nEnter the array elements : \n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nThe array is : ");
	for(i=1;i<=n;i++)
	{
		printf("\t%d",a[i]);
	}
    createHeap();
    for(i=n;i>=2;i--)
    {
        removeMax(i);
        rebuildHeap(i-1);
    }
    printf("\nThe array after sorting : ");
	for(i=1;i<=n;i++)
	{
		printf("\t%d",b[i]);
	}
	printf("\n");
}
