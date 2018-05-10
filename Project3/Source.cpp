#include "Map.h"

int main() {
	srand(time(NULL));
	Map* world = new Map(5,5,50);
	world->initMap();
	world->spawner();
	world->drawMap();
	world->nextTurn();
}