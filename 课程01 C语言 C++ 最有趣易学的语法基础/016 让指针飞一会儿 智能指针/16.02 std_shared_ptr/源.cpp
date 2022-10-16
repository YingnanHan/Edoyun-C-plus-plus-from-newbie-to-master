#include<iostream>

using namespace std;

int main()
{
	// 共享智能指针的声明
	int* a;
	std::shared_ptr<int> ptrA(new int); // 声明一个共享指针
	std::shared_ptr<int[]> ptrB(new int[5] {1, 2, 3, 4, 5}); // 声明一个共享指针
	std::shared_ptr<int> ptrC(std::make_shared<int>(5)); // 声明一个共享指针

	std::cout << ptrA << "\t" << *ptrA << std::endl;
	std::cout << ptrB << "\t" << ptrB[0] << std::endl; // 如果指针指向的是数组那么就不可以使用*ptr的形式来访问数组的内容
	std::cout << ptrC << "\t" << *ptrC << std::endl;

	std::shared_ptr<int> ptrD(ptrA); // 由于是共享指针所以可以在指针之间进行赋值
	std::cout << ptrA << "\t" << *ptrA << std::endl;
	std::cout << ptrD << "\t" << *ptrD << std::endl;

	// 可以有多个std::share_ptr指向同一个地址，同一个地址下只有当最后一个std::shareed_ptr
	// 被释放的时候，才会释放其所占用的空间，std::shared_ptr会记录当前有多少个智能指针被调用
	std::cout << "ptrA.use_count():" << ptrA.use_count() << std::endl;
	std::cout << "ptrB.use_count():" << ptrB.use_count() << std::endl;
	std::cout << "ptrC.use_count():" << ptrC.use_count() << std::endl;
	std::cout << "ptrD.use_count():" << ptrD.use_count() << std::endl;

	// bool std::shared_ptr.unique() 将会返回一个bool值，如果当前智能指针是唯一拥有该指针的
	// 那么返回true，否则返回false 本函数只在C++17 之前的标准中被支持

	std::cout << "ptrA.unique():" << ptrA.unique() << std::endl;
	std::cout << "ptrB.unique():" << ptrB.unique() << std::endl;
	std::cout << "ptrC.unique():" << ptrC.unique() << std::endl;
	std::cout << "ptrD.unique():" << ptrD.unique() << std::endl;

	// std::shared_ptr.reset() 会将当前共享指针设置为nullptr，同时如果当前
	// 智能指针是最后一个拥有该指针的对象，那么将会释放内存
	ptrB.reset();
	std::cout << "ptrB.use_count():" << ptrB.use_count() << std::endl;
	std::cout << ptrB << "\t" << ptrB << std::endl; //由于被释放内存 内存空间被删除，原有位置被设置为0000

	return 0;
}