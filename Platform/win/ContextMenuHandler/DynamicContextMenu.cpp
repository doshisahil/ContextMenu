// DynamicContextMenu.cpp : Implementation of CDynamicContextMenu

#include "pch.h"
#include "DynamicContextMenu.h"
#include <exception>
#include "COMHelper.h"
// CDynamicContextMenu
#include "Poco/AutoPtr.h"
#include "Poco/Util/PropertyFileConfiguration.h"
#include "Poco/Util/JSONConfiguration.h"
#include "ContextMenuRepo.h"

using namespace std;
using Poco::AutoPtr;
using Poco::Util::JSONConfiguration;

STDMETHODIMP CDynamicContextMenu::Initialize(
    LPCITEMIDLIST pidlFolder, LPDATAOBJECT pDataObj, HKEY hProgID)
{
    mLogger.log("CDynamicContextMenu::Initialize");
    try
    {
        this->mFiles = COMHelper::getInstance().getPathsFromDataObject(pDataObj);
    }
    catch (const std::exception&)
    {
        return E_INVALIDARG;
    }
   
    return S_OK;
}

STDMETHODIMP CDynamicContextMenu::QueryContextMenu(
    HMENU hmenu, UINT uMenuIndex, UINT uidFirstCmd,
    UINT uidLastCmd, UINT uFlags)
{
    mLogger.log("CDynamicContextMenu::QueryContextMenu");
    // If the flags include CMF_DEFAULTONLY then we shouldn't do anything.
    if (uFlags & CMF_DEFAULTONLY)
    {
        return MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_NULL, 0);
    }
    std::vector<ContextMenuUPtr> mMenus = 
        mContextMenuRepo.getContextMenuForSelection(mFiles);
    mLogger.log("loop started");
    for (UINT liIndex = 0; liIndex < mMenus.size(); liIndex++)
    {
        mLogger.log("loop");

        if (uidFirstCmd + liIndex > uidLastCmd)
        {
            mLogger.log("Maximum limit reached");
            break;
        }
        InsertMenuA(hmenu, uMenuIndex + liIndex, MF_BYPOSITION, uidFirstCmd + liIndex, mMenus[liIndex]->getMenuText().c_str());
    }
    return MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_NULL, 1);
}

STDMETHODIMP CDynamicContextMenu::GetCommandString(
    UINT_PTR idCmd, UINT uFlags, UINT* pwReserved, LPSTR pszName, UINT cchMax)
{
    mLogger.log("CDynamicContextMenu::GetCommandString");
    USES_CONVERSION;

    // If Explorer is asking for a help string, copy our string into the
    // supplied buffer.
    if (uFlags & GCS_HELPTEXT)
    {
        LPCTSTR szText = _T("This is the simple shell extension's help");

        if (uFlags & GCS_UNICODE)
        {
            // We need to cast pszName to a Unicode string, and then use the
            // Unicode string copy API.
            lstrcpynW((LPWSTR)pszName, T2CW(szText), cchMax);
        }
        else
        {
            // Use the ANSI string copy API to return the help string.
            lstrcpynA(pszName, T2CA(szText), cchMax);
        }
        return S_OK;
    }
    return E_INVALIDARG;
}

STDMETHODIMP CDynamicContextMenu::InvokeCommand(LPCMINVOKECOMMANDINFO pCmdInfo)
{
    mLogger.log("CDynamicContextMenu::InvokeCommand");
    // If lpVerb really points to a string, ignore this function call and bail out.
    if (0 != HIWORD(pCmdInfo->lpVerb))
        return E_INVALIDARG;

    // Get the command index - the only valid one is 0.
    switch (LOWORD(pCmdInfo->lpVerb))
    {
    case 0:
    {
        char szMsg[MAX_PATH + 32];

        sprintf_s(szMsg, "The selected file was:\n\n%s", this->mFiles[0].c_str());
        string lstrMessage = "The selected file was:\n\n";
        //lstrMessage.append(this->mFiles[0].string());
        MessageBoxA(pCmdInfo->hwnd, lstrMessage.c_str(), "SimpleShlExt",
            MB_ICONINFORMATION);

        return S_OK;
    }
    break;

    default:
        return E_INVALIDARG;
        break;
    }
}
