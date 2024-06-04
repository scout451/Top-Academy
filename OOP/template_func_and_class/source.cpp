#include <iostream>
#include <algorithm>
#include <vector>
#include <Windows.h>
#include <stdexcept>
#include <string>

using namespace std;

//Встреча 11
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

//Встреча 12
//Задача 1

//template <typename TValue>
//class Matrix
//{
//private:
//    TValue** newMatrix;
//    int rows, columns;
//
//    void Create()
//	{
//        newMatrix = new TValue * [rows];
//        for (int i = 0; i < rows; i++)
//            newMatrix[i] = new TValue[columns];
//    }
//
//    void Delete() {
//        for (int i = 0; i < rows; i++)
//            delete[] newMatrix[i];
//        delete[] newMatrix;
//    }
//
//public:
//    Matrix(int rows, int columns) : rows(rows), columns(columns)
//	{
//        Create();
//    }
//
//    Matrix(const Matrix<TValue>& other) : rows(other.rows), columns(other.columns)
//	{
//        Create();
//        for (int i = 0; i < rows; i++)
//            for (int j = 0; j < columns; j++)
//                newMatrix[i][j] = other.newMatrix[i][j];
//    }
//
//    Matrix(const int value) : Matrix(value, value) {};
//
//    Matrix& operator=(const Matrix<TValue>& other)
//	{
//        if (this != &other) 
//        {
//            Delete();
//            rows = other.rows;
//            columns = other.columns;
//            Create();
//            for (int i = 0; i < rows; i++)
//                for (int j = 0; j < columns; j++)
//                    newMatrix[i][j] = other.newMatrix[i][j];
//        }
//        return *this;
//    }
//
//    ~Matrix()
//	{
//        Delete();
//    }
//
//    void FillFromKeyboard()
//	{
//        cout << "Введите элемент:\n";
//        for (int i = 0; i < rows; i++)
//            for (int j = 0; j < columns; j++)
//                cin >> newMatrix[i][j];
//    }
//
//    void FillWithRandomValues()
//	{
//        for (int i = 0; i < rows; i++)
//            for (int j = 0; j < columns; j++)
//                newMatrix[i][j] = rand() % 100;
//    }
//
//    void Print() const
//	{
//        for (int i = 0; i < rows; i++) 
//        {
//            for (int j = 0; j < columns; j++)
//                cout << newMatrix[i][j] << " ";
//            cout << endl;
//        }
//    }
//
//    TValue MaxElement() const
//	{
//        TValue max = newMatrix[0][0];
//        for (int i = 0; i < rows; i++)
//            for (int j = 0; j < columns; j++)
//                if (newMatrix[i][j] > max)
//                    max = newMatrix[i][j];
//        return max;
//    }
//
//    TValue MinElement() const
//	{
//        TValue min = newMatrix[0][0];
//        for (int i = 0; i < rows; i++)
//            for (int j = 0; j < columns; j++)
//                if (newMatrix[i][j] < min)
//                    min = newMatrix[i][j];
//        return min;
//    }
//
//    Matrix<TValue> operator+(const Matrix<TValue>& other) const
//	{
//        if (rows != other.rows || columns != other.columns) 
//        {
//            return -1;
//        }
//        Matrix<TValue> result(rows, columns);
//        for (int i = 0; i < rows; i++)
//            for (int j = 0; j < columns; j++)
//                result.newMatrix[i][j] = newMatrix[i][j] + other.newMatrix[i][j];
//        return result;
//    }
//
//    Matrix<TValue> operator-(const Matrix<TValue>& other) const
//	{
//        if (rows != other.rows || columns != other.columns) 
//        {
//           return -1;
//        }
//        Matrix<TValue> result(rows, columns);
//        for (int i = 0; i < rows; i++)
//            for (int j = 0; j < columns; j++)
//                result.newMatrix[i][j] = newMatrix[i][j] - other.newMatrix[i][j];
//        return result;
//    }
//
//    Matrix<TValue> operator*(const Matrix<TValue>& other) const
//	{
//        if (columns != other.rows) 
//        {
//            return -1;
//        }
//        Matrix<TValue> result(rows, other.columns);
//        for (int i = 0; i < rows; i++) 
//            for (int j = 0; j < other.columns; j++) 
//            {
//                result.newMatrix[i][j] = 0;
//                for (int k = 0; k < columns; k++)
//                    result.newMatrix[i][j] += newMatrix[i][k] * other.newMatrix[k][j];
//            }
//        return result;
//    }
//
//    Matrix<TValue> operator/(const Matrix<TValue>& other) const
//	{
//        Matrix<TValue> inverse = other.Inverse();
//        return (*this) * inverse;
//    }
//
//    Matrix<TValue> Inverse() const
//	{
//        if (rows != columns) 
//        {
//            return -1;
//        }
//
//        int n = rows;
//        Matrix<TValue> result(n, n);
//        Matrix<TValue> augmented(n, 2 * n);
//
//        for (int i = 0; i < n; ++i) 
//            for (int j = 0; j < n; ++j) 
//            {
//                augmented.newMatrix[i][j] = newMatrix[i][j];
//                augmented.newMatrix[i][j + n] = (i == j) ? 1 : 0;
//            }
//
//        for (int i = 0; i < n; ++i) 
//        {
//            int maxRow = i;
//            for (int k = i + 1; k < n; ++k) 
//                if (fabs(augmented.newMatrix[k][i]) > fabs(augmented.newMatrix[maxRow][i])) 
//                    maxRow = k;
//
//            for (int k = 0; k < 2 * n; ++k) 
//            {
//                swap(augmented.newMatrix[maxRow][k], augmented.newMatrix[i][k]);
//            }
//
//            for (int k = i + 1; k < n; ++k) 
//            {
//                TValue factor = augmented.newMatrix[k][i] / augmented.newMatrix[i][i];
//                for (int j = i; j < 2 * n; ++j)
//                    augmented.newMatrix[k][j] -= augmented.newMatrix[i][j] * factor;
//            }
//        }
//
//        for (int i = n - 1; i >= 0; --i) 
//        {
//            for (int j = n; j < 2 * n; ++j) 
//                augmented.newMatrix[i][j] /= augmented.newMatrix[i][i];
//            for (int k = 0; k < i; ++k) 
//                for (int j = n; j < 2 * n; ++j) 
//                    augmented.newMatrix[k][j] -= augmented.newMatrix[i][j] * augmented.newMatrix[k][i];
//        }
//
//        for (int i = 0; i < n; ++i) 
//            for (int j = 0; j < n; ++j) 
//                result.newMatrix[i][j] = augmented.newMatrix[i][j + n];
//
//        return result;
//    }
//};
//
//void main()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    srand(time(nullptr));
//
//	Matrix<double> mat1(3, 3);
//	mat1.FillWithRandomValues();
//	cout << "Матрица 1:\n";
//	mat1.Print();
//
//	Matrix<double> mat2(3, 3);
//	mat2.FillWithRandomValues();
//	cout << "Матрица 2:\n";
//	mat2.Print();
//
//	Matrix<double> sum = mat1 + mat2;
//	cout << "Сумма матриц:\n";
//	sum.Print();
//
//	Matrix<double> diff = mat1 - mat2;
//	cout << "Разность матриц:\n";
//	diff.Print();
//
//	Matrix<double> mult = mat1 * mat2;
//	cout << "Произведение матриц:\n";
//	mult.Print();
//
//	Matrix<double> div = mat1 / mat2;
//	cout << "Частное матриц:\n";
//	div.Print();
//
//	cout << "Максимальный элемент в матрице 1: " << mat1.MaxElement() << endl;
//	cout << "Минимальный элемент в матрице 1: " << mat1.MinElement() << endl;
//
//	Matrix<double> inverse = mat2.Inverse();
//	cout << "Обратная матрица ко 2-й матрице:\n";
//	inverse.Print();
//
//    system("pause");
//}

//Встреча 13
//Задача 1

void checkBrackets(const string& input)
{
    vector<char> Brackets;
    int vectorSize = -1;

    for (int i = 0; i < input.length(); i++)
    {
        char currentChar = input[i];
        if (currentChar == '(' || currentChar == '{' || currentChar == '[') 
        {
            Brackets.push_back(currentChar);
            vectorSize++;
        }
        else if (currentChar == ')' || currentChar == '}' || currentChar == ']') 
        {
            if (vectorSize == -1 || (currentChar == ')' && Brackets[vectorSize] != '(') ||
                (currentChar == '}' && Brackets[vectorSize] != '{') ||
                (currentChar == ']' && Brackets[vectorSize] != '[')) 
            {
                cout << "Ошибка! Некорректная расстановка скобок." << endl;
                cout << input.substr(0, i + 1) << endl;
            }
            Brackets.pop_back();
            vectorSize--;
        }
    }

    if (!Brackets.empty())
    {
        cout << "Ошибка! Некорректная расстановка скобок." << endl;
        cout << input.substr(0, input.length()) << endl;
        return;
    }

    cout << "Скобки расставлены корректно." << endl;
}

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string inputString;
    cout << "Введите строку: ";
    getline(cin, inputString);

    checkBrackets(inputString);

    system("pause");
}

