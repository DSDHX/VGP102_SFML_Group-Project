#include "Background.h"

Background::Background() {};

void Background::load(const std::string& fileName)
{
	if (backgroundTexture.loadFromFile(fileName))
	{
		backgroundSprite.setTexture(backgroundTexture);
	}
	else
	{
		//
	}
}

void Background::draw(sf::RenderWindow& window)
{
	if (backgroundTexture.getSize().x > 0 && backgroundTexture.getSize().y > 0)
	{
		window.draw(backgroundSprite);
	}
	else
	{
		window.clear();
	}
}