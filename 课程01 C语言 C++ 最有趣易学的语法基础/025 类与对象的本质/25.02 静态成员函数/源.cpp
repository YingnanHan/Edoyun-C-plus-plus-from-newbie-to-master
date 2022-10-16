#include<iostream>

using namespace std;

class T
{
private:
	// inline const static int count{}; // ������̬��Ա����
	inline static int count{};
public:
	static void Test() //const ��̬��Ա����������const 
	{
		//this->hp++; // ��̬��Ա���������Է���thisָ��
		count++; //  ��̬��Ա���������Է��ʷǾ�̬��Ա����
	}
	int hp;
	T()
	{
		count++;
	}
	int GetCount()
	{
		return count;
	}
	~T()
	{
		count--;
	}
};

// int T::count = 100; // ���� ��̬��Ա�������ڸ�������֮���ǹ����

/* static
	�� �����е����ʵ���У�������ľ�̬��Ա����
	�� ��ľ�̬��Ա������û�����ʵ��������£���Ȼ���Է���
	�� ��ľ�̬��Ա����������ȫ������ �����������൫�Ǵ洢λ��/�ڴ�ռ䲻������
*/

void test()
{
	T t1, t2, t3, t4;
}

T t5;

int main()
{
	// �� ��̬��Ա�������ڸ�������֮���ǹ���� 
	/*T t1, t2, t3, t4;
	T t5;
	t1.count++;
	std::cout << &t2.count << std::endl;
	std::cout << &t3.count << std::endl;*/

	// �� û�ж������Ҳ���Է��ʾ�̬��Ա����
	//T::count = 350; // ʹ��
	//T t1;
	//std::cout << t1.count << std::endl;

	// �� ���С
	//std::cout << sizeof(T); // static��Ա��ռ�ö���ռ�

	// �� ͳ�ƶ������
	test();
	T t1, t2, t3, t4;
	T t5;
	std::cout << t1.GetCount();

	return 0;
}