#pragma once
#ifndef CHARACTERH
#define CHARACTERH

#include <SFML/Graphics.hpp>

using namespace std;

class Character : public sf::Drawable {

public:
		
	enum				Direction { up, down, left, right };

	//Konstruktori
	Character(const sf::Texture& imagePath);
	bool				collision = false;
	//Destruktori
	virtual				~Character();

	//Piirtäminen
	virtual void		draw(sf::RenderTarget& target, sf::RenderStates states) const;

	//Liikkeet
	void				moveUp(int);
	void				moveDown(int);
	void				moveLeft(int);
	void				moveRight(int);

	sf::Texture			texture;

	//Tekemättä //////////////////////////////////////////////////////////////
	//void dropBomb();


	//Healthin getterit ja setterit
	void setHealth(int hp);
	int getHealth();
	void setStartingPosition(int, int);
	float getPositionX();
	float getPositionY();
	int getColHeight();
	void setSpeed(float);
	void setLastY(float);
	void setLastX(float);



private:
	sf::Sprite			pSprite;
	sf::Vector2i		pSource;
	int					width, height;
	int					health;
	int					colHeight;
	float				posX;
	float				posY;

	float				speed = 2;
};

#endif