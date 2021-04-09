/*
** EPITECH PROJECT, 2021
** arcade - pacman
** File description:
** main
*/

#include "api/api.h"
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
    struct tm date = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    date.tm_year = 2021;
    date.tm_mon = 3;
    date.tm_mday = 23;

    date.tm_mon--;
    date.tm_year = date.tm_year - 1900;
    return {
        library_info_t::GAME,
        "pacman",
        mktime(&date),
        "Pac-Man is a famous maze arcade game"
        "developed and released by Namco in 1980."
    };
}