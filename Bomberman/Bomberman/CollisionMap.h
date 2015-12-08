#ifndef COLLISIONMAPH
#define COLLISIONMAPH

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>

#include "character.h"

using namespace std;

class CollisionMap {

private:
	bool collision;
public:
	vector<vector<int>>	colMap;
	vector<int>			tempMap;

	void initColMap(const char*);
	void setColMap(Character p);
	CollisionMap();
	~CollisionMap();
	void collideLeft(Character p);
	void collideRight(Character p);
	void collideTop(Character p);
	void collideBottom(Character p);
	bool getCollision();
	void pass();


};

#endif