#include<iostream>

using namespace std;

namespace htd
{
	void sendMsg()
	{

	}
	namespace hack
	{
		void hardServer()
		{

		}
	}
}

namespace hServer = htd::hack;

int main()
{
	hServer::hardServer();
}
