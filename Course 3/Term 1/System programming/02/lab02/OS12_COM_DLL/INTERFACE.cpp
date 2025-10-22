#include "pch.h"
#include "INTERFACE.h"
#include "SEQLOG.h"
#include "CFactory.h"

extern ULONG g_ServerLocks;
extern ULONG g_Components;

//дл€ определени€, можно ли выгрузить данную DLL из пам€ти.
STDAPI DllCanUnloadNow() { 
	SEQ;
	HRESULT rc = E_UNEXPECTED; //неожиданный сбой операции по умолчанию.
	if ((g_ServerLocks == 0) && (g_Components == 0))
		rc = S_OK; // если нет активных блокировок сервера и нет активных экземпл€ров компонент
	else 
		rc = S_FALSE;

	LOG("DllCanUnloadNow: rc = ", rc);
	return rc;
}

//дл€ получени€ объекта класса фабрики дл€ создани€ экземпл€ров объектов данного класса.
STDAPI DllGetClassObject(const CLSID& clsid, const IID& iid, void ** ppv) {
	SEQ;
	CFactory* pF;
	HRESULT rc = E_UNEXPECTED;
	if (clsid != CLSID_CA)
		rc = CLASS_E_CLASSNOTAVAILABLE;	//запрашиваемый класс не поддерживаетс€
	else if ((pF = new CFactory()) == NULL)	//создаетс€ новый объект класса CFactory. 
		rc = E_OUTOFMEMORY;
	else {
		//дл€ получени€ указанного интерфейса (iid) от новосозданного объекта CFactory. 
		rc = pF->QueryInterface(iid, ppv);
		pF->Release();
	}
	LOG("DllGetClassObject: rc = ", rc);
	return rc;
}