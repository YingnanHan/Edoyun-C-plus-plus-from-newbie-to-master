#include<iostream>
#include<string>

using namespace std;

#define SoftName  "EDY"
#define SoftVersion  "2.0" 
#define SoftVersion1  "3.0" 

int main()
{
	string str;
	// ��
	// �ӷ������Զ�const char * �������
	str = "abc" + string{ "!123" };

	str = "abc" + ("bcd" + string{ "123" }); //�Ϸ�
	//str = "abc" + "bcd" + string{ "123" }; // �������ϵĹ��� ����д���Ϸ�

	str += "nba!" + ("12323" + string("sss")); //Ū�����������ȼ�
	// ��
	string strB;
	// strB = "123" + "456"; //�Ƿ�
	strB = "123""456"; // �Ϸ�

	//�ַ������ӵ�ֱ�ӷ�ʽ
	strB = SoftName SoftVersion; //����Ǳ���������Ҫ���Ͽո� ������ַ���������ֱ������
	// ��
	// �ַ������ַ�������
	string a{ "123" };
	char s;
	// cin >> s;
	// a += s; // ֱ��ʹ��+�����ַ������ַ�
	// cout << a;

	// �� ʹ��append()
	string str4{ "123" };
	str4.append("456"); // append()����һ��string���� ���Ժ�����Կ�ѡ����Ӷ��append()
	// std::cout << str4 << std::endl;

	// �� ��ȡ��ʼ�����ȡ׷��
	string str5{ "123",1 }; //������ȡ123�е�1
	str.append("560ABC", 1, 3); // ��ȡ׷��60A
	str.append(" 456").append(" 567").append(" 89A"); // str.append()���صĶ�����Ȼ��string���͵� ���Կ�����������ε�ʹ��append()

	// �� std::string.substr(a,b) ��ȡ�ַ��� ��ʾ��aλ�ÿ�ʼһ����ȡb���ַ�
	string str6{ "123" };
	str.append("560ABC", 1, 3);
	str.append("  456").append(" 567").append(" 89A");

	string str7 = str.substr(7).substr(4, 2);
	cout << str7;
	//	str7 = str6.substr(7).substr(4, 2);

		// �� ����length()
	cout << "str7.length() = " << str7.length() << std::endl;;

	return 0;
}