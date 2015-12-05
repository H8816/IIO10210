#include "CollisionCoords.h"

void CollisionCoords::initCol() {
	
	ifstream openfile("lvl1.txt");
	if (openfile.is_open()) {

		string tileLocation;
		openfile >> tileLocation;

		while (!openfile.eof()) {

			string loader;
			openfile >> loader;
			char x = loader[0], y = loader[2];

			//Tilemapin piirtäminen
			for (int i = 0; i < loadCounter.x; i++) {
				for (int j = 0; j < loadCounter.y; j++) {
					if (!isdigit(x) || !isdigit(y)) {
						if (loader[0] == '0' && loader[2] == '0')
							colTiles[i][j].setColHeight(0);
						else if (loader[0] == '0' && loader[2] == '1') {
							colTiles[i][j].setColHeight(1);
						}
						else
							colTiles[i][j].setColHeight(2);
					}

					if (openfile.peek() == '\n') {

						//Resetoi x koordinaatin 0		
						loadCounter.x = 0;
						// lisää y koordinaattia yhdellä
						loadCounter.y++;
					}
					else
						loadCounter.x++;
				}
				loadCounter.y++;
			}
		}
	}
}

void CollisionCoords::setCollisionMap() {

	for (int i = 0; i < loadCounter.x; i++) {
		for (int j = 0; j < loadCounter.y; j++) {
			if (colTiles[i][j].getPosX() != -1 && colTiles[i][j].getPosY() != -1) {
				colTiles[i][j].setPosition(i * 40, j * 40);

			}
		}
	}

}

CollisionCoords::CollisionCoords() {

}

CollisionCoords::~CollisionCoords() {

}

//TÄSTÄ TULEE COLLISION MAPPAUS
//20x20 COLLISION BOX OLIOTA JOTKA VOI TUHOTA