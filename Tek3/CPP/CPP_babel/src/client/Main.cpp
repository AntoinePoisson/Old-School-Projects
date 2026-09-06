/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** main
*/

// #define ONLY_AUDIO

# if defined(ONLY_AUDIO)
#include "opus/opus.h"
#include "APortAudio.hpp"
#else
#include "ClientNetwork.h"
#endif

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
int main(int ac, char **av, char **env)
#else
int main(__attribute__((unused))  int ac, __attribute__((unused)) char **av,
__attribute__((unused)) char **env)
#endif
{
#if defined(ONLY_AUDIO)
    babel::APortAudio aze;

    while (1) {
        babel::HandlerAudio ok(aze.getSound().getData());
        aze.playSound(ok.decrypted(ok.encrypted(ok.getData())));
    }
#else
    try {
        babel::ClientNetwork(ac, av);
    } catch (std::string err) {
        std::cout << err << std::endl;
        return (84);
    } catch (...) {
        perror("Error\n");
        return (-1);
    }
#endif
    return (0);
}