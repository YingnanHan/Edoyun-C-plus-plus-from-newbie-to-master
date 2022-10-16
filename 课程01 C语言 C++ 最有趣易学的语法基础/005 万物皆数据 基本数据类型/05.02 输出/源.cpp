#include <iostream>

int main()
{
    // 输入工资 把输入的内容显示出来
    unsigned short salary;
    unsigned short bonus;
    unsigned short total;

    std::cout << "请输入你的工资:";
    std::cin >> salary;
    std::cout << "你的工资是:" << salary << "属于找不到女朋友的水平，\n请输入你的奖金:";
    std::cin >> bonus;
    std::cout << "你的奖金是:" << bonus;
    total = salary + bonus;
    std::cout << "\n你的收入总额是:" << total;
    return 0;

}