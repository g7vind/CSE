#include<stdio.h>
#include<stdlib.h>
int FRONT=-1;
int REAR=-1;
int Q[50];
int n;
void Enqueue()
{
	int item;
	printf("\nEnter the element to enqueue : ");
	scanf("%d",&item);
	if(REAR==n-1)
	{
		printf("\nQueue overflow");
	}
	else
	{
		if(FRONT==-1 && REAR==-1)
		{
			FRONT=0;
		}
		REAR++;
		Q[REAR]=item;
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
        	printf("\nThe element Dequeued : %d",Q[FRONT]);
		if(REAR==FRONT)
		{
			FRONT=-1;
			REAR=-1;
			
		}
		else
		{
			FRONT++;
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
		for(i=FRONT;i<=REAR;i++)
		{
			printf("%d\t",Q[i]);
		}
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
Enter the element to enqueue : 2


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
Enter your choice : 2

Dequeue
The element Dequeued : 2

Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 3

Display
The queue : 3	

Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 2

Dequeue
The element Dequeued : 3

Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 3

Display
Queue underflow

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
The queue : 2	

Menu
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice : 4

Exited successfully*/
