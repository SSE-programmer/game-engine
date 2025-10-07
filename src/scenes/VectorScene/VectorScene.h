#pragma once
#include "objects/CoordinateSystemObject/CoordinateSystemObject.h"
#include "SSE-engine/scenes/Scene.h"

#include "src/objects/VectorObject//Vector2DObject.h"

class VectorScene : public Scene {
public:
    void load(sf::RenderTarget &target) override {
        sf::Vector2u size = target.getSize();
        unsigned int x = size.x, y = size.y;

        manager.addObject(std::make_unique<CoordinateSystemObject>(Vector2D(x * 0.5f, y * 0.5f)));
        manager.addObject(std::make_unique<Vector2DObject>(Vector2D(100, -100), Vector2D(x * 0.5f, y * 0.5f)));
    }
};
