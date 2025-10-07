#pragma once
#include "SSE-engine/scenes/Scene.h"

#include "src/objects/VectorObject//Vector2DObject.h"

class VectorScene : public Scene {
public:
    void load() override {
        manager.addObject(std::make_unique<Vector2DObject>(Vector2D(100, -100), Vector2D(500, 500)));
    }
};
