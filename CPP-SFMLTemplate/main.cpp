//Updated 23/02/2020

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Initialise.h"
#include "Player.h"

//Compiler Directives
using namespace std;

RenderWindow window(VideoMode(800, 600), "Ghouls 'n Ghosts"); // 13 squares wide, 9 square high
sf::View view;


Initialise init;

//Game Screen Variables
	//Assigns a value for each screen
const int GAME_MENU_SCREEN = 0; //Main game screen
const int INSTRUCTIONS_MENU_SCREEN = 1; //Instructions Menu screen
const int LEVEL_1_SCREEN = 2; // Level 1 of the game
const int GAME_OVER_SCREEN = 3; //Game Over screen
int CURRENT_SCREEN = LEVEL_1_SCREEN; //Using current screen in order to switch to another screen
int level = 1; 
int offsetX = 0;
int offsetY = 0;


Vector2i MouseCursorLocation(0,0);

sf::Vector2f fireBallLocation(10,520);
sf::Vector2f arrowLocation(10,520);

bool powerUp = false;


void drawDebugLayout(int playField[20][50]) {
	for (int i = 0; i < 15; i++)
    {
        cout<<  endl;
	}


	int i, j;
	for(i=0; i<20; i++)
	{
		for(j=0; j<25; j++)
		{
			cout<<playField[i][j]<<' ';	
		}
		cout<<'\n';
	}
	cout<<'\n';
}

void spawnGrass(int tileGrass, int tilePositionX, int tilePositionY, Sprite tiles[1])
{
	Sprite grass = tiles[tileGrass = 0];
	grass.setPosition(tilePositionX *32, tilePositionY *30);
	window.draw(grass);
}

void Input (float speed, int offsetX, int offsetY, Sprite &fireBall)
{
	bool A = false, D = false;

	//gameCharacter.Update(speed);
	//gameCharacter.Move(speed, offsetX, offsetY);
	//if (Keyboard::isKeyPressed(Keyboard::W))
	//	{
	//	gameCharacter.Jump(500.0f);
	//	}
	//if (Keyboard::isKeyPressed(Keyboard::A))
	//	{
	//	gameCharacter.Move(-50.0f * speed, 0);
	//	}
	//if (Keyboard::isKeyPressed(Keyboard::D))
	//	{
	//	gameCharacter.Move(50.0f * speed, 0);
	//	}

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) //The <Control> Keyboard Key Is Pressed...
	//	{
	//	fireBallBool = true;
	//	fireBallLocation.x = player.x + 20;
	//	fireBallLocation.y = fireBallLocation.y + 16;
	//	fireBall.setPosition(fireBallLocation.x,fireBallLocation.y);
	//	}
}

void Init (Sprite &gameScreen, Sprite &playButton, Sprite &exitButton, Sprite &startButton, Sprite &instructionMenu,Sprite &background, Sprite &health,
Sprite &healthPotion, Sprite &chest, Sprite &grass, Sprite &fireBall, Sprite &arrow, Sprite &swordPowerUp, Sprite &spellPowerUp, Sprite &bowPowerUp)
{
	gameScreen = init.LoadSpriteFromTexture("Assets/Menus/", "GameScreen", "png");

	instructionMenu = init.LoadSpriteFromTexture("Assets/Menus/", "InstructionsMenu", "png");

	background = init.LoadSpriteFromTexture("Assets/Menus/", "BackGround", "png");
	background.setPosition(0,-28);

	playButton = init.LoadSpriteFromTexture("Assets/Menus/", "playButton", "png");
	playButton.setOrigin(90.0/2, 42.0/2);
	playButton.setPosition(390, 300);

	exitButton = init.LoadSpriteFromTexture("Assets/Menus/", "exitButton", "png");
	exitButton.setOrigin(86.0/2, 42.0/2);
	exitButton.setPosition(390, 400);

	startButton = init.LoadSpriteFromTexture("Assets/Menus/", "startButton", "png");
	startButton.setOrigin (100.0/2, 42.0/2);
	startButton.setPosition (400, 550);

	health = init.LoadSpriteFromTexture("Assets/Objects/", "Health", "png");
	health.setPosition(50, 50);
	
	healthPotion = init.LoadSpriteFromTexture("Assets/Objects/", "HealthPotion", "png");
	healthPotion.setPosition (400, 544);

	chest = init.LoadSpriteFromTexture("Assets/Objects/", "chest", "png");
	chest.setScale(3, 3);
	chest.setPosition (450, 527);

	grass = init.LoadSpriteFromTexture("Assets/Menus/", "placeHolderTileset", "png");

	fireBall = init.LoadSpriteFromTexture("Assets/WeaponAnimations/", "Frame1", "png");
	fireBall.setScale(0.2, 0.2);

	arrow = init.LoadSpriteFromTexture("Assets/WeaponAnimations/", "Arrow", "png");
	arrow.setScale(1.5, 1.5);

	swordPowerUp = init.LoadSpriteFromTexture("Assets/Objects/", "SwordPowerUp", "png");
	swordPowerUp.setPosition(600, 527); 

	spellPowerUp = init.LoadSpriteFromTexture("Assets/Objects/", "SpellPowerUp", "png");
	spellPowerUp.setPosition(150, 527);

	bowPowerUp = init.LoadSpriteFromTexture("Assets/Objects/", "BowPowerUp", "png");
	bowPowerUp.setPosition(250, 527);

}

int main()
{
//Local Variables
	//Event Variables
	Event event;
	//Local Variables
	Clock ClockTime;
	Time speed;

	sf::Clock animationClock;
	float animationDelay = 0.04f;

	int currentHealth = 3;

	Sprite gameScreen, playButton, exitButton, startButton, instructionMenu, background, health, healthPotion, chest, grass, fireBall, arrow, swordPowerUp, spellPowerUp, bowPowerUp;
	Init(gameScreen, playButton, exitButton, startButton, instructionMenu, background, health, healthPotion, chest, grass, fireBall, arrow, swordPowerUp, spellPowerUp, bowPowerUp);

	sf::Texture playerTexture;
	playerTexture.loadFromFile("Assets/Main Character/MainCharacterSheet.png");
	Player player(&playerTexture, sf::Vector2u(6,6), 0.3f, 100.0f, sf::Vector2f(10.0f, 475.0f), 200);

	
	float deltaTime = 0.0f;
	sf::Clock clock;

	window.setFramerateLimit(60);
	

	int i, j;
	int playField[20][50] =
	{
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
	};
	drawDebugLayout(playField);


Sprite tiles[1] = {grass};
	
	while (window.isOpen()) //The Game Window Loop
	{
		deltaTime = ClockTime.restart().asSeconds();
		Input(speed.asSeconds(),offsetX, offsetY, fireBall);
		while (window.pollEvent(event)) //Checks for input for keyboard
		{
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) //Checks to see if the window is closed and then executes the code
			{
				window.close(); //closes the window
				break;
			}
			if (event.type == Event::MouseMoved) //Mouse Movement
				{
				MouseCursorLocation = Mouse::getPosition(window); //Get position within the window
				}
			else if (event.type == Event::MouseButtonPressed) //Checks input of the mouse button is pressed
				{
				if (event.mouseButton.button == Mouse::Left && CURRENT_SCREEN == GAME_MENU_SCREEN || CURRENT_SCREEN == INSTRUCTIONS_MENU_SCREEN)
					{
					if ((MouseCursorLocation.x > playButton.getPosition().x - playButton.getGlobalBounds().width/2) && (MouseCursorLocation.x < (playButton.getPosition().x + playButton.getGlobalBounds().width/2)) && (MouseCursorLocation.y > playButton.getPosition().y - playButton.getGlobalBounds().height/2) && (MouseCursorLocation.y < (playButton.getPosition().y + playButton.getGlobalBounds().height/2)))
						{
							CURRENT_SCREEN = INSTRUCTIONS_MENU_SCREEN; //Changes the current screen if you click on the play button
						}
					else if ((MouseCursorLocation.x > exitButton.getPosition().x - exitButton.getGlobalBounds().width/2) && (MouseCursorLocation.x < (exitButton.getPosition().x + exitButton.getGlobalBounds().width/2)) && (MouseCursorLocation.y > exitButton.getPosition().y - exitButton.getGlobalBounds().height/2) && (MouseCursorLocation.y < (exitButton.getPosition().y + exitButton.getGlobalBounds().height/2)))
						{
							window.close(); //Closes the window if you click on the exit button
						}
					else if ((MouseCursorLocation.x > startButton.getPosition().x - startButton.getGlobalBounds().width/2) && (MouseCursorLocation.x < (startButton.getPosition().x + startButton.getGlobalBounds().width/2)) && (MouseCursorLocation.y > startButton.getPosition().y - startButton.getGlobalBounds().height/2) && (MouseCursorLocation.y < (startButton.getPosition().y + startButton.getGlobalBounds().height/2)))
						{
							CURRENT_SCREEN = LEVEL_1_SCREEN; //Changes the current screen if you click on the start button
						}
					}
				}
		if(event.type == Event::KeyPressed) 
			{
				Input(speed.asSeconds(), offsetX, offsetY, fireBall);

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player.powerUp == 2) //The <Control> Keyboard Key Is Pressed...
						{
						powerUp = true;
						fireBallLocation.x = player.GetPosition().x -50;
						fireBallLocation.y = player.GetPosition().y +20;
						fireBall.setPosition(fireBallLocation.x,fireBallLocation.y);
						}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player.powerUp == 3) //The <Control> Keyboard Key Is Pressed...
						{
						powerUp = true;
						arrowLocation.x = player.GetPosition().x;
						arrowLocation.y = player.GetPosition().y +27;
						arrow.setPosition(arrowLocation.x,arrowLocation.y);
						}
				/*if(Keyboard::isKeyPressed(Keyboard::W))
				{
					player.Jump(500.0f);
					cout << "W key is pressed" << endl;
				}*/
			}
		}
		window.clear();

		
		if (CURRENT_SCREEN == GAME_MENU_SCREEN)
		{
			window.draw(gameScreen);
			window.draw(playButton);
			window.draw(exitButton);
		}
	else if (CURRENT_SCREEN == INSTRUCTIONS_MENU_SCREEN)
		{
			window.draw(instructionMenu);
			window.draw(startButton);
		}
	else if (CURRENT_SCREEN == LEVEL_1_SCREEN)
		{
			window.draw(background);
			player.Draw(window);

			for(i = 0; i<20; i++) 
			{
				for(j = 0; j<25; j++)
				{
					if(playField[i][j] == 2)
					{
						spawnGrass (playField[i][j], j, i, tiles);
					}
				}
			}
			
			if(player.intersects(swordPowerUp, 1, false))
			{
				swordPowerUp.setColor(Color(0,0,0,0));
				swordPowerUp.setPosition (-50,-50);
			
			}
			else if (player.intersects(spellPowerUp, 2, false))
			{
				spellPowerUp.setColor(Color(0,0,0,0));
				spellPowerUp.setPosition (-50,-50);
			}
			if (player.intersects(bowPowerUp, 3, false))
			{
				bowPowerUp.setColor(Color(0,0,0,0));
				bowPowerUp.setPosition (-50,-50);
			}

			player.Update(deltaTime, &playerTexture, sf::Vector2u(6,5), 0.3f, 100.0f);

			view.reset(sf::FloatRect(0, 0, 800, 600));
				//(sf::Vector2f(0.0f,0.0f), sf::Vector2f(800, 600));
			view.setCenter(player.GetPosition()); //setting the 2D camera to the main character
			view.move(0,-150);
			window.setView(view); //calling the 2D view in
			window.draw(healthPotion);
			window.draw(chest);
				window.draw(swordPowerUp);
			window.draw(spellPowerUp);
			window.draw(bowPowerUp);
			window.draw(health);
			player.Draw(window);
			//window.draw(gameCharacter.GetSprite());
			//cout << powerUpDisplay << endl;


			if (powerUp && player.powerUp == 2)
			{
			fireBall.setPosition(fireBallLocation.x,fireBallLocation.y);
				window.draw(fireBall);
			if (animationClock.getElapsedTime().asSeconds() > animationDelay)
				{
				fireBallLocation.x = fireBallLocation.x + 50;
				animationClock.restart();
				}
			if (fireBallLocation.x > 810)
				{
					//fireBall.setPosition(fireBallLocation.x,fireBallLocation.y);
					powerUp = false;
				}
			}

		if (powerUp && player.powerUp == 3)
			{
			arrow.setPosition(arrowLocation.x,arrowLocation.y);
				window.draw(arrow);
			if (animationClock.getElapsedTime().asSeconds() > animationDelay)
				{
				arrowLocation.x = arrowLocation.x + 50;
				animationClock.restart();
				}
			if (arrowLocation.x > 810)
				{
					//arrow.setPosition(arrowLocation.x,arrowLocation.y);
					powerUp = false;
				}
			}

		}
	else if (CURRENT_SCREEN == GAME_OVER_SCREEN)
		{
			//window.draw(GameOverMenu);
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				CURRENT_SCREEN = LEVEL_1_SCREEN;
			}
		}

		window.display();
	}
	return 0;
}