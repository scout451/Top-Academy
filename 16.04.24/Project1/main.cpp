#include <iostream>
#include <vector>

using namespace std;

//задача 1
//void main()
//{
//    const int size = 4;
//    int arr[size];
//    for (int i = 0; i < size; i++)
//        arr[i] = i + 1;
//    int n = size(arr);
//    int m = 3;
// 
//    int index = 0;
//    while (true)
//    {
//        cout << arr[index];
//        index = (index + m - 1) % n;
//        if (index == 0)
//            break;
//    }
//
//    cout << endl;
//	system("pause");
//}


//задача 2

int InRadius(double circle_x, double circle_y, int r, double point_x, double point_y)
{
    double distance = sqrt(pow(point_x - circle_x, 2) + pow(point_y - circle_y, 2));
    const double epsilon = 1e-5;
    if (distance > r)
        return 2;
    else if (abs(distance - r) < epsilon)
        return 0;
    else
        return 1;
}

void main()
{
	double circle_x, circle_y, r;
	double point_x, point_y;

    cout << InRadius(2, 2, 2, 3, 3) << endl;
    cout << InRadius(2, 2, 2, 4, 2) << endl;
    cout << InRadius(2, 2, 2, 4, 3) << endl;

	system("pause");
}
