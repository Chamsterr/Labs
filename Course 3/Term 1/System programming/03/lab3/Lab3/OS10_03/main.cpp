#pragma comment(lib, "../debug/OS10_HTAPI.lib")

#include "../OS10_HTAPI/pch.h"
#include "../OS10_HTAPI/HT.h"

using namespace std;

int main()
{
	ht::HtHandle* ht1 = nullptr;
	ht::HtHandle* ht2 = nullptr;

	//HT 1

	try
	{
		cout << "HT1" << endl;
		ht1 = ht::create(1000, 3, 10, 256, L"./files/HT_Together.ht");
		if (!ht1) throw "create: error";

		cout << "ht1: " << ht1->addr << endl;

		if (!ht::insert(ht1, new ht::Element("key", 3, "payload", 8))) throw "insert: error";
	}
	catch (const char* msg)
	{
		cout << msg << endl;

		if (ht1 != nullptr) cout << ht::getLastError(ht1) << endl;
	}

	//HT 2

	try
	{
		cout << "\nHT2" << endl;
		ht2 = ht::open(L"./files/HT_Together.ht", true);
		if (!ht2) throw "create: error";

		cout << "ht2: " << ht2->addr << endl;

		ht::Element* hte = ht::get(ht1, new ht::Element("key", 3));
		if (!hte) throw "get: error";
		ht::print(hte);
	}
	catch (const char* msg)
	{
		cout << msg << endl;

		if (ht1 != nullptr)
			cout << ht::getLastError(ht1) << endl;
	}


	try
	{
		if (ht1 != nullptr && !ht::close(ht1))throw "close: error (ht1)";

		if (ht2 != nullptr && !ht::close(ht2)) throw "close: error (ht2)";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}