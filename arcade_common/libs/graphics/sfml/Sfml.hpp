/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** NCurses
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "api/IGraphic.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "api/event/KeyboardEvent.hpp"
#include <array>
#include "api/component/Sprite.hpp"
#include "api/component/Text.hpp"
#include "api/component/Transform.hpp"
#include "api/component/Sound.hpp"

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
            void manageEvents(IScene &scene);
            void manageDisplay(IScene &scene);
            void manageKeyboard(IScene &scene, const std::vector<event::Key> &newKeyTab);
            void manageMouse(IScene &scene, sf::Event::MouseButtonEvent button, bool pressed);
            void manageSprite(component::Transform *transform, component::Sprite *sprite);
            void manageText(component::Transform *transform, component::Text *text);
            void manageSound(component::Sound *sound);
            std::vector<event::Key> computeKeyTab();
            bool isPressedKey(event::Key key, const std::vector<event::Key> &tab);
            event::Key sfmlKeyToArcade(sf::Keyboard::Key key);

            sf::RenderWindow m_window;
            std::vector<event::Key> m_keytab;
            std::array<bool, 3> m_mousetab = {false};
            sf::Font font;
            bool fontError = false;
            const float unitSize = 25;
    };

}

#endif /* !SFML_HPP_ */
