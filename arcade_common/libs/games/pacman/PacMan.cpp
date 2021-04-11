/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** PacMan
*/

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include "PacMan.hpp"
#include "api/component/Sprite.hpp"
#include "api/component/AsciiSprite.hpp"
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
                    arcade::IEntity &pacgum = scene.newEntity("pacgum" + std::to_string(i) + "_" + std::to_string(j));
                    
                    transformMap = setTransform(j + 0.4, i + 0.4, 0);
                    spriteMap = setSprite(3, 3, Color {(char)255, (char)255, (char)255, (char)255});
                    pacgum.addComponent(spriteMap);
                    pacgum.addComponent(transformMap);
                    pacgum.addComponent(transformMap);
                }
                else if (mapId[i][j] == 1)
                {
                    // 1 wall
                    arcade::IEntity &border = scene.newEntity("border");

                    transformMap = setTransform(j, i, 0);
                    spriteMap = setSprite(16, 16, Color {(char)255, (char)35, (char)0, (char)255});
                    border.addComponent(spriteMap);
                    border.addComponent(transformMap);
                }
                else if (mapId[i][j] == 2)
                {
                    // 2 super pacgum
                    arcade::IEntity &superPacgum = scene.newEntity("superPacgum" + std::to_string(i) + "_" + std::to_string(j));

                    transformMap = setTransform(j + 0.25, i + 0.25, 0);
                    spriteMap = setSprite(10, 10, Color {(char)255, (char)255, (char)255, (char)255});
                    superPacgum.addComponent(spriteMap);
                    superPacgum.addComponent(transformMap);
                }
                else if (mapId[i][j] == 3)
                {
                    // 3 pacman
                    arcade::IEntity &pacman = scene.newEntity("pacman");

                    transformMap = setTransform(j + 0.1, i + 0.1, 0);
                    spriteMap = setSprite(12, 12, Color {(char)0, (char)255, (char)255, (char)255});
                    pacman.addComponent(spriteMap);
                    pacman.addComponent(transformMap);
                }
                else if (mapId[i][j] == 4)
                {
                    // 4 ghost
                    arcade::IEntity &ghost = scene.newEntity("ghost");

                    transformMap = setTransform(j + 0.1, i + 0.1, 0);
                    spriteMap = setSprite(12, 12, Color {(char)0, (char)0, (char)255, (char)255});
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
            {5, 0, 0, 0, 0, 0, 0, 1, 0, 4, 4, 4, 0, 1, 0, 0, 0, 0, 0, 0, 5},
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
        m_savedMapId = mapId;

        m_score = 0;
        m_timePower = 0;
        m_timeGhostStart = 0;
        m_timeGhost = 0;
        m_winTime = 1;
        createMap(scene, mapId);
        //1
        scene.setWindowSize(336, 400);
        std::cout << "PacMan init" << std::endl;
        //createMap(scene);

        //square.addComponent(transformTest);
    }

    static std::vector<std::reference_wrapper<IEntity>> getSortedEntities(
        IScene &scene)
    {
        std::vector<std::reference_wrapper<IEntity>> entities;

        scene.forEach([&](IEntity& currentEnt) {
            entities.push_back(currentEnt);
        });
        std::sort(entities.begin(), entities.end(), [](IEntity& a, IEntity& b) {
            component::Transform transformA;
            component::Transform transformB;

            a.forEach([&](component::IComponent& currentComp) {
                try {
                    transformA = dynamic_cast<component::Transform&>(currentComp);
                } catch (std::exception& e) {}
            });
            b.forEach([&](component::IComponent& currentComp) {
                try {
                    transformB = dynamic_cast<component::Transform&>(currentComp);
                } catch (std::exception& e) {}
            });
            return (transformA.position.z > transformB.position.z);
        });
        return (entities);
    }

    static void lose(IScene &scene, std::vector<std::vector<int>> mapId)
    {
        std::vector<std::reference_wrapper<IEntity>> sortedEntities = getSortedEntities(scene);

        for (size_t i = 0; i < sortedEntities.size(); i++)
            scene.removeEntity(sortedEntities[i]);
        createMap(scene, mapId);
    }

    static int win(IScene &scene, std::vector<std::vector<int>> mapId)
    {
        std::vector<std::reference_wrapper<IEntity>> sortedEntities = getSortedEntities(scene);

        for (size_t i = 0; i < sortedEntities.size(); i++)
            scene.removeEntity(sortedEntities[i]);
        createMap(scene, mapId);
        return 1;
    }

    static int moveGhost(IScene &scene, std::vector<std::vector<int>> mapId)
    {
        std::vector<std::reference_wrapper<IEntity>> ghost = scene.getEntity("ghost");

        for (size_t i = 0; i < ghost.size(); i++)
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
                        size_t numRand = rand() % 4;

                        if (numRand == 0)
                        {
                            posx = (ptr.position.x);
                            posy = (ptr.position.y) - 1;
                        }
                        else if (numRand == 1)
                        {
                            posx = (ptr.position.x);
                            posy = (ptr.position.y) + 1;
                        }
                        else if (numRand == 2)
                        {
                            posx = (ptr.position.x) - 1;
                            posy = (ptr.position.y);
                        }
                        else
                        {
                            posx = (ptr.position.x) + 1;
                            posy = (ptr.position.y);
                        }

                        if (mapId[posy][posx] == 3)
                            return 1;
                        else if (mapId[posy][posx] != 1)
                            break;
                    }
                    std::cout << "pos " << mapId[posy][posx] << std::endl << "coord y" << posy << " coord x" << posx << std::endl;
                    ptr.position.x = (posx);
                    ptr.position.y = (posy);
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            });
        }
        return 0;
    }

    void PacMan::update(IScene &scene, float dt)
    {
        std::vector<std::reference_wrapper<IEntity>> pacman;
        float speedPacman = 8;
        bool activePower = false;
        
        //std::cout << "PacMan loop" << std::endl;
        std::cout << "Time: " << m_timeGhostStart << std::endl;
        m_timeGhostStart += dt;
        m_timeGhost += dt * m_winTime;
        if (m_timePower > 0)
        {
            pacman = scene.getEntity("pacman");
            std::vector<std::reference_wrapper<IEntity>> ghost = scene.getEntity("ghost");
            
            pacman[0].get().forEach([&](arcade::component::IComponent& comp)
            {
                try
                {
                    component::Sprite &ptr = dynamic_cast<component::Sprite&>(comp);

                    ptr = setSprite(12, 12, Color {(char)255, (char)255, (char)255, (char)255});
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            });
            for (size_t i = 0; i < ghost.size(); i++)
            {
                ghost[i].get().forEach([&](arcade::component::IComponent& comp)
                {
                    try
                    {
                        component::Sprite &ptr = dynamic_cast<component::Sprite&>(comp);

                        ptr = setSprite(12, 12, Color {(char)75, (char)75, (char)75, (char)255});
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                });
            }
            m_timePower -= dt;
            activePower = true;
        }
        else if (activePower == true)
        {
            m_timePower -= dt;
            activePower = false;
            pacman = scene.getEntity("pacman");
            std::vector<std::reference_wrapper<IEntity>> ghost = scene.getEntity("ghost");
            
            pacman[0].get().forEach([&](arcade::component::IComponent& comp)
            {
                try
                {
                    component::Sprite &ptr = dynamic_cast<component::Sprite&>(comp);

                    ptr = setSprite(12, 12, Color {(char)0, (char)255, (char)255, (char)255});
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            });
            for (size_t i = 0; i < ghost.size(); i++)
            {
                ghost[i].get().forEach([&](arcade::component::IComponent& comp)
                {
                    try
                    {
                        component::Sprite &ptr = dynamic_cast<component::Sprite&>(comp);

                        ptr = setSprite(12, 12, Color {(char)0, (char)0, (char)255, (char)255});
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                });
            }
        }
        if (m_timeGhostStart > 10 && m_timeGhost > 1) 
        {
            if (moveGhost(scene, mapId) == 1)
            {
                mapId = m_savedMapId;
                lose(scene, mapId);
                m_winTime = 1;
                m_score = 0;
                m_timePower = 0;
                m_timeGhostStart = 0;
            }
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

                    float posx = (ptr.position.x);
                    float posy = (ptr.position.y - 1);

                    std::cout << "coord y" << posy << " coord x" << posx << std::endl;
                    std::cout << "pos " << mapId[posy][posx] << std::endl;
                    if (mapId[posy][posx] == 0)
                    {
                        scene.removeEntity("pacgum" + std::to_string((int)(posy - 0.1)) + "_" + std::to_string((int)(posx - 0.1)));
                        mapId[posy][posx] = 5;
                        ptr.position.y -= 1;
                        m_score++;
                        if (m_score >= 239)
                        {
                            mapId = m_savedMapId;
                            win(scene, mapId);
                        }
                    }
                    else if (mapId[posy][posx] == 2)
                    {
                        scene.removeEntity("superPacgum" + std::to_string((int)(posy - 0.1)) + "_" + std::to_string((int)(posx - 0.1)));
                        mapId[posy][posx] = 5;
                        m_timePower = 10;
                        ptr.position.y -= 1;
                    }
                    else if (mapId[posy][posx] == 4)
                    {
                        mapId = m_savedMapId;
                        lose(scene, mapId);
                        m_winTime = 1;
                        m_score = 0;
                        m_timePower = 0;
                        m_timeGhostStart = 0;
                        m_timeGhost = 0;
                    }
                    else if (mapId[posy][posx] != 1)
                        ptr.position.y -= 1;
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
                    float posx = (ptr.position.x);
                    float posy = (ptr.position.y + 1);
                
                    std::cout << "pos " << mapId[posy][posx] << std::endl << "coord y" << posy << " coord x" << posx << std::endl;
                    if (mapId[posy][posx] == 0)
                    {
                        scene.removeEntity("pacgum" + std::to_string((int)(posy - 0.1)) + "_" + std::to_string((int)(posx - 0.1)));
                        mapId[posy][posx] = 5;
                        m_score++;
                        ptr.position.y += 1;
                        if (m_score >= 239)
                        {
                            mapId = m_savedMapId;
                            win(scene, mapId);
                        }
                    }
                    else if (mapId[posy][posx] == 2)
                    {
                        scene.removeEntity("superPacgum" + std::to_string((int)(posy - 0.1)) + "_" + std::to_string((int)(posx - 0.1)));
                        mapId[posy][posx] = 5;
                        m_timePower = 10;
                        ptr.position.y += 1;
                    }
                    else if (mapId[posy][posx] == 4)
                    {
                        mapId = m_savedMapId;
                        lose(scene, mapId);
                        m_winTime = 1;
                        m_score = 0;
                        m_timePower = 0;
                        m_timeGhostStart = 0;
                        m_timeGhost = 0;
                    }
                    else if (mapId[posy][posx] != 1)
                        ptr.position.y += 1;
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
                    float posx = (ptr.position.x - 1);
                    float posy = (ptr.position.y);

                    std::cout << "pos " << mapId[posy][posx] << std::endl << "coord y " << posy << " coord x " << posx << std::endl;
                    if (posx < 0)
                    {
                        ptr.position.x = 20;
                        return;
                    }
                    if (mapId[posy][posx] == 0)
                    {
                        scene.removeEntity("pacgum" + std::to_string((int)(posy - 0.1)) + "_" + std::to_string((int)(posx - 0.1)));
                        mapId[posy][posx] = 5;
                        ptr.position.x -= 1;
                        m_score++;
                        if (m_score >= 239)
                        {
                            mapId = m_savedMapId;
                            m_winTime += win(scene, mapId);
                        }
                    }
                    else if (mapId[posy][posx] == 2)
                    {
                        scene.removeEntity("superPacgum" + std::to_string((int)(posy - 0.1)) + "_" + std::to_string((int)(posx - 0.1)));
                        mapId[posy][posx] = 5;
                        ptr.position.x -= 1;
                        m_timePower = 10;
                    }
                    else if (mapId[posy][posx] == 4)
                    {
                        mapId = m_savedMapId;
                        lose(scene, mapId);
                        m_winTime = 1;
                        m_score = 0;
                        m_timePower = 0;
                        m_timeGhostStart = 0;
                        m_timeGhost = 0;
                    }
                    else if (mapId[posy][posx] != 1)
                        ptr.position.x -= 1;
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
                    float posx = (ptr.position.x + 1);
                    float posy = (ptr.position.y);

                    std::cout << "pos " << mapId[posy][posx] << std::endl << "coord y " << posy << " coord x " << posx << std::endl;
                    if (posx > 20)
                    {
                        ptr.position.x = 0;
                        return;
                    }
                    if (mapId[posy][posx] == 0)
                    {
                        scene.removeEntity("pacgum" + std::to_string((int)(posy - 0.1)) + "_" + std::to_string((int)(posx - 0.1)));
                        mapId[posy][posx] = 5;
                        ptr.position.x += 1;
                        m_score++;
                        if (m_score >= 239)
                        {
                            mapId = m_savedMapId;
                            m_winTime += win(scene, mapId);
                        }
                    }
                    else if (mapId[posy][posx] == 2)
                    {
                        scene.removeEntity("superPacgum" + std::to_string((int)(posy - 0.1)) + "_" + std::to_string((int)(posx - 0.1)));
                        mapId[posy][posx] = 5;
                        ptr.position.x += 1;
                        m_timePower = 10;
                    }
                    else if (mapId[posy][posx] == 4)
                    {
                        mapId = m_savedMapId;
                        lose(scene, mapId);
                        m_winTime = 1;
                        m_score = 0;
                        m_timePower = 0;
                        m_timeGhostStart = 0;
                        m_timeGhost = 0;
                    }
                    else if (mapId[posy][posx] != 1)
                        ptr.position.x += 1;
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