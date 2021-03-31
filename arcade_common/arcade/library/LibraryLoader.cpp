/*
** EPITECH PROJECT, 2021
** arcade - core
** File description:
** LibraryLoader
*/

#include "LibraryLoader.hpp"
#include <dlfcn.h>
#include "apiMacro.hpp"
#include <dirent.h>

namespace arcade {

namespace library {

    Library LibraryLoader::load(std::string path)
    {
        Library library;

        library.open(path);
        return library;
    }

    std::vector<Library> LibraryLoader::loadAll()
    {
        std::vector<Library> libs;
        DIR *dir = opendir("lib/");
        struct dirent *file;

        if (!dir)
            return libs;
        while ((file = readdir(dir)) != nullptr) {
            if (file->d_type != DT_REG)
                continue;
            libs.push_back(LibraryLoader::load("lib/" + std::string(file->d_name)));
        }
        closedir (dir);
        return libs;
    }

}

}