#pragma once
#include "Scene.h"
#include <memory>

class SceneManager {
private:
    std::unique_ptr<Scene> _currentScene;
    sf::RenderWindow *_window = nullptr;

public:
    explicit SceneManager(sf::RenderWindow *window) : _window(window) {}

    void changeScene(std::unique_ptr<Scene> scene);

    void update(float dt);

    void draw();
};
