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
#include "api/event/MouseEvent.hpp"

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

    static event::KeyboardEvent pushKeyboardEvent(IScene &scene)
    {
        event::KeyboardEvent keyboardEvent;
        std::vector<int> keys;
        std::vector<int> oldKeys;
        int c;

        while ((c = getch()) != ERR)
            keys.push_back(c);
        for (int i = 0; i != keys.size(); i++) {
            keyboardEvent.key = event::Key::KEY_0; // TODO
            if (std::count(oldKeys.begin(), oldKeys.end(), keys[i]))
                keyboardEvent.action = event::KeyboardEvent::DOWN;
            else 
                keyboardEvent.action = event::KeyboardEvent::PRESSED;
            scene.pushEvent(keyboardEvent);
        }
        for (int i = 0; i != oldKeys.size(); i++) {
            keyboardEvent.key = event::Key::KEY_0; // TODO
            if (!std::count(keys.begin(), keys.end(), oldKeys[i]))
                keyboardEvent.action = event::KeyboardEvent::RELEASED;
            scene.pushEvent(keyboardEvent);
        }
        oldKeys = keys;
    }

    static event::MouseEvent pushMouseEvent(IScene &scene)
    {
        event::MouseEvent mouseEvent;

        scene.pushEvent(mouseEvent);
    }

    void NCurses::update(IScene &scene, float dt)
    {
        std::vector<std::reference_wrapper<IEntity>> sortedEntities;

        std::cout << "NCurses loop" << std::endl;        
        pushKeyboardEvent(scene);
        pushMouseEvent(scene);

        sortedEntities = getSortedEntities(scene);
        // Get vector of entities' sprites
        

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