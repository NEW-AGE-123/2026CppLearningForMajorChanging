#include <iostream>
#include "TagList.h"

int main() {
    // 1. 测试构造函数与有效性过滤
    std::string arr1[] = { "C++", "Python", "", "Java", "C++", "Rust" };
    std::string arr2[] = { "Java", "Go", "Python" };

    TagList list1(arr1, 6);
    std::cout << "List 1 (init): " << list1 << "\n";
    // 预期输出: <C++, Python, Java, Rust>

    TagList list2(arr2, 3);
    std::cout << "List 2 (init): " << list2 << "\n";
    // 预期输出: <Java, Go, Python>

    // 2. 测试拷贝构造与 operator-
    TagList list3 = list1;
    TagList list4 = list1 - list2;
    std::cout << "List 1 - List 2: " << list4 << "\n";
    // 预期输出: <C++, Rust>

    // 3. 测试 operator-= 与拷贝赋值
    list3 -= list2;
    std::cout << "List 3 after -= List 2: " << list3 << "\n";
    // 预期输出: <C++, Rust>

    list4 = list4; // 测试自我赋值

    // 4. 测试自增运算符
    std::cout << "\n--- 测试自增 ---" << std::endl;
    TagList list_inc = list1++;
    std::cout << "list1++ returns: " << list_inc << "\n";
    // 预期输出: <C++, Python, Java, Rust>

    std::cout << "List 1 is now: " << list1 << "\n";
    // 预期输出: <C++, Python, Java, Rust, Mastered>

    TagList list_inc2 = ++list1;
    std::cout << "++list1 returns: " << list_inc2 << "\n";
    // 预期输出: <C++, Python, Java, Rust, Mastered> (不重复添加)

    // 5. 测试自减运算符
    std::cout << "\n--- 测试自减 ---" << std::endl;
    TagList list_dec = list1--;
    std::cout << "list1-- returns: " << list_dec << "\n";
    // 预期输出: <C++, Python, Java, Rust, Mastered>

    std::cout << "List 1 is now: " << list1 << "\n";
    // 预期输出: <C++, Python, Java, Rust>

    --list1;
    std::cout << "After --list1: " << list1 << "\n";
    // 预期输出: <C++, Python, Java>

    return 0;
}