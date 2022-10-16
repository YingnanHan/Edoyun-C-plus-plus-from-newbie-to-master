#include <iostream>

int main()
{
    char a;
linput:
    printf("请您输入一个大写字母，我们给您转换一个小写字母:");
    std::cin >> a;
    if (a > 64 && a < 91)
    {
        a += 32;
        std::cout << a << std::endl;
        goto linput;
    }
    else
    {
        printf("您输入的内容不符合我们的要求，请重新输入：");
        goto linput;
    }
    return 0;
}
