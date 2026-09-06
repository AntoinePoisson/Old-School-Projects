/*
** EPITECH PROJECT, 2018
** cat 
** File description:
** my_cat, it's like command cat system
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void my_putchar(char c)
{
    write(2, &c, 1);
    return;
}

int my_putstr(char const *str)
{
    int carac = 0;

    for (carac = 0; str[carac] != '\0'; carac++)
        my_putchar(str[carac]);
    return (0);
}

int cat(int ac, char *av[], int a)
{
    int fd;
    int count = 30000;
    char buf[500];
    int i = 0;

    fd = open(av[a], O_RDONLY, S_IRWXU);
    if (fd == -1) {
        my_putstr("cat: ");
        my_putstr(av[a]);
        my_putstr(": No such file or directory");
        my_putchar('\n');
        return (84);
    }
    i = read(fd, buf, count);
    if (i == -1)
        return(84);
    write(1, buf, i);
    close(fd);
    return (0);
}

int check_error(int ac, char *av[])
{
    if (ac == 1)
        return (84);
    return (1);
}
