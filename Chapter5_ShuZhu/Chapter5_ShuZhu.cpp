// Chapter5_ShuZhu.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <random>
#include<ctime>
#include<string.h>
#include <string>
#include <sstream>
#define N 100
using namespace std;


void print(int a[])
{
    for (int i = 0; i < 100; i++)
    {
        cout << a[i] << " ";
    }
    cout << "end." << endl;

}


void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int k = 0; k < n-1; k++)
        {
            if (a[k] >= a[k + 1]) {
                swap(a[k], a[k + 1]);
            }
        }
    }
}

void SelectionSort(int a[],int n)
{
    int i = 0, j = 0, k = 0;
    for (int i = 0; i < n-1; i++)
    {
        k = i;
        for (int j = i+1; j < n; j++) 
        {
            if (a[k]>a[j])
            {
                k = j;
            }
        }
        swap(a[k], a[i]);
    }
}

int BSearch_core(int a[],int x,int left, int right)
{
    int mid = (left + right) / 2;
    if (left>right)
    {
        return -1;
    }
    if (a[mid]<x)
    {
        return BSearch_core(a, x, mid+1, right);
    }
    if (a[mid] > x)
    {
        return BSearch_core(a, x, left, mid-1);
    }
    if (a[mid] == x)
    {
        return mid+1;
    }
}

int gcd(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

int gbs(int a, int b)
{
    return a * b / gcd(a, b);
}



void read()
{
    /*
    string a;
    char b[20];
    cin.getline(b, 20);
    getline(cin,a);
    */
    string data;
    getline(cin, data);
    istringstream iss(data);
    string word[20];
    int k = 0;
    string temp;
    while (iss>>temp)
    {
        word[k++] = temp;
    }

    for (int i = 0; i < k; i++)
    {
        cout << word[i] << "::";
    }


}






int main()
{


    default_random_engine engine(static_cast<unsigned int>(time(0)));
    uniform_int_distribution <unsigned int> randomInt(1, 120);
    read();

    int target[100];
    for (int i = 0; i < 100; i++)
    {
        target[i] = randomInt(engine);
    }
    print(target);
    SelectionSort(target, 100);
    print(target);
    cout<<BSearch_core(target, 100, 0, 99);




    //二维数组
    int b[2][2] = { {2,2},{2,2} };
    int c[2][2] = { 2,2,2,2 };

    static int d[2][2];//static数组未初始化每一项为0
    int e[2][2] = { {2},{2} };//部分赋值，使得e[1][0]=2,e[2][0]=2

    cout << endl;
    cout << gcd(15, 20);


    char s1[90] = { "I love China." };
    char s2[90] = { "I don't love America." };

    strcpy(s1, s2);                                      //字符串复制
    strncpy(s1, s2, 5);                                  //字符串部分复制
    strcat_s(s1, s2);                                      //字符串拼接
    cout<<strncat(s1, s2, 5);                            //字符串部分拼接，将s2前n个字符凭借到s1
    cout<<strcmp(s1, s2);                                //字符串比较，前大于后输出1
    cout<<strlen(s1);
    char *temp;
    temp = strtok(s1, " ");
    while (temp!=NULL)
    {
        cout << temp << ":";
        temp = strtok(NULL, " ");
    }

}
