/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** LibraryManager
*/

#ifndef LIBRARYMANAGER_HPP_
#define LIBRARYMANAGER_HPP_

#include <vector>
#include <string>
#include "api/api.h"
#include "api/IGraphic.hpp"
#include "api/IGame.hpp"
#include "Library.hpp"
#include "LibrarySet.hpp"

namespace arcade {

namespace library {

    class LibraryManager { // TODO
        public:
            LibraryManager() = default;
            ~LibraryManager() = default;

            // Add Libraries
            void add(const Library &lib);
            void add(const std::vector<Library> libs);
            // Check if lib exist
            bool existFromPath(std::string path) const;
            bool exist(std::string name) const;
            bool exist(const Library &lib) const;
            bool exist(lib::ILibrary *lib) const;
            // Get lib
            Library *getFromPath(std::string path);
            Library *get(std::string name);
            Library *get(lib::ILibrary *lib);
            Library *get(std::size_t index);
            // close lib
            void closeFromPath(std::string path);
            void close(std::string name);
            void close(const Library &lib);
            void close(lib::ILibrary *lib);
            // set current lib
            void activateFromPath(scene::Scene &scene, std::string path);
            void activate(scene::Scene &scene, std::string name);
            void activate(scene::Scene &scene, const Library &lib);
            // force activation graphic library
            void forceActivate(scene::Scene &scene);
            // Get active game
            Library *getActiveGame();
            // Get active graphic
            Library *getActiveGraphic();
            // Get game
            std::vector<Library> &getGames();
            // Get graphic
            std::vector<Library> &getGraphics();
            // Get game len
            std::size_t gameLen() const;
            // Get graphic len
            std::size_t graphicLen() const;

        private:
            LibrarySet m_games;
            LibrarySet m_graphics;
    };

}

}

#endif /* !LIBRARYMANAGER_HPP_ */
