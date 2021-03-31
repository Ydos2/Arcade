/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Sdl
*/

#include "Sdl.hpp"
#include <iostream>

namespace arcade {

    Sdl::Sdl()
    {
    }

    Sdl::~Sdl()
    {
    }

    void Sdl::init(IScene &scene)
    {
        std::cout << "SDL init" << std::endl;
    }

    void Sdl::update(IScene &scene, float dt)
    {
        std::cout << "SDL loop" << std::endl;
    }

    void Sdl::end(IScene &scene)
    {
        std::cout << "SDL end" << std::endl;
    }

}