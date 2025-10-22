#include "HT.h"

using namespace std;

int main()
{
	ht::HtHandle* ht = nullptr;
	try
	{
		ht = ht::create(
			1000,	// capacity
			1,		// seconds snapshot
			20,		// max key length
			256,	// max payload length
			L"./files/TEST_HT.ht"
		);
		if (!ht) throw "create: error";

		if (!ht::insert(ht, new ht::Element("Key", 3, "payloadData", 11))) throw "insert1: error";

		if (!ht::insert(ht, new ht::Element("Key", 3, "payloadData", 11))) throw "insert2: error";

		ht::Element* hte = ht::get(ht, new ht::Element("Key", 1));
		if (!hte) throw "get: error";
		ht::print(hte);

		if (!ht::update(ht, hte, "newPayloadData", 22))	throw "update: error";

		if (!ht::snap(ht)) throw "snap: error";

		hte = ht::get(ht, new ht::Element("Key", 3));
		if (!hte) throw "get: error";
		ht::print(hte);

		SleepEx(3000, TRUE);

		if (!ht::remove(ht, hte)) throw "remove: error";

		hte = ht::get(ht, new ht::Element("Key", 3));
		if (!hte) throw "get: error (Remove TEST)";
	}
	catch (const char* msg)
	{
		cout << msg << endl;

		if (ht != nullptr) cout << ht::getLastError(ht) << endl;
	}

	try
	{
		if (ht != nullptr && !ht::close(ht)) throw "close: error";

		cout << "Program was executed correctly";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}