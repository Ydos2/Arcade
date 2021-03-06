/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Bios
*/

#ifndef BIOS_HPP_
#define BIOS_HPP_

#include "api/IGame.hpp"
#include "Core.hpp"
#include "scene/Scene.hpp"
#include "library/LibraryManager.hpp"

namespace arcade {

namespace core {

class Bios : public lib::IGame {
    public:
        Bios(arcade::scene::Scene &scene, arcade::library::LibraryManager &libs, arcade::core::Core &core) :
            m_scene(scene), m_libs(libs), m_core(core) {}
        ~Bios() = default;

        void init(IScene &scene) override;
        void update(IScene &scene, float dt) override;
        void end(IScene &scene) override;

        void onKeyEvent(const event::KeyboardEvent& key) override;
        void onMouseEvent(const event::MouseEvent& mouse) override;

    protected:
    private:
        void loadSelected();
        void move(IScene &scene, float dt);
        std::size_t m_cursor_index = 0;
        std::size_t m_cursor_column = 0;
        arcade::scene::Scene &m_scene;
        arcade::library::LibraryManager &m_libs;
        arcade::core::Core &m_core;
};

}

}

#endif /* !BIOS_HPP_ */
