// Complex Number

class Com
{
	int r,i;
	Com(int a,int b)
	{
		r=a;
		i=b;
	}
	void sum(Com o)
	{
		r=r+o.r;
		i=i+o.i;
		System.out.println("The resultant complex number is: "+r+"+i"+i);
	}
}
class Complex
{
	public static void main(String args[])
	{
		Com a1=new Com(2,3);
		Com a2=new Com(3,5);
		a1.sum(a2);
	}
}
