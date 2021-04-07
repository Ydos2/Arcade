/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Sdl
*/

#include <exception>
#include <algorithm>
#include <iostream>
#include "Sdl.hpp"
#include "api/component/Transform.hpp"
#include "api/component/Sprite.hpp"
#include "api/component/AsciiSprite.hpp"
#include "api/component/Sound.hpp"
#include "api/component/Text.hpp"
#include "api/event/KeyboardEvent.hpp"

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
        m_isOpen = true;
    }

    static std::vector<std::reference_wrapper<IEntity>> getSortedEntities(
        IScene &scene)
    {
        std::vector<std::reference_wrapper<IEntity>> entities;

        scene.forEach([&](IEntity& currentEnt) {
            entities.push_back(currentEnt);
        });
        std::sort(entities.begin(), entities.end(), [](IEntity& a, IEntity& b) {
            component::Transform transformA;
            component::Transform transformB;

            a.forEach([&](component::IComponent& currentComp) {
                try {
                    transformA = dynamic_cast<component::Transform&>(currentComp);
                } catch (std::exception& e) {}
            });
            b.forEach([&](component::IComponent& currentComp) {
                try {
                    transformB = dynamic_cast<component::Transform&>(currentComp);
                } catch (std::exception& e) {}
            });
            return (transformA.position.z > transformB.position.z);
        });
        return (entities);
    }

    void Sdl::update(IScene &scene, float dt)
    {
        std::vector<std::reference_wrapper<IEntity>> sortedEntities;
        event::KeyboardEvent keyboardEvent;
        SDL_Event events;

        (void)dt;
        std::cout << "SDL loop" << std::endl;
        
        /* SDL Events */
        while (SDL_PollEvent(&events))
        {
            // C'est un exemple pour voir si ça marche pas de panique SVP
            switch (events.type)
            {
            case SDL_QUIT:
                m_isOpen = false;
                keyboardEvent.action = event::KeyboardEvent::PRESSED;
                keyboardEvent.key = event::Key::KEY_ESCAPE;
                scene.pushEvent(keyboardEvent);
                break;
            case SDL_SCANCODE_AC_BACK:
                keyboardEvent.action = event::KeyboardEvent::PRESSED;
                keyboardEvent.key = event::Key::KEY_DELETE;
                scene.pushEvent(keyboardEvent);
                break;
            }
        }

        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
        if(SDL_RenderClear(m_renderer))
            std::cout <<  __FILE__ << ":" << __LINE__ << "Warning: Could not clear screen renderer, error: " << SDL_GetError() << std::endl;

        sortedEntities = getSortedEntities(scene);
        component::AsciiSprite *asciiSpriteComp;
        component::Sprite *spriteComp;
        component::Transform *transformComp;
        component::Sound *soundComp;
        component::Text *textComp;

        sortedEntities[0].get().forEach([&](arcade::component::IComponent& comp)
        {
            if (auto ptr = dynamic_cast<component::AsciiSprite*>(&comp))
                asciiSpriteComp = ptr;
            else if (auto ptr = dynamic_cast<component::Sprite*>(&comp))
                spriteComp = ptr;
            else if (auto ptr = dynamic_cast<component::Transform*>(&comp))
                transformComp = ptr;
            else if (auto ptr = dynamic_cast<component::Sound*>(&comp))
                soundComp = ptr;
            else if (auto ptr = dynamic_cast<component::Text*>(&comp))
                textComp = ptr;
        });

        if (spriteComp && transformComp) {
            SDL_Rect rect;
            rect.x = int(transformComp->position.x);
            rect.y = int(transformComp->position.y);
            rect.w = spriteComp->width;
            rect.h = spriteComp->height;
            SDL_Surface *surface = SDL_CreateRGBSurfaceFrom(spriteComp->pixels.data(),
                spriteComp->width, spriteComp->height, 32, 4 * spriteComp->width,
                0, 0, 0, 255);
            SDL_Texture *textureSdl = SDL_CreateTextureFromSurface(m_renderer, surface);

            SDL_RenderCopy(m_renderer, textureSdl, NULL, &rect);
            SDL_SetRenderDrawColor(m_renderer, 47, 97, 0, 255);
            SDL_FreeSurface(surface);
        }

        SDL_RenderPresent(m_renderer);
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
        std::cout << "Quit request" << std::endl;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        std::cout << "!" << std::endl;
        if (m_isOpen)
            return (false);
        return (true);
        // if ça tourne = false
        // else ça tourne pas = true
    }
}