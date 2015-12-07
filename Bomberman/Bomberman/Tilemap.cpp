#include "Tilemap.h"

void Tilemap::init() {

	ifstream openfile("lvl1.txt");
	map.clear();

	if (openfile.is_open()) {

		string tileLocation;
		openfile >> tileLocation;
		tileTexture.loadFromFile(tileLocation);
		tiles.setTexture(tileTexture);

		//Tiletekstitiedoston luenta  ja muuntaminen kuviksi
		while (!openfile.eof()) {
			string str, value;
			getline(openfile, str);
			stringstream stream(str);

			while (getline(stream, value, ' ')) {
				if (value.length() > 0) {
					string xx = value.substr(0, value.find(','));
					string yy = value.substr(value.find(',') + 1);

					int x, y, i, j;

					for (i = 0; i < xx.length(); i++) {
						if (!isdigit(xx[i]))
							break;
					}
					for (j = 0; j < yy.length(); j++) {
						if (!isdigit(yy[j]))
							break;
					}

					x = (i == xx.length()) ? atoi(xx.c_str()) : -1;
					y = (j == yy.length()) ? atoi(yy.c_str()) : -1;

					tempMap.push_back(sf::Vector2i(x, y));
				}
			}
			if (tempMap.size() > 0) {
				map.push_back(tempMap);
				tempMap.clear();
			}

		}
		map.push_back(tempMap);

	}
}

Tilemap::Tilemap() {


}

Tilemap::~Tilemap() {

}

void Tilemap::drawTilemap(sf::RenderWindow & window) {
	
	//Tilemapin piirtäminen
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j].x != -1 && map[i][j].y != -1) {
				tiles.setPosition(j * 40, i * 40);
				tiles.setTextureRect(sf::IntRect(map[i][j].x * 40, map[i][j].y * 40, 40, 40));
				window.draw(tiles);
			}
		}
	}

}