#include <SFML\Graphics.hpp>
#include "Collider.h"

class Platform
{
public:
	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Platform(void);

	void Draw(sf::RenderWindow& window);
	Collider GetCollider() { return Collider(mainCharacter); }

private:
	sf::RectangleShape mainCharacter;
};

