#include<stdio.h>
#include<stdlib.h>
/* Creating a structure node with data, rchild and lchild as its members. */
struct node
{
	int data;
	struct node *rchild,*lchild;
}*root=NULL;
int item1;
/**
 * The function takes an item as input and inserts it into the BST
 */
void insert()
{	
	int item;
	printf("\nEnter the item to insert : ");
	scanf("%d",&item);
	struct node *x,*ptr,*par;
	x=(struct node*)malloc(sizeof(struct node));
	x->data=item;
	x->lchild=NULL;
	x->rchild=NULL;
	if(root==NULL)
	{
		root=x;
	}
	else
	{
		ptr=root;
		while(ptr!=NULL)
		{
		
			if(item<ptr->data)
			{
				par=ptr;
				ptr=ptr->lchild;
			}
			else
			{
				par=ptr;
				ptr=ptr->rchild;
			}
		}
		if(item < par->data)
		{
			par->lchild=x;
		}
		else if(item > par->data)
		{	
			par->rchild=x;
		}
	}
}
/**
 * If the right subtree of the node is not empty, then the successor is the leftmost node in the right
 * subtree
 * 
 * @param x The node whose inorder successor is to be found.
 * 
 * @return The inorder successor of the node x.
 */
struct node* inorder_succ(struct node *x)
{
	struct node *p;
	p=x->rchild;
	if(p!=NULL)
	{
		while(p->lchild!=NULL)
		{
			p=p->lchild;
		}
	}
	return p;
}
/**
 * The function takes an item as input and deletes it from the tree
 * 
 * @param item The item to be deleted.
 */
void delete(int item)
{
	struct node *ptr,*par,*ptr1;
	int item1;
	ptr=root;
	int flag=0;
	while(ptr!=NULL && flag==0)
	{
		if(item==ptr->data)
		{
			flag=1;
		}
		else if(item<ptr->data)
		{
			par=ptr;
			ptr=ptr->lchild;
		}
		else 
		{
			par=ptr;
			ptr=ptr->rchild;
		}
	}
	if(flag==0)
	{
		printf("\nElement does not exit in the tree ");
		exit(0);
	}
	if(ptr->lchild==NULL && ptr->rchild==NULL)
	{
		if(par->rchild==ptr)
		{
			par->rchild=NULL;
		}
		else
		{
			par->lchild=NULL;
		}
		free(ptr);
	}
	else
		{ 
			if(ptr->lchild!=NULL && ptr->rchild!=NULL)
			{
				ptr1=inorder_succ(ptr);
				item1=ptr1->data;
				delete(item1);
				ptr->data=item1;
			}
			else
			{
				if(par->rchild==ptr)
				{
					if(ptr->lchild==NULL)
					{
						par->rchild=ptr->rchild;
					}
					else 
					{
						par->rchild=ptr->lchild;
					}
				}
				else if(par->lchild==ptr)
				{
					if(ptr->lchild==NULL)
					{
						par->lchild=ptr->rchild;
					}
					else 
					{
						par->lchild=ptr->lchild;
					}
				}
				free(ptr);
			}
		}
}
/**
 * The function search() searches for a given element in the binary search tree
 * 
 * @param x The element to be searched.
 */
void search(int x)
{
	struct node *ptr=root;
	int f=0;
	while(ptr!=NULL && f==0)
	{
		if(x==ptr->data)
		{
			f=1;
		}
		else if(x<ptr->data)
		{
			ptr=ptr->lchild;
		}
		else
		{
			ptr=ptr->rchild;
		}
	}
	if(f==1)
	{
		printf("\nElement is found");
	}
	else
	{
		printf("\nElement is not found");
	}
}
/**
 * If the current node is not NULL, then recursively call the inorder_display function for the left
 * child, print the data of the current node, and recursively call the inorder_display function for the
 * right child
 * 
 * @param ptr The pointer to the node to be displayed.
 */
void inorder_display(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder_display(ptr->lchild);
		printf("\t%d",ptr->data);
		inorder_display(ptr->rchild);
	}
}
/**
 * If the current node is not NULL, then print the data part of the node, then do a preorder traversal
 * of the left subtree, followed by a preorder traversal of the right subtree
 * 
 * @param ptr The pointer to the node that we want to display.
 */
void preorder_display(struct node *ptr)
{
	if(ptr!=NULL)
	{
		printf("\t%d",ptr->data);
		preorder_display(ptr->lchild);
		preorder_display(ptr->rchild);
	}
}
/**
 * If the current node is not NULL, then recursively call the postorder_display() function for the left
 * child and right child of the current node, and then display the data of the current node
 * 
 * @param ptr The pointer to the node to be displayed.
 */
void postorder_display(struct node *ptr)
{
	if(ptr!=NULL)
	{
		postorder_display(ptr->lchild);
		postorder_display(ptr->rchild);
		printf("\t%d",ptr->data);
	}
}
/**
 * The above function is a menu driven program which performs the following operations on a binary
 * search tree:
 * 1. Insertion
 * 2. Deletion
 * 3. Search
 * 4. Preorder display
 * 5. Inorder display
 * 6. Postorder display
 * 7. Exit
 */
void main()
{
	int ch,a;
	do
	{
		printf("\nMenu");
		printf("\n1.Insert");
		printf("\n2.Delete");
		printf("\n3.Search");
		printf("\n4.preorder_Display");
		printf("\n5.Inorder_Display");
		printf("\n6.postorder_Display");
		printf("\n7.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("\nInsertion");
			insert();
		}
		else if(ch==2)
		{

			printf("\nDeletion");
			printf("\nEnter the element to delete : ");
			scanf("%d",&a);
			delete(a);
		}
		else if(ch==3)
		{
			printf("\nSearch");
			printf("\nEnter the element to searchs : ");
			scanf("%d",&a);
			search(a);
		}
		else if(ch==4)
		{
			printf("\npreorder display");
			printf("\nThe elements is/are : ");
			preorder_display(root);
			printf("\n");
		}
		else if(ch==5)
		{
			printf("\nInorder display");
			printf("\nThe elements is/are : ");
			inorder_display(root);
			printf("\n");
		}
		else if(ch==6)
		{
			printf("\npostorder display");
			printf("\nThe elements is/are : ");
			postorder_display(root);
			printf("\n");
		}
		else if(ch==7)
		{
			printf("\nExited successfully");
			exit(0);
		}
		else
		{
			printf("\nInvalid input Exited successfully");
			exit(0);
		}
	}while(1);
}
