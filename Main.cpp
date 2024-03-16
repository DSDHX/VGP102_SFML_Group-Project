#include <SFML/Graphics.hpp>
#include <iostream> 

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "2D Sprite Movement");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("C:/Users/23259/Desktop/VGP102Final/res/img/brick.jpg")) {
        return -1;
    }
    sf::Sprite background(backgroundTexture);

    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("C:/Users/23259/Desktop/VGP102Final/res/img/player.png")) {
        return -1;
    }
    sf::Sprite player(playerTexture);
    player.setPosition(50, 300);

    sf::Texture obstacleTexture;
    if (!obstacleTexture.loadFromFile("C:/Users/23259/Desktop/VGP102Final/res/img/spike.png")) {
        return -1;
    }
    sf::Sprite obstacle(obstacleTexture);
    obstacle.setPosition(300, 300);

    sf::Texture finishTexture;
    if (!finishTexture.loadFromFile("C:/Users/23259/Desktop/VGP102Final/res/img/finish.png")) {
        return -1;
    }
    sf::Sprite finishLine(finishTexture);
    finishLine.setPosition(700, 300);

    float moveSpeed = 0.1f;

    bool isPlayerAlive = true;

    sf::Font font;
    if (!font.loadFromFile("C:/Users/23259/Desktop/VGP102Final/res/front/arial.ttf")) {
        return -1;
    }

    sf::Text youWinText("You Win!", font, 50);
    youWinText.setFillColor(sf::Color::Green);
    youWinText.setPosition(300, 200);

    sf::Text youDieText("You Die!", font, 50);
    youDieText.setFillColor(sf::Color::Red);
    youDieText.setPosition(300, 200);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float dx = 0.0f;
        float dy = 0.0f;
        if (isPlayerAlive) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                dx -= moveSpeed;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                dx += moveSpeed;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                dy -= moveSpeed;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                dy += moveSpeed;
            }
        }

        if (isPlayerAlive) {
            player.move(dx, dy);
        }

        if (isPlayerAlive && player.getGlobalBounds().intersects(obstacle.getGlobalBounds())) {
            isPlayerAlive = false;
        }

        if (player.getGlobalBounds().intersects(finishLine.getGlobalBounds())) {
            window.close(); 
        }

        window.clear();

        window.draw(background);

        window.draw(obstacle);
        window.draw(finishLine);
        if (isPlayerAlive) {
            window.draw(player);
        }

        if (!isPlayerAlive) {
            window.draw(youDieText);
        }
        else if (player.getGlobalBounds().intersects(finishLine.getGlobalBounds())) {
            window.draw(youWinText);
        }

        window.display();
    }

    return 0;
}