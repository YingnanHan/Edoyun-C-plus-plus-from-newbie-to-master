#include<iostream>

void Add(int&& a)
{
	std::cout << a;
}

struct Role
{
	int hp;
	int mp;
};

Role CreateMonster()
{
	Role rt{ 100, 200 };
	return rt;
}

void Show(Role &&r1) // ��ʱ��һ����ʱ����r1��Ȼ����ɾ��,����������ȷʵ�˷ѿռ�
{
	std::cout << r1.hp << " " << r1.mp << std::endl;
}

int main()
{
	/*����01*/

	//int c = 232 + 11; // ��ֵ c�洢��ջ�ռ���
	//int& d = c; // ��ֵ����
	//int&& e = 320; // ��ֵ���� ��ֵ�����޷�д��ֵ
	////Add(100 + 111); //��������ֵ ���ֵ����ʱ�洢�ڼĴ������� ��������������ֵ���� һ�������һЩ��������Դ˽����Ż�
	//int a[10];
	//// *(a + 1) = 100; //��ֵ
	//e = 1500;
	//int x = c + 320 + 250;
	//Add(static_cast<int&&>(x));
	//Add(c + 320 + 250); // ��ֵ���õ��ŵ�֮һ�ǿ��Խ�ʡһ����ʱ����

	/*����02*/
	Show(CreateMonster());
}