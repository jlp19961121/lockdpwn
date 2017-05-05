/*
	���α�(������� ��ų����)���� ���� �����Լ� + ��� + �Ҹ��� ���� �ҽ��ڵ� 
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Shape  // �������� ������ �߻�Ŭ���� (���� �����Լ��� ���)
{
protected:
	string name;
	int width, height;

public:
	
	Shape(string n = "", int w = 0, int h = 0)
		: name(n), width(w), height(h)
	{}


	virtual double getArea() = 0;    // <-- ���� �����Լ�

	string getName()
	{
		return name;
	}

};



class Oval : public Shape
{
public:
	Oval(string n, int w, int h) : Shape(n, w, h) {}


	virtual double getArea()
	{
		return width * height*3.14;
	}

};



class Rect : public Shape
{
public:
	Rect(string n, int w, int h) : Shape(n, w, h) {}


	virtual double getArea()
	{
		return width * height;
	}

};




class Triangular : public Shape
{
public:
	Triangular(string n, int w, int h) : Shape(n, w, h) {}


	virtual double getArea()
	{
		return width * height/2;
	}

};




int main()
{
	Shape *p[3];

	p[0] = new Oval("��붱", 10, 20);
	p[1] = new Rect("����", 30,40);
	p[2] = new Triangular("�佺Ʈ", 30,40);


	for (int i = 0; i < 3; i++)
	{
		cout << p[i]->getName() << "���̴� " << p[i]->getArea() << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		delete p[i];
	}

}









