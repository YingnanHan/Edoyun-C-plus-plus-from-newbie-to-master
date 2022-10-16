#include<iostream>

using namespace std;

class T
{
private:
	// inline const static int count{}; // 声明静态成员常量
	inline static int count{};
public:
	static void Test() //const 静态成员函数不可是const 
	{
		//this->hp++; // 静态成员函数不可以访问this指针
		count++; //  静态成员函数不可以访问非静态成员变量
	}
	int hp;
	T()
	{
		count++;
	}
	int GetCount()
	{
		return count;
	}
	~T()
	{
		count--;
	}
};

// int T::count = 100; // 定义 静态成员变量是在各个对象之间是共享的

/* static
	① 在所有的类的实例中，共享类的静态成员变量
	② 类的静态成员变量在没有类的实例的情况下，依然可以访问
	③ 类的静态成员变量并不完全属于类 作用域属于类但是存储位置/内存空间不属于类
*/

void test()
{
	T t1, t2, t3, t4;
}

T t5;

int main()
{
	// ① 静态成员变量是在各个对象之间是共享的 
	/*T t1, t2, t3, t4;
	T t5;
	t1.count++;
	std::cout << &t2.count << std::endl;
	std::cout << &t3.count << std::endl;*/

	// ② 没有定义对象也可以访问静态成员变量
	//T::count = 350; // 使用
	//T t1;
	//std::cout << t1.count << std::endl;

	// ③ 求大小
	//std::cout << sizeof(T); // static成员不占用对象空间

	// ④ 统计对象个数
	test();
	T t1, t2, t3, t4;
	T t5;
	std::cout << t1.GetCount();

	return 0;
}