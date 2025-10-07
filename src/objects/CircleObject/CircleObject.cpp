#include "CircleObject.h"

CircleObject::CircleObject(float radius, sf::Vector2f position) {
    circle.setRadius(radius);
    circle.setOrigin(circle.getGeometricCenter());
    circle.setPosition(position);
    circle.setFillColor(_color);
}

void CircleObject::setColor(sf::Color color) {
    _color = color;
    circle.setFillColor(color);
}

void CircleObject::update(float dt) {
    circle.move({50.f * dt, 0.f});
}

void CircleObject::draw(sf::RenderTarget &target) {
    target.draw(circle);
}
