extern int x; // = 250

void test()
{
	::x; //可以在外部函数内部访问到其他文件中具有外部连接属性的变量
}