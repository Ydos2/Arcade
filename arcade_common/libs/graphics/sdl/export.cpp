/*
** EPITECH PROJECT, 2021
** arcade - sdl
** File description:
** main
*/

#include "../../../common/api.h"
#include "Sdl.hpp"

void *library_create()
{
    auto lib = new arcade::Sdl();
    return lib;
}

void library_delete(void *library)
{
    delete (arcade::Sdl *)library;
}

library_info_t library_get_data()
{
    struct tm date = {0, 0, 0, 23, 3, 2021, 0, 0, 0};

    date.tm_mon--;
    date.tm_year = date.tm_year - 1900;
    return {
        GRAPHIC,
        "sdl2",
        mktime(&date),
        "Simple DirectMedia Layer (SDL) is a cross-platform software "
        "development library designed to provide a hardware abstraction "
        "layer for computer multimedia hardware components."
    };
}