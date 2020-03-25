#include "Platform.h"


Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	mainCharacter.setSize(size);
	mainCharacter.setOrigin(size / 2.0f);
	mainCharacter.setTexture(texture);
	mainCharacter.setPosition(position);
}


Platform::~Platform(void)
{
}

void Platform::Draw(sf::RenderWindow & window)
{
	window.draw(mainCharacter);
}
