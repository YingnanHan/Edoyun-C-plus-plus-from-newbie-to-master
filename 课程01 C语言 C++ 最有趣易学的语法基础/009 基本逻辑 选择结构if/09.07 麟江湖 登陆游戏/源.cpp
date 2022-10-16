#include <iostream>

using namespace std;

int main()
{
    unsigned long long uId, uPass;

    cout << "÷ë½­ºþÓÎÏ·×¢²á\n\nÇëÊäÈëÄúµÄÕÊºÅ(16bitÊ®Áù½øÖÆ):";
    std::cin >> hex >> uId;
    std::cout << "\nÇëÊäÈëÄúµÄÃÜÂë:";
    std::cin >> uPass;
    // ×¢²á²¿·Ö
    //

    if ((uId > 0xfffff) && (uPass > 0xfffff))
    {
        unsigned long long uInid, uInPass;
        system("cls");
        cout << "÷ë½­ºþÓÎÏ·µÇÂ¼\n\nÇëÊäÈëÄúµÄÕÊºÅ(16bitÊ®Áù½øÖÆ):";
        std::cin >> uInid;
        std::cout << "\nÇëÊäÈëÄúµÄÃÜÂë:";
        std::cin >> uInPass;
        if (uInid == uId)
        {
            // std
            if (uPass == uInPass)
            {
                std::cout << "µÇÂ½ÓÎÏ·";
            }
            else
            {
                std::cout << "¶Ô²»ÆðÄúÊäÈëµÄÃÜÂëÓÐÎó£¡";
            }
        }
        else
        {
            std::cout << "¶Ô²»Æð£¬ÄúÊäÈëµÄÕËºÅÓÐÎó" << std::endl;
        }
    }
    else
    {
        std::cout << "×¢²áÊ§°Ü£¬ÕËºÅ»òÃÜÂë²»×ãÁùÎ»\n\n";
    }
}