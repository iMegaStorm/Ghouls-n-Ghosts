#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
class Player
{

public:

	float x;
	float y;

public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f Position, float Mass);
	~Player(void);

	void Update(float deltaTime, sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	void Jump (float velocity);
	void Draw(sf::RenderWindow& window);
	bool intersects(sf::Sprite sprite, int type, bool powerUpDisplay);
	sf::Vector2f GetPosition() { return mainCharacter.getPosition(); }

public:
	sf::RectangleShape mainCharacter;
	Animation animation;
	unsigned int row; //never less than 0
	float speed;
	int jumpCount;
	int powerUp;
	bool faceRight;

	sf::Sprite mainCharacterSprite;
	sf::Vector2f mainCharacterPosition;
	int JumpCount;
	float mainCharacterMass;
	float mainCharacterVelocity;
	bool mainCharacterOnGround;
	float mainCharacterGravity;

};

