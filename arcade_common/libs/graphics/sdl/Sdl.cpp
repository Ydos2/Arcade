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
#include "api/event/MouseEvent.hpp"

namespace arcade
{
    void Sdl::init(IScene &scene)
    {
        std::cout << "SDL init" << std::endl;
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
            // trow error
        }

        math::Vector2 windowSize = scene.getWindowSize();
        if (windowSize.x == 0 || windowSize.y == 0)
        {
            windowSize.x = 600;
            windowSize.y = 640;
        }

        if (SDL_CreateWindowAndRenderer(windowSize.x, windowSize.y, SDL_WINDOW_SHOWN, &m_window, &m_renderer) < 0)
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
            SDL_Quit();
            // trow error
        }
        //m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
        //SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_NONE);
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

    static event::Key sdlKeyToArcadeKey(char sdlKey)
    {
        std::vector<char> sdlKeys = {
            (char)SDLK_ESCAPE, (char)SDLK_BACKSPACE,
            (char)SDLK_RIGHT, (char)SDLK_LEFT,
            (char)SDLK_UP, (char)SDLK_DOWN,
            0, // KEY_SHIFT_LEFT,
            0, // KEY_SHIFT_RIGHT,
            0, // KEY_CTRL_LEFT,
            0, // KEY_CTRL_RIGHT,
            0, // KEY_ALT_LEFT,
            0, // KEY_ALT_RIGHT,
            '\t', (char)SDLK_PAGEUP, (char)SDLK_PAGEDOWN, (char)SDLK_DELETE, (char)SDLK_INSERT,
            (char)SDLK_END, ' ', (char)SDLK_F1, (char)SDLK_F2,
            (char)SDLK_F3, (char)SDLK_F4, (char)SDLK_F5, (char)SDLK_F6,
            (char)SDLK_F7, (char)SDLK_F8, (char)SDLK_F9, (char)SDLK_F10,
            (char)SDLK_F11, (char)SDLK_F12, 'a','b','c','d','e','f','g','h',
            'i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y',
            'z','1','2','3','4','5','6','7','8','9','0'
        };

        std::vector<event::Key> arcadeKeys = {
            event::Key::KEY_ESCAPE,
            event::Key::KEY_BACK_SPACE,
            event::Key::KEY_ARROW_RIGHT,
            event::Key::KEY_ARROW_LEFT,
            event::Key::KEY_ARROW_UP,
            event::Key::KEY_ARROW_DOWN,
            event::Key::KEY_SHIFT_LEFT,
            event::Key::KEY_SHIFT_RIGHT,
            event::Key::KEY_CTRL_LEFT,
            event::Key::KEY_CTRL_RIGHT,
            event::Key::KEY_ALT_LEFT,
            event::Key::KEY_ALT_RIGHT,
            event::Key::KEY_TAB,
            event::Key::KEY_PAGE_UP,
            event::Key::KEY_PAGE_DOWN,
            event::Key::KEY_DELETE,
            event::Key::KEY_INSERT,
            event::Key::KEY_END_FILE,
            event::Key::KEY_SPACE,
            event::Key::KEY_F1,
            event::Key::KEY_F2,
            event::Key::KEY_F3,
            event::Key::KEY_F4,
            event::Key::KEY_F5,
            event::Key::KEY_F6,
            event::Key::KEY_F7,
            event::Key::KEY_F8,
            event::Key::KEY_F9,
            event::Key::KEY_F10,
            event::Key::KEY_F11,
            event::Key::KEY_F12,
            event::Key::KEY_A,
            event::Key::KEY_B,
            event::Key::KEY_C,
            event::Key::KEY_D,
            event::Key::KEY_E,
            event::Key::KEY_F,
            event::Key::KEY_G,
            event::Key::KEY_H,
            event::Key::KEY_I,
            event::Key::KEY_J,
            event::Key::KEY_K,
            event::Key::KEY_L,
            event::Key::KEY_M,
            event::Key::KEY_N,
            event::Key::KEY_O,
            event::Key::KEY_P,
            event::Key::KEY_Q,
            event::Key::KEY_R,
            event::Key::KEY_S,
            event::Key::KEY_T,
            event::Key::KEY_U,
            event::Key::KEY_V,
            event::Key::KEY_W,
            event::Key::KEY_X,
            event::Key::KEY_Y,
            event::Key::KEY_Z,
            event::Key::KEY_1,
            event::Key::KEY_2,
            event::Key::KEY_3,
            event::Key::KEY_4,
            event::Key::KEY_5,
            event::Key::KEY_6,
            event::Key::KEY_7,
            event::Key::KEY_8,
            event::Key::KEY_9,
            event::Key::KEY_0,
        };
    
        for (size_t i = 0; i != sdlKeys.size(); i++) {
            if (sdlKeys[i] == sdlKey)
                return (arcadeKeys[i]);
        }
        return (event::Key::KEY_ESCAPE);
    }

    static void SpriteRenderer(component::Sprite *spriteComp, component::Transform *transformComp,
        SDL_Renderer *m_renderer)
    {
        //std::cout << "Sprite" << std::endl;
        SDL_Rect rect;
        rect.x = int(transformComp->position.x * 16);
        rect.y = int(transformComp->position.y * 16);
        rect.w = spriteComp->width;
        rect.h = spriteComp->height;
        SDL_Surface *surface = SDL_CreateRGBSurfaceFrom(spriteComp->pixels.data(),
            spriteComp->width, spriteComp->height, 32, 4 * spriteComp->width,
            0, 0, 0, 255);
        SDL_Texture *textureSdl = SDL_CreateTextureFromSurface(m_renderer, surface);

        SDL_RenderCopy(m_renderer, textureSdl, NULL, &rect);
        SDL_SetRenderDrawColor(m_renderer, 47, 97, 0, 255);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(textureSdl);
    }

    static void TextRenderer(component::Text *textComp, component::Transform *transformComp,
        SDL_Renderer *m_renderer)
    {
        //std::cout << "Text" << std::endl;
        TTF_Font* Sans = TTF_OpenFont("res/font/OpenSans-Regular.ttf", 24);
        SDL_Color White = {255, 255, 255, 255};
        SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, textComp->text.c_str(), White);
        SDL_Texture* text = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);

        SDL_Rect rect;
        rect.x = transformComp->position.x; 
        rect.y = transformComp->position.y;
        rect.w = transformComp->scale.x;
        rect.h = transformComp->scale.y;

        SDL_RenderCopy(m_renderer, text, NULL, &rect);
        SDL_FreeSurface(surfaceMessage);
        SDL_DestroyTexture(text);
        //SDL_SetRenderDrawColor(m_renderer, 47, 97, 0, 255);
    }

    static event::MouseEvent mouseManagement(SDL_MouseButtonEvent button)
    {
        event::MouseEvent mouseEvent;

        switch (button.button) {
            case SDL_BUTTON_LEFT:
                mouseEvent.button = event::MouseEvent::MOUSE_PRIMARY;
                return (mouseEvent);
                break;
            case SDL_BUTTON_RIGHT:
                mouseEvent.button = event::MouseEvent::MOUSE_SECONDARY;
                return (mouseEvent);
                break;
            case SDL_BUTTON_MIDDLE:
                mouseEvent.button = event::MouseEvent::MOUSE_AUXILIARY;
                return (mouseEvent);
                break;
        }
        mouseEvent.button = event::MouseEvent::MOUSE_PRIMARY;
        return (mouseEvent);
    }

    void Sdl::update(IScene &scene, float dt)
    {
        std::vector<std::reference_wrapper<IEntity>> sortedEntities;
        event::KeyboardEvent keyboardEvent;
        event::MouseEvent mouseEvent;
        SDL_Event events;

        (void)dt;
        //std::cout << "SDL loop" << std::endl;
        
        /* SDL Events */
        while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_QUIT:
                m_isOpen = false;
                keyboardEvent.action = event::KeyboardEvent::PRESSED;
                keyboardEvent.key = event::Key::KEY_ESCAPE;
                scene.pushEvent(keyboardEvent);
                break;
            case SDL_KEYDOWN:
                //std::cout << (unsigned long)sdlKeyToArcadeKey(events.key.keysym.sym) << std::endl;
                keyboardEvent.action = event::KeyboardEvent::DOWN;
                keyboardEvent.key = sdlKeyToArcadeKey(events.key.keysym.sym);
                scene.pushEvent(keyboardEvent);
                break;
            case SDL_KEYUP:
                keyboardEvent.action = event::KeyboardEvent::RELEASED;
                keyboardEvent.key = sdlKeyToArcadeKey(events.key.keysym.sym);
                scene.pushEvent(keyboardEvent);
                break;
            case SDL_MOUSEBUTTONDOWN:
                mouseEvent.action = event::MouseEvent::DOWN;
                mouseEvent.button = mouseManagement(events.button).button;
                scene.pushEvent(keyboardEvent);
                break;
            case SDL_MOUSEBUTTONUP:
                mouseEvent.action = event::MouseEvent::RELEASED;
                mouseEvent.button = mouseManagement(events.button).button;
                break;
            }
        }

        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
        if (SDL_RenderClear(m_renderer))
            std::cout <<  __FILE__ << ":" << __LINE__ << "Warning: Could not clear screen renderer, error: " << SDL_GetError() << std::endl;

        sortedEntities = getSortedEntities(scene);

        component::AsciiSprite *asciiSpriteComp = nullptr;
        component::Sprite *spriteComp = nullptr;
        component::Transform *transformComp = nullptr;
        component::Sound *soundComp = nullptr;
        component::Text *textComp = nullptr;

        for (size_t i = 0; i < sortedEntities.size(); i++)
        {
            sortedEntities[i].get().forEach([&](arcade::component::IComponent& comp)
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

            if (spriteComp != nullptr && transformComp != nullptr)
                SpriteRenderer(spriteComp, transformComp, m_renderer);
            else if (textComp != nullptr && transformComp != nullptr)
                TextRenderer(textComp, transformComp, m_renderer);
            
            asciiSpriteComp = nullptr;
            spriteComp = nullptr;
            transformComp = nullptr;
            soundComp = nullptr;
            textComp = nullptr;
        }

        SDL_RenderPresent(m_renderer);
    }

    void Sdl::end(IScene &scene)
    {
        std::cout << "SDL end" << std::endl;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        (void)scene;
    }

    bool Sdl::quitRequested() const
    {
        //std::cout << "Quit request" << std::endl;
        if (m_isOpen)
            return (false);
        return (true);
    }
}