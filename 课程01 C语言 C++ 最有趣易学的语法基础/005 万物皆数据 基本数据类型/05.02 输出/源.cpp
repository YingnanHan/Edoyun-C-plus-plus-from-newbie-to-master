#include <iostream>

int main()
{
    // ���빤�� �������������ʾ����
    unsigned short salary;
    unsigned short bonus;
    unsigned short total;

    std::cout << "��������Ĺ���:";
    std::cin >> salary;
    std::cout << "��Ĺ�����:" << salary << "�����Ҳ���Ů���ѵ�ˮƽ��\n��������Ľ���:";
    std::cin >> bonus;
    std::cout << "��Ľ�����:" << bonus;
    total = salary + bonus;
    std::cout << "\n��������ܶ���:" << total;
    return 0;

}