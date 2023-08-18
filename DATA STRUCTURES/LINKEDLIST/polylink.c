#include<stdio.h>
#include<stdlib.h>
struct poly
{
	int coeff;
	int exp;
	struct poly *link;
}*a,*b,*poly,*newnode,*temp,*head;
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
			temp=poly;
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
void polyadd(struct poly *a,struct poly *b)
{
	struct poly *t1,*t2;
	t1=a;
	t2=b;
	head=NULL;
	while(t1!=NULL && t2!=NULL)
	{
		if(t1->exp==t2->exp)
		{
			res((t1->coeff+t2->coeff),t1->exp);
			t1=t1->link;
			t2=t2->link;
		}
		else if(t1->exp>t2->exp)
		{
		
			res(t1->coeff,t1->exp);
			t1=t1->link;
		}
		else if(t1->exp<t2->exp)
		{
			res(t2->coeff,t2->exp);
			t2=t2->link;
		}
	}
	while(t1!=NULL)
	{
		res(t1->coeff,t1->exp);
		t1=t1->link;
	}
	while(t2!=NULL)
	{
		res(t2->coeff,t2->exp);
		t2=t2->link;
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
	polyadd(a,b);
	printf("\nThe polynomial after addition : ");
	display(poly);
	printf("\n");
}
/*output
Enter the number of terms of polynomial 1 :3

Enter the coefficient : 4

Enter the exponent : 2

Enter the coefficient : 3

Enter the exponent : 1

Enter the coefficient : 5

Enter the exponent : 0

Enter the number of terms of polynomial 2 : 2

Enter the coefficient : 3

Enter the exponent : 2

Enter the coefficient : 6

Enter the exponent : 0

The polynomial 1 : 4x^2+3x^1+5
The polynomial 2 : 3x^2+6
The polynomial after addition : 7x^2+3x^1+11
*/
