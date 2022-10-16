#include <iostream>

using namespace std;

void bubble(int a[], int n) 
{
    int temp, i, j;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (a[j] > a[j + 1]) 
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

}

int main() {
    int i, n;
    int a[100];
    cout << "请输入数组总数：" << endl;
    cin >> n;
    cout << "请输入一组整数：" << endl;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    bubble(a, n);
    cout << "排序后的数组为：" << endl;
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}