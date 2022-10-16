#include<iostream>

using namespace std;

class bullet
{
public:
	float x;
	float h;
	float y;

	float damage;

	void* operator new(size_t size, const char* text); // ���������new
	void operator delete(void* adr, const char* text)noexcept;
	void operator delete(void* adr, size_t size)noexcept; // ���������delete

	//����ò���ĳЩnew delete�����İ汾��ô����Ҫ���������ص����ò����ĺ���ɾ��
	void* operator new[](size_t size) = delete;
	void operator delete[](void* addr) = delete;
	void operator delete (void* addr) noexcept;
};

char* mem = new char[0x1000];

void* bullet::operator new(size_t size, const char* text)
{
	std::cout << "\r\n��������ڴ�";
	return mem; //���ڴ�ռ������mem��
	//return ::operator new (size); // ���ݸ�ȫ�ֵ�newҪ������ڴ��С
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
	bullet* shota1 = new("") bullet; // �����������ķ�ʽ
	delete shota1;
	/*bullet* shota2 = new bullet[20];
	delete[] shota2;*/


	return 0;
}