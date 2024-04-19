#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

//Задача 1
//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	ifstream file1, file2;
//	file1.open("file1.txt");
//	file2.open("file2.txt");
//
//	if (!file1.is_open() || !file2.is_open())
//		return;
//
//	vector<string> lines_file1;
//	vector<string> lines_file2;
//
//	string str;
//	while (getline(file1, str))
//		lines_file1.push_back(str);
//
//	while (getline(file2, str))
//		lines_file2.push_back(str);
//
//	file1.close();
//	file2.close();
//
//	bool IsEqual = (lines_file1 == lines_file2);
//
//	if(!IsEqual)
//	{
//		for (int i = lines_file1.size() - 1; i >= 0; i--)
//			if (lines_file1.at(i) != lines_file2.at(i))
//				cout << "Несовпадающая строка из файла 1: " << "[ " << i << " ]" << lines_file1.at(i) << endl;
//		cout << endl;
//		for (int i = lines_file1.size() - 1; i >= 0; i--)
//			if (lines_file1.at(i) != lines_file2.at(i))
//				cout << "Несовпадающая строка из файла 2: " << "[ " << i << " ]" << lines_file2.at(i) << endl;
//	}
//
//	system("pause");
//} //Программа работает, при условии одинакового размера файлов. В условиях не указан, какой размер у файлов, поэтому я решил оставить так.

//Задача 2

//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	ifstream inputFile;
//	ofstream outputFile;
//	inputFile.open("file1.txt");
//	outputFile.open("file1_stat.txt");
//	
//	if (!inputFile.is_open() || !outputFile.is_open())
//		return;
//
//	int countSymbols = 0, countStrings = 0, countVowels = 0, countConsonants = 0, countDigits = 0;
//	char symbol;
//	char vowels[] = {"AaEeUuYyIiOo"};
//	char consonants[] = { "QqWwRrTtPpSsDdFfGgHhJjKkLlZzXxCcVvBbNnMm" };
//	char digits[] = { "0123456789" };
//
//	while (inputFile.get(symbol))
//		countSymbols++;
//
//	inputFile.clear();
//	inputFile.seekg(0, inputFile.beg);
//
//	string str;
//	while (getline(inputFile ,str))
//		countStrings++;
//
//	inputFile.clear();
//	inputFile.seekg(0, inputFile.beg);
//
//	while (inputFile.get(symbol))
//		if (strchr(vowels, symbol))
//			countVowels++;
//
//	inputFile.clear();
//	inputFile.seekg(0, inputFile.beg);
//
//	while (inputFile.get(symbol))
//		if (strchr(consonants, symbol))
//			countConsonants++;
//
//	inputFile.clear();
//	inputFile.seekg(0, inputFile.beg);
//
//	while (inputFile.get(symbol))
//		if (strchr(digits, symbol))
//			countDigits++;
//
//	inputFile.close();
//
//	outputFile << "Количество символов: " << countSymbols << endl;
//	outputFile << "Количество строк: " << countStrings << endl;
//	outputFile << "Количество согласных: " << countConsonants << endl;
//	outputFile << "Количество гласных: " << countVowels << endl;
//	outputFile << "Количество цифр: " << countDigits << endl;
//
//	outputFile.close();
//
//	system("pause");
//}

//Задача 3

string encryptCaesarCipher(const string& input, int shift)
{
    string encrypted;
    for (char c : input)
    {
        if (isalpha(c))
        {
            char lowerCaseChar = tolower(c);
            int newPosition = (lowerCaseChar - 'a' + shift) % 26;
            if(c >'a' && c < 'z')
                encrypted += 'a' + newPosition;
            if (c > 'A' && c < 'Z')
                encrypted += 'A' + newPosition;
        }
        else
            encrypted += c;
    }
    return encrypted;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    const int shift = 3;

	ifstream inputFile;
	ofstream outputFile;
	inputFile.open("file1.txt");
	outputFile.open("file1_code.txt");

	if (!inputFile.is_open() || !outputFile.is_open())
		return;

    string str;
	while (getline(inputFile, str))
	{
        string encryptedLine = encryptCaesarCipher(str, shift);
        outputFile << encryptedLine << endl;
	}

	inputFile.close();
	outputFile.close();

	system("pause");
}