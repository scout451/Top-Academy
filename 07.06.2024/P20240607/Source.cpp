#include <iostream>
#include <string>
#include <vector>

using namespace std;

//метод время (дистанция)
//метод стоимость (дистанция)

//class Transport
//{
//public:
//	virtual int Time() = 0;
//	virtual int Cost() = 0;
//};
//
//class Auto : public Transport
//{
//	const int Speed = 60;
//	const int ExpenditureFuel = 10;
//public:
//	virtual int Time(int distance)
//	{
//		return Speed * distance;
//	}
//	virtual int Cost(int distance, int fuelCost)
//	{
//		return distance / ExpenditureFuel * fuelCost;
//	}
//};
//
//class Bycicle : public Transport
//{
//	const int Speed = 20;
//public:
//	virtual int Time(int distance)
//	{
//		return Speed * distance;
//	}
//
//	int Cost() override
//	{
//		return 0;
//	}
//};
//
//class Carriage : public Transport
//{
//	const int Speed = 10;
//public:
//	virtual int Time(int distance)
//	{
//		return Speed * distance;
//	}
//
//	int Cost() override
//	{
//		return 0;
//	}
//};


class Employer
{
	string name;
public:
	string GetName() { return name; }
	void SetName(string n) { name = n; }

	Employer() : name(0) {}

	Employer (const string& n) : name(n) {}

	virtual void Print() = 0;
};

class President : public Employer
{
	int yearsInOffice;
public:
	President(const string& n, int year ) : Employer(n)
	{
		yearsInOffice = year;
	}

	void Print() override
	{
		cout << "Президент управляет " << yearsInOffice << " лет." << endl;
	}
};

class Manager : public Employer
{
	string department;
public:
	Manager(const string& n, const string& dep ) : Employer(n)
	{
		department = dep;
	}

	void Print() override
	{
		cout << "Менеджер управляет " << department << " отделом." << endl;
	}
};

class Worker : public Employer
{
	string specialization;
public:
	Worker(const string& n, const string& spec ) : Employer(n)
	{
		specialization = spec;
	}

	void Print() override
	{
		cout << "У рабочего профессия " << specialization << "." << endl;
	}
};

//void main()
//{
//	setlocale(LC_ALL, "");
//	Worker w("Worker", "Farmer");
//	Manager m("Manager", "IT");
//	President p("President", 20);
//
//	w.Print();
//	m.Print();
//	p.Print();
//
//	system("pause");
//}

class Figure
{
public:
	virtual double Area() = 0;
};

class Rectangle : public Figure
{
	double  height;
	double  weight;
public:
	Rectangle(double  h, double  w) : height(h), weight(w) {}
	double Area() override
	{
		return height * weight;
	}
};

class Circle : public Figure
{
	double  radius;
	const double numberOfPi = 3.1415926;
public:
	Circle(double  r) : radius(r) {}
	double Area() override
	{
		return numberOfPi * (radius * radius);
	}
};

class Triangle : public Figure
{
	double  katetA;
	double  katetB;
public:
	Triangle(double  a, double  b) : katetA(a), katetB(b) {}
	double Area() override
	{
		return (katetA * katetB) / 2;
	}
};

class Trapezoid : public Figure
{
	double  footingA;
	double  footingB;
	double  height;
public:
	Trapezoid(double  a, double  b, double  h) : footingA(a), footingB(b), height(h) {}
	double Area() override
	{
		return (footingA + footingB) / 2 * height;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	vector<Figure*> figures;
	figures.push_back(new Triangle(5,9));
	figures.push_back(new Circle(6));
	figures.push_back(new Rectangle(7, 3));
	figures.push_back(new Trapezoid(4, 8, 3));

	for (Figure* f : figures)
		cout << "Площадь фигуры = " << f->Area() << endl;

	for (Figure* f : figures)
		delete f;

	figures.clear();

	system("pause");
}