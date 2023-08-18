#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next,*prev;
}*head=NULL,*tail=NULL,*temp,*loc;
int item,c=1;
void inbe()
{	
	printf("\nEnter the element to insert : ");
	scanf("%d",&item);
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=item;
	newnode->next=head;
	if(head!=NULL)
	{
		head->prev=newnode;
	}
	else
	{
		tail=newnode;
	}
	head=newnode;
	newnode->prev=NULL;
}
int count()
{
	int c=1;
	if(head!=NULL)
	{
		temp=head;
		while(temp->next!=NULL)
		{
			c++;
			temp=temp->next;
		}
		
	}
	return c;
}
void inen()
{
	printf("\nEnter the element to insert : ");
	scanf("%d",&item);
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=item;
	newnode->prev=tail;
	if(tail!=NULL)
	{
		tail->next=newnode;
	}
	else
	{
		head=newnode;
	}
	tail=newnode;
	newnode->next=NULL;
}
void inpo()
{	
	int pos;
	
	printf("\nEnter the position to insert : ");
	scanf("%d",&pos);
	if(pos==1)
	{
		inbe();
	}
	else
	{	
		int i;
		printf("\nEnter the element to insert : ");
		scanf("%d",&item);
		struct node *newnode;
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=item;
		temp=head;
		loc=temp->next;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
			loc=loc->next;
		}
		newnode->prev=temp;
		newnode->next=loc;
		temp->next=newnode;
		loc->prev=newnode;
	}
	
}
void disp()
{
	if(head!=NULL)
	{
		printf("\nThe elements in linkedlist is/are : ");
		temp=head;
		while(temp->next!=NULL)
		{
			printf("\t%d",temp->data);
			temp=temp->next;
		}
		printf("\t%d",temp->data);
		
	}
	else
	{
		printf("\nLinkedlist is empty");
	}
}
void del_beg()
{
	struct node *newnode;
	if(head!=NULL)
	{
		newnode=head;
		printf("\nElement deleted : %d ",newnode->data);
		if(head!=tail)
		{
			head=head->next;
			head->prev=NULL;
		}
		else
		{
			head=tail=NULL;
		}
		free(newnode);
	}
	else
	{
		printf("\nEmpty linked list");
	}
}
void del_end()
{
  	struct node *newnode;
	if(tail!=NULL)
	{
		newnode=tail;
		printf("\nElement deleted : %d ",newnode->data);
		if(head!=tail)
		{
			tail=tail->prev;
			tail->next=NULL;
		}
		else
		{
			head=tail=NULL;
		}
		free(newnode);
	}
	else
	{
		printf("\nEmpty linked list");
	}
}
void del_pos()
{
	int pos;
	if(head!=NULL)
	{
		
		int i;
		printf("\nEnter the position to delete: ");
		scanf("%d",&pos);
		if(pos==1)
		{
			del_beg();
		}
		else if(pos==count())
		{
			del_end();
		}
		else
		{
			temp=head;
			loc=temp->next;
			for(i=1;i<pos-1;i++)
			{
				temp=temp->next;
				loc=loc->next;
			}
			temp->next=loc->next;
			loc->next->prev=temp;
			printf("\nElement deleted : %d ",loc->data);
			free(loc);			
		}
	}
	else
	{
		printf("\nEmpty linked list");
	}
}
void main()
{
	int ch;
	do
	{
		printf("\nMenu");
		printf("\n1.Insert at begining");
		printf("\n2.Insert at end");
		printf("\n3.Insert at any pos");
		printf("\n4.Delete at begin");
		printf("\n5.Delete at end");
		printf("\n6.Delete at position");
		printf("\n7.Display");
		printf("\n8.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nInsert at begining");
				inbe();
				printf("\n");
				break;
			case 2:printf("\nInsert at End");
				inen();
				printf("\n");
				break;
			case 3:printf("\nInsert at any pos");
				inpo();
				printf("\n");
				break;
			case 4 : printf("\nDeletion at begining");
				 del_beg();
				 printf("\n");
				 break;
			case 5 : printf("\nDeletion at end");
				 del_end();
				 printf("\n");
				 break;
			case 6: printf("Deletion at position");
				del_pos();
				 printf("\n");\
				 break;
			case 7:printf("\nDisplay");
				disp();
				printf("\n");
				break;
			case 8 : printf("\nExited successfully\n");
				exit(0);
			default : printf("\nExited invalid input\n");
				 exit(0);
		}
	}while(1);
}
/*output

Menu
1.Insert at begining
2.Insert at end
3.Insert at any pos
4.Delete at begin
5.Delete at end
6.Delete at position
7.Display
8.Exit
Enter your choice : 1

Insert at begining
Enter the element to insert : 1


Menu
1.Insert at begining
2.Insert at end
3.Insert at any pos
4.Delete at begin
5.Delete at end
6.Delete at position
7.Display
8.Exit
Enter your choice : 2

Insert at End
Enter the element to insert : 2


Menu
1.Insert at begining
2.Insert at end
3.Insert at any pos
4.Delete at begin
5.Delete at end
6.Delete at position
7.Display
8.Exit
Enter your choice : 1

Insert at begining
Enter the element to insert : 6


Menu
1.Insert at begining
2.Insert at end
3.Insert at any pos
4.Delete at begin
5.Delete at end
6.Delete at position
7.Display
8.Exit
Enter your choice : 7

Display
The elements in linkedlist is/are : 	6	1	2

Menu
1.Insert at begining
2.Insert at end
3.Insert at any pos
4.Delete at begin
5.Delete at end
6.Delete at position
7.Display
8.Exit
Enter your choice : 3

Insert at any pos
Enter the position to insert : 2

Enter the element to insert : 3


Menu
1.Insert at begining
2.Insert at end
3.Insert at any pos
4.Delete at begin
5.Delete at end
6.Delete at position
7.Display
8.Exit
Enter your choice : 7

Display
The elements in linkedlist is/are : 	6	3	1	2

Menu
1.Insert at begining
2.Insert at end
3.Insert at any pos
4.Delete at begin
5.Delete at end
6.Delete at position
7.Display
8.Exit
Enter your choice : 4

Deletion at begining
Element deleted : 6 

Menu
1.Insert at begining
2.Insert at end
3.Insert at any pos
4.Delete at begin
5.Delete at end
6.Delete at position
7.Display
8.Exit
Enter your choice : 5

Deletion at end
Element deleted : 2 

Menu
1.Insert at begining
2.Insert at end
3.Insert at any pos
4.Delete at begin
5.Delete at end
6.Delete at position
7.Display
8.Exit
Enter your choice : 6
Deletion at position
Enter the position to delete: 2

Element deleted : 1 

Menu
1.Insert at begining
2.Insert at end
3.Insert at any pos
4.Delete at begin
5.Delete at end
6.Delete at position
7.Display
8.Exit
Enter your choice : 7

Display
The elements in linkedlist is/are : 	3

Menu
1.Insert at begining
2.Insert at end
3.Insert at any pos
4.Delete at begin
5.Delete at end
6.Delete at position
7.Display
8.Exit
Enter your choice : 8

Exited successfully
*/
