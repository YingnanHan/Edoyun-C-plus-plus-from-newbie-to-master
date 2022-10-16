#include<iostream>

using namespace std;

class MoveObject
{
public:
	int x;
	int y;

	void virtual move() // ��б�Ϸ���
	{
		x++;
		y++;
	}
};

class NPCObject : public MoveObject
{
public:
	void virtual move() override // ��б�Ϸ��� ��������������麯�����д��override�ؼ���������
	{
		x++;
		y++;
		std::cout << "I'm NPC" << std::endl;
	}
};

class MonsterObject final : public NPCObject
{
public:
	void virtual move() override
	{
		x++;
		y++;
		std::cout << "I'm Monster" << std::endl;
	}
};

// 01 ��ʽ�������ʵ�д��
//void Move(MonsterObject* obj)
//{
//	obj->move();
//}
//
//void Move(NPCObject* obj)
//{
//	obj->move();
//}

// 02 ʹ�ö�̬
void Move(MoveObject* obj) //�������ʹ�����û���ָ��
{
	obj->move();
}

class SNPObject : public MoveObject
{
public:
	void virtual move() override
	{
		x++;
		y++;
		std::cout << "";
		return; //0��ʾ��ָ��
	}
};

int main()
{
	MonsterObject anaconda;
	NPCObject     npc;

	Move(&anaconda);		// ��̬��
	Move(&npc);				// ��̬��

	return 0;
}

/* �����麯���Ľ�˵
	1. virtualֻ��д������ڲ��������߶��壬���ܰ�virtualд�����ⲿ�Ķ��嵱��
	2. ������Ķ������޷�ʹ���麯���ģ�����ʹ�û���ָ����ʵ���麯���ĵ���
	3. �麯����������ͻ����б���ӵ����ͬ�ĺ��������Լ������б�
	4. �麯����������ͻ����з���ֵҪ�����һ��[���ǵ�����ֵ����Ϊָ�������ʱ����->Э�������¿��Ա��� (����ֵ���봦��ͬһ�̳й�ϵ�м�)]
	5. �麯�������Ǻ���ģ��
*/
