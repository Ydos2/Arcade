/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Scene
*/

#include <string>
#include <iostream>
#include <algorithm>
#include "Scene.hpp"
#include "api/event/KeyboardEvent.hpp"
#include "api/event/MouseEvent.hpp"

namespace arcade
{

    namespace scene
    {

        void Scene::exit()
        {
            m_exitState = true;
        }

        void Scene::pushEvent(const event::IEvent &event)
        {
            try {
                const event::KeyboardEvent &keyEvent =
                dynamic_cast<const event::KeyboardEvent &>(event);

                this->m_keyBoardEvent.push_back(keyEvent);
                return;
            } catch (std::exception &e) {}

            try {
                const event::MouseEvent &mouseEvent =
                dynamic_cast<const event::MouseEvent &>(event);

                this->m_mouseEvent.push_back(mouseEvent);
                return;
            } catch (std::exception &e) {}
        }

        IEntity &Scene::newEntity(std::string name)
        {
            m_entity.push_back(core::Entity(name));

            return m_entity.back();
        }

        IEntity &Scene::newEntity()
        {
            m_entity.push_back(core::Entity(""));

            return m_entity.back();
        }

        std::vector<std::reference_wrapper<IEntity>> Scene::getEntity(
            const std::string &name)
        {
            std::vector<std::reference_wrapper<IEntity>> ret;

            for (size_t i = 0; i < m_entity.size(); i++) {
                core::Entity &ent = m_entity[i];
                if (ent.getName() == name)
                    ret.push_back(ent);
            }
            return ret;
        }

        void Scene::removeEntity(const std::string &name)
        {
            for (std::size_t i = 0; i < m_entity.size(); i++) {
                if (m_entity[i].getName() == name)
                    m_entity.erase(m_entity.begin() + i);
            }
        }

        void Scene::removeEntity(const IEntity &entity)
        {
            const core::Entity& ent = static_cast<const core::Entity&>(entity);

            for (std::size_t i = 0; i < m_entity.size(); i++) {
                if (m_entity[i] == ent)
                    m_entity.erase(m_entity.begin() + i);
            }
        }

        void Scene::addScore(float score)
        {
            m_score = score;
        }

        void Scene::forEach(std::function<void(IEntity &)> comp)
        {
            std::for_each(m_entity.begin(), m_entity.end(), comp);
        }

        void Scene::forEach(std::function<void(IEntity&)> fun, const std::string& name)
        {
            for (std::size_t i = 0; i < m_entity.size(); i++) {
                if (m_entity[i].getName() == name)
                    fun(m_entity[i]);
            }
        }

        void Scene::setWindowSize(int x, int y)
        {
            m_windowSize.x = x;
            m_windowSize.y = y;
        }

        math::Vector2 Scene::getWindowSize() const
        {
            return m_windowSize;
        }

        std::vector<event::KeyboardEvent> Scene::pullKeyBoardEvents()
        {
            std::vector<event::KeyboardEvent> ret = m_keyBoardEvent;

            m_keyBoardEvent.clear();
            return ret;
        }

        std::vector<event::MouseEvent> Scene::pullMouseEvents()
        {
            std::vector<event::MouseEvent> ret = m_mouseEvent;

            m_mouseEvent.clear();
            return ret;
        }
    }

}