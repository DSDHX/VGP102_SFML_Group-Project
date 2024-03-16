#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>

class Background
{
public:
	Background();
	void load(const std::string& fileName);
	void draw(sf::RenderWindow& window);

private:
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;
};

#endif // !BACKGROUND_H