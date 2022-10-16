#include <iostream>

int main()
{
    int a{ 0x23f };
    int b = 1 + a << 1 & 0x00FF | 0xF;
    std::cout << std::hex << b;
}