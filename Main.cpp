#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Player.h"

int main()
{
    //Create Window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game");

    Background background;
    background.load("C:/Users/23259/Desktop/VGP102Final/res/img/brick.jpg");

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

    Player player;
    player.setPosition(50, 300);
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

    //Game while
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
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
        background.draw(window);
        player.draw(window);
        window.draw(obstacle);
        window.draw(finishLine);
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