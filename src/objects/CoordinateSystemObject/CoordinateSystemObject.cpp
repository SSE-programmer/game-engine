#include "CoordinateSystemObject.h"

#include <cmath>

#include "objects/VectorObject/Vector2DObject.h"

void CoordinateSystemObject::setOrigin(Vector2D origin) {
    _origin = origin;
}

void CoordinateSystemObject::setColor(sf::Color color) {
    _color = color;
}

void CoordinateSystemObject::setStep(float value) {
    _step = value;
}

void CoordinateSystemObject::setMainThickness(float value) {
    _mainThickness = value;
}

void CoordinateSystemObject::setSecondaryThickness(float value) {
    _secondaryThickness = value;
}

void CoordinateSystemObject::update(float dt) {
}

void CoordinateSystemObject::draw(sf::RenderTarget &target) {
    const sf::Vector2u renderTargetSize = target.getSize();
    const float epsilon = _step * 0.5 - 0.1;
    sf::Color secondaryLineColor = sf::Color(_color.r, _color.g, _color.b, 100);
    const float xLinesOffset = fmod(_origin.x, _step);
    const float yLinesOffset = fmod(_origin.y, _step);

    for (float x = xLinesOffset; x < renderTargetSize.x; x += _step) {
        const bool isMainLine = abs(x - _origin.x) <= epsilon;
        Vector2DObject secondaryLine({0, static_cast<float>(renderTargetSize.y)}, {x, 0});

        secondaryLine.setThickness(isMainLine ? _mainThickness : _secondaryThickness);
        secondaryLine.setColor(isMainLine ? _color : secondaryLineColor);
        secondaryLine.drawEndAsArrow(isMainLine);
        secondaryLine.draw(target);
    }

    for (float y = yLinesOffset; y < renderTargetSize.y; y += _step) {
        const bool isMainLine = abs(y - _origin.y) <= epsilon;
        Vector2DObject secondaryLine({static_cast<float>(renderTargetSize.x), 0}, {0, y});

        secondaryLine.setThickness(isMainLine ? _mainThickness : _secondaryThickness);
        secondaryLine.setColor(isMainLine ? _color : secondaryLineColor);
        secondaryLine.drawEndAsArrow(isMainLine);
        secondaryLine.draw(target);
    }
}
