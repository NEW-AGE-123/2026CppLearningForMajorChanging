// 2026Lab01_01_Complex.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;



class complex
{
public:
    friend ostream& operator<<(ostream& output, complex p);
    complex() {
        realPart = 0;
        imaginePart = 0;
    }
    complex(int a, int b)
    {
        this->realPart = a;
        this->imaginePart = b;
    }

    complex operator+(complex p)
    {
        complex temp;
        temp.realPart = p.realPart + this->realPart;
        temp.imaginePart = p.imaginePart + this->imaginePart;
        return temp;
    }
    complex operator-(complex p)
    {
        complex temp;
        temp.realPart = realPart-p.realPart;
        temp.imaginePart = imaginePart - p.imaginePart;
        return temp;
    }

private:
    int realPart;
    int imaginePart;
};

ostream& operator<<(ostream& output,complex p)
{
    output << "(" << p.realPart << "," << p.imaginePart << ")";
    return output;
}

int main()
{
    complex a(1, 7);
    complex b(9, 2);
    complex c(10, 1);
    complex d(11, 5);
    cout << a << "+" << b << "=" << (a + b) << endl;
    cout << c << "-" << d << "=" << (c - d) << endl;
}

