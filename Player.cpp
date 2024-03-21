#include "Player.h"

Player::Player()
{
	//load texture
	if (!texture.loadFromFile("C:/Users/23259/Desktop/VGP102Final/res/img/player.png"))
	{
		//if error
	}
	sprite.setTexture(texture);
}

void Player::draw(sf::RenderWindow& window) // draw player
{
	window.draw(sprite);
}

void Player::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

void Player::move(float offsetX, float offsetY)
{
	sprite.move(offsetX, offsetY);
}

sf::FloatRect Player::getGlobalBounds() const // for check collision
{
	return sprite.getGlobalBounds();
}