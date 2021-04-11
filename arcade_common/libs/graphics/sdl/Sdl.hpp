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
#include <SDL2/SDL_ttf.h>

namespace arcade {

    class Sdl : lib::IGraphic {
        public:
            Sdl() = default;
            ~Sdl() = default;

            void init(IScene &scene) override;
            void update(IScene &scene, float dt) override;
            void end(IScene &scene) override;

            bool quitRequested() const override;

        protected:
        private:
            SDL_Window *m_window;
            SDL_Renderer *m_renderer;
            SDL_Texture *m_texture;
            bool m_isOpen;
    };

}

#endif /* !LIB_SDL_HPP_ */
