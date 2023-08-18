#include<stdio.h>
#include<stdlib.h>
struct node
{
	int vertex;
	struct node *link;
}*gptr[10],*ptr;
int i, top = -1, stack[10], visit[10],n,front=0,rear=0,q[20],VISIT[20],c=0;
void push(int a)
{
	stack[++top] = a;
}
int pop()
{
	return stack[top--];
}
int search(int* a, int b)
{
	int flag = 0,j;
	for(int j =0; j<=n; j++)
	{
		if(a[j] == b)
		{
			flag = 1;
			break;
		}
	}
	if(flag == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void enqueue(int a)
{
	if(front==0 && rear==0)
	{
		q[++rear]=a;
		front=front+1;
	}
	else
	{
		q[++rear]=a;
	}				
}
int dequeue()
{ 	
	int item;
	if(front==rear)
	{
		item=q[front];
		front=0;
		rear=0;
	}
	else
	{
		item=q[front++];
	}
	return item;
}	
void dfs(int v)
{
    int u,j;
    struct node* ptr;
	u=v;
	i=0; 
	push(u);
	while(top != -1)
	{
		u=pop();
		if(search(visit,u) == 0)
		{
			visit[i] = u;
			i++;
			ptr = gptr[u];
			while(ptr != NULL)
			{
				push(ptr->vertex);
				ptr = ptr->link;
			}
		}
	}
	printf("\n Graph in DFS : ");
	for(j=0;j<=n-1;j++)
	{
		printf("  %d", visit[j]);
	}
}
void bfs(int v)
{
	int u,k;
	u=v;
	enqueue(u);
	while(front!=0 && rear!=0)
	{
		u=dequeue();
		if(search(VISIT,u)==0)
		{
			VISIT[c]=u;
			c++;
			ptr=gptr[u];
			while(ptr!=NULL)
			{
				enqueue(ptr->vertex);
				ptr=ptr->link;
			}
		}
	}
    printf("\n Graph in BFS : ");
	for(k=0;k<n;k++)
	{
		printf("%d ",VISIT[k]);
	}
}
int main()
{
	int v,c,k,item,l,w,ch;
	struct node *temp;
	printf("\nEnter no of vertices : ");
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
		gptr[i]=NULL;
    }
	printf("\nEnter starting vertex : ");
	for(l=1; l<=n;l++)
	{
		scanf("%d", &v);
		printf("\nEnter no. of connections for vertex %d : ", v);
		scanf("%d", &c); 
		for(k=1;k<=c;k++)
		{
			printf("Enter vertex of connection %d  : ", k);
			scanf("%d", &item);
	        struct node *p = (struct node*)malloc(sizeof(struct node));
			if(k==1)
			{
				p->vertex = item;
				gptr[v] = p;
				p->link = NULL;
			}
			else
			{
				p->vertex = item;
				temp = gptr[v];
				while(temp->link != NULL)
				{
					temp = temp->link;
                }
				temp->link = p;
				p->link = NULL;
			}
		}
		if(l != n)
		{
			printf("\nEnter next vertex : ");
		} 
	}
    do
    {
        printf("\nTraversal options\n1.DFS\n2.BFS\n3.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: printf("\nOption selected : DFS");
                    printf("\nEnter the starting vertex to traverse : ");
                    scanf("%d",&w);
                    dfs(w);
                    printf("\n");
                    break;
            case 2: printf("\nOption selected : BFS");
                    printf("\nEnter the starting vertex to traverse : ");
                    scanf("%d",&w);
                    bfs(w);
                    printf("\n");
                    break;
            case 3: printf("\nExited Successfully");
                    exit(0);
            default:printf("\nWrong input");
                    exit(0);
        }
    } while (1);
	printf("\n");
}