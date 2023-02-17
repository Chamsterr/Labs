#include "Error.h"
#include <math.h>
namespace Error
{
	// ����� ������: 0 - 99 ��������� ������
	//               100 - 109 - ������ ����������
	//               110 - 119 - ������� �������� � ������ ������
	ERROR errors[ERROR_MAX_ENTRY] = // ������� ������
	{
		ERROR_ENTRY(0, "������������ ��� ������"),
		ERROR_ENTRY(1, "��������� ����"), 
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),

		ERROR_ENTRY_NODEF(10), ERROR_ENTRY_NODEF(20), ERROR_ENTRY_NODEF(30), ERROR_ENTRY_NODEF(40), ERROR_ENTRY_NODEF(50),
		ERROR_ENTRY_NODEF(60), ERROR_ENTRY_NODEF(70), ERROR_ENTRY_NODEF(80), ERROR_ENTRY_NODEF(90),

		ERROR_ENTRY(100, "�������� -in ������ ���� �����"),
		ERROR_ENTRY(101, "�������� ������ ��������� �����"), ERROR_ENTRY_NODEF(102), ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104, "��������� ����� �������� ���������"),
		ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107),
		ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY(110, "������ ��� �������� ����� � �������� ����� (-in)"),
		ERROR_ENTRY(111, "������������ ������ � �������� ����� (-in)"),
		ERROR_ENTRY(112, "������������ ������ � �������� ����� (-log)"),
		ERROR_ENTRY(113, "������������ ������ � �������� ����� (-out)"),

		ERROR_ENTRY(114, "������� �� ���������"), ERROR_ENTRY_NODEF(115),
		ERROR_ENTRY_NODEF(116), ERROR_ENTRY_NODEF(117), ERROR_ENTRY_NODEF(118), ERROR_ENTRY_NODEF(119), 
		ERROR_ENTRY_NODEF(120), ERROR_ENTRY_NODEF(130), ERROR_ENTRY_NODEF(140), ERROR_ENTRY_NODEF(150),
		ERROR_ENTRY_NODEF(160), ERROR_ENTRY_NODEF(170), ERROR_ENTRY_NODEF(180), ERROR_ENTRY_NODEF(190),
		ERROR_ENTRY_NODEF(200), ERROR_ENTRY_NODEF(300), ERROR_ENTRY_NODEF(400), ERROR_ENTRY_NODEF(500),
		ERROR_ENTRY_NODEF(600), ERROR_ENTRY_NODEF(700), ERROR_ENTRY_NODEF(800), ERROR_ENTRY_NODEF(900)
	};

	ERROR geterror(int id) {
		ERROR error;
		if (id < ERROR_MAX_ENTRY && id > 0)
		{
			ERROR error;
			int i = 1;
			error = errors[0];
			do
			{
				error = errors[i];
				i++;
				if (i == ERROR_MAX_ENTRY) {
					error = ERROR_ENTRY_NODEF(id);
					return error;
				}
			} while (error.id != id);
			return error;
		}
		else
			return errors[0];
	}

	ERROR geterrorin(int id, int line) {
		ERROR error;
		if (id < ERROR_MAX_ENTRY && id > 0)
		{
			ERROR error;
			int i = 1;
			error = errors[0];
			do
			{
				error = errors[i];
				i++;
			} while (abs(error.id) != id);
			error.inext.line = line;
			return error;
		}
		else
			return errors[0];
	}
	ERROR geterrorin(int id, int line = -1, int col = -1) { 
		ERROR error;
		if (id < ERROR_MAX_ENTRY && id > 0)
		{
			ERROR error;
			int i = 1;
			error = errors[0];
			do
			{
				error = errors[i];
				i++;
			} while (abs(error.id) != id);
			error.inext.line = line;
			error.inext.col = col;
			return error;
		}
		else
			return errors[0];
	}

};