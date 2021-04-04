/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "api/IGame.hpp"

namespace arcade {

    class Nibbler : public lib::IGame {
        public:
            Nibbler() = default;
            ~Nibbler() = default;

            void init(IScene &scene) override;
            void update(IScene &scene, float dt) override;
            void end(IScene &scene) override;

            void onKeyEvent(const event::KeyboardEvent& key) override;
            void onMouseEvent(const event::MouseEvent& mouse) override;

        protected:
        private:
    };

}

#endif /* !NIBBLER_HPP_ */
