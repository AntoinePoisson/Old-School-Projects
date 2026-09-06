import java.awt.*;
import java.awt.font.*;
import java.awt.event.*;
import java.util.*;
import java.awt.geom.*;
import javax.swing.*;
import java.util.Scanner;

public class Example
{
   public static void main(String[] args)
   {
	  EventQueue.invokeLater(new Runnable()
		 {
			public void run()
			{
			   DrawFrame frame = new DrawFrame();
			   frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			   frame.setVisible(true);
			}
		 });
   }
}

/**
 * A frame that contains a panel with drawings
 */
class DrawFrame extends JFrame
{
   public DrawFrame()
   {
	  setTitle("Canvas Button Test");
	  setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);

		 MyButton button = new MyButton();
	  add(button);
   }

   public static final int DEFAULT_WIDTH = 400;
   public static final int DEFAULT_HEIGHT = 400;
}

/**
 * A panel that displays the button
 */
class MyButton extends JPanel
{
		int xAPoints[] = {150, 225, 150};
		int yAPoints[] = {150, 150, 225};
		int xBPoints[] = {225, 150, 225};
		int yBPoints[] = {225, 225, 150};
		Graphics2D triA;
		Graphics2D triB;

		public MyButton()
		{
			addMouseListener (new MyMouseListener(this));
		}

		public void paintComponent(Graphics g)
		{
			Graphics2D g2 = (Graphics2D) g;
			g2.setBackground(Color.WHITE);

		  // draw outer rectangle
		  double leftX = 150;
		  double topY = 150;
		  double width = 75;
		  double height = 75;
		  Rectangle2D rect = new Rectangle2D.Double(leftX, topY, width, height);
		  g2.draw(rect);

			// draw top triangle
			Graphics2D triangleA = (Graphics2D) g;
			triangleA.drawPolygon(xAPoints, yAPoints, 3);
			triangleA.setPaint(Color.WHITE);
			triangleA.fillPolygon(xAPoints, yAPoints, 3);

			// draw bottom triangle
			Graphics2D triangleB = (Graphics2D) g;
			triangleB.drawPolygon(xBPoints, yBPoints, 3);
			triangleB.setPaint(Color.LIGHT_GRAY);
			triangleB.fillPolygon(xBPoints, yBPoints, 3);

			// draw an enclosed rectangle 
			double bLeftX = 160;
			double bTopY = 160;
			double bWidth = 55;
			double bHeight = 55;
			Rectangle2D bRect = new Rectangle2D.Double(bLeftX, bTopY, bWidth, bHeight);
			g2.draw(bRect);
			g2.setPaint(Color.WHITE);
			g2.fill(bRect);

			// redraw the triangles and enclosing rectangle to get borders
			g2.setPaint(Color.BLACK);
			triangleA.drawPolygon(xAPoints, yAPoints, 3);
			triangleB.drawPolygon(xBPoints, yBPoints, 3);
			g2.draw(bRect);
			g2.setPaint(Color.WHITE);
			g2.fill(bRect);
			g2.setPaint(Color.BLACK);
			g2.draw(bRect);

		// color the triangles when button is pressed
		public void setDownColor(Graphics g)
		{
			Graphics2D g2 = (Graphics2D) g;
			g2.setBackground(Color.WHITE);

			// draw outer rectangle
			double leftX = 150;
			double topY = 150;
			double width = 75;
			double height = 75;
			Rectangle2D rect = new Rectangle2D.Double(leftX, topY, width, height);
			g2.draw(rect);

			// draw top triangle
			Graphics2D triangleA = (Graphics2D) g;
			triangleA.drawPolygon(xAPoints, yAPoints, 3);
			triangleA.setPaint(Color.LIGHT_GRAY);
			triangleA.fillPolygon(xAPoints, yAPoints, 3);

			// draw bottom triangle
			Graphics2D triangleB = (Graphics2D) g;
			triangleB.drawPolygon(xBPoints, yBPoints, 3);
			triangleB.setPaint(Color.WHITE);
			triangleB.fillPolygon(xBPoints, yBPoints, 3);

			// draw an enclosed rectangle 
			double bLeftX = 160;
			double bTopY = 160;
			double bWidth = 55;
			double bHeight = 55;
			Rectangle2D bRect = new Rectangle2D.Double(bLeftX, bTopY, bWidth, bHeight);
			g2.draw(bRect);
		  g2.setPaint(Color.WHITE);
			g2.fill(bRect);

			// redraw the triangles and enclosing rectangle to get borders
			g2.setPaint(Color.BLACK);
			triangleA.drawPolygon(xAPoints, yAPoints, 3);
			triangleB.drawPolygon(xBPoints, yBPoints, 3);
			g2.draw(bRect);
			g2.setPaint(Color.WHITE);
			g2.fill(bRect);
			g2.setPaint(Color.BLACK);
			g2.draw(bRect);
		}
}

class MyMouseListener implements MouseListener
{
		MyButton button;
		public MyMouseListener(MyButton b)
		{
			button = b;
		}

		public void mouseExited(MouseEvent e)
		{
		}

		public void mouseEntered(MouseEvent e)
		{
		}

		public void mouseReleased(MouseEvent e)
		{
			// notify listeners of mouseclick
			if (e.getClickCount() == 1)
			{
				button.paintComponent(button.getGraphics());
			}
		}

		public void mouseClicked(MouseEvent e)
		{
			// notify listeners of mouseclick
			if (e.getClickCount() >= 2) 
			{
				System.out.println("This is the result of a mouse double-click!");
			}
		}

		public void mousePressed(MouseEvent e)
		{
			// notify listeners of mouseclick
			if (e.getClickCount() == 1) 
			{
				System.out.println("This is the result of a mouse single-click!");
				button.setDownColor(button.getGraphics());
			}
		}


}

