#include<iostream>
#include<string>

using namespace std;

int main()
{
	// case 01
	//string str1{ "12345" };
	//std::cout << str1[0] << endl;
	//// �ַ�������ʹ���±���ȡ�����е�����
	//// ����string��һ�����󣬲��Ҹ����ڲ����ַ�������
	//// ���� (int)&str1 != (int)&str1[0]
	//std::cout << (int)&str1 << " " << (int)&str1[0] << std::endl;

	//str1 = str1 + "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	//std::cout << (int)&str1 << " " << (int)&str1[0] << std::endl;

	//// ͨ������ĶԱ� ���Է��� string�����һ���������ڴ��ַ���ᷢ���仯
	//// ���е����ݾ����Ǵ��ںδ��ɲ���ϵͳȷ�������ַ����ĳ��ȷ�������仯
	//// ��ʱ��ԭ������ַ����Ŀռ䱻�ͷţ����ҿ���һ���µĿռ���д洢��
	//// �¹�����ַ���ԭ�����ַ��������ж����str����ָ���λ�÷����仯����
	//// ������û������ַ������κθĶ�



	// case 02 ʹ��c_str()�������ַ���ʵ�ʴ�ŵĵ�ַ
	//string str{ "12345" };
	//std::cout << str[0] << std::endl;

	//std::cout << (int)&str << " " << (int)&str[0] << " "<<(int)&str[1] << std::endl;
	//str = str + "655555555555535";
	//std::cout << (int)&str << " " << (int)&str[0] << " " << (int)&str[1] << std::endl;
	//
	//const char* baseStr = str.c_str(); //����ʵ�ʵ�string�ַ���
	//std::cout << (int)&str << " " << (int)&str[0] << " " << (int)&str[1] << " " << int(baseStr) << std::endl;
	//// c_str() ����C����ַ����� ���Ƿ���������const���Բ������޸� ����const_cast����ǿ���޸�



	// case 03 ʹ��data()�������ַ���ʵ�ʴ�ŵĵ�ַ���ҵõ�һ�������޸ĵ��ַ��� char���͵�ָ��  C++ 17

	//string str{ "12345" };
	//std::cout << str[0] << std::endl;

	//std::cout << (int)&str << " " << (int)&str[0] << " "<<(int)&str[1] << std::endl;
	//str = str + "655555555555535";
	//std::cout << (int)&str << " " << (int)&str[0] << " " << (int)&str[1] << std::endl;
	//
	//char* baseStr = str.data(); //����ʵ�ʵ�string�ַ���
	//std::cout << (int)&str << " " << (int)&str[0] << " " << (int)&str[1] << " " << int(baseStr) << std::endl;



	// case 04
	// C++11֮�� �ַ�����ĩβҲ�������'\0'



	// case 05 replace() �滻����
	/*string stdID{ "id=user" };
	stdID.replace(3, 4, 6, '*');
	std::cout << stdID << std::endl;
	stdID.replace(3, 4, "����");
	std::cout << stdID << std::endl;
	stdID.replace(3, 4, "zhangsanpkq", 3, 4);
	std::cout << stdID << std::endl;*/

	// case 06 ���뺯�� insert
	// case 07 �������� erase

	// �÷�ͬ��

	return 0;
}