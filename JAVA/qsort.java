/* Write a java progtram that implements quick sort algorithm for sorting a list of names in ascending order. */

class A
{	
	String s[];
	A(String s[])
	{
		this.s=s;
	}
	void quick_sort(int f,int l)
		{
			int i,j;
			String pivot,temp;
			if(f<l)
			{
				pivot=s[f];
				i=f;
				j=l;
				while(i<j)
				{
					while(s[i].compareTo(pivot)<=0 && i<l)
					{
						i++;
					}
					while(s[i].compareTo(pivot)>=0 && j>f)
					{
						j--;
					}
					if(i<j)
					{
						temp=s[i];
						s[i]=s[j];
						s[j]=temp;
					}
				}
				temp=s[j];
				s[j]=s[f];
				s[f]=temp;
				quick_sort(f,j-1);
				quick_sort(j+1,l);
			}
		}
		void display()
		{
			int i;
			System.out.println("The array after sorting  : ");
			for(i=0;i<s.length;i++)
			{
				System.out.println(s[i]);
			}	
		}
}
class quick
{
	public static void main(String[] args)
	{
		String a[]={"suii","ali","clan"};
		int i;
		System.out.println("The array elements : ");
		for(i=0;i<a.length;i++)
		{
			System.out.println(a[i]);
		}
		A z=new A(a);
		z.quick_sort(0,a.length-1);
		z.display();
		
	}	
}

