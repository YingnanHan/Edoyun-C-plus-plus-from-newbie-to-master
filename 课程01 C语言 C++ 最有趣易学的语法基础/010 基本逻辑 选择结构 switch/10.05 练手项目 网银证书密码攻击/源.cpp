#include <iostream>
#include<conio.h>

int main()
{
    int password;
    int repassword;
input:
    std::cout << "请输入一个6位数字的密码:";
    std::cin >> password;
    std::cout << std::endl << "请再输入一次:";
    std::cin >> repassword;

    if (password == repassword)
    {
        if (password > 999999)
        {
            goto input;
        }
        system("cls");
        std::cout << "密码设置成功!\n按下任意键进入破解系统";
        _getch();

        int testPass{};
    lhack:
        if (testPass != password)
        {
            testPass++;
            goto lhack;
        }
        else
        {
            std::cout << "密码破解成功" << testPass;
        }
    }
    else
    {
        goto input;
    }
}