#include<iostream>
#include<string>

using std::string;

int main()
{
	/*
	// Cԭ���ַ���
	char str[0x10] = "123";
	char strB[0x10] = "456";

	char strC[0x20];
	memcpy(strC, str, strlen(str));
	memcpy(strC + strlen(str), strB, strlen(strB) + 1);
	*/

	// C++�ַ���
	string str1("�����Ѳ�������Ƥ!! ass"); // ��ʼ����ʽ��
	//std::cin >> str;
	//std::cout << str;
	string str2("��ð���", 3); // ��ʼ����ʽ�� ��ĳһ��λ�ÿ�ʼ��ȡ�ַ���
	string str3("56789", 2, 3); // ��ʼ����ʽ�� ��ȡĳһ���ַ���
	string str4(str1, 0, 6); // ��ʼ����ʽ�� ��ȡĳһ���ַ���
	string str5(6, 'a'); // ��ʼ����ʽ�� �����ַ������ж��ٸ�ͬ�����ַ�

	// �ַ���������
	string str = "123" + string(" ") + "456"; // Ĭ������� ֱ�Ӷ����ַ�����Ϊ������Ĭ����const char* ���� ��������Ӧ��ʹ������һ��string��������ת�����½������ʱִ����ʽת��
	int age;
	std::cin >> age;
	string ls = "�û���������:" + std::to_string(age); // �����ת��Ϊstring��ô�ͻᰴ���ֽ�Ϊ��λ���ͳ�һ����ASCII���Ӧ���ַ�
	std::cout << ls;

	return 0;
}