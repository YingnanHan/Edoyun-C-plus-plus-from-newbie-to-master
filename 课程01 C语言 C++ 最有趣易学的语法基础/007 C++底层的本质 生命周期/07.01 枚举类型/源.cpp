// ö������

#include<iostream>

using namespace std;

#define Normal 0
#define High 1
#define Rare 2
#define Epic 3
#define Myth 4
#define Legend 5

int main()
{
	short weaponLv;
	weaponLv = Normal; // ��ͨװ��
	short weaponALv = Legend; // ��˵
	short weaponBlv = Myth; // ��˵
	std::cout << "���װ����Ʒ��Ϊ:" << weaponBlv;
	/*��֪ʶ*/
	enum class EquipLv : int // ö�����ͱ���Ϊ����
	{
		//  �����ָ������Ԫ����ǰ��Ԫ�صĵ���ֵ
		normal = 10, armyA = normal, // ����ƽ����������������ε���
		high, armyB = high,
		rare, armyC = normal,
		epic, armyD = epic,
		legend, armyE = legend,
		myth, armyF = myth,
	};

	EquipLv weaponCLv(EquipLv::rare);
	EquipLv weaponDLv(EquipLv::rare);

	short diff = (int)weaponCLv - (int)weaponBlv;
	std::cout << "�����Ҽ�װ���ĵȼ����Ϊ:" << diff;

	// ö�����Ͷ�����޸�
	weaponDLv = EquipLv::legend;
}