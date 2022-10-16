#include <iostream>
#include<cstdlib>
#include <map>

using namespace std;

int main() {
    cout << "请输入字符串：" << endl;
    string s;
    cin >> s;	//获取一行输入

    map<string, int> cnt;	//用于统计
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            cnt["英文字母"]++;
        else if (s[i] >= '0' && s[i] <= '9')
            cnt["数字"]++;
        else if (s[i] == ' ')
            cnt["空格"]++;
        else if (i + 1 < s.length() &&       //防止越界
            ((unsigned char)s[i] >= 0x81 && (unsigned char)s[i] <= 0xFE &&         //高位
                (unsigned char)s[i + 1] >= 0x40 && (unsigned char)s[i + 1] <= 0xFE))
        {    //低位
           //使用unsigned char是因为unsigned不会变成负值，这样方便判断
            cnt["中文字符"]++;
            i++;
        }
        else
            cnt["其它字符"]++;
    }

    for (map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
    {
        printf("%s个数：%d\n", (it->first).c_str(), it->second);
    }

    return 0;
}
