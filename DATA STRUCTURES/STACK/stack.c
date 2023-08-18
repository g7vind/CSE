#include<stdio.h>
#include<stdlib.h>
int st[50],TOP,ele,size,choice;
void push(int n)
{
    if(TOP>=n-1)
    {
        printf("\nStack Overflow\n");
    }
    else
    {
        printf("\nEnter the element to push : ");
        scanf("%d",&ele);
        TOP=TOP+1;
        st[TOP]=ele;
    }
}
void pop()
{
    int ele;
    if(TOP<=-1)
    {
        printf("\nStack empty\n");
    }
    else
    {   
        printf("\nItem to be popped : %d \n",st[TOP]);
        TOP=TOP-1;
    }
}
void disp()
{
	int i;
	i=TOP;
    if(TOP==-1)
    {
        printf("\nstack empty\n");
    }
    else
    {
        printf("\nStack : ");
        while(i!=-1)
        {
            printf("\t%d",st[i]);
            i--;
        }
        printf("\n");
    }
}
void main()
{
  
    TOP=-1;
    printf("Enter the size of the stack : ");
    scanf("%d",&size);
    do
    {
        printf("\t\nMenu");
        printf("\t\n1.Push");
        printf("\t\n2.Pop");
        printf("\t\n3.Display");
        printf("\t\n4.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\n......PUSH......\n");
                    push(size);
                    break;
            case 2:printf("\n......POP......\n");
                    pop();
                    break;
            case 3:printf("\n......DISPLAY......\n");
                    disp();
                    break;
            case 4:printf("\nYou have exited successfully\n") ;
            		exit(0);

        }
    } while (1);
    
}
/*output
Enter the size of the stack : 1
	
Menu	
1.Push	
2.Pop	
3.Display	
4.Exit
Enter your choice : 1

......PUSH......

Enter the element to push : 2
	
Menu	
1.Push	
2.Pop	
3.Display	
4.Exit
Enter your choice : 1

......PUSH......

Stack Overflow
	
Menu	
1.Push	
2.Pop	
3.Display	
4.Exit
Enter your choice : 3

......DISPLAY......

Stack : 	2
	
Menu	
1.Push	
2.Pop	
3.Display	
4.Exit
Enter your choice : 2

......POP......

Item to be popped : 2 
	
Menu	
1.Push	
2.Pop	
3.Display	
4.Exit
Enter your choice : 2

......POP......

Stack empty
	
Menu	
1.Push	
2.Pop	
3.Display	
4.Exit
Enter your choice : 4

You have exited successfully

*/

