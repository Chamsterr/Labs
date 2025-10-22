#pragma once
#include <objbase.h>

class CFactory : public IClassFactory
{
public:
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv);
	virtual ULONG STDMETHODCALLTYPE AddRef(void);
	virtual ULONG STDMETHODCALLTYPE Release(void);


	virtual HRESULT STDMETHODCALLTYPE CreateInstance(IUnknown* pUO, const IID& id, void** ppv);
	//Ётот метод создает новый экземпл€р объекта с указанным идентификатором id. 
	//ѕараметры pUO и ppv предназначены дл€ передачи объекта, который может использоватьс€ при создании, и дл€ возвращени€ указател€ на новый объект.
	virtual HRESULT STDMETHODCALLTYPE LockServer(BOOL b);
	//Ётот метод блокирует или разблокирует сервер (например, сервер COM), чтобы предотвратить его выгрузку из пам€ти

	CFactory();
	~CFactory();

private:
	ULONG m_lRef;
};