#ifndef TILEMAPH
#define TILEMAPH

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Tilemap {
private:
public:


	// Tilejen textuurit
	sf::Texture						tileTexture;
	sf::Sprite						tiles;

	// Kartan koko 20 tileä x 20 tileä, x = 20*40 *  y = 20*40 = 800x * 800y

	vector<vector<sf::Vector2i>>	map;
	vector<sf::Vector2i>			tempMap;


	void init();
	void drawTilemap(sf::RenderWindow & window);
	Tilemap();
	~Tilemap();
};

#endif