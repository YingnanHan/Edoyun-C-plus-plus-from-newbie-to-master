#include<iostream>

using namespace std;

int main()
{
	// case 01
	//int* p;

	//{
	//	int* a = new int[50];
	//	p = a;
	//	a[2] = 255; //�ڴ�����ⲿ�ᵼ��Ұָ��p�ĳ���
	//}
	//std::cout << p[2]; //p��Ȼָ��Ŀ��������a�ĵ�ַ������a�Ѿ����ͷ���

	// case 02
	//int* p;
	//{
	//	std::unique_ptr<int[]>a{ std::make_unique<int[]>(50) };
	//	a[2] = 250;

	//	p = a.get(); // �õ�a��Ӧ������
	//	std::cout << p[2]<<std::endl;
	//}
	//std::cout << p[2] << std::endl;// ����a������ָ�룬�ڴ�����ⲿa�ᱻ�ͷŵ�����Ӧ���ڴ�Ҳ�ỹ������ϵͳ������p��Ȼָ�����ռ�
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
