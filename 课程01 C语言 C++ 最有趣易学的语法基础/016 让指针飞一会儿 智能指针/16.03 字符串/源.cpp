#include<iostream>
#include<locale>

using namespace std;

int main()
{
	char str[0xFF]{ "Hello" }; // char �����ַ�ÿһ��Ϊһ���ֽ�
	const char* strA = "Hello ����"; // char������GBK�����Ӧ�������������ֽ�
	const char* strB = new char[0xff] { "Hello" };

	std::cout << strA; //һ����ַ������
	cout << endl;

	wchar_t wstr[0xFF]{ L"Hello ����" }; // L��ʾ���ǿ��ֽڵĳ��� ÿһ���ַ�ռ�������ֽ�
	const wchar_t* wstr1 = L"Hello ����";
	// std::cout << wstr1; //һ����ַ��������wchar��������
	setlocale(LC_ALL, "chs");// �趨����̨������ӡ���ַ�����(����Unicode�������ӳ��) ��������������򲻻��ӡ��Ӧ������
	std::wcout << wstr1; // ʹ��wcoutר�����wchar�����ַ���
	// std::cout << wstr1; //��ôЩ��ֱ�ӵ���������ֽ��ַ����ڵײ�洢��ʮ��������
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		cout << short(wstr[i]) << endl;
	}
}