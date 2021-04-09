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
        m_window.create(sf::VideoMode(800, 600), "arcade");
        m_window.setVerticalSyncEnabled(true);
    }

    void Sfml::update(IScene &scene, float dt)
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }
    }

    void Sfml::end(IScene &scene)
    {
        std::cout << "Sfml end" << std::endl;
    }

    bool Sfml::quitRequested() const
    {
        if (m_window.isOpen())
            return false;
        return true;
    }
}