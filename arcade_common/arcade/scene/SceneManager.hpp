/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include <unordered_map>
#include "Scene.hpp"

namespace arcade {

namespace scene {

    class SceneManager {
        public:
            SceneManager() = default;
            ~SceneManager() = default;

            // set scene active
            Scene *setActive(std::string name);
            // get current scene
            Scene *getCurrent() const;
            // get current scene name
            std::string getCurrentName() const;
            // get scene
            Scene *get(std::string name);
            // add Scene
            void add(Scene newScene, std::string name);
            // close scene
            void close(std::string name);

        private:
            std::unordered_map<std::string, Scene> m_scenes;
            Scene *m_current;
    };

}

}

#endif /* !SCENEMANAGER_HPP_ */
