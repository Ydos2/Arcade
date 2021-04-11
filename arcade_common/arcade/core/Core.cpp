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
        this->m_sceneManager.add(scene::Scene(), "GAME");
        scene::Scene *scene = this->m_sceneManager.setActive("BIOS");

        if (path != "") {
            this->m_libraryManager.add(library::LibraryLoader::load(path));
            this->m_libraryManager.activateFromPath(*scene, path);
            if (!this->m_libraryManager.getActiveGraphic())
                return false;
        }
        this->m_libraryManager.add(library::LibraryLoader::loadAll());
        if (!this->m_libraryManager.getActiveGraphic()) {
            this->m_libraryManager.forceActivate(*scene);
        }

        m_bios = new Bios(*scene, m_libraryManager, *this);
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

        manageSpecialKeyboard();

        if (graph->quitRequested())
            m_exit = true;

        if (scene->isExit())
            exitGame();

        tmp_chrono = 0;

        this->m_time = now;
    }

    void Core::manageSpecialKeyboard()
    {
        library::Library *gameLib = this->m_libraryManager.getActiveGame();
        library::Library *graphLib = this->m_libraryManager.getActiveGraphic();
        lib::IGame *game = gameLib ? gameLib->getLibrary<lib::IGame>() : m_bios;
        lib::IGraphic *graph = graphLib->getLibrary<lib::IGraphic>();
        scene::Scene *scene = this->m_sceneManager.getCurrent();

        for (auto iter : scene->pullKeyBoardEvents()) {
            if (iter.DOWN) {
                switch (iter.key)
                {
                case event::Key::KEY_F1 : // previous game
                    m_sceneManager.setActive("GAME");
                    m_sceneManager.get("GAME")->clear();
                    m_libraryManager.previousGame(*scene);
                    break;
                case event::Key::KEY_F2 : // next game
                    m_sceneManager.setActive("GAME");
                    m_sceneManager.get("GAME")->clear();
                    m_libraryManager.nextGame(*scene);
                    break;
                case event::Key::KEY_F3 : // previous graph
                    m_libraryManager.previousGraph(*scene);
                    break;
                case event::Key::KEY_F4 : // next graph
                    m_libraryManager.nextGraph(*scene);
                    break;
                case event::Key::KEY_END_FILE : // go bios
                    exitGame();
                    break;
                case event::Key::KEY_INSERT : // restart
                    restartGame();
                    break;
                case event::Key::KEY_ESCAPE : // exit
                    m_exit = true;
                    break;
                default:
                    break;
                }
            }
            game->onKeyEvent(iter);
        }
        for (auto iter : scene->pullMouseEvents()) {
            game->onMouseEvent(iter);
        }
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

    void Core::exitGame()
    {
        m_sceneManager.get("GAME")->clear();
        m_sceneManager.setActive("BIOS");
    }

    void Core::launchGame(library::Library *gameLib)
    {
        m_sceneManager.setActive("GAME");
        m_sceneManager.get("GAME")->clear();
        m_libraryManager.activateFromPath(*this->m_sceneManager.getCurrent(),gameLib->getPath());
    }

    void Core::restartGame()
    {
        scene::Scene *scene = this->m_sceneManager.getCurrent();
    
        auto game = m_libraryManager.getActiveGame();
        if (!game)
            return;
        m_sceneManager.get("GAME")->clear();
        game->getLibrary<lib::IGame>()->init(*scene);
    }

}

}