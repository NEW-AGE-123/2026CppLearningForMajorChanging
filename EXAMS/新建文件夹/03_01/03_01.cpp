// 03_01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<sstream>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;






bool if_right(int n)
{
	int temp[20]; 
	for (int &a:temp)
	{
		a = -1;
	}
	int a = n;
	int i;
	for (i = 0; i < 20; i++)
	{
		temp[i] = a % 10;
		a = a / 10;
		if (a<1)
		{
			break;
		}
	}
	int length = i + 1;
	for (int k = 0; k < length; k++)
	{
		stringstream iss1;
		stringstream iss2;
		for (int i = 0; i < k; i++)
		{
			iss1 << temp[k-i-1];
		}
		for (int i = k; i < length; i++)
		{
			iss2 << temp[length - i - 1+k];
		}
		/*
		string s1 = iss1.str();
		string s2 = iss2.str();
		cout << s1 << " " << s2 << endl;
		*/
		int tempstr;
		iss1 >> tempstr;
		int tempstr2;
		iss2 >> tempstr2;
		
		if (sqrt(n)==tempstr+tempstr2)
		{
			return 1;
		}
		
	}
	return 0;




	return 1;
}


bool is_right_str(int n)
{
	stringstream iss;
	iss << n;
	string temp;
	iss >> temp;
	for (int i = 0; i < temp.size(); i++)
	{
		string a = temp.substr(0,i);
		string b = temp.substr(i, temp.size());
		int a1 = atoi(a.c_str());
		int b1 = atoi(b.c_str());
		if (a1 + b1 == sqrt(n))
			return 1;
	}
	return 0;
}

int main()
{
	for (int i = 1; i < 10001; i++)
	{
		if (is_right_str(i * i)) {
			cout << i << endl;
		}
	}
}

