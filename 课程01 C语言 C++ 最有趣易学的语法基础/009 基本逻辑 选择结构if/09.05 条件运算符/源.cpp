#include <iostream>

using namespace std;

int main()
{

    // ����һ
    /*int a, b, c;
    cout << "������һ������:";
    cin >> a;
    cout << "������һ������:";
    cin >> b;*/


    //// д��һ
    //if (a > b)
    //{
    //    c = a;
    //}
    //else
    //{
    //    c = b;
    //}
    //std::cout << "�Ƚϴ������Ϊ:" << c << std::endl;


    //// д����
    //std::cout << "�Ƚϴ������Ϊ:" << (a > b ? a : b) << std::endl;


    // ������
    int cs;
    std::cout << "������һ���������ǽ�Ϊ���������10000������������Ժ�Ľ��:" << std::endl;
    std::cin >> cs;
    int end;
    end = cs ? (10000 / cs) : 0; // ����cs�Ǽٵ�����:ǰ��ı��ʽ���ᱻִ��
    std::cout << end;

    // ���� ��&&��������е�ʱ�� �򵥵�����Ӧ��д��ǰ�� �����ڻ���ʱ����Լʱ��

    return 0;
}
