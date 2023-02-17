#include "pch.h"
#include "Error.h"
#include "Parm.h"
#include "In.h"
#include "Log.h"

int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "ru");
	//----------------------Функция для тестирования Errors-----------------
	//std::cout << "---- тест Error::geterror ----" << std::endl << std::endl;
	//try { throw ERROR_THROW(85); }
	//catch (Error::ERROR e) {
	//	std::cout << "Ошибка " << e.id << ": " << e.message << std::endl << std::endl;
	//};

	//try { throw ERROR_THROW_IN(111, 7, 7); }
	//catch (Error::ERROR e) {
	//	std::cout << "Ошибка " << e.id << ": " << e.message
	//			  << ", строка " << e.inext.line
	//			  << ", позиция " << e.inext.col << std::endl << std::endl;
	//};
	// ---------------------------------------------------------------------


	/*----------------------Функция для тестирования Parm-------------------*/
	/*std::cout << "---- тест Parm::getparm ----" << std::endl << std::endl;*/
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		std::wcout << "-in:" << parm.in << ", -out:" << parm.out << ", -log:" << parm.log << std::endl << std::endl;

	}
	catch (Error::ERROR e)
	{
		std::cout << "Ошибка " << e.id << ": " << e.message << std::endl << std::endl;
		return 0;
	}
	// ---------------------------------------------------------------------


	/*----------------------Функция для тестирования getin-------------------*/

	//std::cout << "---- тест In::getin ----" << std::endl << std::endl;
	//try
	//{
	//	Parm::PARM parm = Parm::getparm(argc, argv);
	//	In::IN in = In::getin(parm.in);
	//	/*std::cout << in.text << std::endl;*/
	//	std::cout << "Всего символов: " << in.size << std::endl;
	//	std::cout << "Всего строк:  " << in.lines << std::endl;
	//	std::cout << "Пропущено:  " << in.lines << std::endl;
	//}
	//catch (Error::ERROR e)
	//{
	//	std::cout << "Ошибка " << e.id << ": " << e.message << std::endl << std::endl;
	//};
	//system("pause");
	//// ---------------------------------------------------------------------

	/*----------------------Функция для тестирования getin 2-------------------*/

	//std::cout << "---- тест In::getin 2 ----" << std::endl << std::endl;
	//try
	//{
	//	Parm::PARM parm = Parm::getparm(argc, argv);
	//	In::IN in = In::getin(parm.in);
	//	/*std::cout << in.text << std::endl;*/
	//	std::cout << "Всего символов: " << in.size << std::endl;
	//	std::cout << "Всего строк:  " << in.lines << std::endl;
	//	std::cout << "Пропущено:  " << in.lines << std::endl;
	//}
	//catch (Error::ERROR e)
	//{
	//	std::cout << "Ошибка " << e.id << ": " << e.message << std::endl << std::endl;
	//	std::cout << " строка " << e.inext.line << " позиция " << e.inext.col << std::endl << std::endl;
	//};
	//system("pause");
	// ---------------------------------------------------------------------

	/*----------------------Функция для тестирования log-------------------*/

	/*std::cout << "---- тест In::log ----" << std::endl << std::endl;*/
	Log::LOG log = Log::INITLOG;

	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, (char*)"Тест:", (char*)" без ошибок \n", "");
		Log::WriteLine(log, (wchar_t*)L"Тест:", (wchar_t*)L" без ошибок \n", L"");
		setlocale(LC_ALL, "en_US.UTF8");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in, parm.out);
		Log::WriteIn(log, in);
		Log::Close(log);
	}
	catch (Error::ERROR error)
	{
		setlocale(LC_ALL, "ru");
		Log::WriteError(log, error);
	};

	// ---------------------------------------------------------------------


	return 0;
}