/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** NCurses
*/

#include "Sfml.hpp"
#include <iostream>
#include "api/event/MouseEvent.hpp"
#include <unordered_map>

namespace arcade
{

    void Sfml::init(IScene &scene)
    {
        m_window.create(sf::VideoMode(800, 600), "arcade");
        m_window.setVerticalSyncEnabled(true);
        m_window.setKeyRepeatEnabled(false);

        if (!font.loadFromFile("res/OpenSans-Regular.ttf"))
        {
            std::cerr << "sfml : Could not load fonts. Text will not be displayed correctly" << std::endl;
            return;
        }
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
        for(int i = 0; i < this->m_keytab.size(); i++) {
            std::cout << (int)this->m_keytab[i] << " ";
        }
        std::cout << std::endl;
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

    event::Key Sfml::sfmlKeyToArcade(sf::Keyboard::Key key)
    {
        std::unordered_map<sf::Keyboard::Key, event::Key> keytab = {
            {sf::Keyboard::Escape, event::Key::KEY_ESCAPE},
            {sf::Keyboard::BackSpace, event::Key::KEY_BACK_SPACE},
            {sf::Keyboard::Right, event::Key::KEY_ARROW_RIGHT},
            {sf::Keyboard::Left, event::Key::KEY_ARROW_LEFT},
            {sf::Keyboard::Up, event::Key::KEY_ARROW_UP},
            {sf::Keyboard::Down, event::Key::KEY_ARROW_DOWN},
            {sf::Keyboard::LShift, event::Key::KEY_SHIFT_LEFT},
            {sf::Keyboard::RShift, event::Key::KEY_SHIFT_RIGHT},
            {sf::Keyboard::LControl, event::Key::KEY_CTRL_LEFT},
            {sf::Keyboard::RControl, event::Key::KEY_CTRL_RIGHT},
            {sf::Keyboard::LAlt, event::Key::KEY_ALT_LEFT},
            {sf::Keyboard::RAlt, event::Key::KEY_ALT_RIGHT},
            {sf::Keyboard::Tab, event::Key::KEY_TAB},
            {sf::Keyboard::PageUp, event::Key::KEY_PAGE_UP},
            {sf::Keyboard::PageDown, event::Key::KEY_PAGE_DOWN},
            {sf::Keyboard::Delete, event::Key::KEY_DELETE},
            {sf::Keyboard::Insert, event::Key::KEY_INSERT},
            {sf::Keyboard::End, event::Key::KEY_END_FILE},
            {sf::Keyboard::Space, event::Key::KEY_SPACE},
            {sf::Keyboard::F1, event::Key::KEY_F1},
            {sf::Keyboard::F2, event::Key::KEY_F2},
            {sf::Keyboard::F3, event::Key::KEY_F3},
            {sf::Keyboard::F4, event::Key::KEY_F4},
            {sf::Keyboard::F5, event::Key::KEY_F5},
            {sf::Keyboard::F6, event::Key::KEY_F6},
            {sf::Keyboard::F7, event::Key::KEY_F7},
            {sf::Keyboard::F8, event::Key::KEY_F8},
            {sf::Keyboard::F9, event::Key::KEY_F9},
            {sf::Keyboard::F10, event::Key::KEY_F10},
            {sf::Keyboard::F11, event::Key::KEY_F11},
            {sf::Keyboard::F12, event::Key::KEY_F12},
            {sf::Keyboard::A, event::Key::KEY_A},
            {sf::Keyboard::B, event::Key::KEY_B},
            {sf::Keyboard::C, event::Key::KEY_C},
            {sf::Keyboard::D, event::Key::KEY_D},
            {sf::Keyboard::E, event::Key::KEY_E},
            {sf::Keyboard::F, event::Key::KEY_F},
            {sf::Keyboard::G, event::Key::KEY_G},
            {sf::Keyboard::H, event::Key::KEY_H},
            {sf::Keyboard::I, event::Key::KEY_I},
            {sf::Keyboard::J, event::Key::KEY_J},
            {sf::Keyboard::K, event::Key::KEY_K},
            {sf::Keyboard::L, event::Key::KEY_L},
            {sf::Keyboard::M, event::Key::KEY_M},
            {sf::Keyboard::N, event::Key::KEY_N},
            {sf::Keyboard::O, event::Key::KEY_O},
            {sf::Keyboard::P, event::Key::KEY_P},
            {sf::Keyboard::Q, event::Key::KEY_Q},
            {sf::Keyboard::R, event::Key::KEY_R},
            {sf::Keyboard::S, event::Key::KEY_S},
            {sf::Keyboard::T, event::Key::KEY_T},
            {sf::Keyboard::U, event::Key::KEY_U},
            {sf::Keyboard::V, event::Key::KEY_V},
            {sf::Keyboard::W, event::Key::KEY_W},
            {sf::Keyboard::X, event::Key::KEY_X},
            {sf::Keyboard::Y, event::Key::KEY_Y},
            {sf::Keyboard::Z, event::Key::KEY_Z},
            {sf::Keyboard::Num1, event::Key::KEY_1},
            {sf::Keyboard::Num2, event::Key::KEY_2},
            {sf::Keyboard::Num3, event::Key::KEY_3},
            {sf::Keyboard::Num4, event::Key::KEY_4},
            {sf::Keyboard::Num5, event::Key::KEY_5},
            {sf::Keyboard::Num6, event::Key::KEY_6},
            {sf::Keyboard::Num7, event::Key::KEY_7},
            {sf::Keyboard::Num8, event::Key::KEY_8},
            {sf::Keyboard::Num9, event::Key::KEY_9},
            {sf::Keyboard::Num0, event::Key::KEY_0},
            {sf::Keyboard::Numpad1, event::Key::KEY_1},
            {sf::Keyboard::Numpad2, event::Key::KEY_2},
            {sf::Keyboard::Numpad3, event::Key::KEY_3},
            {sf::Keyboard::Numpad4, event::Key::KEY_4},
            {sf::Keyboard::Numpad5, event::Key::KEY_5},
            {sf::Keyboard::Numpad6, event::Key::KEY_6},
            {sf::Keyboard::Numpad7, event::Key::KEY_7},
            {sf::Keyboard::Numpad8, event::Key::KEY_8},
            {sf::Keyboard::Numpad9, event::Key::KEY_9},
            {sf::Keyboard::Numpad0, event::Key::KEY_0},
        };
        if (keytab.find(key) == keytab.end())
            throw std::exception();
        return keytab[key];
    }

    void Sfml::manageEvents(IScene &scene)
    {
        sf::Event event;
        std::vector<event::Key> newKeyTab = m_keytab;
        std::array<bool, 3> mousesPressed = {false};

        while (m_window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed :
                    m_window.close();
                    break;
                case sf::Event::KeyPressed :
                    try {
                        auto arckey = sfmlKeyToArcade(event.key.code);
                        for (std::size_t i = 0; i < newKeyTab.size(); i++)
                            if (newKeyTab[i] == arckey)
                                break;
                        newKeyTab.push_back(arckey);
                    } catch (std::exception &e) {}
                    break;
                case sf::Event::KeyReleased :
                    try {
                        auto arckey = sfmlKeyToArcade(event.key.code);
                        for (std::size_t i = 0; i < newKeyTab.size(); i++)
                            if (newKeyTab[i] == arckey) {
                                newKeyTab.erase(newKeyTab.begin() + i);
                                break;
                            }
                    } catch (std::exception &e) {}
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

    void Sfml::manageSprite(component::Transform *transform, component::Sprite *sprite)
    {
        if (!transform || !sprite)
            return;
    
        sf::Texture texture;
        sf::Sprite sfSprite;
        sf::Uint8* pixels = new sf::Uint8[sprite->width * sprite->height * 4];

        for (int i = 0; i < sprite->width * sprite->height; i++) {
            pixels[i * 4 + 0] = sprite->pixels[i].r;
            pixels[i * 4 + 1] = sprite->pixels[i].g;
            pixels[i * 4 + 2] = sprite->pixels[i].b;
            pixels[i * 4 + 3] = sprite->pixels[i].a;
        }

        texture.create(sprite->width, sprite->height);
        texture.update(pixels);

        sfSprite.setTexture(texture);
        sfSprite.setPosition(transform->position.x, transform->position.y);
        sfSprite.setScale(transform->scale.x, transform->scale.y);
        sfSprite.setRotation(transform->rotation.z);
        m_window.draw(sfSprite);

        delete pixels;
    }

    void Sfml::manageText(component::Transform *transform, component::Text *text)
    {
        sf::Text sfText;

        if (!transform || !text || fontError)
            return;

        sfText.setFont(font);
        sfText.setString(text->text);
        sfText.setCharacterSize(24);
        sfText.setFillColor(sf::Color::White);
        sfText.setPosition(transform->position.x, transform->position.y);
        sfText.setRotation(transform->rotation.z);
        sfText.setScale(transform->scale.x, transform->scale.y);
        this->m_window.draw(sfText);
    }

    void Sfml::manageSound(component::Sound *sound)
    {
        if (!sound)
            return;
        (void)sound;
    }

    void Sfml::manageDisplay(IScene &scene)
    {
        scene.forEach([&](arcade::IEntity &entity){
            component::Sprite *sprite = nullptr;
            component::Transform *transform = nullptr;
            component::Text *text = nullptr;
            component::Sound *sound = nullptr;

            entity.forEach([&](arcade::component::IComponent &component){
                if (auto ptr = dynamic_cast<component::Transform *>(&component))
                    transform = ptr;
                if (auto ptr = dynamic_cast<component::Sprite *>(&component))
                    sprite = ptr;
                if (auto ptr = dynamic_cast<component::Text *>(&component))
                    text = ptr;
                if (auto ptr = dynamic_cast<component::Sound *>(&component))
                    sound = ptr;
            });

            this->manageSprite(transform, sprite);
            this->manageText(transform, text);
            this->manageSound(sound);
        });
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