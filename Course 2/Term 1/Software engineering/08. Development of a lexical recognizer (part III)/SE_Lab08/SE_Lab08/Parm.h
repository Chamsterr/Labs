#include <tchar.h> 
#pragma once
#define PARAM_IN L"-in:"                   // ключ для файла исходного кода
#define PARAM_OUT L"-out:"				   // ключ для файла объектного кода
#define PARAM_LOG L"-log:"				   // ключ для файла журнала

#define PARAM_MAX_SIZE 300                 // максимальная длина строки параметра
#define PARAM_OUT_DEFAULT_EXT L".out"      // расширение файла объектного кода по умолчанию
#define PARAM_LOG_DEFAULT_EXT L".log"      // расширение файла протокола по умолчанию

namespace Parm // обработка входных параметров
{
	struct PARM // входные данные
	{
		wchar_t in[PARAM_MAX_SIZE]; // -in имя файла исходного кода
		wchar_t out[PARAM_MAX_SIZE]; // -out имя файла объектоного кода
		wchar_t log[PARAM_MAX_SIZE]; // -log имя файла протокола 
	};

	PARM getparm(int argc, _TCHAR* argv[]);
};