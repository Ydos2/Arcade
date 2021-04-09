/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Entity
*/

#include "Entity.hpp"

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
        
        m_components.push_back(std::move(std::make_shared<component::IComponent>(component)));
    }

    void Entity::removeComponent(const component::IComponent& component)
    {
        for (int i = 0; i < m_components.size(); i++) {
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