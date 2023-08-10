#include <stdio.h>
#include<stdlib.h>
void main()
{
    int track[20],disk[20],i,j,l,k,n,total=0,h,temp,end;
    printf("Enter number of tracks : ");
    scanf("%d",&n);
    printf("Enter initial head position : ");
    scanf("%d",&h);
    printf("Enter total number of cylinders : ");
    scanf("%d",&end);
    end=end-1;
    track[0]=0;
    track[1]=h;
    track[2]=end;
    n=n+3;
    printf("Enter tracks : ");
    for(i=3;i<n;i++)
        scanf("%d",&track[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(track[j]>track[j+1])
                track[j]=track[j]^track[j+1]^(track[j+1]=track[j]);
        }
    }
    for(i=0;i<n;i++)
    {
        if(track[i]==h){
            k=i;
            break;
        }
    }
    if((h-track[0])<=(end-h))
    {
        l=0;
        for(i=k;i>=0;i--)
        {
            disk[l]=track[i];
            l++;
        }
        for(i=n-1;i>k;i--)
        {
            disk[l]=track[i];
            l++;
        }
    }
    else
    {
        l=0;
        for(i=k;i<n;i++)
        {
            disk[l]=track[i];
            l++;
        }
        for(i=0;i<k;i++)
        {
            disk[l]=track[i];
            l++;
        }
    }
    printf("Tracks traversed : ");
    for(i=0;i<l-1;i++)
        printf("%d --> ",disk[i]);
    printf("%d",disk[l-1]);
    total=0;
    for(i=0;i<l-1;i++)
            total+=abs(disk[i]-disk[i+1]);
    printf("\nTotal head movement : %d \n",total);
}
