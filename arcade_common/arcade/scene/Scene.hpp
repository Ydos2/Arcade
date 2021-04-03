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

namespace arcade {

namespace scene {

class Scene : public IScene {
    public:
        Scene() = default;
        ~Scene() = default;

        void close();

        void exit() const override;
        void pushEvent(const event::IEvent& event) override;

        IEntity& newEntity(std::string name) override;
        IEntity& newEntity() override;
        std::vector<std::reference_wrapper<IEntity>> getEntity(
            const std::string& name) override;
        void removeEntity(const std::string& name) override;
        void removeEntity(const IEntity& entity) override;

        void addScore(float score) override;

        void forEach(std::function<void(IEntity&)>) override;

    protected:
    private:
};

}

}

#endif /* !SCENE_HPP_ */
