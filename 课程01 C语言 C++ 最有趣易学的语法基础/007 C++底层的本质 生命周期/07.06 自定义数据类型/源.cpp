#include <iostream>

int main()
{
    /*
    int wheel{ 19 };
    unsigned price{ 1000000 };
    char logo{ 'B' };
    unsigned gls{ 100 };

    std::cout << "车辆商标:" << logo << " 车轮大小:" << wheel << " 车辆售价:" << price << std::endl;

    int wheelA{ 19 };
    unsigned priceA{ 1000000 };
    char logoA{ 'A' };
    unsigned glsA{ 100 };

    std::cout << "车辆商标:" << logoA << " 车轮大小:" << wheelA << " 车辆售价:" << priceA << std::endl;
    */

    // 自定义数据类型
    struct CAR
    {
        char logo{ 'A' };
        unsigned short wheel{ 19 };
        unsigned price{ 900000 };
    };
    CAR car1{ 'C',25,500000 };
    CAR car2{ 'B',34,600000 };
    CAR car3{ 'U',90,700000 };

    std::cout << "车辆C logo:" << car1.logo << " 车辆C whsize:" << car1.wheel << " 车辆C price:" << car1.price << std::endl;
    std::cout << "车辆B logo:" << car2.logo << " 车辆B whsize:" << car2.wheel << " 车辆B price:" << car2.price << std::endl;
    std::cout << "车辆U logo:" << car3.logo << " 车辆U whsize:" << car3.wheel << " 车辆U price:" << car3.price << std::endl;
}
