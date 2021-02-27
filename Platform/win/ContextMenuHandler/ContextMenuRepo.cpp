#include "pch.h"
#include "ContextMenuRepo.h"
#include "ContextMenu.h"
using namespace std;
class MockContextMenu : public ContextMenu
{
public:
	// Inherited via ContextMenu
	MockContextMenu()
	{

	}
	virtual bool shouldBeVisible(std::filesystem::path pSelectedFiles) override
	{
		return true;
	}
	virtual std::string getMenuText() override
	{
		return std::string("Hello World");
	}
	virtual void execute() override
	{
	}
};
std::vector<ContextMenuUPtr> ContextMenuRepo::getContextMenuForSelection(std::vector<std::filesystem::path> pSelectedFiles)
{
	std::vector<ContextMenuUPtr> lContextMenus;
	lContextMenus.push_back(make_unique<MockContextMenu>());
	//lContextMenus.push_back(new MockContextMenu());
	return lContextMenus;
}
