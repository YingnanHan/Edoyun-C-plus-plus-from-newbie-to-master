// 枚举类型

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
	weaponLv = Normal; // 普通装备
	short weaponALv = Legend; // 传说
	short weaponBlv = Myth; // 传说
	std::cout << "这件装备的品质为:" << weaponBlv;
	/*新知识*/
	enum class EquipLv : int // 枚举类型必须为整型
	{
		//  如果不指定后面元素是前面元素的递增值
		normal = 10, armyA = normal, // 设置平级别变量，后续依次递增
		high, armyB = high,
		rare, armyC = normal,
		epic, armyD = epic,
		legend, armyE = legend,
		myth, armyF = myth,
	};

	EquipLv weaponCLv(EquipLv::rare);
	EquipLv weaponDLv(EquipLv::rare);

	short diff = (int)weaponCLv - (int)weaponBlv;
	std::cout << "这两家件装备的等级差距为:" << diff;

	// 枚举类型对象的修改
	weaponDLv = EquipLv::legend;
}