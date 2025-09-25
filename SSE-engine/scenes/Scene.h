#pragma once
#include "../objects/ObjectManager.h"
#include <SFML/Graphics/RenderTarget.hpp>

class Scene {
protected:
    ObjectManager manager;

public:
    virtual ~Scene() = default;

    virtual void load() = 0;

    void update(float dt) { manager.updateAll(dt); }
    void draw(sf::RenderTarget &target) { manager.drawAll(target); }
};
