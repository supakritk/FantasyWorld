#include "Map.h"

int main() {
	srand(time(NULL));
	Map* world = new Map(30,30,50);
	world->initMap();
	world->spawner();
	world->drawMap();
	world->nextTurn();
}