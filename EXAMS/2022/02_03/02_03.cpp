#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


#include <string.h>

using namespace std;

class Date {
	friend class Customer;
public:
	Date(int a, int b, int c)
		:year(a), month(b), day(c)
	{}

private:
	int year;
	int month;
	int day;
};

class Items {
public:
	friend class Customer;
	Items(const char* a, int  b, double c)
	{
		strcpy(item_name,a);
		number = b;
		price = c;
	}

private:
	char item_name[20];
	int number;
	double price;
};

class Customer {
public:
	Customer(string theid, Date a)
		:id(theid), time(a),total(0),counter(0)
	{
		cout << "Customer ID:" << id << endl;
		cout << "Purchase Date : " << a.year << "-" << a.month << "-" << a.day << endl;
		cout << "The Purchase items are listed as follows : " << endl;
	}
	void selectItem(const char* a, int b, double c)
	{
		Items c1(a, b, c);
		total += c1.number * c1.price;
		counter++;
		cout << counter << ": itemName: " << c1.item_name << ", number : " << c1.number << ",price : " << c1.price << ", amount : " << total << endl;
	}
	void print()
	{
		cout << "The total amount of the Purchase items is " << total;
	}
private:
	Date time;
	int counter;
	double total;
	string id;
};

auto main() -> int {
	Date d1(2022, 6, 18);
	Customer c1("11000001", d1);
	c1.selectItem("cup", 2, 9.2);
	c1.selectItem("jacket", 1, 50);
	c1.selectItem("steak", 3, 10);
	c1.print();
	return 0;
}