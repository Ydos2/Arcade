/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** NCurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "../../../common/IGraphic.hpp"

namespace arcade {

    class NCurses : lib::IGraphic {
        public:
            NCurses();
            ~NCurses();

            void init(Scene &scene) override;
            void update(Scene &scene, float dt) override;
            void end(Scene &scene) override;
        protected:
        private:
    };

}

#endif /* !NCURSES_HPP_ */
