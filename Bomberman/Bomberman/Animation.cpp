/*#include "animation.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

Animation::Animation() {
	texture.loadFromFile("liikkeet.png");
}

void Animation::moveLeft() {

	sf::IntRect rectSourceSprite(0,40,40,40);
	sf::Sprite sprite(texture, rectSourceSprite);
	sf::Clock clock;

		if (clock.getElapsedTime().asSeconds() > 1.0f) {
			if (rectSourceSprite.left == 80)
				rectSourceSprite.left = 0;
			else
				rectSourceSprite.left += 40;

			sprite.setTextureRect(rectSourceSprite);
			clock.restart();
		}

}

void Animation::moveRight() {

	sf::IntRect rectSourceSprite(0, 80, 40, 40);
	sf::Sprite sprite(texture, rectSourceSprite);
	sf::Clock clock;

	if (clock.getElapsedTime().asSeconds() > 1.0f) {
		if (rectSourceSprite.left == 80)
			rectSourceSprite.left = 0;
		else
			rectSourceSprite.left += 40;

		sprite.setTextureRect(rectSourceSprite);
		clock.restart();
	}

}

void Animation::moveUp() {

	sf::IntRect rectSourceSprite(0, 0, 40, 40);
	sf::Sprite sprite(texture, rectSourceSprite);
	sf::Clock clock;

	if (clock.getElapsedTime().asSeconds() > 1.0f) {
		if (rectSourceSprite.left == 80)
			rectSourceSprite.left = 0;
		else
			rectSourceSprite.left += 40;

		sprite.setTextureRect(rectSourceSprite);
		clock.restart();
	}

}

void Animation::moveDown() {

	sf::IntRect rectSourceSprite(0, 40, 40, 40);
	sf::Sprite sprite(texture, rectSourceSprite);
	sf::Clock clock;

	if (clock.getElapsedTime().asSeconds() > 1.0f) {
		if (rectSourceSprite.left == 80)
			rectSourceSprite.left = 0;
		else
			rectSourceSprite.left += 40;

		sprite.setTextureRect(rectSourceSprite);
		clock.restart();
	}

}*/