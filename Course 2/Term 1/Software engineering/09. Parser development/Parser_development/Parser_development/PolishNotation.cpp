#include "PolishNotation.h"

namespace Polish {
	bool polishNotation(int i, LT::LexTable& LT) {// функция пер в пол нат
		std::stack<LT::Entry> stack;
		std::queue<LT::Entry> queue;

		LT::Entry aggregate_symbol;
		aggregate_symbol.idxTI = -1;
		aggregate_symbol.lexema = '#';
		aggregate_symbol.line = lex.lextable.table[i].line;

		LT::Entry function_symbol;
		function_symbol.idxTI = LT_TI_NULLIDX;
		function_symbol.lexema = '@';
		function_symbol.line = lex.lextable.table[i].line;
		int idx;

		int lexem_counter = 0;
		int parm_counter = 0;
		int lexem_position = i;
		char* buf = new char[i];

		bool is_function = false;

		for (i; lex.lextable.table[i].lexema != LEX_SEMICOLON; i++, lexem_counter++) {
			switch (lex.lextable.table[i].lexema) {
			case LEX_ID:
			case LEX_LITERAL:
				if (lex.idtable.table[lex.lextable.table[i].idxTI].idtype == IT::F) {
					is_function = true;
					idx = lex.lextable.table[i].idxTI;
				}
				else {
					if (is_function)
						parm_counter++;
					queue.push(lex.lextable.table[i]);
				}
				continue;

			case LEX_LEFTTHESIS:
				stack.push(lex.lextable.table[i]);
				continue;

			case LEX_RIGHTTHESIS:
				while (stack.top().lexema != LEX_LEFTTHESIS) {
					queue.push(stack.top());
					stack.pop();
					if (stack.empty())
						return false;
				}

				if (!is_function)
					stack.pop();
				else {
					function_symbol.idxTI = idx;
					idx = LT_TI_NULLIDX;
					lex.lextable.table[i] = function_symbol;
					queue.push(lex.lextable.table[i]);
					_itoa_s(parm_counter, buf, 2, 10);
					stack.top().lexema = buf[0];
					stack.top().idxTI = LT_TI_NULLIDX;
					stack.top().line = function_symbol.line;
					queue.push(stack.top());
					stack.pop();
					parm_counter = 0;
					is_function = false;
				}
				continue;

			case LEX_OPERATOR:
				while (!stack.empty() && lex.lextable.table[i].priority <= stack.top().priority) {
					queue.push(stack.top());
					stack.pop();
				}
				stack.push(lex.lextable.table[i]);
				continue;
			}
		}

		while (!stack.empty()) {
			if (stack.top().lexema == LEX_LEFTTHESIS || stack.top().lexema == LEX_RIGHTTHESIS)
				return false;

			queue.push(stack.top());
			stack.pop();
		}

		while (lexem_counter != 0) {
			if (!queue.empty()) {
				lex.lextable.table[lexem_position++] = queue.front();
				queue.pop();
			}
			else
				lex.lextable.table[lexem_position++] = aggregate_symbol;

			lexem_counter--;
		}

		for (int i = 0; i < lexem_position; i++) {
			if (lex.lextable.table[i].lexema == LEX_OPERATOR || lex.lextable.table[i].lexema == LEX_LITERAL)
				lex.idtable.table[lex.lextable.table[i].idxTI].idxFirstLE = i;
		}

		return true;
	}

	void startPolish(LT::LexTable& LT) {
		for (int i = 0; i < lex.lextable.size; i++) {
			if (lex.lextable.table[i].lexema == '=') {// находит - = пееводит выр в инверсию
				polishNotation(i + 1, lex);
			}
			else if (lex.lextable.table[i].lexema == LEX_ID && lex.idtable.table[lex.lextable.table[i].idxTI].iddatatype == IT::PROC &&//если процед,преобр пол инв
				lex.lextable.table[i - 1].lexema != LEX_PROCEDURE) {
				polishNotation(i, lex);
			}
		}
	}
}