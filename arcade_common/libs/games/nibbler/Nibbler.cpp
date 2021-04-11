/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include <iostream>
#include <vector>

namespace arcade {

    static Nibbler::map getMap(std::string filepath) {
        
    }

    void Nibbler::init(IScene &scene)
    {
        std::cout << "Nibbler init" << std::endl;
        // Init map
            // Wall sprites (ascii + graphic)
            // Wall positions
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