#include<iostream>

/*emplate<typename TR=int, typename T1, typename T2>
TR ave(T1 a, T2 b)
{
	return (a + b) / 2;
}*/

//template<typename TR = int, typename T1 = TR, typename T2> // Ĭ��ģ�����Ͳ���
//TR ave(T1 a, T2 b)
//{
//	return (a + b) / 2;
//}

// Ĭ��ģ����� -- ����ģ������з����͵�ģ�����
template<int max = 2000, int min = 1000, typename T>
bool ChangeHp(T& hp, T damage)
{
	hp -= damage;
	if (hp > max)
	{
		hp = max;
	}
	return hp < min;
}


int main()
{
	int hp = 2500;
	ChangeHp<2000, 1000>(hp, 100); // �в����ƶ�T���ͣ� ���ݵ�<>�ڲ��Ĳ�����Ϊģ�峣��������ʵ���Ͼ���ģ���滻
	std::cout << hp;
	return 0;
}