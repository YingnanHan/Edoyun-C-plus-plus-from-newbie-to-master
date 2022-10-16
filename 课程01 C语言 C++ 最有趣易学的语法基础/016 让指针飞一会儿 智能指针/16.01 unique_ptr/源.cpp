// 01 定义

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int* a{};
//	std::unique_ptr<int> intPtr{}; // 定义空指针
//	std::cout << intPtr << std::endl;
//
//	return 0;
//}



// 02 初始化

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int* a = new int;
//	std::unique_ptr<int> intPtr{ new int{5} }; // 定义指向单一变量的指针
//	*intPtr = 500;
//	std::cout << intPtr << std::endl;
//
//	return 0;
//}



// 03 禁止赋值

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int* a = new int;
//	std::unique_ptr<int[]> intptr{ new int[5] {1,2,3,4,5} }; // 定义指向数组的指针
//	/* std::unique_ptr<int[]> intptrA = intptr; // unique_ptr不允许赋值 */
//	std::cout << intptr << std::endl;
//	return 0;
//}


// 04 指向数组与变量的区别

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	std::unique_ptr<int[]> intPtr{ std::make_unique<int[]>(5) }; //C++11语法 定义一个指向具有五个元素数组的智能指针
//	std::unique_ptr<int> intPtrA{ std::make_unique<int>(5) }; //C++11语法 定义一个指向具有1个元素数组的智能指针 初始值为5
//
//	return 0;
//}


// 05 reset() 方法

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	std::unique_ptr<int[]> intptr{ std::make_unique<int[]>(5) }; //c++11语法 定义一个指向具有五个元素数组的智能指针
//	std::unique_ptr<int> intptrA{ std::make_unique<int>(5) }; //c++11语法 定义一个指向具有1个元素数组的智能指针 初始值为5
//
//	intptr.reset();  // reset会释放智能指针的内存空间并且将std::unique_ptr设置为nullptr就是00000
//	std::cout << intptr << std::endl;
//	return 0;
//}


// 06 get()方法

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int* a = new int; // 定义一个普通指针
//	std::unique_ptr<int[]> intptr{ std::make_unique<int[]>(5) }; //c++11语法 定义一个指向具有五个元素数组的智能指针
//	std::unique_ptr<int> intptrA{ std::make_unique<int>(5) }; //c++11语法 定义一个指向具有1个元素数组的智能指针 初始值为5
//
//	a = intptrA.get(); // get() 方法用于得到智能指针的一般化形式
//	std::cout << intptrA << std::endl;
//	std::cout << a << std::endl;
//	return 0;
//}


// 07 release方法

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int* a = new int; // 定义一个普通指针
//	std::unique_ptr<int[]> intptr{ std::make_unique<int[]>(5) }; //c++11语法 定义一个指向具有五个元素数组的智能指针
//	std::unique_ptr<int> intptra{ std::make_unique<int>(5) }; //c++11语法 定义一个指向具有1个元素数组的智能指针 初始值为5
//
//	std::cout << intptr << std::endl;
//	a = intptr.release(); // release将会返回unique_ptr的指针，并且将unique_ptr设置为nullptr
//	std::cout << a << std::endl;
//	std::cout << intptr << std::endl;
//	return 0;
//}


//08 std::unique_ptr 的转移
#include<iostream>

using namespace std;

int main()
{
	// 过户释放与唯一性

	int* a = new int[5];
	delete[]a;

	std::unique_ptr<int[]> intptr{ std::make_unique<int[]>(5) };
	std::unique_ptr<int[]> intptrA{ };

	std::cout << intptr << " " << intptrA << std::endl;
	intptrA = std::move(intptr); //在移动的过程中要保证类型的一致，这样会杜绝悬空指针
	std::cout << intptr << " " << intptrA << std::endl;

	return 0;
}