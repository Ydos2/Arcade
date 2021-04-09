/*
** EPITECH PROJECT, 2021
** arcade - ncurses
** File description:
** main
*/

#include "api/api.h"
#include "NCurses.hpp"

void *library_create()
{
    auto lib = new arcade::NCurses();
    return lib;
}

void library_delete(void *library)
{
    delete (arcade::NCurses *)library;
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
        library_info_t::GRAPHIC,
        "ncurses",
        mktime(&date),
        "ncurses is a library that allows the programmer to write "
        "text-based user interfaces in a terminal-independent manner."
    };
}