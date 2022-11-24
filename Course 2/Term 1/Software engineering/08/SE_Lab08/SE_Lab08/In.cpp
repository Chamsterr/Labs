#include "pch.h"
#include "In.h"
#include "Error.h"
#include "Parm.h"
#include <fstream>
#include <locale>
#include <sys/stat.h>
#include <filesystem>
#include "LT.h"

namespace In {

	IN getin(wchar_t* infile, wchar_t* outfile)
	{
		std::wifstream fin;
		std::wofstream fout;

		std::fstream file(infile);

		char char_infile[PARAM_MAX_SIZE];
		size_t i;
		wcstombs_s(&i, char_infile, (size_t)PARAM_MAX_SIZE, infile, (size_t)PARAM_MAX_SIZE);

		struct stat fi;
		stat(char_infile, &fi);
		

		if (fi.st_size >= IN_MAX_LEN_TEXT) {
			throw ERROR_THROW(101);
		}

		fin.open(infile);
		fout.open(outfile);

		

		if (!fin.is_open()) {
			throw ERROR_THROW(110);
		}
		else{
			LT::LexTable LT = { 1 }; 
			IN in;
			in.size = 0;
			in.lines = 0;
			in.ignor = 0;

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
				if (!quotes && previous == ' ' && letter == ' ')
				{
					continue;
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
					next = 0;
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
					next = 0;
					fout << "Ошибка 111: Недопустимый символ в исходном файле (-in), строка" << in.lines << ", позиция " << col;
					throw ERROR_THROW_IN(111, in.lines, col);
				}

				else {
					if (test == '`'){
						int line_number = ++in.lines;
						fout << ' ' << char(test) << line_number << std::endl;
					}
				}
				if (letter != IN_CODE_ENDL) {
					in.size++;
					col++;
				}
				else {
					col = 0;
					in.lines++;
				}
				previous = letter;
			}
			fout << " `" << in.lines << std::endl;
			fout.close();
			return in;
		}

	}
};