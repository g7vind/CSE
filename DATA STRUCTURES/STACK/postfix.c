#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
char stack[100];
int stack1[100];
int top1=-1;
int top = -1;
int check(char value)
{
    if (value == '+' || value == '-' || value == '*' || value == '/' || value == '^' || value == '(')
    {
        return 1;
    }
    else
        return 0;
}
void push(char x)
{
    stack[++top] = x;
}
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
int pop1()
{
    if(top1 == -1)
        return -1;
    else
        return stack1[top1--];
}
void push1(int x)
{
    stack1[++top1] = x;
}

int ISP(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x=='^')
        return 3;
    return 0;
}
int ICP(char x)
{
    if(x == '(')
        return 4;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x=='^')
        return 4;
    return 0;
}
void main()
{
    int i=0,j=0,t,y,z,op;
    char infix[50],postfix[50],item,x;
    printf("Enter the expression in infix : ");
    scanf("%s",infix);
    infix[strlen(infix)]=')';
    push('(');
    while(top!=-1)
    {
        item=infix[i];
        i++;
        if(isalpha(item))
        {
            postfix[j]=item;
            j++;
        }
        else if(item==')')
        {
            x=pop();
            while(x!='(')
            {
                postfix[j]=x;
                j++;
                x=pop();
            }
        }
        else if(check(item)==1)
        {
            x=pop();
            if(ISP(x)>=ICP(item))
            {
                while(ISP(x)>=ICP(item))
                {
                    postfix[j]=x;
                    j++;
                    x=pop();
                }
                push(x);
                push(item);
            }
            else if(ISP(x)<ICP(item))
            {
                push(x);
                push(item);
            }
        }
        else if(check(item)==0)
        {
            printf("\nAn error encountered please check the entered expression");
            exit(0);
        }
    }
    
    printf("The postfix form : ");
    for(i=0;i<j;i++)
    {
        printf("%c",postfix[i]);
    }
    i=0;
    item=postfix[i];
    while(i<j)
    {
        if(isalpha(item))
        {
            printf("\nEnter the value for %c : ",item);
            scanf("%d",&op);
            push1(op);
        }
        else
        {
            
            y=pop1();
            z=pop1();
            switch(item)
            {
                case '+':t=z+y;
                        break;
                case '-':t=z-y;
                        break;
                case '*':t=z*y;
                        break;
                case '/':t=z/y;
                        break;
                case '^':t=pow(z,y);
                        break;
            }
            push1(t);
        }
        i++;
        item=postfix[i];
    }
    printf("\nThe value : ");
    printf("%d",stack1[top1]);
    printf("\n");
}
/*output
Enter the expression in infix : a+b*c
The postfix form : abc*+
Enter the value for a : 2

Enter the value for b : 4

Enter the value for c : 6

The value : 26
*/
