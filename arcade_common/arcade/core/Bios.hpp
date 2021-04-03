/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Bios
*/

#ifndef BIOS_HPP_
#define BIOS_HPP_

#include "api/IGame.hpp"

namespace arcade {

namespace core {

class Bios : public lib::IGame {
    public:
        Bios() = default;
        ~Bios() = default;

        void init(IScene &scene) override;
        void update(IScene &scene, float dt) override;
        void end(IScene &scene) override;

        void onKeyEvent(const event::KeyboardEvent& key) override;
        void onMouseEvent(const event::MouseEvent& mouse) override;

    protected:
    private:
};

}

}

#endif /* !BIOS_HPP_ */
