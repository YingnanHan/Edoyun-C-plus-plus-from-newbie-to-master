#include <iostream>

namespace LGame
{
    int MP{ 1000 };
    int HP{ 1000 };
    int lv{ 1 };
    namespace LGameWeapon // Ƕ���������ռ�
    {
        int damage{ 3000 };
        namespace WeaponLv
        {
            int lv{ 0 };
        }
    }
}

// �����ռ䲻�ܷ��ں�������
// �ڲ���ͻ��������������ռ���Ե��ø������ռ�

int main()
{
    // �� ��һ�ַ�ʽ ����ʹ�����ַ�ʽ
    //using std::cout;
    //using std::cin;
    //using std::hex;

    // �� �ڶ��ַ�ʽ -- �����м�һ�����ݣ�Ϊ��ֹ��ͻ�����Ƽ�ʹ��
    using namespace std;

    cout << "����Ҫstd:" << std::endl;
    int a;
    cin >> hex >> a;// ����ʮ�����Ƶķ�ʽ����

    // �� ���������ռ��е�����
    cout << "LGame::HP:" << LGame::HP << endl;
    cout << "LGame::LGameWeapon::damage:" << LGame::LGameWeapon::damage << std::endl;
    cout << "LGame::LGameWeapon::WeaponLv::lv:" << LGame::LGameWeapon::WeaponLv::lv << std::endl;

    // �� ������ı�������ȷ��������һ�����Կ��Ǽ����������޶���
}