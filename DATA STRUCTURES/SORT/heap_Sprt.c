#include<stdio.h>
int main()
{
    int i,n,N=0,p,j,Lchild,Rchild,c[20],a[20],temp,x,y,k;
    printf("\nEnter size of array : ");
    scanf("%d",&n);
    printf("\nEnter array elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nArray before sorting : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nSTEPS insertion\n");
    for(i=0;i<n;i++)
    {
        N=N+1;
        c[N]=a[i];
        j=N;
        p=j/2;
        while(p>0 && c[p]<=c[j])
        {
        temp=c[p];
        c[p]=c[j];
        c[j]=temp;
        j=p;
        p=p/2;
    }
    }
    for(i=1;i<=n;i++)
    {
        printf("%d ",c[i]);
    }
    printf("\nSTEPS deletion");
    for(i=0;i<n;i++)
    {
        a[i]=c[1];
        printf("\n%d",c[1]);
        c[1]=c[N];
        N=N-1;
        j=1;
        while(j<N)
        {
            Lchild=2*j;
            Rchild=2*j+1;
            if(Lchild<=N)
            {
                x=c[Lchild];
            }
            else
            {
                x=-10;
            }
            if(Rchild<=N)
            {
                y=c[Rchild];
            }
            else
            {
                y=-10;
            }
            if(x<=c[j] && y<=c[j])
            {
                break;
            }
            else if(x>=y && x>=c[j])
            {
                temp=c[j];
                c[j]=c[Lchild];
                c[Lchild]=temp;
                j=Lchild;
            }
            else if(y>x && y>=c[j])
            {
                temp=c[j];
                c[j]=c[Rchild];
                c[Rchild]=temp;
                j=Rchild;
            }
        }
    }
    printf("\nSorted array : ");
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",a[i]);
    }
}