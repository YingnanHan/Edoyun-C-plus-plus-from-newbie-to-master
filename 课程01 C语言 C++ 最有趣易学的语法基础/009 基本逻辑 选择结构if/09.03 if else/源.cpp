#include <iostream>

int main()
{
    int a{ 5000 };
    int b{ 1 };

    std::cout << "���������Ľ��:";
    std::cin >> b;

    if (b)
    {
        if (b > 0)
        {
            std::cout << "����ȡ��ҵ��";
        }
        else
        {
            std::cout << "������ҵ��";
        }
    }
    else
    {
        std::cout << "����\n";
        std::cout << "�������ѽ����" << std::endl;
    }
    return 0;
}