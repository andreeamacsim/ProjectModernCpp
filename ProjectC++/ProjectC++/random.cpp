module random;
import <iostream>;
#include <ctime>
using namespace game;
int game::generateGameCode()
{
	int nr = std::rand() % 900000 + 100000;
	return nr;
}

