/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** PacMan
*/

#include "PacMan.hpp"
#include <iostream>

namespace arcade {

    PacMan::PacMan()
    {
    }

    PacMan::~PacMan()
    {
    }

    void PacMan::init(Scene &scene)
    {
        std::cout << "PacMan init" << std::endl;
    }

    void PacMan::update(Scene &scene, float dt)
    {
        std::cout << "PacMan loop" << std::endl;
    }

    void PacMan::end(Scene &scene)
    {
        std::cout << "PacMan end" << std::endl;
    }

}