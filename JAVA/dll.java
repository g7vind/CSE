/* DLL */
/* Write a java program for the following create a doubly linked list of elements ,delete a given element from the above list,display the contents of the list after deletion. */
import java.util.*;

class node
{
	node next;
	node prev;
	int data;
	node(int d,node prev,node next)
	{
		data = d;
		this.next = next;
		this.prev = prev;
	}
}

class dll
{
	public static void main(String args[])
	{
		int c,item;
		node head,tail,temp;
		head = null;
		tail = null;
		Scanner sc = new Scanner(System.in);
		do
		{
			System.out.println("Menu:-");
			System.out.println("1. Insert");
			System.out.println("2. Delete");
			System.out.println("3. Display");
			System.out.println("4. Exit");
			System.out.println("\nEnter your choice:");
			c = sc.nextInt();
			System.out.println("\n");
			if(c==1)
			{
				System.out.println("Enter the element to insert:");
				item = sc.nextInt();
				node newnode = new node(item,null,head);
				if(head == null)
				{
					head = newnode;
					tail = newnode;
				}
				else
				{
					head = newnode;
				}
			}
			else if(c==2)
			{
				if(head == null)
				{
					System.out.println("Empty list");
				}
				else if(head == tail)
				{
					System.out.println("Deleted element is "+head.data);
					head = head.next;
					head = null;
					tail = null;
				}
				else
				{
					temp = head;
					head = head.next;
					head.prev = null;
					System.out.println("Deleted element is "+temp.data);	
				}
			}
			else if(c==3)
			{
				if(head == null)
				{
					System.out.println("Empty list");
				}
				else
				{
					System.out.println("The elements in the list are:-");
					temp = head;
					while(temp!=null)
					{
						System.out.println(temp.data);
						temp = temp.next;
					}
				}
			}
			else if(c==4)
			{
				System.exit(0);
			}
			else
			{
				System.out.println("Invalid choice");
			}
			System.out.println("\n");
		}while(true);
	}
}

/* output

Menu:-
1. Insert
2. Delete
3. Display
4. Exit

Enter your choice:
1


Enter the element to insert:
5


Menu:-
1. Insert
2. Delete
3. Display
4. Exit

Enter your choice:
1


Enter the element to insert:
3


Menu:-
1. Insert
2. Delete
3. Display
4. Exit

Enter your choice:
1


Enter the element to insert:
7


Menu:-
1. Insert
2. Delete
3. Display
4. Exit

Enter your choice:
3


The elements in the list are:-
7
3
5


Menu:-
1. Insert
2. Delete
3. Display
4. Exit

Enter your choice:
2


Deleted element is 7


Menu:-
1. Insert
2. Delete
3. Display
4. Exit

Enter your choice:
3


The elements in the list are:-
3
5


Menu:-
1. Insert
2. Delete
3. Display
4. Exit

Enter your choice:
4

*/
