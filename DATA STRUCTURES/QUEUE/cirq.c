#include<stdio.h>
#include<stdlib.h>
int FRONT=-1;
int REAR=-1;
int CQ[50];
int n;
void Enqueue()
{
	int item,next;
	printf("\nEnter the element to enqueue : ");
	scanf("%d",&item);
	if(FRONT==-1 && REAR==-1)
	{
		FRONT=0;
		REAR=0;
		CQ[REAR]=item;
	}
	else
	{
		next=(REAR+1)%n;
		if(next==FRONT)
		{
			printf("\nQueue overflow");
		}
		else
		{
			REAR=(REAR+1)%n;
			CQ[REAR]=item;
		}
	}
}
void Dequeue()
{
	if(FRONT==-1 && REAR==-1)
	{
		printf("\nQueue underflow");
	}
	else
	{
		if(REAR==FRONT)
		{
        		printf("\nThe element Dequeued : %d",CQ[FRONT]);
			FRONT=-1;
			REAR=-1;
			
		}
		else
		{
			printf("\nThe element Dequeued : %d",CQ[FRONT]);
			FRONT=(FRONT+1)%n;
		}
	}
}
void Display()
{
	int i;
	if(FRONT==-1 && REAR==-1)
	{
		printf("\nQueue underflow");
	}
	else
	{
		printf("\nThe queue : ");
		i=FRONT;
		while(i!=REAR)
		{
			printf("%d\t",CQ[i]);
			i=(i+1)%n;
		}
		printf("%d\t",CQ[REAR]);
	}
}
void main()
{
	int choice;
	printf("\nEnter the number of elements in the queue : ");
	scanf("%d",&n);
	do
	{
		printf("\nMenu");
		printf("\n1.Enqueue");
		printf("\n2.Dequeue");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\nEnqueue");
				Enqueue();
				break;
			case 2:printf("\nDequeue");
				Dequeue();
				break;
			case 3:printf("\nDisplay");
				Display();
				break;	
			case 4:printf("\nExited successfully\n");
				exit(0);
			default :printf("\ninvalid input");
		}
		printf("\n");
	}while(1);
	printf("\n");
}
/*output
Enter the number of elements in the queue : 2

Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 1

Enqueue
Enter the element to enqueue : 1


Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 1

Enqueue
Enter the element to enqueue : 2


Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 3

Display
The queue : 1	2	

Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 1

Enqueue
Enter the element to enqueue : 3

Queue overflow

Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 3

Display
The queue : 1	2	

Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 2

Dequeue
The element Dequeued : 1

Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 1

Enqueue
Enter the element to enqueue : 3


Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 3

Display
The queue : 2	3	

Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 4

Exited successfully
*/

