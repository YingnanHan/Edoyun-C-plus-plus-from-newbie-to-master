#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

typedef struct Role
{
	string ID;
	int Exp;
}*PROLE;

int main()
{
	string strData = "id=Tomy Clare;exp=9523;id=Sunny;exp=9523;id=DyBaby;exp=25301;id=Simple;exp=25301;id=Simple;exp=25301;id=Bkacs11;exp=2100;id=DumpX;exp=36520;";

	int istart{}, iend{}, icount{};
	// �ȼ����ж��ٸ��û�
	for (int i = 0; i < strData.length(); i++)
	{
		if (strData[i] == ';')
		{
			icount += 1;
			i += 3; // �ҵ���һ������ �������߼��޹ص�����
		}
	}

	PROLE pRole = new Role[icount / 2];
	icount = 0;

	do
	{
		istart = strData.find("id=", istart);
		if (istart == std::string::npos)
		{
			break;
		}
		iend = strData.find(";", istart + 3);
		pRole[icount].ID = strData.substr(istart + 3, iend - istart - 3);
		istart = iend + 1;
		istart = strData.find("exp=", istart);
		iend = strData.find(";", istart + 4);
		pRole[icount++].Exp = std::stoi(strData.substr(istart + 4, iend - istart - 4));
		istart = iend + 1;
	} while (true);

	for (int i = 0; i < icount; i++)
	{
		std::cout << setw(10) << pRole[i].ID << "\t" << "\t" << "\t" << pRole[i].Exp << std::endl;
	}
	cout << "---------------------------------------" << endl;
	// ����������
	for (int i = 1; i < icount; i++)
	{
		for (int y = 1; y < icount; y++)
		{
			if (pRole[y].Exp > pRole[y - 1].Exp)
			{
				Role tmp = pRole[y - 1];
				pRole[y - 1] = pRole[y];
				pRole[y] = tmp;
			}
		}
	}

	for (int i = 0; i < icount; i++)
	{
		std::cout << setw(10) << pRole[i].ID << "\t" << "\t" << "\t" << pRole[i].Exp << std::endl;
	}
}