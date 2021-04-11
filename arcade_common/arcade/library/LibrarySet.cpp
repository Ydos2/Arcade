/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** LibrarySet
*/

#include "LibrarySet.hpp"
#include <iostream>

namespace arcade {

namespace library {

    // get whole lib list
    std::vector<Library> &LibrarySet::getList()
    {
        return this->m_list;
    }

    // get active lib
    Library *LibrarySet::getActive()
    {
        for (auto &lib : this->m_list) {
            if (lib.getPath() == this->m_current) {
                return &lib;
            }
        }
        return nullptr;
    }

    // add lib
    void LibrarySet::add(const Library &lib)
    {
        if (this->existFromPath(lib.getPath()))
            return;
        this->m_list.push_back(lib);
    }

    // search lib
    bool LibrarySet::existFromPath(std::string path) const
    {
        for (std::size_t i = 0; i < this->m_list.size(); i++) {
            if (this->m_list[i].getPath() == path)
                return true;
        }
        return false;
    }

    bool LibrarySet::exist(std::string name) const
    {
        for (std::size_t i = 0; i < this->m_list.size(); i++) {
            if (this->m_list[i].getName() == name)
                return true;
        }
        return false;
    }

    bool LibrarySet::exist(const Library &lib) const
    {
        for (std::size_t i = 0; i < this->m_list.size(); i++) {
            if (this->m_list[i].getPath() == lib.getPath())
                return true;
        }
        return false;
    }

    bool LibrarySet::exist(lib::ILibrary *lib) const
    {
        for (std::size_t i = 0; i < this->m_list.size(); i++) {
            if (this->m_list[i].getLibrary() == lib)
                return true;
        }
        return false;
    }

    // get lib
    Library *LibrarySet::getFromPath(std::string path)
    {
        for (std::size_t i = 0; i < this->m_list.size(); i++) {
            if (this->m_list[i].getPath() == path)
                return &(this->m_list[i]);
        }
        return nullptr;
    }

    Library *LibrarySet::get(std::string name)
    {
        for (std::size_t i = 0; i < this->m_list.size(); i++) {
            if (this->m_list[i].getName() == name)
                return &(this->m_list[i]);
        }
        return nullptr;
    }

    Library *LibrarySet::get(lib::ILibrary *lib)
    {
        for (std::size_t i = 0; i < this->m_list.size(); i++) {
            if (this->m_list[i].getLibrary() == lib)
                return &(this->m_list[i]);
        }
        return nullptr;
    }

    Library *LibrarySet::get(std::size_t index)
    {
        if (this->m_list.size() >= index)
            return nullptr;
        return &(this->m_list[index]);
    }

    // get lib index
    std::size_t LibrarySet::getIndexFromPath(std::string path) const
    {
        for (std::size_t i = 0; i < this->m_list.size(); i++) {
            if (this->m_list[i].getPath() == path)
                return i;
        }
        return std::string::npos;
    }

    std::size_t LibrarySet::getIndex(std::string name) const
    {
        for (std::size_t i = 0; i < this->m_list.size(); i++) {
            if (this->m_list[i].getName() == name)
                return i;
        }
        return std::string::npos;
    }

    std::size_t LibrarySet::getIndex(lib::ILibrary *lib) const
    {
        for (std::size_t i = 0; i < this->m_list.size(); i++) {
            if (this->m_list[i].getLibrary() == lib)
                return i;
        }
        return std::string::npos;
    }

    std::size_t LibrarySet::getIndex(const Library &lib) const
    {
        for (std::size_t i = 0; i < this->m_list.size(); i++) {
            if (this->m_list[i].getPath() == lib.getPath())
                return i;
        }
        return std::string::npos;
    }

    // close lib
    void LibrarySet::closeFromPath(std::string path)
    {
        std::size_t index = this->getIndexFromPath(path);

        this->close(index);
    }

    void LibrarySet::close(std::string name)
    {
        std::size_t index = this->getIndex(name);

        this->close(index);
    }

    void LibrarySet::close(const Library &lib)
    {
        std::size_t index = this->getIndexFromPath(lib.getPath());

        this->close(index);
    }

    void LibrarySet::close(lib::ILibrary *lib)
    {
        std::size_t index = this->getIndex(lib);

        this->close(index);
    }

    void LibrarySet::close(std::size_t index)
    {
        if (index == std::string::npos)
            return;
        if (this->m_list[index].getLibrary() == this->getActive()->getLibrary())
            this->m_current = nullptr;
        this->m_list[index].close();
        this->m_list.erase(this->m_list.begin() + index);
    }

    // set current lib
    void LibrarySet::activateFromPath(scene::Scene &scene, std::string path)
    {
        std::size_t index = this->getIndexFromPath(path);

        this->activate(scene, index);
    }

    void LibrarySet::activate(scene::Scene &scene, std::string name)
    {
        std::size_t index = this->getIndex(name);

        this->activate(scene, index);
    }

    void LibrarySet::activate(scene::Scene &scene, const Library &lib)
    {
        std::size_t index = this->getIndexFromPath(lib.getPath());

        this->activate(scene, index);
    }

    void LibrarySet::activate(scene::Scene &scene, std::size_t index)
    {
        if (index == std::string::npos)
            return;
        arcade::library::Library &current = this->m_list[index];

        this->m_current = current.getPath();
        current.getLibrary()->init(scene);
    }

    // get len
    std::size_t LibrarySet::size() const
    {
        return this->m_list.size();
    }

    void LibrarySet::next(scene::Scene &scene)
    {
        auto current = getActive();
        if (!current)
            return;
        current->getLibrary()->end(scene);
        int index = this->getIndexFromPath(current->getPath()) + 1;
        if (index >= this->m_list.size())
            index = 0;
        this->activate(scene, index);
    }

    void LibrarySet::previous(scene::Scene &scene)
    {
        auto current = getActive();
        if (!current)
            return;
        current->getLibrary()->end(scene);
        int index = this->getIndexFromPath(current->getPath()) + 1;
        if (index >= this->m_list.size())
            index = 0;
        this->activate(scene, index);
    }

}

}