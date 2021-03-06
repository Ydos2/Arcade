/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-arcade-mathias.ressort
** File description:
** Nibbler
*/

#include <iostream>
#include <vector>
#include <string>

#include "Nibbler.hpp"
#include "api/component/Sprite.hpp"
#include "api/component/AsciiSprite.hpp"
#include "api/component/Transform.hpp"
#include "api/event/KeyboardEvent.hpp"

namespace arcade {

    arcade::component::Sprite Nibbler::setSprite(size_t height, size_t width, arcade::Color color)
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

    void Nibbler::initMap(IScene &scene)
    {
        std::cout << "Nibbler initMap" << std::endl;
        arcade::component::Sprite wallSprite;
        arcade::component::AsciiSprite wallAsciiSprite;
        arcade::component::Transform wallTransform;

        m_map = {
            "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
            "W     W      W         W     W",
            "W WWW W WWWW W  W WWWW W WWW W",
            "W W     W         W        W W",
            "W W WW WW WW WWWW W WWW WW W W",
            "W   W                    W   W",
            "WWWWW WWWWW WWW WW WWWWW WWWWW",
            "W     W   W        W   W     W",
            "W WWWWW W WWW WW WWW W WWWWW W",
            "W W     W            W     W W",
            "W W WWW W WW WW W WW W WWW W W",
            "W W   W      W         W   W W",
            "W W W WWW W WWWWWW W WWW W W W",
            "W   W     W        W     W   W",
            "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
        };
        m_mapDimensions = {(float)(m_map[0].size()), (float)(m_map.size())};

        for (size_t row = 0; row < m_mapDimensions.y; row++) {
            for (size_t col = 0; char c = m_map[row][col]; col++) {
                if (c != ' ') {
                    arcade::IEntity &wall = scene.newEntity("wall");
                    wallAsciiSprite.height = 1;
                    wallAsciiSprite.width = 1;
                    std::vector<char> vector = {c};
                    std::shared_ptr<std::vector<char>> vectorPtr(&vector);
                    wallAsciiSprite.sprite = vectorPtr;

                    wallSprite = setSprite(
                        16,
                        16,
                        Color {(char)255, (char)255, (char)255, (char)255}
                    );

                    wallTransform.position = {(float)col, (float)row, 0};

                    wall.addComponent(wallAsciiSprite);
                    wall.addComponent(wallSprite);
                    wall.addComponent(wallTransform);
                }
            }
        }
        std::cout << "Nibbler initMap test" << std::endl;
    }

    void Nibbler::initSnake(IScene &scene)
    {
        std::cout << "Nibbler initSnake" << std::endl;
        arcade::component::Sprite sprite;
        arcade::component::AsciiSprite asciiSprite;
        arcade::component::Transform headTransform;
        arcade::IEntity &head = scene.newEntity("head");

        m_segmentsPos.push_back({14, 7});
        m_direction = RIGHT;

        sprite = setSprite(
            16,
            16,
            Color {(char)255, (char)255, (char)0, (char)0}
        );

        asciiSprite.height = 1;
        asciiSprite.width = 1;
        std::vector<char> vector = {'O'};
        std::shared_ptr<std::vector<char>> vectorPtr(&vector);
        asciiSprite.sprite = vectorPtr;

        headTransform.position = {
            m_segmentsPos[0].x,
            m_segmentsPos[0].y,
            1
        };

        head.addComponent(asciiSprite);
        head.addComponent(sprite);
        head.addComponent(headTransform);

        for (size_t i = 0; i < 3; i++) {
            arcade::component::Transform tailTransform;
            arcade::IEntity &tail = scene.newEntity("tail" + std::to_string(i));
            
            m_segmentsPos.push_back({
                m_segmentsPos[0].x,
                m_segmentsPos[0].y - (i + 1)
            });

            tailTransform.position = {
                m_segmentsPos[i + 1].x,
                m_segmentsPos[i + 1].y,
                1
            };

            tail.addComponent(asciiSprite);
            tail.addComponent(sprite);
            tail.addComponent(tailTransform);
        }
    }

    void Nibbler::initFood(IScene &scene)
    {
        std::cout << "Nibbler initFood" << std::endl;
        m_foodPosition = {1, 1};
        arcade::component::Sprite sprite;
        arcade::component::AsciiSprite asciiSprite;
        arcade::component::Transform transform;
        arcade::IEntity &food = scene.newEntity("food");

        sprite = setSprite(
            16,
            16,
            Color {(char)0, (char)255, (char)0, (char)0}
        );

        asciiSprite.height = 1;
        asciiSprite.width = 1;
        std::vector<char> vector = {'*'};
        std::shared_ptr<std::vector<char>> vectorPtr(&vector);
        asciiSprite.sprite = vectorPtr;

        transform.position = {1, 1, 2};

        food.addComponent(asciiSprite);
        food.addComponent(sprite); 
        food.addComponent(transform);

        moveFood(scene);
    }

    void Nibbler::init(IScene &scene)
    {
        std::cout << "Nibbler init" << std::endl;
        srand((unsigned)time(NULL));

        initMap(scene);
        initSnake(scene);
        initFood(scene);
    }

    bool Nibbler::isWall(math::Vector2 coords)
    {
        std::cout << "Nibbler isWall: " << coords.x << ',' << coords.y
                  << " -> " << m_map[coords.y][coords.x] << std::endl;
        if (m_map[coords.y][coords.x] == 'W') {
            std::cout << "It's a wall" << std::endl;
            return (true);
        }
        std::cout << "It's not a wall" << std::endl;
        return (false);
    }

    bool Nibbler::isSnake(math::Vector2 coords, bool ignoreHead)
    {
        std::cout << "Nibbler isSnake" << std::endl;
        for (size_t i = ignoreHead ? 1 : 0; i < m_segmentsPos.size(); i++) {
            if (m_segmentsPos[i].x == coords.x && m_segmentsPos[i].y == coords.y)
                return (true);
        }
        return (false);
    }

    bool Nibbler::isFood(math::Vector2 coords)
    {
        std::cout << "Nibbler isFood" << std::endl;
        if (m_foodPosition.x == coords.x && m_foodPosition.y == coords.y)
            return (true);
        return (false);
    }

    void Nibbler::moveFood(IScene &scene)
    {
        std::cout << "Nibbler moveFood" << std::endl;
        math::Vector2 coords = {0, 0};
        while (isWall(coords) || isSnake(coords, false)) {
            coords = {
                (float)(random() % (int)(m_mapDimensions.x)),
                (float)(random() % (int)(m_mapDimensions.y))
            };
        }
        m_foodPosition = coords;
        std::reference_wrapper<IEntity> food = scene.getEntity("food")[0];
            food.get().forEach([&](arcade::component::IComponent& component) {
                if (auto ptr = dynamic_cast<component::Transform*>(&component)) {
                    ptr->position = {
                        m_foodPosition.x,
                        m_foodPosition.y,
                        2
                    };
                }
            });
    }

    void Nibbler::moveSnake(IScene &scene, float dt)
    {
        std::cout << "Nibbler moveSnake" << std::endl;
        for (size_t i = m_segmentsPos.size() - 1; i > 0; i--) {
            m_segmentsPos[i] = m_segmentsPos[i - 1];

            std::reference_wrapper<IEntity> segment =
                scene.getEntity("tail" + std::to_string(i - 1))[0];
            segment.get().forEach([&](arcade::component::IComponent& component) {
                if (auto ptr = dynamic_cast<component::Transform*>(&component)) {
                    ptr->position = {
                        m_segmentsPos[i].x,
                        m_segmentsPos[i].y,
                        1
                    };
                }
            });
        }

        switch (m_direction) {
        case UP:
            m_segmentsPos[0].y--;
            break;
        case DOWN:
            m_segmentsPos[0].y++;
            break;
        case LEFT:
            m_segmentsPos[0].x--;
            break;
        case RIGHT:
            m_segmentsPos[0].x++;
            break;
        default:
            break;
        }
        std::reference_wrapper<IEntity> head = scene.getEntity("head")[0];
        head.get().forEach([&](arcade::component::IComponent& component) {
            if (auto ptr = dynamic_cast<component::Transform*>(&component)) {
                ptr->position = {
                    m_segmentsPos[0].x,
                    m_segmentsPos[0].y,
                    1
                };
            }
        });
    }

    void Nibbler::makeSnakeGrow(IScene &scene)
    {
        std::cout << "Nibbler makeSnakeGrow" << std::endl;
        math::Vector2 lastSegment = m_segmentsPos[m_segmentsPos.size() - 1];
        std::cout << "test0" << std::endl;
        std::vector<math::Vector2> surrondingTiles = {
            {lastSegment.x - 1, lastSegment.y},
            {lastSegment.x + 1, lastSegment.y},
            {lastSegment.x, lastSegment.y - 1},
            {lastSegment.x, lastSegment.y + 1}
        };
        std::cout << "test1" << std::endl;

        for (math::Vector2 tile : surrondingTiles) {
        std::cout << "test2" << std::endl;
            if (tile.x >= 0 && tile.y >= 0 && tile.x < m_mapDimensions.x &&
                tile.y < m_mapDimensions.y && !isWall(tile) && !isSnake(tile, false)) {

            std::cout << "test3" << std::endl;
                m_segmentsPos.push_back(tile);

            std::cout << "test4" << std::endl;
                arcade::component::Sprite sprite;
                arcade::component::AsciiSprite asciiSprite;
                arcade::component::Transform transform;
                arcade::IEntity &tail =
                    scene.newEntity("tail" + std::to_string(m_segmentsPos.size() - 2));

            std::cout << "test5" << std::endl;
                sprite = setSprite(
                    16,
                    16,
                    Color {(char)255, (char)255, (char)0, (char)0}
                );

            std::cout << "test6" << std::endl;
                asciiSprite.height = 1;
                asciiSprite.width = 1;
                std::vector<char> vector = {'O'};
                std::shared_ptr<std::vector<char>> vectorPtr(&vector);
                asciiSprite.sprite = vectorPtr;
            std::cout << "test7" << std::endl;

                transform.position = {tile.x, tile.y, 1};
            std::cout << "test8" << std::endl;

                tail.addComponent(asciiSprite);
                tail.addComponent(sprite);
                tail.addComponent(transform);
            std::cout << "test9" << std::endl;
                return;
            }
        }
        scene.exit();
    }

    void Nibbler::update(IScene &scene, float dt)
    {
        std::cout << "Nibbler update" << std::endl;
        
        static float time = 0;
        
        time += dt;
        if (time < 0.5)
            return;
        time = 0;

        std::cout << "Food is at:" << m_foodPosition.x << ',' << m_foodPosition.y << std::endl;
        std::cout << "Current length is:" << m_segmentsPos.size() << std::endl;
        moveSnake(scene, dt);
        if (isFood(m_segmentsPos[0])) {
            makeSnakeGrow(scene);
            moveFood(scene);
        }
        if (isWall(m_segmentsPos[0]) || isSnake(m_segmentsPos[0], true)) {
            std::cout << "Nibbler update: game over" << std::endl;
            scene.exit();
        }
    }

    void Nibbler::end(IScene &scene)
    {
        std::cout << "Nibbler end" << std::endl;
        (void)scene;
    }

    void Nibbler::onKeyEvent(const event::KeyboardEvent& key)
    {
        std::cout << "Nibbler onKeyEvent" << std::endl;
        switch (key.key) {
            case event::Key::KEY_ARROW_UP:
                if (m_direction != DOWN)
                    m_direction = UP;
                break;
            case event::Key::KEY_ARROW_DOWN:
                if (m_direction != UP)
                    m_direction = DOWN;
                break;
            case event::Key::KEY_ARROW_LEFT:
                if (m_direction != RIGHT)
                    m_direction = LEFT;
                break;
            case event::Key::KEY_ARROW_RIGHT:
                if (m_direction != LEFT)
                    m_direction = RIGHT;
                break;
            default:
                break;
        }
    }
    
    void Nibbler::onMouseEvent(const event::MouseEvent& mouse)
    {
        std::cout << "Nibbler onMouseEvent" << std::endl;
        (void)mouse;
    }

}