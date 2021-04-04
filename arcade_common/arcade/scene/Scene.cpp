/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Scene
*/

#include "Scene.hpp"
#include <string>

namespace arcade
{

    namespace scene
    {

        void Scene::close()
        {
        }

        void Scene::exit() const
        {
        }

        void Scene::pushEvent(const event::IEvent &event)
        {
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
            const std::string& name)
        {
        }

        void Scene::removeEntity(const std::string &name)
        {
        }

        void Scene::removeEntity(const IEntity &entity)
        {
        }

        void Scene::addScore(float score)
        {
        }

        void Scene::forEach(std::function<void(IEntity&)>)
        {
        }

    }

}