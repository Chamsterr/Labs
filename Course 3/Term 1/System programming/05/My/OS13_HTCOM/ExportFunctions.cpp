#include "pch.h"
#include "ExportFunctions.h"
#include "Registry.h"
#include "ClassFactory.h"

//
// �������������� �������
//
//
// ����� �� ��������� DLL?
//
STDAPI DllCanUnloadNow()
{
	if ((g_cComponents == 0) && (g_cServerLocks == 0))
	{
		return S_OK;
	}
	else
	{
		return S_FALSE;
	}
}

//
// �������� ������� ������
//
STDAPI DllGetClassObject(const CLSID& clsid,
	const IID& iid,
	void** ppv)
{
	std::cout << "DllGetClassObject:\t������� ������� ������" << std::endl;
	// ����� �� ������� ����� ���������?
	if (clsid != CLSID_ComponentHT)
	{
		return CLASS_E_CLASSNOTAVAILABLE;
	}
	// ������� ������� ������
	ClassFactory* pFactory = new ClassFactory; // ������� ������ ��������������� � ������������ � 1
	if (pFactory == NULL)
	{
		return E_OUTOFMEMORY;
	}
	// �������� ��������� ���������
	HRESULT hr = pFactory->QueryInterface(iid, ppv);
	pFactory->Release();

	return hr;
}

//
// ����������� �������
//	
STDAPI DllRegisterServer()
{
	return RegisterServer(g_hModule,
		CLSID_ComponentHT,
		g_szFriendlyName,
		g_szVerIndProgID,
		g_szProgID);
}

//
// �������� ������� �� �������
//
STDAPI DllUnregisterServer()
{
	return UnregisterServer(CLSID_ComponentHT,
		g_szVerIndProgID,
		g_szProgID);
}