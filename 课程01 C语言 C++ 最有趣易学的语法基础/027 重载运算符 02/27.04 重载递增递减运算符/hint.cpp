#include "hint.h"

hint::hint(int val)
{
	mem[0] = new char;
	mem[1] = new char;
	mem[2] = new char;
	mem[3] = new char;

	*this = val;
}

hint::hint(hint& val) :hint((int)val)
{

}

hint::~hint()
{
	delete mem[0];
	delete mem[1];
	delete mem[2];
	delete mem[3];
}

hint::operator int() const
{
	int val;
	char* read = (char*)&val;

	read[3] = mem[0][0];
	read[1] = mem[1][0];
	read[0] = mem[2][0] ^ 0x23;
	read[2] = mem[3][0];

	return val;
}

void hint::operator=(int val)
{
	char* read = (char*)&val;
	mem[0][0] = read[3];
	mem[1][0] = read[1];
	mem[2][0] = read[0] ^ 0x23;
	mem[3][0] = read[2];
}

hint& hint::operator++()
{
	*this = *this + 1;
	return *this;
}

hint hint::operator++(int x)
{
	hint val = (int) * this;
	*this = *this + 1;
	return val;
}

const hint& operator--(hint& val) // const限制i++++++++这类情况发生
{
	val = val - 1;
	return val;
}

const hint operator--(hint& val, int x)
{
	hint _val = val;
	--val;
	return _val;
}