// Chapter7_array_vector.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<array>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    const size_t ARRAY_SIZE = 10;
    //声明array对象
    array<int, ARRAY_SIZE> Temp;
    static array<int, ARRAY_SIZE> Temp2;//默认元素都为0

    //基于范围的for语句
    array<int, 5> items = { -2,2,99,4,5 };
    for (int item:items)
    {
        cout << item;
    }
    cout << endl;

    //对array排序，查找
    sort(items.begin(), items.end());
    int a[5] = { 1,2,33,44,11 };
    sort(&a[0], &a[5]);



    binary_search(items.begin(),items.end(), 5);
    for (int item : items)
    {
        cout << item;
    }


    

}

