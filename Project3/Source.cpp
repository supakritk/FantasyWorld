#include "Map.hpp"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int r, c, p;
	srand((unsigned int)time(NULL));
	std::cout << "Pls input number of row: ";
	std::cin >> r;
	std::cout << "Pls input number of collumn: ";
	std::cin >> c;
	std::cout << "Pls input number of monsters you want to spawn on map: ";
	std::cin >> p;

	REQUIRE(r * c >= p);

	auto world = std::make_shared<Map>(r, c, p);

	world->initMap();
	world->spawner();
	system("pause");

	return 0;
}