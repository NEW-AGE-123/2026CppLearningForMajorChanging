// 2026Lab03_05.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;


class Date
{
    friend class FinalTest;
    friend ostream& operator<<(ostream& output, const Date& p);
public:
    Date(int a, int b, int c)
        :year(a), month(b), day(c) {

    }
    Date()
        :year(0), month(0), day(0) {

    }
    
private:
    int day;
    int month;
    int year;
};

ostream& operator<<(ostream& output, const Date& p)
{
    output << p.year << "/" << p.month << "/" << p.day;
    return output;
}


class FinalTest
{
public:
    FinalTest(const string& a, const Date& b) :
        CourseName(a), TestDate(b)
    {

    }
    FinalTest(string a) :
        CourseName(a)
    {
    }
    void print()
    {
        cout << "CourseName:" << CourseName << " TestDate:" << TestDate << endl;
    }
    void setDue(const Date& p)
    {
        TestDate.year = p.year;
        TestDate.month = p.month;
        TestDate.day = p.day;
    }
private:
    string CourseName;
    Date TestDate;
};


int main()
{
    FinalTest item1("C++ Test", Date(2014, 6, 2));
    item1.print();
    FinalTest item2("Java");
    item2.print();
    item2.setDue(Date(2014, 6, 10));
    item2.print();
}