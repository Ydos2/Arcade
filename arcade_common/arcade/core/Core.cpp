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

namespace core {

    int Core::execute(std::string path)
    { 
        if (!this->start(path)) {
            std::cerr << "An error occured at start. Abort." << std::endl;
            return 84;
        }
        while (!m_exit)
            this->update();
        this->end();
    
        return 0;
    }

    bool Core::start(std::string path)
    {
        this->m_sceneManager.add(scene::Scene(), "BIOS");
        scene::Scene *scene = this->m_sceneManager.setActive("BIOS");

        if (path != "") {
            this->m_libraryManager.add(library::LibraryLoader::load(path));
            this->m_libraryManager.activateFromPath(*scene, path);
            //if (!this->m_libraryManager.getActiveGraphic())
            //    return false;
        }
        this->m_libraryManager.add(library::LibraryLoader::loadAll());
        if (!this->m_libraryManager.getActiveGraphic()) {
            this->m_libraryManager.forceActivate(*scene);
        }

        m_bios = new Bios(*scene, m_libraryManager);
        m_bios->init(*scene);

        m_time = std::chrono::system_clock::now();

        if (!this->m_libraryManager.getActiveGraphic()
            || !this->m_sceneManager.getCurrent())
            return false;
        return true;
    }

    double tmp_chrono = 0;

    void Core::update()
    {
        library::Library *gameLib = this->m_libraryManager.getActiveGame();
        library::Library *graphLib = this->m_libraryManager.getActiveGraphic();

        lib::IGame *game = gameLib ? gameLib->getLibrary<lib::IGame>() : m_bios;
        lib::IGraphic *graph = graphLib->getLibrary<lib::IGraphic>();
    
        scene::Scene *scene = this->m_sceneManager.getCurrent();
    
        auto now = std::chrono::system_clock::now();
        std::chrono::duration<double> dt = now - this->m_time;

        tmp_chrono += dt.count();

        game->update((*scene), dt.count());
        graph->update((*scene), dt.count());

        for (auto iter : scene->pullKeyBoardEvents())
            game->onKeyEvent(iter);
        for (auto iter : scene->pullMouseEvents())
            game->onMouseEvent(iter);

        if (graph->quitRequested())
            m_exit = true;

        tmp_chrono = 0;

        this->m_time = now;
    }

    void Core::end()
    {
        library::Library *gameLib = this->m_libraryManager.getActiveGame();
        library::Library *graphLib = this->m_libraryManager.getActiveGraphic();

        lib::IGame *game = gameLib ? gameLib->getLibrary<lib::IGame>() : m_bios;
        lib::IGraphic *graph = graphLib->getLibrary<lib::IGraphic>();

        graph->end(*m_sceneManager.getCurrent());

        m_bios->end(*m_sceneManager.get("BIOS"));
        m_sceneManager.close("BIOS");

        if (game) {
            game->end(*m_sceneManager.get("GAME"));
            m_sceneManager.close("GAME");
        }
    }

}

}