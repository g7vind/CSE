import java.util.*;

class A extends Thread
{
	int a;
	public void run()
	{
		for(int i=0;i<100;i++)
		{
			Random r = new Random();
			a = r.nextInt(100);
			System.out.println("The random number: "+a);
			if(a%2==0)
			{
				B t2 = new B(a);
				t2.start();
			}
			else
			{
				C t3 = new C(a);
				t3.start();
			}
			try
			{
				Thread.sleep(1000);
			}
			catch(Exception e){}
		}
	}
}

class B extends Thread
{
	int a;
	B(int x)
	{
		a = x;
	}
	public void run()
	{
		System.out.println("The random number is even.");
		System.out.println(a*a);
	}
}

class C extends Thread
{
	int a;
	C(int x)
	{
		a = x;
	}
	public void run()
	{
		System.out.println("The random number is odd.");
		System.out.println(a*a*a);
	}
}

class tdemo
{
	public static void main(String args[])
	{
		A t1 = new A();
		t1.start();
	}
}

/*

OUTPUT

The random number: 31
The random number is odd.
29791
The random number: 43
The random number is odd.
79507
The random number: 3
The random number is odd.
27
The random number: 71
The random number is odd.
357911
The random number: 58
The random number is even.
3364
The random number: 85
The random number is odd.
614125
The random number: 26
The random number is even.
676
The random number: 21
The random number is odd.
9261
The random number: 84
The random number is even.
7056
The random number: 70
The random number is even.
4900

*/
