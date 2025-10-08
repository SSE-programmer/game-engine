#include "Vector2DObject.h"

#include "objects/CircleObject/CircleObject.h"
#include "SSE-engine/basic/Math.h"

void Vector2DObject::setOrigin(Vector2D origin) {
    _origin = origin;
}

void Vector2DObject::setColor(sf::Color color) {
    _color = color;
}

void Vector2DObject::setThickness(float value) {
    _thickness = value;
}

void Vector2DObject::setStartDotRadius(float value) {
    _dotRadius = value;
}

void Vector2DObject::setArrowLength(float value) {
    _arrowLength = value;
}

void Vector2DObject::setArrowWidth(float value) {
    _arrowWidth = value;
}

void Vector2DObject::drawStartAsDot(bool value) {
    _drawStartAsDot = value;
}

void Vector2DObject::drawEndAsArrow(bool value) {
    _drawEndAsArrow = value;
}

void Vector2DObject::update(float dt) {
}

void Vector2DObject::draw(sf::RenderTarget &target) {
    const float magnitude = Magnitude(_vector);

    Vector2D direction = Normalize(_vector);

    sf::RectangleShape thickLine(sf::Vector2f(magnitude - (_drawEndAsArrow ? _arrowLength : 0), _thickness));
    thickLine.setOrigin({0.f, _thickness / 2.f});
    thickLine.setPosition({_origin.x, _origin.y});

    const float angleDeg = std::atan2(direction.y, direction.x) * 180.f / static_cast<float>(PI);

    thickLine.setRotation(sf::degrees(angleDeg));
    thickLine.setFillColor(_color);
    target.draw(thickLine);

    if (_drawStartAsDot) {
        _drawDot(target, _origin);
    }

    if (_drawEndAsArrow) {
        _drawArrow(
            target,
            {
                _origin.x + direction.x * magnitude,
                _origin.y + direction.y * magnitude
            },
            angleDeg
        );
    }
}

void Vector2DObject::_drawDot(sf::RenderTarget &target, Vector2D position) {
    CircleObject dot(_dotRadius, {position.x, position.y});

    dot.setColor(_color);
    dot.draw(target);
}

void Vector2DObject::_drawArrow(sf::RenderTarget &target, Vector2D position, float angle) {
    sf::ConvexShape arrow;
    arrow.setPointCount(3);
    arrow.setPoint(0, {0.f, 0.f});
    arrow.setPoint(1, {-_arrowLength, _arrowWidth / 2.f});
    arrow.setPoint(2, {-_arrowLength, -_arrowWidth / 2.f});
    arrow.setFillColor(_color);

    arrow.setPosition({position.x, position.y});
    arrow.setRotation(sf::degrees(angle));
    target.draw(arrow);
}
