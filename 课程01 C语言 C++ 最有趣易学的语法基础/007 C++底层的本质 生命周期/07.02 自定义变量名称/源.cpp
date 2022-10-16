#include <iostream>

//  方法一
#define 整数 int // 不建议这么写
#define eLong long

int main()
{
    整数 a{ 100 };
    std::cout << typeid(a).name() << std::endl;

    // 方法二
    typedef int eInt;
    eInt b{};
    std::cout << typeid(b).name() << std::endl;

    // 方法三
    using eInt32 = int;
    eInt32 e{};
    std::cout << e << std::endl;

    typedef long long int64; // 为long long 更名
    using eInt64 = eLong long; // 使用using 构造新变量

    // 例子
    using ellong = long long;
    ellong aa{};

    using wf = unsigned int;
    wf qq{};

    typedef unsigned xxx;
}