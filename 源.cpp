#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<cmath>
#include <windows.h>
using namespace std;

/*----------------------------------*
		  Global Varables
*-----------------------------------*/
class Triangle
{
private:
	double a, b, c; //����Ϊ˽�г�Ա����
public:
	void setABC(double x, double y, double z)
	{
		if ((x + y) > z && (x - y) < z)
		{
			cout << "�����ж���������ĸ�ʽ��ȷ��" << endl;
			a = x;
			b = y;
			c = z;
		}

		else cout << "�����ж���������ĸ�ʽ����ȷ��" << endl;
	};
	//�����ߵ�ֵ��ע��Ҫ�ܳ�������
	void getABC(double *x, double *y, double *z)
	{
		*x = a;
		*y = b;
		*z = c;
	};//ȡ���ߵ�ֵ
	double perimeter(void)
	{
		double ce;
		ce = a + b + c;
		return ce;
	}//���������ε��ܳ�
	double area(void )
	{
		double s;
		double p;
		p = (a + b + c) / 2;
		s = sqrt(p*(p - a)*(p - b)*(p - c));
		return s;
	}
	//���㲢���������ε����
	double vary(void )
	{
		double t, V;
		if (a > b)
			if (a > c)
				t = a;
			else t = c;
		if (a < b)
		{
			if (b > c)
				t = b;
			else t = c;
		}
		V  = cos( b*b + c * c - t * t / 2 * b*c);
		return V;
	}
	void display()
	{
		cout << "���øú����Ķ����thisָ����";
		cout << this << endl;                             	//�����ǰ��������ĵ�ַ     
		cout << "��ǰ����a��Ա����ʼ��ַ: ";         	//�����ǰ�����a��Ա�ĵ�ַ
		cout << &this->a << endl;
		cout << "��ǰ����b��Ա����ʼ��ַ: ";        	//�����ǰ�����b��Ա�ĵ�ַ
		cout << &this->b << endl;
		cout << "��ǰ����c��Ա����ʼ��ַ: ";        	//�����ǰ�����b��Ա�ĵ�ַ
		cout << &this->c << endl;
		cout << "a=" << this->a  << " ,b=" << this->b<<"  ,c="<<this->c << endl;  //���this��ָ��������ݳ�Աֵ
	}

};

/*----------------------------------*
		  Main Function
*-----------------------------------*/

int main()
{

	Triangle tri1 ,tri2;	//�������������һ��ʵ��������
    double x, y, z, V;
	cout << "�����������ε����ߣ�" << endl;
	cin >> x >> y >> z;//֤����Ķ���ʵ���洢���ǳ�Ա����
	cout << "tri1��ռ���ڴ�Ϊ=" << sizeof(tri1) << endl;
	if ((x + y) > z && (x - y) < z)
	{
		tri1.setABC(x, y, z);	//Ϊ�����ó�ֵ
		tri1.getABC(&x, &y, &z);   //�����ߵ�ֵΪx,y,z��ֵ
		cout << "������Ϊ��" << x << '\t' << y << '\t' << z << endl;
		cout << "�����ε��ܳ�Ϊ��" << tri1.perimeter() << endl;
		cout<<"���Ϊ��" << tri1.area() << '\t' << endl;
		V = tri1.vary();
		if (V > 0)
			cout << "��������Ϊ�۽�������" << endl;
		else if (V < 0)
			cout << "��������Ϊ���������" << endl;
		else
			cout << "��������Ϊֱ��������" << endl;
	}

	else cout << "�����ж���������ĸ�ʽ����ȷ��" << endl;

	//�����ߵ�ֵ��ע��Ҫ�ܳ�������
	tri2.setABC(3, 4, 5);	//Ϊ�����ó�ֵ
	cout << "DateA��ַ:" << &tri1<< endl;              //�������DateA�ĵ�ַ     
	tri1.display();
	cout << "DateB��ַ:" << &tri2 << endl;  
	tri2.display();                  //�������DateB�ĵ�ַ  
	system("pause");

	return 0;
}