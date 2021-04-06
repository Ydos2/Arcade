/*
** EPITECH PROJECT, 2021
** arcade - nibbler
** File description:
** main
*/

#include "api/api.h"
#include "Nibbler.hpp"

void *library_create()
{
    auto lib = new arcade::Nibbler();
    return lib;
}

void library_delete(void *library)
{
    delete (arcade::Nibbler *)library;
}

library_info_t library_get_data()
{
    struct tm date = {0, 0, 0, 23, 3, 2021, 0, 0, 0};

    date.tm_mon--;
    date.tm_year = date.tm_year - 1900;
    return {
        library_info_t::GAME,
        "nibbler",
        mktime(&date),
        "Nibbler is a maze video game created by SNK and released"
        " on arcade terminals (on the Rock-Ola system) in 1982."
    };
}