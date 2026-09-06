/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** access
*/

#ifndef ACCESS_HPP_
#define ACCESS_HPP_

#ifdef _WIN32
    #include <io.h>
    inline int access(const char *pathname, int mode) {
        return _access(pathname, mode);
    }
    enum {
        ACCESS_R_OK = 4
    };
#else
# include <unistd.h>
    enum {
        ACCESS_R_OK = R_OK
    };
#endif


#endif /* !ACCESS_HPP_ */
