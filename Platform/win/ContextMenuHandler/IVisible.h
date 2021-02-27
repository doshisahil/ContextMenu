#pragma once
#include "Selection.h"

class IVisible
{
public:
	virtual bool shouldBeVisible(Selection pSelection);
};