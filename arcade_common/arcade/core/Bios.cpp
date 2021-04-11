/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Bios
*/

#include "Bios.hpp"
#include <iostream>
#include "api/component/Sprite.hpp"
#include "api/component/Transform.hpp"
#include "api/event/KeyboardEvent.hpp"
#include "api/event/MouseEvent.hpp"

namespace arcade
{

    namespace core
    {

        void Bios::init(IScene &scene)
        {
            std::cout << "BIOS init" << std::endl;
        }

        void Bios::update(IScene &scene, float dt)
        {
            (void)scene;
            (void)dt;
            std::cout << "BIOS update" << std::endl;
        }

        void Bios::end(IScene &scene)
        {
            std::cout << "BIOS end" << std::endl;
            (void)scene;
        }

        void Bios::onKeyEvent(const event::KeyboardEvent& key)
        {
        if (key.action == key.DOWN)
        {
            std::cout << (unsigned long)key.key << std::endl;
            switch (key.key)
            {
            case event::Key::KEY_ARROW_UP:
                std::cout << "!" << std::endl;
                break;
            case event::Key::KEY_ARROW_DOWN:
                std::cout << "!" << std::endl;
                break;
            case event::Key::KEY_ARROW_LEFT:
                break;
            case event::Key::KEY_ARROW_RIGHT:
                break;
            default:
                std::cout << "?" << std::endl;
                break;
            }
        }

        }

        void Bios::onMouseEvent(const event::MouseEvent& mouse)
        {
            if (mouse.action == mouse.DOWN)
            {
                switch (mouse.button)
                {
                case mouse.MOUSE_PRIMARY:
                    std::cout << "!" << std::endl;
                    break;
                case mouse.MOUSE_SECONDARY:
                    // action
                    break;
                case mouse.MOUSE_AUXILIARY:
                    // action
                    break;
                default:
                    break;
                }
            }
        }

    }

}
