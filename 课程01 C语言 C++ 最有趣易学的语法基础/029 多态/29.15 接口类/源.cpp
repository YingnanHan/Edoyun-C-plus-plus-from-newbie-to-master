#include<iostream>

using namespace std;

class Animal // ӵ��һ�����麯���������������
{
protected:
	Animal() //���齫�������Ĺ��캯������Ϊprotected
	{

	}

public:
	// �����Թ��캯������ ���һ����ֻ�����˺�������û��ʵ�֣���ô���������ӿ���
	void virtual Move() = 0; // ���麯��
	void virtual Fly() = 0; // ���麯��
};

class Dog : public Animal
{
	void virtual Move()
	{

	}
	// ������ಢû��ʵ�ָ�����������ݣ���ô���ͻ���һ������
};

class Cat :public Animal
{
	void virtual Move()
	{

	}
};



int main()
{
	// Animal ani; // �����಻���Զ������ �Լ�����ʵ��
	// Animal* cat = new Cat();

	return 0;
}