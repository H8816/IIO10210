
#include "Bomb.h"
#include <iostream>

Bomb::Bomb() {


}

Bomb::~Bomb() {

}

void Bomb::explode() {



}

///////////////////////////////
//SETTERIT JA GETTERIT//////////
//////////////////////////////

void Bomb::setPosX(float x) {
	this->posX = x;
}

void Bomb::setPosY(float y) {
	this->posY = y;
}

float Bomb::getPosX() {
	return this->posX;
}

float Bomb::getPosY() {
	return this->posY;
}