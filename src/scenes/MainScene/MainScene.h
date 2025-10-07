#pragma once
#include "SSE-engine/scenes/Scene.h"
#include "src/objects/CircleObject/CircleObject.h"

class MainMenuScene : public Scene {
public:
    void load(sf::RenderTarget &target) override {
        sf::Vector2f center(400.f, 300.f);
        manager.addObject(std::make_unique<CircleObject>(50.f, center));
    }
};
