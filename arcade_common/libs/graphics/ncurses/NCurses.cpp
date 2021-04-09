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
#include "api/component/Sprite.hpp"
#include "api/component/AsciiSprite.hpp"
#include "api/component/Sound.hpp"
#include "api/component/Text.hpp"
#include "api/event/KeyboardEvent.hpp"
#include "api/event/MouseEvent.hpp"

namespace arcade
{

    void NCurses::init(IScene &scene)
    {
        (void)scene;
        initscr();
        nodelay(stdscr, TRUE);
        raw();
        noecho();
        keypad(stdscr, TRUE);
        curs_set(0);
        start_color();
        m_isOpen = true;
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
            (char)KEY_RIGHT, (char)KEY_LEFT,
            (char)KEY_UP, (char)KEY_DOWN,
            0, // KEY_SHIFT_LEFT,
            0, // KEY_SHIFT_RIGHT,
            0, // KEY_CTRL_LEFT,
            0, // KEY_CTRL_RIGHT,
            0, // KEY_ALT_LEFT,
            0, // KEY_ALT_RIGHT,
            '\t', (char)KEY_NPAGE, (char)KEY_PPAGE, (char)KEY_DC, (char)KEY_IC,
            (char)KEY_END, ' ', (char)KEY_F(1), (char)KEY_F(2),
            (char)KEY_F(3), (char)KEY_F(4), (char)KEY_F(5), (char)KEY_F(6),
            (char)KEY_F(7), (char)KEY_F(8), (char)KEY_F(9), (char)KEY_F(10),
            (char)KEY_F(11), (char)KEY_F(12), 'A','B','C','D','E','F','G','H',
            'I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y',
            'Z','1','2','3','4','5','6','7','8','9','0'
        };

        std::vector<event::Key> arcadeKeys = {
            event::Key::KEY_ESCAPE,
            event::Key::KEY_BACK_SPACE,
            event::Key::KEY_ARROW_RIGHT,
            event::Key::KEY_ARROW_LEFT,
            event::Key::KEY_ARROW_UP,
            event::Key::KEY_ARROW_DOWN,
            event::Key::KEY_SHIFT_LEFT,
            event::Key::KEY_SHIFT_RIGHT,
            event::Key::KEY_CTRL_LEFT,
            event::Key::KEY_CTRL_RIGHT,
            event::Key::KEY_ALT_LEFT,
            event::Key::KEY_ALT_RIGHT,
            event::Key::KEY_TAB,
            event::Key::KEY_PAGE_UP,
            event::Key::KEY_PAGE_DOWN,
            event::Key::KEY_DELETE,
            event::Key::KEY_INSERT,
            event::Key::KEY_END_FILE,
            event::Key::KEY_SPACE,
            event::Key::KEY_F1,
            event::Key::KEY_F2,
            event::Key::KEY_F3,
            event::Key::KEY_F4,
            event::Key::KEY_F5,
            event::Key::KEY_F6,
            event::Key::KEY_F7,
            event::Key::KEY_F8,
            event::Key::KEY_F9,
            event::Key::KEY_F10,
            event::Key::KEY_F11,
            event::Key::KEY_F12,
            event::Key::KEY_A,
            event::Key::KEY_B,
            event::Key::KEY_C,
            event::Key::KEY_D,
            event::Key::KEY_E,
            event::Key::KEY_F,
            event::Key::KEY_G,
            event::Key::KEY_H,
            event::Key::KEY_I,
            event::Key::KEY_J,
            event::Key::KEY_K,
            event::Key::KEY_L,
            event::Key::KEY_M,
            event::Key::KEY_N,
            event::Key::KEY_O,
            event::Key::KEY_P,
            event::Key::KEY_Q,
            event::Key::KEY_R,
            event::Key::KEY_S,
            event::Key::KEY_T,
            event::Key::KEY_U,
            event::Key::KEY_V,
            event::Key::KEY_W,
            event::Key::KEY_X,
            event::Key::KEY_Y,
            event::Key::KEY_Z,
            event::Key::KEY_1,
            event::Key::KEY_2,
            event::Key::KEY_3,
            event::Key::KEY_4,
            event::Key::KEY_5,
            event::Key::KEY_6,
            event::Key::KEY_7,
            event::Key::KEY_8,
            event::Key::KEY_9,
            event::Key::KEY_0,
        };

        for (size_t i = 0; i != ncursesKeys.size(); i++) {
            if (ncursesKeys[i] == ncursesKey)
                return (arcadeKeys[i]);
        }
        return (event::Key::KEY_ESCAPE);
    }

    static void pushKeyboardEvent(IScene &scene)
    {
        event::KeyboardEvent keyboardEvent;
        std::vector<char> keys;
        static std::vector<char> oldKeys;
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

    static void displayEntity(component::AsciiSprite *sprite,
                                component::Transform *transform)
    {
        int windowWidth = 0;
        int windowHeight = 0;
        int spriteX = 0;
        int spriteY = 0;

        getmaxyx(stdscr, windowHeight, windowWidth);
        spriteX = transform->position.x;
        spriteY = windowHeight - transform->position.y - sprite->height;
        for (size_t i = 0; i < sprite->height; i++) {
            for (size_t j = 0; j < sprite->width; j++) {
                std::vector<char> vectorSprite = *(sprite->sprite.get());
                mvaddch(
                    spriteY + i,
                    spriteX + j,
                    vectorSprite[i * sprite->width + j]
                );
            }
        }
    }

    void NCurses::update(IScene &scene, float dt)
    {
        std::vector<std::reference_wrapper<IEntity>> sortedEntities;
        component::Transform *transform;
        component::AsciiSprite *asciiSprite;
        component::Sound *sound;
        component::Text *text;

        pushKeyboardEvent(scene);
        pushMouseEvent(scene);

        (void)dt;
        sortedEntities = getSortedEntities(scene);
        for (std::reference_wrapper<IEntity> entity : sortedEntities) {
            entity.get().forEach([&](arcade::component::IComponent& component) {
                if (auto ptr = dynamic_cast<component::AsciiSprite*>(&component))
                    asciiSprite = ptr;
                else if (auto ptr = dynamic_cast<component::Transform*>(&component))
                    transform = ptr;
                else if (auto ptr = dynamic_cast<component::Sound*>(&component))
                    sound = ptr;
                else if (auto ptr = dynamic_cast<component::Text*>(&component))
                    text = ptr;
            });
            displayEntity(asciiSprite, transform);
            // TODO: display text, manage sound
            refresh();
        }
    }

    void NCurses::end(IScene &scene)
    {
        (void)scene;
        curs_set(TRUE);
        endwin();
    }

    bool NCurses::quitRequested() const
    {
        return (false);
    }
}