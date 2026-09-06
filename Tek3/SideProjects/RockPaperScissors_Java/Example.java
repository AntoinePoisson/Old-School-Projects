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

class Character {

    public Integer _x = 0;
    public Integer _y = 0;
    public Integer _height = 0;
    public Integer _width = 0;
    public String _text = "";
    public Integer _xText = 0;
    public Integer _yText = 0;
    public Color _color = Color.BLACK;
    public Color _colorRect = Color.WHITE;

    public Character(Integer x, Integer y, Integer height, Integer width, String text, Integer xText, Integer yText) {
        this._x = x;
        this._y = y;
        this._height = height;
        this._width = width;
        this._text = text;
        this._xText = xText;
        this._yText = yText;
    }
}


class myMouseListener extends MouseAdapter {


    public boolean checkClick(Integer x1, Integer _x, Integer _width, Integer y1, Integer _y, Integer _height) {
        return x1 > _x && x1 < (_x + _width) && y1 - 30 > _y && y1 - 30 < (_y + _height);
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        int x1 = e.getX();
        int y1 = e.getY();


        int find = -1;

        for (int i = 0; i < Main.listCharacter.size(); i++) {
            if (checkClick(x1, Main.listCharacter.get(i)._x, Main.listCharacter.get(i)._width, y1, Main.listCharacter.get(i)._y, Main.listCharacter.get(i)._height) && Main.listCharacter.get(i)._colorRect == Color.WHITE) {
                Main.listCharacter.get(i)._colorRect = Color.BLACK;
                Main.listCharacter.get(i)._color = Color.WHITE;
                find = 0;
                if (Main.solution.indexOf(Main.listCharacter.get(i)._text) == -1)
                    break;
                for (int index = 0; index < Main.solution.length(); index++) {
                    if (Main.solution.charAt(index) == Main.listCharacter.get(i)._text.charAt(0)) {
                        Main.display_word = Main.display_word.substring(0, index) + Main.listCharacter.get(i)._text.charAt(0) + Main.display_word.substring(index + 1);
                    }
                }
                find = 1;
            }
        }
        if (find == 0) {
            Main.wrongAnswer = Main.wrongAnswer + 1;
        }
        if (Main.wrongAnswer >= 8) {
            System.out.println("You Loose !");
            System.exit(0);
        }
        if (Main.solution.equals(Main.display_word)) {
            System.out.println("YOU WIN !");
            System.exit(0);
        }
    }
}

class Surface extends JPanel {

    private String displayHiddenWord() {
        String word = "";
        for (int i = 0; i < Main.display_word.length(); i++) {
            word += Main.display_word.charAt(i);
            word += ' ';
        }
        return (word);
    }

    private void doDrawing(Graphics g) {

        Graphics2D g2d = (Graphics2D) g;
        g2d.setPaint(Color.WHITE);
        g2d.drawString(displayHiddenWord(), 350 - (5 * Main.display_word.length()), 245);

        g2d.drawImage(new ImageIcon(Main.listImages.get(Main.wrongAnswer)).getImage(), 280, 20, null);

        for (int i = 0; i < Main.listCharacter.size(); i++) {
            Rectangle2D rect = new Rectangle2D.Double(Main.listCharacter.get(i)._x, Main.listCharacter.get(i)._y, Main.listCharacter.get(i)._height, Main.listCharacter.get(i)._width);
            g2d.draw(rect);
            g2d.setPaint(Main.listCharacter.get(i)._colorRect);
            g2d.fill(rect);
            g2d.setPaint(Main.listCharacter.get(i)._color);
            g2d.drawString(Main.listCharacter.get(i)._text, Main.listCharacter.get(i)._xText, Main.listCharacter.get(i)._yText);
        }
        repaint();
    }

    @Override
    public void paintComponent(Graphics g) {

        super.paintComponent(g);
        g.setColor(Color.BLACK);
        g.fillRect(0, 0, getWidth(), getHeight());
        doDrawing(g);
    }
}


public class Example extends JFrame {

    public static String solution = "";
    public static String display_word = "";
    public static Integer wrongAnswer = 2;
    public static ArrayList<Character> listCharacter = new ArrayList<Character>();
    public static ArrayList<String> listImages = new ArrayList<String>();


    public Main() {
        getWord();
        initGraphic();
        fillList();
    }

    public void getWord() {
        try {
            BufferedReader reader = new BufferedReader(new FileReader("./.config"));
            solution = reader.readLine().toUpperCase();
            reader.close();
            for (int i = 0; i < solution.length(); i++) {
                display_word += '_';
            }
            System.out.println(solution);
        } catch (Exception e) {
            System.err.format("Erreur with .config file");
            e.printStackTrace();
        }
    }

    public void fillList() {
        listCharacter.add(new Character(25, 380 - 10, 22, 25, "A", (25 + 5), 385));
        listCharacter.add(new Character(50, 380 - 10, 22, 25, "B", (50 + 5), 385));
        listCharacter.add(new Character(75, 380 - 10, 22, 25, "C", (75 + 5), 385));
        listCharacter.add(new Character(100, 380 - 10, 22, 25, "D", (100 + 5), 385));
        listCharacter.add(new Character(125, 380 - 10, 22, 25, "E", (125 + 5), 385));
        listCharacter.add(new Character(150, 380 - 10, 22, 25, "F", (150 + 5), 385));
        listCharacter.add(new Character(175, 380 - 10, 22, 25, "G", (175 + 5), 385));
        listCharacter.add(new Character(200, 380 - 10, 22, 25, "H", (200 + 5), 385));
        listCharacter.add(new Character(225, 380 - 10, 22, 25, "I", (225 + 8), 385));
        listCharacter.add(new Character(250, 380 - 10, 22, 25, "J", (250 + 5), 385));
        listCharacter.add(new Character(275, 380 - 10, 22, 25, "K", (275 + 5), 385));
        listCharacter.add(new Character(300, 380 - 10, 22, 25, "L", (300 + 5), 385));
        listCharacter.add(new Character(325, 380 - 10, 22, 25, "M", (325 + 5), 385));
        listCharacter.add(new Character(350, 380 - 10, 22, 25, "N", (350 + 5), 385));
        listCharacter.add(new Character(375, 380 - 10, 22, 25, "O", (375 + 5), 385));
        listCharacter.add(new Character(400, 380 - 10, 22, 25, "P", (400 + 5), 385));
        listCharacter.add(new Character(425, 380 - 10, 22, 25, "Q", (425 + 5), 385));
        listCharacter.add(new Character(450, 380 - 10, 22, 25, "R", (450 + 5), 385));
        listCharacter.add(new Character(475, 380 - 10, 22, 25, "S", (475 + 5), 385));
        listCharacter.add(new Character(500, 380 - 10, 22, 25, "T", (500 + 5), 385));
        listCharacter.add(new Character(525, 380 - 10, 22, 25, "U", (525 + 5), 385));
        listCharacter.add(new Character(550, 380 - 10, 22, 25, "V", (550 + 5), 385));
        listCharacter.add(new Character(575, 380 - 10, 22, 25, "W", (575 + 3), 385));
        listCharacter.add(new Character(600, 380 - 10, 22, 25, "X", (600 + 5), 385));
        listCharacter.add(new Character(625, 380 - 10, 22, 25, "Y", (625 + 5), 385));
        listCharacter.add(new Character(650, 380 - 10, 22, 25, "Z", (650 + 5), 385));
        listImages.add("resources/hangman_none.png");
        listImages.add("resources/hangman_one.png");
        listImages.add("resources/hangman_two.png");
        listImages.add("resources/hangman_three.png");
        listImages.add("resources/hangman_four.png");
        listImages.add("resources/hangman_five.png");
        listImages.add("resources/hangman_six.png");
        listImages.add("resources/hangman_seven.png");
        listImages.add("resources/hangman_none.png");
    }

    public void initGraphic() {
        this.addMouseListener(new myMouseListener());
        add(new Surface());

        setTitle("HangMan");
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
