#include "pch.h"
#include "PopupContextMenu.h"

std::string PopupContextMenu::getMenuText()
{
	return std::string();
}

void PopupContextMenu::execute()
{

}

bool PopupContextMenu::shouldBeVisible(std::filesystem::path pSelectedFiles)
{
	return true;
}
