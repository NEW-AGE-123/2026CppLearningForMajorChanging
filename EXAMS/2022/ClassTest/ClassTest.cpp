// ClassTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class A
{
public:
    A(const A& p)
    {
        cout << "拷贝构造函数被使用" << endl;
    }
    A& operator=(const A& p)
    {
        cout << "赋值构造函数被使用" << endl;
        return *this;
    }
    A()
    { }
    ~A()
    {
        cout << "析构函数被调用" << endl;
    }
};

class B
{
public:
    B(A aa)
        :a(aa)
    {
    }
    A a;
};


int main()
{
    A test01;
    B test02(test01);
}





