#include "Map.hpp"

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int r, c, p;
	srand((unsigned int)time(NULL));
	cout << "Pls input number of row: ";
	cin >> r;
	cout << "Pls input number of collumn: ";
	cin >> c;
	cout << "Pls input number of monsters you want to spawn on map: ";
	cin >> p;

	REQUIRE(r * c >= p);

	auto world = make_shared<Map>(r, c, p);

	world->initMap();
	world->spawner();
	world->autoNextTurn();
}