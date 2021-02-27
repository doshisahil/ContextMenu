#pragma once
#include "ContextMenu.h"
#include <string>
#include <vector>
#include "Input.h"
enum Selection_Count {
	Selection_Count_SINGLE,
	Selection_Count_MULTIPLE
};

enum Selection_Type{
	Selection_Type_FILE,
	Selection_Type_FOLDER,
	Selection_Type_ANY
};

class PopupContextMenu : public ContextMenu
{
private:
	std::string mstrCommand;
	std::string mstrMenuText;
	Selection_Count mCount;
	Selection_Type mType;
	//std::string mstrFilterRegex;

public:
	PopupContextMenu();
	// Inherited via ContextMenu
	virtual bool shouldBeVisible(std::filesystem::path pSelectedFiles) override;

	virtual std::string getMenuText() override;

	virtual void execute() override;
};