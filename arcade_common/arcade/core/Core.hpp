/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "library/LibraryManager.hpp"
#include "scene/SceneManager.hpp"
#include <chrono>
#include <ctime>  

namespace arcade {

namespace core {

    class Core {
        public:
            Core() = default;
            ~Core() = default;

            int execute(std::string path = "");

            void exitGame();
            void launchGame(library::Library *gameLib);
        
        private:
            void createBios();
            bool start(std::string path);
            void update();
            void end();
            void manageSpecialKeyboard();
            void restartGame();

        private:
            library::LibraryManager m_libraryManager;
            scene::SceneManager m_sceneManager;
            std::chrono::_V2::system_clock::time_point m_time;
            lib::IGame *m_bios = nullptr;
            bool m_exit = false;
    };

}

}

#endif /* !CORE_HPP_ */