import java.io.*;

class filep
{
	public static void main(String args[]) throws IOException
	{
		try
		{
			FileInputStream f1 = new FileInputStream("ff1.txt");
			FileOutputStream f2 = new FileOutputStream("f2.txt");
			int ch;
			do
			{
				ch = f1.read();
				f2.write(ch);
			}while(ch!=-1);
			f1.close();
			f2.close();
		}
		catch(FileNotFoundException e)
		{
			System.out.println(e);
		}
		catch(IOException e)
		{
			System.out.println(e);
		}
	}
}

