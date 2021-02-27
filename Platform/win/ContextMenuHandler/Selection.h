#pragma once
#include <vector>
#include <filesystem>
class Selection
{
private:
	std::vector<std::filesystem::path> mSelection;

public:

	void addSelection(LPDATAOBJECT pDataObj);
	virtual bool isSingleFile() = 0;
	virtual bool isAllFile() = 0;
	virtual bool isAllFolder() = 0;
	virtual bool isSingleFolder() = 0;
	virtual bool isMultipleSelected() = 0;
	virtual std::filesystem::path getPath() = 0;
	virtual std::vector<std::filesystem::path> getSelectedPath() = 0;
	virtual std::vector<std::filesystem::path> getPathRecursively() = 0;
};