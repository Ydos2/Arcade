/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** NCurses
*/

#include "Sfml.hpp"
#include <iostream>

namespace arcade
{

    void Sfml::init(IScene &scene)
    {
        std::cout << "Sfml init" << std::endl;
    }

    void Sfml::update(IScene &scene, float dt)
    {
        std::cout << "Sfml loop" << std::endl;
    }

    void Sfml::end(IScene &scene)
    {
        std::cout << "Sfml end" << std::endl;
    }

    bool Sfml::quitRequested() const
    {
    }
}