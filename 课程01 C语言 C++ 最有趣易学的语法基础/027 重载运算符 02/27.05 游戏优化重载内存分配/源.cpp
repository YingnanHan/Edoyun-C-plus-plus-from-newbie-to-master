#include<iostream>

using namespace std;

class bullet
{
public:
	float x;
	float h;
	float y;

	float damage;

	void* operator new(size_t size, const char* text); // 重载运算符new
	void operator delete(void* adr, const char* text)noexcept;
	void operator delete(void* adr, size_t size)noexcept; // 重载运算符delete

	//如果用不到某些new delete函数的版本那么就需要将可以重载但是用不到的函数删除
	void* operator new[](size_t size) = delete;
	void operator delete[](void* addr) = delete;
	void operator delete (void* addr) noexcept;
};

char* mem = new char[0x1000];

void* bullet::operator new(size_t size, const char* text)
{
	std::cout << "\r\n申请分配内存";
	return mem; //将内存空间分配在mem上
	//return ::operator new (size); // 传递给全局的new要分配的内存大小
}

void bullet::operator delete(void* adr, const char* text)noexcept
{
	std::cout << "\n\r释放内存";
}

void bullet::operator delete(void* adr, size_t size)noexcept
{
	std::cout << "\n\r释放内存X";
}

void bullet::operator delete(void* addr) noexcept
{
	// 如果同时定义了带参数的与不带参数的此函数的两个版本，那么就仅仅此函数会被调用
}

int main()
{
	// case 01
	//bullet* shota = new (mem) bullet(); // 指定在某一个位置上分配内存 如这里的mem数组(堆空间)上
	//cout << (void*)mem << std::endl;
	//cout << shota << std::endl;
	//delete[] (mem); // 可以不写

	// case 02
	//bullet* shota = new  bullet(); // 指定在某一个位置上分配内存 如这里的mem数组(堆空间)上
	//cout << (void*)mem << std::endl;
	//cout << shota << std::endl;
	//delete[](mem); // 可以不写

	// case 03
	bullet* shota1 = new("") bullet; // 传入额外参数的方式
	delete shota1;
	/*bullet* shota2 = new bullet[20];
	delete[] shota2;*/


	return 0;
}