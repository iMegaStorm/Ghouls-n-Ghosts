#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Player
{

public:

	float x;
	float y;

public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f Position, float jumpHeight);
	~Player(void);

	void Update(float deltaTime, sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	void Jump (float velocity);
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);
	bool intersects(sf::Sprite sprite, int type, bool powerUpDisplay);
	sf::Vector2f GetPosition() { return mainCharacter.getPosition(); }
	Collider GetCollider() { return Collider(mainCharacter); }

public:
	sf::RectangleShape mainCharacter;
	Animation animation;
	unsigned int row; //never less than 0
	float speed;
	int powerUp;
	bool faceRight;

	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;


};

