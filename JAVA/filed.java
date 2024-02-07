import java.io.*;

class filed
{
	public static void main(String args[])
	{
		try
		{
			FileReader fr = new FileReader("f1.txt");
			FileWriter fw = new FileWriter("f2.txt");
			int c;
			do
			{
				c = fr.read();
				if(c!=-1)
					fw.write(c);
			}while(c!=-1);
			fr.close();
			fw.close();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}
