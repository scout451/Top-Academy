#include <iostream>

using namespace std;

class Point
{
	int x;
	int y;
	int z;

public:
	Point() : Point(0,0,0)
	{
	}

	Point(int a, int b, int c)
	{
		x = a;
		y = b;
		z = c;
	}

	int GetX() { return x; }
	void SetX(int a) { x = a; }

	int GetY() { return y; }
	void SetY(int a) { y = a; }

	int GetZ() { return z; }
	void SetZ(int a) { z = a; }
};

void main()
{
	Point Point(2,3,4);
	Point.SetX(1);
	Point.SetY(2);
	Point.SetZ(3);
	cout << Point.GetX() << " " << Point.GetY() << " " << Point.GetZ() << endl;

	system("pause");
}