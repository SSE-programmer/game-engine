#include "CoordinateSystemObject.h"

#include "SSE-engine/basic/Math.h"
#include <cmath>

#include "objects/VectorObject/Vector2DObject.h"

void CoordinateSystemObject::setOrigin(Vector2D origin) {
    _origin = origin;
}

void CoordinateSystemObject::setColor(sf::Color color) {
    _color = color;
}

void CoordinateSystemObject::update(float dt) {
}

void CoordinateSystemObject::draw(sf::RenderTarget &target) {
    const sf::Vector2u renderTargetSize = target.getSize();
    constexpr float mainThickness = 2.0f;
    constexpr float step = 10.0f;
    constexpr float secondaryThickness = 1.0f;
    constexpr float arrowLength = 12.0f;
    constexpr float arrowWidth = 8.0f;
    constexpr float epsilon = step * 0.5 - 0.1;

    const float xLinesOffset = fmod(_origin.x, step);
    const float yLinesOffset = fmod(_origin.y, step);

    for (float x = xLinesOffset; x < renderTargetSize.x; x += step) {
        const bool isMainLine = abs(x - _origin.x) <= epsilon;

        const float thickness = isMainLine ? mainThickness : secondaryThickness;

        if (isMainLine) {
            Vector2DObject vector2DObject({0, static_cast<float>(renderTargetSize.y)}, {x, 0});

            vector2DObject.setColor(_color);
            vector2DObject.draw(target);
        } else {
            sf::RectangleShape thickLine(sf::Vector2f(thickness, renderTargetSize.y));

            thickLine.setPosition({x, 0});
            thickLine.setFillColor(_color);
            target.draw(thickLine);
        }
    }

    for (float y = yLinesOffset; y < renderTargetSize.y; y += step) {
        const bool isMainLine = abs(y - _origin.y) <= epsilon;

        const float thickness = isMainLine ? mainThickness : secondaryThickness;

        if (isMainLine) {
            Vector2DObject vector2DObject({static_cast<float>(renderTargetSize.x), 0}, {0, y});

            vector2DObject.setColor(_color);
            vector2DObject.draw(target);
        } else {
            sf::RectangleShape thickLine(sf::Vector2f(renderTargetSize.x, thickness));

            thickLine.setPosition({0, y});
            thickLine.setFillColor(_color);
            target.draw(thickLine);
        }
    }
}
