#include <iostream>
#include <SFML/Graphics.hpp>
#include "loadAssets.h"

//Compiler Directives
using namespace std;
using namespace sf;

RenderWindow window(VideoMode(800, 600), "Ghouls 'n Ghosts"); // 13 squares wide, 9 square high

LoadAssets loadAssets;

//Game Screen Variables
	//Assigns a value for each screen
const int GAME_MENU_SCREEN = 0; //Main game screen
const int INSTRUCTIONS_MENU_SCREEN = 1; //Instructions Menu screen
const int LEVEL_1_SCREEN = 2; // Level 1 of the game
const int GAME_OVER_SCREEN = 3; //Game Over screen
int CURRENT_SCREEN = GAME_MENU_SCREEN; //Using current screen in order to switch to another screen

Vector2i MouseCursorLocation(0,0);

void inputs ()
{
	bool W = false, S = false, A = false, D = false;

	if (Keyboard::isKeyPressed(Keyboard::W));
	if (Keyboard::isKeyPressed(Keyboard::S));
	if (Keyboard::isKeyPressed(Keyboard::A));
	if (Keyboard::isKeyPressed(Keyboard::D));
}

void gameAssets (Sprite &gameScreen, Sprite &playButton, Sprite &exitButton, Sprite &instructionMenu)
{
	gameScreen = loadAssets.LoadSpriteFromTexture("Assets/", "GameScreen", "png");

	instructionMenu = loadAssets.LoadSpriteFromTexture("Assets/", "InstructionsMenu", "png");

	playButton = loadAssets.LoadSpriteFromTexture("Assets/", "playButton", "png");
	playButton.setOrigin(90.0/2, 42.0/2);
	playButton.setPosition(390, 300);

	exitButton = loadAssets.LoadSpriteFromTexture("Assets/", "exitButton", "png");
	exitButton.setOrigin(86.0/2, 42.0/2);
	exitButton.setPosition(390, 400);
	
}

int main()
{
//Local Variables
	//Event Variables
	Event event;
	
	Sprite gameScreen, playButton, exitButton, instructionMenu;
	gameAssets(gameScreen, playButton, exitButton, instructionMenu);


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
			if (event.type == Event::MouseMoved) //Mouse Movement
				{
				MouseCursorLocation = Mouse::getPosition(window);
				}
			else if (event.type == Event::MouseButtonPressed)
				{
				if (event.mouseButton.button == Mouse::Left && CURRENT_SCREEN == GAME_MENU_SCREEN)
					{
					if ((MouseCursorLocation.x > playButton.getPosition().x - playButton.getGlobalBounds().width/2) && (MouseCursorLocation.x < (playButton.getPosition().x + playButton.getGlobalBounds().width/2)) && (MouseCursorLocation.y > playButton.getPosition().y - playButton.getGlobalBounds().height/2) && (MouseCursorLocation.y < (playButton.getPosition().y + playButton.getGlobalBounds().height/2)))
						{
							CURRENT_SCREEN = INSTRUCTIONS_MENU_SCREEN; //Changes the current screen if you click on the play button
						}
					if ((MouseCursorLocation.x > exitButton.getPosition().x - exitButton.getGlobalBounds().width/2) && (MouseCursorLocation.x < (exitButton.getPosition().x + exitButton.getGlobalBounds().width/2)) && (MouseCursorLocation.y > exitButton.getPosition().y - exitButton.getGlobalBounds().height/2) && (MouseCursorLocation.y < (exitButton.getPosition().y + exitButton.getGlobalBounds().height/2)))
						{
							window.close(); //Closes the window if you click on the exit button
						}
					}
				}
		if(event.type == Event::KeyPressed) 
			{
			}
		}
		window.clear(sf::Color(100,100,100));
		
		if (CURRENT_SCREEN == GAME_MENU_SCREEN)
		{
			window.draw(gameScreen);
			window.draw(playButton);
			window.draw(exitButton);
		}
	else if (CURRENT_SCREEN == INSTRUCTIONS_MENU_SCREEN)
		{
			window.draw(instructionMenu);
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				CURRENT_SCREEN = LEVEL_1_SCREEN;
			}
		}
	else if (CURRENT_SCREEN == LEVEL_1_SCREEN)
		{
			
		}
	else if (CURRENT_SCREEN == GAME_OVER_SCREEN)
		{
			//window.draw(/*GameOverMenu*/);
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				CURRENT_SCREEN = LEVEL_1_SCREEN;
			}
		}



		window.display();
	}
	return 0;
}