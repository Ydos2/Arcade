/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "library/LibraryManager.hpp"
#include "SceneManager.hpp"
#include <chrono>
#include <ctime>  

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
            library::LibraryManager m_libraryManager;
            SceneManager m_sceneManager;
            std::chrono::_V2::system_clock::time_point m_time;
            lib::IGame *m_bios = nullptr;
    };

}

#endif /* !CORE_HPP_ */