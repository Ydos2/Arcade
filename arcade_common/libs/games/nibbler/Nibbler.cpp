/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Nibbler
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Nibbler.hpp"
#include "api/component/Sprite.hpp"
#include "api/component/AsciiSprite.hpp"
#include "api/component/Transform.hpp"
#include "api/event/KeyboardEvent.hpp"

namespace arcade {

    static void initMap(IScene &scene)
    {
        arcade::IEntity &wall = scene.newEntity("wall");
        arcade::component::Sprite wallSprite;
        arcade::component::AsciiSprite wallAsciiSprite;
        arcade::component::Transform wallTransform;

        std::ifstream fileStream("res/maps/map1");
        std::string line;
        if (!fileStream)
            return;

        for (size_t row = 0; getline(fileStream, line); row++) {
            for (size_t col; char c = line[col]; col++) {
                if (c != ' ' && c != '\n') {
                    wallAsciiSprite.height = 1;
                    wallAsciiSprite.width = 1;
                    std::vector<char> vector = {c};
                    std::shared_ptr<std::vector<char>> vectorPtr(&vector);
                    wallAsciiSprite.sprite = vectorPtr;

                    wallSprite.height = 1;
                    wallSprite.width = 1;
                    wallSprite.pixels = {
                        Color {(char)255, (char)255, (char)255, (char)255}
                    };

                    wallTransform.position = {col, row, 0};

                    wall.addComponent(wallAsciiSprite);
                    wall.addComponent(wallSprite);
                    wall.addComponent(wallTransform);
                }
            }
        }
    }

    static void initSnake(IScene &scene)
    {
        arcade::component::Sprite sprite;
        arcade::component::AsciiSprite asciiSprite;
        arcade::component::Transform headTransform;
        arcade::IEntity &head = scene.newEntity("head");

        sprite.height = 1;
        sprite.width = 1;
        sprite.pixels = {
            Color {(char)255, (char)0, (char)0, (char)255}
        };

        asciiSprite.height = 1;
        asciiSprite.width = 1;
        std::vector<char> vector = {'O'};
        std::shared_ptr<std::vector<char>> vectorPtr(&vector);
        asciiSprite.sprite = vectorPtr;

        headTransform.position = {14, 7, 1};

        head.addComponent(asciiSprite);
        head.addComponent(sprite);
        head.addComponent(headTransform);

        for (size_t i = 0; i < 3; i++) {
            arcade::component::Transform tailTransform;
            arcade::IEntity &tail = scene.newEntity("tail" + std::to_string(i));
            
            tailTransform.position = {14, 7 - (i + 1), 1};

            tail.addComponent(asciiSprite);
            tail.addComponent(sprite);
            tail.addComponent(tailTransform);
        }
    }

    void Nibbler::init(IScene &scene)
    {
        std::cout << "Nibbler init" << std::endl;

        initMap(scene);
        initSnake(scene);

        // Init snake (4 segments)
            // Position of every segment
            // Its direction
            // Its speed ?
            


        // Init food
            // Its position
            // Its sprite
    }

    void Nibbler::update(IScene &scene, float dt)
    {
        std::cout << "Nibbler loop" << std::endl;
        // Make food appear if there is none

        // Make the snake eat and grow if it's on food
            // Remove the food from entities if it's just been eaten
            // Make the snake die if it just grew and is too big

        // Manage events
            // Change snake's direction if needed
            // Other events: pause, quit, etc ?

        // Make the snake move forward
            // Make the snake die if it hit a wall or itself
    }

    void Nibbler::end(IScene &scene)
    {
        std::cout << "Nibbler end" << std::endl;
    }

    void Nibbler::onKeyEvent(const event::KeyboardEvent& key)
    {
        // Change direction if a valid key has been pressed / released / is down
    }
    
    void Nibbler::onMouseEvent(const event::MouseEvent& mouse)
    {

    }

}