#pragma once
#include "SFML/Graphics/CircleShape.hpp"
#include "SSE-engine/objects/GameObject.h"

class CircleObject : public GameObject {
private:
    sf::CircleShape circle;

public:
    CircleObject(float radius, sf::Vector2f position);

    void update(float dt) override;

    void draw(sf::RenderTarget &target) override;
};
