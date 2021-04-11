/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** NCurses
*/

#include "Sfml.hpp"
#include <iostream>
#include "api/event/MouseEvent.hpp"

namespace arcade
{

    void Sfml::init(IScene &scene)
    {
        m_window.create(sf::VideoMode(800, 600), "arcade");
        m_window.setVerticalSyncEnabled(true);
    }

    bool Sfml::isPressedKey(event::Key key, const std::vector<event::Key> &tab)
    {
        for (int iter = 0; iter < tab.size(); iter++) {
            if (tab[iter] == key)
                return true;
        }
        return false;
    }

    void Sfml::manageKeyboard(IScene &scene, const std::vector<event::Key> &newKeyTab)
    { 
        event::KeyboardEvent event;
    
        for (int iter = 0; iter < newKeyTab.size(); iter++) {
            event.key = newKeyTab[iter];
            if (isPressedKey(newKeyTab[iter], this->m_keytab)) {
                event.action = event.DOWN;
            } else {
                event.action = event.PRESSED;
            }
            scene.pushEvent(event);
        }

        for (int iter = 0; iter < this->m_keytab.size(); iter++) {
            event.key = this->m_keytab[iter];
            if (!isPressedKey(this->m_keytab[iter], newKeyTab)) {
                event.action = event.RELEASED;
                scene.pushEvent(event);
            }
        }

        this->m_keytab = newKeyTab;
    }

    static int mouseButtonsToIndex(sf::Mouse::Button button)
    {
        switch (button)
        {
        case sf::Mouse::Left :
            return 0;
        case sf::Mouse::Right :
            return 1;
        case sf::Mouse::Middle :
            return 2;
        default:
            return -1;
        }
        return -1;
    }

    void Sfml::manageMouse(IScene &scene, sf::Event::MouseButtonEvent button, bool pressed)
    {
        int buttonIndex = mouseButtonsToIndex(button.button);
        if (buttonIndex == -1)
            return;
        event::MouseEvent mouseEvent;
    
        mouseEvent.x = button.x;
        mouseEvent.y = button.y;
        mouseEvent.button = buttonIndex == 0 ? event::MouseEvent::MOUSE_PRIMARY :
                            buttonIndex == 1 ? event::MouseEvent::MOUSE_SECONDARY :
                            event::MouseEvent::MOUSE_AUXILIARY;

        if (pressed && !this->m_mousetab[buttonIndex]) {
            mouseEvent.action = event::MouseEvent::PRESSED;
            this->m_mousetab[buttonIndex] = true;
            scene.pushEvent(mouseEvent);
        } else if (!pressed && this->m_mousetab[buttonIndex]) {
            mouseEvent.action = event::MouseEvent::RELEASED;
            this->m_mousetab[buttonIndex] = false;
            scene.pushEvent(mouseEvent);
        }
    }

    event::Key sfmlKeyToArcade(sf::Keyboard::Key key)
    {
        return event::Key::KEY_0;
    }

    void Sfml::manageEvents(IScene &scene)
    {
        sf::Event event;
        std::vector<event::Key> newKeyTab;
        std::array<bool, 3> mousesPressed = {false};

        while (m_window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed :
                    m_window.close();
                    break;
                case sf::Event::KeyPressed :
                    newKeyTab.push_back(sfmlKeyToArcade(event.key.code));
                    break;
                case sf::Event::MouseButtonPressed :
                    if (mouseButtonsToIndex(event.mouseButton.button) == -1)
                        break;
                    manageMouse(scene, event.mouseButton, true);
                    mousesPressed[mouseButtonsToIndex(event.mouseButton.button)] = true;
                    break;
                case sf::Event::MouseButtonReleased :
                    if (mouseButtonsToIndex(event.mouseButton.button) == -1)
                        break;
                    manageMouse(scene, event.mouseButton, false);
                    mousesPressed[mouseButtonsToIndex(event.mouseButton.button)] = true;
                    break;
            }

            for (int i = 0; i < 3; i++) {
                if (!mousesPressed[i] && this->m_mousetab[i]) {
                    event::MouseEvent mouseEvent;
                    sf::Vector2i mousePos = sf::Mouse::getPosition();
                    mouseEvent.x = mousePos.x;
                    mouseEvent.y = mousePos.y;
                    mouseEvent.button = mouseEvent.button = i == 0 ? event::MouseEvent::MOUSE_PRIMARY :
                                                            i == 1 ? event::MouseEvent::MOUSE_SECONDARY :
                                                                     event::MouseEvent::MOUSE_AUXILIARY;
                    mouseEvent.action = event::MouseEvent::DOWN;
                    scene.pushEvent(mouseEvent);
                }
            }
        }

        manageKeyboard(scene, newKeyTab);
    }

    void Sfml::manageDisplay(IScene &scene)
    {
        
    }

    void Sfml::update(IScene &scene, float dt)
    {
        (void)dt;
        m_window.clear(sf::Color::Black);
        manageEvents(scene);
        manageDisplay(scene);
        m_window.display();
    }

    void Sfml::end(IScene &scene)
    {
        if (m_window.isOpen())
            m_window.close();
    }

    bool Sfml::quitRequested() const
    {
        if (m_window.isOpen())
            return false;
        return true;
    }
}