#include "CollisionMap.h"

CollisionMap::CollisionMap() {

}

CollisionMap::~CollisionMap() {

}

void CollisionMap::initColMap(const char*filename) {
	
	ifstream openfile(filename);
	colMap.clear();

	if (openfile.is_open()) {


		//Tiletekstitiedoston luenta  ja muuntaminen kuviksi
		while (!openfile.eof()) {
			
			string str, value;
			getline(openfile, str);
			stringstream stream(str);

			while (getline(stream, value, ' ')) {
				if (value.length() > 0) {
					int a = atoi(value.c_str());
					tempMap.push_back(a);
				}
			}
			if (tempMap.size() > 0) {
				colMap.push_back(tempMap);
				tempMap.clear();
			}

		}
		colMap.push_back(tempMap);

	}
}

void CollisionMap::setColMap(Character p) {
	for (int i = 0; i < colMap.size(); i++) {
		for (int j = 0; j < colMap[i].size(); j++) {
			if (colMap[i][j] == 1) {
				float bottom, top, left, right;
				bottom = i * 40 + 40;
				top = i * 40;
				left = j * 40;
				right = j * 40 + 40;
				
				if (p.getPositionX() > right || p.getPositionX() + 40 < left || p.getPositionY() > bottom || p.getPositionY() + 40 < top) {
					pass();
				}
				else if (p.getPositionY() + 40 > top) {
					collideBottom(p);
				}
				else if (p.getPositionY() > bottom) {
						collideTop(p);
				}
				else if (p.getPositionX() + 40 > left) {
						collideLeft(p);
				}
				else if (p.getPositionX() < right) {
					collideRight(p);
				}
				
			}
		}
	}
}
void CollisionMap::collideLeft(Character p) {
	p.moveRight(0);
	cout << "collideLeft!" << endl;
}

void CollisionMap::collideRight(Character p) {
	p.moveLeft(0);
	cout << "collideRight!" << endl;
}

void CollisionMap::collideTop(Character p) {
	p.moveDown(0);
	cout << "collideTop!" << endl;
}

void CollisionMap::collideBottom(Character p) {
	p.moveUp(0);
	cout << "collideBot!" << endl;
}

bool CollisionMap::getCollision() {
	return collision;
}

void CollisionMap::pass() {
	this->collision = false;
} 