/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** main.c
*/

char *backticks(char *str);

int main(void)
{
    backticks("salut `le monde` `ca va` `la` l");
    backticks("salut     `         le    monde   `   `  ca   va  ` `  la  ` l");
    return (0);
}
