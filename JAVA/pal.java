//Palindrome

import java.util.*;

class pal
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the string: ");
		String s1=sc.nextLine();
		String s2=new String();
		int l=s1.length();
		for(int i=l-1;i>=0;i--)
		{
			s2=s2+s1.charAt(i);
		}
		System.out.println("The reverse is: "+s2);
		if(s2.equalsIgnoreCase(s1)==true)
		{
			System.out.println("The string is palindrome");
		}
		else
		{
			System.out.println("The string is not a palindrome");
		}
	}
}

/*
OUTPUT

Enter the string:
malayalam
The reverse is: malayalam
The string is palindrome

*/