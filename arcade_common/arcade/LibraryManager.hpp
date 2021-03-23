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
#include "../common/api.h"

namespace arcade {

    class LibraryManager { // TODO
        public:
            LibraryManager();
            ~LibraryManager();

            void load(std::string path);
            void loadAll(std::string path);
            void close(std::string name);
            //void close(lib::ILibrary *lib);
            //void close(Library &lib);
            void setActive(std::string name);
            //void setActive(lib::ILibrary *lib);
            //void setActive(Library &lib);
            //Library &getCurrentGame() const;
            //Library &getCurrentGraphic() const;
            //Library &get(std::string name);
            //Library &getGame(std::size_t index);
            //Library &getGraphic(std::size_t index);
            std::size_t gameLen() const;
            std::size_t graphicLen() const;

        private:
            //std::vector<Library> _games;
            //std::vector<Library> _graphics;
            //lib::IGame *_currentGame;
            //lib::IGraphic *_currentGraphic;
    };

}

#endif /* !LIBRARYMANAGER_HPP_ */
