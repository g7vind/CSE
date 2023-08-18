#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int data;
	struct queue *link;
}*F=NULL,*R=NULL,*newnode,*temp;
void enqueue()
{	
	int item;
	printf("\nEnter the element to insert : ");
	scanf("%d",&item);
	newnode=(struct queue*)malloc(sizeof(struct queue));
	newnode->data=item;
	newnode->link=NULL;
	if(F==NULL && R==NULL)
	{
		F=newnode;
		R=newnode;
	}
	else
	{
		R->link=newnode;
		R=newnode;
	}
}
void dequeue()
{
	if(F==NULL && R==NULL)
	{
		printf("\nEmpty queue");
	}
	else if(F==R)
	{
		temp=F;
		printf("\nElement deleted : %d  ",F->data);
		free(temp);
		F=NULL;
		R=NULL;
	}
	else
	{
		temp=F;
		F=F->link;
		printf("\nElement deleted : %d  ",temp->data);
		free(temp);
	}
}
void disp()
{
	if(F!=NULL)
	{
		printf("\nThe elements in queue is/are : ");
		temp=F;
		while(temp!=NULL)
		{
			printf("\t%d",temp->data);
			temp=temp->link;
		}
		
	}
	else
	{
		printf("\nqueue is empty");
	}
}
void main()
{
	int ch;
	do
	{
		printf("\nMenu");
		printf("\n1.Enqueue");
		printf("\n2.Dequeue");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nOption selected : Enqueue\n");
				enqueue();
				printf("\n");
				break;
			case 2:printf("\nOption selected : Dequeue\n");
				dequeue();
				printf("\n");
				break;
			case 3:printf("\nOption selected : DISPLAY\n");
				disp();
				printf("\n");
				break;
			case 4: printf("\nExited successfully\n");
				exit(0);
			default:printf("\nInvalid Input\n");
		}
	}while(1);
}
/*output
Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 1

Option selected : Enqueue

Enter the element to insert : 1


Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 1

Option selected : Enqueue

Enter the element to insert : 2


Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 1

Option selected : Enqueue

Enter the element to insert : 3


Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 3

Option selected : DISPLAY

The elements in queue is/are : 	1	2	3

Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 2

Option selected : Dequeue

Element deleted : 1  

Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 2

Option selected : Dequeue

Element deleted : 2  

Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 2

Option selected : Dequeue

Element deleted : 3  

Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 2

Option selected : Dequeue

Empty queue

Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 3

Option selected : DISPLAY

queue is empty

Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 4

Exited successfully
*/
