/*
** EPITECH PROJECT, 2021
** arcade - sdl
** File description:
** main
*/

#include "api/api.h"
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
    struct tm date = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    date.tm_year = 2021;
    date.tm_mon = 3;
    date.tm_mday = 23;

    date.tm_mon--;
    date.tm_year = date.tm_year - 1900;
    return {
        library_info_t::GRAPHIC,
        "sdl2",
        mktime(&date),
        "Simple DirectMedia Layer (SDL) is a cross-platform software "
        "development library designed to provide a hardware abstraction "
        "layer for computer multimedia hardware components."
    };
}