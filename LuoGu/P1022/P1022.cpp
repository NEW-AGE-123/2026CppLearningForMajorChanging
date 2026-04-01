// P1022.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;





int main()
{
	int changshu = 0;
	int xishu = 0;
	int xiang = 0;
	int now = 1, f = 1, r = 0;
	char a, c;

	while (cin >> a)
	{
		if (a == '+')
		{
			if (xiang != 0)
			{
				changshu += xiang * f * now;
				xiang = 0;
			}
			f = 1; r = 0;
		}
		if (a == '-')
		{
			if (xiang != 0)
			{
				changshu += xiang * f * now;
				xiang = 0;

			}
			f = -1; r = 0;
		}
		if (a == '=')
		{
			if (xiang != 0)
			{
				changshu += xiang * f * now;
				xiang = 0;
			}
			f = 1; r = 0;
			now = -1;
		}
		if (a <= '9' && a >= '0') { xiang = xiang * 10 + a - '0'; r = 1; }
		if (a <= 'z' && a >= 'a')
		{
			c=a;
			if (r == 0)
			{
				xiang = 1;
			}
			xishu += xiang * now*f;
			xiang = 0;
		}
	}
	if (xiang != 0)
	{
		changshu += xiang * f * now;
		xiang = 0;

	}


	cout <<c<<"=" <<fixed<<setprecision(3)<<(double(changshu) / xishu)? double(changshu) / xishu:0;
}