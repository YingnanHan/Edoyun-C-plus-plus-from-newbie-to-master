#include <iostream>

int main()
{
    int a{ 5000 };
    int b{ 1 };

    std::cout << "请输入您的金额:";
    std::cin >> b;

    if (b)
    {
        if (b > 0)
        {
            std::cout << "办理取款业务";
        }
        else
        {
            std::cout << "办理存款业务";
        }
    }
    else
    {
        std::cout << "捣乱\n";
        std::cout << "警察快来呀！！" << std::endl;
    }
    return 0;
}