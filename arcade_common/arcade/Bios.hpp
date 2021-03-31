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

class Bios : public lib::IGame {
    public:
        Bios() = default;
        ~Bios() = default;

        void init(IScene &scene) override;
        void update(IScene &scene, float dt) override;
        void end(IScene &scene) override;

    protected:
    private:
};

}

#endif /* !BIOS_HPP_ */
