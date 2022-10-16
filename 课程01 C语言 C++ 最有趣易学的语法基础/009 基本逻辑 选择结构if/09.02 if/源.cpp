#include <iostream>

int main()
{
    int a{ 6000 };
    int b{ 100000 }; // b是true还是false取决与其自身的值
    if (a > b)
    {
        std::cout << "你有钱" << std::endl;
        std::cout << "你实在是有钱" << std::endl;
    }
    if (a == b)
    {
        std::cout << "咱俩一样有钱" << std::endl;
    }
    else
    {
        std::cout << "我有钱" << std::endl;
    }
    if (a <= b)
    {
        std::cout << "你这个无耻的骗子" << std::endl;
    }

    std::cout << "请输入您的取款金额:";
    std::cin >> b;
    if (b == 0)
    {
        std::cout << "\n捣乱" << std::endl;
    }
    if (b)
    {
        std::cout << "\n办理业务!";

    }
    return 0;
}