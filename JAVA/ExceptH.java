import java.util.Scanner;

class Demo
{
	public static void main(String args[]) //throws Exception,ArithmeticException,ArrayIndexOutOfBoundsException
	{
		int n,a[];
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the size of array:");
		n = sc.nextInt();
		try
		{
			if(n<1)
				throw new ArrayIndexOutOfBoundsException("Size is too low");
			else
				a = new int[n];
				System.out.println("Enter the elements:-");
				for(int i=0;i<n;i++)
				{
					a[i] = sc.nextInt();
				}
		}
		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.println(e);
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		finally
		{
			System.out.println("Exit");
		}
	}
}

/*

OUTPUT

Enter the size of array:
-8
java.lang.ArrayIndexOutOfBoundsException: Size is too low
Exit
*/
