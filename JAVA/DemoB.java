
import java.lang.Math;
class Shape
{
	double ar(int r)
	{
		return 3.14*r*r;
	}
	double ar(int l,int b)
	{
		return l*b;
	}
	double ar(int a,int b,int c)
	{
		double s=(a+b+c)/2;
		return Math.sqrt(s*(s-a)*(s-b)*(s-c));
	}
}

class DemoB
{
	public static void main(String args[])
	{
		Shape b1=new Shape();
		System.out.println("The area of circle is "+(b1.ar(1)));
		System.out.println("The area of rectangle is "+(b1.ar(3,4)));
		System.out.println("The area of traingle is "+(b1.ar(3,4,5)));
	} 
}
