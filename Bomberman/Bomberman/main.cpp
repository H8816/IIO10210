#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <cctype>
#include <string>
#include <thread>
#include "Gamestatus.h"
#include "Tilemap.h"
#include "Character.h"
#include "Animation.h"
#include "CollisionMap.h"



using namespace std;

int main() {



	Tilemap						lvl1;

	sf::RenderWindow		window(sf::VideoMode(800, 800), "Bomberman");

	Gamestatus				gs;

	CollisionMap			col1;
	CollisionMap			col2;

	sf::Clock clock;

	sf::Time time;


	void bombdelay();
	void display();






	
	// Animaation muuttujia
	int call = 0;
	int movefactor = 100;

	//Ikkunan luonti


	//Pelitilan olio


	//Ensimmäisen kentän luonti


	//Collisionmap




	//Characterin luonti
	sf::Texture pTexture;
	if (!pTexture.loadFromFile("liikkeet.png")) {
		cerr << "Character texture error" << endl;
	}

	Character				p1(pTexture);
	Character				p2(pTexture);

	// Pommin luonti
	sf::Texture pBomb;
	if (!pBomb.loadFromFile("bomb.png")) {
		cerr << "Bomb texture error" << endl;
	}



	//Pelaajan paikan sijoitus
	p1.setStartingPosition(160,160);
	p2.setStartingPosition(620, 620);

	//LEVEL1 Tilemapin alustus
	lvl1.init();
	
	//LEVEL1 Collisionmapin alustus
	col1.initColMap("lvl1col.txt");
	col2.initColMap("lvl1col.txt");

	// IKKUNAN WHILELOOP
	
	while (window.isOpen()) {

		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)) {

			// Ikkunan sulkeminen ruksista, Lisää escille toiminta
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
				window.close();
		}

		if (gs.getgamestatus() == 0) {
			//Timer
			time = clock.getElapsedTime();

			//cout << delay.asSeconds() << endl;

			window.clear();

			//Tilemapin piirtäminen
			lvl1.drawTilemap(window);
			//CollisionMapin piirtäminen
			col1.setColMap(p1);
			col2.setColMap(p2);


			//Pelaajan 1 piirto ja ohjaus
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && col1.getCollision() == false) //move up
			{
				//CHECK BOTTOM COLLISION
				if (call < movefactor * 1) p1.moveUp(0);
				else if (call < movefactor * 2) p1.moveUp(40);
				else if (call < movefactor * 3) p1.moveUp(0);
				else p1.moveUp(80);
				call++;
				if (call == movefactor * 4) call = 0;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && col1.getCollision() == false) //move down
			{
				//CHECK TOP COLLISION
				if (call < movefactor * 1) p1.moveDown(0);
				else if (call < movefactor * 2) p1.moveDown(40);
				else if (call < movefactor * 3) p1.moveDown(0);
				else p1.moveDown(80);
				call++;
				if (call == movefactor * 4) call = 0;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && col1.getCollision() == false) //move right
			{
				//CHECK LEFT COLLISION
				if (call < movefactor * 1) p1.moveRight(0);
				else if (call < movefactor * 2) p1.moveRight(40);
				else if (call < movefactor * 3) p1.moveRight(0);
				else p1.moveRight(80);
				call++;
				if (call == movefactor * 4) call = 0;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && col1.getCollision() == false) //move left
			{
				//CHECK RIGHT COLLISION
				if (call < movefactor * 1) p1.moveLeft(0);
				else if (call < movefactor * 2) p1.moveLeft(40);
				else if (call < movefactor * 3) p1.moveLeft(0);
				else p1.moveLeft(80);
				call++;
				if (call == movefactor * 4) call = 0;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) //Drop bomb
			{



			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) //Drop bomb
			{
				p1.setSpeed(3);
			}
			else if (event.type == sf::Event::KeyReleased) {
				switch (event.key.code) {
				case sf::Keyboard::N:

					p1.setSpeed(2);
				}
			}


			//Pelaajan 2 piirto ja ohjaus
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && col2.getCollision() == false) //move up
			{
				if (call < movefactor * 1) p2.moveUp(0);
				else if (call < movefactor * 2) p2.moveUp(40);
				else if (call < movefactor * 3) p2.moveUp(0);
				else p2.moveUp(80);
				call++;
				if (call == movefactor * 4) call = 0;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && col2.getCollision() == false) //move down
			{
				if (call < movefactor * 1) p2.moveDown(0);
				else if (call < movefactor * 2) p2.moveDown(40);
				else if (call < movefactor * 3) p2.moveDown(0);
				else p2.moveDown(80);
				call++;
				if (call == movefactor * 4) call = 0;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && col2.getCollision() == false) //move right
			{
				if (call < movefactor * 1) p2.moveRight(0);
				else if (call < movefactor * 2) p2.moveRight(40);
				else if (call < movefactor * 3) p2.moveRight(0);
				else p2.moveRight(80);
				call++;
				if (call == movefactor * 4) call = 0;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && col2.getCollision() == false) //move left
			{
				if (call < movefactor * 1) p2.moveLeft(0);
				else if (call < movefactor * 2) p2.moveLeft(40);
				else if (call < movefactor * 3) p2.moveLeft(0);
				else p2.moveLeft(80);
				call++;
				if (call == movefactor * 4) call = 0;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown)) //Drop bomb
			{
			}


			window.draw(p1);
			window.draw(p2);
			window.display();

		}
	}
}





void bombdelay() {
	sf::Clock delayclock;
	sf::Time delay;
	delay = delayclock.getElapsedTime();
	delayclock.restart();
	cout << "asd" << endl;
	while (delayclock.getElapsedTime().asSeconds() < 3) {
	}
	cout << "KABOOOOOM!!!!" << endl;

}


