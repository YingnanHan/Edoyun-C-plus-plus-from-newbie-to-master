#include <iostream>

using namespace std;

int main()
{
    unsigned long long uId, uPass;

    cout << "�뽭����Ϸע��\n\n�����������ʺ�(16bitʮ������):";
    std::cin >> hex >> uId;
    std::cout << "\n��������������:";
    std::cin >> uPass;
    // ע�Ჿ��
    //

    if ((uId > 0xfffff) && (uPass > 0xfffff))
    {
        unsigned long long uInid, uInPass;
        system("cls");
        cout << "�뽭����Ϸ��¼\n\n�����������ʺ�(16bitʮ������):";
        std::cin >> uInid;
        std::cout << "\n��������������:";
        std::cin >> uInPass;
        if (uInid == uId)
        {
            // std
            if (uPass == uInPass)
            {
                std::cout << "��½��Ϸ";
            }
            else
            {
                std::cout << "�Բ������������������";
            }
        }
        else
        {
            std::cout << "�Բ�����������˺�����" << std::endl;
        }
    }
    else
    {
        std::cout << "ע��ʧ�ܣ��˺Ż����벻����λ\n\n";
    }
}