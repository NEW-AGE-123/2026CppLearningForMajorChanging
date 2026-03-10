#include<iostream>
using namespace std;


class Kard
{
	/*friend ostream& operator<<(ostream&, Kard&);
	friend istream& operator>>(istream&, Kard&);
	friend Kard& operator++(Kard&);
	friend Kard operator++(Kard&, int);
	*/
	friend ostream& operator<<(ostream&, const Kard&);
	friend istream& operator>>(istream&, Kard&);
	friend Kard& operator--(Kard&);
	friend Kard operator--(Kard&, int);
public:
	int value;

	//函数方法调用
	Kard operator+(Kard& p)
	{
		Kard temp;
		temp.value = this->value + p.value;
		return temp;
	}
	Kard& operator++()
	{
		color++;
		return *this;
	}
	Kard operator++(int a)
	{
		Kard temp = *this;
		color++;
		return temp;
	}
	Kard operator=(Kard& p)
	{
		p.color = this->color;
	}
private:
	int color = 10;
};
//全局函数实现重载
/*
Kard operator+(Kard& p1, Kard& p2)
{
	Kard temp;
	temp.value = p1.value + p2.value;
	return temp;
}


*/
//左移运算符重载
ostream& operator<<(ostream& out, const Kard& p)
{
	out << "p.value=" << p.value << " p.color=" << p.color;
	return out;
}
//右移运算符重载
istream& operator>>(istream& input, Kard& p)
{
	input >> p.value >> p.color;
	return input;
}
/*
//自增运算符重载  &非常关键
Kard& operator++(Kard &p)
{
	p.color++;
	return p;
}

//自增运算符重载  后置递增，以参数int 为标志
Kard operator++(Kard& p,int a)
{
	Kard temp = p;
	p.color++;
	return temp;
}
*/
//自减运算符重载
Kard& operator--(Kard& p)
{
	p.color--;
	return p;
}
Kard operator--(Kard& p, int a)
{
	Kard temp = p;
	p.color--;
	return temp;
}

int main()
{
	Kard a;
	Kard b;
	a.value = 10;
	b.value = 20;
	Kard c;
	c = a + b;

	cout << c << endl;
	cin >> c;
	cout << c << endl;
	++c;
	c++;
	cout << --c << endl;
	cout << c-- << endl;
	cout << c << endl;

}