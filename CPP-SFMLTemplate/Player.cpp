#include "Player.h"
#include <iostream>

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f Position, float jumpHeight) :
	animation(texture, imageCount, switchTime)
{
		this->speed = speed;
		this->jumpHeight = jumpHeight;
		row = 0;
		faceRight = true;

		mainCharacter.setSize(sf::Vector2f(94.0f,120.0f));
		mainCharacter.setOrigin(mainCharacter.getSize() / 2.0f);
		mainCharacter.setPosition(Position);
		mainCharacter.setTexture(texture);
}


Player::~Player(void)
{
}

void Player::Update(float deltaTime, sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) 
{
	bool cantMove = false;

	velocity.x = 0.0f;
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
				velocity.x -= speed;
		}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
		if(!cantMove)
			{
				velocity.x += speed;
			}
		}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && canJump);
		{
			canJump = false;
			velocity.y = sqrtf(2.0f * 981.0f * jumpHeight);
		}

		velocity.y += 981.0f * deltaTime;
		
	if(velocity.x == 0.0f)
		{
			row = 0;	
			cantMove = true;
		}
		else
		{
			row = 1;
	if (velocity.x > 0.0f)
		{
			faceRight = true;
			cantMove = false;
		}
		else
		{
			faceRight = false;
		}
	}

		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && cantMove)
		{
			if (powerUp == 1)
			{
				animation.Update(2, 0.08f, faceRight);
				row = 2;
			}
			else if (powerUp == 2)
			{
				row = 3;
			}
			else if (powerUp == 3)
			{
				row = 5;
			}

		}

		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			if(velocity.x == 0.0f)
			{
				row = 4;
			}
		}
		std::cout << canJump << std::endl;
		animation.Update(row, deltaTime, faceRight);
		mainCharacter.setTextureRect(animation.uvRect);
		mainCharacter.move(velocity * deltaTime);
}

void Player::OnCollision(sf::Vector2f direction)
{
	if(direction.x < 0.0f)
	{
		//Collision on the left.
		velocity.x = 0.0f;
	}
	else if(direction.x > 0.0f)
	{
		//Collision on the right.
		velocity.x = 0.0f;
	}
	if(direction.y < 0.0f)
	{
		//Collision on the bottom.
		velocity.y = 0.0f;
		canJump = true;
	}
	else if(direction.y > 0.0f)
	{
		//collision on the top
		velocity.y = 0.0f;
	}

}

bool Player::intersects(sf::Sprite sprite, int type, bool powerUpDisplay)
{
	if(mainCharacter.getGlobalBounds().intersects(sprite.getGlobalBounds())) 
	{
			powerUp = type;
			return true;
	}
	return false;
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(mainCharacter);
}