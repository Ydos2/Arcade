/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Bios
*/

#include "Bios.hpp"
#include <iostream>
#include "api/component/Sprite.hpp"
#include "api/component/Transform.hpp"
#include "api/component/Text.hpp"
#include "api/event/KeyboardEvent.hpp"
#include "api/event/MouseEvent.hpp"

namespace arcade
{

    namespace core
    {
        static arcade::component::Sprite createSprite(size_t height, size_t width, arcade::Color color)
        {
            arcade::component::Sprite sprite;
            std::vector<arcade::Color> pixel;

            sprite.height = height;
            sprite.width = width;
            for (size_t i = 0; i < height * width; i++)
                pixel.push_back(color);
            sprite.pixels = pixel;
            return (sprite);
        }

        static component::Sprite createArrowSprite(
            arcade::Color arrowColor = ((arcade::Color) {(char)255, (char)255, (char)255, (char)255}),
            size_t arrowSize=20)
        {
            component::Sprite sprite = createSprite(arrowSize, arrowSize, (arcade::Color) {0, 0, 0, 0});
            for (size_t i = 0; i < arrowSize; i ++)
            {
                for (size_t j = 0; j < i + 1; j++) {

                    int offsetX = (arrowSize - i - 1);
                    int offsetY = (arrowSize / 2 - (i + 1) / 2 + j);
                    if (offsetY < 0)
                        offsetY = 0;
                    if (offsetY > arrowSize)
                        offsetY = arrowSize - 1;
                    int index = offsetX + offsetY * arrowSize;
                
                    sprite.pixels[index] = arrowColor;
                }
            }
            return sprite;
        }

        static arcade::component::Transform createTransform(float x, float y, float z)
        {
            arcade::component::Transform transform;

            transform.position.x = x;
            transform.position.y = y;
            transform.position.z = z;
            transform.scale.x = 1;
            transform.scale.y = 1;
            transform.scale.z = 1;
            return (transform);
        }

        static arcade::component::Text createText(std::string content)
        {
            arcade::component::Text text;

            text.text = content;
            return text;
        }

        static void createArrow(IScene &scene, std::string name)
        {
            arcade::IEntity &pacgum = scene.newEntity(name);

            pacgum.addComponent(createTransform(1, 1, 0));
            pacgum.addComponent(createArrowSprite());
        }

        

        static void createLibs(scene::Scene &scene, library::LibraryManager &libs)
        {
            const float start = 1;
            const float step = 1;
            float pos = start;
        
            for (auto &games : libs.getGames()) {
                arcade::IEntity &gamesEnt = scene.newEntity("game");

                gamesEnt.addComponent(createTransform(2, pos, 0));
                gamesEnt.addComponent(createText(games.getName()));
                pos += step;
            }

            pos = start;
            for (auto &graph : libs.getGraphics()) {
                arcade::IEntity &graphEnt = scene.newEntity("game");

                graphEnt.addComponent(createTransform(20, pos, 0));
                graphEnt.addComponent(createText(graph.getName()));
                pos += step;
            }
        }

        void Bios::init(IScene &scene)
        {
            std::cout << "BIOS init" <<std::endl;
            createArrow(scene, "cursor");
            createLibs(m_scene, m_libs);
        }

        void Bios::move(IScene &scene, float dt)
        {
            std::vector<std::reference_wrapper<IEntity>> ghost = scene.getEntity("cursor");

            ghost[0].get().forEach([&](arcade::component::IComponent& comp)
            {
                try
                {
                    float posX = this->m_cursor_column == 0 ? 1 : 19;
                    float posY = this->m_cursor_index + 1;
                    component::Transform &ptr = dynamic_cast<component::Transform&>(comp);
                    ptr.position.x = posX;
                    ptr.position.y = posY;
                }
                catch(const std::exception& e)
                {
                }
            });
        }

        void Bios::update(IScene &scene, float dt)
        {
            move(scene, dt);
        }

        void Bios::end(IScene &scene)
        {
            (void)scene;
        }

        void Bios::onKeyEvent(const event::KeyboardEvent& key)
        {
            if (key.action == key.PRESSED)
            {
                std::cout << (unsigned long)key.key << std::endl;
                switch (key.key)
                {
                case event::Key::KEY_ARROW_UP:
                    this->m_cursor_index -= 1;
                    if (this->m_cursor_index <= 0) {
                        this->m_cursor_index = 0;
                    }
                    break;
                case event::Key::KEY_ARROW_DOWN:
                    this->m_cursor_index += 1;
                    if (this->m_cursor_column == 0 && this->m_cursor_index >= m_libs.getGames().size()) {
                        this->m_cursor_index = m_libs.getGames().size() -1;
                    }
                    if (this->m_cursor_column == 1 && this->m_cursor_index >= m_libs.getGraphics().size()) {
                        this->m_cursor_index = m_libs.getGraphics().size() -1;
                    }
                    break;
                case event::Key::KEY_ARROW_LEFT:
                    this->m_cursor_column = 0;
                    this->m_cursor_index = 0;
                    break;
                case event::Key::KEY_ARROW_RIGHT:
                    this->m_cursor_column = 1;
                    this->m_cursor_index = 0;
                    break;
                case event::Key::KEY_SPACE:
                    loadSelected();
                    break;
                default:
                    std::cout << "?" << std::endl;
                    break;
                }
            }
        }

        void Bios::loadSelected()
        {
            if (m_cursor_column == 0) {
                for (int i = 0; i < m_libs.getGames().size(); i++) {
                    if (i == m_cursor_index) {
                        m_core.launchGame(&m_libs.getGames()[i]);
                    }
                }
            } else {
                for (int i = 0; i < m_libs.getGraphics().size(); i++) {
                    if (i == m_cursor_index) {
                        m_libs.getActiveGraphic()->getLibrary()->end(m_scene);
                        m_libs.activateFromPath(m_scene, m_libs.getGames()[i].getPath());
                    }
                }
            }
        }

        void Bios::onMouseEvent(const event::MouseEvent& mouse)
        {
            /*if (mouse.action == mouse.DOWN)
            {
                switch (mouse.button)
                {
                case mouse.MOUSE_PRIMARY:
                    std::cout << "!" << std::endl;
                    break;
                case mouse.MOUSE_SECONDARY:
                    // action
                    break;
                case mouse.MOUSE_AUXILIARY:
                    // action
                    break;
                default:
                    break;
                }
            }*/
        }

    }

}
