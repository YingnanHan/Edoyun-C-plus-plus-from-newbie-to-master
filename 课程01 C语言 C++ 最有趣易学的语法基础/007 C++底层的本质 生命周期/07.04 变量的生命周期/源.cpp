#include <iostream>

int a{ 100 }; // 全局变量 可以写在代码中的任何位置，但写在main后面就不可以使用

int main()
{
    int a{ 10 };
    {
        int c{ 90 };
        int a{ 30 };
        {
            char a = 'A';
            std::cout << a << std::endl;
            std::cout << "显示全局变量::a = " << ::a << std::endl; // ::表示全局变量的位置解析
        }//右括号会导致生命周期结束
        std::cout << a << std::endl;
    }
    std::cout << a << std::endl;
}