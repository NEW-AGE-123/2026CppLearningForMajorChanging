// 2024_01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>




class Shape
{
public:
    virtual void display()
    {

    }
    virtual double volume() = 0;
private:

};

class Spheres:public Shape
{
public:
    Spheres(double a)
        :v(a*a*M_PI*(double)3/4)
    {

    }
    void display()  override
    {
        std::cout << "Spheres's Volume =" << v <<std::endl;
    }
    double volume()  override
    {
        return v;
    }
private:
    double v;
};

class Cuboid :public Shape
{
public:
    Cuboid(double a, double b, double c)
        :v(a* b*c)
    {

    }
    void display()  override
    {
        std::cout << "Cuboid's Volume =" << v << std::endl;
    }
    double volume()  override
    {
        return v;
    }
private:
    double v;
};

class Cube :public Shape
{
public:
    Cube(double a)
        :v(a* a* a)
    {

    }
    void display()  override
    {
        std::cout << "Cube's Volume =" << v << std::endl;
    }
    double volume()  override
    {
        return v;
    }
private:
    double v;
};





int main()
{
    Shape* shapes[3];

    shapes[0] = new Spheres(3);
    shapes[1] = new Cuboid(2, 3, 4);
    shapes[2] = new Cube(5);

    double totalVolume = 0;

    for (int i = 0; i < 3; ++i)
    {
        shapes[i]-> display();
        totalVolume += shapes[i]->volume();
    }


    std::cout << "Total volume of all shapes:" << totalVolume << std::endl;
}

