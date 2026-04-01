#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;


void read(string& a)
{
	a = "";
	getline(cin, a);
}
void process(char* target, string order)
{
	stringstream iss(order);
	int n;
	iss >> n;
	switch (n)
	{
	case 1:
	{
		string temp;
		iss >> temp;
		iss.ignore();
		strcat(target, temp.c_str());
		cout << target << endl;
		break;
	}
	case 2:
	{
		int l1, l2;
		iss >> l1 >> l2;
		iss.ignore();
		char temp[300];
		strncpy(temp, target + l1, l2);
		temp[l2] = '\0';
		strcpy(target, temp);
		cout << target << endl;
		break;
	}
	case 3:
	{
		int location = -1;
		string tempstr;
		iss >> location >> tempstr;
		iss.ignore();
		char temp[300];
		strncpy(temp, target, location - 1);
		temp[location - 1] = '\0';
		strcat(temp, tempstr.c_str());
		strncat(temp, target + location, strlen(target - location));
		strcpy(target, temp);
		cout << target << endl;
		break;
	}
	}


}




int main()
{

	int counter = 0;
	cin >> counter;
	cin.ignore();
	char target[200];
	cin.getline(target, 200);

	for (int i = 0; i < counter; i++)
	{
		string order;
		read(order);
		process(target, order);
	}












}





