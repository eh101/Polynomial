#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
using namespace std;

//多项式的项的类
typedef class Item *PItem;
class Item
{
public:
	float Coef;
	float Exp;
	Item* Next;
	//构造函数
	Item(float coef = 0, float exp = 0);
	//拷贝构造函数
	Item(const Item& item);
};
//多项式类
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