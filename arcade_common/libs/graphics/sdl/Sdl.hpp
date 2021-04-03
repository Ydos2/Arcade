/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Sdl
*/

#ifndef LIB_SDL_HPP_
#define LIB_SDL_HPP_

#include "api/IGraphic.hpp"
#include <SDL2/SDL.h>

namespace arcade {

    class Sdl : lib::IGraphic {
        public:
            Sdl();
            ~Sdl();

            void init(IScene &scene) override;
            void update(IScene &scene, float dt) override;
            void end(IScene &scene) override;

        protected:
        private:
            SDL_Window *m_window;
            SDL_Renderer *m_renderer;
    };

}

#endif /* !LIB_SDL_HPP_ */
