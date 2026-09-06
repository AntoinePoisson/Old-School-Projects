/*
** EPITECH PROJECT, 2019
** usefull_function
** File description:
** mgetline.h
*/

#ifndef _MGETLINE_H_
#define _MGETLINE_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef READ_SIZE
#define READ_SIZE (1)
#endif

char *mgetline(int fd);

#endif
