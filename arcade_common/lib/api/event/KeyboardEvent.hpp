/*
** EPITECH PROJECT, 2021
** Arcade-Toulouse
** File description:
** Keyboard
*/

#ifndef KEYBOARD_HPP_
#define KEYBOARD_HPP_

#include "IEvent.hpp"

#define NCURSES_KEY_BACKSPACE 0407
#define NCURSES_KEY_RIGHT 0405
#define NCURSES_KEY_LEFT 0404
#define NCURSES_KEY_UP 0403
#define NCURSES_KEY_DOWN 0402
#define NCURSES_KEY_END 0550
#undef KEY_BACKSPACE
#undef KEY_RIGHT
#undef KEY_LEFT
#undef KEY_UP
#undef KEY_DOWN
#undef KEY_END

namespace arcade {

namespace event {

    enum class Key {
        KEY_ESCAPE,
        KEY_BACKSPACE,
        KEY_RIGHT,
        KEY_LEFT,
        KEY_UP,
        KEY_DOWN,
        KEY_SHIFT_LEFT,
        KEY_SHIFT_RIGHT,
        KEY_CTRL_LEFT,
        KEY_CTRL_RIGHT,
        KEY_ALT_LEFT,
        KEY_ALT_RIGHT,
        KEY_TAB,
        KEY_PAGE_UP,
        KEY_PAGE_DOWN,
        KEY_DELETE,
        KEY_INSER,
        KEY_END,
        KEY_SPACE,
        KEY_F1,
        KEY_F2,
        KEY_F3,
        KEY_F4,
        KEY_F5,
        KEY_F6,
        KEY_F7,
        KEY_F8,
        KEY_F9,
        KEY_F10,
        KEY_F11,
        KEY_F12,
        KEY_A = 65,
        KEY_B = 66,
        KEY_C = 67,
        KEY_D = 68,
        KEY_E = 69,
        KEY_F = 70,
        KEY_G = 71,
        KEY_H = 72,
        KEY_I = 73,
        KEY_J = 74,
        KEY_K = 75,
        KEY_L = 76,
        KEY_M = 77,
        KEY_N = 78,
        KEY_O = 79,
        KEY_P = 80,
        KEY_Q = 81,
        KEY_R = 82,
        KEY_S = 83,
        KEY_T = 84,
        KEY_U = 85,
        KEY_V = 86,
        KEY_W = 87,
        KEY_X = 88,
        KEY_Y = 89,
        KEY_Z = 90,
        KEY_1,
        KEY_2,
        KEY_3,
        KEY_4,
        KEY_5,
        KEY_6,
        KEY_7,
        KEY_8,
        KEY_9,
        KEY_0,
    };

    struct KeyboardEvent : public IEvent {
        Key key;
        enum { PRESSED, DOWN, RELEASED } action;
    };

}

}

#endif /* !KEYBOARD_HPP_ */
