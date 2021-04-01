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
        Scene(std::string name);
        ~Scene() = default;

        std::string getName() const;
    protected:
    private:
        std::string m_name;
};

}

}

#endif /* !SCENE_HPP_ */
