#pragma once
#include<iostream>
using namespace std;



class Grades
{

};

class Grade
{
	friend class Grades;//友员类
	friend void show(Grade& );//友元函数
public:
	static int counter;//初始化在类外进行
	//默认构造函数
	Grade();
	//前置构造函数
	Grade(int a, int b) :G_a(a), G_b(b)
	{
		counter++;
	}

	//复制构造函数
	Grade(const Grade& p)
	{
		G_a = p.G_a;
		G_b = p.G_b;
	}

	//set函数
	void set_G_a(int a)
	{
		G_a = a;
	}
	//get函数
	int get_G_a()
	{
		return G_a;
	}

	~Grade()
	{
		cout << "class grade was deleted." << endl;
	}
private:
	int G_a;
	int G_b;
};

void show(Grade &p)
{
	cout << p.G_a << " " << p.G_b << endl;
}

int Grade::counter = 0;//类外初始化静态成员