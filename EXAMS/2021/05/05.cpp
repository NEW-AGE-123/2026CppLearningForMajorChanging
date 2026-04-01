// 05.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;



class Shape
{
public:
	virtual void get_volume() = 0;
	virtual void get_area() = 0;
	~Shape()
	{ }
};
class TwoDiagramShape :public Shape
{
public:
	virtual void get_area()
	{
		cout << "print_area." << endl;
	}
	virtual void get_volume()
	{

	}

	~TwoDiagramShape()
	{ }
};

class ThreeDiagramShape :public Shape
{
public:
	virtual void get_area()
	{
		cout << "print_area." << endl;
	}
	virtual void get_volume()
	{
		cout << "print_volume." << endl;
	}
	~ThreeDiagramShape()
	{

	}
};

class Cube :public ThreeDiagramShape
{
public:
	virtual void get_area()
	{
		cout << "print_Cube_area." << endl;
	}
	virtual void get_volume()
	{
		cout << "print_Cube_volume." << endl;
	}
	~Cube()
	{ }
};

class Circle :public TwoDiagramShape
{
public:
	virtual void get_area()
	{
		cout << "print_Circle_area." << endl;
	}
	~Circle()
	{ }
};







int main()
{
	Cube cube;
	Circle circle;
	vector<Shape*> a;
	a.push_back(&cube);
	a.push_back(&circle);


	for (int i = 0; i < a.size(); i++)
	{
		if (TwoDiagramShape* twoptr = dynamic_cast<TwoDiagramShape*> (a[i]))
		{
			a[i]->get_area();
		}
		if (ThreeDiagramShape* twoptr = dynamic_cast<ThreeDiagramShape*>(a[i]))
		{
			a[i]->get_area();
			a[i]->get_volume();
		}
	}
}

