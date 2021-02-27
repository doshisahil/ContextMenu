// dllmain.h : Declaration of module class.

class CContextMenuModule : public ATL::CAtlDllModuleT< CContextMenuModule >
{
public :
	DECLARE_LIBID(LIBID_ContextMenuExtensionLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_CONTEXTMENU, "{ba7ffb13-09fd-42e1-a91d-f36ee657ef9c}")
};

extern class CContextMenuModule _AtlModule;
