import java.awt.EventQueue;
import java.awt.Graphics;
import java.awt.Graphics2D;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.*;
import java.awt.font.*;
import java.awt.event.*;
import java.util.*;
import java.awt.geom.*;
import javax.swing.*;
import java.util.Scanner;
import java.io.*;
import java.util.*;
import java.lang.Math;

class myMouseListener extends MouseAdapter {


    public boolean checkClick(Integer x1, Integer _x, Integer _width, Integer y1, Integer _y, Integer _height) {
        return x1 > _x && x1 < (_x + _width) && y1 - 30 > _y && y1 - 30 < (_y + _height);
    }

    public Integer checkWin(Integer player, Integer ia) {
        switch (player) {
            case 0:
                if (ia == 0) {
                    Main.isChoosing = true;
                    return (-1);
                } else if (ia == 1)
                    return (0);
                else
                    return (1);
            case 1:
                if (ia == 0)
                    return (1);
                else if (ia == 1) {
                    Main.isChoosing = true;
                    return (-1);
                } else
                    return (0);
            case 2:
                if (ia == 0)
                    return (0);
                else if (ia == 1)
                    return (1);
                else {
                    Main.isChoosing = true;
                    return (-1);
                }
        }
        return 1;
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        int x1 = e.getX();
        int y1 = e.getY();

        if (Main.isChoosing) {
            if (checkClick(x1, 50, 170, y1, 120, 200)) {
                Main.isChoosing = false;
                Main.playerChoose = 0;
                Main.iaChoose = ((int)(Math.random() * 3));
                Main.stateGame = checkWin(Main.playerChoose, Main.iaChoose);
            }
            if (checkClick(x1, 250, 170, y1, 122, 200)) {
                Main.isChoosing = false;
                Main.playerChoose = 1;
                Main.iaChoose = ((int)(Math.random() * 3));
                Main.stateGame = checkWin(Main.playerChoose, Main.iaChoose);
            }
            if (checkClick(x1, 475, 170, y1, 120, 200)) {
                Main.isChoosing = false;
                Main.playerChoose = 2;
                Main.iaChoose = ((int)(Math.random() * 3));
                Main.stateGame = checkWin(Main.playerChoose, Main.iaChoose);
            }
        } else {
            if (checkClick(x1, 150, 117, y1, 370, 30)) {
                Main.isChoosing = true;
                Main.playerChoose = 0;
                Main.iaChoose = 0;
                Main.stateGame = -1;
            }
            if (checkClick(x1, 420, 117, y1, 370, 30)) {
                System.exit(0);
            }
        }
    //     if (Main.solution.equals(Main.display_word)) {
    //         System.out.println("YOU WIN !");
    //         System.exit(0);
    //     }
    }
}

class Surface extends JPanel {

    private void doDrawing(Graphics g) {

        Graphics2D g2d = (Graphics2D) g;
        if (Main.isChoosing) {
            g2d.setPaint(Color.BLACK);
            g2d.drawString("CHOOSE ... :", 310 , 40);

            g2d.drawImage(new ImageIcon(Main.listImages.get(0)).getImage(), 50, 120, null);
            g2d.drawImage(new ImageIcon(Main.listImages.get(1)).getImage(), 250, 122, null);
            g2d.drawImage(new ImageIcon(Main.listImages.get(2)).getImage(), 475, 120, null);
        } else {
            if (Main.stateGame == 1) {
                g2d.drawImage(new ImageIcon("resources/win.png").getImage(), 110, 40, null);
            } else if (Main.stateGame == 0) {
                g2d.drawImage(new ImageIcon("resources/lose.png").getImage(), 110, 40, null);
            }
            g2d.setPaint(Color.BLACK);
            g2d.drawString("Your :", 100 , 120);
            g2d.drawImage(new ImageIcon(Main.listImages.get(Main.playerChoose)).getImage(), 50, 140, null);


            g2d.setPaint(Color.BLACK);
            g2d.drawString("IA :", 550 , 120);
            g2d.drawImage(new ImageIcon(Main.listImages.get(Main.iaChoose)).getImage(), 475, 140, null);

            g2d.drawImage(new ImageIcon("resources/playAgain.png").getImage(), 150, 370, null);
            g2d.drawImage(new ImageIcon("resources/leave.png").getImage(), 420, 370, null);
        }
        // g2d.setPaint(Color.WHITE);
        // g2d.drawString(displayHiddenWord(), 350 - (5 * Main.display_word.length()), 245);

        // g2d.drawImage(new ImageIcon(Main.listImages.get(Main.wrongAnswer)).getImage(), 280, 20, null);

        // for (int i = 0; i < Main.listCharacter.size(); i++) {
        //     Rectangle2D rect = new Rectangle2D.Double(Main.listCharacter.get(i)._x, Main.listCharacter.get(i)._y, Main.listCharacter.get(i)._height, Main.listCharacter.get(i)._width);
        //     g2d.draw(rect);
        //     g2d.setPaint(Main.listCharacter.get(i)._colorRect);
        //     g2d.fill(rect);
        //     g2d.setPaint(Main.listCharacter.get(i)._color);
        //     g2d.drawString(Main.listCharacter.get(i)._text, Main.listCharacter.get(i)._xText, Main.listCharacter.get(i)._yText);
        // }
        repaint();
    }

    @Override
    public void paintComponent(Graphics g) {

        super.paintComponent(g);
        g.setColor(new Color(255, 234, 0));
        g.fillRect(0, 0, getWidth(), getHeight());
        doDrawing(g);
    }
}


public class Main extends JFrame {

    public static Integer iaChoose = 0;
    public static Integer playerChoose = 0;
    public static Integer stateGame = 0;
    public static Boolean isChoosing = true;
    public static ArrayList<String> listImages = new ArrayList<String>();


    public Main() {
        initGraphic();
        fillList();
    }

    public void fillList() {
        listImages.add("resources/rock.png");
        listImages.add("resources/paper.png");
        listImages.add("resources/scissor.png");
    }

    public void initGraphic() {
        this.addMouseListener(new myMouseListener());
        add(new Surface());

        setTitle("Rock Paper Scissors");
        setSize(700, 450);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                Main ex = new Main();
                ex.setVisible(true);
            }
        });
    }
}
