#include <iostream>
import word;
#include <filesystem>
#include <ctime>
#include <memory>
#include <sqlite_orm/sqlite_orm.h>
#include "playersDatabase.h"
#include "Routing.h"

using namespace game;
int main()
{
	PlayerStorage storage;
	if (!storage.Initialize())
	{
		std::cout << "Failed to initialize the database\n";
		return -1;
	}
	Routing r;

	r.Run(storage);

	return 0;
}


