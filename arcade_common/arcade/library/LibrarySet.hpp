/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** LibrarySet
*/

#ifndef LIBRARYSET_HPP_
#define LIBRARYSET_HPP_

#include "Library.hpp"
#include "api/ILibrary.hpp"
#include "scene/Scene.hpp"
#include <vector>
#include <list>

namespace arcade {

namespace library {

    class LibrarySet {
        public:
            LibrarySet() = default;
            ~LibrarySet() = default;

            // get whole lib list
            std::vector<Library> &getList();
            // get active lib
            Library *getActive();
            // add lib
            void add(const Library &lib);
            // search lib
            bool existFromPath(std::string path) const;
            bool exist(std::string name) const;
            bool exist(const Library &lib) const;
            bool exist(lib::ILibrary *lib) const;
            // get lib
            Library *getFromPath(std::string path);
            Library *get(std::string name);
            Library *get(lib::ILibrary *lib);
            Library *get(std::size_t index);
            // get lib index
            std::size_t getIndexFromPath(std::string path) const;
            std::size_t getIndex(std::string name) const;
            std::size_t getIndex(lib::ILibrary *lib) const;
            std::size_t getIndex(const Library &lib) const;
            // close lib
            void closeFromPath(std::string path);
            void close(std::string name);
            void close(const Library &lib);
            void close(lib::ILibrary *lib);
            void close(std::size_t index);
            // set current lib
            void activateFromPath(scene::Scene &scene, std::string path);
            void activate(scene::Scene &scene, std::string name);
            void activate(scene::Scene &scene, const Library &lib);
            void activate(scene::Scene &scene, std::size_t index);
            // get len
            std::size_t size() const;

        protected:
        private:
            std::vector<Library> m_list;
            std::string m_current = "";
    };

}

}

#endif /* !LIBRARYSET_HPP_ */
