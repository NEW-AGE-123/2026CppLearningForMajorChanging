// 02.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int main()
{
    char c[200];
    char a[100];
    char b[100];
    cin.getline(a, 100);
    cin.getline(b, 100);
    int length = strlen(a);

    for (int i = 0; i < length-1; i++)
    {
        c[i] = a[i];
    }
    c[length-1] = ',';
    int i = 0;
    for (i = length; i < length+strlen(b); i++)
    {
        c[i] = b[i - length];
    }
    c[i] = 0;
    for (int k = 0; k < i; k++)
    {
        if (c[k] >= 'a' && c[k] <= 'z') 
        {
            c[k] += 'A' - 'a';
        }
    }
    cout << c;
}

