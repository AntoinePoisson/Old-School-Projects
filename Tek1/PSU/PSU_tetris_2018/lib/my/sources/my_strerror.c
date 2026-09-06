/*
** EPITECH PROJECT, 2019
** lib
** File description:
** mstrerror.c
*/

#include <errno.h>
#include <unistd.h>

char *error_file_directory(int errnum)
{
    switch (errnum) {
    case EBADF: return ("Bad file descriptor.\n");
    case EBADFD: return ("File descriptor in bad state.\n");
    case EEXIST: return ("File exists.\n");
    case EISNAM: return ("Is a named type file.\n");
    case EMFILE: return ("Too many open files.\n");
    case ENFILE: return ("Too many open files in system.\n");
    case EROFS: return ("Read-only file system.\n");
    case ENOTDIR: return ("Not a directory.\n");
    case ENOTEMPTY: return ("Directory not empty.\n");
    case EISDIR: return ("Is a directory.\n");
    case ENOENT: return ("No such file or directory.\n");
    }
    return (NULL);
}

char *error_size(int errnum)
{
    switch (errnum) {
    case E2BIG: return ("Argument list too long.\n");
    case EFBIG: return ("File too large.\n");
    case EMSGSIZE: return ("Message too long.\n");
    case ENAMETOOLONG: return ("File name too long.\n");
    case EOVERFLOW: return ("Value too large for defined data type.\n");
    case EMLINK: return ("Too many links.\n");
    case ELOOP: return ("Too many levels of symbolic links.\n");
    case EDOM: return ("Numerical argument out of domain.\n");
    case ERANGE: return ("Numerical result out of range.\n");
    }
    return (NULL);
}

char *error_adress_memory(int errnum)
{
    switch (errnum) {
    case EACCES: return ("Permission denied.\n");
    case EADDRINUSE: return ("Address already in use.\n");
    case EADDRNOTAVAIL: return ("Cannot assign requested address.\n");
    case EAFNOSUPPORT: return ("Address family not supported by protocol.\n");
    case EFAULT: return ("Bad address.\n");
    case ENOMEM: return ("Cannot allocate memory.\n");
    case ENOSPC: return ("No space left on device.\n");
    case EBADSLT: return ("Invalid slot.\n");
    }
    return (NULL);
}

char *error_operation_system(int errnum)
{
    switch (errnum) {
    case EALREADY: return ("Operation already in progress.\n");
    case EPERM: return ("Operation not permitted.\n");
    case EOPNOTSUPP | ENOTSUP: return ("Operation not supported.\n");
    case ECANCELED: return ("Operation canceled.\n");
    case EIO: return ("Input/output error.\n");
    case EINTR: return ("Interrupted system call.\n");
    case EBADMSG: return ("Bad message.\n");
    case ECHILD: return ("No child processes.\n");
    case EINVAL: return ("Invalid argument.\n");
    case EBADE: return ("Invalid exchange.\n");
    case ETIME: return ("Timer expired.\n");
    case ETIMEDOUT: return ("Connection timed out.\n");
    case EAGAIN: return ("Resource temporarily unavailable.\n");
    }
    return (NULL);
}

int my_strerror(int errnum)
{
    char *message = NULL;

    message = error_file_directory(errnum);
    message = (!message) ? error_size(errnum) : message;
    message = (!message) ? error_adress_memory(errnum) : message;
    message = (!message) ? error_operation_system(errnum) : message;
    if (message)
        for (int a = 0; message[a]; a++)
            write(1, &message[a], 1);
    return (84);
}
