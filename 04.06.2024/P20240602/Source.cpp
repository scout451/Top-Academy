#include <iostream>

using namespace std;

class Passport
{
	int code;
	int number;

public:
	Passport() : Passport(0,0) {}

	Passport(int code, int number)
	{
		this->code = code;
		this->number = number;
	}
	
	int GetCode() const { return code; }
	void SetCode(const int code) { this->code = code; }

	int GetNumber() const { return number; }
	void SetNumber(int const number) { this->number = number; }
};

class ForeignPassport : public Passport
{
	int visaNumber;

public:
	ForeignPassport() : Passport(0, 0) { visaNumber = 0; }

	ForeignPassport(int code, int number, int visaNumber) : Passport(code, number)
	{
		this->visaNumber = visaNumber;
	}

	int GetVisaNumber() const { return visaNumber; }
	void SetVisaNumber(int visaNumber) { this->visaNumber = visaNumber; }
};

//void main()
//{
//	ForeignPassport passport(2134, 634561, 8518);
//	ForeignPassport passport1;
//	cout << passport.GetCode() << " " << passport.GetNumber() << " " << passport.GetVisaNumber() << endl;
//	cout << passport1.GetCode() << " " << passport1.GetNumber() << " " << passport1.GetVisaNumber() << endl;
//
//	system("pause");
//}

class Circle
{
	int radius;

public:

	Circle(int r) : radius(r) {}

	int GetRadius() const { return radius; }
	void SetRadius(int r)
	{
		radius = r;
	}
};

class Square
{
	int hight;
	int wight;

public:

	Square(int h, int w) : hight(h), wight(w) {}

	int GetHight() const { return hight; }
	void SetHight(const int h)
	{
		hight = h;
	}

	int GetWight() const { return wight; }
	void SetWight(const int w)
	{
		wight = w;
	}
};

class CircleInSquare : public Circle, public Square
{
public:
	CircleInSquare(int r, int h, int w) : Circle(r), Square(h, w) {}
};

void main()
{
	CircleInSquare circle(123, 123, 213);
	cout << circle.GetRadius() << " " << circle.GetHight() << " " << circle.GetWight() << endl;

	system("pause");
}