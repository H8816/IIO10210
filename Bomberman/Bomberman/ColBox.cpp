#include "ColBox.h"	


ColBox::ColBox() {
	width = 40;
	height = 40;

}

ColBox::~ColBox() {
	//Tuhoaa seinän kuvan, ja vaihtaa siihen tilalle ruohikon
}

void ColBox::setColHeight(int i) {
	this->colHeight = i;
}

void ColBox::setPosition(int i, int j) {
	this->posX = i;
	this->posY = j;
}

int ColBox::getPosX() {
	return this->posX;
}

int ColBox::getPosY(){
	return this->posY;
}