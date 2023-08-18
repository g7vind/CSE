#include<stdio.h>
#include<stdlib.h>
struct poly
{
	int coeff;
	int exp;
	struct poly *link;
}*a,*b,*poly,*newnode,*temp,*pol,*head;
struct poly* createpoly(int n)
{
	int c,e,i=1;
	head=NULL;
	while(i<=n)
	{
		newnode=(struct poly*)malloc(sizeof(struct poly));
		printf("\nEnter the coefficient : ");
		scanf("%d",&c);
		printf("\nEnter the exponent : ");
		scanf("%d",&e);
		newnode->coeff=c;
		newnode->exp=e;
		newnode->link=NULL;
		if(head==NULL)
		{
			head=newnode;
			temp=head;
		}
		else
		{
			temp->link=newnode;
			temp=newnode;
		}
		i++;
	}
	return head;
}
int large()
{
    int l=0;
    temp=poly;
    while(temp!=NULL)
    {
        if(l<temp->exp)
        {
            l=temp->exp;
        }
        temp=temp->link;
    }
    return l;
}
void res(int x,int y)
{	
		
		newnode=(struct poly*)malloc(sizeof(struct poly));
		newnode->coeff=x;
		newnode->exp=y;
		newnode->link=NULL;
		if(head==NULL)
		{
			head=newnode;
			poly=head;
			temp=head;
		}
		else
		{
			temp->link=newnode;
			temp=newnode;
		}
}
void display(struct poly *x)
{
	int i;
	temp=x;
	printf("%dx^%d",temp->coeff,temp->exp);
	temp=temp->link;
	while(temp!=NULL)
	{
		if(temp->exp==0)
		{
			printf("+%d",temp->coeff);	
		}
		else
		{
			printf("+%dx^%d",temp->coeff,temp->exp);
		}
		temp=temp->link;
	}
	
}
void polymul()
{
    int i,s=0;
	struct poly *t1,*t2;
	t1=a;
	t2=b;
	head=NULL;
	while(t1!=NULL)
	{
		while(t2!=NULL)
		{
			res((t1->coeff*t2->coeff),(t1->exp+t2->exp));
			t2=t2->link;
		}
		t2=b;
		t1=t1->link;
	}
	t1=poly;
	head=NULL;
	for(i=large();i>=0;i--)
	{
	    while(t1!=NULL)
	    {
	        if(t1->exp==i)
	        {
	            s=s+t1->coeff;
	        }
	        t1=t1->link;
	    }
	    newnode=(struct poly*)malloc(sizeof(struct poly));
		newnode->coeff=s;
		newnode->exp=i;
		newnode->link=NULL;
		if(head==NULL)
		{
		    head=newnode;
		    pol=head;
		    t2=head;
		}
		else
		{
		    t2->link=newnode;
		    t2=newnode;
		}
		t1=poly;
		s=0;
		
	    
	}
}
void main()
{
	int n1,n2;
	printf("\nEnter the number of terms of polynomial 1 :");
	scanf("%d",&n1);
	a=createpoly(n1);
	printf("\nEnter the number of terms of polynomial 2 : ");
	scanf("%d",&n2);
	b=createpoly(n2);
	printf("\nThe polynomial 1 : ");
	display(a);
	printf("\nThe polynomial 2 : ");
	display(b);
	polymul();
	printf("\nThe polynomial after multiplication : ");
	display(pol);
	printf("\n");
}