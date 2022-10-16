#include <iostream>

using namespace std;

int main()
{

    // 案例一
    /*int a, b, c;
    cout << "请输入一个整数:";
    cin >> a;
    cout << "请输入一个整数:";
    cin >> b;*/


    //// 写法一
    //if (a > b)
    //{
    //    c = a;
    //}
    //else
    //{
    //    c = b;
    //}
    //std::cout << "比较大的数字为:" << c << std::endl;


    //// 写法二
    //std::cout << "比较大的数字为:" << (a > b ? a : b) << std::endl;


    // 案例二
    int cs;
    std::cout << "请输入一个数，我们将为您计算这个10000除以这个数字以后的结果:" << std::endl;
    std::cin >> cs;
    int end;
    end = cs ? (10000 / cs) : 0; // 由于cs是假的所以:前面的表达式不会被执行
    std::cout << end;

    // 技巧 在&&运算符并列的时候 简单的内容应该写在前面 这样在汇编的时候会节约时间

    return 0;
}
