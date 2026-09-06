#!/bin/ruby

require 'gosu'
require 'rubygems'
require 'ostruct'

WORD = File.read(".config").split[0].upcase
DISPLAY_WORD = ""
Button = Struct.new(:_xRect, :_yRect, :_widthRect, :_heightRect, :_colorRect, :_text, :_xButton, :_yButton, :_colorButton)

for i in 0...WORD.length do
    DISPLAY_WORD[i] = "_"
end

module Input
    LISTBUTTON = [
        Button.new(25, 380, 22, 25, Gosu::Color::WHITE, "A", 25 + 5, 385, Gosu::Color::BLACK),
        Button.new(50, 380, 22, 25, Gosu::Color::WHITE, "B", 50 + 5, 385, Gosu::Color::BLACK),
        Button.new(75, 380, 22, 25, Gosu::Color::WHITE, "C", 75 + 5, 385, Gosu::Color::BLACK),
        Button.new(100, 380, 22, 25, Gosu::Color::WHITE, "D", 100 + 5, 385, Gosu::Color::BLACK),
        Button.new(125, 380, 22, 25, Gosu::Color::WHITE, "E", 125 + 5, 385, Gosu::Color::BLACK),
        Button.new(150, 380, 22, 25, Gosu::Color::WHITE, "F", 150 + 5, 385, Gosu::Color::BLACK),
        Button.new(175, 380, 22, 25, Gosu::Color::WHITE, "G", 175 + 5, 385, Gosu::Color::BLACK),
        Button.new(200, 380, 22, 25, Gosu::Color::WHITE, "H", 200 + 5, 385, Gosu::Color::BLACK),
        Button.new(225, 380, 22, 25, Gosu::Color::WHITE, "I", 225 + 8, 385, Gosu::Color::BLACK),
        Button.new(250, 380, 22, 25, Gosu::Color::WHITE, "J", 250 + 5, 385, Gosu::Color::BLACK),
        Button.new(275, 380, 22, 25, Gosu::Color::WHITE, "K", 275 + 5, 385, Gosu::Color::BLACK),
        Button.new(300, 380, 22, 25, Gosu::Color::WHITE, "L", 300 + 5, 385, Gosu::Color::BLACK),
        Button.new(325, 380, 22, 25, Gosu::Color::WHITE, "M", 325 + 5, 385, Gosu::Color::BLACK),
        Button.new(350, 380, 22, 25, Gosu::Color::WHITE, "N", 350 + 5, 385, Gosu::Color::BLACK),
        Button.new(375, 380, 22, 25, Gosu::Color::WHITE, "O", 375 + 5, 385, Gosu::Color::BLACK),
        Button.new(400, 380, 22, 25, Gosu::Color::WHITE, "P", 400 + 5, 385, Gosu::Color::BLACK),
        Button.new(425, 380, 22, 25, Gosu::Color::WHITE, "Q", 425 + 5, 385, Gosu::Color::BLACK),
        Button.new(450, 380, 22, 25, Gosu::Color::WHITE, "R", 450 + 5, 385, Gosu::Color::BLACK),
        Button.new(475, 380, 22, 25, Gosu::Color::WHITE, "S", 475 + 5, 385, Gosu::Color::BLACK),
        Button.new(500, 380, 22, 25, Gosu::Color::WHITE, "T", 500 + 5, 385, Gosu::Color::BLACK),
        Button.new(525, 380, 22, 25, Gosu::Color::WHITE, "U", 525 + 5, 385, Gosu::Color::BLACK),
        Button.new(550, 380, 22, 25, Gosu::Color::WHITE, "V", 550 + 5, 385, Gosu::Color::BLACK),
        Button.new(575, 380, 22, 25, Gosu::Color::WHITE, "W", 575 + 3, 385, Gosu::Color::BLACK),
        Button.new(600, 380, 22, 25, Gosu::Color::WHITE, "X", 600 + 5, 385, Gosu::Color::BLACK),
        Button.new(625, 380, 22, 25, Gosu::Color::WHITE, "Y", 625 + 5, 385, Gosu::Color::BLACK),
        Button.new(650, 380, 22, 25, Gosu::Color::WHITE, "Z", 650 + 5, 385, Gosu::Color::BLACK)

    ]
end

module Hangman
    IMAGE = [
        "resources/hangman_none.png",
        "resources/hangman_one.png",
        "resources/hangman_two.png",
        "resources/hangman_three.png",
        "resources/hangman_four.png",
        "resources/hangman_five.png",
        "resources/hangman_six.png",
        "resources/hangman_seven.png",
        "resources/hangman_none.png"
    ]
end

class Game < Gosu::Window

    def initialize
        super 700, 450, false
        self.caption = "HangMan Game"
        @indexHang = 0
        @font = Gosu::Font.new(self, Gosu::default_font_name, 20)
        @hangman = Gosu::Image.new(Hangman::IMAGE[@indexHang])
    end

    def update
        if (@indexHang >= 8)
            print "You Loose !"
            exit!
        end
        if (DISPLAY_WORD == WORD)
            print "YOU WIN !"
            exit!
        end
    end

    def draw_centered_text(text, size, font)
        res = ""
        i = 0
        for index in 0...text.length do
            res[i] = text[index]
            res[i + 1] = ' '
            i = i + 2
        end
        centered_text = Gosu::Image.from_text(res, size, {:width => 700, :align => :center, :font => font})
    end

    def draw
        draw_centered_text(DISPLAY_WORD, 45, Gosu::default_font_name).draw(0, 245, 0, 1, 1, Gosu::Color::WHITE)
        @hangman.draw(280, 20, 0)
        for el in Input::LISTBUTTON do
            Gosu.draw_rect(el._xRect, el._yRect, el._widthRect, el._heightRect, el._colorRect, 0, mode=:default)
            @font.draw_text(el._text, el._xButton, el._yButton, 0, 1.0, 1.0, el._colorButton)
        end
    end

    def needs_cursor?
        true
    end

    def mouse_over_button(mouse_x, mouse_y, x, y, w, h)
        mouse_x > x and mouse_x < (x + w)  and mouse_y > y and mouse_y < (y + h)
    end

    def button_down(id)
        case id
        when Gosu::MsLeft
            find = -1
            for el in Input::LISTBUTTON do
                if mouse_over_button(mouse_x, mouse_y, el._xRect, el._yRect, el._widthRect, el._heightRect) and el._colorRect == Gosu::Color::WHITE
                    el._colorButton = Gosu::Color::WHITE
                    el._colorRect = Gosu::Color::BLACK
                    find = 0
                    break if WORD.include?(el._text) == false
                    for i in 0...WORD.length do
                        if WORD[i] == el._text
                            DISPLAY_WORD[i] = el._text
                        end
                    end
                    find = 1
                end
            end
            if find == 0
                @indexHang = @indexHang + 1
                @hangman = Gosu::Image.new(Hangman::IMAGE[@indexHang])
            end
        end
    end
end

Game.new.show
