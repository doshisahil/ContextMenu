#pragma once
#include <string>
#include <vector>
#include "Selection.h"
class Menu
{
private:
	std::string mCommandText;

public:
	bool shouldBeVisible(Selection pSelection);
	std::string getCommandName();
	void execute();
};

