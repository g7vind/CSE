import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

class abbre implements ActionListener
{
	JFrame jf;
	JTextField t1,t2;
	JButton b;
	JLabel l1,l2;
	int i,j;
	abbre()
	{
		jf=new JFrame("Abbrevations");
		jf.setSize(400,400);
		jf.setVisible(true);
		jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jf.setLayout(new FlowLayout());
		
		l1=new JLabel("String");
		jf.add(l1);
		t1=new JTextField(20);
		jf.add(t1);
		
		b=new JButton("CLICK");
		jf.add(b);
		b.addActionListener(this);
		
		l2=new JLabel("Abbrevation");
		jf.add(l2);
		t2=new JTextField(20);
		jf.add(t2);
	}
	public void actionPerformed(ActionEvent ae)
	{
		String s=t1.getText();
		String ab="";
		int x=s.length();
		ab=Character.toString(s.charAt(0));
		for(i=1;i<x;i++)
		{
			if(Character.toString(s.charAt(i)).equals(" "))
				ab=ab+Character.toString(s.charAt(i+1));
		}
		t2.setText(ab);
	}
	public static void main(String args[])
	{
		abbre ab = new abbre();
	}
}
