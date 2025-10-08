#pragma once
#include "SSE-engine/basic/Vector2D.h"
#include "SSE-engine/objects/GameObject.h"

class Vector2DObject : public GameObject {
private:
    Vector2D _vector;
    Vector2D _origin{0.0f, 0.0f};
    sf::Color _color{sf::Color::Black};
    bool _drawStartAsDot{false};
    bool _drawEndAsArrow{false};
    float _thickness = 2.0f;
    float _dotRadius = 3.0f;
    float _arrowLength = 12.0f;
    float _arrowWidth = 8.0f;

    void _drawDot(sf::RenderTarget &target, Vector2D position);

    void _drawArrow(sf::RenderTarget &target, Vector2D position, float angle);

public:
    explicit Vector2DObject(Vector2D vector): _vector(vector) {
    };

    Vector2DObject(Vector2D vector, Vector2D origin): _vector(vector), _origin(origin) {
    };

    void setOrigin(Vector2D origin);

    void setColor(sf::Color color);

    void setThickness(float value);

    void setStartDotRadius(float value);

    void setArrowLength(float value);

    void setArrowWidth(float value);

    void drawStartAsDot(bool value);

    void drawEndAsArrow(bool value);

    void update(float dt) override;

    void draw(sf::RenderTarget &target) override;
};
