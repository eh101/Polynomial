#include"Polynomial.h"
#include<iostream>
using namespace std;

//Item�Ĺ��캯��
Item::Item(float coef, float exp)
{
	Coef = coef;
	Exp = exp;
	Next = NULL;
}

//Item�Ŀ������캯����������ָ����
Item::Item(const Item& item)
{
	Coef = item.Coef;
	Exp = item.Exp;
	Next = NULL;
}
//Polynomial�Ĺ��캯��
Polynomial::Polynomial()
{
	polynomial = new Item();//����ͷ�ڵ�
}

//����ӵ�ͬʱ������ͺϲ�ͬ�����ɾ���ϲ���ϵ��Ϊ0����ʳ�superAdd
void Polynomial::superAdd(Item inItem)//��˴�������ǵ�ַ������ʹ��ͬһ��������ʱ��ı�ԭ����ֵ
{
	PItem item = new Item(inItem);
	if (item->Coef == 0)//ϵ��Ϊ0��ֱ�ӷ�������
		return;
	if (polynomial->Next == NULL)//��ǰ����ʽ��û���ֱ����ͷ�ڵ�����item
	{
		polynomial->Next = item;
		return;
	}
	PItem temp = polynomial;//��ʱָ�룬����ѭ������
	while (temp->Next != NULL)
	{
		if (item->Exp < temp->Next->Exp)//��ָ��С��temp->Next->Exp��ǰ�����item
		{
			item->Next = temp->Next;
			temp->Next = item;
			return;
		}
		else if (temp->Next->Exp == item->Exp)//item��ָ�������ʽ�е�ĳ����ͬ���ϲ����ǵ�ϵ��
		{
			temp->Next->Coef += item->Coef;
			delete item;
			if (temp->Next->Coef == 0)//���ϲ���ϵ��Ϊ�㣬��ɾ������
			{
				PItem p = temp->Next;
				temp->Next = temp->Next->Next;
				delete p;
			}
			return;
		}
		temp = temp->Next;
	}
	temp->Next = item;//ִ�е�����˵��item->Exp���ڶ���ʽ�е�����ϵ�����ʽ���������һ�������
}

//����"+"�����
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

//����"-"�����
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

//�������
ostream &operator<<(ostream &out, const Polynomial &Poly)
{
	if (Poly.polynomial->Next == NULL)//���PolyΪ�����������"0"
		return out << 0;
	PItem temp = Poly.polynomial->Next;//��ʱָ�룬����ѭ������

	//����ĵ�һ���Ҫ"+"��
	if (temp->Exp == 0)//ָ��Ϊ�㲻���"X^"
		out << temp->Coef;
	else if (temp->Coef == 1)//ϵ��Ϊ1�������1
		out << "X^" << temp->Exp;
	else if (temp->Coef == -1)//ϵ��Ϊ-1��ֻ�������"-"
		out << "-X^" << temp->Exp;
	else
		out << temp->Coef << "X^" << temp->Exp;//ϵ����Ϊ1�����temp->Coef
	temp = temp->Next;
	//����ڶ������еĻ�
	while (temp != NULL)
	{
		if (temp->Coef > 0)//ϵ������0�����"+"��
		{
			out << "+";
			if (temp->Exp == 0)//ָ��Ϊ�㲻���"X^"
				out << temp->Coef;
			else if (temp->Coef == 1)//ϵ��Ϊ1�������1
				out << "X^" << temp->Exp;
			else if (temp->Coef == -1)//ϵ��Ϊ-1��ֻ�������"-"
				out << "-X^" << temp->Exp;
			else
				out << temp->Coef << "X^" << temp->Exp;//ϵ����Ϊ1�����temp->Coef
		}
		else
			if (temp->Exp == 0)//ָ��Ϊ�㲻���"X^"
				out << temp->Coef;
			else if (temp->Coef == 1)//ϵ��Ϊ1�������1
				out << "X^" << temp->Exp;
			else if (temp->Coef == -1)//ϵ��Ϊ-1��ֻ�������"-"
				out << "-X^" << temp->Exp;
			else
				out << temp->Coef << "X^" << temp->Exp;//ϵ����Ϊ1�����temp->Coef
			temp = temp->Next;
	}
	return out;
}