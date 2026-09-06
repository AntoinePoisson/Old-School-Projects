/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** AOpus
*/

#ifndef AOPUS_HPP_
#define AOPUS_HPP_

#include <vector>
#include <iostream>
#include <algorithm>
#include <arpa/inet.h>

#include "opus/opus.h"
#include "ErrorAOpus.hpp"
#include "ICrypt.hpp"

#define SAMPLE_RATE 48000
#define FRAMES_PER_BUFFER 480

namespace babel {

    class AOpus : public ICrypt {
        public:
            AOpus();
            AOpus(std::vector<int> const &sound);
            ~AOpus();

            std::vector<unsigned char> encryptData(std::vector<int> data);
            std::vector<int> decryptData(std::vector<unsigned char> data);
            void setData(std::vector<int> const &sound);
            std::vector<int> getData(void) const;
            void clear(void);
        private:
            bool _empty;
            std::vector<int> _sound;
            OpusEncoder *_encrypt;
            OpusDecoder *_decrypt;
    };

}

#endif /* !AOPUS_HPP_ */
