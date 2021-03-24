/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Sdl
*/

#ifndef LIB_SDL_HPP_
#define LIB_SDL_HPP_

#include "../../../common/IGraphic.hpp"

namespace arcade {

    class Sdl : lib::IGraphic {
        public:
            Sdl();
            ~Sdl();

            void init(Scene &scene) override;
            void update(Scene &scene, float dt) override;
            void end(Scene &scene) override;

        protected:
        private:
    };

}

#endif /* !LIB_SDL_HPP_ */
