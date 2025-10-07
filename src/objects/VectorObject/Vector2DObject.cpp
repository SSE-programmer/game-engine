#include "Vector2DObject.h"

#include "objects/CircleObject/CircleObject.h"
#include "SSE-engine/basic/Math.h"

void Vector2DObject::setOrigin(Vector2D origin) {
    _origin = origin;
}

void Vector2DObject::setColor(sf::Color color) {
    _color = color;
}

void Vector2DObject::update(float dt) {
}

void Vector2DObject::draw(sf::RenderTarget &target) {
    const float magnitude = Magnitude(_vector);
    const float thickness = 2.0f;
    const float arrowLength = 12.0f;
    const float arrowWidth = 8.0f;
    const float dotRadius = 3.0f;

    Vector2D direction = Normalize(_vector);

    sf::RectangleShape thickLine(sf::Vector2f(magnitude - arrowLength, thickness));
    thickLine.setOrigin({0.f, thickness / 2.f});
    thickLine.setPosition({_origin.x, _origin.y});

    const float angleDeg = std::atan2(direction.y, direction.x) * 180.f / static_cast<float>(PI);

    thickLine.setRotation(sf::degrees(angleDeg));
    thickLine.setFillColor(_color);
    target.draw(thickLine);

    CircleObject dot(dotRadius, {_origin.x, _origin.y});
    dot.setColor(_color);
    dot.draw(target);

    sf::ConvexShape arrow;
    arrow.setPointCount(3);
    arrow.setPoint(0, {0.f, 0.f});
    arrow.setPoint(1, {-arrowLength, arrowWidth / 2.f});
    arrow.setPoint(2, {-arrowLength, -arrowWidth / 2.f});
    arrow.setFillColor(_color);

    arrow.setPosition({_origin.x + direction.x * magnitude,
                       _origin.y + direction.y * magnitude});
    arrow.setRotation(sf::degrees(angleDeg));
    target.draw(arrow);
}
