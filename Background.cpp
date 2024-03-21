#include "Background.h"

Background::Background() {};

void Background::load(const std::string& fileName) // Load Background
{
	if (backgroundTexture.loadFromFile(fileName)) // try to load from user
	{
		backgroundSprite.setTexture(backgroundTexture);// if success
	}
	else
	{
		//if error
	}
}

void Background::draw(sf::RenderWindow& window) // draw the background
{
	if (backgroundTexture.getSize().x > 0 && backgroundTexture.getSize().y > 0) // check background
	{
		window.draw(backgroundSprite); // if good, draw it
	}
	else
	{
		window.clear();
	}
}