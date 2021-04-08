/*
** EPITECH PROJECT, 2021
** Arcade-Toulouse
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include "IComponent.hpp"
#include <vector>


namespace arcade {

/**
 * @brief An ARGB colour
 */
struct Color {
    char a;
    char r;
    char g;
    char b;
};

namespace component {

    /**
     * @brief Component representing a sprite made out of 32-bits ARGB pixels
     */
    struct Sprite : public IComponent {
        std::vector<Color> pixels;
        size_t width;
        size_t height;
    };

}

}

#endif /* !SPRITE_HPP_ */
