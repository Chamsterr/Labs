#pragma once

extern long g_cComponents;
extern long g_cServerLocks;

class ClassFactory : public IClassFactory
{
public:
	virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
	virtual ULONG __stdcall AddRef();
	virtual ULONG __stdcall Release();
	
	virtual HRESULT __stdcall CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv);
	virtual HRESULT __stdcall LockServer(BOOL bLock);

	ClassFactory() : m_cRef(1) {}
	~ClassFactory() { std::cout << "Фабрика класса:\t\tСаморазрушение" << std::endl; }
private:
	long m_cRef;
};