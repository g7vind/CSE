/* To check whether prime or not */
import java.util.Scanner;

class Prime
{
	public static void main(String args[])
	{
		int i,f=1;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the number to check:");
		int a=sc.nextInt();
		for(i=2;i<=a/2;i++)
		{
			if(a%i==0)
			{
				f=0;
				break;
			}
			else
			{
				f=1;
			}
		}
		if(f==1)
		{
			System.out.println("The number is prime.");
		}
		else
		{
			System.out.println("The number is not prime.");
		}
	}
}

/*

OUTPUT

Enter the number to check:
4
The number is not prime.

*/
