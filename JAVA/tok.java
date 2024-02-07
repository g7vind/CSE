import java.util.*;
class tok
{
	public static void main(String args[])
	{
		String s = new String("1 2 3 4 5");
		int sum = 0;
		StringTokenizer st = new StringTokenizer(s);
		System.out.println("The tokens are: ");
		while(st.hasMoreTokens())
		{
			String i = new String(st.nextToken());
			System.out.print(i+"\t");
			sum+=Integer.parseInt(i);
		}
		System.out.println("\nThe sum of tokens is: "+sum);
	}
}
