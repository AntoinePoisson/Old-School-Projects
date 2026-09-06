/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** generate_uuid
*/

#include <uuid/uuid.h>
#include <string.h>

char *generate_uuid(void)
{
    uuid_t binuuid;
    char uuid[37] = {0};

    uuid_generate_random(binuuid);
    uuid_unparse_upper(binuuid, uuid);
    return (strdup(uuid));
}