#include <iostream>
#include <SFML/Graphics.hpp>
#include<fstream>
#include "loadAssets.h"

//Compiler Directives
using namespace std;
using namespace sf;

RenderWindow window(VideoMode(800, 600), "Ghouls 'n Ghosts"); // 13 squares wide, 9 square high

LoadAssets loadAssets;



void inputs ()
{
	bool W = false, S = false, A = false, D = false;

	if (Keyboard::isKeyPressed(Keyboard::W));
	if (Keyboard::isKeyPressed(Keyboard::S));
	if (Keyboard::isKeyPressed(Keyboard::A));
	if (Keyboard::isKeyPressed(Keyboard::D));
}

int main()
{
//Local Variables
	//Event Variables
	Event event;
	
	window.setFramerateLimit(60);
	
	while (window.isOpen()) //The Game Window Loop
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) //Checks to see if the window is closed and then executes the code
			{
				window.close(); //closes the window
				break;
			}
			if(event.type == Event::KeyPressed) 
			{
			}
		}
		window.clear(sf::Color(100,100,100));
		window.display();
	}
	return 0;
}