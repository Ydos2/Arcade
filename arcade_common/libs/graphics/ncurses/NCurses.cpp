/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** NCurses
*/

#include "NCurses.hpp"
#include <iostream>

namespace arcade {

    NCurses::NCurses()
    {
    }

    NCurses::~NCurses()
    {
    }

    void NCurses::init(IScene &scene)
    {
        std::cout << "NCurses init" << std::endl;
    }

    void NCurses::update(IScene &scene, float dt)
    {
        std::cout << "NCurses loop" << std::endl;
    }

    void NCurses::end(IScene &scene)
    {
        std::cout << "NCurses end" << std::endl;
    }

}