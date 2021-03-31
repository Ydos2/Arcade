/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** SceneManager
*/

#include <string>
#include "SceneManager.hpp"

namespace arcade {

    SceneManager::SceneManager()
    {
    }

    SceneManager::~SceneManager()
    {
    }

    Scene *SceneManager::setActive(std::string name)
    {
        m_current = m_scenes.at(name);
        return m_current;
    }

    Scene *SceneManager::getCurrent() const
    {
        return (m_current);
    }

    Scene *SceneManager::get(std::string name)
    {
        return (m_scenes.at(name));
    }

    void SceneManager::add(Scene *newScene) // TODO
    {
        (void) newScene;
    }

    void SceneManager::close(std::string name) // TODO
    {
        (void) name;
    }

}
