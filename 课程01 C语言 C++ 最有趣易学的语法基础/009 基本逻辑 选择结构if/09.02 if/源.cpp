#include <iostream>

int main()
{
    int a{ 6000 };
    int b{ 100000 }; // b��true����falseȡ�����������ֵ
    if (a > b)
    {
        std::cout << "����Ǯ" << std::endl;
        std::cout << "��ʵ������Ǯ" << std::endl;
    }
    if (a == b)
    {
        std::cout << "����һ����Ǯ" << std::endl;
    }
    else
    {
        std::cout << "����Ǯ" << std::endl;
    }
    if (a <= b)
    {
        std::cout << "������޳ܵ�ƭ��" << std::endl;
    }

    std::cout << "����������ȡ����:";
    std::cin >> b;
    if (b == 0)
    {
        std::cout << "\n����" << std::endl;
    }
    if (b)
    {
        std::cout << "\n����ҵ��!";

    }
    return 0;
}