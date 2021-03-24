/*
** EPITECH PROJECT, 2021
** arcade - pacman
** File description:
** main
*/

#include "../../../common/api.h"
#include "PacMan.hpp"

void *library_create()
{
    auto lib = new arcade::PacMan();
    return lib;
}

void library_delete(void *library)
{
    delete (arcade::PacMan *)library;
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