// DynamicContextMenu.h : Declaration of the CDynamicContextMenu

#pragma once
#include "resource.h"       // main symbols



#include "ContextMenu_i.h"
#include "SimpleLogger.h"
#include <vector>
#include <string>
#include <filesystem>
#include "ContextMenuRepo.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CDynamicContextMenu

class ATL_NO_VTABLE CDynamicContextMenu :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDynamicContextMenu, &CLSID_DynamicContextMenu>,
	public IShellExtInit,
	public IContextMenu
{
public:
	CDynamicContextMenu()
	{
	}

DECLARE_REGISTRY_RESOURCEID(106)

DECLARE_NOT_AGGREGATABLE(CDynamicContextMenu)

BEGIN_COM_MAP(CDynamicContextMenu)
	COM_INTERFACE_ENTRY(IShellExtInit)
	COM_INTERFACE_ENTRY(IContextMenu)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	// IShellExtInit
	STDMETHODIMP Initialize(LPCITEMIDLIST, LPDATAOBJECT, HKEY);

	// IContextMenu



	STDMETHODIMP GetCommandString(UINT_PTR, UINT, UINT*, LPSTR, UINT);
	STDMETHODIMP InvokeCommand(LPCMINVOKECOMMANDINFO);
	STDMETHODIMP QueryContextMenu(HMENU, UINT, UINT, UINT, UINT);

protected:
	//Selection mSelection;
	std::vector<std::filesystem::path> mFiles;
	SimpleLogger mLogger;
	ContextMenuRepo mContextMenuRepo;
};

OBJECT_ENTRY_AUTO(__uuidof(DynamicContextMenu), CDynamicContextMenu)
