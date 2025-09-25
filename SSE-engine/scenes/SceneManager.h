#pragma once
#include "Scene.h"
#include <memory>

class SceneManager {
private:
    std::unique_ptr<Scene> currentScene;

public:
    void changeScene(std::unique_ptr<Scene> scene);

    void update(float dt);

    void draw(sf::RenderTarget &target);
};
