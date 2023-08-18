#include<stdio.h>
#include<stdlib.h>
int n;
int DQ[50];
int F=-1;
int R=-1;
void PUSHDQ()
{
	int item,temp;
	printf("\nEnter the element to PUSHDQ : ");
	scanf("%d",&item);
	if(F==-1 && R==-1)
	{
		F=0;
		R=0;
		DQ[F]=item;
	}
	else
	{
		if(F==0)
		{
			temp=n-1;
		}
		else
		{
			temp=F-1;
		}
		if(temp==R)
		{
			printf("\nDEQUE is Full");
		}
		else
		{
			F=temp;
			DQ[F]=item;
		}
	}
	
}
void POPDQ()
{
	if(F==-1 && R==-1)
	{
		printf("\nDEQUE is empty");
	}
	else
	{
		if(R==F)
		{
        		printf("\nThe element POPDQED : %d",DQ[F]);
			F=-1;
			R=-1;
			
		}
		else
		{
			printf("\nThe element POPDQED  : %d",DQ[F]);
			F=(F+1)%n;
		}
	}
}
void INJECT()
{
	int item,next;
	printf("\nEnter the element to INJECT : ");
	scanf("%d",&item);
	if(F==-1 && R==-1)
	{
		F=0;
		R=0;
		DQ[R]=item;
	}
	else
	{
		next=(R+1)%n;
		if(next==F)
		{
			printf("\nDEQUE is full");
		}
		else
		{
			R=(R+1)%n;
			DQ[R]=item;
		}
	}
}
void EJECT()
{
	if(F==-1 && R==-1)
	{
		printf("\nDEQUE is empty");
	}
	else
	{
		if(F==R)
		{
			printf("\nThe element POPDQED : %d",DQ[R]);
			R=-1;
			F=-1;
		}
		else
		{
			if(R==0)
			{
				printf("\nThe element Ejected : %d",DQ[R]);
				R=n-1;
			}
			else
			{
				printf("\nThe element Ejected : %d",DQ[R]);
				R=R-1;
			}
		}
	}
}
void DISPLAY()
{
	int i;
	if(F==-1 && R==-1)
	{
		printf("\nQueue underflow");
	}
	else
	{
		printf("\nThe queue : ");
		i=F;
		while(i!=R)
		{
			printf("\t%d",DQ[i]);
			i=(i+1)%n;
		}
		printf("\t%d",DQ[R]);
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
		printf("\n1.PUSHDQ");
		printf("\n2.POPDQ");
		printf("\n3.INJECT");
		printf("\n4.EJECT");
		printf("\n5.Display");
		printf("\n6.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\nPUSHDQ");
				PUSHDQ();
				break;
			case 2:printf("\nPOPDQ");
				POPDQ();
				break;
			case 3:printf("\nINJECT");
				INJECT();
				break;
			case 4 :printf("\nEJECT");
				EJECT();
				break;
			case 5:printf("\nDisplay");
				DISPLAY();
				break;	
			case 6:printf("\nExited successfully\n");
				exit(0);
			default :printf("\ninvalid input");
		}
		printf("\n");
	}while(1);
	printf("\n");
}
/*output
Enter the number of elements in the queue : 5

Menu
1.PUSHDQ
2.POPDQ
3.INJECT
4.EJECT
5.Display
6.Exit
Enter your choice : 1

PUSHDQ
Enter the element to PUSHDQ : 8


Menu
1.PUSHDQ
2.POPDQ
3.INJECT
4.EJECT
5.Display
6.Exit
Enter your choice : 1

PUSHDQ
Enter the element to PUSHDQ : 6


Menu
1.PUSHDQ
2.POPDQ
3.INJECT
4.EJECT
5.Display
6.Exit
Enter your choice : 3

INJECT
Enter the element to INJECT : 2


Menu
1.PUSHDQ
2.POPDQ
3.INJECT
4.EJECT
5.Display
6.Exit
Enter your choice : 4

EJECT
The element Ejected : 2

Menu
1.PUSHDQ
2.POPDQ
3.INJECT
4.EJECT
5.Display
6.Exit
Enter your choice : 5

Display
The queue : 	6	8

Menu
1.PUSHDQ
2.POPDQ
3.INJECT
4.EJECT
5.Display
6.Exit
Enter your choice : 6

Exited successfully*/
