#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int data;
	struct stack *link;
}*TOP=NULL,*newnode,*temp;
void push()
{	
	int item;
	printf("\nEnter the element to insert : ");
	scanf("%d",&item);
	newnode=(struct stack*)malloc(sizeof(struct stack));
	newnode->data=item;
	if(TOP==NULL)
	{
		newnode->link=NULL;
		TOP=newnode;
	}
	else
	{
		newnode->link=TOP;
		TOP=newnode;
	}
}
void pop()
{
	if(TOP==NULL)
	{
		printf("\nEmpty stack");
	}
	else if(TOP->link==NULL)
	{
		printf("\nElement deleted : %d  ",TOP->data);
		free(TOP);
		TOP=NULL;
	}
	else
	{
		temp=TOP;
		TOP=TOP->link;
		printf("\nElement deleted : %d  ",temp->data);
		free(temp);
	}
}
void disp()
{
	if(TOP!=NULL)
	{
		printf("\nThe elements in stack is/are : ");
		temp=TOP;
		while(temp!=NULL)
		{
			printf("\t%d",temp->data);
			temp=temp->link;
		}
		
	}
	else
	{
		printf("\nStack is empty");
	}
}
void main()
{
	int ch;
	do
	{
		printf("\nMenu");
		printf("\n1.PUSH");
		printf("\n2.POP");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nOption selected : PUSH\n");
				push();
				printf("\n");
				break;
			case 2:printf("\nOption selected : POP\n");
				pop();
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
1.PUSH
2.POP
3.Display
4.Exit
Enter your choice : 1

Option selected : PUSH

Enter the element to insert : 1


Menu
1.PUSH
2.POP
3.Display
4.Exit
Enter your choice : 1

Option selected : PUSH

Enter the element to insert : 2


Menu
1.PUSH
2.POP
3.Display
4.Exit
Enter your choice : 1

Option selected : PUSH

Enter the element to insert : 3


Menu
1.PUSH
2.POP
3.Display
4.Exit
Enter your choice : 3

Option selected : DISPLAY

The elements in stack is/are : 	3	2	1

Menu
1.PUSH
2.POP
3.Display
4.Exit
Enter your choice : 2

Option selected : POP

Element deleted : 3  

Menu
1.PUSH
2.POP
3.Display
4.Exit
Enter your choice : 2

Option selected : POP

Element deleted : 2  

Menu
1.PUSH
2.POP
3.Display
4.Exit
Enter your choice : 2

Option selected : POP

Element deleted : 1  

Menu
1.PUSH
2.POP
3.Display
4.Exit
Enter your choice : 2

Option selected : POP

Empty stack

Menu
1.PUSH
2.POP
3.Display
4.Exit
Enter your choice : 3

Option selected : DISPLAY

Stack is empty

Menu
1.PUSH
2.POP
3.Display
4.Exit
Enter your choice : 4

Exited successfully
*/
