#include <iostream>

int main()
{
    ////////////////////////////////////////////////
    int b{ 100 };
    int end1;
    end1 = b / 3; // �ض�
    end1 /= 3; // ����ĵȼ�д��

    int end2;
    end2 = b % 3; // �ض�
    end2 %= 3; // ����ĵȼ�д��

    std::cout << 010uL << std::endl; // �˽����µ��޷���9
    std::cout << end1 << std::endl;
    std::cout << end2 << std::endl;

    ////////////////////////////////////////////////

    int d{ 100 };
    ++d;
    std::cout << d << std::endl;
    d++;
    std::cout << d << std::endl;
    int send(++d + 5); // �ȵ���ʾ��
    std::cout << send << std::endl;
    send = (d++ + 5);// �����ʾ��
    std::cout << send << std::endl;

    send = (--d + 5); // �ȵݼ�ʾ��
    std::cout << send << std::endl;
    send = (d-- + 5);// ��ݼ�ʾ��
    std::cout << send << std::endl;
}