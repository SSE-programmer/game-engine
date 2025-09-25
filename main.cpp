#include <iostream>
#include <SFML/Graphics.hpp>

#include "src/scenes/MainScene/MainScene.h"
#include "SSE-engine/basic/Vector3D.h"
#include "SSE-engine/objects/ObjectManager.h"
#include "SSE-engine/scenes/SceneManager.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    auto v1 = Vector3D(1.5, 2, 3);
    auto v2 = Vector3D(1, 4, 7);
    auto v3 = v1 + v2;

    std::cout << "v3 = (" << v3.x << ", " << v3.y << ", " << v3.z << ")" << std::endl;

    auto desktopMode = sf::VideoMode::getDesktopMode();
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    auto window = sf::RenderWindow(desktopMode, "GameEngine", sf::Style::Default, sf::State::Windowed, settings);
    window.setFramerateLimit(144);


    SceneManager sceneManager;
    sceneManager.changeScene(std::make_unique<MainMenuScene>());

    sf::Clock clock;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        float dt = clock.restart().asSeconds();
        sceneManager.update(dt);

        window.clear(sf::Color::White);
        sceneManager.draw(window);
        window.display();
    }
}
