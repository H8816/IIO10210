#ifndef COLBOXH
#define COLBOXH

#include <SFML/Graphics.hpp>

class ColBox {
private:
	int						width;
	int						height;
	sf::Vector2i			loadCounter = sf::Vector2i(0, 0);
	sf::Texture				tileTexture;
	sf::Sprite				tiles;
	int						colHeight;
	int						posX;
	int						posY;
public:
	ColBox();
	~ColBox();
	void setColHeight(int);
	void setPosition(int, int);
	int getPosX();
	int getPosY();
};

#endif
