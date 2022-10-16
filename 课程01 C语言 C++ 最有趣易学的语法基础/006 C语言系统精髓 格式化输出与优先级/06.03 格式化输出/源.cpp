#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	cout << std::fixed; // 设置输出为6位小数，小数计数法
	cout << 3.14 << endl;

	cout << std::scientific; // 设置科学计数法
	cout << 3.14 << endl;

	cout << std::defaultfloat; // 设置输出为默认
	cout << 3.14 << endl;

	cout << std::setprecision(3); // 设置输出3为有效数字
	cout << 3.1415925 << endl;

	cout << 314 << endl; // 输出十进制数字

	cout << std::hex; // 设置输出十六进制
	cout << 314 << endl;

	cout << std::oct; // 设置输出八进制
	cout << 314 << endl;

	cout << std::showbase;
	cout << std::hex; // 设置输出含前导十六进制
	cout << 314 << endl;

	cout << std::showbase << std::oct; // 设置输出含前导八进制
	cout << 314 << endl;

	cout << std::dec;
	std::cout << std::setw(10) << 3.14 << std::endl; // 设置固定位宽
	std::cout << std::setfill('&') << std::setw(20) << 3.14 << std::endl; //设置固定宽度空特殊符号填充

	// 左右对齐
	cout << std::defaultfloat;
	std::cout << std::left; // 设置左对齐
	cout << std::dec;
	std::cout << std::setw(10) << 3.14 << std::endl; // 设置固定位宽
	std::cout << std::setfill('&') << std::setw(20) << 3.14 << std::endl; //设置固定宽度空特殊符号填充
	// 转移制表符\t
	std::cout << "\t你好!!\b\a" << endl;

	return 0;
}
