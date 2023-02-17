#pragma once
#include "Error.h"
#include <vector>
#include <string>

typedef short GRBALPHABET; // символы алф грамматики терминалы > 0, нетерминалы < 0
namespace GRB
{
	struct Rule //правило в грамматики Грейбах 
	{
		GRBALPHABET nn; //нетерминал (левый символ правила) < 0
		int iderror; // идентификатор диагностического сообщения
		short size; // кол-во цепочек - первых частей правила
		struct Chain
		{
			short size; // длина цепочки
			std::vector <GRBALPHABET> nt;
			Chain() { size = 0; nt = {}; };
			Chain(
				short psize, // кол-во символов в цепочке
				GRBALPHABET s, ... // символы (терминал или нетерминал)
			);
			char* getCChain(char* b);
			static GRBALPHABET T(char t) { return GRBALPHABET(t); }; // терминал
			static GRBALPHABET N(char n) { return -GRBALPHABET(n); }; // не терминал
			static bool isT(GRBALPHABET s) { return s > 0; } // терминал?
			static bool isN(GRBALPHABET s) { return !isT(s); }; // нетерминал?
			static char alphabet_to_char(GRBALPHABET s) { return isT(s) ? char(s) : char(-s); }; // GRBALPHABET-> char'
		};
		std::vector<Chain>chains; // массив цепочек - правых частей правила 
		Rule() { nn = 0x00; iderror = -1; size = 0; chains = {}; }
		Rule(
			GRBALPHABET pnn, // нетерминал (<0)
			int iderror, // идентификатор диагностического сообщения (Error)
			short psize, // кол-во цепочек - правых частей правила
			Chain c, ... // множество цепочек - правых частей правила
		);
		char* getCRule( // получить правило в виде N->цепочка (для распечатки)
			char* b,
			short nchain // номер цепочки (правой части ) в правиле
		);
		short getNextChain( // получить следующую за j подходящую цепочку, вернуть ее номер или -1
			GRBALPHABET t, // первый символ цепочки 
			Rule::Chain& pchain, // возвращаемая цепочка
			short j // номер цепочки
		);
	};

	struct Greibach // грамматика Грейбах
	{
		short size; // кол-во правил
		GRBALPHABET startN; // стартовый сивол
		GRBALPHABET stbottomT; // дно стека
		std::vector<Rule> rules; // множество правил
		Greibach() { size = 0; startN = 0; stbottomT = 0; rules = {}; };
		Greibach(
			GRBALPHABET pstartN, // стартовый символ
			GRBALPHABET pstbottomT, // дно стека
			short psize, // кол-во правил
			Rule r, ... // правила
		);
		short getRule( // получить правило, возвращается номер правила или -1
			GRBALPHABET pnn, // левый символ правила
			Rule& prule // возвраемое правило грамматики
		);
		Rule getRule(short n); // получить правило по номеру
	};
	Greibach getGreibach(); // получить грамматику
}