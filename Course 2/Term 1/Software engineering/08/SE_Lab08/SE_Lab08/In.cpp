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
#include "LT.h"
#include "IT.h"
#include "FST.h"
  

namespace In 
{
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
		struct word_with_number_line 
		{
			std::string word;
			int line_number;

			word_with_number_line(std::string str, int x) 
			{
				word = str;
				line_number = x;
			}
		};
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
			std::cout << words[i].word << " " << words[i].line_number << std::endl;
		}

		for (int i = 0; i < words.size(); i++) {
			std::cout << words[i].word << std::endl;
			LT::LexTable LT(150);
			IT::IdTable IT(150);
			bool integer_flag;
			bool string_flag;

			if (words[i].word[0] == 'f') {
				FST::FST fst2(
					words[i].word,
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
					LT.Add(LT::Entry { LEX_FUNCTION, words[i].line_number });
				}

			}
			else if (words[i].word[0] == 'd')
			{
				FST::FST fst(
					words[i].word,
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
					LT.Add(LT::Entry{ LEX_DECLARE, words[i].line_number });
				}
			}
			else if (words[i].word[0] == 'r')
			{
				FST::FST fst(
					words[i].word,
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
					LT.Add(LT::Entry{ LEX_RETURN, words[i].line_number });
				}
			}
			else if (words[i].word[0] == 'p')
			{

				FST::FST fst(
					words[i].word,
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
					LT.Add(LT::Entry{ LEX_PRINT, words[i].line_number });
				}
			}

			else if (words[i].word[0] == 's' || words[i].word[0] == 'i')
			{

				FST::FST fst(
					words[i].word,
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

				FST::FST fst2(
					words[i].word,
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
				bool string_flag = FST::execute(fst2);

				if (integer_flag || string_flag)
				{
					if (integer_flag)
						LT.Add(LT::Entry{ LEX_INTEGER, words[i].line_number });
					if (string_flag)
						LT.Add(LT::Entry{ LEX_STRING, words[i].line_number });
				}
			}

			else
			{
				LT.Add(LT::Entry{ LEX_ID, words[i].line_number });
				IT.Add(IT::Entry{ LT.table.size(), words[i].word.c_str(), 2, 1});
					std::cout << " ---------------------------------" << words[i].word.c_str() << std::endl;
			}
			//for (int i = 0; i < LT.table.size(); i++) {
			//	std::cout << " -----" << LT.table[i].lexema << std::endl;
			//}
			//for (int i = 0; i < IT.table.size(); i++) {
			//	std::cout << " ---------------------------------" << IT.table[i].id << std::endl;
			//}
		}

	}

};