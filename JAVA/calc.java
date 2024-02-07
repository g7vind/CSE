import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class calc implements ActionListener
{
	JFrame f;
	JTextField j;
	JButton b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,badd,bsub,bmul,bdiv,bclr,bdt,beq;
	
	int op;
	double a,b,r;
	calc()
	{
		f=new JFrame("CALCULATOR");
		j=new JTextField();
		f.add(j);
		f.setSize(400,400);
		f.setLayout(new GridLayout(7,7,10,10));
		
		
		b0=new JButton("0");
		b1=new JButton("1");
		b2=new JButton("2");
		b3=new JButton("3");
		b4=new JButton("4");
		b5=new JButton("5");
		b6=new JButton("6");
		b7=new JButton("7");
		b8=new JButton("8");
		b9=new JButton("9");
		badd=new JButton("+");
		bsub=new JButton("-");
		bdiv=new JButton("/");
		bmul=new JButton("*");
		bclr=new JButton("CLEAR");
		bdt=new JButton(".");
		beq=new JButton("=");
		
		
		f.add(b0);
		f.add(b1);
		f.add(b2);
		f.add(b3);
		f.add(b4);
		f.add(b5);
		f.add(b6);
		f.add(b7);
		f.add(b8);
		f.add(b9);
		f.add(badd);
		f.add(bsub);
		f.add(bmul);
		f.add(bdiv);
		f.add(bclr);
		f.add(bdt);
		f.add(beq);
		
		b0.addActionListener(this);
		b1.addActionListener(this);
		b2.addActionListener(this);
		b3.addActionListener(this);
		b4.addActionListener(this);
		b5.addActionListener(this);
		b6.addActionListener(this);
		b7.addActionListener(this);
		b8.addActionListener(this);
		b9.addActionListener(this);
		badd.addActionListener(this);
		bsub.addActionListener(this);
		bmul.addActionListener(this);
		bdiv.addActionListener(this);
		bclr.addActionListener(this);
		bdt.addActionListener(this);
		beq.addActionListener(this);
		
		f.setVisible(true);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
	}
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==b0)
			j.setText(j.getText().concat("0"));
		else if(e.getSource()==b1)
			j.setText(j.getText().concat("1"));
		else if(e.getSource()==b2)
			j.setText(j.getText().concat("2"));
		else if(e.getSource()==b3)
			j.setText(j.getText().concat("3"));
		else if(e.getSource()==b4)
			j.setText(j.getText().concat("4"));
		else if(e.getSource()==b5)
			j.setText(j.getText().concat("5"));
		else if(e.getSource()==b6)
			j.setText(j.getText().concat("6"));
		else if(e.getSource()==b7)
			j.setText(j.getText().concat("7"));
		else if(e.getSource()==b8)
			j.setText(j.getText().concat("8"));
		else if(e.getSource()==b9)
			j.setText(j.getText().concat("9"));
		else if(e.getSource()==badd)
		{
			a=Double.parseDouble(j.getText());
			op=1;
			j.setText(" ");
			
		}
		else if(e.getSource()==bsub)
		{
			a=Double.parseDouble(j.getText());
			op=2;
			j.setText(" ");
			
		}
		else if(e.getSource()==bmul)
		{
			a=Double.parseDouble(j.getText());
			op=3;
			j.setText(" ");
			
		}
		else if(e.getSource()==bdiv)
		{
			a=Double.parseDouble(j.getText());
			op=4;
			j.setText(" ");
			
		}
		else if(e.getSource()==bclr)
		{
			
			j.setText(" ");
			
		}
		else if(e.getSource()==bdt)
		{
			
			j.setText(j.getText().concat("."));
			
		}
		else if(e.getSource()==beq)
		{
			
			b=Double.parseDouble(j.getText());
			try
			{
			
			switch(op)
			{
				case 1:
					r=a+b;
					break;
				case 2:
					r=a-b;
					break;
				case 3:
					r=a*b;
					break;
				case 4:
					r=a/b;
					break;
				
					
					
					
			}
			j.setText(""+r);
			}
			catch(Exception e1)
			{
				System.out.println(e1);
			}
		}
	}



	public static void main(String args[])
	{
		calc c1=new calc();
		
	}
}

