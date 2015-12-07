#ifndef GAMEH
#define GAMEH

#include <SFML/Graphics.hpp>
#include "Gamestatus.h"
#include "Tilemap.h"
#include "CollisionMap.h"

class Game {
private:

public:
	//init!
	void init();
	Game();
	void display();
};
#endif;