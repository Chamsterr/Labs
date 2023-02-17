#include <tchar.h> 
#pragma once
#define PARAM_IN L"-in:"                   // ���� ��� ����� ��������� ����
#define PARAM_OUT L"-out:"				   // ���� ��� ����� ���������� ����
#define PARAM_LOG L"-log:"				   // ���� ��� ����� �������

#define PARAM_MAX_SIZE 300                 // ������������ ����� ������ ���������
#define PARAM_OUT_DEFAULT_EXT L".out"      // ���������� ����� ���������� ���� �� ���������
#define PARAM_LOG_DEFAULT_EXT L".log"      // ���������� ����� ��������� �� ���������

namespace Parm // ��������� ������� ����������
{
	struct PARM // ������� ������
	{
		wchar_t in[PARAM_MAX_SIZE]; // -in ��� ����� ��������� ����
		wchar_t out[PARAM_MAX_SIZE]; // -out ��� ����� ����������� ����
		wchar_t log[PARAM_MAX_SIZE]; // -log ��� ����� ��������� 
	};

	PARM getparm(int argc, _TCHAR* argv[]);
};