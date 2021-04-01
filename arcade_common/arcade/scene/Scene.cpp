/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Scene
*/

#include "Scene.hpp"
#include <string>

namespace arcade {

namespace scene {

Scene::Scene(std::string name)
{
    m_name = name;
}

std::string Scene::getName() const
{
    return m_name;
}

}

}