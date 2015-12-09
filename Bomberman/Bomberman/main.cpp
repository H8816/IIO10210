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
#include "Bomb.h"



using namespace std;

int main() {

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//OLIOT///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//TÌleMap	
	Tilemap							lvl1;

	//Ikkuna
	sf::RenderWindow				window(sf::VideoMode(800, 800), "Bomberman");

	//Gamestatus
	Gamestatus						gs;

	//Collisionmap kummallekin pelaajalle
	CollisionMap					col1;
	CollisionMap					col2;

	//Pommi
	Bomb							pommi;

	//Pommilaskuri
	int pommilaskuri = 0;

	//Ajan laskeminen, pommeja varten
	sf::Clock clock;
	Bomb bomb;
	sf::Time time;
	//pommin aika counterit, m‰‰r‰‰ miten pommi k‰ytt‰ytyy
	int								counter = 0;
	int								bombcounter = 0;
	int								fireCounter = 0;
	int								timerCounter = 0;

	// Animaation muuttujia
	int								call = 0;
	int								movefactor = 100;


	//Pommin textuuri//////////////////////////////////////////////////
	sf::Sprite						pommitus;
	sf::Texture						bTexture;
	if (!bTexture.loadFromFile("bomb.png")) {
		cerr << "Character texture error" << endl;
	}


	//Liekkien textuuri/////////////////////////////////////////////
	sf::Sprite						fire;
	sf::Texture						fireTexture;
	if (!fireTexture.loadFromFile("fire.png")) {
		cerr << "Character texture error" << endl;
	}



	//Characterin luonti
	sf::Texture						pTexture;
	if (!pTexture.loadFromFile("liikkeet.png")) {
		cerr << "Character texture error" << endl;
	}

	Character						p1(pTexture);
	Character						p2(pTexture);






	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	//Pelaajan paikan sijoitus
	p1.setStartingPosition(160, 160);
	p2.setStartingPosition(620, 620);

	//LEVEL1 Tilemapin alustus
	lvl1.init();

	//LEVEL1 Collisionmapin alustus
	col1.initColMap("lvl1col.txt");
	col2.initColMap("lvl1col.txt");

	// IKKUNAN WHILELOOP



	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//PELI LOOPPI///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	while (window.isOpen()) {

		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)) {

			// Ikkunan sulkeminen ruksista, Lis‰‰ escille toiminta
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
				window.close();
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		//GameStatuksen valinta////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////////


		if (gs.getgamestatus() == 0) {
			//Timer
			time = clock.getElapsedTime();

			//cout << delay.asSeconds() << endl;

			window.clear();

			////////////////////////////////////////////////////////////////////////////////
			//TILEMAP JA COLMAP/////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////

			//Tilemapin piirt‰minen
			lvl1.drawTilemap(window);

			//CollisionMapin piirt‰minen
			col1.setColMap(p1);
			col2.setColMap(p2);

			///////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//Pelaajan 1 piirto ja ohjaus/////////////////////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////


			/////////////////////////////////////////////////////
			//Ohjaus A,S,D,W/////////////////////////////////////
			////////////////////////////////////////////////////

			//Ylˆsp‰in
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && col1.getCollision() == false) //move up
			{
				if (call < movefactor * 1) p1.moveUp(0);
				else if (call < movefactor * 2) p1.moveUp(40);
				else if (call < movefactor * 3) p1.moveUp(0);
				else p1.moveUp(80);
				call++;
				if (call == movefactor * 4) call = 0;
			}

			//Alasp‰in
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && col1.getCollision() == false) //move down
			{
				if (call < movefactor * 1) p1.moveDown(0);
				else if (call < movefactor * 2) p1.moveDown(40);
				else if (call < movefactor * 3) p1.moveDown(0);
				else p1.moveDown(80);
				call++;
				if (call == movefactor * 4) call = 0;
			}

			//Oikealle
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && col1.getCollision() == false) //move right
			{
				if (call < movefactor * 1) p1.moveRight(0);
				else if (call < movefactor * 2) p1.moveRight(40);
				else if (call < movefactor * 3) p1.moveRight(0);
				else p1.moveRight(80);
				call++;
				if (call == movefactor * 4) call = 0;
			}
			//Vasemmalle
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && col1.getCollision() == false) //move left
			{
				if (call < movefactor * 1) p1.moveLeft(0);
				else if (call < movefactor * 2) p1.moveLeft(40);
				else if (call < movefactor * 3) p1.moveLeft(0);
				else p1.moveLeft(80);
				call++;
				if (call == movefactor * 4) call = 0;
			}

			//POMMI//////////////////////////////////////////////////////////////////////
			////////////////////////////////////////////////////////////////////////////
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && timerCounter == 0)
			{
				clock.restart();
				bombcounter = 1;
				timerCounter = 1;
				float pomposX = p1.getPositionX();
				float pomposY = p1.getPositionY();

				pommi.setPosX(pomposX);
				pommi.setPosY(pomposY);

				pommitus.setTexture(bTexture);
				pommitus.setPosition(pomposX, pomposY);
			}

			//Sprint///////////////////////////

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
			{
				p1.setSpeed(3);
			}
			else if (event.type == sf::Event::KeyReleased) {
				switch (event.key.code) {
				case sf::Keyboard::N:

					p1.setSpeed(2);
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//Pelaajan 2 piirto ja ohjaus////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//Ylˆsp‰in///////////////////////////////////////////////////////////////////////////////////////
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && col2.getCollision() == false) //move up
			{
				if (call < movefactor * 1) p2.moveUp(0);
				else if (call < movefactor * 2) p2.moveUp(40);
				else if (call < movefactor * 3) p2.moveUp(0);
				else p2.moveUp(80);
				call++;
				if (call == movefactor * 4) call = 0;
			}

			//Alasp‰in/////////////////////////////////////////////////////////////////////////////////////
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && col2.getCollision() == false) //move down
			{
				if (call < movefactor * 1) p2.moveDown(0);
				else if (call < movefactor * 2) p2.moveDown(40);
				else if (call < movefactor * 3) p2.moveDown(0);
				else p2.moveDown(80);
				call++;
				if (call == movefactor * 4) call = 0;
			}

			//Oikealle//////////////////////////////////////////////////////////////////////////////////////
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && col2.getCollision() == false) //move right
			{
				if (call < movefactor * 1) p2.moveRight(0);
				else if (call < movefactor * 2) p2.moveRight(40);
				else if (call < movefactor * 3) p2.moveRight(0);
				else p2.moveRight(80);
				call++;
				if (call == movefactor * 4) call = 0;
			}

			//Vasemmalle////////////////////////////////////////////////////////////////////////////////////
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && col2.getCollision() == false) //move left
			{
				if (call < movefactor * 1) p2.moveLeft(0);
				else if (call < movefactor * 2) p2.moveLeft(40);
				else if (call < movefactor * 3) p2.moveLeft(0);
				else p2.moveLeft(80);
				call++;
				if (call == movefactor * 4) call = 0;
			}

			//Pommi
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown)) { //Drop bomb
			}

			//Pommin r‰j‰hdyksen ajastus 3 sekunttia pommin j‰tt‰misen j‰lkeen
			if (clock.getElapsedTime().asSeconds() > 3) {
				if (bombcounter == 1) {
					counter = 1;
					bombcounter = 0;
				}
			}

			//Pommin liekkien ajastus, pyyhkii liekin pois n‰kyvist‰
			if (clock.getElapsedTime().asSeconds() > 4) {
				if (timerCounter == 0) {
					fireCounter = 0;
				}
			}

			//Pommin r‰j‰hdys
			if (counter == 1) {
				counter = 0;
				cout << "KABOOM!" << endl;
				//Liekkien kuvan positio kun pommi on r‰j‰ht‰nyt
				float fposx = pommi.getPosX() - 40;
				float fposy = pommi.getPosY() - 40;
				fire.setTexture(fireTexture);
				fire.setPosition(fposx, fposy);
				fireCounter = 1;
				// Pommilaskuri lis‰‰ yhden lis‰‰
				pommilaskuri++;
				cout << "Pommeja rajahtanyt " << pommilaskuri << endl;
				// Kirjoittaa tiedostoon
				std::ofstream ofs("pommi.txt", std::ofstream::out);

				ofs << "pommeja rajahtanyt viime pelissa: " << pommilaskuri << " kpl" << endl; ;

				ofs.close();

			}

			//cout << clock.getElapsedTime().asSeconds() << endl;

			//Pelaajien piirt‰minen
			window.draw(p1);
			window.draw(p2);
			//Pommin piirto mik‰li b n‰pp‰in on painettu, 3 sekunnin viive.
			if (bombcounter == 1) {
				window.draw(pommitus);
			}
			//Liekkien piirto, 4 sekunnin viiveell‰ b painamisesta
			if (fireCounter == 1) {
				window.draw(fire);
				timerCounter = 0;
			}

			window.display();

		}
	}
}




