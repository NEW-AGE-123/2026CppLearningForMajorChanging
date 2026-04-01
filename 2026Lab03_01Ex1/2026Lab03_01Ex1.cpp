// 2026Lab03_01Ex1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;




class MyBase1 {
public:
	MyBase1() { cout << "...BaseClass1 Object is created!" << endl; }

	~MyBase1() { cout << "...BaseClass1 Object is destroyed!" << endl; }
};
/*
class Myderived1 : public MyBase1 {
public:
	Myderived1()
	{
		cout << "...First layer derived Object is created!" << endl;
	}
	~Myderived1()

	{
		cout << "...First layer derived Object is Destroyed!" << endl;
	}
};

class Myderived11 : public Myderived1 {
public:
	Myderived11()

	{
		cout << "...Second layer derived Object is created!" << endl;
	}

	~Myderived11()

	{
		cout << "...Second layer derived Object is destroyed!" << endl;
	}
};

class MyBase2 {
	MyBase1 a1;
public:
	MyBase2()

	{
		cout << "...BaseClass2 Object is created!" << end;
	}

	~MyBase2()

	{
		cout << "...BaseClass2 Object is destroyed!" << end;
	}
};
*/


class MyBase2 {
	MyBase1 a1;
public:
	MyBase2()

	{
		cout << "...BaseClass2 Object is created!" << endl;
	}

	~MyBase2()

	{
		cout << "...BaseClass2 Object is destroyed!" << endl;
	}
};


class Myderived1 : public MyBase2 {
	MyBase1 a1;
public:
	Myderived1()

	{
		cout << "...First layer derived Object is created!" << endl;
	}

	~Myderived1()

	{
		cout << "...First layer derived Object is Destroyed!" << endl;
	}
};

class Myderived11 : public Myderived1 {
public:
	Myderived11()

	{
		cout << "...Second layer derived Object is created!" << endl;
	}

	~Myderived11()

	{
		cout << "...Second layer derived Object is destroyed!" << endl;
	}
};
int main()
{
	MyBase2 a;
	Myderived1 b;
	Myderived11 c;
}












/*
int main()
{
	MyBase1 a;
	Myderived1 b;
	Myderived11 c;
}
*/
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
