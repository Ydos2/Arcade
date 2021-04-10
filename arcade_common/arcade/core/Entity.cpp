/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Entity
*/

#include "Entity.hpp"
#include "api/component/Transform.hpp"
#include "api/component/Sprite.hpp"
#include "api/component/AsciiSprite.hpp"
#include "api/component/Sound.hpp"
#include "api/component/Text.hpp"
#include <iostream>

namespace arcade {

namespace core {

    int Entity::m_idIndex = 0;

    Entity::Entity(const std::string &name)
    {
        this->m_name = name;
        this->m_id = m_idIndex;
    }

    void Entity::addComponent(const component::IComponent& component)
    {
        if (auto ptr = dynamic_cast<const component::AsciiSprite*>(&component))
            m_components.push_back(std::make_shared<component::AsciiSprite>(*ptr));
        else if (auto ptr = dynamic_cast<const component::Sprite*>(&component))
            m_components.push_back(std::make_shared<component::Sprite>(*ptr));
        else if (auto ptr = dynamic_cast<const component::Transform*>(&component))
            m_components.push_back(std::make_shared<component::Transform>(*ptr));
        else if (auto ptr = dynamic_cast<const component::Sound*>(&component))
            m_components.push_back(std::make_shared<component::Sound>(*ptr));
        else if (auto ptr = dynamic_cast<const component::Text*>(&component))
            m_components.push_back(std::make_shared<component::Text>(*ptr));
    }

    void Entity::removeComponent(const component::IComponent& component)
    {
        for (std::size_t i = 0; i < m_components.size(); i++) {
            if (&component == m_components[i].get()) {
                m_components.erase(m_components.begin() + i);
                return;
            }
        }
    }

    void Entity::forEach(std::function<void(component::IComponent&)> fun)
    {
        for (std::size_t i = 0; i < m_components.size(); i++) {
            fun(*m_components[i].get());
        }
    }

    bool Entity::operator==(const Entity &other)
    {
        return this->m_id == other.m_id;
    }

    std::string Entity::getName() const
    {
        return m_name;
    }

}

}