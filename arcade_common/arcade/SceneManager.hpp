/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include <unordered_map>
#include "../common/Scene.hpp"

namespace arcade {

    class SceneManager {
        public:
            SceneManager();
            ~SceneManager();

            Scene *setActive(std::string name);
            Scene *getCurrent() const;
            Scene *get(std::string name);
            void add(Scene *newScene);
            void close(std::string name);

        private:
            std::unordered_map<std::string, Scene *> _scenes;
            Scene *_current;
    };

}

#endif /* !SCENEMANAGER_HPP_ */
