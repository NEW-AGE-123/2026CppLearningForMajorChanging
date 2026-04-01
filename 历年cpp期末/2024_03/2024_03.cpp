// 2024_03.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;




int gcd(int a, int b)
{
	if (a % b == 0)
	{
		return b;
	}

	return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
class Fraction
{
    friend ostream& operator<<(ostream& output, Fraction a);
    friend Fraction operator+(int i, const Fraction& a);
    friend Fraction operator+(const Fraction& a, int i);
public:
    Fraction()
        :x(0),y(0)
    { }
    Fraction(int a,int b)
        :x(a/gcd(a,b)), y(b / gcd(a, b))
    {}
    Fraction operator+(const Fraction& a)
    {
        int fenzi = lcm(y, a.y) / y *x +lcm(y, a.y) / a.y * a.x;
        int fenmu = lcm(y, a.y);
        Fraction temp(fenzi, fenmu);
        return temp;
    }

    Fraction& operator=(const Fraction& a)
    {
        y = a.y;
        x = a.x;
        return *this;
    }

private:
    int x;
    int y;
};


ostream& operator<<(ostream& output, Fraction a)
{
    if (a.y == 1)
    {
        output << a.x;
    }
    else
    {
        output << a.x << "/" << a.y;
    }
    return output;
}

Fraction operator+(int i,const Fraction& a)
{
    int fenzi = i * a.y + a.x;
    int fenmu = a.y;
    Fraction temp(fenzi, fenmu);
    return temp;
}
Fraction operator+(const Fraction& a, int i)
{
    int fenzi = i * a.y + a.x;
    int fenmu = a.y;
    Fraction temp(fenzi, fenmu);
    return temp;
}





int main() {
    cout << "test 1: ";
    Fraction f1(1, 3), f2(7, 15);
    cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;

    cout << "test 2: ";
    Fraction f3(4, 5), f4(2, 5);
    cout << f3 << "+" << f4 << "=" << f3 + f4 << endl;

    cout << "test 3: ";
    int i = 1;
    Fraction f6 = i + f1;
    cout << i << "+" << f1 << "=" << f6 << endl;

    Fraction f7(2, 15), f8;
    f8 = f4 + f7;
    cout << f4 << "+" << f7 << "=" << f8 << endl;

    return 0;
}