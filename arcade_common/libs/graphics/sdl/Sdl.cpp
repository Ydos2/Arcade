/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Sdl
*/

#include "Sdl.hpp"
#include <iostream>

namespace arcade
{
    void Sdl::init(IScene &scene)
    {
        std::cout << "SDL init" << std::endl;
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
            exit(EXIT_FAILURE);
        }

        SDL_Window *pWindow{nullptr};
        SDL_Renderer *pRenderer{nullptr};

        if (SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &m_window, &m_renderer) < 0)
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
            SDL_Quit();
            exit(EXIT_FAILURE);
        }
    }

    void Sdl::update(IScene &scene, float dt)
    {
        SDL_Event events;
        bool isOpen{true};

        std::cout << "SDL loop" << std::endl;
        while (isOpen)
        {
            while (SDL_PollEvent(&events))
            {
                switch (events.type)
                {
                case SDL_QUIT:
                    isOpen = false;
                    break;
                }
            }

            SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
            SDL_RenderClear(m_renderer);
            SDL_RenderPresent(m_renderer);
        }
    }

    void Sdl::end(IScene &scene)
    {
        std::cout << "SDL end" << std::endl;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();

        exit(EXIT_SUCCESS);
    }

    bool Sdl::quitRequested() const
    {
    }
}