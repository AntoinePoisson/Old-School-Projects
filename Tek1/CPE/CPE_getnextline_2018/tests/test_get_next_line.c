/*
** EPITECH PROJECT, 2018
** test_get_next_line
** File description:
** test_get_next_line
*/

#include  <criterion/criterion.h>
#include  <criterion/redirect.h>
#include  <fcntl.h>
#include  <unistd.h>

int fd = -1;

char *get_next_line(int fd);

void open_file(void)
{
    fd = open("tests/data.txt", O_RDONLY);
    cr_redirect_stdout();
}

void open_file_not_read(void)
{
    fd = open("tests/data.txt", O_WRONLY);
    cr_redirect_stdout();
}

void open_file_void(void)
{
    fd = open("tests/void.txt", O_RDONLY);
    cr_redirect_stdout();
}

void close_file(void)
{
    if (fd != -1)
        close(fd);
}

Test(get_next_line, read_line, .init = open_file, .fini = close_file)
{
    char *expected = "BONJOUR 12345678 1234567890.";
    char *got = get_next_line(fd);

    cr_assert_str_eq(got, expected);
}

Test(get_next_line, read_line_two, .init = open_file, .fini = close_file)
{
    char *expected = "CECI est la deuxième phrase.";
    char *got;

    get_next_line(fd);
    got = get_next_line(fd);
    cr_assert_str_eq(got, expected);
}

Test(get_next_line, Invalid_fd)
{
    int fd_two = -1;
    char *expected = NULL;
    char *got = get_next_line(fd_two);

    cr_assert_eq(got, expected);
}

Test(get_next_line, Invalid_file, .init = open_file_void, .fini = close_file)
{
    char *expected = NULL;
    char *got = get_next_line(fd);

    cr_assert_eq(got, expected);
}

Test(get_next_line, Error_Read, .init = open_file, .fini = close_file)
{
    char *expected = NULL;
    char *got;

    while ((got = get_next_line(fd)))
        free(got);
    cr_assert_eq(got, expected);
}

Test(get_next_line, Cannot_Read, .init = open_file_not_read,
    .fini = close_file)
{
    char *expected = NULL;
    char *got;

    while ((got = get_next_line(fd)))
        free(got);
    cr_assert_eq(got, expected);
}
