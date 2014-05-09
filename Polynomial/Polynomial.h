#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
using namespace std;

//����ʽ�������
typedef class Item *PItem;
class Item
{
public:
	float Coef;
	float Exp;
	Item* Next;
	//���캯��
	Item(float coef = 0, float exp = 0);
	//�������캯��
	Item(const Item& item);
};
//����ʽ��
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