/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** PacMan
*/

#include <iostream>
#include "PacMan.hpp"
#include "api/component/Sprite.hpp"
#include "api/component/Text.hpp"
#include "api/component/Transform.hpp"
#include "api/event/KeyboardEvent.hpp"
#include "api/event/MouseEvent.hpp"

namespace arcade {

    void PacMan::init(IScene &scene)
    {
        arcade::IEntity &square = scene.newEntity("square");
        arcade::component::Sprite imgTest;
        arcade::component::Text textTest;
        arcade::component::Transform transformTest;

        scene.setWindowSize(1250, 800);
        std::cout << "PacMan init" << std::endl;

        imgTest.height = 10;
        imgTest.width = 10;
        imgTest.pixels = {
            Color {(char)255, (char)255, (char)255, (char)255},
            Color {(char)255, (char)255, (char)255, (char)255},
            Color {(char)255, (char)255, (char)255, (char)255},
            Color {(char)255, (char)255, (char)255, (char)255},
            Color {(char)255, (char)255, (char)255, (char)255},
            Color {(char)255, (char)255, (char)255, (char)255},
            Color {(char)255, (char)255, (char)255, (char)255},
            Color {(char)255, (char)255, (char)255, (char)255},
            Color {(char)255, (char)255, (char)255, (char)255},
            Color {(char)255, (char)255, (char)255, (char)255}
        };

        transformTest.position.x = 0;
        transformTest.position.y = 0;
        transformTest.position.z = 0;

        textTest.text = "lol";

        square.addComponent(imgTest);
        square.addComponent(transformTest);
    }

    void PacMan::update(IScene &scene, float dt)
    {
        std::cout << "PacMan loop" << std::endl;
        (void)scene;
        (void)dt;
    }

    void PacMan::end(IScene &scene)
    {
        std::cout << "PacMan end" << std::endl;
        (void)scene;
    }

    void PacMan::onKeyEvent(const event::KeyboardEvent& key)
    {
        if (key.action == key.DOWN)
        {
            std::cout << (unsigned long)key.key << std::endl;
            switch (key.key)
            {
            case event::Key::KEY_ARROW_UP:
                std::cout << "!" << std::endl;
                m_direction = math::Vector3 {0, -1, 0};
                break;
            case event::Key::KEY_ARROW_DOWN:
                std::cout << "!" << std::endl;
                m_direction = math::Vector3 {0, 1, 0};
                break;
            case event::Key::KEY_ARROW_LEFT:
                m_direction = math::Vector3 {-1, 0, 0};
                break;
            case event::Key::KEY_ARROW_RIGHT:
                m_direction = math::Vector3 {1, 0, 0};
                break;
            default:
                std::cout << "?" << std::endl;
                break;
            }
        }
    }
    
    void PacMan::onMouseEvent(const event::MouseEvent& mouse)
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
        else if (mouse.action == mouse.RELEASED)
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