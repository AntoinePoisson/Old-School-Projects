/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** AOpus
*/

#include "AOpus.hpp"

    //! Public
babel::AOpus::AOpus()
: _empty(true), _encrypt(nullptr), _decrypt(nullptr)
{
    int err = 0;

    _decrypt = opus_decoder_create(SAMPLE_RATE, 2, &err);
    if (err != OPUS_OK)
        throw babel::ErrorAOpus("[OPUS]", "Can't Create Decoder");
    _encrypt = opus_encoder_create(SAMPLE_RATE, 2, OPUS_APPLICATION_VOIP, &err);
    if (err != OPUS_OK)
        throw babel::ErrorAOpus("[OPUS]", "Can't Create Encoder");
}

babel::AOpus::AOpus(std::vector<int> const &sound)
: _empty(false), _encrypt(nullptr), _decrypt(nullptr)
{
    int err = 0;

    _decrypt = opus_decoder_create(SAMPLE_RATE, 2, &err);
    if (err != OPUS_OK)
        throw babel::ErrorAOpus("[OPUS]", "Can't Create Decoder");
    _encrypt = opus_encoder_create(SAMPLE_RATE, 2, OPUS_APPLICATION_VOIP, &err);
    if (err != OPUS_OK)
        throw babel::ErrorAOpus("[OPUS]", "Can't Create Encoder");
    _sound.clear();
    for (auto element : sound)
        _sound.push_back(element);
}

babel::AOpus::~AOpus()
{
    if (_empty) {
        return;
    }
    if (_decrypt) {
        opus_decoder_destroy(_decrypt);
    }
    if (_encrypt) {
        opus_encoder_destroy(_encrypt);
    }
}

std::vector<unsigned char> babel::AOpus::encryptData(std::vector<int> data)
{
    // std::vector<unsigned char> result(FRAMES_PER_BUFFER * 2);

    // if (opus_encode(_encrypt, reinterpret_cast<opus_int16 *>(data.data()), data.size(),
    //     result.data(), FRAMES_PER_BUFFER) < 0) {
    //     throw babel::ErrorAOpus("[OPUS]", "Fail Encrypt");
    // }
    std::vector<unsigned char> result(FRAMES_PER_BUFFER * 2);

    if (opus_encode(_encrypt, reinterpret_cast<opus_int16 *>(data.data()), data.size(),
        result.data(), FRAMES_PER_BUFFER * 2) < 0) {
        throw babel::ErrorAOpus("[OPUS]", "Fail Encrypt");
    }
    return (result);
}

std::vector<int> babel::AOpus::decryptData(std::vector<unsigned char> data)
{
    // std::vector<int> result(FRAMES_PER_BUFFER);

    // if (opus_decode(_decrypt, data.data(), data.size(),
    //     reinterpret_cast<opus_int16 *>(result.data()), FRAMES_PER_BUFFER, 0) < 0) {
    //     throw babel::ErrorAOpus("[OPUS]", "Fail Decrypt");
    // }
    std::vector<int> result(FRAMES_PER_BUFFER);

    if (opus_decode(_decrypt, data.data(), data.size(),
        reinterpret_cast<opus_int16 *>(result.data()), FRAMES_PER_BUFFER * 8, 0) < 0) {
        throw babel::ErrorAOpus("[OPUS]", "Fail Decrypt");
    }
    return (result);
}

void babel::AOpus::setData(std::vector<int> const &sound)
{
    if (sound.size() == 0)
        return;
    _sound.clear();
    for (auto element : sound)
        _sound.push_back(element);
    _empty = false;
}

std::vector<int> babel::AOpus::getData(void) const
{
    return (_sound);
}

void babel::AOpus::clear(void)
{
    _sound.clear();
    _empty = true;
}
