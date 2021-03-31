/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Library
*/

#include "Library.hpp"
#include "apiMacro.hpp"
#include <dlfcn.h>

namespace arcade {

namespace library {

    Library::Library(const std::string &path)
    {
        this->open(path);
    }

    Library::~Library()
    {
    }

    void Library::openError()
    {
        if (dlerror()) {
            this->close();
            throw std::string("error");
        }
    }

    void Library::open(const std::string &path)
    {
        this->m_path = path;
        this->m_file = dlopen(path.c_str(), RTLD_LAZY);
        openError();
        this->m_data = LIB_DATA(this->m_file);
        openError();
        this->m_lib = LIB_CREATE(this->m_file);
        openError();
    }

    void Library::close()
    {
        bool error = false;
    
        if (this->m_lib) {
            LIB_DELETE(this->m_file, this->m_lib);
            this->m_lib = nullptr;
        }
        if (this->m_file) {
            dlclose(this->m_file);
            this->m_file = nullptr;
        }
        this->m_path = "";

        if (error)
            throw dlerror();
    }

    std::string Library::getPath() const
    {
        return this->m_path;
    }
    
    library_info_t Library::getData() const
    {
        return this->m_data;
    }

    std::string Library::getName() const
    {
        return this->m_data.name;
    }

    std::string Library::getDetails() const
    {
        return this->m_data.desc;
    }

    time_t Library::getDate() const
    {
        return this->m_data.date;
    }

    bool Library::isGame() const
    {
        return this->m_data.type == library_info_t::GAME;
    }

    bool Library::isGraphic() const
    {
        return this->m_data.type == library_info_t::GRAPHIC;
    }

}

}