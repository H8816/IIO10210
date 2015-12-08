#include "character.h"

//Konstruktori
Character::Character(const sf::Texture& imagePath) :
	pSprite(imagePath), pSource(1, Character::down) {
	pSprite.setTextureRect(sf::IntRect(0, 80, 40, 40));
	colHeight = 1;
}

//Destruktori
Character::~Character() {

}

//Piirtäminen
void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(pSprite, states);
}


//Liikkeet
void Character::moveUp(int rightcoord) {
	pSource.y = up;
	pSprite.move(0, -0.5*speed);
	this->posY = posY - 0.5 * speed;

	pSprite.setTextureRect(sf::IntRect(rightcoord, 0, 40, 40));

	//Animaatio


}


void Character::moveDown(int downcoord) {
	pSource.y = down;
	pSprite.move(0, +0.5*speed);
	this->posY = posY + speed * 0.5;
	pSprite.setTextureRect(sf::IntRect(downcoord, 80, 40, 40));

	//Animaatio


}
void Character::moveLeft(int leftcoord) {
	pSource.x = left;
	pSprite.move(-0.5*speed, 0);
	this->posX = posX - 0.5 * speed;
	pSprite.setTextureRect(sf::IntRect(leftcoord, 120, 40, 40));

	//Animaatio

}

void Character::moveRight(int rightcoord) {
	pSource.x = right;
	pSprite.move(+0.5*speed, 0);
	this->posX = posX + 0.5 * speed;
	pSprite.setTextureRect(sf::IntRect(rightcoord, 40, 40, 40));

	//Animaatio

}


//void Character::dropBomb() {}

//Healthin getterit ja setterit
void Character::setHealth(int hp) {
	this->health = hp;
}
int Character::getHealth() {
	return health;
}

void Character::setStartingPosition(int x, int y) {
	
	int i = x;
	int j = y;
	this->posX = x;
	this->posY = y;

	pSprite.move(i,j);
	if (j < 400) {
		pSprite.setTextureRect(sf::IntRect(0, 80, 40, 40));
	}
	else
		pSprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
}

float Character::getPositionX() {
	return posX;
}

float Character::getPositionY() {
	return posY;
}

void Character::setSpeed(float s) {
	this->speed = s;
}

int Character::getColHeight() {
	return colHeight;
}

void::Character::setLastX(float posx) {
	this->posX = posX - posx;
}

void::Character::setLastY(float posy) {
	this->posY = posY - posy;
}