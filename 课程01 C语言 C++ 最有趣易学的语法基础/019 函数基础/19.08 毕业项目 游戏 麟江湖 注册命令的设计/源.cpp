#include<iostream>

// 本程序仅仅在命令行下执行
// 执行方式 C:\Users\20613\Desktop\易道云 C++ 全栈 工程\课程01 C语言 C++ 最有趣易学的语法基础\019 函数基础\19.08 毕业项目 游戏 麟江湖 注册命令的设计\x64\Debug
// 目录下执行 linReg 加上参数 <id:xxx pass:yyy country:zzz> xxx yyy zzz部分请自行修改

char* ReadRef(const char* ref, const char* cmds)
{
	//pass:
	//id:xxxxx pass xxxxx
	for (int i = 0; cmds[i]; i++)
	{
		if (cmds[i] == ref[0])
		{
			bool bfind = true;
			int x;
			for (x = 0; ref[x]; x++)
			{
				if (ref[x] != cmds[i + x])
				{
					bfind = false;
					break;
				}
			}
			if (bfind)
			{
				return (char*)&cmds[i + x];
			}
		}
	}
	return nullptr;
}

int main(int count,char* arc[])
{
	char* id{}, * pass{}, * country{};
	const char* iRef{ "id:" };
	const char* passRef{ "pass:" };
	const char* countryRef{ "country:" };

	for (int i = 1; arc[i]; i++)
	{
		if (id == nullptr)
		{
			id = ReadRef(iRef, arc[i]);
			if (id != nullptr)
			{
				continue;
			}
		}
		if (pass == nullptr)
		{
			pass = ReadRef(passRef, arc[i]);
			if (pass != nullptr)
			{
				continue;
			}
		}
		if (country == nullptr)
		{
			country = ReadRef(countryRef, arc[i]);
			if (country != nullptr)
			{
				continue;
			}
		}
	}

	if ((int)id * (int)pass * (int)country)
	{
		std::cout << "账号：" << id;
		std::cout << "密码：" << pass;
		std::cout << "国家：" << country;
	}
	else
	{
		std::cout << "请使用命令的方式调用你的程序";
	}
}