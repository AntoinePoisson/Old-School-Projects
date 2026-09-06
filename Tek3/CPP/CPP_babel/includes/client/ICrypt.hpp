/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** ICrypt
*/

#ifndef ICRYPT_HPP_
#define ICRYPT_HPP_

namespace babel {

    class ICrypt {
        public:
            virtual ~ICrypt() = default;

            virtual std::vector<unsigned char> encryptData(std::vector<int> data) = 0;
            virtual std::vector<int> decryptData(std::vector<unsigned char> data) = 0;
    };

}

#endif /* !ICRYPT_HPP_ */
