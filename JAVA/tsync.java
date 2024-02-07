/* write a java program for the following create a doubly linked list of elements ,delete a given element from the above list,display the contents of the list after deletion. */
	
/* Write a java progtram that implements quick sort algorithm for sorting a list of names in ascending order. */

class First
{
	public void show(String msg)
	{
		System.out.println("["+msg);
		try
		{
			Thread.sleep(1000);
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		System.out.print("]\n");
	}
}
class Second extends Thread
{
	First fobj;
	String msg;
	Second(First f,String s)
	{
		msg=s;
		fobj=f;
		start();
	}
	public void run()
	{
		synchronized(fobj)
		{
			fobj.show(msg);
		}
	}
}
class tsync
{
	public static void main(String[] args)
	{
		First fnew=new First();
		Second s1=new Second(fnew,"First");
		Second s3=new Second(fnew,"Third");
		Second s2=new Second(fnew,"Second");
	}
}

