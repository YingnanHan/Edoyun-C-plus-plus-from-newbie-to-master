#include<iostream>

using namespace std;

class bullet
{
private:
	bool bUse = true;
public:
	float x;
	float h;
	float y;

	float damage;

	void* operator new(size_t size, const char* txt); // 重载运算符new
	void operator delete(void* adr, const char* txt)noexcept;
	void operator delete(void* adr, size_t size)noexcept; // 重载运算符delete
	void operator delete(void* adr) noexcept;

	//如果用不到某些new delete函数的版本那么就需要将可以重载但是用不到的函数删除
	void* operator new[](size_t size) = delete;
	void operator delete[](void* adr) = delete;
	
	~bullet();
};

char* mem = new char[1000 * sizeof(bullet)] {};

void* bullet::operator new(size_t size, const char* text)
{
	bullet* dat = (bullet*)mem;
	for (int i = 0; i < 1000; i++)
	{
		if (!dat[i].bUse)
		{
			return &dat[i];
		}
	}
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

bullet::~bullet()
{
	bUse = false;
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
	//bullet* shota1 = new("") bullet; // 传入额外参数的方式
	//delete shota1;
	///*bullet* shota2 = new bullet[20];
	//delete[] shota2;*/

	// case 04
	bullet* shota1 = new ("it's a test") bullet;
	bullet* shota2 = new ("it's a test") bullet;
	delete shota1;
	bullet* shota3 = new ("it's a test") bullet;
	bullet* shota4 = new ("it's a test") bullet;
	bullet* shota5 = new ("it's a test") bullet;
	
	std::cout << shota1 << std::endl;
	std::cout << shota2 << std::endl;
	std::cout << shota3 << std::endl;
	std::cout << shota4 << std::endl;
	std::cout << shota5 << std::endl;

	return 0;
}