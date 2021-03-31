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
            PacMan();
            ~PacMan();

            void init(IScene &scene) override;
            void update(IScene &scene, float dt) override;
            void end(IScene &scene) override;
        protected:
        private:
    };

}

#endif /* !PACMAN_HPP_ */
