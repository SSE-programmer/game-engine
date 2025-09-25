#include "ObjectManager.h"

void ObjectManager::addObject(std::unique_ptr<GameObject> obj) {
    objects.push_back(std::move(obj));
}

void ObjectManager::updateAll(float dt) {
    for (auto &obj: objects) obj->update(dt);
}

void ObjectManager::drawAll(sf::RenderTarget &target) {
    for (auto &obj: objects) obj->draw(target);
}
