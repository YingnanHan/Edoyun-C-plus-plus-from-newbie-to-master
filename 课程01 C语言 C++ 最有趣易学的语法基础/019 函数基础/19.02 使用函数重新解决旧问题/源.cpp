// class 14.07.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ������
//

// class 14.07.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ������
//

#include<iostream>
#include<string>

using std::string;


typedef struct Role
{

	string Id;
	int Exp;

}*PROLE;


// ��ȡ���ݳ���(�����ַ���)
int GetDataCount(string str)
{
	int icount{};
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ';')
		{
			icount++;
			i += 3;
		}
	}

	return icount / 2;
}


string GetDataStr(string str, int istart)
{
	string strReturn{};
	int iend{};
	istart = str.find("id=", istart);
	if (istart == std::string::npos)  return strReturn;
	iend = str.find(";", istart + 3);
	strReturn = str.substr(istart + 3, iend - istart - 3);
	return strReturn;
}

int main()
{
	string strData = "id=Tomy Clare;exp=9523;act=250;id=Sunny;exp=9523;id=DyBaby;exp=25301;id=Simple;exp=25301;id=Simple;exp=25301;id=Bkacs11;exp=2100;id=DumpX;exp=36520;";

	int istart{}, iend{}, icount{ GetDataCount(strData) };


	std::cout << GetDataStr(strData,0);

	return 0;
}