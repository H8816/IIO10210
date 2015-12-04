#include "animation.h"
#include <iostream>
using namespace std;


//Konstruktori
Animation::Animation(const sf::Texture& imagePath) :
	bombSprite(imagePath) {
	bombSprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
}

//Destruktori
Animation::~Animation() {
	//deletoi pommin kun se on kajahtanut ehkä????
}

//Piirtäminen
void Animation::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(bombSprite, states);

}


void Animation::dropBomb() {
	
}

