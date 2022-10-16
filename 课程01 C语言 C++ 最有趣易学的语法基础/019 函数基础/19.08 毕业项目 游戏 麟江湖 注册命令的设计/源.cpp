#include<iostream>

// �������������������ִ��
// ִ�з�ʽ C:\Users\20613\Desktop\�׵��� C++ ȫջ ����\�γ�01 C���� C++ ����Ȥ��ѧ���﷨����\019 ��������\19.08 ��ҵ��Ŀ ��Ϸ �뽭�� ע����������\x64\Debug
// Ŀ¼��ִ�� linReg ���ϲ��� <id:xxx pass:yyy country:zzz> xxx yyy zzz�����������޸�

char* ReadRef(const char* ref, const char* cmds)
{
	//pass:
	//id:xxxxx pass xxxxx
	for (int i = 0; cmds[i]; i++)
	{
		if (cmds[i] == ref[0])
		{
			bool bfind = true;
			int x;
			for (x = 0; ref[x]; x++)
			{
				if (ref[x] != cmds[i + x])
				{
					bfind = false;
					break;
				}
			}
			if (bfind)
			{
				return (char*)&cmds[i + x];
			}
		}
	}
	return nullptr;
}

int main(int count,char* arc[])
{
	char* id{}, * pass{}, * country{};
	const char* iRef{ "id:" };
	const char* passRef{ "pass:" };
	const char* countryRef{ "country:" };

	for (int i = 1; arc[i]; i++)
	{
		if (id == nullptr)
		{
			id = ReadRef(iRef, arc[i]);
			if (id != nullptr)
			{
				continue;
			}
		}
		if (pass == nullptr)
		{
			pass = ReadRef(passRef, arc[i]);
			if (pass != nullptr)
			{
				continue;
			}
		}
		if (country == nullptr)
		{
			country = ReadRef(countryRef, arc[i]);
			if (country != nullptr)
			{
				continue;
			}
		}
	}

	if ((int)id * (int)pass * (int)country)
	{
		std::cout << "�˺ţ�" << id;
		std::cout << "���룺" << pass;
		std::cout << "���ң�" << country;
	}
	else
	{
		std::cout << "��ʹ������ķ�ʽ������ĳ���";
	}
}