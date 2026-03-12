// Chapter6_Func.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;


//宏定义
#define PI =3.14
#define FUNC(a,b) a*b

//条件编译
#ifndef iostream
#include<iostream>
#endif // !<iostream>


//内联函数
inline int Times(int a)
{
    return pow(M_E, a);
}


//函数模版
template<typename T>
T MaxData(T a, T b, T c)
{
    T max = a;
    (b > max) ? max = b : ;
    (c > max) ? max = c : ;
    return max;
}

template<typename T>
auto MaxData(T a, T b, T c) -> T
{
    T max = a;
    (b > max) ? max = b : ;
    (c > max) ? max = c : ;
    return max;
}



void cmath_EX()
{
    double target = 2;
    sin(target);
    cos(target);
    asin(target);
    pow(M_E, 4);
    sqrt(target);
    exp(target);
}




int main()
{
#ifndef M_E
    cout << "M_E NOT DEFINED";
#endif //条件编译
}
