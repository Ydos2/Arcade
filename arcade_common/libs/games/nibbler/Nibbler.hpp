/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include <vector>
#include "api/IGame.hpp"

namespace arcade {

    class Nibbler : public lib::IGame {

        struct map {
            size_t height;
            size_t width;
            std::vector<char> map;
        };

        public:
            Nibbler() = default;
            ~Nibbler() = default;

            void init(IScene &scene) override;
            void update(IScene &scene, float dt) override;
            void end(IScene &scene) override;

            void onKeyEvent(const event::KeyboardEvent& key) override;
            void onMouseEvent(const event::MouseEvent& mouse) override;

        private:
            void initMap(IScene &scene);
            void initSnake(IScene &scene);
            void initFood(IScene &scene);
            void moveFood(IScene &scene);
            void moveSnake(IScene &scene);

        private:
            std::vector<std::string> m_map;
            math::Vector2 m_mapDimensions;

            std::vector<math::Vector2> m_segmentPositions;
            size_t m_snakeLength;
            enum {UP, DOWN, LEFT, RIGHT} m_direction;
            
            math::Vector2 m_foodPosition;
    };

}

#endif /* !NIBBLER_HPP_ */
