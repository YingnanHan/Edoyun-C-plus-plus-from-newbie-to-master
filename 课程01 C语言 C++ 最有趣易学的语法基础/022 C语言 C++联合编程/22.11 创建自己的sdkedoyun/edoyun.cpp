#include<iostream>
#include"edoyun.h"

#define VERSION "1.0"

int ave(int a, int b)
{
	return a * b / 2;
}

namespace edoyun
{
	const char* GetVersion()
	{
		const char* str = VERSION;
		return str;
	}
}

// �� ���� ���� -> �������� -> ��̬��
// �� д�����֮���ڽ���������Ҽ��������
// �� �ڹ���Ŀ¼��Debug�ļ������ҵ� 22.11 �����Լ���sdkedoyun.lib
// �� �½��ļ���edoyun, 22.11 �����Լ���sdkedoyun.lib �����ƶ���ȥ
// �� ��edoyun.h�ƶ�����Ӧ���ļ����У�����ļ�����SDK�Ķ�Ӧ��"˵����"