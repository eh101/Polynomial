#include<iostream>
#include<string>
#include"Polynomial.h"
using namespace std;

int main()
{
	Polynomial A, B, C, D;
	float coef, exp;
	//多项式A的输入
	cout << "请输入多项式A,输入非数字结束\n";
	for (int i = 1;; i++)
	{
		cout << "-----------------------------\n";
		cout << "请输入第" << i << "项系数：";
		if (!(cin >> coef))
		{
			cout << "-----------------------------\n";
			cout << "输入结束！\n";
			break;
		}
		cout << "请输入第" << i << "项指数：";
		cin >> exp;
		Item item(coef, exp);
		A.superAdd(item);
	}
	//多项式B的输入
	cin.clear();
	cin.sync();
	cout << "请输入多项式B,输入非数字结束\n";
	for (int i = 1;; i++)
	{
		cout << "-----------------------------\n";
		cout << "请输入第" << i << "项系数：";
		if (!(cin >> coef))
		{
			cout << "-----------------------------\n";
			cout << "输入结束！\n";
			break;
		}
		cout << "请输入第" << i << "项指数：";
		cin >> exp;
		Item item(coef, exp);
		B.superAdd(item);
	}
	cout << "A = " << A << endl;
	cout << "B = " << B << endl;
	C = A + B;
	cout << "C = A+B = " << C << endl;
	D = A - B;
	cout << "D = A-B = " << D << endl;
}