/*
** EPITECH PROJECT, 2021
** arcade - core
** File description:
** Core
*/

#include "Core.hpp"
#include "Bios.hpp"
#include "library/LibraryLoader.hpp"
#include <iostream>

namespace arcade { // TODO

    Core::Core()
    {
    }

    Core::~Core()
    {
    }

    int Core::execute(std::string path)
    { 
        Scene *s = new Scene("BIOS");
    
        this->m_sceneManager.add(s);
        this->m_sceneManager.setActive("BIOS");
        this->m_libraryManager.add(library::LibraryLoader::load(path));
        this->m_libraryManager.activateFromPath(*m_sceneManager.getCurrent(), path);

        this->start();
        while (1)
            this->update();
        this->end();
    
        return 0;
    }

    void Core::start()
    {
        this->m_libraryManager.add(library::LibraryLoader::loadAll());
        m_bios = new Bios();

        m_time = std::chrono::system_clock::now();
    }

    double tmp_chrono = 0;

    void Core::update()
    {
        library::Library *gameLib = this->m_libraryManager.getActiveGame();
        library::Library *graphLib = this->m_libraryManager.getActiveGraphic();

        lib::IGame *game = gameLib ? gameLib->getLibrary<lib::IGame>() : m_bios;
        lib::IGraphic *graph = graphLib->getLibrary<lib::IGraphic>();
    
        Scene *scene = this->m_sceneManager.getCurrent();
    
        auto now = std::chrono::system_clock::now();
        std::chrono::duration<double> dt = now - this->m_time;

        tmp_chrono += dt.count();

        if (tmp_chrono > 0.5f) {

            if (game)
                game->update((*scene), dt.count());
            graph->update((*scene), dt.count());

            tmp_chrono = 0;
        }

        this->m_time = now;
    }

    void Core::end()
    {

    }

}