/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Bios
*/

#include "Bios.hpp"
#include <iostream>

namespace arcade {

namespace core {

void Bios::init(IScene &scene)
{
    (void)scene;
    std::cout << "BIOS init" << std::endl;
}

void Bios::update(IScene &scene, float dt)
{
    (void)scene;
    (void)dt;
    std::cout << "BIOS update" << std::endl;
}

void Bios::end(IScene &scene)
{
    std::cout << "BIOS end" << std::endl;
    (void)scene;
}

}

}
