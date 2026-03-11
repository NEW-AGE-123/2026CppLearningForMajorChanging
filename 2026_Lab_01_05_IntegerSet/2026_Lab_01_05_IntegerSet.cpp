// 2026_Lab_01_05_IntegerSet.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;



class IntegerSet
{
    friend ostream& operator<<(ostream& output, IntegerSet a);
public:
    IntegerSet()
    {
        for (int i = 0; i < 100; i++)
        {
            numbers[i] = 0;
        };
    }
    IntegerSet(int* a, int n)
    {
        for (int i = 0; i < 100; i++)
        {
            numbers[i] = 0;
        };
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= 1 && a[i] <= 100)
            {
                numbers[a[i] - 1] = 1;
            }
        }
    }
    IntegerSet unionOfSets(IntegerSet a)
    {
        return *this + a;
    }
    IntegerSet intersectionOfSets(IntegerSet a)
    {
        return *this - a;
    }
    IntegerSet operator+(IntegerSet a)
    {
        IntegerSet temp;
        for (int i = 0; i < 100; i++)
        {
            temp.numbers[i] = ((this->numbers[i]) || (a.numbers[i]));
        }
        return temp;
    }    
    IntegerSet operator-(IntegerSet a)
    {
        IntegerSet temp;
        for (int i = 0; i < 100; i++)
        {
            temp.numbers[i] = ((this->numbers[i]) && (a.numbers[i]));
        }
        return temp;
    }
    void InsetElement(int m)
    {
        if (m>=1&&m<=100)
        {
            numbers[m - 1] = 1;
        }
    }    
    void DeleteElement(int m)
    {
        if (m >= 1 && m <= 100)
        {
            numbers[m - 1] = 0;
        }
    }
    void inputElement()
    {
        int a;
        int i = 0;
        cout << "Entering Set:" << endl;
        cout << "Entering Element"<<i<<"(-1 to end):";
        cin >> a;
        while ((a >= 1 && a <= 100) && a != -1)
        {
            numbers[a - 1] = 1;
            i++;
            cout << "Entering Element" << i << "(-1 to end):";
            cin >> a;
        }

    }
    bool isEqual(IntegerSet a)
    {
        for (int i = 0; i < 100; i++)
        {
            if (this->numbers[i] != a.numbers[i]) {
                return 0;
            }
        }
        return 1;
    }


private:
    bool numbers[100];
};

ostream& operator<<(ostream& output, IntegerSet a)
{
    cout << "Members:{";
    for (int i = 0; i < 100; i++)
    {
        if (a.numbers[i] == 1) {
            output << i + 1<<" ";
        }
    }
    cout << "}" << endl;;
    return output;
}


int main()
{
    IntegerSet a;
    a.inputElement();
    cout << a;
    IntegerSet b;
    b.inputElement();
    cout << b;
    cout << a + b;
}
