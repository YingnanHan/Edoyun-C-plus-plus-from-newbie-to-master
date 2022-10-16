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

	void* operator new(size_t size, const char* txt); // ���������new
	void operator delete(void* adr, const char* txt)noexcept;
	void operator delete(void* adr, size_t size)noexcept; // ���������delete
	void operator delete(void* adr) noexcept;

	//����ò���ĳЩnew delete�����İ汾��ô����Ҫ���������ص����ò����ĺ���ɾ��
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
	std::cout << "\n\r�ͷ��ڴ�";
}

void bullet::operator delete(void* adr, size_t size)noexcept
{
	std::cout << "\n\r�ͷ��ڴ�X";
}

void bullet::operator delete(void* addr) noexcept
{
	// ���ͬʱ�����˴��������벻�������Ĵ˺����������汾����ô�ͽ����˺����ᱻ����

}

bullet::~bullet()
{
	bUse = false;
}

int main()
{
	// case 01
	//bullet* shota = new (mem) bullet(); // ָ����ĳһ��λ���Ϸ����ڴ� �������mem����(�ѿռ�)��
	//cout << (void*)mem << std::endl;
	//cout << shota << std::endl;
	//delete[] (mem); // ���Բ�д

	// case 02
	//bullet* shota = new  bullet(); // ָ����ĳһ��λ���Ϸ����ڴ� �������mem����(�ѿռ�)��
	//cout << (void*)mem << std::endl;
	//cout << shota << std::endl;
	//delete[](mem); // ���Բ�д

	// case 03
	//bullet* shota1 = new("") bullet; // �����������ķ�ʽ
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