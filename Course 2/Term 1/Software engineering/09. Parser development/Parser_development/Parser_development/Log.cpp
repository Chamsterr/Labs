#include "pch.h"
#include "Error.h"
#include "Parm.h"
#include "In.h"
#include "Log.h"
#include <ctime>

namespace Log
{
	LOG getlog(wchar_t logfile[]) {

		LOG log;
		std::ofstream* fout = new std::ofstream;
		fout->open(logfile);
		log.stream = fout;
		(*(log.stream)).open(logfile);

		if (!(*(log.stream)).is_open()) {
			throw ERROR_THROW(112);
		}
		else
			wcscpy_s(log.logfile, logfile);
		fout->close();
		return log;
	}

	void WriteLine(LOG log, char* c, ...) {
		int* arr_for_parm = (int*)(&c);
		int k = 0;
		
		char str[PARAM_MAX_SIZE] = {""};

		while (arr_for_parm[k] != (int)(""))
		{
			char* parm_item = (char*)arr_for_parm[k];
			strncat_s(str, _countof(str), parm_item, 100);
			k++;
		}
		(*(log.stream)).open(log.logfile);
		(*(log.stream)) << str;
	}
	void WriteLine(LOG log, wchar_t* c, ...){
		int* arr_for_parm_for_wchart = (int*)(&c);
		int k = 0;

		size_t i;

		wchar_t str_for_wchart[PARAM_MAX_SIZE] = { L"" };

		while (arr_for_parm_for_wchart[k] != (int)(""))
		{
			if (arr_for_parm_for_wchart[k] == (int)L"")
				break;

			wchar_t* parm_item_for_wchart = (wchar_t*)arr_for_parm_for_wchart[k];
			wcsncat_s(str_for_wchart, _countof(str_for_wchart), parm_item_for_wchart, 100);
			k++;
		}
		char buffer_for_parm_item_char_[PARAM_MAX_SIZE];
		wcstombs_s(&i, buffer_for_parm_item_char_, (size_t)PARAM_MAX_SIZE, str_for_wchart, (size_t)PARAM_MAX_SIZE);
		(*(log.stream)) << buffer_for_parm_item_char_;
	}
	void WriteLog(LOG log) {
		size_t i;
		time_t ltime;
		wchar_t buf[26];
		errno_t err;

		time(&ltime);

		err = _wctime_s(buf, 26, &ltime);
		char buf_for_char[26];
		wcstombs_s(&i, buf_for_char, (size_t)26, buf, (size_t)26);
		(*(log.stream)) << "-----------Протокол---------- " << buf_for_char;

	}
	void WriteParm(LOG log, Parm::PARM parm) {
		size_t i;
		char buffer_for_log[PARAM_MAX_SIZE], buffer_for_out[PARAM_MAX_SIZE], buffer_for_in[PARAM_MAX_SIZE];

		wcstombs_s(&i, buffer_for_log, (size_t)PARAM_MAX_SIZE, parm.log, (size_t)PARAM_MAX_SIZE);
		wcstombs_s(&i, buffer_for_out, (size_t)PARAM_MAX_SIZE, parm.out, (size_t)PARAM_MAX_SIZE);
		wcstombs_s(&i, buffer_for_in, (size_t)PARAM_MAX_SIZE, parm.in, (size_t)PARAM_MAX_SIZE);

		(*(log.stream)) << "-----------Параметры---------- \n";
		(*(log.stream)) << "-log: " << buffer_for_log << std::endl;
		(*(log.stream)) << "-out: " << buffer_for_out << std::endl;
		(*(log.stream)) << "-in: " << buffer_for_in << std::endl;
	}
	void WriteIn(LOG log, In::IN in) {
		(*(log.stream)) << "-----------Исходные данные---------- \n";
		(*(log.stream)) << "Всего символов: " << in.size << std::endl;
		(*(log.stream)) << "Всего строк:  " << in.lines << std::endl;
		(*(log.stream)) << "Пропущено:  " << in.ignor << std::endl;
	}

	void WriteError(LOG log, Error::ERROR error) {
		if ((*(log.stream))) {
			std::cout << std::endl << "Ошибка " << error.id << ": " << error.message
				<< ", строка " << error.inext.line
				<< ", позиция " << error.inext.col << std::endl << std::endl;
			(*(log.stream)) << "Ошибка " << error.id << ": " << error.message
				<< ", строка " << error.inext.line
				<< ", позиция " << error.inext.col << std::endl << std::endl;
		}
		else {
			std::cout << std::endl << "Ошибка " << error.id << ": " << error.message
				<< ", строка " << error.inext.line << ", позиция " << error.inext.col << std::endl << std::endl;
		}
	}
	void Close(LOG log) {
		(*(log.stream)).close();
	}
}