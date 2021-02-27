#pragma once
#include <string>
#include <vector>
#include "Input.h"
#include <map>
class CommandEngine
{
private:
	std::string mstrCommand;
public:
	CommandEngine();
	std::vector<std::string> extractRequiredInputs();
	void executeCommand(std::map<std::string, std::string> pInputs);
};