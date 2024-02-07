import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class Traffic extends JFrame implements ItemListener
{	

	JFrame actualWindow;
	JPanel messageContainer, lightsContainer;
	JLabel message;
	ButtonGroup btn_group;
	JRadioButton rb_red, rb_yellow, rb_green;
	Traffic()
	 {
		
		actualWindow = new JFrame("Traffic Lights");
		messageContainer = new JPanel();
		lightsContainer = new JPanel();
		message = new JLabel("Select Light");
		btn_group = new ButtonGroup();
		rb_red = new JRadioButton("Red");
		rb_yellow = new JRadioButton("Yellow");
		rb_green = new JRadioButton("Green");
		
		actualWindow.setLayout(new GridLayout(2, 1));
		
		
		rb_red.setForeground(Color.RED);
		rb_yellow.setForeground(Color.YELLOW);
		rb_green.setForeground(Color.GREEN);
		
		btn_group.add(rb_red);
		btn_group.add(rb_yellow);
		btn_group.add(rb_green);
		
		rb_red.addItemListener(this);
		rb_yellow.addItemListener(this);
		rb_green.addItemListener(this);
		
		messageContainer.add(message);
		lightsContainer.add(rb_red);
		lightsContainer.add(rb_yellow);
		lightsContainer.add(rb_green);
		
		actualWindow.add(messageContainer);
		actualWindow.add(lightsContainer);
				
		actualWindow.setSize(300, 200);
		actualWindow.setVisible(true);
	}

	public void itemStateChanged(ItemEvent ie)
	 {
		JRadioButton selected = (JRadioButton) ie.getSource();
		String textOnButton = selected.getText();
		if(textOnButton.equals("Red"))
		 {
			message.setForeground(Color.RED);
			message.setText("STOP");
		} 
		else if(textOnButton.equals("Yellow")) 
		{
			message.setForeground(Color.YELLOW);
			message.setText("READY");
		} 
		else 
		{
			message.setForeground(Color.GREEN);
			message.setText("GO");
		}
	}
}
public class traffic
 {

	public static void main(String[] args)
	{
		Traffic t = new Traffic();
	}

}
