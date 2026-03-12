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
    for (int item : items)
    {
        cout << item;
    }
    cout << endl;

    //对array排序，查找
    sort(items.begin(), items.end());
    int a[5] = { 1,2,33,44,11 };
    sort(&a[0], &a[5]);



    binary_search(items.begin(), items.end(), 5);
    for (int item : items)
    {
        cout << item;
    }



    //vector
    vector<int> example;
    example.size();//访问大小
    example.empty();//判断是否为空
    example.push_back(1);//在末尾添加元素
    example.pop_back();//删除末尾元素
    example.front();//访问第一个元素
    example.back();//访问最后一个元素
    example[0];//访问元素
    example.insert(example.begin() + 1, 2, 5);//在第一个元素前插入2个5
    example.erase(example.begin(), example.begin() + 2);//删除前两个元素 注意不是前三个，是左闭右开

}

