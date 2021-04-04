/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** NCurses
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "api/IGraphic.hpp"

namespace arcade {

    class Sfml : lib::IGraphic {
        public:
            Sfml() = default;
            ~Sfml() = default;

            void init(IScene &scene) override;
            void update(IScene &scene, float dt) override;
            void end(IScene &scene) override;

            bool quitRequested() const override;
        protected:
        private:
    };

}

#endif /* !SFML_HPP_ */
