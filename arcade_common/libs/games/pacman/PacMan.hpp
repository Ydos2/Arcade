/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** PacMan
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "../../../common/IGame.hpp"

namespace arcade {

    class PacMan : public lib::IGame {
        public:
            PacMan();
            ~PacMan();

            void init(Scene &scene) override;
            void update(Scene &scene, float dt) override;
            void end(Scene &scene) override;
        protected:
        private:
    };

}

#endif /* !PACMAN_HPP_ */
