#include <iostream>

int main()
{
    // 默认情况下 输出数字指的是十进制数字
    std::cout << 99 << 10'250 << std::endl; // 10'250 表示10250 这样写的目的是方便西方国家查看数字
    std::cout << 0b11 << std::endl; // 前导0b表示二进制
    std::cout << 010 << std::endl; // 前导0表示八进制
    std::cout << 0x11 << std::endl; // 前导0x表示十六进制
    // 即便表示的时候是其他进制，但是在不设置的情况下，默认输出十进制数字
    return 0;
}