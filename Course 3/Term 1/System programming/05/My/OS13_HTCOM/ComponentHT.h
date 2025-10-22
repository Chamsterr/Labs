#pragma once
#include "Interface.h"

extern long g_cComponents;		// ���������� �������� �����������
extern long g_cServerLocks;		// ������� ����������

// ���������
//
class ComponentHT : public IHT, public IElement
{
public:
	// IUnknown
	virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
	virtual ULONG __stdcall AddRef();
	virtual ULONG __stdcall Release();

	// ��������� IHT
	STDMETHOD(create(ht::HtHandle** htHandle, int capacity, int secSnapshotInterval, int maxKeyLength, int maxPayloadLength, const wchar_t* fileName));
	STDMETHOD(open(ht::HtHandle** htHandle, const wchar_t* fileName, bool isMapFile = false));
	STDMETHOD(snap(BOOL& rc, ht::HtHandle* htHandle));
	STDMETHOD(close(BOOL& rc, ht::HtHandle* htHandle));
	STDMETHOD(insert(BOOL& rc, ht::HtHandle* htHandle, const ht::Element* element));
	STDMETHOD(removeOne(BOOL& rc, ht::HtHandle* htHandle, const ht::Element* element));
	STDMETHOD(get(ht::Element** rcElement, ht::HtHandle* htHandle, const ht::Element* element));
	STDMETHOD(update(BOOL& rc, ht::HtHandle* htHandle, const ht::Element* oldElement, const void* newPayload, int newPayloadLength));
	STDMETHOD(getLastError(const char** lastError, ht::HtHandle* htHandle));
	STDMETHOD(print(const ht::Element* element));

	// ��������� IElement
	STDMETHOD(createGetElement(ht::Element** getElement, const void* key, int keyLength));
	STDMETHOD(createInsertElement(ht::Element** newElement, const void* key, int keyLength, const void* payload, int  payloadLength));
	STDMETHOD(createUpdateElement(ht::Element** updateElement, const ht::Element* oldElement, const void* newPayload, int  newPayloadLength));

	// �����������
	ComponentHT() : m_cRef(1)
	{
		InterlockedIncrement(&g_cComponents);
	}
	// ����������
	~ComponentHT()
	{
		InterlockedDecrement(&g_cComponents);
		std::cout << "���������:\t\t��������������" << std::endl;
	}

private:
	// ������� ������
	long m_cRef;
};