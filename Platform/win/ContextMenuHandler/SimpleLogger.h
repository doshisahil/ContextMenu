#pragma once
#include <string>
#include <iostream>
#include <fstream>

class SimpleLogger
{
private:
	std::ofstream mLogFile;

public:

	SimpleLogger();
	~SimpleLogger();
	void log(std::string pstrMessage);
};

