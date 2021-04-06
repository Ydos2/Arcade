/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** NCurses
*/

#include <exception>
#include <algorithm>
#include <iostream>
#include <ncurses.h>
#include "NCurses.hpp"
#include "api/component/Transform.hpp"
#include "api/event/KeyboardEvent.hpp"

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

    static std::vector<std::reference_wrapper<IEntity>> getSortedEntities(
        IScene &scene)
    {
        std::vector<std::reference_wrapper<IEntity>> entities;

        scene.forEach([&](IEntity& currentEnt) {
            entities.push_back(currentEnt);
        });
        std::sort(entities.begin(), entities.end(), [](IEntity& a, IEntity& b) {
            component::Transform transformA;
            component::Transform transformB;

            a.forEach([&](component::IComponent& currentComp) {
                try {
                    transformA = dynamic_cast<component::Transform&>(currentComp);
                } catch (std::exception& e) {}
            });
            b.forEach([&](component::IComponent& currentComp) {
                try {
                    transformB = dynamic_cast<component::Transform&>(currentComp);
                } catch (std::exception& e) {}
            });
            return (transformA.position.z > transformB.position.z);
        });
        return (entities);
    }

    void NCurses::update(IScene &scene, float dt)
    {
        std::vector<std::reference_wrapper<IEntity>> sortedEntities;
        event::KeyboardEvent keyboardEvent;
        char input = 0;

        std::cout << "NCurses loop" << std::endl;

        // Get keyboard events
        input = getch();
        //scene.pushEvent(/**/);

        // Get mouse events
        //scene.pushEvent(/**/);

        sortedEntities = getSortedEntities(scene);

        // Get vector of entities' sprites
        // ?

        // Display entities' sprites

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
        curs_set(TRUE);
        endwin();
    }
}