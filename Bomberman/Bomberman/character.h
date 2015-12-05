#pragma once
#ifndef CHARACTERH
#define CHARACTERH

#include <SFML/Graphics.hpp>

class Character : public sf::Drawable {

public:
		
	enum				Direction { up, down, left, right };

	//Konstruktori
	Character(const sf::Texture& imagePath);

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
	int getPositionX();
	int getPositionY();
	void setSpeed(float);

private:
	sf::Sprite			pSprite;
	sf::Vector2i		pSource;
	int					width, height;
	int					health;
	int					colHeight;
	int					posX;
	int					posY;
	float				speed = 0.8f;
};

#endif