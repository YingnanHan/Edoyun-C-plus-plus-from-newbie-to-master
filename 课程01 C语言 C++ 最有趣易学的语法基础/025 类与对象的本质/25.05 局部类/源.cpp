/*
	�����ں����ڵ����Ϊ�ֲ���
	(1) �ֲ�����붨��������
	(2) �ֲ����в�����ʹ�þ�̬��Ա����
	(3) �ֲ�����Է���ȫ�ֱ���
*/

#include<iostream>

using namespace std;

int main()
{
	class T // �ֲ��� -- ����ʹ��ȫ�ֱ������ǲ�����ʹ�þֲ�����
	{
		int hp;
		int mp;

	public:
		 
		auto GetHP()
		{
			return this->hp;
		}

		static int GetCount()
		{
			// ���Զ��徲̬�������ǲ����Զ��徲̬����
		}

	};

	T t1;

	return 0;
}