#include <iostream>

int main()
{
    // 01 打印所有个位数字
    for (int i = 0; i < 10; i++)
    {
        std::cout << i << std::endl;
    }
    std::cout << "循环结束" << std::endl;
    std::cout << std::endl;

    // 02 打印所有的大写字母
    for (int i = 0; i < 26; i++)
    {
        std::cout << char('A' + i) << std::endl;
    }
    std::cout << "循环结束" << std::endl;
    std::cout << std::endl;

    // 03 每五个元素换行 打印字母表
    for (char a = 65; a < 91; a++)
    {
        if (!((a - 65) % 5) && (a > 65))
        {
            std::cout << std::endl;
        }
        std::cout << a << "\t";
    }

    // 04 输出某个大写字母后面的所有字母
    std::cout << std::endl;
    char charIn;
    std::cin >> charIn;

    for (char a = charIn + 1; a < 91; a++)
    {
        if (!((a - charIn - 1) % 5) && (a > charIn + 1))
        {
            std::cout << std::endl;
        }
        std::cout << a << "\t";
    }

    return 0;
}