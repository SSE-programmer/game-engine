#pragma once
#include "SSE-engine/basic/Vector2D.h"
#include "SSE-engine/objects/GameObject.h"

class CoordinateSystemObject : public GameObject {
private:
    Vector2D _origin{0.0f, 0.0f};
    sf::Color _color{sf::Color::Green};

public:
    CoordinateSystemObject();
    explicit CoordinateSystemObject(Vector2D origin): _origin(origin) {};

    void setOrigin(Vector2D origin);

    void setColor(sf::Color color);

    void update(float dt) override;

    void draw(sf::RenderTarget &target) override;
};
