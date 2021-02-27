#pragma once
#include <string>
#include <vector>
#include "Selection.h"
#include <memory>

class ContextMenu
{
public:
	virtual bool shouldBeVisible(std::filesystem::path pSelectedFiles) = 0;
	virtual std::string getMenuText() = 0;
	virtual void execute() = 0;
	virtual ~ContextMenu() {}
};

using ContextMenuUPtr = std::unique_ptr<ContextMenu>;