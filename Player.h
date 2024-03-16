#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	void draw(sf::RenderWindow& window);
	void setPosition(float x, float y);
	void move(float offsetX, float offsetY);
	sf::FloatRect getGlobalBounds() const;

private:
	sf::Sprite sprite;
	sf::Texture texture;
};

#endif // !PLAYER_H