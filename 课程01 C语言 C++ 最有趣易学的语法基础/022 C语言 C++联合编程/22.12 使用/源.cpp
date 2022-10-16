#include<iostream>
#include<edoyun.h>

using namespace std;

// #pragma comment(lib, "22.11 创建自己的sdkedoyun.lib")

int main()
{
	// 使用的时候将我们已经设计好的lib库文件放到某一个位置，
	// 这个文件以及.h文件放在一个文件夹下，所以我们需要让VS
	// 知道要去哪里找到该文件夹。
	// 方法 点击解决方案-> Alt+Enter-> VC++目录 ->包含目录->(使用分号分割)
	// 将文件夹的目录加入到对应位置
	// 点击解决方案-> Alt+Enter-> VC++目录 ->库目录->(使用分号分割)
	// 将文件夹的目录加入到对应位置
	// 在文件中写入#pragma comment(lib, "22.11 创建自己的sdkedoyun.lib")预编译指令 如果不去写预编译指令，那么就需要在附加库目录中添加内容 22.11 创建自己的sdkedoyun.lib; 连接器->输入->附加依赖项
	// 值得注意的是，原来的文件下绝对不可以写main函数
	std::cout << edoyun::GetVersion();
	std::cout << ave(100, 300);
}