/*
** EPITECH PROJECT, 2020
** bmp
** File description:
** bmp
*/

#include "bitmap.h"

uint16_t change_endian_16(uint16_t endian)
{
    endian = ((endian >> 8) | (endian << 8));
    return (endian);
}

void make_bmp_header(bmp_header_t *header, size_t size)
{
    header->magic = change_endian_16(0x424D);
    header->size = size * size * 4 + 54;
    header->_app1 = 0x0000;
    header->_app2 = 0x0000;
    header->offset = 54;
}

void make_bmp_info_header(bmp_info_header_t *header, size_t size)
{
    header->size = sizeof(bmp_info_header_t);
    header->width = size;
    header->height = size;
    header->planes = 1;
    header->bpp = 32;
    header->compression = 0x0000;
    header->raw_data_size = size * size * 4;
    header->h_resolution = 0x0000;
    header->v_resolution = 0x0000;
    header->palette_size = 0x0000;
    header->important_colors = 0x0000;
}