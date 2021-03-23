/*
** EPITECH PROJECT, 2021
** arcade - pacman
** File description:
** main
*/

#include "../../../common/api.h"

void *library_create()
{
    return NULL;
}

void library_delete(void *library)
{
    (void)library;
}

library_info_t library_get_data()
{
    struct tm date = {0, 0, 0, 23, 3, 2021, 0, 0, 0};

    date.tm_mon--;
    date.tm_year = date.tm_year - 1900;
    return {
        GAME,
        "pacman",
        mktime(&date),
        "Pac-Man is a famous maze arcade game"
        "developed and released by Namco in 1980."
    };
}