#pragma once
#include "objects/CoordinateSystemObject/CoordinateSystemObject.h"
#include "SSE-engine/scenes/Scene.h"

#include "src/objects/VectorObject//Vector2DObject.h"

class VectorScene : public Scene {
public:
    void load(sf::RenderTarget &target) override {
        sf::Vector2u size = target.getSize();
        unsigned int x = size.x, y = size.y;

        std::unique_ptr<CoordinateSystemObject> coordinateSystem = std::make_unique<CoordinateSystemObject>(Vector2D(x * 0.5f, y * 0.5f));

        coordinateSystem->setColor(sf::Color(80, 80, 80));
        coordinateSystem->setStep(100.0f);
        manager.addObject(std::move(coordinateSystem));

        Vector2D origin = Vector2D(x * 0.5f, y * 0.5f);

        Vector2D vector1 = Vector2D(100, -100);
        std::unique_ptr<Vector2DObject> vector1Object = std::make_unique<Vector2DObject>(vector1, origin);

        vector1Object->drawStartAsDot(true);
        vector1Object->drawEndAsArrow(true);
        manager.addObject(std::move(vector1Object));

        Vector2D vector2 = vector1 * -1;
        std::unique_ptr<Vector2DObject> vector2Object = std::make_unique<Vector2DObject>(vector2, origin);
        vector2Object->drawStartAsDot(true);
        vector2Object->drawEndAsArrow(true);
        manager.addObject(std::move(vector2Object));

        Vector2D vector3 = Vector2D(200, 50);
        std::unique_ptr<Vector2DObject> vector3Object = std::make_unique<Vector2DObject>(vector3, origin);
        vector3Object->drawStartAsDot(true);
        vector3Object->drawEndAsArrow(true);
        manager.addObject(std::move(vector3Object));

        Vector2D vector4 = vector1 + vector3;
        std::unique_ptr<Vector2DObject> vector4Object = std::make_unique<Vector2DObject>(vector4, origin);
        vector4Object->drawStartAsDot(true);
        vector4Object->drawEndAsArrow(true);
        manager.addObject(std::move(vector4Object));
    }
};
