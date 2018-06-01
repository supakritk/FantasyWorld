#include "GameController.hpp"

using namespace std;

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	auto game = make_shared<GameController>();

	game->gameStart();

	game->spawner->spawn(game->map->getNumber(), game->map->mapdata, game->map->monsterdata);
	
	system("pause");

	return 0;
}