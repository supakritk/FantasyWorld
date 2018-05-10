#include "Map.h"

int main() {
	int r, c, p;
	srand(time(NULL));
	cout << "Pls input number of row: ";
	cin >> r;
	cout << "Pls input number of collumn: ";
	cin >> c;
	cout << "Pls input monster percent you want to spawn on map: ";
	cin >> p;

	Map* world = new Map(r,c,p);
	world->initMap();
	world->spawner();
	world->drawMap();
	world->nextTurn();
}