#include <iostream>

int a{ 100 }; // ȫ�ֱ��� ����д�ڴ����е��κ�λ�ã���д��main����Ͳ�����ʹ��

int main()
{
    int a{ 10 };
    {
        int c{ 90 };
        int a{ 30 };
        {
            char a = 'A';
            std::cout << a << std::endl;
            std::cout << "��ʾȫ�ֱ���::a = " << ::a << std::endl; // ::��ʾȫ�ֱ�����λ�ý���
        }//�����Żᵼ���������ڽ���
        std::cout << a << std::endl;
    }
    std::cout << a << std::endl;
}