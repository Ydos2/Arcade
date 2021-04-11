/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <string>
#include "api/IScene.hpp"
#include "api/event/KeyboardEvent.hpp"
#include "api/event/MouseEvent.hpp"
#include "core/Entity.hpp"

namespace arcade
{

    namespace scene
    {

        class Scene : public IScene
        {
        public:
            Scene() = default;
            ~Scene() = default;

            void close();
            void clear();

            void exit() override;
            bool isExit() const;
            void pushEvent(const event::IEvent &event) override;

            IEntity &newEntity(std::string name) override;
            IEntity &newEntity() override;
            std::vector<std::reference_wrapper<IEntity>> getEntity(const std::string &name) override;
            void removeEntity(const std::string &name) override;
            void removeEntity(const IEntity &entity) override;

            void addScore(float score) override;

            void forEach(std::function<void(IEntity &)>) override;
            void forEach(std::function<void(IEntity&)>, const std::string& name) override;

            void setWindowSize(int x, int y) override;
            math::Vector2 getWindowSize() const override;

            std::vector<event::KeyboardEvent> pullKeyBoardEvents();
            std::vector<event::MouseEvent> pullMouseEvents();

        protected:
        private:
            bool m_exitState;
            std::vector<core::Entity> m_entity;
            math::Vector2 m_windowSize;
            std::vector<event::KeyboardEvent> m_keyBoardEvent;
            std::vector<event::MouseEvent> m_mouseEvent;
            float m_score;
        };

    }

}

#endif /* !SCENE_HPP_ */
