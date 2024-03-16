#include <SFML/Graphics.hpp>
#include <iostream> 

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Sprite Movement");

    sf::Texture texture;
    if (!texture.loadFromFile("brick.jpg")) {
        std::cerr << "Failed to load sprite texture!" << std::endl;
        return 1;
    }

    sf::Sprite sprite(texture);

    sprite.setPosition(400, 300);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float movementSpeed = 5.0f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            sprite.move(-movementSpeed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            sprite.move(movementSpeed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            sprite.move(0, -movementSpeed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            sprite.move(0, movementSpeed);
        }

        window.clear();

        window.draw(sprite);

        window.display();
    }

    return 0;
}