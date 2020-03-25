#pragma once
#include <SFML\Graphics.hpp>
class Collider
{
public:
	Collider(sf::RectangleShape& mainCharacter);
	~Collider(void);

	void Move(float dx, float dy) { mainCharacter.move(dx, dy); }

	bool CheckCollision(Collider & other, sf::Vector2f& direction, float push);
	sf::Vector2f GetPosition() { return mainCharacter.getPosition(); }
	sf::Vector2f GetHalfSize() { return mainCharacter.getSize() / 2.0f; }

private:
	sf::RectangleShape& mainCharacter;

};

