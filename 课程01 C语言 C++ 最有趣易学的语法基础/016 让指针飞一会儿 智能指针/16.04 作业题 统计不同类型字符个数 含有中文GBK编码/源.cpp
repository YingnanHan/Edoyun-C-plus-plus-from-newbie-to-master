#include <iostream>
#include<cstdlib>
#include <map>

using namespace std;

int main() {
    cout << "�������ַ�����" << endl;
    string s;
    cin >> s;	//��ȡһ������

    map<string, int> cnt;	//����ͳ��
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            cnt["Ӣ����ĸ"]++;
        else if (s[i] >= '0' && s[i] <= '9')
            cnt["����"]++;
        else if (s[i] == ' ')
            cnt["�ո�"]++;
        else if (i + 1 < s.length() &&       //��ֹԽ��
            ((unsigned char)s[i] >= 0x81 && (unsigned char)s[i] <= 0xFE &&         //��λ
                (unsigned char)s[i + 1] >= 0x40 && (unsigned char)s[i + 1] <= 0xFE))
        {    //��λ
           //ʹ��unsigned char����Ϊunsigned�����ɸ�ֵ�����������ж�
            cnt["�����ַ�"]++;
            i++;
        }
        else
            cnt["�����ַ�"]++;
    }

    for (map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
    {
        printf("%s������%d\n", (it->first).c_str(), it->second);
    }

    return 0;
}
