#include <iostream>
#include<cctype>

using namespace std;

int main()
{
    char a;
    bool b;
    cout << "please enter a character:";
    char c;
    cin >> c;
    c = toupper(c);
    b = isupper(c);
    cout << c << endl;
    cout << b << endl;
    return 0;
}