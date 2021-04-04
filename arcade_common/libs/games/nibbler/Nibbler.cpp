/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include <iostream>

namespace arcade {

    void Nibbler::init(IScene &scene)
    {
        std::cout << "Nibbler init" << std::endl;
    }

    void Nibbler::update(IScene &scene, float dt)
    {
        std::cout << "Nibbler loop" << std::endl;
    }

    void Nibbler::end(IScene &scene)
    {
        std::cout << "Nibbler end" << std::endl;
    }

    void Nibbler::onKeyEvent(const event::KeyboardEvent& key)
    {

    }
    
    void Nibbler::onMouseEvent(const event::MouseEvent& mouse)
    {

    }

}