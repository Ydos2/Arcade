/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** LibraryManager
*/

#include "LibraryManager.hpp"
#include "LibraryLoader.hpp"
#include <iostream>

namespace arcade {

namespace library {

        // add libraries
        void LibraryManager::add(const Library &lib)
        {
            if (this->m_games.exist(lib) || this->m_graphics.exist(lib))
                return;
            if (lib.isGame()) {
                this->m_games.add(lib);
            }
            if (lib.isGraphic()) {
                this->m_graphics.add(lib);
            }
        }

        void LibraryManager::add(const std::vector<Library> libs)
        {
            for (const Library &lib : libs)
                this->add(lib);
        }

        // Check if lib exist
        bool LibraryManager::existFromPath(std::string path) const
        {
            return this->m_games.existFromPath(path)
                || this->m_graphics.existFromPath(path);
        }
    
        bool LibraryManager::exist(std::string name) const
        {
            return this->m_games.exist(name)
                || this->m_graphics.exist(name);
        }
    
        bool LibraryManager::exist(const Library &lib) const
        {
            return this->m_games.exist(lib)
                || this->m_graphics.exist(lib);
        }

        bool LibraryManager::exist(lib::ILibrary *lib) const
        {
            return this->m_games.exist(lib)
                || this->m_graphics.exist(lib);
        }

        // Get lib
        Library *LibraryManager::getFromPath(std::string path)
        {
            Library *res = this->m_games.getFromPath(path);

            res = res ? res : this->m_graphics.getFromPath(path);
            return res;
        }

        Library *LibraryManager::get(std::string name)
        {
            Library *res = this->m_games.get(name);

            res = res ? res : this->m_graphics.get(name);
            return res;
        }

        Library *LibraryManager::get(lib::ILibrary *lib)
        {
            Library *res = this->m_games.get(lib);

            res = res ? res : this->m_graphics.get(lib);
            return res;
        }

        Library *LibraryManager::get(std::size_t index)
        {
            Library *res = this->m_games.get(index);

            res = res ? res : this->m_graphics.get(index);
            return res;
        }

        // close lib
        void LibraryManager::closeFromPath(std::string path)
        {
            this->m_games.closeFromPath(path);
            this->m_graphics.closeFromPath(path);
        }

        void LibraryManager::close(std::string name)
        {
            this->m_games.close(name);
            this->m_graphics.close(name);
        }

        void LibraryManager::close(const Library &lib)
        {
            this->m_games.close(lib);
            this->m_graphics.close(lib);
        }

        void LibraryManager::close(lib::ILibrary *lib)
        {
            this->m_games.close(lib);
            this->m_graphics.close(lib);
        }

        // set current lib
        void LibraryManager::activateFromPath(scene::Scene &scene, std::string path)
        {
            this->m_games.activateFromPath(scene, path);
            this->m_graphics.activateFromPath(scene, path);
        }

        void LibraryManager::activate(scene::Scene &scene, std::string name)
        {
            this->m_games.activate(scene, name);
            this->m_graphics.activate(scene, name);
        }

        void LibraryManager::activate(scene::Scene &scene, const Library &lib)
        {
            this->m_games.activate(scene, lib);
            this->m_graphics.activate(scene, lib);
        }

        void LibraryManager::activate(scene::Scene &scene, lib::ILibrary *lib)
        {
            this->m_games.activate(scene, lib);
            this->m_graphics.activate(scene, lib);
        }

        // Get active game
        Library *LibraryManager::getActiveGame() const
        {
            return this->m_games.getActive();
        }

        // Get active graphic
        Library *LibraryManager::getActiveGraphic() const
        {
            Library *graph = this->m_graphics.getActive();

            return graph;
        }

        // Get game
        std::vector<Library> &LibraryManager::getGames()
        {
            return this->m_games.getList();
        }

        // Get graphic
        std::vector<Library> &LibraryManager::getGraphics()
        {
            return this->m_graphics.getList();
        }

        // Get game len
        std::size_t LibraryManager::gameLen() const
        {
            return this->m_games.size();
        }

        // Get graphic len
        std::size_t LibraryManager::graphicLen() const
        {
            return this->m_graphics.size();
        }

}

}
