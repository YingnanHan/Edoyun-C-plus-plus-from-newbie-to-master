#include <iostream>

int main()
{
    /*
    int wheel{ 19 };
    unsigned price{ 1000000 };
    char logo{ 'B' };
    unsigned gls{ 100 };

    std::cout << "�����̱�:" << logo << " ���ִ�С:" << wheel << " �����ۼ�:" << price << std::endl;

    int wheelA{ 19 };
    unsigned priceA{ 1000000 };
    char logoA{ 'A' };
    unsigned glsA{ 100 };

    std::cout << "�����̱�:" << logoA << " ���ִ�С:" << wheelA << " �����ۼ�:" << priceA << std::endl;
    */

    // �Զ�����������
    struct CAR
    {
        char logo{ 'A' };
        unsigned short wheel{ 19 };
        unsigned price{ 900000 };
    };
    CAR car1{ 'C',25,500000 };
    CAR car2{ 'B',34,600000 };
    CAR car3{ 'U',90,700000 };

    std::cout << "����C logo:" << car1.logo << " ����C whsize:" << car1.wheel << " ����C price:" << car1.price << std::endl;
    std::cout << "����B logo:" << car2.logo << " ����B whsize:" << car2.wheel << " ����B price:" << car2.price << std::endl;
    std::cout << "����U logo:" << car3.logo << " ����U whsize:" << car3.wheel << " ����U price:" << car3.price << std::endl;
}
