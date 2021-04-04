/*
** EPITECH PROJECT, 2021
** arcade - ncurses
** File description:
** main
*/

#include "api/api.h"
#include "Sfml.hpp"

void *library_create()
{
    auto lib = new arcade::Sfml();
    return lib;
}

void library_delete(void *library)
{
    delete (arcade::Sfml *)library;
}

library_info_t library_get_data()
{
    struct tm date = {0, 0, 0, 23, 3, 2021, 0, 0, 0};

    date.tm_mon--;
    date.tm_year = date.tm_year - 1900;
    return {
        library_info_t::GRAPHIC,
        "sfml",
        mktime(&date),
        "SFML offers a simple interface to the various components of your PC,"
        " in order to facilitate the development of games or multimedia applications."
        " It is composed of five modules : system, windowing, graphics, audio and network."
    };
}