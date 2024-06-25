#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

//Встреча 20

//class Base
//{
//public:
//	virtual void Display(const string& path) = 0;
//};
//
//class Ascii : public Base
//{
//public:
//	void Display(const string& path) override
//	{
//		string line;
//		ifstream data(path);
//
//		if (data.is_open())
//		{
//			while (getline(data, line))
//			{
//				cout << line << endl;
//			}
//		}
//		else
//		{
//			cout << "Unable to open file: " << path << endl;
//		}
//		data.close();
//	}
//};
//
//class Binary : public Base
//{
//public:
//	void Display(const string& path) override
//	{
//		ifstream data(path, ios::binary);
//
//		if (data.is_open())
//		{
//			char ch;
//			while (data.get(ch))
//			{
//				for (int i = 7; i >= 0; i--)
//					cout << ((ch >> i) & 1);
//				cout << ' ';
//			}
//		}
//		else
//		{
//			cout << "Unable to open file: " << path << endl;
//		}
//		data.close();
//	}
//};
//
//void Test()
//{
//	Ascii ascii;
//	Binary binary;
//
//	string asciiPath = "ascii2.txt";
//	string binaryPath = "binary.txt";
//
//	cout << "Displaying ASCII file:" << endl;
//	ascii.Display(asciiPath);
//
//	cout << "Displaying Binary file:" << endl;
//	binary.Display(binaryPath);
//}
//
//void main()
//{
//	Test();
//
//	system("pause");
//}

//Встреча 21
//Задание 1

//class Base
//{
//protected:
//    int a;
//    int b;
//public:
//    int GetA() { return a; }
//    void SetA(int value) { a = value; }
//    int GetB() { return b; }
//    void SetB(int value) { b = value; }
//
//    virtual pair<double, double> Root() = 0; //не придумал какой тип данных тут возвращать
//};
//
//class Linear : public Base
//{
//public:
//    virtual pair<double, double> Root() override 
//    {
//        return make_pair(static_cast<double>(-b) / a, -0.0); // -0.0 чтобы сработал make_pair, 
//    }                                            
//};
//
//class Quadratic : public Base
//{
//    int c;
//public:
//
//    int GetC() { return c; }
//    void SetC(int value) { c = value; }
//
//    virtual pair<double, double> Root() override
//    {
//        double D = b * b - 4 * a * c;
//        if (D > 0)
//        {
//            double x1 = (-b + sqrt(D)) / (2 * a);
//            double x2 = (-b - sqrt(D)) / (2 * a);
//            return make_pair(x1, x2);
//        }
//        else if (D == 0)
//        {
//            double x = -b / (2 * a);
//            return make_pair(x, x);
//        }
//        else
//        {
//            return make_pair(-0.0, -0.0); // при отсутствии корней возвращает -0
//        }
//    }
//};
//
//void Test()
//{
//	Linear linear;
//	linear.SetA(2);
//	linear.SetB(8);
//
//	Quadratic quadratic;
//	quadratic.SetA(1);
//	quadratic.SetB(-3);
//	quadratic.SetC(2);
//
//	Quadratic quadratic2;
//	quadratic2.SetA(2);
//	quadratic2.SetB(2);
//	quadratic2.SetC(2);
//
//	pair<double, double> rootLinear = linear.Root();
//	pair<double, double> rootQuadratic = quadratic.Root();
//	pair<double, double> rootQuadratic2 = quadratic2.Root();
//
//	cout << "Root of Linear Equation: " << rootLinear.first << ", " << rootLinear.second << endl;
//	cout << "Roots of Quadratic Equation: " << rootQuadratic.first << ", " << rootQuadratic.second << endl;
//	cout << "Roots of Quadratic2 Equation: " << rootQuadratic2.first << ", " << rootQuadratic2.second << endl;
//}
//
//void main()
//{
//    Test();
//
//    system("pause");
//}

//Задание 2

class Point
{
	int x;
	int y;
public:
	int GetX() { return x; }
	void SetX(int value) { x = value; }

	int GetY() { return y; }
	void SetY(int value) { y = value; }

	Point() : Point(0,0) {}

	Point(int valueX, int valueY) : x(valueX), y(valueY) {}
};

class Shape
{
protected:
	Point point;
public:
	Shape() : Shape(0, 0) {}
	Shape(int x, int y)
	{
		point.SetY(y);
		point.SetX(x);
	}
	virtual string Show() = 0;
	virtual void Save() = 0;
	virtual void Load() = 0;
};

class Square : public Shape
{
	int side;
public:
	Square() : Square(0, 0, 0) {}
	Square(int s, int x, int y) : Shape(x, y), side(s) {}

	static Square* FromString(const string& str)
	{
		try
		{
			if (!str.starts_with("Square"))
				throw(("Invalid str '{}' for Rectangle", str));

			const int sideStartIndex = str.find("(s=");
			if (sideStartIndex == -1)
				throw(("Not found start of side in str '{}' for Square"), str);

			const int sideEndIndex = str.find(",pX=", sideStartIndex);
			if(sideEndIndex == -1)
				throw(("Not found end of side in str '{}' for Square"), str);

			const int pXStartIndex = str.find(",pX=", sideEndIndex);
			if (pXStartIndex == -1)
				throw(("Not found start of pX in str '{}' for Square"), str);

			const int pXEndIndex = str.find(",pY=", pXStartIndex);
			if (pXEndIndex == -1)
				throw(("Not found end of pX in str '{}' for Square"), str);

			const int pYStartIndex = str.find(",pY=", pXEndIndex);
			if (pYStartIndex == -1)
				throw(("Not found start of pY in str '{}' for Square"), str);

			const int pYEndIndex = str.find(")", pYStartIndex);
			if (sideStartIndex == -1)
				throw(("Not found end of pY in str '{}' for Square"), str);

			const int side = stoi(
				str.substr(sideStartIndex + 3, sideEndIndex - sideStartIndex - 3));
			const int pX = stoi(
				str.substr(pXStartIndex + 4, pXEndIndex - pXStartIndex - 4));
			const int pY = stoi(
				str.substr(pYStartIndex + 4, pYEndIndex - pYStartIndex - 4));

			return new Square(side, pX, pY);
		}
		catch (const string& error)
		{
			cout << "Error parcing square: " << error << endl;
		}
	}

	string Show() override
	{
		return "Square(s=" + to_string(side) + ",pX=" + to_string(point.GetX()) + ",pY=" + to_string(point.GetY()) + ")";
	}

	void Save() override
	{
		ofstream file("Square.txt");
		if (file.is_open())
		{
			file << this->Show();
		}
		file.close();
	}

	void Load() override
	{
		ifstream file("Square.txt");
		if(file.is_open())
		{
			string data;
			getline(file, data);
			Square* sq = FromString(data);
			if (sq != nullptr)
				*this = *sq;
		}
		else
		{
			cout << "Failed to open file" << endl;
		}
		file.close();
	}
};

class Rectangle : public Shape
{
	int height;
	int width;
public:
	Rectangle() : Rectangle(0, 0, 0, 0) {}
	Rectangle(int h, int w, int x, int y) :  Shape(x,y), height(h), width(w) {}

	static Rectangle* FromString(const string& str)
	{
		try
		{
			if (!str.starts_with("Rectangle"))
				throw(("Invalid str '{}' for Rectangle", str));

			const int heightStartIndex = str.find("(h=");
			if (heightStartIndex == -1)
				throw(("Not found start of height in str '{}' for Rectangle"), str);

			const int heightEndIndex = str.find(",w=", heightStartIndex);
			if (heightEndIndex == -1)
				throw(("Not found end of height in str '{}' for Rectangle"), str);

			const int widthStartIndex = str.find(",w=");
			if (widthStartIndex == -1)
				throw(("Not found start of width in str '{}' for Rectangle"), str);

			const int widthEndIndex = str.find(",pX=", widthStartIndex);
			if (widthEndIndex == -1)
				throw(("Not found end of width in str '{}' for Rectangle"), str);

			const int pXStartIndex = str.find(",pX=", heightEndIndex);
			if (pXStartIndex == -1)
				throw(("Not found start of pX in str '{}' for Rectangle"), str);

			const int pXEndIndex = str.find(",pY=", pXStartIndex);
			if (pXEndIndex == -1)
				throw(("Not found end of pX in str '{}' for Rectangle"), str);

			const int pYStartIndex = str.find(",pY=", pXEndIndex);
			if (pYStartIndex == -1)
				throw(("Not found start of pY in str '{}' for Rectangle"), str);

			const int pYEndIndex = str.find(")", pYStartIndex);
			if (heightStartIndex == -1)
				throw(("Not found end of pY in str '{}' for Rectangle"), str);

			const int height = stoi(
				str.substr(heightStartIndex + 3, heightEndIndex - heightStartIndex - 3));
			const int width = stoi(
				str.substr(widthStartIndex + 3, widthEndIndex - widthStartIndex - 3));
			const int pX = stoi(
				str.substr(pXStartIndex + 4, pXEndIndex - pXStartIndex - 4));
			const int pY = stoi(
				str.substr(pYStartIndex + 4, pYEndIndex - pYStartIndex - 4));

			return new Rectangle(height, width, pX, pY);
		}
		catch (const string& error)
		{
			cout << "Error parcing rectangle" << error << endl;
		}
	}

	string Show() override
	{
		return "Rectangle(h=" + to_string(height) + ",w=" + to_string(width) +
			",pX=" + to_string(point.GetX()) + ",pY=" + to_string(point.GetY()) + ")";
	}

	void Save() override
	{
		ofstream file("Rectangle.txt");
		if (file.is_open())
		{
			file << this->Show();
		}
		else
			cout << "Failed to open file" << endl;

		file.close();
		
	}

	void Load() override
	{
		ifstream file("Rectangle.txt");
		if (file.is_open())
		{
			string data;
			getline(file, data);
			Rectangle* rect = FromString(data);
			if(rect != nullptr)
				*this = *rect;
			else
				cout << "Failed to open file" << endl;
		}
		file.close();
	}
};

class Circle : public Shape
{
	int radius;
public:
	Circle() : Circle(0, 0, 0) {}
	Circle(int r, int x, int y) : Shape(x, y), radius(r) {}

	static Circle* FromString(const string& str)
	{
		try
		{
			if (!str.starts_with("Circle"))
				throw(("Invalid str '{}' for Rectangle", str));

			const int radiusStartIndex = str.find("(r=");
			if (radiusStartIndex == -1)
				throw(("Not found start of radius in str '{}' for Circle"), str);

			const int radiusEndIndex = str.find(",pX=", radiusStartIndex);
			if (radiusEndIndex == -1)
				throw(("Not found end of radius in str '{}' for Circle"), str);

			const int pXStartIndex = str.find(",pX=", radiusEndIndex);
			if (pXStartIndex == -1)
				throw(("Not found start of pX in str '{}' for Circle"), str);

			const int pXEndIndex = str.find(",pY=", pXStartIndex);
			if (pXEndIndex == -1)
				throw(("Not found end of pX in str '{}' for Circle"), str);

			const int pYStartIndex = str.find(",pY=", pXEndIndex);
			if (pYStartIndex == -1)
				throw(("Not found start of pY in str '{}' for Circle"), str);

			const int pYEndIndex = str.find(")", pYStartIndex);
			if (radiusStartIndex == -1)
				throw(("Not found end of pY in str '{}' for Circle"), str);

			const int radius = stoi(
				str.substr(radiusStartIndex + 3, radiusEndIndex - radiusStartIndex - 3));
			const int pX = stoi(
				str.substr(pXStartIndex + 4, pXEndIndex - pXStartIndex - 4));
			const int pY = stoi(
				str.substr(pYStartIndex + 4, pYEndIndex - pYStartIndex - 4));

			return new Circle(radius, pX, pY);
		}
		catch (const string& error)
		{
			cout << "Error on parsing circle " << error << endl;
		}
	}
	string Show() override
	{
		return "Circle(r=" + to_string(radius) + ",pX=" + to_string(point.GetX()) + 
			",pY=" + to_string(point.GetY()) + ")";
	}
	virtual void Save()
	{
		ofstream file("Circle.txt");
		if (file.is_open())
		{
			file << this->Show();
		}
		else
		{
			cout << "Failed to open file" << endl;
		}
		file.close();
	}
	virtual void Load()
	{
		ifstream file("Circle.txt");
		if (file.is_open())
		{
			string data;
			getline(file, data);
			Circle* cr = FromString(data);
			if (cr != nullptr)
				*this = *cr;
		}
		else
		{
			cout << "Failed to open file" << endl;
		}
		file.close();
	}
};

class Ellipse : public Shape
{
	int heightRectangle;
	int widthRectangle;
public:
	Ellipse() : Ellipse(0, 0, 0, 0) {}
	Ellipse(int h, int w, int x, int y) : Shape(x, y), heightRectangle(h), widthRectangle(w) {}

	static Ellipse* FromString(const string& str)
	{
		try
		{
			if (!str.starts_with("Ellipse"))
				throw(("Invalid str '{}' for Ellipse", str));

			const int heightStartIndex = str.find("(h=");
			if (heightStartIndex == -1)
				throw(("Not found start of height in str '{}' for Ellipse"), str);

			const int heightEndIndex = str.find(",w=", heightStartIndex);
			if (heightEndIndex == -1)
				throw(("Not found end of height in str '{}' for Ellipse"), str);

			const int widthStartIndex = str.find(",w=");
			if (widthStartIndex == -1)
				throw(("Not found start of width in str '{}' for Ellipse"), str);

			const int widthEndIndex = str.find(",pX=", widthStartIndex);
			if (widthEndIndex == -1)
				throw(("Not found end of width in str '{}' for Ellipse"), str);

			const int pXStartIndex = str.find(",pX=", heightEndIndex);
			if (pXStartIndex == -1)
				throw(("Not found start of pX in str '{}' for Ellipse"), str);

			const int pXEndIndex = str.find(",pY=", pXStartIndex);
			if (pXEndIndex == -1)
				throw(("Not found end of pX in str '{}' for Ellipse"), str);

			const int pYStartIndex = str.find(",pY=", pXEndIndex);
			if (pYStartIndex == -1)
				throw(("Not found start of pY in str '{}' for Ellipse"), str);

			const int pYEndIndex = str.find(")", pYStartIndex);
			if (heightStartIndex == -1)
				throw(("Not found end of pY in str '{}' for Ellipse"), str);

			const int height = stoi(
				str.substr(heightStartIndex + 3, heightEndIndex - heightStartIndex - 3));
			const int width = stoi(
				str.substr(widthStartIndex + 3, widthEndIndex - widthStartIndex - 3));
			const int pX = stoi(
				str.substr(pXStartIndex + 4, pXEndIndex - pXStartIndex - 4));
			const int pY = stoi(
				str.substr(pYStartIndex + 4, pYEndIndex - pYStartIndex - 4));

			return new Ellipse(height, width, pX, pY);
		}
		catch (const string& error)
		{
			cout << "Error on parsing ellipse " << error << endl;
		}
	}
	string Show() override
	{
		return "Ellipse(h=" + to_string(heightRectangle) + ",w=" + to_string(widthRectangle) +
			",pX=" + to_string(point.GetX()) + ",pY=" + to_string(point.GetY()) + ")";
	}
	virtual void Save()
	{
		ofstream file("Ellipse.txt");
		if (file.is_open())
		{
			file << this->Show();
		}
		else
		{
			cout << "Failed to open file" << endl;
		}
		file.close();
	}
	virtual void Load()
	{
		ifstream file("Ellipse.txt");
		if (file.is_open())
		{
			string data;
			getline(file, data);
			Ellipse* el = FromString(data);
			if (el != nullptr)
				*this = *el;
		}
		else
		{
			cout << "Failed to open file" << endl;
		}
		file.close();
	}
};

void TestSave()
{
	Square* square = Square::FromString("Square(s=4,pX=1,pY=1)");
	if (square != nullptr)
	{
		cout << square->Show() << endl;
		square->Save();
		delete square;
	}

	Rectangle* rectangle = Rectangle::FromString("Rectangle(h=2,w=5,pX=3,pY=3)");
	if (rectangle != nullptr)
	{
		cout << rectangle->Show() << endl;
		rectangle->Save();
		delete rectangle;
	}

	Circle* circle = Circle::FromString("Circle(r=6,pX=7,pY=7)");
	if (circle != nullptr)
	{
		cout << circle->Show() << endl;
		circle->Save();
		delete circle;
	}

	Ellipse* ellipse = Ellipse::FromString("Ellipse(h=8,w=3,pX=6,pY=9");
	if(ellipse != nullptr)
	{
		cout << ellipse->Show() << endl;
		ellipse->Save();
		delete ellipse;
	}
}

void TestLoad()
{
	Square loadedSquare;
	loadedSquare.Load();
	cout << loadedSquare.Show() << endl;

	Rectangle loadedRectangle;
	loadedRectangle.Load();
	cout << loadedRectangle.Show() << endl;

	Circle loadedCircle;
	loadedCircle.Load();
	cout << loadedCircle.Show() << endl;

	Ellipse loadedEllipse;
	loadedEllipse.Load();
	cout << loadedEllipse.Show() << endl;
}

void main()
{
	TestSave();

	cout << endl;

	TestLoad();

	system("pause");
}