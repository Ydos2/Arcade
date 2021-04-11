/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** PacMan
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "api/IGame.hpp"
#include "api/Vector3.hpp"

namespace arcade {

    class PacMan : public lib::IGame {
        public:
            PacMan() = default;
            ~PacMan() = default;

            void init(IScene &scene) override;
            void update(IScene &scene, float dt) override;
            void end(IScene &scene) override;

            void onKeyEvent(const event::KeyboardEvent& key) override;
            void onMouseEvent(const event::MouseEvent& mouse) override;

        protected:
        private:
            arcade::math::Vector3 m_direction;
            std::vector<std::vector<int>> mapId;
            std::vector<std::vector<int>> m_savedMapId;
            float m_score;
            float m_timePower;
            float m_timeGhostStart;
            float m_timeGhost;
            float m_winTime;
    };

}

#endif /* !PACMAN_HPP_ */
