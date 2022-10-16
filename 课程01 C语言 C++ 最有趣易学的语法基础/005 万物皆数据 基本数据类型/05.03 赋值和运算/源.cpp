#include <iostream>

int main()
{
    ////////////////////////////////////////////////
    int b{ 100 };
    int end1;
    end1 = b / 3; // 截断
    end1 /= 3; // 上面的等价写法

    int end2;
    end2 = b % 3; // 截断
    end2 %= 3; // 上面的等价写法

    std::cout << 010uL << std::endl; // 八进制下的无符号9
    std::cout << end1 << std::endl;
    std::cout << end2 << std::endl;

    ////////////////////////////////////////////////

    int d{ 100 };
    ++d;
    std::cout << d << std::endl;
    d++;
    std::cout << d << std::endl;
    int send(++d + 5); // 先递增示范
    std::cout << send << std::endl;
    send = (d++ + 5);// 后递增示范
    std::cout << send << std::endl;

    send = (--d + 5); // 先递减示范
    std::cout << send << std::endl;
    send = (d-- + 5);// 后递减示范
    std::cout << send << std::endl;
}