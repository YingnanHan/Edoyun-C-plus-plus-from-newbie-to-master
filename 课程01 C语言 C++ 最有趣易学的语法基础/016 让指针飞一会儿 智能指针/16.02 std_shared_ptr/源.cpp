#include<iostream>

using namespace std;

int main()
{
	// ��������ָ�������
	int* a;
	std::shared_ptr<int> ptrA(new int); // ����һ������ָ��
	std::shared_ptr<int[]> ptrB(new int[5] {1, 2, 3, 4, 5}); // ����һ������ָ��
	std::shared_ptr<int> ptrC(std::make_shared<int>(5)); // ����һ������ָ��

	std::cout << ptrA << "\t" << *ptrA << std::endl;
	std::cout << ptrB << "\t" << ptrB[0] << std::endl; // ���ָ��ָ�����������ô�Ͳ�����ʹ��*ptr����ʽ���������������
	std::cout << ptrC << "\t" << *ptrC << std::endl;

	std::shared_ptr<int> ptrD(ptrA); // �����ǹ���ָ�����Կ�����ָ��֮����и�ֵ
	std::cout << ptrA << "\t" << *ptrA << std::endl;
	std::cout << ptrD << "\t" << *ptrD << std::endl;

	// �����ж��std::share_ptrָ��ͬһ����ַ��ͬһ����ַ��ֻ�е����һ��std::shareed_ptr
	// ���ͷŵ�ʱ�򣬲Ż��ͷ�����ռ�õĿռ䣬std::shared_ptr���¼��ǰ�ж��ٸ�����ָ�뱻����
	std::cout << "ptrA.use_count():" << ptrA.use_count() << std::endl;
	std::cout << "ptrB.use_count():" << ptrB.use_count() << std::endl;
	std::cout << "ptrC.use_count():" << ptrC.use_count() << std::endl;
	std::cout << "ptrD.use_count():" << ptrD.use_count() << std::endl;

	// bool std::shared_ptr.unique() ���᷵��һ��boolֵ�������ǰ����ָ����Ψһӵ�и�ָ���
	// ��ô����true�����򷵻�false ������ֻ��C++17 ֮ǰ�ı�׼�б�֧��

	std::cout << "ptrA.unique():" << ptrA.unique() << std::endl;
	std::cout << "ptrB.unique():" << ptrB.unique() << std::endl;
	std::cout << "ptrC.unique():" << ptrC.unique() << std::endl;
	std::cout << "ptrD.unique():" << ptrD.unique() << std::endl;

	// std::shared_ptr.reset() �Ὣ��ǰ����ָ������Ϊnullptr��ͬʱ�����ǰ
	// ����ָ�������һ��ӵ�и�ָ��Ķ�����ô�����ͷ��ڴ�
	ptrB.reset();
	std::cout << "ptrB.use_count():" << ptrB.use_count() << std::endl;
	std::cout << ptrB << "\t" << ptrB << std::endl; //���ڱ��ͷ��ڴ� �ڴ�ռ䱻ɾ����ԭ��λ�ñ�����Ϊ0000

	return 0;
}