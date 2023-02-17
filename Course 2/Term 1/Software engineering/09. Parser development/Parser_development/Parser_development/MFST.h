#pragma once
#include "GRB.h"
#include "LT.h"
#include <stack>
#include <iostream>
#include <iomanip>

static int FST_TRACE_n = -1;
static char rbuf[205], sbuf[205], lbuf[1024];

#define MFST_TRACE_START std::cout <<std::setw(4)<<std::left<<"Шаг"<<":"\
						 <<std::setw(20)<<std::left<<"Правило"\
						 <<std::setw(30)<<std::left<<"Входная лента"\
						 <<std::setw(20)<<std::left<<"Стек"\
						 <<std::endl;

#define NS(n) GRB::Rule::Chain::N(n);
#define TS(n) GRB::Rule::Chain::T(n);
#define ISNS(n) GRB::Rule::Chain::isN(n);

#define MFST_TRACE1 std::cout <<std::setw(4)<<std::left<<++FST_TRACE_n<<": "\
						 <<std::setw(20)<<std::left<< rule.getCRule(rbuf,nrulechain)\
						 <<std::setw(30)<<std::left<< getCLenta(lbuf,lenta_position)\
						 <<std::setw(20)<<std::left<< getCSt(sbuf)\
						 <<std::endl;
#define MFST_TRACE2 std::cout <<std::setw(4)<<std::left<<FST_TRACE_n<<": "\
						 <<std::setw(20)<<std::left<<" "\
						 <<std::setw(30)<<std::left<<getCLenta(lbuf,lenta_position)\
						 <<std::setw(20)<<std::left<<getCSt(sbuf)\
						 <<std::endl;
#define MFST_TRACE3 std::cout <<std::setw(4)<<std::left<<++FST_TRACE_n<<": "\
						 <<std::setw(20)<<std::left<<" "\
						 <<std::setw(30)<<std::left<<getCLenta(lbuf,lenta_position)\
						 <<std::setw(20)<<std::left<<getCSt(sbuf)\
						 <<std::endl;
#define MFST_TRACE4(c) std::cout <<std::setw(4)<<std::left<<++FST_TRACE_n<<": "<<std::setw(20)<<std::left<<c<<std::endl;
#define MFST_TRACE5(c) std::cout<<std::setw(4)<<std::left<<FST_TRACE_n<<": "<<std::setw(20)<<std::left<<c<<std::endl;
#define MFST_TRACE6(c,k) std::cout<<std::setw(4)<<std::left<<FST_TRACE_n<<": "<<std::setw(20)<<std::left<<c<<k<<std::endl;
#define MFST_TRACE7 std::cout<<std::setw(4)<<std::left<<state.lenta_position<<": "\
					<<std::setw(20)<<std::left<<rule.getCRule(rbuf,state.nrulechain)\
					<<std::endl;



#define MFST_DIAGN_MAXSIZE 2*ERROR_MAXSIZE_MESSAGE
#define MFST_DIAGN_NUMBER 3
typedef std::stack<short> MFSTSTSTACK;		///стек автомата

namespace MFST
{
	struct MfstState			// Состояние автомата (для сохранения)
	{
		short lenta_position;	// позиция на ленте
		short nrule;            // номер текущего правила
		short nrulechain;		// номер текущей цепочки, текущего правила
		MFSTSTSTACK st;			// стек автомата
		MfstState();
		MfstState(short pposition, MFSTSTSTACK pst, short pnrule, short pnrulechain);
		MfstState(
			short pposition,	// позиция на ленте
			MFSTSTSTACK pst,	// стек автомата
			short pnrulechain	// номер текущей цепочки, текущего правила
		);
	};

	struct Mfst					// Магазинный автомат
	{
		enum RC_STEP {			// код возврата функции step
			NS_OK,				// найдено правило и цепочка, цепочка записана в стек
			NS_NORULE,			// не найдено правило грамматики (ошибка в грамматике)
			NS_NORULECHAIN,		// не найдена подходящая цепочка правила (ошибка в исх. коде)
			NS_ERROR,			// неизвестный нетерминальный символ грамматики
			TS_OK,				// тек. символ ленты == вершине стека, продвинулась лента, pop стека)
			TS_NOK,				// тек. символ ленты != вершине стека, восстановлено состояние
			LENTA_END,			// тек. позиция ленты >= lenta_size
			SURPRISE			// неожиданный код возврата (ошибка в step)
		};

		struct MfstDiagnosis		// Диагностика
		{
			short lenta_position;	// позиция на ленте
			RC_STEP rc_step;		// код завершения шага
			short nrule;			// номер правила
			short nrule_chain;		// номер цепочки правила
			MfstDiagnosis();        // диагностика
			MfstDiagnosis(
				short plenta_position, // позиция на ленте
				RC_STEP prc_step,      // код завершения шага
				short pnrule,          // номер правила
				short pnrule_chain     // номер цепочки правила
			);
		}diagnosis[MFST_DIAGN_NUMBER];	// последние самые глубокие сообщения

		GRBALPHABET* lenta;		// перекодированная (TS/NS) лента (из LEX)
		short lenta_position;	// тек. позиция на ленте
		short nrule;			// номер тек. правила
		short nrulechain;		// номер тек. цепочки, тек. правила
		short lenta_size;		// размер ленты
		GRB::Greibach grebach;	// граматика Грейбах
		LT::LexTable lex;		// рез. работы лексического анализатора
		MFSTSTSTACK st;			// стек автомата
		std::stack<MfstState> storestate;	// стек для сохранения состояний
		Mfst();
		Mfst(
			LT::LexTable plex,    // результат работы лексического анализатора
			GRB::Greibach pgrebach); // грамматика Грейбах

		char* getCSt(char* buf); // получить содержимое стека
		char* getCLenta(char* buf, short pos, short n = 25);  // лента: n символов с pos
		char* getDiagnosis(short n, char* buf); // получ. n-ую строку диагностики или 0x00
		bool savestate(); // сохранить состояние автомата
		bool reststate(); // восст. состояние автомата
		bool push_chain // поместить цепочку правила в стек
		(
			GRB::Rule::Chain chain	// цепочка правила
		);
		RC_STEP step();		// выполнить шаг автомата
		bool start();		// запустить автомат
		bool savediagnosis
		(
			RC_STEP pprc_step	// код завершения шага
		);
		void printrules();	// вывести последовательность правил


		struct Deducation	// вывод
		{
			short size;				// кол-во шагов в выводе
			short* nrules;			// номера правил грамматики
			short* nrulechains;		// номера цепочек правил грамматики (nrules)
			Deducation() {
				size = 0;
				nrules = 0;
				nrulechains = 0;
			};
		}deducation;
		bool savededucation();		// сохранить дерево вывода
	};
}