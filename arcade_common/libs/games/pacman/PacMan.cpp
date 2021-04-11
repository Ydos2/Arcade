/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** PacMan
*/

#include <iostream>
#include "PacMan.hpp"
#include "api/component/Sprite.hpp"
#include "api/component/Text.hpp"
#include "api/component/Transform.hpp"
#include "api/event/KeyboardEvent.hpp"
#include "api/event/MouseEvent.hpp"

namespace arcade {

    static arcade::component::Sprite setSprite(size_t height, size_t width, arcade::Color color)
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

    static arcade::component::Transform setTransform(float x, float y, float z)
    {
        arcade::component::Transform transform;

        transform.position.x = x;
        transform.position.y = y;
        transform.position.z = z;
        return (transform);
    }

    static void createMap(IScene &scene, std::vector<std::vector<int>> mapId)
    {
        arcade::component::Sprite spriteMap;
        arcade::component::Transform transformMap;
        
        for (size_t i = 0; i < mapId.size(); i++)
        {
            for (size_t j = 0; j < mapId[i].size(); j++)
            {
                if (mapId[i][j] == 0)
                {
                    // 0 pacgum
                    arcade::IEntity &pacgum = scene.newEntity("pacgum" + i + j);

                    transformMap = setTransform(j * 25 + 10, i * 25 + 10, 0);
                    spriteMap = setSprite(5, 5, Color {(char)255, (char)255, (char)255, (char)255});
                    pacgum.addComponent(spriteMap);
                    pacgum.addComponent(transformMap);
                }
                else if (mapId[i][j] == 1)
                {
                    // 1 wall
                    arcade::IEntity &border = scene.newEntity("border" + i + j);

                    transformMap = setTransform(j * 25, i * 25, 0);
                    spriteMap = setSprite(25, 25, Color {(char)255, (char)35, (char)0, (char)255});
                    border.addComponent(spriteMap);
                    border.addComponent(transformMap);
                }
                else if (mapId[i][j] == 2)
                {
                    // 2 super pacgum
                    arcade::IEntity &superPacgum = scene.newEntity("superPacgum" + i + j);

                    transformMap = setTransform(j * 25 + 6.25, i * 25 + 6.25, 0);
                    spriteMap = setSprite(12.5, 12.5, Color {(char)255, (char)255, (char)255, (char)255});
                    superPacgum.addComponent(spriteMap);
                    superPacgum.addComponent(transformMap);
                }
                else if (mapId[i][j] == 3)
                {
                    // 3 pacman
                    arcade::IEntity &pacman = scene.newEntity("pacman");

                    transformMap = setTransform(j * 25 + 2.5, i * 25 + 2.5, 0);
                    spriteMap = setSprite(20, 20, Color {(char)0, (char)255, (char)255, (char)255});
                    pacman.addComponent(spriteMap);
                    pacman.addComponent(transformMap);
                }
                else if (mapId[i][j] == 4)
                {
                    // 4 ghost
                    arcade::IEntity &ghost = scene.newEntity("ghost" + i + j);

                    transformMap = setTransform(j * 25 + 2.5, i * 25 + 2.5, 0);
                    spriteMap = setSprite(20, 20, Color {(char)0, (char)0, (char)255, (char)255});
                    ghost.addComponent(spriteMap);
                    ghost.addComponent(transformMap);
                }
            }
        }
    }

    void PacMan::init(IScene &scene)
    {
        //arcade::IEntity &map = scene.newEntity("square");
        // 19 * 21
        mapId = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 1},
            {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1},
            {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 0, 1, 1, 4, 1, 1, 0, 1, 0, 1, 1, 1, 1},
            {0, 0, 0, 0, 0, 0, 0, 1, 4, 4, 4, 1, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
            {1, 0, 0, 1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 1},
            {1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1},
            {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
            {1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
            {1, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        };

        m_score = 0;
        m_timePower = 0;
        createMap(scene, mapId);
        // 25 * 25
        scene.setWindowSize(475, 525);
        std::cout << "PacMan init" << std::endl;
        //createMap(scene);

        //square.addComponent(transformTest);
    }

    void PacMan::update(IScene &scene, float dt)
    {
        std::vector<std::reference_wrapper<IEntity>> pacman;
        component::Transform *transformComp = nullptr;
        
        //std::cout << "PacMan loop" << std::endl;
        if (m_timePower > 0)
        {
            // power activate
            m_timePower -= dt;
        }

        if (m_direction.x == 0 && m_direction.y == -1)
        {
            pacman = scene.getEntity("pacman");
            m_direction.y = 0;
            pacman[0].get().forEach([&](arcade::component::IComponent& comp)
            {
                if (auto ptr = dynamic_cast<component::Transform*>(&comp))
                    transformComp = ptr;
            });
            if (transformComp != nullptr)
            {
                if (mapId[(transformComp->position.y-2.5) / 25 - 1][(transformComp->position.x-2.5) / 25] == 0)
                {
                    mapId[(transformComp->position.y-2.5) / 25 - 1][(transformComp->position.x-2.5) / 25] = 5;
                    transformComp->position.y -= 25;
                    m_score++;
                }
                else if (mapId[(transformComp->position.y-2.5) / 25 - 1][(transformComp->position.x-2.5) / 25] == 2)
                {
                    mapId[(transformComp->position.y-2.5) / 25 - 1][(transformComp->position.x-2.5) / 25] = 5;
                    transformComp->position.y -= 25;
                    m_timePower = 10;
                }
                else if (mapId[(transformComp->position.y-2.5) / 25 - 1][(transformComp->position.x-2.5) / 25] == 4)
                {
                    transformComp->position.y -= 25;
                    //lose
                }
                else if (mapId[(transformComp->position.y-2.5) / 25 - 1][(transformComp->position.x-2.5) / 25] == 5)
                {
                    transformComp->position.y -= 25;
                }
            }
        }
        else if (m_direction.x == 0 && m_direction.y == 1)
        {
            pacman = scene.getEntity("pacman");
            m_direction.y = 0;
            pacman[0].get().forEach([&](arcade::component::IComponent& comp)
            {
                if (auto ptr = dynamic_cast<component::Transform*>(&comp))
                    transformComp = ptr;
            });
            if (transformComp != nullptr)
            {
                if (mapId[(transformComp->position.y-2.5) / 25 + 1][(transformComp->position.x-2.5) / 25] == 0)
                {
                    mapId[(transformComp->position.y-2.5) / 25 + 1][(transformComp->position.x-2.5) / 25] = 5;
                    transformComp->position.y += 25;
                    m_score++;
                }
                else if (mapId[(transformComp->position.y-2.5) / 25 + 1][(transformComp->position.x-2.5) / 25] == 2)
                {
                    mapId[(transformComp->position.y-2.5) / 25 + 1][(transformComp->position.x-2.5) / 25] = 5;
                    transformComp->position.y += 25;
                    m_timePower = 10;
                }
                else if (mapId[(transformComp->position.y-2.5) / 25 + 1][(transformComp->position.x-2.5) / 25] == 4)
                {
                    transformComp->position.y += 25;
                    //lose
                }
                else if (mapId[(transformComp->position.y-2.5) / 25 + 1][(transformComp->position.x-2.5) / 25] == 5)
                {
                    transformComp->position.y += 25;
                }
            }
        }
        else if (m_direction.x == -1 && m_direction.y == 0)
        {
            pacman = scene.getEntity("pacman");
            m_direction.x = 0;
            pacman[0].get().forEach([&](arcade::component::IComponent& comp)
            {
                if (auto ptr = dynamic_cast<component::Transform*>(&comp))
                    transformComp = ptr;
            });
            std::cout << transformComp << std::endl;
            std::cout << "aaaa" << std::endl;
            if (transformComp != nullptr)
            {
            std::cout << "aaa" << std::endl;
                if (mapId[(transformComp->position.y-2.5) / 25][(transformComp->position.x-2.5) / 25 - 1] == 0)
                {
            std::cout << "aa" << std::endl;
                    mapId[(transformComp->position.y-2.5) / 25][(transformComp->position.x-2.5) / 25 - 1] = 5;
                    transformComp->position.x -= 25;
                    m_score++;
                }
                else if (mapId[(transformComp->position.y-2.5) / 25][(transformComp->position.x-2.5) / 25 - 1] == 2)
                {
            std::cout << "aa" << std::endl;
                    mapId[(transformComp->position.y-2.5) / 25][(transformComp->position.x-2.5) / 25 - 1] = 5;
                    transformComp->position.x -= 25;
                    m_timePower = 10;
                }
                else if (mapId[(transformComp->position.y-2.5) / 25][(transformComp->position.x-2.5) / 25 - 1] == 4)
                {
            std::cout << "aa" << std::endl;
                    transformComp->position.x -= 25;
                    //lose
                }
                else if (mapId[(transformComp->position.y-2.5) / 25][(transformComp->position.x-2.5) / 25 - 1] == 5)
                {
            std::cout << "aa" << std::endl;
                    transformComp->position.x -= 25;
                }
                else
                {
            std::cout << "OOF" << std::endl;
                }
            }
        }
        else if (m_direction.x == 1 && m_direction.y == 0)
        {
            pacman = scene.getEntity("pacman");
            m_direction.x = 0;
            pacman[0].get().forEach([&](arcade::component::IComponent& comp)
            {
                if (auto ptr = dynamic_cast<component::Transform*>(&comp))
                    transformComp = ptr;
            });
            std::cout << "bbbb" << std::endl;
            if (transformComp != nullptr)
            {
                if (mapId[(transformComp->position.y-2.5) / 25][(transformComp->position.x-2.5) / 25 + 1] == 0)
                {
                    mapId[(transformComp->position.y-2.5) / 25][(transformComp->position.x-2.5) / 25 + 1] = 5;
                    transformComp->position.x += 25;
                    m_score++;
                }
                else if (mapId[(transformComp->position.y-2.5) / 25][(transformComp->position.x-2.5) / 25 + 1] == 2)
                {
                    mapId[(transformComp->position.y-2.5) / 25][(transformComp->position.x-2.5) / 25 + 1] = 5;
                    transformComp->position.x += 25;
                    m_timePower = 10;
                }
                else if (mapId[(transformComp->position.y-2.5) / 25][(transformComp->position.x-2.5) / 25 + 1] == 4)
                {
                    transformComp->position.x += 25;
                    //lose
                }
                else if (mapId[(transformComp->position.y-2.5) / 25][(transformComp->position.x-2.5) / 25 + 1] == 5)
                {
                    transformComp->position.x += 25;
                }
            }
        }
    }

    void PacMan::end(IScene &scene)
    {
        std::cout << "PacMan end" << std::endl;
        (void)scene;
    }

    void PacMan::onKeyEvent(const event::KeyboardEvent& key)
    {
        component::Transform *transformComp = nullptr;

        std::cout << "!!!!!" << std::endl;
        if (key.action == key.DOWN)
        {
            std::cout << (unsigned long)key.key << std::endl;
            switch (key.key)
            {
            case event::Key::KEY_ARROW_UP:
                std::cout << "!" << std::endl;
                m_direction = math::Vector3 {0, -1, 0};
                break;
            case event::Key::KEY_ARROW_DOWN:
                std::cout << "!" << std::endl;
                m_direction = math::Vector3 {0, 1, 0};
                break;
            case event::Key::KEY_ARROW_LEFT:
                std::cout << "!" << std::endl;
                m_direction = math::Vector3 {-1, 0, 0};
                break;
            case event::Key::KEY_ARROW_RIGHT:
                std::cout << "!" << std::endl;
                m_direction = math::Vector3 {1, 0, 0};
                break;
            default:
                std::cout << "?" << std::endl;
                break;
            }
        }
    }
    
    void PacMan::onMouseEvent(const event::MouseEvent& mouse)
    {
        if (mouse.action == mouse.DOWN)
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
        }
        else if (mouse.action == mouse.RELEASED)
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
        }
    }

}