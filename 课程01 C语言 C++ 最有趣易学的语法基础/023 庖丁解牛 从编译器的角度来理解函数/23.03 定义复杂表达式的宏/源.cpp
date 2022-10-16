#include<iostream>

using namespace std;

#define SUM(X,Y) X+Y
#define RELEASE(x) delete[]x;x=nullptr
#define BIGGER(x,y) x>y?x:y

#define SHOW(x) std::cout<<#x; //# 表示按原样输出内容
#define CONCAT(x,y) std::cout<<x##y; //## 表示将 XY拼接起来

int main()
{
	// 01
	//cout << SUM(100, 200) << endl;
	//int* a = new int{ 100 };
	//cout << *a << endl;
	//RELEASE(a);
	//// cout << *a; //a在这里之前被删除，非法使用
	
	// 02
	//SHOW("Hello World!"); // 按原样输出 "Hello World!"
	
	// 03
	CONCAT("Hello ","World!")

	return 0;
}