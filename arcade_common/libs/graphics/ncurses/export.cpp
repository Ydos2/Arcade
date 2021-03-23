/*
** EPITECH PROJECT, 2021
** arcade - ncurses
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
        GRAPHIC,
        "ncurses",
        mktime(&date),
        "ncurses is a library that allows the programmer to write "
        "text-based user interfaces in a terminal-independent manner."
    };
}