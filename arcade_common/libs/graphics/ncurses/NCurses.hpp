/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** NCurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "api/IGraphic.hpp"

namespace arcade {

    class NCurses : lib::IGraphic {
        public:
            NCurses();
            ~NCurses();

            void init(IScene &scene) override;
            void update(IScene &scene, float dt) override;
            void end(IScene &scene) override;
        protected:
        private:
    };

}

#endif /* !NCURSES_HPP_ */
