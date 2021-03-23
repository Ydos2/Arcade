/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "./LibraryManager.hpp"
#include "./SceneManager.hpp"

namespace arcade {

    class Core {
        public:
            Core();
            ~Core();

            int execute(std::string path);

        private:
            void createBios();
            void start();
            void update();
            void end();

        private:
            LibraryManager _libraryManager;
            SceneManager _sceneManager;
    };

}

#endif /* !CORE_HPP_ */