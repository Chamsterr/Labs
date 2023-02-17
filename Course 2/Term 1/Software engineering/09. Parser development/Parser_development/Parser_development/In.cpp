#include "pch.h"
#include "In.h"
#include "Error.h"
#include "Parm.h"
#include <fstream>
#include <locale>
#include <sys/stat.h>
#include <filesystem>
#include "LT.h"
#include <string>
#include <vector>
#include "IT.h"
#include "FST.h"
#include "MFST.h"

namespace In
{
	LT::LexTable LT(150);
	IT::IdTable IT(150);
	bool try_recognition(In::word_with_number_line word)
	{
		if (word.word[0] == 'f') {
			FST::FST fst2(
				word.word,
				9,
				FST::NODE(1, FST::RELATION('f', 1)),
				FST::NODE(1, FST::RELATION('u', 2)),
				FST::NODE(1, FST::RELATION('n', 3)),
				FST::NODE(1, FST::RELATION('c', 4)),
				FST::NODE(1, FST::RELATION('t', 5)),
				FST::NODE(1, FST::RELATION('i', 6)),
				FST::NODE(1, FST::RELATION('o', 7)),
				FST::NODE(1, FST::RELATION('n', 8)),
				FST::NODE()
			);
			if (FST::execute(fst2))
			{
				LT.Add(LT::Entry{ LEX_FUNCTION, word.line_number, LT_TI_NULLIDX });
				return true;
			}
		}
		else if (word.word[0] == 'd')
		{
			FST::FST fst(
				word.word,
				8,
				FST::NODE(1, FST::RELATION('d', 1)),
				FST::NODE(1, FST::RELATION('e', 2)),
				FST::NODE(1, FST::RELATION('c', 3)),
				FST::NODE(1, FST::RELATION('l', 4)),
				FST::NODE(1, FST::RELATION('a', 5)),
				FST::NODE(1, FST::RELATION('r', 6)),
				FST::NODE(1, FST::RELATION('e', 7)),
				FST::NODE()
			);
			if (FST::execute(fst))
			{
				LT.Add(LT::Entry{ LEX_DECLARE, word.line_number, LT_TI_NULLIDX });
				return true;
			}
		}
		else if (word.word[0] == 'r')
		{
			FST::FST fst(
				word.word,
				7,
				FST::NODE(1, FST::RELATION('r', 1)),
				FST::NODE(1, FST::RELATION('e', 2)),
				FST::NODE(1, FST::RELATION('t', 3)),
				FST::NODE(1, FST::RELATION('u', 4)),
				FST::NODE(1, FST::RELATION('r', 5)),
				FST::NODE(1, FST::RELATION('n', 6)),
				FST::NODE()
			);
			if (FST::execute(fst))
			{
				LT.Add(LT::Entry{ LEX_RETURN, word.line_number, LT_TI_NULLIDX });
				return true;
			}
		}
		else if (word.word[0] == 'p')
		{

			FST::FST fst(
				word.word,
				6,
				FST::NODE(1, FST::RELATION('p', 1)),
				FST::NODE(1, FST::RELATION('r', 2)),
				FST::NODE(1, FST::RELATION('i', 3)),
				FST::NODE(1, FST::RELATION('n', 4)),
				FST::NODE(1, FST::RELATION('t', 5)),
				FST::NODE()
			);
			if (FST::execute(fst))
			{
				LT.Add(LT::Entry{ LEX_PRINT, word.line_number, LT_TI_NULLIDX });
				return true;
			}
		}
		else if (word.word[0] == 's' || word.word[0] == 'i')
		{
			bool integer_flag = 0, string_flag = 0;

			if (word.word[0] == 's')
			{
				FST::FST fst(
					word.word,
					7,
					FST::NODE(1, FST::RELATION('s', 1)),
					FST::NODE(1, FST::RELATION('t', 2)),
					FST::NODE(1, FST::RELATION('r', 3)),
					FST::NODE(1, FST::RELATION('i', 4)),
					FST::NODE(1, FST::RELATION('n', 5)),
					FST::NODE(1, FST::RELATION('g', 6)),
					FST::NODE()
				);
				integer_flag = FST::execute(fst);
			}
			else if (word.word[0] == 'i')
			{
				FST::FST fst2(
					word.word,
					8,
					FST::NODE(1, FST::RELATION('i', 1)),
					FST::NODE(1, FST::RELATION('n', 2)),
					FST::NODE(1, FST::RELATION('t', 3)),
					FST::NODE(1, FST::RELATION('e', 4)),
					FST::NODE(1, FST::RELATION('g', 5)),
					FST::NODE(1, FST::RELATION('e', 6)),
					FST::NODE(1, FST::RELATION('r', 7)),
					FST::NODE()
				);
				string_flag = FST::execute(fst2);
			}
			if (integer_flag || string_flag)
			{
				if (integer_flag)
					LT.Add(LT::Entry{ LEX_INTEGER, word.line_number, LT_TI_NULLIDX });
				else if (string_flag)
					LT.Add(LT::Entry{ LEX_STRING, word.line_number, LT_TI_NULLIDX });
				return true;
			}
		}
		else if (word.word[0] == 'm')
		{
			FST::FST fst2(
				word.word,
				5,
				FST::NODE(1, FST::RELATION('m', 1)),
				FST::NODE(1, FST::RELATION('a', 2)),
				FST::NODE(1, FST::RELATION('i', 3)),
				FST::NODE(1, FST::RELATION('n', 4)),
				FST::NODE()
			);
			if (FST::execute(fst2)) {
				LT.Add(LT::Entry{ LEX_MAIN, word.line_number, LT_TI_NULLIDX });
				return true;
			}
		}
		else if (word.word[0] == LEX_LEFTHESIS || word.word[0] == LEX_RIGHTHESIS || word.word[0] == LEX_BRACELET || word.word[0] == LEX_LEFTBRACE || word.word[0] == LEX_COMMA || word.word[0] == LEX_SEMICOLON)
		{
			LT.Add(LT::Entry{ word.word[0], word.line_number, LT_TI_NULLIDX });
			return true;
		}
		else if (word.word[0] == '+' || word.word[0] == '-' || word.word[0] == '*' || word.word[0] == '/' || word.word[0] == '=')
		{
			LT.Add(LT::Entry{ word.word[0] == '='? '=': 'v', word.line_number, LT_TI_NULLIDX});
			return true;
		}
		else
		{
			if (word.word[0] == '\'' || ((int)word.word[0] <= 57 && (int)word.word[0] >= 48))
			{
				int test = IT.IsId(word.word);
				if (test == TI_NULLIDX)
				{
					IT.Add(IT::Entry{ unsigned int(LT.table.size() + 1), word.word, word.word[0] == '\'' ? IT::IDDATATYPE::STR : IT::IDDATATYPE::INT, IT::IDTYPE::L });
					IT::Entry IT_EN = IT.table.back();
					IT.table.pop_back();
					if (word.word[0] == '\'')
						strcpy_s(IT_EN.value.vstr.str, word.word.c_str());
					else
						IT_EN.value.vint = std::stoi(word.word);
					IT.table.push_back(IT_EN);
					std::cout << "-----------------------" << "IT_EN.value.vstr.str - " << IT_EN.value.vstr.str << "IT_EN.value.vstr.str.IT - " << IT_EN.value.vint << std::endl;
					LT.Add(LT::Entry{ (char)LEX_LITERAL, word.line_number, IT.table.size() - 1 });
				}
				else {
					IT.Add(*&IT.table[test]);
					LT.Add(LT::Entry{ (char)LEX_LITERAL, word.line_number, IT.table.size() - 1 });
				}
				return true;
			}

		}

		//надо понять какого типа идентификатор
		int test = IT.IsId(word.word);
		if (test == TI_NULLIDX)
		{
			if (LT.table[LT.table.size() - 1].lexema[0] == LEX_FUNCTION)
			{
				IT.Add(IT::Entry{ unsigned int(LT.table.size() + 1), word.word, LT.table[LT.table.size() - 2].lexema == (char*)LEX_STRING ? IT::IDDATATYPE::STR : IT::IDDATATYPE::INT, IT::IDTYPE::F });
				LT.Add(LT::Entry{ (char)LEX_ID, word.line_number, IT.table.size() - 1 });

			}
			else if (LT.table[LT.table.size() - 2].lexema[0] == LEX_LEFTHESIS || LT.table[LT.table.size() - 2].lexema[0] == LEX_COMMA)
			{
				IT.Add(IT::Entry{ unsigned int(LT.table.size() + 1), word.word, LT.table[LT.table.size() - 2].lexema == (char*)LEX_STRING ? IT::IDDATATYPE::STR : IT::IDDATATYPE::INT, IT::IDTYPE::P });
				LT.Add(LT::Entry{ (char)LEX_ID, word.line_number, IT.table.size() - 1 });
			}
			else if (LT.table[LT.table.size() - 2].lexema[0] == LEX_DECLARE)
			{
				IT.Add(IT::Entry{ unsigned int(LT.table.size() + 1), word.word, LT.table[LT.table.size() - 1].lexema == (char*)LEX_STRING ? IT::IDDATATYPE::STR : IT::IDDATATYPE::INT, IT::IDTYPE::V });
				LT.Add(LT::Entry{ (char)LEX_ID, word.line_number, IT.table.size() - 1 });
			}
			else
				throw ERROR_THROW_LEX(114, word.line_number);
		}
		else {
			IT::Entry l = IT.table[test];
			LT.Add(LT.GetEntry(l.idxfirstLE - 1));

			IT.Add(*&IT.table[test]);
		}
		return true;
	}
	IN getin(wchar_t* infile, wchar_t* outfile)
	{
		std::wifstream fin;
		std::wofstream fout;

		std::fstream file(infile);

		char char_infile[PARAM_MAX_SIZE];
		size_t i;
		wcstombs_s(&i, char_infile, (size_t)PARAM_MAX_SIZE, infile, (size_t)PARAM_MAX_SIZE);

		struct stat fi;
		int line_number = 1;
		stat(char_infile, &fi);
		std::vector<word_with_number_line> words;

		if (fi.st_size >= IN_MAX_LEN_TEXT) {
			throw ERROR_THROW(101);
		}

		fin.open(infile);
		fout.open(outfile);



		if (!fin.is_open()) {
			throw ERROR_THROW(110);
		}
		else {
			LT::LexTable LT = { 1 };
			IN in;
			in.size = 0;
			in.lines = 1;
			in.ignor = 0;
			std::string word = "";

			wchar_t letter;
			wchar_t previous = ' ';
			char utf_letter[3];
			int next = 0, test, col = 0, counter = 0;

			bool quotes = false;
			while (fin.get(letter)) {
				unsigned char un_letter = letter;

				if (letter == '\'') {
					quotes = !quotes;
				}

				if (un_letter > 0x7F) {
					if (un_letter == 208) {
						next = 48;
					}
					else if (un_letter == 209)
						next = 112;

					previous = letter;
					fin.get(letter);
					utf_letter[0] = previous;
					utf_letter[1] = letter;
					utf_letter[2] = 0;
				}

				test = in.code[int(letter) + next];

				if (test == IN::I)
					in.ignor++;

				else if (test == IN::T) {
					if (next)
						fout << utf_letter;
					else
						fout << letter;
				}

				else if (test == IN::F) {
					utf_letter[2] = 0;
					fout.close();
					fout.open(outfile);
					in.lines++;
					col++;
					if (next)
						fout << utf_letter << std::endl;
					else
						fout << letter << std::endl;
					fout << "Ошибка 111: Недопустимый символ в исходном файле (-in), строка" << in.lines << ", позиция " << col;
					throw ERROR_THROW_IN(111, in.lines, col);
				}

				else {
					if (test == '`') {
						fout << ' ' << char(test) << in.lines << std::endl;
						in.lines++;
					}
				}
				if (letter != IN_CODE_ENDL) {
					in.size++;
					col++;
				}
				else {
					col = 0;
				}


				if (letter == LEX_COMMA || letter == LEX_SEMICOLON || letter == LEX_LEFTBRACE || letter == LEX_BRACELET || letter == LEX_LEFTHESIS || letter == LEX_RIGHTHESIS || letter == '+' || letter == '-' || letter == '*' || letter == '/' || letter == '=') {
					if (word != "\n" && word != "")
						words.push_back(word_with_number_line{ word, in.lines });

					word = letter;
					if (word != "\n" && word != "")
						words.push_back(word_with_number_line{ word, in.lines });
					word = "";
				}
				else if (letter == ' ' && previous != ' ' && !quotes) {

					if (word != "\n" && word != "")
						words.push_back(word_with_number_line{ word, in.lines });
					word = "";
				}
				else {
					if (next) {
						word += utf_letter;
					}
					else
						if (letter != '\n')
							word += letter;
					next = 0;
				}
				previous = letter;
			}
			fout << " `" << in.lines << std::endl;
			/*return in;*/
		}

		for (int i = 0; i < words.size(); i++) {
			try_recognition(words[i]);
		}

		for (int i = 0; i < LT.table.size() - 1; i++) {
			int TI_index = (unsigned int)LT.table[i].idxTI == TI_NULLIDX ? -1 : LT.table[i].idxTI;
			std::cout << i + 1 << ") " << words[i].word << "-----" << LT.table[i].lexema[0] << "----- " << TI_index << "       (" << words[i].line_number << std::endl;
		}
		int line = 1;
		fout << line << ") ";
		for (int i = 0; i < LT.table.size() - 1; i++) {
			fout << LT.table[i].lexema[0];
			if (words[i + 1].line_number != line) {
				line++;
				fout << std::endl << line << ") ";
			}
		}
		fout << LT.table[LT.table.size() - 1].lexema[0];

		for (int i = 0; i < IT.table.size(); i++) {
			std::string datatype = IT.table[i].iddatatype == 1 ? " INT" : " STR";
			std::string idtype;
			if (IT.table[i].idtype == IT::IDTYPE::F) {
				idtype = " function";
			}
			else if (IT.table[i].idtype == IT::IDTYPE::V) {
				idtype = " var";
			}
			else if (IT.table[i].idtype == IT::IDTYPE::P) {
				idtype = " parametr";
			}
			else if (IT.table[i].idtype == IT::IDTYPE::L) {
				idtype = " literal";
			}

			std::cout << IT.table[i].id << datatype << idtype << " " << IT.table[i].idxfirstLE << std::endl;
		}


		MFST_TRACE_START
		MFST::Mfst mfst(LT, GRB::getGreibach());
		mfst.printrules();
		mfst.start();

		system("pause");
		LT.Delete();
		IT.Delete();
	}

};