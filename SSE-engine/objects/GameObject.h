#pragma once
#include <SFML/Graphics.hpp>

class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderTarget& target) = 0;
};