#include<iostream>

using namespace std;

class Animal
{
public:
	int Age;
};

class Human : public Animal
{
public:
	int Money;
	void doit()
	{
		std::cout << "do it " << std::endl;
	}
};

int main()
{
	// test 01

	//Human MrWang{};
	//MrWang.Age = 350;
	//MrWang.Money = 520;
	//Animal animal = MrWang; // �ڴ���Ƭ��ʼ�� �����漰�������Ļ�����������д
	//std::cout << animal.Age << std::endl; // ����ת��


	// test 02

	Human MrWang{};
	MrWang.Age = 350;
	MrWang.Money = 520;
	// ����ת��
	Animal *animal = &MrWang; // ʵ����Ӧ��ʹ��ָ���������������ת��
	std::cout << animal->Age << std::endl; 
	// ����ת��
	Human* human = (Human*)animal; //ǿ���Ե�����ת�ͣ�����ҪĿ���ǵ���animal����ĺ���
	human->doit(); // ���doit()���溬�з����������еĶ�������ô���Ƽ�ʹ��



	return 0;
}