


#include<iostream>
#include<string>

using namespace std;

int main()
{
	// case 01
	//// ���һ�������û���������id����pass����role���԰����Ӧ��������ʾ����
	//string str{ "id=user;pass=632105;role=��Ӣ��;" };
	//string strIn;
	//string strOut;

	//while(true)
	//{
	//	std::cout << "��������Ҫ���ҵ�����:\n";
	//	std::cin >> strIn; //Ҫ������ַ��� ����
	//	int lfind = str.find(strIn + "=");
	//	if (lfind == std::string::npos)
	//	{
	//		std::cout << "�Բ��� ��Ҫ��ѯ�����Բ�����!";
	//	}
	//	else
	//	{
	//		int lend = str.find(";", lfind);
	//		strOut = str.substr(lfind + strIn.length() + 1, lend - lfind - strIn.length()-1);
	//		std::cout << strOut << std::endl;
	//	}
	//}

	// case 02 �ַ�������
	string id = "id=;";

	id.insert(3, "killertestid", 6);
	std::cout << id << std::endl;

	id.insert(3, "killertestid", 6, 6);
	std::cout << id << std::endl;

	id.insert(3, 6, '*');
	std::cout << id << std::endl;

	id.insert(3, "testid");
	std::cout << id << std::endl;

	return 0;
}
