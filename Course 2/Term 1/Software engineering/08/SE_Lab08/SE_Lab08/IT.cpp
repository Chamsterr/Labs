#include "IT.h"
namespace IT
{
	IdTable::IdTable(int ms) 
	{
		maxsize = ms;
		n = 0;
		table = {};
	}

	void IdTable::Add(Entry entry)
	{
		table.push_back(entry);
	}

	Entry IdTable::GetEntry(int n) {
		return table[n];
	}

	int IdTable::IsId(const char* id[ID_MAXSIZE]) {
		for (int i = 0; i < table.size(); i++) {
			if (table[i].id == id) {
				return table[i].value.vint;
			}
		}
		return TI_NULLIDX;
	}

	void IdTable::Delete() {
		std::vector<Entry>().swap(table);
	}
}