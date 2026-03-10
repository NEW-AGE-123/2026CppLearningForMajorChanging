// 2026Lab01_02_Time_inhanced.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <iomanip>
using namespace std;


class Time
{
	friend void tick(Time& );
	friend ostream& operator<<(ostream& , Time );
public:
	Time(int a, int b, int c)
	{
		hour = a;
		minute = b;
		second = c;
	}


private:
	int hour;
	int minute;
	int second;
};


void tick(Time& t)
{
	int*p[3] = { &t.second ,&t.minute,&t.hour };
	int**a = &p[0];
	**a = **a + 1;
	while ((**a)==60&&(a)!=(p+2))
	{
		**(a + 1) = **(a + 1) + 1;
		**a = 0;
		a = a + 1;
	}
	if ((**a) == 24 && (a) == (p + 2))
	{
		t.hour = 0;
		t.minute = 0;
		t.second = 0;
	}
}

ostream& operator<<(ostream& output, Time t)
{
	output << setw(2) << setfill('0') << t.hour << ":" << setw(2) << setfill('0') << t.hour << ":" << setw(2) << setfill('0') << t.second << endl;
	return output;
}
int main()
{
	Time a(23, 59, 59);
	cout << a;
	tick(a);
	cout << a;

}

