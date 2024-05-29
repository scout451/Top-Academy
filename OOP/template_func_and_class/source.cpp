#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//Задача 1
/*
template <typename TValue>
TValue Min(TValue left, TValue right)
{
    return left < right ? left : right;
}

template <typename TValue>
TValue Max(TValue left, TValue right)
{
    return left > right ? left : right;
}

template <typename TArray>
void Sort(TArray& array, int asc = 1)
{
    if (asc == 1)
        sort(begin(array), end(array), [](const auto& a, const auto& b) { return a < b; });
    else if (asc == 0)
        sort(begin(array), end(array), [](const auto& a, const auto& b) { return a > b; });
}

template <typename TArray, typename TValue>
int BinarySearch(const TArray& array, TValue search_value)
{
    int first_index = 0;
    int last_index = size(array) - 1;

    if (last_index == -1)
        return -1;

    while (first_index <= last_index)
    {
        int average_index = first_index + (last_index - first_index) / 2;
        if (array[average_index] == search_value)
            return average_index;
        if (array[average_index] < search_value)
            first_index = average_index + 1;
        else
            last_index = average_index - 1;
    }

    return -1;
}

template<typename TArray, typename TElement>
TElement Replace(TArray& array, int index, TElement newElement)
{
    return array[index] = newElement;
}

void main()
{
    setlocale(LC_ALL, "");
    vector<int> vec = { 4, 2, 3, 1 };
    Sort(vec);
    for (const auto& val : vec)
        cout << val << " ";
    cout << endl;

    int index = BinarySearch(vec, 3);
    if (index != -1)
        cout << "Элемент найден по индексу: " << index << endl;
    else
        cout << "Элемент не найден" << endl;

    vector<double> arr_2 = { 3.1, 2.4, 5.2, 1.8, 4.9 };
    Sort(arr_2, 0);
    for (const auto& val : arr_2)
        cout << val << " ";
    cout << endl;

    index = BinarySearch(arr_2, 4.9);
    if (index != -1)
        cout << "Элемент найден по индексу: " << index << endl;
    else
        cout << "Элемент не найден" << endl;

    Replace(arr_2, 2, 4.12);

	for (const auto& val : arr_2)
        cout << val << " ";
    cout << endl;


    system("pause");
}*/


//Задача 2

//template <typename TValue>
//class Matrix
//{
//    TValue** newMatrix;
//    int rows;
//    int columns;
//
//    void Create()
//    {
//        newMatrix = new TValue * [rows];
//        for (int i = 0; i < rows; i++)
//            newMatrix[i] = new TValue[columns];
//    }
//
//public:
//    Matrix() : rows(0), columns(0), newMatrix(nullptr) {};
//
//    Matrix(int r) : rows(r), columns(r) { Create(); };
//
//    Matrix(int r, int c) : rows(r), columns(c) { Create(); }
//
//    ~Matrix()
//    {
//        for (int i = 0; i < rows; i++)
//            delete[] newMatrix[i];
//        delete[] newMatrix;
//    }
//
//    Matrix(const Matrix& other)
//    {
//        rows = other.rows;
//        columns = other.columns;
//        Create();
//        for (int i = 0; i < rows; i++)
//            for (int j = 0; j < columns; j++)
//                newMatrix[i][j] = other[i][j];
//    }
//
//    Matrix operator=(const Matrix& other) const
//    {
//        if (this == other)
//            return *this;
//
//        for (int i = 0; i < rows; i++)
//            delete[] newMatrix[i];
//        delete[] newMatrix;
//
//        rows = other.rows;
//        columns = other.columns;
//        Create();
//        for (int i = 0; i < rows; i++)
//            for (int j = 0; j < columns; j++)
//                newMatrix[i][j] = other[i][j];
//
//        return *this;
//    }
//
//    Matrix(Matrix&& other)
//    {
//        newMatrix = other.newMatrix;
//        rows = other.rows;
//        columns = other.columns;
//
//        other.newMatrix = nullptr;
//        other.rows = 0;
//        other.columns = 0;
//    }
//
//    Matrix operator=(Matrix&& other)
//    {
//        if (this == other)
//            return *this;
//
//        for (int i = 0; i < rows; i++)
//            delete[] newMatrix[i];
//        delete[] newMatrix;
//
//        newMatrix = other.newMatrix;
//        rows = other.rows;
//        columns = other.columns;
//
//        other.newMatrix = nullptr;
//        other.rows = 0;
//        other.columns = 0;
//
//        return *this;
//    }
//
//    void SetValue(int r, int c, const TValue& value)
//    {
//    	newMatrix[r][c] = value;
//    }
//
//    TValue GetValue(int r, int c) const
//    {
//    	return newMatrix[r][c];
//    }
//
//    void FillManual()
//    {
//    	cout << "Enter elements of the matrix:" << endl;
//    	for (int i = 0; i < rows; i++) 
//        
//            for (int j = 0; j < columns; j++)
//                cin >> newMatrix[i][j];
//    }
//
//    void Print() 
//    {
//        for (int i = 0; i < rows; i++)
//        {
//            for (int j = 0; j < columns; j++)
//            {
//                cout << newMatrix[i][j] << " ";
//            }
//            cout << endl;
//        }
//    }
//};
//
//void main()
//{
//    setlocale(LC_ALL, "");
//    Matrix<int> mat(3, 3);
//
//    // Заполнение матрицы вручную
//    mat.FillManual();
//
//    // Вывод матрицы
//    mat.Print();
//
//    system("pause");
//}


template <typename TValue>
class Matrix
{
private:
    TValue** newMatrix;
    int rows, columns;

    void Create()
	{
        newMatrix = new TValue* [rows];
        for (int i = 0; i < rows; i++) 
            newMatrix[i] = new TValue[columns];
    }

    void Delete()
	{
        for (int i = 0; i < rows; i++)
            delete[] newMatrix[i];
        delete[] newMatrix;
    }

public:
    Matrix(int rows, int columns) : rows(rows), columns(columns)
	{
        Create();
    }

    ~Matrix()
	{
        Delete();
    }

    void FillFromKeyboard()
	{
        cout << "Введите элемент:\n";
        for (int i = 0; i < rows; i++) 
            for (int j = 0; j < columns; j++) 
                cin >> newMatrix[i][j];
    }

    void FillWithRandomValues()
	{
        srand(time(nullptr));
        for (int i = 0; i < rows; i++) 
            for (int j = 0; j < columns; j++) 
                newMatrix[i][j] = rand() % 100;
	}

    void Print() const
	{
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < columns; j++)
                cout << newMatrix[i][j] << " ";
            cout << endl;
        }
    }

    TValue MaxElement() const
	{
        TValue max = newMatrix[0][0];
        for (int i = 0; i < rows; i++) 
            for (int j = 0; j < columns; j++)
                if (newMatrix[i][j] > max) 
                    max = newMatrix[i][j];

        return max;
    }

    TValue MinElement() const
	{
        TValue min = newMatrix[0][0];
        for (int i = 0; i < rows; i++) 
            for (int j = 0; j < columns; j++) 
                if (newMatrix[i][j] < min) 
                    min = newMatrix[i][j];

        return min;
    }

    Matrix<TValue> operator+(const Matrix<TValue>& other) const
	{
        Matrix<TValue> result(rows, columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                result.newMatrix[i][j] = newMatrix[i][j] + other.newMatrix[i][j];

        return result;
    }

    Matrix<TValue> operator-(const Matrix<TValue>& other) 
	{
        Matrix<TValue> result(rows, columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                result.newMatrix[i][j] = newMatrix[i][j] - other.newMatrix[i][j];

            return result;
	}

	Matrix<TValue> operator*(const Matrix<TValue>&other) const
	{
		Matrix<TValue> result(rows, other.columns);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < other.columns; j++) 
			{
				result.newMatrix[i][j] = 0;
				for (int k = 0; k < columns; ++k)
					result.newMatrix[i][j] += newMatrix[i][k] * other.newMatrix[k][j];
			}

		return result;
	}

    Matrix<TValue> operator/(const TValue& scalar) const
	{
        Matrix<TValue> result(rows, columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++) 
                result.newMatrix[i][j] = newMatrix[i][j] / scalar;

        return result;
    }
};

void main()
{
    setlocale(LC_ALL, "");

    Matrix<int> mat1(3, 3);
    mat1.FillWithRandomValues();
    cout << "Матрица 1:\n";
    mat1.Print();


    Matrix<int> mat2(3, 3);
    mat2.FillFromKeyboard();
    cout << "Matrix 2:\n";
    mat2.Print();

    Matrix<int> sum = mat1 + mat2;
    cout << "Сумма матриц:\n";
    sum.Print();

    Matrix<int> diff = mat1 - mat2;
    cout << "Вычитание матриц:\n";
    diff.Print();

    Matrix<int> div = mat1 / 3;
    cout << "Деление матриц:\n";
    div.Print();

    Matrix<int> mult = mat1 * mat2;
    cout << "Умножение матриц:\n";
    mult.Print();



    // Поиск максимального и минимального элемента в матрице
    cout << "Максимальный элемент в матрице 1: " << mat1.MaxElement() << endl;
    cout << "Минимальный элемент в матрице 1: " << mat1.MinElement() << endl;

    system("pause");
}