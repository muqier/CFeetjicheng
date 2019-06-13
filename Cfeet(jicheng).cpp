// 2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream" 
using namespace std;
class CFeet
{
public:
	int foot;
	int inch;
public:
	CFeet();
	CFeet(int f, int i);
	int setFoot(int f, int i);
	~CFeet();
	void displayFoot();
	void display();
	void addOneFoot();
	int getFoot();
	int getInch();
	int check();
	CFeet addFoot(CFeet &od);
	CFeet operator + (CFeet&otemp);
	CFeet operator+(const int &d);
};
CFeet CFeet::operator + (CFeet&otemp)
{
	CFeet temp;
	temp.setFoot(foot + otemp.foot, inch + otemp.inch);
	return temp;
}
CFeet CFeet::addFoot(CFeet &od)
{
	CFeet temp;
	temp.setFoot(foot + od.foot, inch + od.inch);
	return temp;
}
CFeet::CFeet()
{
	foot = 1;
	inch = 12;
}
CFeet::CFeet(int f, int i)
{
	foot = f;
	inch = i;
	check();
}
int CFeet::setFoot(int f, int i)
{
	foot = f;
	inch = i;
	check();
	return 0;
}
CFeet::~CFeet()
{
	cout << "foot=" << foot << "inch=" << inch << endl;
}
void CFeet::displayFoot()
{
	cout << "foot=" << foot << "inch=" << inch << endl;
}
int CFeet::check()
{
	if (inch >= 12 && inch % 12 == 0)
	{
		foot++;
		return 0;
	}
	foot = foot + inch / 12;
	inch = inch % 12;
}
int CFeet::getFoot()
{
	return foot;
}
int CFeet::getInch()
{
	return inch;
}
void CFeet::addOneFoot()
{
	foot = foot + inch / 12;
	inch = inch % 12;
	if (inch >= 12 && inch % 12 == 0)
	{
		foot++;
	}
}
class CMylovefoot : public CFeet
{
public:
	CMylovefoot operator + (CFeet&otemp)
	{
		CMylovefoot temp;
		temp.setFoot(foot + otemp.foot, inch + otemp.inch);
		return temp;
	}

	CMylovefoot()
	{
		foot = 0;
		inch = 0;
		check();
	}
	CMylovefoot(int f, int i)
	{
		foot = f;
		inch = i;
		check();
	}
	void displayFoot()
	{
		cout << "foot=" << foot << "inch=" << inch << endl;
	}
	void display()
	{
		cout << "foot=" << foot << "inch=" << inch << endl;
	}
	void addOneFoot(CFeet &od)
	{
		CMylovefoot temp;
	}
	int getFoot()
	{
		return foot;
	}
	int getInch()
	{
		return inch;
	}
	int check()
	{
		if (inch >= 12 && inch % 12 == 0)
		{
			foot++;
			return 0;
		}
		foot = foot + inch / 12;
		inch = inch % 12;
	}
};
int main()
{
	CMylovefoot od1(2, 34), od2(6, 20), od3;
	od3 = od1 + od2;
	od1.displayFoot();
	od2.displayFoot();
	od3.displayFoot();
	return 0;
}