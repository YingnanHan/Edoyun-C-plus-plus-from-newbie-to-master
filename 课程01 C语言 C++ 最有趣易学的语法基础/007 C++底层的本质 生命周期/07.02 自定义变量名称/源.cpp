#include <iostream>

//  ����һ
#define ���� int // ��������ôд
#define eLong long

int main()
{
    ���� a{ 100 };
    std::cout << typeid(a).name() << std::endl;

    // ������
    typedef int eInt;
    eInt b{};
    std::cout << typeid(b).name() << std::endl;

    // ������
    using eInt32 = int;
    eInt32 e{};
    std::cout << e << std::endl;

    typedef long long int64; // Ϊlong long ����
    using eInt64 = eLong long; // ʹ��using �����±���

    // ����
    using ellong = long long;
    ellong aa{};

    using wf = unsigned int;
    wf qq{};

    typedef unsigned xxx;
}