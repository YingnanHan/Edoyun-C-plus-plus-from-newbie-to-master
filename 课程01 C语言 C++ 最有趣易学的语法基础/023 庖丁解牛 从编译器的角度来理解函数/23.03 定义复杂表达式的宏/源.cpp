#include<iostream>

using namespace std;

#define SUM(X,Y) X+Y
#define RELEASE(x) delete[]x;x=nullptr
#define BIGGER(x,y) x>y?x:y

#define SHOW(x) std::cout<<#x; //# ��ʾ��ԭ���������
#define CONCAT(x,y) std::cout<<x##y; //## ��ʾ�� XYƴ������

int main()
{
	// 01
	//cout << SUM(100, 200) << endl;
	//int* a = new int{ 100 };
	//cout << *a << endl;
	//RELEASE(a);
	//// cout << *a; //a������֮ǰ��ɾ�����Ƿ�ʹ��
	
	// 02
	//SHOW("Hello World!"); // ��ԭ����� "Hello World!"
	
	// 03
	CONCAT("Hello ","World!")

	return 0;
}