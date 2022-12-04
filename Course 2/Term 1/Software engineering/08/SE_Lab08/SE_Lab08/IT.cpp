#include "IT.h"
#include <string>
namespace IT
{
	IdTable::IdTable(int ms) 
	{
		maxsize = ms;
		n = 0;
	}
	Entry::Entry(unsigned int ifLE, std::string i, IT::IDDATATYPE idd, IT::IDTYPE idt)
	{
		idxfirstLE = ifLE;
		strcpy_s(id, i.c_str());
		iddatatype = idd;
		idtype = idt;
	}

	void IdTable::Add(Entry entry)
	{
		table.push_back(entry);
	}

	Entry IdTable::GetEntry(int n) {
		return table[n];
	}

	int IdTable::IsId(char id[ID_MAXSIZE]) {
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