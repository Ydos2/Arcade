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

    protected:
    private:
};

}

}

#endif /* !SCENE_HPP_ */
