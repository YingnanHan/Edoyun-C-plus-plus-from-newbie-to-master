#include<iostream>

using namespace std;

class T;
class T1;

class T
{
	int hp;
	int mp;
	void GetHP()
	{
		std::cout << hp;
	}
	void GetMP()
	{
		std::cout << mp;
	}
	friend void SetHP(T& t1, T1& t2); // ������Ԫ����
	friend void SetMP(T& t1, T1& t2); // ������Ԫ����
	friend class T1;
};

class T1
{
	int hp;
	int mp;
	void GetHP()
	{
		T t1;
		t1.GetHP();
		std::cout << hp;
	}
	void GetMP()
	{
		std::cout << mp;
	}
	// ��Ԫ���� ���ǵ������ ���鲻Ҫʹ����Ԫ ��������һ��ƽ�ȵĹ�ϵ
	friend void SetHP(T& t1, T1& t2); // ������Ԫ����
	friend void SetMP(T& t1, T1& t2); // ������Ԫ����
};

void SetHP(T& t1, T1& t2)
{
	t1.hp = 2500;
	t1.GetHP();
}

void SetMP(T& t1, T1& t2)
{
	t1.mp = 2500;
	t1.GetMP();
}

int main()
{
	T t1;
	T1 t2;
	SetHP(t1, t2);
	return 0;
}