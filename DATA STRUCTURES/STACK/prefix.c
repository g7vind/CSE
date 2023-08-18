#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
char stack[100];
int top = -1;
int stack1[100];
int top1=-1;
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
int check(char value)
{
    if (value == '+' || value == '-' || value == '*' || value == '/' || value == '^' || value == ')')
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

int ISP(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x=='^')
        return 4;
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
        return 3;
    return 0;
}
void main()
{
    int i=0,j=0,y,op,z,r,t;
    char infix[50],prefix[50],item,x,k[50];
    printf("Enter the expression in infix : ");
    scanf("%s",k);
    for(i=strlen(k)-1,r=0;i>=0;i--)
    {
    	infix[r]=k[i];
    	r++;
    }
    infix[r]='(';
    push(')');
    i=0;
    while(top!=-1)
    {
        item=infix[i];
        i++;
        if(isalpha(item))
        {
            prefix[j]=item;
            j++;
        }
        else if(item=='(')
        {
            x=pop();
            while(x!=')')
            {
                prefix[j]=x;
                j++;
                x=pop();
            }
        }
        else if(check(item)==1)
        {
            x=pop();
            if(ISP(x)>ICP(item))
            {
                while(ISP(x)>ICP(item))
                {
                    prefix[j]=x;
                    j++;
                    x=pop();
                }
                push(x);
                push(item);
            }
            else if(ISP(x)<=ICP(item))
            {
                push(x);
                push(item);
            }
        }
        else if(check(item)==0)
        {
            printf("\nAn error encountered while evaluating the expression\n");
            exit(0);
        }
    }
    printf("\nThe prefix :");
    prefix[j]='\0';
    for(i=strlen(prefix)-1;prefix[i]!='\0';i--)
    {
        printf("%c",prefix[i]);
    }
    printf("\n");
    i=0;
    item=prefix[i];
    while(item!='\0')
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
                case '+':t=y+z;
                        break;
                case '-':t=y-z;
                        break;
                case '*':t=y*z;
                        break;
                case '/':t=y/z;
                        break;
                case '^':t=pow(y,z);
                        break;
            }
            push1(t);
        }
        i++;
        item=prefix[i];
    }
    printf("\nThe value : ");
    printf("%d",stack1[top1]);
    printf("\n");

}
/*
output
Enter the expression in infix : a+b*c

The prefix :+a*bc

Enter the value for c : 6

Enter the value for b : 4

Enter the value for a : 2

The value : 26
*/
