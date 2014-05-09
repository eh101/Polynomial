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
	//����"+"�����
	friend Polynomial operator +(Polynomial &, Polynomial &);
	//����"-"�����
	friend Polynomial operator -(Polynomial &, Polynomial &);
	//�������
	friend ostream &operator<<(ostream &out, const Polynomial &Poly);
	//����ӵ�ͬʱ������ͺϲ�ͬ�����ɾ���ϲ���ϵ��Ϊ0����ʳ�superAdd
	void superAdd(Item);
};
#endif