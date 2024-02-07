//write a java program that implements binary search algorithm
import java.util.*;
class srch
{
	int mid;
	int search(int a[],int l,int h,int k)
	{
		mid = (l+h)/2;
		if(a[mid]==k)
		{
			return 1;
		}
		else if(l>=h)
		{
			return -1;
		}
		else if(a[mid]<k)
		{
			return search(a,l,mid-1,k);
		}
		else
		{
			return search(a,mid+1,h,k);
		}
	}
}
class binsrch
{
	public static void main(String args[])
	{
		int a[],n,i,s;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the size of array:");
		n = sc.nextInt();
		a = new int[n];
		System.out.println("Enter the elements:-");
		for(i=0;i<n;i++)
		{
			a[i] = sc.nextInt();
		}
		System.out.println("Enter the element to search for:");
		s = sc.nextInt();
		int low=0,high=n-1;
		srch s1 = new srch();
		int r = s1.search(a,low,high,s);
		if(r==1)
		{
			System.out.println("Element is present in the array.");
		}
		else if(r==-1)
		{
			System.out.println("Element is absent in the array.");
		}
	}
}

/*
OUTPUT

Enter the size of array:
5
Enter the elements:-
1
3
5
7
9
Enter the element to search for:
5
Element is present in the array.

*/