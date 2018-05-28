#include "Map.hpp"
#include "GameController.hpp"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	/*
	int r, c, m;
	srand((unsigned int)time(NULL));
	std::cout << "Pls input number of row: ";
	std::cin >> r;
	std::cout << "Pls input number of collumn: ";
	std::cin >> c;
	std::cout << "Pls input number of monsters you want to spawn on map: ";
	std::cin >> m;

	REQUIRE(r * c >= m);

	auto world = std::make_shared<Map>(r, c, m);

	world->initMap();
	world->spawner();
	world->playerController();
	*/
	
	system("pause");

	return 0;
}