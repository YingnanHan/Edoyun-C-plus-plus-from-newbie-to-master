#include <iostream>

int main()
{
    char a;
linput:
    printf("��������һ����д��ĸ�����Ǹ���ת��һ��Сд��ĸ:");
    std::cin >> a;
    if (a > 64 && a < 91)
    {
        a += 32;
        std::cout << a << std::endl;
        goto linput;
    }
    else
    {
        printf("����������ݲ��������ǵ�Ҫ�����������룺");
        goto linput;
    }
    return 0;
}
