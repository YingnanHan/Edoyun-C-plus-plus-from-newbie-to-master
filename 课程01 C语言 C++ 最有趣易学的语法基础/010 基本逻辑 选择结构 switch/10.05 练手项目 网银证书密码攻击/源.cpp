#include <iostream>
#include<conio.h>

int main()
{
    int password;
    int repassword;
input:
    std::cout << "������һ��6λ���ֵ�����:";
    std::cin >> password;
    std::cout << std::endl << "��������һ��:";
    std::cin >> repassword;

    if (password == repassword)
    {
        if (password > 999999)
        {
            goto input;
        }
        system("cls");
        std::cout << "�������óɹ�!\n��������������ƽ�ϵͳ";
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
            std::cout << "�����ƽ�ɹ�" << testPass;
        }
    }
    else
    {
        goto input;
    }
}