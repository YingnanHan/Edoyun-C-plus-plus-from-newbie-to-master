#include<iostream>
#include<Windows.h>

using namespace std;

void Hack()
{
	std::cout << "HHHHHHHHHHHHHHHHHHH" << std::endl;
}

class AIM
{
public:
	// [unknown]
	int HP; // +0x0
	virtual void Eat()
	{
		std::cout << "AIM" << std::endl;
	}

	virtual void Die()
	{
		std::cout << "AIM-DIE" << std::endl;
	}
};

class WOLF :public AIM
{
public:

	virtual void Eat()
	{
		std::cout << "WOLF_EAT" << std::endl;
	}

	virtual void Die()
	{
		std::cout << "WOLF_DIE" << std::endl;
	}

	void Sound()
	{
		std::cout << "aoaoaoaoaoaoao~~~" << std::endl;
	}
};

int main()
{
	AIM* wolf = new WOLF();
	wolf->Die();
	wolf->Eat();

	std::cout << sizeof(AIM) << std::endl;
	std::cout << wolf << " " << &wolf->HP << std::endl; // ��������ĸ��ֽ�

	unsigned* vtable = (unsigned*)wolf;
	std::cout << std::hex << "VTABLE : " << vtable[0] << std::endl;
	unsigned* func = (unsigned*)vtable[0];
	std::cout << std::hex << "eat : " << func[0] << std::endl;
	std::cout << std::hex << "eat : " << func[1] << std::endl;

	WOLF aWolf;
	aWolf.Sound();

	// �޸��麯���� -- ����WindowsAPI�޸��麯�����ɷ���Ȩ��
	DWORD old;
	VirtualProtect(func, 8, PAGE_EXECUTE_READWRITE, &old); // �޸�Ȩ��
	func[0] = (unsigned)Hack; // �޸�����
	func[1] = (unsigned)Hack; // �޸�����
	wolf->Eat();
	WOLF aWlf;
	aWlf.Sound();
	aWlf.Eat();		// ���漰��̬

	AIM* _aim = new WOLF();
	_aim->Eat();

	return 0;
}

//��������
// ��1��ͬһ����Ķ��ʵ����ָ��һ���麯����
// ��2��ͨ���޸��麯��������ݿ���ʵ�ֽٳ�
// ��3��ֻ��ͨ��ָ����ʺ����Ż�����麯����