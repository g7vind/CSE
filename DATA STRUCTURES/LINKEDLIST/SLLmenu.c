#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*head=NULL,*temp,*loc;
int item,c=1;
void inbe()
{	
	printf("\nEnter the element to insert : ");
	scanf("%d",&item);
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=item;
	if(head==NULL)
	{
		newnode->link=NULL;
		head=newnode;
	}
	else
	{
		newnode->link=head;
		head=newnode;
	}
}
void inen()
{
	printf("\nEnter the element to insert : ");
	scanf("%d",&item);
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=item;
	newnode->link=NULL;
	if(head!=NULL)
	{
		temp=head;
		while(temp->link!=NULL)
		{
			temp=temp->link;
			c++;
		}
		temp->link=newnode;
	}
	else
	{
		head=newnode;
	}
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
	{	printf("\nEnter the element to insert : ");
		scanf("%d",&item);
		struct node *newnode;
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=item;
		newnode->link=NULL;
		
			int i;
			temp=head;
			for(i=1;i<pos-1;i++)
			{
				temp=temp->link;
			}
			newnode->link=temp->link;
			temp->link=newnode;
	}
	
}
void disp()
{
	if(head!=NULL)
	{
		printf("\nThe elements in linkedlist is/are : ");
		temp=head;
		while(temp->link!=NULL)
		{
			printf("\t%d",temp->data);
			temp=temp->link;
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
	if(head==NULL)
	{
		printf("\nEmpty linked list");
	}
	else
	{
		temp=head;
		head=head->link;
		printf("\nElement deleted : %d  ",temp->data);
		free(temp);
	}
}
void del_end()
{
	if(head==NULL)
	{
		printf("\nEmpty linked list");
	}
	else
	{
		if(head->link==NULL)
		{
			temp=head;
			head=head->link;
			printf("\nElement deleted : %d ",temp->data);
			free(temp);
		}
		else
		{
			temp=head;
			loc=temp->link;
			while(loc->link!=NULL)
			{
				temp=temp->link;
				loc=loc->link;
			}
			temp->link=NULL;
			printf("\nElement deleted : %d ",loc->data);
			free(loc);
		}
	}
}
void del_pos()
{
	int pos;
	if(head==NULL)
	{
		printf("\nEmpty linked list");
	}
	else
	{
		int i;
		printf("\nEnter the position to delete: ");
		scanf("%d",&pos);
		if(pos==1)
		{
			del_beg();
		}
		else
		{
			temp=head;
			loc=temp->link;
			for(i=1;i<pos-1;i++)
			{
				temp=temp->link;
				loc=loc->link;
			}
			temp->link=loc->link;
			printf("\nElement deleted : %d ",loc->data);
			free(loc);			
		}
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
Enter the element to insert : 4


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
Enter the element to insert : 8


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
The elements in linkedlist is/are : 	4	2	8	6

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
Enter the position to insert : 3

Enter the element to insert : 10


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
The elements in linkedlist is/are : 	4	2	10	8	6

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
Element deleted : 4  

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
Enter your choice : 6
Deletion at position
Enter the position to delete: 3

Element deleted : 8 

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
The elements in linkedlist is/are : 	2	10

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
