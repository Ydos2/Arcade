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
        _current = _scenes.at(name);
    }

    Scene *SceneManager::getCurrent() const
    {
        return (_current);
    }

    Scene *SceneManager::get(std::string name)
    {
        return (_scenes.at(name));
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
