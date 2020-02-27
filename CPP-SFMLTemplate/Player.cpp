#include "Player.h"
#include <iostream>

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float x, float y) :
	animation(texture, imageCount, switchTime)
{
		this->speed = speed;
		row = 0;
		faceRight = true;

		mainCharacter.setSize(sf::Vector2f(94.0f,120.0f));
		mainCharacter.setOrigin(50/2,37/2);
		mainCharacter.setPosition(x, y);
		mainCharacter.setTexture(texture);
}


Player::~Player(void)
{
}

void Player::Update(float deltaTime, sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) 
{
	
	//Local Variables
	sf::Vector2f movement(0.0f, 0.0f);
	bool cantMove = false;
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
				movement.x -= speed * deltaTime;
		}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
		if(!cantMove)
			{
				movement.x += speed * deltaTime;
			}
		}
		//else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W));
			//movement.y -= speed * deltaTime;
		
	if(movement.x == 0.0f)
		{
			row = 0;	
			cantMove = true;
		}
		else
		{
			row = 1;
		}

	if (movement.x > 0.0f)
		{
			faceRight = true;
			cantMove = false;
		}
		else
		{
			faceRight = false;
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
			if(movement.x == 0.0f)
			{
				row = 4;
			}
		}
	
		animation.Update(row, deltaTime, faceRight);
		mainCharacter.setTextureRect(animation.uvRect);
		mainCharacter.move(movement);
}
void Player::Jump(float velocity)
{
	//Main "Jump()"

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