#pragma once
#include <fstream>
#include "In.h"
#include "Parm.h"
#include "Error.h"
#include "pch.h"

namespace Log	// –абота с протоколом
{
	struct LOG // протокол
	{
		wchar_t logfile[PARAM_MAX_SIZE]; // им€ файла протокола
		std::ofstream* stream;
	};

	static const LOG INITLOG { L"", NULL }; // структура дл€ начальной инициализации LOG
	LOG getlog(wchar_t logfile[]); // сформировать структуру LOG
	void WriteLine(LOG log, char* c, ...); // вывести в протокол конкатенацию строк 
	void WriteLine(LOG log, wchar_t* c, ...); // вывести в протоокол конкатенацию строк 
	void WriteLog(LOG log); // вывести в протокол заголовок
	void WriteParm(LOG log, Parm::PARM parm); // вывести в протокол информации о входных параметрах
	void WriteIn(LOG log, In::IN in); // вывести в протокол информацию о входном потоке
	void WriteError(LOG log, Error::ERROR error); // вывести в протокол информацию об ошибке
	void Close(LOG log);
};
