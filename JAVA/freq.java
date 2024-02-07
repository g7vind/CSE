//Frequency of character in a string

import java.util.*;

class freq
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter the string: ");
		String s1=sc.nextLine();
		System.out.println("The string is: "+s1);
		System.out.print("Enter the character to check: ");
		char c=sc.next().charAt(0);
		int count=0;
		for(int i=0;i<s1.length();i++)
		{
			if(s1.charAt(i)==c)
			{
				count++;
			}
		}
		if(count>0)
		{
			System.out.println("The frequency of the characte '"+c+"' in the string is: "+count);
		}
		else
		{
			System.out.println("The string has no character '"+c+"'");
		}
	}
}

/*
OUTPUT

Enter the string: malayalam
The string is: malayalam
Enter the character to check: a
The frequency of the character 'a' in the string is: 4

*/