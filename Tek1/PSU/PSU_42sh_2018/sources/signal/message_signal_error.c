/*
** EPITECH PROJECT, 2019
** message_signal_error.c
** File description:
** message_signal_error
*/

#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "my_shell.h"

int research_signal(int signal, int w)
{
    switch (signal) {
        case 1:
            return (print_signal("Hangup", w));
        case 3:
            return (print_signal("Quit", w));
        case 4:
            return (print_signal("Illegal instruction", w));
        case 5:
            return (print_signal("Trace/BPT trap", w));
        case 6:
            return (print_signal("Abort", w));
        case 7:
            return (print_signal("Bus error", w));
        case 8:
            return (print_signal("Floating exception", w));
        case 9:
            return (print_signal("Killed", w));
    }
    return (0);
}

int research_signal_two(int signal, int w)
{
    switch (signal) {
        case 10:
            return (print_signal("User signal 1", w));
        case 11:
            return (print_signal("Segmentation fault", w));
        case 12:
            return (print_signal("User signal 2", w));
        case 13:
            return (print_signal("Broken pipe", w));
        case 14:
            return (print_signal("Alarm clock", w));
        case 15:
            return (print_signal("Terminated", w));
        case 16:
            return (print_signal("Stack limit exceeded", w));
        case 24:
            return (print_signal("Cputime limit exceeded", w));
    }
    return (0);
}

int research_signal_three(int signal, int w)
{
    switch (signal) {
        case 25:
            return (print_signal("Filesize limit exceeded", w));
        case 26:
            return (print_signal("Virtual time alarm", w));
        case 27:
            return (print_signal("Profiling time alarm", w));
        case 29:
            return (print_signal("Pollable event occured", w));
        case 30:
            return (print_signal("Power failure", w));
        case 31:
            return (print_signal("Bad system call", w));
        case 32:
            return (print_signal("Signal 32", w));
        case 33:
            return (print_signal("Signal 33", w));
    }
    return (0);
}

int research_signal_ext_one(int signal, int w)
{
    switch (signal) {
        case 34:
            return (print_signal("First Realtime Signal", w));
        case 35:
            return (print_signal("Second Realtime Signal", w));
        case 36:
            return (print_signal("Third Realtime Signal", w));
        case 37:
            return (print_signal("Fourth Realtime Signal", w));
        case 38:
            return (print_signal("Signal 38", w));
        case 39:
            return (print_signal("Signal 39", w));
        case 40:
            return (print_signal("Signal 40", w));
        case 41:
            return (print_signal("Signal 41", w));
    }
    return (0);
}

int research_signal_ext_two(int signal, int w)
{
    switch (signal) {
        case 42:
            return (print_signal("Signal 42", w));
        case 43:
            return (print_signal("Signal 43", w));
        case 44:
            return (print_signal("Signal 44", w));
        case 45:
            return (print_signal("Signal 45", w));
        case 46:
            return (print_signal("Signal 46", w));
        case 47:
            return (print_signal("Signal 47", w));
        case 48:
            return (print_signal("Signal 48", w));
    }
    return (0);
}