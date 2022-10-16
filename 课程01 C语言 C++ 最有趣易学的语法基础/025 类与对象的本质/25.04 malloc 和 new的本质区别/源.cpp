#include<iostream>

/*
	对于普通的数据类型来说malloc和new没有什么区别，但是对于类来说malloc仅仅是分配内存
	而new除了会分配内存之外还会调用构造函数。delete仅仅是释放内存空间，而且调用第一个
	元素的析构函数，而delete[]不仅仅释放内存空间，还会调用每一个元素的析构函数
*/

using namespace std;

class T
{
	int m_count{};
	inline static int count{};
public:
	T()
	{
		std::cout << "第" << ++count << "个T被构造" << std::endl;
		m_count = count;
	}
	~T()
	{
		std::cout << "第" << m_count-- << "个T被销毁" << std::endl;
	}
	int test = 2;
};

int main()
{
	T* t1 = (T*)malloc(10 * sizeof(T));
	std::cout << t1[0].test;

	int* pint = (int*)malloc(10 * 4);
	pint[2] = 250;
	std::cout << pint[2] << std::endl;

	T* t2 = new T[100];

	// T* Tarr = new T[100];

	int* pint2 = new int[200];
	pint2[100] = 5000;
	// free(pint);
	delete pint; // 对于普通数据类型，这两句话是一样的
	//free(t1); //可以释放new而来的空间但是不会调用析构函数
	delete[] t2; // delete t2; 将导致错误
	
	std::cout << pint2[100] << std::endl;
	delete[] pint2;
	// std::cout << pint2[100] << std::endl; // 无法访问


	return 0;
}