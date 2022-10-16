#include <iostream>

namespace LGame
{
    int MP{ 1000 };
    int HP{ 1000 };
    int lv{ 1 };
    namespace LGameWeapon // 嵌套名命名空间
    {
        int damage{ 3000 };
        namespace WeaponLv
        {
            int lv{ 0 };
        }
    }
}

// 命名空间不能放在函数体内
// 在不冲突的情况下子命名空间可以调用父命名空间

int main()
{
    // ① 第一种方式 优先使用这种方式
    //using std::cout;
    //using std::cin;
    //using std::hex;

    // ② 第二种方式 -- 但是切记一劳永逸，为防止冲突，不推荐使用
    using namespace std;

    cout << "不需要std:" << std::endl;
    int a;
    cin >> hex >> a;// 按照十六进制的范式输入

    // ③ 访问命名空间中的内容
    cout << "LGame::HP:" << LGame::HP << endl;
    cout << "LGame::LGameWeapon::damage:" << LGame::LGameWeapon::damage << std::endl;
    cout << "LGame::LGameWeapon::WeaponLv::lv:" << LGame::LGameWeapon::WeaponLv::lv << std::endl;

    // ④ 如果担心编译器不确定调用哪一个可以考虑加上作用域限定符
}