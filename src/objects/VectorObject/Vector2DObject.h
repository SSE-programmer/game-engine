#pragma once
#include "SSE-engine/basic/Vector2D.h"
#include "SSE-engine/objects/GameObject.h"

class Vector2DObject : public GameObject {
private:
    Vector2D _vector;
    Vector2D _origin{0.0f, 0.0f};
    sf::Color _color{sf::Color::Black};

public:
    explicit Vector2DObject(Vector2D vector): _vector(vector) {};

    Vector2DObject(Vector2D vector, Vector2D origin): _vector(vector), _origin(origin) {};

    void setOrigin(Vector2D origin);

    void setColor(sf::Color color);

    void update(float dt) override;

    void draw(sf::RenderTarget &target) override;
};
