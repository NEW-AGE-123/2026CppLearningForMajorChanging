// 04.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
using namespace std;



class Date
{
	friend class FinalTest;
public:
	Date()
		:yr(2014), mn(1), dy(1)
	{

	}
	Date(int a, int b, int c)
		:yr(a), mn(b), dy(c)
	{

	}
private:
	int yr;
	int mn;
	int dy;
};

class FinalTest
{
public:
	FinalTest(string a, const Date& b)
		:name(a),time(b)
	{}
	FinalTest(string a)
		:name(a)
	{
	}
	void setDue(const Date& b)
	{
		time = b;
	}
	void print()
	{
		cout << "Title:" << name << endl;
		cout << "Test Date:" << time.yr << "/" << time.mn << "/" << time.dy << endl;
	}
private:
	string name;
	Date time;
};












int main() {
	FinalTest item1("C++ Test", Date(2014, 6, 2));
	item1.print();
	FinalTest item2("Java");
	item2.print();
	item2.setDue(Date(2014, 6, 10));
	item2.print();
}