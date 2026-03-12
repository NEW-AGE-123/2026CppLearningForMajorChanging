#include<iostream>
using namespace std;


int Plus(int a, int b);
int substract(int a, int b);
int cal(int (*p)(int, int), int a, int b);


int main()
{
	//定义
	int example = 0;
	int* p = &example;
	int* p1 = (int*)0x200;
	int** x = &p1;
	int a[5];
	p = a;

	int* p3 = nullptr;


	//*p与自增自减
	(*p)++; //相当于a++。表达式为3,a=4
	*p++;    // *p++首先*p ，然后p=p+1,指针指向b，表达式为3, p＝2004H
	++*p;     //相当于++(*p)，就是*p=*p+1，即a=4
	*++p;
	//指针减法差为所指数组元素下标差

	//二维数组
	int b[2][2] = { 1,2,3,4 };
	int (*p4)[2] = b;
	p4++;
	cout << *p4 << endl;
	cout << *p4 << endl;
	cout << p4[0] << endl;
	cout << p4[0] + 1 << endl;


	//使用函数指针
	int (*pf)(int, int) = Plus;
	cout << cal(pf, 2, 3) << endl;;


	//const用法
	const int* p5 = a;//表明a不可改变
	int* const p6 = a;//表面p5指向不能变
	const int* const p7 = a;


	//指针与字符串、
	char color[] = "blue";
	const char* colorPtr = "blue";
	char colorb[] = { 'b','l','u','e','\0' };
	cout << colorPtr + 1 << endl;//输出字符串
	cout << *colorPtr << endl;//输出字符

	//引用==起另一个名字

	//内存管理
	int* p8 = new int(20);
	int (*p9)[5] = new int[2][5];//*p9[5]指的是含有5个int元素的数组
	delete[] p9;
	delete p8;
}
int Plus(int a, int b)
{
	return a + b;
}
int substract(int a, int b)
{
	return a - b;
}

//函数指针
int cal(int (*p)(int, int), int a, int b)
{
	return (*p)(a, b);
}