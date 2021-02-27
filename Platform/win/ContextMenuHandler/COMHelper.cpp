#include "pch.h"
#include "COMHelper.h"

COMHelper& COMHelper::getInstance()
{
    static COMHelper sCOMHelper;
    return sCOMHelper;
}

std::vector<std::filesystem::path> COMHelper::getPathsFromDataObject(LPDATAOBJECT pDataObj)
{
    std::vector<std::filesystem::path> lPaths;
    FORMATETC fmt = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
    STGMEDIUM stg = { TYMED_HGLOBAL };
    try
    {
        HDROP hDrop;

        // Look for CF_HDROP data in the data object.
        if (FAILED(pDataObj->GetData(&fmt, &stg)))
        {
            throw std::exception("CF_HDROP not found in data object");
        }

        // Get a pointer to the actual data.
        hDrop = (HDROP)GlobalLock(stg.hGlobal);

        // Make sure it worked.
        if (NULL == hDrop)
        {
            throw std::exception("hDrop is null");
        }

        // Sanity check - make sure there is at least one filename.
        UINT uNumFiles = DragQueryFile(hDrop, 0xFFFFFFFF, NULL, 0);
        HRESULT hr = S_OK;

        if (0 == uNumFiles)
        {
            throw std::exception("Num of file is zero");
        }
        char l_szFile[MAX_PATH + 1];
        // Get the name of the first file and store it in our member variable l_szFile.
        for (int i = 0; i < uNumFiles; i++)
        {
            if (0 == DragQueryFileA(hDrop, 0, l_szFile, MAX_PATH))
            {
                throw std::exception("Failed to get file path");
            }
            lPaths.push_back(l_szFile);
        }
    }
    catch (...)
    {
        GlobalUnlock(stg.hGlobal);
        ReleaseStgMedium(&stg);
        throw;
    }
    return lPaths;
}
