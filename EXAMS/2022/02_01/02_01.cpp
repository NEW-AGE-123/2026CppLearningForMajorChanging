// 02_01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#define SIZE 10
using namespace std;




template < typename T >
void sort(T* a,int size)
{
	for (int i = 0; i < size-1; i++)
	{
		for (int k = 0; k < size-1; k++)
		{
			if (a[k] > a[k + 1])
				swap(a[k], a[k + 1]);
		}
	}
}

template<typename T>
int Bsearch(T* a,int begin,int end, T target)
{
	int mid = (begin + end) / 2;
	if (a[mid]==target)
	{
		return mid;
	}
	if (a[mid] < target)
	{
		return Bsearch(a, mid + 1, end, target);
	}
	if (a[mid] > target)
	{
		return Bsearch(a, begin, mid-1, target);
	}
}


int main()
{
	int a[10] = { 7,3,9,8,0,2,4,4,8,2 };
	string b[10] = { "a","d","k","d","c","e","s","f","s","z" };
	sort(a, SIZE);
	sort(b, SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		cout << a[i];
	}
	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << b[i];
	}
	cout << endl;
	string target = "e";
	cout << "e" << Bsearch(b, 0, 9, target);
	cout << "7" << Bsearch(a, 0, 9, 7);
};
