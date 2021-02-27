#pragma once
#include <vector>
#include <filesystem>

class COMHelper
{
public:
	static COMHelper& getInstance();
	std::vector<std::filesystem::path> getPathsFromDataObject(LPDATAOBJECT pDataObj);
};

