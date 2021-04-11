/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** PacMan
*/

#include <iostream>
#include <cstdlib>
#include <math.h>
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
                        std::cout << "pacgum" + std::to_string(i) + "_" + std::to_string(j) << std::endl;
                    arcade::IEntity &pacgum = scene.newEntity("pacgum" + std::to_string(i) + "_" + std::to_string(j));

                    transformMap = setTransform(j * 25 + 10, i * 25 + 10, 0);
                    spriteMap = setSprite(5, 5, Color {(char)255, (char)255, (char)255, (char)255});
                    pacgum.addComponent(spriteMap);
                    pacgum.addComponent(transformMap);
                }
                else if (mapId[i][j] == 1)
                {
                    // 1 wall
                    arcade::IEntity &border = scene.newEntity("border");

                    transformMap = setTransform(j * 25, i * 25, 0);
                    spriteMap = setSprite(25, 25, Color {(char)255, (char)35, (char)0, (char)255});
                    border.addComponent(spriteMap);
                    border.addComponent(transformMap);
                }
                else if (mapId[i][j] == 2)
                {
                    // 2 super pacgum
                    arcade::IEntity &superPacgum = scene.newEntity("superPacgum");

                    transformMap = setTransform(j * 25 + 6.25, i * 25 + 6.25, 0);
                    spriteMap = setSprite(12.5, 12.5, Color {(char)255, (char)255, (char)255, (char)255});
                    superPacgum.addComponent(spriteMap);
                    superPacgum.addComponent(transformMap);
                }
                else if (mapId[i][j] == 3)
                {
                    // 3 pacman
                    std::cout << "::" << std::endl;
                    arcade::IEntity &pacman = scene.newEntity("pacman");

                    transformMap = setTransform(j * 25 + 2.5, i * 25 + 2.5, 0);
                    spriteMap = setSprite(20, 20, Color {(char)0, (char)255, (char)255, (char)255});
                    pacman.addComponent(spriteMap);
                    pacman.addComponent(transformMap);
                }
                else if (mapId[i][j] == 4)
                {
                    // 4 ghost
                    arcade::IEntity &ghost = scene.newEntity("ghost");

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
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
            {1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 4, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 4, 4, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
            {1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1},
            {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
            {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
            {1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        };

        m_score = 0;
        m_timePower = 0;
        m_timeGhostStart = 0;
        m_timeGhost = 0;
        createMap(scene, mapId);
        // 25 * 25
        scene.setWindowSize(525, 625);
        std::cout << "PacMan init" << std::endl;
        //createMap(scene);

        //square.addComponent(transformTest);
    }

    static void moveGhost(IScene &scene, std::vector<std::vector<int>> mapId)
    {
        std::vector<std::reference_wrapper<IEntity>> ghost = scene.getEntity("ghost");

        for (size_t i = 0, numRand = rand() % 4; i < ghost.size(); i++)
        {
            float posx = 0;
            float posy = 0;

            ghost[i].get().forEach([&](arcade::component::IComponent& comp)
            {
                try
                {
                    component::Transform &ptr = dynamic_cast<component::Transform&>(comp);
                    
                    while (1)
                    {
                        if (numRand == 0)
                        {
                            posx = (ptr.position.x) / 25;
                            posy = (ptr.position.y) / 25 - 1;
                        }
                        else if (numRand == 1)
                        {
                            posx = (ptr.position.x) / 25;
                            posy = (ptr.position.y) / 25 + 1;
                        }
                        else if (numRand == 2)
                        {
                            posx = (ptr.position.x) / 25 - 1;
                            posy = (ptr.position.y) / 25;
                        }
                        else
                        {
                            posx = (ptr.position.x) / 25 + 1;
                            posy = (ptr.position.y) / 25;
                        }

                        if (mapId[posy][posx] != 1)
                            break;

                        std::cout << "pos " << mapId[posy][posx] << std::endl << "coord y" << posy << " coord x" << posx << std::endl;
                        ptr.position.x = (posx + 10) * 25;
                        ptr.position.y = (posy + 10) * 25;
                    }
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            });
        }
    }

    void PacMan::update(IScene &scene, float dt)
    {
        std::vector<std::reference_wrapper<IEntity>> pacman;
        
        //std::cout << "PacMan loop" << std::endl;
        std::cout << "Time: " << m_timeGhostStart << std::endl;
        m_timeGhostStart += dt;
        m_timeGhost += dt;
        if (m_timePower > 0)
        {
            // power activate
            m_timePower -= dt;
        }
        if (m_timeGhostStart > 10 && m_timeGhost > 1)
        {
            moveGhost(scene, mapId);
            m_timeGhost = 0;
        }

        if (m_direction.x == 0 && m_direction.y == -1)
        {
            pacman = scene.getEntity("pacman");
            m_direction.y = 0;
            
            pacman[0].get().forEach([&](arcade::component::IComponent& comp)
            {
                try
                {
                    component::Transform &ptr = dynamic_cast<component::Transform&>(comp);

                    float posx = (ptr.position.x) / 25;
                    float posy = (ptr.position.y) / 25 - 1;

                    std::cout << "coord y" << posy << " coord x" << posx << std::endl;
                    std::cout << "pos " << mapId[posy][posx] << std::endl;
                    if (mapId[posy][posx] == 0)
                    {
                        std::cout << "pacgum" + std::to_string((int)(posy - 0.1)) + "_" + std::to_string((int)(posx - 0.1)) << std::endl;
                        std::vector<std::reference_wrapper<arcade::IEntity>> ent = scene.getEntity("pacgum" + std::to_string((int)(posy - 0.1)) + "_" + std::to_string((int)(posx - 0.1)));

                    std::cout << "ici " << ent.size() << std::endl;
                        scene.removeEntity(ent[0]);
                        mapId[posy][posx] = 5;
                        ptr.position.y -= 25;
                        m_score++;
                    }
                    else if (mapId[posy][posx] == 2)
                    {
                        mapId[posy][posx] = 5;
                        ptr.position.y -= 25;
                        m_timePower = 10;
                    }
                    else if (mapId[posy][posx] == 4)
                    {
                        ptr.position.y -= 25;
                        //lose
                    }
                    else if (mapId[posy][posx] != 1)
                    {
                        ptr.position.y -= 25;
                    }
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            });
        }
        else if (m_direction.x == 0 && m_direction.y == 1)
        {
            pacman = scene.getEntity("pacman");
            m_direction.y = 0;

            pacman[0].get().forEach([&](arcade::component::IComponent& comp)
            {
                try
                {
                    component::Transform &ptr = dynamic_cast<component::Transform&>(comp);
                    float posx = (ptr.position.x) / 25;
                    float posy = (ptr.position.y) / 25 + 1;
                
                    std::cout << "pos " << mapId[posy][posx] << std::endl << "coord y" << posy << " coord x" << posx << std::endl;
                    if (mapId[posy][posx] == 0)
                    {
                        mapId[posy][posx] = 5;
                        ptr.position.y += 25;
                        m_score++;
                    }
                    else if (mapId[posy][posx] == 2)
                    {
                        mapId[posy][posx] = 5;
                        ptr.position.y += 25;
                        m_timePower = 10;
                    }
                    else if (mapId[posy][posx] == 4)
                    {
                        ptr.position.y += 25;
                        //lose
                    }
                    else if (mapId[posy][posx] != 1)
                    {
                        ptr.position.y += 25;
                    }
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            });
        }
        else if (m_direction.x == -1 && m_direction.y == 0)
        {
            pacman = scene.getEntity("pacman");
            m_direction.x = 0;
            
            pacman[0].get().forEach([&](arcade::component::IComponent& comp)
            {
                try
                {
                    component::Transform &ptr = dynamic_cast<component::Transform&>(comp);
                    float posx = (ptr.position.x) / 25 - 1;
                    float posy = (ptr.position.y) / 25;

                    std::cout << "pos " << mapId[posy][posx] << std::endl << "coord y " << posy << " coord x " << posx << std::endl;
                    if (posx < 0)
                        ptr.position.x = 21 * 25;
                    if (mapId[posy][posx] == 0)
                    {
                        mapId[posy][posx] = 5;
                        ptr.position.x -= 25;
                        m_score++;
                    }
                    else if (mapId[posy][posx] == 2)
                    {
                        mapId[posy][posx] = 5;
                        ptr.position.x -= 25;
                        m_timePower = 10;
                    }
                    else if (mapId[posy][posx] == 4)
                    {
                        ptr.position.x -= 25;
                        //lose
                    }
                    else if (mapId[posy][posx] != 1)
                    {
                        ptr.position.x -= 25;
                    }
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            });
        }
        else if (m_direction.x == 1 && m_direction.y == 0)
        {
            pacman = scene.getEntity("pacman");
            m_direction.x = 0;

            pacman[0].get().forEach([&](arcade::component::IComponent& comp)
            {
                try
                {
                    component::Transform &ptr = dynamic_cast<component::Transform&>(comp);
                    float posx = (ptr.position.x) / 25 + 1;
                    float posy = (ptr.position.y) / 25;

                    std::cout << "pos " << mapId[posy][posx] << std::endl << "coord y " << posy << " coord x " << posx << std::endl;
                    if (posx > 20)
                        ptr.position.x = -25;
                    if (mapId[posy][posx] == 0)
                    {
                        mapId[posy][posx] = 5;
                        ptr.position.x += 25;
                        m_score++;
                    }
                    else if (mapId[posy][posx] == 2)
                    {
                        mapId[posy][posx] = 5;
                        ptr.position.x += 25;
                        m_timePower = 10;
                    }
                    else if (mapId[posy][posx] == 4)
                    {
                        ptr.position.x += 25;
                        //lose
                    }
                    else if (mapId[posy][posx] != 1)
                    {
                        ptr.position.x += 25;
                    }
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            });
        }
    }

    void PacMan::end(IScene &scene)
    {
        std::cout << "PacMan end" << std::endl;
        (void)scene;
    }

    void PacMan::onKeyEvent(const event::KeyboardEvent& key)
    {
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