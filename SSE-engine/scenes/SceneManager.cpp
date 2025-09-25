#include "SceneManager.h"

void SceneManager::changeScene(std::unique_ptr<Scene> scene) {
    currentScene = std::move(scene);
    if (currentScene) currentScene->load();
}

void SceneManager::update(float dt) {
    if (currentScene) currentScene->update(dt);
}

void SceneManager::draw(sf::RenderTarget &target) {
    if (currentScene) currentScene->draw(target);
}
