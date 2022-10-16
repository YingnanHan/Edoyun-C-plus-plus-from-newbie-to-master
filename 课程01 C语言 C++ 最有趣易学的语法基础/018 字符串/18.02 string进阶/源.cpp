#include<iostream>
#include<string>

using namespace std;

#define SoftName  "EDY"
#define SoftVersion  "2.0" 
#define SoftVersion1  "3.0" 

int main()
{
	string str;
	// ①
	// 加法不可以对const char * 进行相加
	str = "abc" + string{ "!123" };

	str = "abc" + ("bcd" + string{ "123" }); //合法
	//str = "abc" + "bcd" + string{ "123" }; // 按照如上的规则 这样写不合法

	str += "nba!" + ("12323" + string("sss")); //弄清楚运算符优先级
	// ②
	string strB;
	// strB = "123" + "456"; //非法
	strB = "123""456"; // 合法

	//字符串连接的直接方式
	strB = SoftName SoftVersion; //如果是变量名称需要加上空格 如果是字符串本身，就直接链接
	// ③
	// 字符串与字符的链接
	string a{ "123" };
	char s;
	// cin >> s;
	// a += s; // 直接使用+连接字符串和字符
	// cout << a;

	// ④ 使用append()
	string str4{ "123" };
	str4.append("456"); // append()返回一个string对象 所以后面可以可选的添加多个append()
	// std::cout << str4 << std::endl;

	// ⑤ 截取初始化与截取追加
	string str5{ "123",1 }; //仅仅截取123中的1
	str.append("560ABC", 1, 3); // 截取追加60A
	str.append(" 456").append(" 567").append(" 89A"); // str.append()返回的对象仍然是string类型的 所以可以连续任意次的使用append()

	// ⑥ std::string.substr(a,b) 截取字符串 表示从a位置开始一共截取b个字符
	string str6{ "123" };
	str.append("560ABC", 1, 3);
	str.append("  456").append(" 567").append(" 89A");

	string str7 = str.substr(7).substr(4, 2);
	cout << str7;
	//	str7 = str6.substr(7).substr(4, 2);

		// ⑦ 长度length()
	cout << "str7.length() = " << str7.length() << std::endl;;

	return 0;
}