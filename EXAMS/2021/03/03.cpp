// 03.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define SIZE 5
using namespace std;

class Polynomial
{
    friend auto operator+(Polynomial const& lhs, Polynomial const& rhs) -> Polynomial;
    friend auto operator<<(std::ostream& ostream, Polynomial const& polynomial) -> std::ostream&;
public:
    Polynomial(int a[])
    {
        for (int i = 0; i < SIZE; i++)
        {
            xishu[i] = a[i];
        }
    }
    Polynomial()
    {
        for (int i = 0; i < SIZE; i++)
        {
            xishu[i] = 0;
        }
    }
    auto operator+=(Polynomial const& other) -> Polynomial&
    {
        for (int i = 0; i < SIZE; i++)
        {
            xishu[i] += other.xishu[i];
        }
        return *this;
    }
private:
    int xishu[SIZE];
};


auto operator+(Polynomial const& lhs, Polynomial const& rhs) -> Polynomial
{
    Polynomial temp;
    for (int i = 0; i < SIZE;i++)
    {
        temp.xishu[i] = lhs.xishu[i] + rhs.xishu[i];
    }
    return temp;
}

auto operator<<(std::ostream& ostream, Polynomial const& polynomial) -> std::ostream&
{
    int i = 0;
    while (!polynomial.xishu[i])
    {
        i++;
    }
    if (i == 0)
    {
        ostream << polynomial.xishu[i];
    }
    else
    {
        ostream << polynomial.xishu[i] << "x^" << i;
    }
    i++;

        while (polynomial.xishu[i]&&i<SIZE)
        {
            ostream << "+";

            ostream << polynomial.xishu[i] << "x^" << i;
            i++;
        }
    return ostream;
}


int main()
{
    int a[5] = { 2,5,1,2,6 };
    int b[5] = { -2,-3,-5,-1,0 };
    Polynomial test01(a);
    Polynomial test02(b);
    cout << test01 << endl;
    cout << test01 + test02 << endl;
    test01 += test02;
    cout << test01;
}

