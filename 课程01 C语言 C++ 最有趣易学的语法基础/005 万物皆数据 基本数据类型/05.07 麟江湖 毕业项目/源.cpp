#include <iostream>

#define dVersion "v1.1"
#define dUrl     "�ٷ���վ http://edoyun.ke.qq.com"

int main()
{
    system("color 07");
    // ҳ��01
    std::cout << "================================================" << std::endl; // �����߿�16*3
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "             �뽭��\"����̨��\"" << dVersion << "             " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "             ���ڼ�����Ϸ...                    " << std::endl;
    std::cout << "             ���ȡ�8/100��                      " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << dUrl << "                " << std::endl;
    std::cout << "================================================" << std::endl;// �ײ��߿�

    system("pause");
    system("cls");

    // ҳ��02
    unsigned short birthYear;  // ������
    float weight;   // ����
    unsigned short height;  // ���
    unsigned short sex;  // �Ա� 0��1Ů
    unsigned long long mobile;  // �绰����

    std::cout << "================================================" << std::endl; // �����߿�16*3
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "             �뽭��\"����̨\"" << dVersion << "             " << std::endl;
    /*��� ���� �Ա� �ֻ���*/
    std::cout << "             ��������ĳ�����:";
    std::cin >> birthYear;
    std::cout << "             �������������:";
    std::cin >> weight;
    std::cout << "             ������������:";
    std::cin >> height;
    std::cout << "             ����������Ա�:";
    std::cin >> sex;
    std::cout << "             ����������ֻ���:";
    std::cin >> mobile;

    unsigned long long endInfo;

    /*������Ϣ*/
    // ���� 1999 45.5 171 1 18943117137
    endInfo = mobile / 2 * birthYear * 1000000;
    float fls = height * height / weight;
    endInfo += fls;
    endInfo *= 10;
    endInfo += sex;
    std::cout << "���ļ�������Ϊ:" << endInfo << std::endl;
    std::cout << "���½�ٷ���վ�ü������뻻ȡ������";

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << dUrl << "                " << std::endl;
    std::cout << "================================================" << std::endl;// �ײ��߿�

    system("pause");
    return 0;
}