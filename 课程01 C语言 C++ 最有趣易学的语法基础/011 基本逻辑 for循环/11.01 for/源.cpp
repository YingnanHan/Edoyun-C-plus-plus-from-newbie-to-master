#include <iostream>

int main()
{
    // 01 ��ӡ���и�λ����
    for (int i = 0; i < 10; i++)
    {
        std::cout << i << std::endl;
    }
    std::cout << "ѭ������" << std::endl;
    std::cout << std::endl;

    // 02 ��ӡ���еĴ�д��ĸ
    for (int i = 0; i < 26; i++)
    {
        std::cout << char('A' + i) << std::endl;
    }
    std::cout << "ѭ������" << std::endl;
    std::cout << std::endl;

    // 03 ÿ���Ԫ�ػ��� ��ӡ��ĸ��
    for (char a = 65; a < 91; a++)
    {
        if (!((a - 65) % 5) && (a > 65))
        {
            std::cout << std::endl;
        }
        std::cout << a << "\t";
    }

    // 04 ���ĳ����д��ĸ�����������ĸ
    std::cout << std::endl;
    char charIn;
    std::cin >> charIn;

    for (char a = charIn + 1; a < 91; a++)
    {
        if (!((a - charIn - 1) % 5) && (a > charIn + 1))
        {
            std::cout << std::endl;
        }
        std::cout << a << "\t";
    }

    return 0;
}