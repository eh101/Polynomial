#include<iostream>
#include<string>
#include"Polynomial.h"
using namespace std;

int main()
{
	Polynomial A, B, C, D;
	float coef, exp;
	//����ʽA������
	cout << "���������ʽA,��������ֽ���\n";
	for (int i = 1;; i++)
	{
		cout << "-----------------------------\n";
		cout << "�������" << i << "��ϵ����";
		if (!(cin >> coef))
		{
			cout << "-----------------------------\n";
			cout << "���������\n";
			break;
		}
		cout << "�������" << i << "��ָ����";
		cin >> exp;
		Item item(coef, exp);
		A.superAdd(item);
	}
	//����ʽB������
	cin.clear();
	cin.sync();
	cout << "���������ʽB,��������ֽ���\n";
	for (int i = 1;; i++)
	{
		cout << "-----------------------------\n";
		cout << "�������" << i << "��ϵ����";
		if (!(cin >> coef))
		{
			cout << "-----------------------------\n";
			cout << "���������\n";
			break;
		}
		cout << "�������" << i << "��ָ����";
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