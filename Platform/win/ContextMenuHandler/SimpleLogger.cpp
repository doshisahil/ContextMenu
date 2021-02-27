#include "pch.h"
#include "SimpleLogger.h"
using namespace std;

SimpleLogger::SimpleLogger():mLogFile("C:\\Users\\HIRAL\\Desktop\\log.txt", ofstream::out | ofstream::app)
{
	log("==== Program Loaded =====");
}

void SimpleLogger::log(std::string pstrMessage)
{
	mLogFile << pstrMessage << endl;
}

SimpleLogger::~SimpleLogger()
{
	mLogFile.close();
}