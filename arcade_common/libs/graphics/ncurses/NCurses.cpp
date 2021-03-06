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
        mousemask(BUTTON1_PRESSED | BUTTON1_RELEASED | BUTTON1_CLICKED |
                  BUTTON2_PRESSED | BUTTON2_RELEASED | BUTTON2_CLICKED |
                  BUTTON3_PRESSED | BUTTON3_RELEASED | BUTTON3_CLICKED,
                  NULL);
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

    static event::Key ncursesKeyToArcadeKey(int ncursesKey)
    {
        std::vector<int> ncursesKeys = {
            KEY_EXIT, KEY_BACKSPACE, KEY_RIGHT, KEY_LEFT, KEY_UP, KEY_DOWN,
            0, // KEY_SHIFT_LEFT,
            0, // KEY_SHIFT_RIGHT,
            0, // KEY_CTRL_LEFT,
            0, // KEY_CTRL_RIGHT,
            0, // KEY_ALT_LEFT,
            0, // KEY_ALT_RIGHT,
            '\t', KEY_NPAGE, KEY_PPAGE, KEY_DC, KEY_IC, KEY_END, ' ', KEY_F(1),
            KEY_F(2), KEY_F(3), KEY_F(4), KEY_F(5), KEY_F(6), KEY_F(7), KEY_F(8),
            KEY_F(9), KEY_F(10), KEY_F(11), KEY_F(12), 'A','B','C','D','E','F',
            'G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W',
            'X','Y','Z','1','2','3','4','5','6','7','8','9','0'
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

    static void pushMouseEvent(IScene &scene)
    {
        event::MouseEvent mouseEvent;
        MEVENT nCursesMouseEvent;

        if (getmouse(&nCursesMouseEvent)) {
            mouseEvent.x = nCursesMouseEvent.x;
            mouseEvent.y = nCursesMouseEvent.y;
            switch (nCursesMouseEvent.bstate) {
                case BUTTON1_PRESSED :
                    mouseEvent.button = event::MouseEvent::MOUSE_PRIMARY;
                    mouseEvent.action = event::MouseEvent::DOWN;
                    break;
                case BUTTON1_RELEASED :
                    mouseEvent.button = event::MouseEvent::MOUSE_PRIMARY;
                    mouseEvent.action = event::MouseEvent::RELEASED;
                    break;
                case BUTTON1_CLICKED :
                    mouseEvent.button = event::MouseEvent::MOUSE_PRIMARY;
                    mouseEvent.action = event::MouseEvent::PRESSED;
                    break;
                case BUTTON2_PRESSED :
                    mouseEvent.button = event::MouseEvent::MOUSE_SECONDARY;
                    mouseEvent.action = event::MouseEvent::DOWN;
                    break;
                case BUTTON2_RELEASED :
                    mouseEvent.button = event::MouseEvent::MOUSE_SECONDARY;
                    mouseEvent.action = event::MouseEvent::RELEASED;
                    break;
                case BUTTON2_CLICKED :
                    mouseEvent.button = event::MouseEvent::MOUSE_SECONDARY;
                    mouseEvent.action = event::MouseEvent::PRESSED;
                    break;
                case BUTTON3_PRESSED :
                    mouseEvent.button = event::MouseEvent::MOUSE_AUXILIARY;
                    mouseEvent.action = event::MouseEvent::DOWN;
                    break;
                case BUTTON3_RELEASED :
                    mouseEvent.button = event::MouseEvent::MOUSE_AUXILIARY;
                    mouseEvent.action = event::MouseEvent::RELEASED;
                    break;
                case BUTTON3_CLICKED :
                    mouseEvent.button = event::MouseEvent::MOUSE_AUXILIARY;
                    mouseEvent.action = event::MouseEvent::PRESSED;
                    break;
                default:
                    mouseEvent.button = event::MouseEvent::MOUSE_AUXILIARY;
                    mouseEvent.action = event::MouseEvent::PRESSED;
                    break;
            }
        }
        scene.pushEvent(mouseEvent);
    }

    static void manageEvents(IScene &scene)
    {
        event::KeyboardEvent keyboardEvent;
        std::vector<int> keys;
        static std::vector<int> oldKeys;
        int c;

        while ((c = getch()) != ERR)
            keys.push_back(c);
        for (int key : keys) {
            if (key == KEY_MOUSE)
                pushMouseEvent(scene);
            else {
                keyboardEvent.key = ncursesKeyToArcadeKey(key);
                if (std::count(oldKeys.begin(), oldKeys.end(), key))
                    keyboardEvent.action = event::KeyboardEvent::DOWN;
                else 
                    keyboardEvent.action = event::KeyboardEvent::PRESSED;
                scene.pushEvent(keyboardEvent);
            }
        }
        for (int key : oldKeys) {
            if (key != KEY_MOUSE) {
                keyboardEvent.key =  ncursesKeyToArcadeKey(key);
                if (!std::count(keys.begin(), keys.end(), key))
                    keyboardEvent.action = event::KeyboardEvent::RELEASED;
                scene.pushEvent(keyboardEvent);
            }
        }
        oldKeys = keys;
    }

    static void displayAsciiSprite(component::AsciiSprite *sprite,
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

    static void displayText(component::Text *text,
                                component::Transform *transform)
    {
        int windowWidth = 0;
        int windowHeight = 0;
        int spriteX = 0;
        int spriteY = 0;

        getmaxyx(stdscr, windowHeight, windowWidth);
        spriteX = transform->position.x;
        spriteY = windowHeight - transform->position.y - 1;
        mvprintw(spriteY, spriteX, text->text.c_str());
    }

    void NCurses::update(IScene &scene, float dt)
    {
        std::vector<std::reference_wrapper<IEntity>> sortedEntities;
        component::Transform *transform;
        component::AsciiSprite *asciiSprite;
        component::Sound *sound;
        component::Text *text;

        manageEvents(scene);

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
            if (asciiSprite && transform)
                displayAsciiSprite(asciiSprite, transform);
            else if (text && transform)
                displayText(text, transform);
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