/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** NCurses
*/

#include "NCurses.hpp"
#include <iostream>
#include <ncurses.h>

namespace arcade
{

    void NCurses::init(IScene &scene)
    {
        std::cout << "NCurses init" << std::endl;
        initscr();
        nodelay(stdscr, TRUE);
        raw();
        noecho();
        keypad(stdscr, TRUE);
        curs_set(0);
        start_color();
    }

    void NCurses::update(IScene &scene, float dt)
    {
        std::cout << "NCurses loop" << std::endl;
    }

    void NCurses::end(IScene &scene)
    {
        std::cout << "NCurses end" << std::endl;
        curs_set(TRUE);
        endwin();
    }

    bool NCurses::quitRequested() const
    {
        std::cout << "Quit request" << std::endl;
    }
}