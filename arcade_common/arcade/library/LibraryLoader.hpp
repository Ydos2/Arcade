/*
** EPITECH PROJECT, 2021
** arcade - core
** File description:
** Loader
*/

#ifndef LIBRARY_LOADER_HPP_
#define LIBRARY_LOADER_HPP_

#include "Library.hpp"
#include <vector>

namespace arcade {

namespace library {

    class LibraryLoader {
        public:
            static Library load(std::string path);
            static std::vector<Library> loadAll();

        protected:
        private:
    };

}

}

#endif /* !LIBRARY_LOADER_HPP_ */
