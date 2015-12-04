#pragma once
#ifndef ANIMATIONH
#define ANIMATIONH
#include <SFML/Graphics.hpp>
#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Animation : public sf::Drawable {

public:

	//enum Direction { up, down, left, right };

	//Konstruktori
	Animation(const sf::Texture& imagePath);

	//Destruktori
	virtual ~Animation();

	//Piirtäminen
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Texture texture;

	//Tekemättä //////////////////////////////////////////////////////////////
	void getPosx(float);
	void getPosy();
	void setPosx();
	void setPosy();
	void dropBomb();

private:
	sf::Sprite bombSprite;
	sf::Vector2i bombSource;
	int width, height;
};



#endif