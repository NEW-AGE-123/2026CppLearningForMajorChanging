// 02_02.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<cmath>
using namespace std;



class Cvector
{
public:
    Cvector(double a, double b)
        :x(a), y(b)
    {

    }
    static double modulus(Cvector a) 
    {
        return sqrt(a.x * a.x + a.y * a.y);
    }
    static double inner_product(Cvector a, Cvector b)
    {
        return (a.x * b.x + a.y * b.y);
    }
    static double Cosine_distance(Cvector a, Cvector b)
    {
        return (inner_product(a, b) / (modulus(a) * modulus(b)));
    }
private:
    double x;
    double y;
};
int main()
{
    Cvector a(1, 1), b(2, 1);
    cout << Cvector::modulus(a) << endl;
    cout << Cvector::inner_product(a, b) << endl;
    cout << Cvector::Cosine_distance(a, b) << endl;

}

