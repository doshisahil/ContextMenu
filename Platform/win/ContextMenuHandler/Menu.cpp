#include "pch.h"
#include "Menu.h"

bool ContextMenu::shouldBeVisible(Selection pSelection)
{
	return false;
}

std::string ContextMenu::getCommandName()
{
	return std::string();
}

void ContextMenu::execute()
{
}
