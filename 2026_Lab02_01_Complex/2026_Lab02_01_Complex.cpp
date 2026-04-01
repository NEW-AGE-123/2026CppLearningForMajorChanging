// 2026Lab01_01_Complex.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;



class complex
{
public:
	friend ostream& operator<<(ostream& output, complex p);
	friend istream& operator>>(istream& input, complex &p);
	complex() {
		realPart = 0;
		imaginePart = 0;
	}
	complex(double a, double b)
	{
		this->realPart = a;
		this->imaginePart = b;
	}

	complex operator+(complex p)
	{
		complex temp;
		temp.realPart = p.realPart + this->realPart;
		temp.imaginePart = p.imaginePart + this->imaginePart;
		return temp;
	}
	complex operator-(complex p)
	{
		complex temp;
		temp.realPart = realPart - p.realPart;
		temp.imaginePart = imaginePart - p.imaginePart;
		return temp;
	}
	complex operator*(const complex &p)
	{
		complex temp(realPart * p.realPart - imaginePart * p.imaginePart, imaginePart * p.realPart + realPart * p.imaginePart);
		return temp;
	}
	bool operator==(const complex& p)
	{
		if (realPart == p.realPart && imaginePart == p.imaginePart)
		{
			return 1;
		}
		return 0;
	}
	bool operator!=(const complex& p)
	{
		if (realPart == p.realPart && imaginePart == p.imaginePart)
		{
			return 0;
		}
		return 1;
	}

private:
	double realPart;
	double imaginePart;
};

ostream& operator<<(ostream& output, complex p)
{
	output << "(" << p.realPart << "," << p.imaginePart << ")";
	return output;
}
\

istream& operator>>(istream& input, complex &p)
{
	char ch1,ch2,ch3;
	input >> ch1 >> p.realPart >> ch2 >> p.imaginePart >> ch3;
	cout << ch1 << ch2 << ch3 << p.realPart << p.imaginePart << endl;
	return input;
}







int main()
{
	complex x, y(4.3, 8.2), z(3.3, 1.1), k;
	cout << "Enter a complex number in the form: (a, b)\n? ";
	cin >> k; // demonstrating overloaded >> 
	cout << "x: " << x << "\ny: " << y << "\nz: " << z << "\nk: "
		<< k << '\n'; // demonstrating overloaded << 
	x = y + z; // demonstrating overloaded + and = 
	cout << "\nx = y + z:\n" << x << " = " << y << " + " << z << '\n';
	x = y - z; // demonstrating overloaded - and = 
	cout << "\nx = y - z:\n" << x << " = " << y << " - " << z << '\n';
	x = y * z; // demonstrating overloaded * and = 
	cout << "\nx = y * z:\n" << x << " = " << y << " * " << z << "\n\n";
	if (x != k) // demonstrating overloaded != 
		cout << x << " != " << k << '\n';
	cout << '\n';
	x = k;
	if (x == k) // demonstrating overloaded == 
		cout << x << " == " << k << '\n';
	return 0;
}

