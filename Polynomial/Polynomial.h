#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
using namespace std;

typedef class Item *PItem;
class Item
{
public:
	float Coef;
	float Exp;
	Item* Next;
	Item(float coef = 0, float exp = 0);
	Item(const Item& item);
};

class Polynomial
{
	PItem polynomial;
public:
	Polynomial();
	//重载"+"运算符
	friend Polynomial operator +(Polynomial &, Polynomial &);
	//重载"-"运算符
	friend Polynomial operator -(Polynomial &, Polynomial &);
	//重载输出
	friend ostream &operator<<(ostream &out, const Polynomial &Poly);
	//在添加的同时可排序和合并同类项，并删除合并后系数为0的项，故称superAdd
	void superAdd(Item);
};
#endif