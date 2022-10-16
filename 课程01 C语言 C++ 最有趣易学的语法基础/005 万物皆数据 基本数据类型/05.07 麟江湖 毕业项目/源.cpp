#include <iostream>

#define dVersion "v1.1"
#define dUrl     "官方网站 http://edoyun.ke.qq.com"

int main()
{
    system("color 07");
    // 页面01
    std::cout << "================================================" << std::endl; // 顶部边框16*3
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "             麟江湖\"控制台版\"" << dVersion << "             " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "             正在加载游戏...                    " << std::endl;
    std::cout << "             进度【8/100】                      " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << dUrl << "                " << std::endl;
    std::cout << "================================================" << std::endl;// 底部边框

    system("pause");
    system("cls");

    // 页面02
    unsigned short birthYear;  // 出生年
    float weight;   // 体重
    unsigned short height;  // 身高
    unsigned short sex;  // 性别 0男1女
    unsigned long long mobile;  // 电话号码

    std::cout << "================================================" << std::endl; // 顶部边框16*3
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "             麟江湖\"控制台\"" << dVersion << "             " << std::endl;
    /*身高 体重 性别 手机号*/
    std::cout << "             请输入你的出生年:";
    std::cin >> birthYear;
    std::cout << "             请输入你的体重:";
    std::cin >> weight;
    std::cout << "             请输入你的身高:";
    std::cin >> height;
    std::cout << "             请输入你的性别:";
    std::cin >> sex;
    std::cout << "             请输入你的手机号:";
    std::cin >> mobile;

    unsigned long long endInfo;

    /*加密信息*/
    // 例如 1999 45.5 171 1 18943117137
    endInfo = mobile / 2 * birthYear * 1000000;
    float fls = height * height / weight;
    endInfo += fls;
    endInfo *= 10;
    endInfo += sex;
    std::cout << "您的激活密码为:" << endInfo << std::endl;
    std::cout << "请登陆官方网站用激活密码换取激活码";

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << dUrl << "                " << std::endl;
    std::cout << "================================================" << std::endl;// 底部边框

    system("pause");
    return 0;
}