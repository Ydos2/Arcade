/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** SceneManager
*/

#include <string>
#include "SceneManager.hpp"
#include <iostream>

namespace arcade {

namespace scene {

    // set scene active
    Scene *SceneManager::setActive(std::string name)
    {
        try {
            m_current = &(m_scenes.at(name));
        } catch (std::exception &e) {
            std::cerr << "The scene \"" << name << "\" does not exist." << std::endl;
        }
        return m_current;
    }

    Scene *SceneManager::getCurrent() const
    {
        return (m_current);
    }

    Scene *SceneManager::get(std::string name)
    {
        try {
            return &(m_scenes.at(name));
        } catch (std::exception &e) {
            std::cerr << "The scene \"" << name << "\" does not exist." << std::endl;
        }
        return nullptr;
    }

    void SceneManager::add(Scene newScene, std::string name)
    {
        this->m_scenes.insert(std::make_pair(name, newScene));
    }

    void SceneManager::close(std::string name)
    {
        try {
            m_scenes.at(name).close();
            m_scenes.erase(name);
        } catch (std::exception &e) {
            std::cerr << "The scene \"" << name << "\" does not exist." << std::endl;
        }
    }

}

}
