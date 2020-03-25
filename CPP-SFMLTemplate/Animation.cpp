#include "Animation.h"
#include <iostream>


Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}


Animation::~Animation(void)
{
}

void Animation::Update(int row, float deltaTime, bool faceRight)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		
		if (currentImage.x > 5)
		{
			currentImage.x = 0;
		}
		//else if(currentImage.x >= 3 && row == 0)
		//{
		//	currentImage.x = 0;
		//}
		//else if (currentImage.x >= 4 && row == 2)
		//{
		//	currentImage.x = 0;
		//}
		//else if (currentImage.x >= 3 && row == 4)
		//{
		//	currentImage.x = 0;
		//}
	}
	//std::cout << currentImage.x << std::endl;

	uvRect.top = currentImage.y * uvRect.height;

	if(faceRight)
	{
			uvRect.left = currentImage.x * uvRect.width;
			uvRect.width = abs(uvRect.width); //makes the width positive
	}
	else
	{
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width); //makes the width negative
	}
}