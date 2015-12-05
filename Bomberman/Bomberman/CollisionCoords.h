#ifndef Collisioncoordsh
#define Collisioncoordsh

#include "ColBox.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

class CollisionCoords {
private:
	ColBox					colTiles[20][20];
	int						width;
	int						height;
	sf::Vector2i			loadCounter = sf::Vector2i(0, 0);

public:
	CollisionCoords();
	~CollisionCoords();
	void initCol();
	void setCollisionMap();
};
#endif