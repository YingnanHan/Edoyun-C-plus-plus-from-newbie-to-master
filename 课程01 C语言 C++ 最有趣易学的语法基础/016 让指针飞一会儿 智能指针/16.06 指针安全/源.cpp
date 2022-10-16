#include<iostream>

using namespace std;

int main()
{
	// case 01
	//int* p;

	//{
	//	int* a = new int[50];
	//	p = a;
	//	a[2] = 255; //在代码块外部会导致野指针p的出现
	//}
	//std::cout << p[2]; //p仍然指向目标代码块中a的地址，但是a已经被释放了

	// case 02
	//int* p;
	//{
	//	std::unique_ptr<int[]>a{ std::make_unique<int[]>(50) };
	//	a[2] = 250;

	//	p = a.get(); // 得到a对应的内容
	//	std::cout << p[2]<<std::endl;
	//}
	//std::cout << p[2] << std::endl;// 由于a是智能指针，在代码块外部a会被释放掉，对应的内存也会还给操作系统，但是p仍然指向这块空间
	//

	// case 03
	int* p;
	{
		int* a = new int[5];
		p = a;
		std::cout << p[0] << std::endl;
		delete[] a;
	}
	std::cout << p[0];

	return 0;
}
