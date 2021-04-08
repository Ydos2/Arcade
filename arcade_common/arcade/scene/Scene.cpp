/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Scene
*/

#include <string>
#include <algorithm>
#include "Scene.hpp"
#include "api/event/KeyboardEvent.hpp"
#include "api/event/MouseEvent.hpp"

namespace arcade
{

    namespace scene
    {

        void Scene::close()
        {
        }

        void Scene::exit() const
        {
            //if (m_exitState)
            // exit
        }

        void Scene::pushEvent(const event::IEvent &event)
        {
            if (arcade::event::KeyboardEvent const *keyEvent =
                dynamic_cast<const event::KeyboardEvent *>(&event))
            {
                //auto actionEvent = il faut get les event
                //if (actionEvent)
                //faire l'event 
            }
            else if (arcade::event::MouseEvent const * keyEvent =
                dynamic_cast<const event::MouseEvent *>(&event))
            {
                //auto actionEvent = il faut get les event
                //if (actionEvent)
                //faire l'event
            }
        }

        IEntity &Scene::newEntity(std::string name)
        {
            /*for (size_t i = 0; i < m_entity.size(); i++)
            {
                if (m_entity[i].get())
            }
            
            m_entity.push_back()*/
        }

        IEntity &Scene::newEntity()
        {
        }

        std::vector<std::reference_wrapper<IEntity>> Scene::getEntity(
            const std::string &name)
        {
        }

        void Scene::removeEntity(const std::string &name)
        {
        }

        void Scene::removeEntity(const IEntity &entity)
        {
            for (std::reference_wrapper<arcade::IEntity> i : m_entity)
            {
                /*if (i == entity)
                {

                }*/
            }
        }

        void Scene::addScore(float score)
        {
        }

        void Scene::forEach(std::function<void(IEntity &)> comp)
        {
            std::for_each(m_entity.begin(), m_entity.end(), comp);
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
    }

}