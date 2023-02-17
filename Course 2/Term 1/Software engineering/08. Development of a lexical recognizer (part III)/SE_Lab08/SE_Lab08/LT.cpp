#include "LT.h"
#include <memory>
#include <iostream>

namespace LT // ������� ������
{
	LexTable::LexTable(int ms) {
		maxsize = ms;
		size = 0;
		table = {};
	}

	void LexTable::Add(Entry entry) {
		table.push_back(entry);
	}

	Entry LexTable::GetEntry(int n) {
		return table[n];
	}

	void LexTable::Delete() {
		std::vector<Entry>().swap(table);
	}
}