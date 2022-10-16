// 01 ����

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int* a{};
//	std::unique_ptr<int> intPtr{}; // �����ָ��
//	std::cout << intPtr << std::endl;
//
//	return 0;
//}



// 02 ��ʼ��

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int* a = new int;
//	std::unique_ptr<int> intPtr{ new int{5} }; // ����ָ��һ������ָ��
//	*intPtr = 500;
//	std::cout << intPtr << std::endl;
//
//	return 0;
//}



// 03 ��ֹ��ֵ

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int* a = new int;
//	std::unique_ptr<int[]> intptr{ new int[5] {1,2,3,4,5} }; // ����ָ�������ָ��
//	/* std::unique_ptr<int[]> intptrA = intptr; // unique_ptr������ֵ */
//	std::cout << intptr << std::endl;
//	return 0;
//}


// 04 ָ�����������������

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	std::unique_ptr<int[]> intPtr{ std::make_unique<int[]>(5) }; //C++11�﷨ ����һ��ָ��������Ԫ�����������ָ��
//	std::unique_ptr<int> intPtrA{ std::make_unique<int>(5) }; //C++11�﷨ ����һ��ָ�����1��Ԫ�����������ָ�� ��ʼֵΪ5
//
//	return 0;
//}


// 05 reset() ����

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	std::unique_ptr<int[]> intptr{ std::make_unique<int[]>(5) }; //c++11�﷨ ����һ��ָ��������Ԫ�����������ָ��
//	std::unique_ptr<int> intptrA{ std::make_unique<int>(5) }; //c++11�﷨ ����һ��ָ�����1��Ԫ�����������ָ�� ��ʼֵΪ5
//
//	intptr.reset();  // reset���ͷ�����ָ����ڴ�ռ䲢�ҽ�std::unique_ptr����Ϊnullptr����00000
//	std::cout << intptr << std::endl;
//	return 0;
//}


// 06 get()����

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int* a = new int; // ����һ����ָͨ��
//	std::unique_ptr<int[]> intptr{ std::make_unique<int[]>(5) }; //c++11�﷨ ����һ��ָ��������Ԫ�����������ָ��
//	std::unique_ptr<int> intptrA{ std::make_unique<int>(5) }; //c++11�﷨ ����һ��ָ�����1��Ԫ�����������ָ�� ��ʼֵΪ5
//
//	a = intptrA.get(); // get() �������ڵõ�����ָ���һ�㻯��ʽ
//	std::cout << intptrA << std::endl;
//	std::cout << a << std::endl;
//	return 0;
//}


// 07 release����

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int* a = new int; // ����һ����ָͨ��
//	std::unique_ptr<int[]> intptr{ std::make_unique<int[]>(5) }; //c++11�﷨ ����һ��ָ��������Ԫ�����������ָ��
//	std::unique_ptr<int> intptra{ std::make_unique<int>(5) }; //c++11�﷨ ����һ��ָ�����1��Ԫ�����������ָ�� ��ʼֵΪ5
//
//	std::cout << intptr << std::endl;
//	a = intptr.release(); // release���᷵��unique_ptr��ָ�룬���ҽ�unique_ptr����Ϊnullptr
//	std::cout << a << std::endl;
//	std::cout << intptr << std::endl;
//	return 0;
//}


//08 std::unique_ptr ��ת��
#include<iostream>

using namespace std;

int main()
{
	// �����ͷ���Ψһ��

	int* a = new int[5];
	delete[]a;

	std::unique_ptr<int[]> intptr{ std::make_unique<int[]>(5) };
	std::unique_ptr<int[]> intptrA{ };

	std::cout << intptr << " " << intptrA << std::endl;
	intptrA = std::move(intptr); //���ƶ��Ĺ�����Ҫ��֤���͵�һ�£�������ž�����ָ��
	std::cout << intptr << " " << intptrA << std::endl;

	return 0;
}