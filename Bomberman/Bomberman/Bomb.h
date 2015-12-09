#ifndef BOMBH
#define BOMBH

#include<SFML\Graphics.hpp>
#include<iostream>

using namespace std;

class Bomb {

public:
	//Pommin konstruktori
	Bomb();
	//Pommin destruktori
	~Bomb();
	//Räjäytys funktio
	void explode();
	//Setterit ja getterit
	void setPosY(float);
	void setPosX(float);
	float getPosX();
	float getPosY();




private:
	//Muuttujat
	float posX;
	float posY;

};
#endif