#include <iostream>

#define dVersion "v2.1" // ʹ�ú궨��

int main()
{
    int year{ 2019 };
    int mon{ 10 };
    int day{ 1 };

    const int year_fix{ 2019 };

    std::cout << "�׵��� ʱ��������ʾ����" << dVersion << std::endl;
    std::cout << "������" << year << "��" << std::endl;
    std::cout << "�������" << mon << "��" << std::endl;
    std::cout << "������" << year << "��" << mon << "��" << day << "��" << std::endl;
}