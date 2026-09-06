/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sys/types.h>
#include <signal.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

typedef struct protoent protoent_t;
typedef struct sockaddr_in sockaddr_in_t;



void *my_malloc(size_t size)
{
    void *data = malloc(size);

    if (data == NULL) {
        fprintf(stdout, "Error: malloc failure\n");
        exit(84);
    }
    memset(data, 0, size);
    return (data);
}

char *my_realloc(char *str)
{
    int malloc_size = 0;
    char *result;

    for (; str[malloc_size]; malloc_size++);
    result = static_cast<char *>(my_malloc(sizeof(char) * (malloc_size + 2)));
    for (int i = 0; str[i]; i++) {
        result[i] = str[i];
        result[i + 1] = '\0';
    }
    free(str);
    return (result);
}

char bufferize(int fd)
{
    static char *buff = NULL;
    static char *tmp = NULL;
    static int line = 0;
    char c = 0;
    fd_set fds;
    struct timeval time = {0, 0};

    FD_ZERO(&fds);
    FD_SET(fd, &fds);

    if (!buff) {
        buff = static_cast<char *>(my_malloc(sizeof(char) * (42 + 1)));
        tmp = buff;
    }
    if (!line) {
        buff = tmp;
        int sel = select(fd + 1, &fds, NULL, NULL, &time);
        if (sel > 0 && FD_ISSET(fd, &fds)) {
            line = read(fd, buff, 42);
        } else {
            return ('\n');
        }
        if (!line) {
            return ('\0');
        }
    }
    c = buff[0];
    buff = &buff[1];
    line -= 1;
    return (c);
}

char *get_next_line(int fd, char delimiter)
{
    char *str = static_cast<char *>(my_malloc(sizeof(char) * (1 + 1)));
    char c = 0;
    int i = 0;

    c = bufferize(fd);
    for (; c && c != delimiter; i++) {
        str[i] = c;
        str[i + 1] = '\0';
        if ((str = my_realloc(str)) == NULL)
            return (NULL);
        c = bufferize(fd);
    }
    if (!c && i <= 1)
        return (NULL);
    return (str);
}




int connect_socket(int fd_sock, char *ip, int port)
{
    sockaddr_in_t addr_in;

    addr_in.sin_family = AF_INET;
    addr_in.sin_port = htons(port);
    addr_in.sin_addr.s_addr = inet_addr(ip);
    if (connect(fd_sock, (const struct sockaddr *)&addr_in,
    sizeof(addr_in)) == -1) {
        fprintf(stdout, "Error: can't connect to the server. \
Please use a valid ip/port\n");
        shutdown(fd_sock, SHUT_RDWR);
        return (-1);
    }
    return (0);
}

int open_socket(void)
{
    protoent_t *pe;
    int fd_sock;
    int set = 1;

    if ((pe = getprotobyname("TCP")) == NULL) {
        fprintf(stdout, "Error: bad use of getprotobyname() function\n");
        return (-1);
    }
    if ((fd_sock = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1) {
        fprintf(stdout, "Error: bad use of socket() function\n");
        return (-1);
    }
    if (setsockopt(fd_sock, SOL_SOCKET, SO_REUSEPORT, &set, sizeof(set)) == -1)
        fprintf(stdout, "Error: bad use of setsockopt() function\n");
    return (fd_sock);
}

int main(int ac, char **av)
{
    int fd_sock = 0;
    sf::RenderWindow *window = new sf::RenderWindow(
        sf::VideoMode(
            1366,
            700
        ),
        "Client interface",
        sf::Style::Close
    );
    sf::Event event;
    window->setFramerateLimit(10);
    window->setPosition(sf::Vector2i(0, 0));
    if (ac != 3) {
        std::cerr << "Bad args: need Ip and port" << std::endl;
        return (84);
    }
    if ((fd_sock = open_socket()) == -1)
        return (84);
    if (connect_socket(fd_sock, av[1], atoi(av[2])) == -1)
        return (84);
    sf::RectangleShape rec;
    int padding = 20;
    rec.setSize(sf::Vector2f(1366 / 2 - padding * 2, 700 / 2 - padding * 2));
    rec.setPosition(sf::Vector2f(padding, padding));
    rec.setFillColor(sf::Color(27, 27, 27));
    std::vector<std::string> output = {};
    std::vector<std::string> input = {};
    std::string user = "";
    sf::Font font;
    font.loadFromFile("font.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color(255,255,255));
    fd_set fds;
    struct timeval time = {0, 0};

    FD_ZERO(&fds);
    FD_SET(fd_sock, &fds);
    char *gnl = NULL;
    usleep(50000);
    sf::RectangleShape curs;
    curs.setFillColor(sf::Color(255, 255, 255));
    curs.setSize(sf::Vector2f(1, 20));
    sf::Clock clocked;
    std::vector<std::string> commands = {"Forward", "Right", "Left", "Look", "Inventory", "Broadcast text", "Connect_nbr", "Fork", "Eject", "Take object", "Set object", "Incantation"};
    sf::RectangleShape button;
    button.setFillColor(sf::Color(27, 27, 27));
    button.setSize(sf::Vector2f(30, 30));
    sf::Vector2i mouse;
    bool click = false;
    bool click2 = false;
    // sf::Music bot;
    // bot.openFromFile("hover.ogg");
    while (window->isOpen()) {
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b') {
                    if (user.size())
                        user.erase(user.size() - 1, 1);
                } else
                    user += event.text.unicode;
            }
            if (event.type == event.KeyReleased && event.key.code == sf::Keyboard::Return) {
                write(fd_sock, (user + "\n").c_str(), strlen((user + "\n").c_str()));
                output.push_back(user);
                if (output.size() > 9)
                    output.erase(output.begin(), output.begin() + 1);
                user = "";
            }
            mouse = sf::Mouse::getPosition(*window);
            if (!click) {
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (!click2) {
                        click2 = true;
                        click = true;
                    }
                } else {
                    click2 = false;
                }
            } else {
                click = false;
            }
        }
        int sel = select(fd_sock + 1, &fds, NULL, NULL, &time);
        // if (sel > 0 && FD_ISSET(fd_sock, &fds)) {
        gnl = get_next_line(fd_sock, '\n');
        if (gnl && strlen(gnl)) {
            input.push_back(std::string(gnl));
            if (input.size() > 10)
                input.erase(input.begin(), input.begin() + 1);
        }
        window->clear(sf::Color(10, 10, 27));
        rec.setPosition(sf::Vector2f(padding, padding));
        window->draw(rec);
        for (int i = 0; i < static_cast<int>(input.size()); i++) {
            text.setPosition(sf::Vector2f(padding + 10, padding + 10 + 30 * i));
            std::string inputTmp = input[i];
            if (inputTmp.size() > 65) {
                inputTmp.erase(inputTmp.begin() + 65, inputTmp.end());
                inputTmp += "...";
            }
            text.setString(inputTmp);
            window->draw(text);
        }
        rec.setPosition(sf::Vector2f(padding, padding + 700 / 2));
        window->draw(rec);
        // text.setString(user);
        // text.setPosition(padding + 10, 700 - padding - 30);
        int j = 0;
        for (; j < static_cast<int>(output.size()); j++) {
            text.setPosition(sf::Vector2f(padding + 10, 700 / 2 + padding + 10 + 30 * j));
            std::string outputTmp = output[j];
            if (outputTmp.size() > 65) {
                outputTmp.erase(outputTmp.begin() + 65, outputTmp.end());
                outputTmp += "...";
            }
            text.setString(outputTmp);
            window->draw(text);
        }
        text.setString(user);
        text.setPosition(padding + 10, 700 / 2 + padding + 10 + 30 * j);
        window->draw(text);
        if (clocked.getElapsedTime().asMilliseconds() >= 500) {
            curs.setPosition(padding + 10 + text.getLocalBounds().width + 5, 700 / 2 + padding + 10 + 30 * j + 5);
            window->draw(curs);
            if (clocked.getElapsedTime().asMilliseconds() >= 1000)
                clocked.restart();
        }
        for (j = 0; j < commands.size(); j++) {
            button.setPosition(sf::Vector2f(1366 / 2, padding + j * 35));
            text.setPosition(sf::Vector2f(1366 / 2 + 10, padding + j * 35 + 5));
            text.setString(commands[j]);
            button.setSize(sf::Vector2f(text.getLocalBounds().width + 20, 30));
            window->draw(button);
            window->draw(text);
            if (click) {
                if (mouse.x >= button.getPosition().x && mouse.x <= button.getPosition().x + button.getLocalBounds().width &&
                mouse.y >= button.getPosition().y && mouse.y <= button.getPosition().y + button.getLocalBounds().height) {
                    click = false;
                    write(fd_sock, (commands[j] + "\n").c_str(), strlen((commands[j] + "\n").c_str()));
                    output.push_back(commands[j]);
                    if (output.size() > 9)
                        output.erase(output.begin(), output.begin() + 1);
                    // bot.stop();
                    // bot.play();
                }
            }
        }
        window->display();
    }
    shutdown(fd_sock, SHUT_RDWR);
}