#include<iostream>

// �����ɫ��Ϣ�ṹ��
typedef struct Role
{
	char* Name;
	int Hp;
	int MaxHp;
	int Mp;
	int maxMp;
	int lv;
}*PROLE, ROLE;

// �����ַ��������ĳ��Ȳ�����
int clen(const char* str)
{
	int i;
	for (i = 0; str[i]; i++)
	{

	}
	return ++i;
}

// �ڶѿռ��Ͽ����ַ���������
char* cstr(const char* str)
{
	int len = clen(str); // �����ַ����ĳ���
	char* strRt = new char[len]; // �����ַ����ĳ���������heap�Ϸ����ڴ�ռ�
	memcpy(strRt, str, len); // ���ַ������¿���������
	return strRt; // �����������ɵ��ַ���
}

// ���崴����ɫ�ĺ���
PROLE CreateMonster(const char* str, int Hp, int Mp)
{
	PROLE rt = new ROLE{ cstr(str), Hp, Hp, Mp, Mp, 1 };
	return rt;
}

ROLE& CreateMonster_(const char* str, int Hp, int Mp)
{
	PROLE rt = new ROLE{ cstr(str), Hp, Hp, Mp, Mp, 1 };
	return *rt;
}

int main()
{
	// ʹ��ָ��Ĵ��ݷ�ֹ���ܵ�����
	PROLE role = CreateMonster("ultraman",1500, 1500);

	std::cout << role->Name << std::endl;
	std::cout << role->Hp << "/" << role->MaxHp;


	ROLE& role1 = CreateMonster_("ultraman", 1500, 1500);

	std::cout << role1.Name << std::endl;
	std::cout << role1.Hp << "/" << role1.MaxHp;
	return 0;
}