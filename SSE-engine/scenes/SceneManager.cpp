#include "SceneManager.h"

void SceneManager::changeScene(std::unique_ptr<Scene> scene) {
    _currentScene = std::move(scene);
    if (_currentScene && _window) _currentScene->load(*_window);
}

void SceneManager::update(float dt) {
    if (_currentScene) _currentScene->update(dt);
}

void SceneManager::draw() {
    if (_currentScene && _window) _currentScene->draw(*_window);
}
