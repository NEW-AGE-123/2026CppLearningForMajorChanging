// 2026_Lab_01_04SimpleCalculator.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;


class SimpleCalculator
{
public:
    double add(double a, double b)
    {
        return a + b;
    }
    double substract(double a, double b)
    {
        return a - b;
    }
    double multiply(double a, double b)
    {
        return a * b;
    }
    double divide(double a, double b)
    {
        return a /b;
    }
};
int main()
{
    SimpleCalculator a;
    cout << a.add(12.123, 23.231) << endl;
    cout << a.substract(12.123, 23.231) << endl;
    cout << a.multiply(12.123, 23.231) << endl;
    cout << a.divide(12.123, 23.231) << endl;
}


