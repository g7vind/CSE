/* menu driven for matrix add,sub,mul */
import java.util.Scanner;
class menu
{
	public static void main(String args[])
	{
		int a[][],b[][],c[][],i,j,n;
		System.out.println("MENU\n");
		System.out.println("1. Matrix Add");
		System.out.println("2. Matrix Sub");
		System.out.println("3. Matrix Mul\n");
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter your choice:");
		int ch=sc.nextInt();
		System.out.println("\nMATRIX A\n");
		System.out.println("Enter the number of rows:");
		int r1=sc.nextInt();
		System.out.println("Enter the number of cols:");
		int c1=sc.nextInt();
		a=new int[r1][c1];
		System.out.println("Enter the elements:-");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				n=sc.nextInt();
				a[i][j]=n;
			}
		}
		System.out.println("The matrix A is:-");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				System.out.print(a[i][j]+"\t");
			}
			System.out.println();
		}
		System.out.println("\nMATRIX B\n");
		System.out.println("Enter the number of rows:");
		int r2=sc.nextInt();
		System.out.println("Enter the number of cols:");
		int c2=sc.nextInt();
		b=new int[r2][c2];
		System.out.println("Enter the elements:-");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				n=sc.nextInt();
				b[i][j]=n;
			}
		}
		System.out.println("The matrix B is:-");
		for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{
				System.out.print(b[i][j]+"\t");
			}
			System.out.println();
		}
		
		if(ch==1)
		{
			if(r1==r2 & c1==c2)
			{
				c=new int[r1][c1];
				for(i=0;i<r1;i++)
				{
					for(j=0;j<c1;j++)
					{
						c[i][j]=a[i][j]+b[i][j];
					}
				}
				System.out.println("\nThe matrix after addition is:-");
				for(i=0;i<r1;i++)
				{
					for(j=0;j<c1;j++)
					{
						System.out.print(c[i][j]+"\t");
					}
					System.out.println();
				}
			}
			else
			{
				System.out.println("\nAddition not possible.");
			}
		}
		else if(ch==2)
		{
			if(r1==r2 & c1==c2)
			{
				c=new int[r1][c1];
				for(i=0;i<r1;i++)
				{
					for(j=0;j<c1;j++)
					{
						c[i][j]=a[i][j]-b[i][j];
					}
				}
				System.out.println("\nThe matrix after subtraction is:-");
				for(i=0;i<r1;i++)
				{
					for(j=0;j<c1;j++)
					{
						System.out.print(c[i][j]+"\t");
					}
					System.out.println();
				}
			}
			else
			{
				System.out.println("\nSubtraction not possible.");
			}
		}
		else if(ch==3)
		{
			int k;
			if(c1==r2)
			{
				c=new int[c1][r2];
				for(i=0;i<r1;i++)
				{
					for(j=0;j<c2;j++)
					{
						c[i][j]=0;
						for(k=0;k<r2;k++)
						{
							c[i][j]=c[i][j]+a[i][k]*b[k][j];
						}
					}
				}
				System.out.println("\nThe matrix after multiplication is:-");
				for(i=0;i<r1;i++)
				{
					for(j=0;j<c1;j++)
					{
						System.out.print(c[i][j]+"\t");
					}
					System.out.println();
				}
			}
			else
			{
				System.out.println("\nMultiplication not possible.");
			}
		}
	}
}

/*

OUTPUT

MENU

1. Matrix Add
2. Matrix Sub
3. Matrix Mul

Enter your choice:3

MATRIX A

Enter the number of rows:
2
Enter the number of cols:
2
Enter the elements:-
1
2
3
4
The matrix A is:-
1	2	
3	4	

MATRIX B

Enter the number of rows:
2
Enter the number of cols:
2
Enter the elements:-
1
2
3
4
The matrix B is:-
1	2	
3	4	

The matrix after multiplication is:-
7	10	
15	22	

*/
