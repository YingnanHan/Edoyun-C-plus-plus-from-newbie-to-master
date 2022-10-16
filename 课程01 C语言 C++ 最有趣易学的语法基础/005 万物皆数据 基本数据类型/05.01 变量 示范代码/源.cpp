#include <iostream>

#define dVersion "v2.1" // 使用宏定义

int main()
{
    int year{ 2019 };
    int mon{ 10 };
    int day{ 1 };

    const int year_fix{ 2019 };

    std::cout << "易道云 时间日期显示程序" << dVersion << std::endl;
    std::cout << "今年是" << year << "年" << std::endl;
    std::cout << "这个月是" << mon << "月" << std::endl;
    std::cout << "今天是" << year << "年" << mon << "月" << day << "日" << std::endl;
}