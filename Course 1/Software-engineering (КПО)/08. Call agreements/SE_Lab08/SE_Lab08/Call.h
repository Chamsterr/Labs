#pragma once
#pragma once
namespace call {
	
	int _cdecl cdevl(int a, int b, int c)
	{return a + b + c;}
	int _stdcall cstd(int& a_ref, int b, int c)
	{ return a_ref * b * c; }
	int _fastcall cfst(int a, int b, int c, int d)
	{ return a + b + c + d; }
}































/*
Как только управление передается в вызываемую функцию, до выполнения каких-
либо инструкций внутри нее, первые 4 байта по адресу, хранящемуся в ESP, будут 
содержать адрес возврата, 4 байта по адресу (ESP + 4) будут содержать первый 
параметр, следующие 4 байтах по адресу (ESP + 8) будут содержать второй
параметр

Регистры EAX – это регистры общего назначения
*/