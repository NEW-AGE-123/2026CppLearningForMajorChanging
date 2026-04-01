// 03.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;



bool compareUP(char a, char b)
{
	if (a > b)
	{
		return 1;
	}
	return 0;
}
bool compareDOWN(char a, char b)
{
	if (a < b)
	{
		return 1;
	}
	return 0;
}

void sort(char *a, bool (ptr)(char, char))
{
	for (int i = 0; i < strlen(a)-1; i++)
	{
		for (int k = 0; k < strlen(a)-1; k++)
		{
			if (ptr(a[k], a[k + 1]))
			{
				swap(a[k], a[k + 1]);
			}
		}
	}
}
int wash(char *a)
{
	int counter = 0;
	char temp[200];
	for (int  i = 0; i < strlen(a); i++)
	{
		if ((a[i] <= 'z'&&a[i] >= 'a') || (a[i] <= 'Z'&&a[i] >= 'A'))
		{
			if (a[i] <= 'Z'&&a[i] >= 'A')
			{
				a[i] += 'a' - 'A';
			}
			temp[counter++] = a[i];
		}
	}
	strncpy(a, temp, counter);
	a[counter] = 0;
	return counter;
}



int main()
{
	char a[200];
	cin.getline(a, 200);
	char firstHalf[200], secondHalf[200];
	wash(a);
	int length = strlen(a),mid;
	mid = length-length / 2;
	strncpy(firstHalf, a, mid);
	firstHalf[mid] = 0;
	strncpy(secondHalf, a + mid, length - mid);
	secondHalf[length - mid] = 0;
	cout << firstHalf << endl;
	cout << secondHalf << endl;
	sort(firstHalf, compareUP);
	sort(secondHalf,compareDOWN);
	cout << firstHalf << endl;
	cout << secondHalf << endl;
}

