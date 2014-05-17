#include"Polynomial.h"
#include<iostream>
using namespace std;

//Item的构造函数
Item::Item(float coef, float exp)
{
	Coef = coef;
	Exp = exp;
	Next = NULL;
}

//Item的拷贝构造函数（不拷贝指针域）
Item::Item(const Item& item)
{
	Coef = item.Coef;
	Exp = item.Exp;
	Next = NULL;
}
//Polynomial的构造函数
Polynomial::Polynomial()
{
	polynomial = new Item();//申请头节点
}

//在添加的同时可排序和合并同类项，并删除合并后系数为0的项，故称superAdd
void Polynomial::superAdd(Item inItem)//如此处传入的是地址，则多次使用同一参数插入时会改变原参数值
{
	PItem item = new Item(inItem);
	if (item->Coef == 0)//系数为0，直接放弃插入
		return;
	if (polynomial->Next == NULL)//当前多项式中没有项，直接在头节点后插入item
	{
		polynomial->Next = item;
		return;
	}
	PItem temp = polynomial;//临时指针，用于循环查找
	while (temp->Next != NULL)
	{
		if (item->Exp < temp->Next->Exp)//在指数小于temp->Next->Exp的前面插入item
		{
			item->Next = temp->Next;
			temp->Next = item;
			return;
		}
		else if (temp->Next->Exp == item->Exp)//item的指数与多项式中的某项相同，合并它们的系数
		{
			temp->Next->Coef += item->Coef;
			delete item;
			if (temp->Next->Coef == 0)//若合并后系数为零，则删除该项
			{
				PItem p = temp->Next;
				temp->Next = temp->Next->Next;
				delete p;
			}
			return;
		}
		temp = temp->Next;
	}
	temp->Next = item;//执行到该条说明item->Exp大于多项式中的所有系数，故将其插入最后一个项后面
}

//重载"+"运算符
Polynomial operator +(Polynomial &P1, Polynomial &P2){
	Polynomial poly;
	PItem p1 = P1.polynomial->Next, p2 = P2.polynomial->Next;
	while (p1 != NULL)
	{
		poly.superAdd(*p1);
		p1 = p1->Next;
	}
	while (p2 != NULL)
	{
		poly.superAdd(*p2);
		p2 = p2->Next;
	}
	return poly;
}

//重载"-"运算符
Polynomial operator -(Polynomial &P1, Polynomial &P2){
	Polynomial poly;
	PItem p1 = P1.polynomial->Next, p2 = P2.polynomial->Next;
	while (p1 != NULL)
	{
		p1->Coef = p1->Coef;
		poly.superAdd(*p1);
		p1 = p1->Next;
	}
	while (p2 != NULL)
	{
		p2->Coef = -p2->Coef;
		poly.superAdd(*p2);
		p2 = p2->Next;
	}
	return poly;
}

//重载输出
ostream &operator<<(ostream &out, const Polynomial &Poly)
{
	if (Poly.polynomial->Next == NULL)//如果Poly为空则输出返回"0"
		return out << 0;
	PItem temp = Poly.polynomial->Next;//临时指针，用于循环查找

	//输出的第一项不需要"+"号
	if (temp->Exp == 0)//指数为零不输出"X^"
		out << temp->Coef;
	else if (temp->Coef == 1)//系数为1，不输出1
		out << "X^" << temp->Exp;
	else if (temp->Coef == -1)//系数为-1，只输出负号"-"
		out << "-X^" << temp->Exp;
	else
		out << temp->Coef << "X^" << temp->Exp;//系数不为1，输出temp->Coef
	temp = temp->Next;
	//输出第二项，如果有的话
	while (temp != NULL)
	{
		if (temp->Coef > 0)//系数大于0需输出"+"号
		{
			out << "+";
			if (temp->Exp == 0)//指数为零不输出"X^"
				out << temp->Coef;
			else if (temp->Coef == 1)//系数为1，不输出1
				out << "X^" << temp->Exp;
			else if (temp->Coef == -1)//系数为-1，只输出负号"-"
				out << "-X^" << temp->Exp;
			else
				out << temp->Coef << "X^" << temp->Exp;//系数不为1，输出temp->Coef
		}
		else
			if (temp->Exp == 0)//指数为零不输出"X^"
				out << temp->Coef;
			else if (temp->Coef == 1)//系数为1，不输出1
				out << "X^" << temp->Exp;
			else if (temp->Coef == -1)//系数为-1，只输出负号"-"
				out << "-X^" << temp->Exp;
			else
				out << temp->Coef << "X^" << temp->Exp;//系数不为1，输出temp->Coef
			temp = temp->Next;
	}
	return out;
}