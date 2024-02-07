/* Transpose */

import java.util.Scanner;

class transpose
{
	public static void main(String args[])
	{
		int i,j;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the number of rows:");
		int row=sc.nextInt();
		System.out.println("Enter the number of columns:");
		int col=sc.nextInt();
		int a[][]=new int[row][col];
		int t[][]=new int[col][row];
		System.out.println("Enter the elements:");
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				int n=sc.nextInt();
				a[i][j]=n;
			}
		}
		System.out.println("The matrix is:-");
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				t[j][i]=a[i][j];
				System.out.print(a[i][j]+"\t");
			}
			System.out.println();
		}
		System.out.println("The transpose matrix is:-");
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				System.out.print(t[i][j]+"\t");
			}
			System.out.println(); 
		}
	}
}

/*

OUTPUT

Enter the number of rows:
3
Enter the number of columns:
3
Enter the elements:
1
2
3
4
5
6
7
8
9
The matrix is:-
1	2	3	
4	5	6	
7	8	9	
The transpose matrix is:-
1	4	7	
2	5	8	
3	6	9

*/