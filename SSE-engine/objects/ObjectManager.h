#pragma once
#include "GameObject.h"
#include <vector>
#include <memory>


class ObjectManager {
private:
    std::vector<std::unique_ptr<GameObject>> objects;

public:
    void addObject(std::unique_ptr<GameObject> obj);
    void updateAll(float dt);
    void drawAll(sf::RenderTarget& target);
};
