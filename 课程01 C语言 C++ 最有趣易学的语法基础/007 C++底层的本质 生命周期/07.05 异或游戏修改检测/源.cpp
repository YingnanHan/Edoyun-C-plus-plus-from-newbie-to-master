#include <iostream>

int main()
{
    unsigned int diamond{ 6000 };
    unsigned int vip_exp{ 80000 };

    unsigned xbase = diamond ^ vip_exp;

    std::cout << "修改钻石数量:";
    std::cin >> diamond;
    std::cout << "修改累计消费:";
    std::cin >> vip_exp;

    /*模拟一次检测*/
    unsigned realDiamond = xbase ^ diamond;
    unsigned realVip_exp = xbase ^ vip_exp;

    std::cout << "你应该的钻石量是:" << realDiamond << "你实际的钻石:" << diamond << std::endl;;
    std::cout << "你应该的消费量是:" << realVip_exp << std::endl;
}