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

    static event::Key ncursesKeyToArcadeKey(char ncursesKey)
    {
        std::vector<char> ncursesKeys = {
            (char)KEY_EXIT, (char)KEY_BACKSPACE,
            (char)KEY_RIGHT, (char)KEY_LEFT, (char)KEY_UP, (char)KEY_DOWN,
            0, // KEY_SHIFT_LEFT,
            0, // KEY_SHIFT_RIGHT,
            0, // KEY_CTRL_LEFT,
            0, // KEY_CTRL_RIGHT,
            0, // KEY_ALT_LEFT,
            0, // KEY_ALT_RIGHT,
            '\t', (char)KEY_NPAGE, (char)KEY_PPAGE, (char)KEY_DC, (char)KEY_IC,
            (char)KEY_END, ' ', (char)KEY_F(1), (char)KEY_F(2), (char)KEY_F(3),
            (char)KEY_F(4), (char)KEY_F(5), (char)KEY_F(6), (char)KEY_F(7),
            (char)KEY_F(8), (char)KEY_F(9), (char)KEY_F(10), (char)KEY_F(11),
            (char)KEY_F(12), 'A','B','C','D','E','F','G','H','I','J','K','L',
            'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3',
            '4','5','6','7','8','9','0'
        };

        std::vector<event::Key> arcadeKeys(67);
        int i = -1;
        std::generate(arcadeKeys.begin(), arcadeKeys.end(), [&]() {
            i++;
            if (i < 32)
                return (i);
            return (i + 33);
        });

        for (auto i = 0; i != ncursesKeys.size(); i++) {
            if (ncursesKeys[i] == ncursesKey)
                return (arcadeKeys[i]);
        }
        return (event::Key::KEY_ESCAPE);
    }

    static void pushKeyboardEvent(IScene &scene)
    {
        event::KeyboardEvent keyboardEvent;
        std::vector<char> keys;
        std::vector<char> oldKeys;
        char c;

        while ((c = getch()) != ERR)
            keys.push_back(c);
        for (char key : keys) {
            keyboardEvent.key = ncursesKeyToArcadeKey(key);
            if (std::count(oldKeys.begin(), oldKeys.end(), key))
                keyboardEvent.action = event::KeyboardEvent::DOWN;
            else 
                keyboardEvent.action = event::KeyboardEvent::PRESSED;
            scene.pushEvent(keyboardEvent);
        }
        for (char key : oldKeys) {
            keyboardEvent.key =  ncursesKeyToArcadeKey(key);
            if (!std::count(keys.begin(), keys.end(), key))
                keyboardEvent.action = event::KeyboardEvent::RELEASED;
            scene.pushEvent(keyboardEvent);
        }
        oldKeys = keys;
    }

    static void pushMouseEvent(IScene &scene)
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

        (void)dt;
        sortedEntities = getSortedEntities(scene);
        // Get vector of entities' sprites
        

        // Display entities' sprites

    }

    void NCurses::end(IScene &scene)
    {
        (void)scene;
        std::cout << "NCurses end" << std::endl;
        curs_set(TRUE);
        endwin();
    }

    bool NCurses::quitRequested() const
    {
        std::cout << "Quit request" << std::endl;
        curs_set(TRUE);
        endwin();
        return (true); // TODO
    }
}