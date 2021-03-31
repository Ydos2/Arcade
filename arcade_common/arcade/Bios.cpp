/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Bios
*/

#include "Bios.hpp"
#include <iostream>

namespace arcade {

void Bios::init(IScene &scene)
{
    (void)scene;
}

void Bios::update(IScene &scene, float dt)
{
    (void)scene;
    (void)dt;
    std::cout << "BIOS" << std::endl;
}

void Bios::end(IScene &scene)
{
    (void)scene;
}

}
