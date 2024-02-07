/* To find second smallest element in an array */
import java.util.Scanner;
class second
{
	public static void main(String args[])
	{
		int i,j,temp;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the size of the array:");
		int l=sc.nextInt();
		int a[]=new int[l];
		System.out.println("Enter the elements:-");
		for(i=0;i<l;i++)
		{
			int n=sc.nextInt();
			a[i]=n;
		}
		System.out.println("The array is:-");
		for(i=0;i<l;i++)
		{
			System.out.println(a[i]);
		}
		for(i=0;i<l-1;i++)
		{
			for(j=0;j<l-i-1;j++)
			{
				if(a[j]>a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
		System.out.println("The second smallest element is "+a[1]);
	}
}

/*

OUTPUT

Enter the size of the array:
5
Enter the elements:-
4
2
1
6
3
The array is:-
4
2
1
6
3
The second largest element is 3

*/