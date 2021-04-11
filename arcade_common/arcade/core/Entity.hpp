/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <string>
#include <memory>
#include <vector>
#include "api/IEntity.hpp"
#include "api/component/IComponent.hpp"

namespace arcade {

namespace core {


class Entity : public IEntity {
    public:
        Entity(const std::string &name);
        ~Entity() = default;

        void addComponent(const component::IComponent& component) override;

        void removeComponent(const component::IComponent& component) override;
        void forEach(std::function<void(component::IComponent&)> fun) override;

        bool operator==(const Entity &other);

        std::string getName() const;
    protected:
    private:
        std::string m_name;
        int m_id;
        std::vector<std::shared_ptr<component::IComponent>> m_components;

        static int m_idIndex;
        

};

}

}

#endif /* !ENTITY_HPP_ */
