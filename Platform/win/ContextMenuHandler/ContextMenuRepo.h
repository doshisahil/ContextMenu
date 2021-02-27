#pragma once
#include "Selection.h"
#include "ContextMenu.h"
#include <vector>
#include <filesystem>

class ContextMenuRepo
{

public:
	std::vector<ContextMenuUPtr> getContextMenuForSelection(std::vector<std::filesystem::path> pSelectedFiles);
};

