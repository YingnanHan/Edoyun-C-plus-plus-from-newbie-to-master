#include <iostream>

int main()
{
    unsigned int diamond{ 6000 };
    unsigned int vip_exp{ 80000 };

    unsigned xbase = diamond ^ vip_exp;

    std::cout << "�޸���ʯ����:";
    std::cin >> diamond;
    std::cout << "�޸��ۼ�����:";
    std::cin >> vip_exp;

    /*ģ��һ�μ��*/
    unsigned realDiamond = xbase ^ diamond;
    unsigned realVip_exp = xbase ^ vip_exp;

    std::cout << "��Ӧ�õ���ʯ����:" << realDiamond << "��ʵ�ʵ���ʯ:" << diamond << std::endl;;
    std::cout << "��Ӧ�õ���������:" << realVip_exp << std::endl;
}