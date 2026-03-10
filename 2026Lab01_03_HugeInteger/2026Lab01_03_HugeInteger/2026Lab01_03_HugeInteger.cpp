// 2026Lab01_03_HugeInteger.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cmath>
#include<sstream>
using namespace std;

class HugeInteger
{
	friend ostream& operator<<(ostream& output, HugeInteger h);
	friend HugeInteger operator+(HugeInteger a, HugeInteger b);
	friend HugeInteger operator-(HugeInteger a, HugeInteger b);
public:
	HugeInteger()
	{
		for (int &a : number)
		{
			a = 0;
		}
	}
	HugeInteger(int a)
	{
		for (int &b : number)
		{
			b = 0;
		}
		input(a);
	}
	void input(int a)
	{
		int i = 0;
		for (int &b : number)
		{
			b = 0;
		}
		while (a != 0)
		{
			number[i] = a % 10;
			a = a / 10;
			i++;
		}
	}
	void output(int a)
	{
		cout << a << endl;
	}
	HugeInteger add(HugeInteger a)
	{
		HugeInteger b = *this;
		return (a + b);
	}
	HugeInteger substract(HugeInteger a)
	{
		HugeInteger b = *this;
		return (a - b);
	}
	bool isEqualto(HugeInteger b)
	{
		HugeInteger a = *this;
		for (int i = 0; i < 40; i++)
		{
			if (a.number[i] != b.number[i])
				return 0;
		}
		return 1;
	}
	bool isNotEqualto(HugeInteger b)
	{
		HugeInteger a = *this;
		for (int i = 0; i < 40; i++)
		{
			if (a.number[i] != b.number[i])
				return 1;
		}
		return 0;
	}
	bool isGreaterThan(HugeInteger b)
	{
		HugeInteger a = *this;
		for (int i = 39; i > -1; i--)
		{
			if (a.number[i] > b.number[i])
				return 1;
			if (a.number[i] < b.number[i])
			{
				return 0;
			}
		}
		return 0;
	}
	bool isLessThan(HugeInteger b)
	{
		HugeInteger a = *this;
		for (int i = 39; i > -1; i++)
		{
			if (a.number[i] < b.number[i])
				return 1;
			if (a.number[i] > b.number[i])
				return 0;
		}
		return 0;
	}
	bool isGreaterThanOrEqualto(HugeInteger b)
	{
		HugeInteger a = *this;
		for (int i = 39; i > -1; i--)
		{
			if (a.number[i] > b.number[i])
				return 1;
			if (a.number[i] < b.number[i])
				return 0;
		}
		return 1;
	}
	bool isLessThanOrEqualto(HugeInteger b)
	{
		HugeInteger a = *this;
		for (int i = 39; i > -1; i++)
		{
			if (a.number[i] < b.number[i])
				return 1;
			if (a.number[i] > b.number[i])
				return 0;
		}
		return 1;
	}
	bool isZero()
	{
		for (size_t i = 0; i < 40; i++)
		{
			if ((*this).number[i] != 0)
				return 0;
		}
		return 1;
	}
private:
	int number[40];
};

ostream& operator<<(ostream& output, HugeInteger h)
{
	stringstream  iss;
	for (int i = 39; i > -1; i--)
	{
		iss << h.number[i];
	}
	string integer = iss.str();
	output << integer << endl;
	return output;
}

HugeInteger operator+(HugeInteger a, HugeInteger b)
{
	HugeInteger temp;
	for (int i = 0; i < 40; i++)
	{
		temp.number[i] = temp.number[i]+a.number[i] + b.number[i];
		if (temp.number[i]>=10)
		{
			temp.number[i] = temp.number[i] - 10;
			temp.number[i + 1]++;
		}
	}
	return temp;
}
HugeInteger operator-(HugeInteger a, HugeInteger b)
{
	if (!a.isGreaterThanOrEqualto(b))
		swap(a, b);
	HugeInteger temp;
	for (int i = 0; i < 40; i++)
	{
		temp.number[i] = temp.number[i] + a.number[i] - b.number[i];
		if (temp.number[i] <0)
		{
			temp.number[i] = temp.number[i] + 10;
			temp.number[i + 1]--;
		}
	}
	return temp;
}




int main()
{
	HugeInteger a(923231);
	HugeInteger b(92328);
	cout << a+b;
	cout << a - b;
}

