/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** PacMan
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "api/IGame.hpp"

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
    };

}

#endif /* !PACMAN_HPP_ */
