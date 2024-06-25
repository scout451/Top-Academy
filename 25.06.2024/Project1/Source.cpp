#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <list>
#include <vector>

using namespace std;

void CleanWord(string& word)
{
    const int size = word.size();

    int startIndex = 0;
    while (!isalpha(word[startIndex]) && startIndex < size)
        startIndex++;

    int endIndex = size - 1;
    while (!isalpha(word[endIndex]) && endIndex >= 0)
        endIndex--;

    if ((startIndex != 0 || endIndex != size - 1) && startIndex <= endIndex)
        word = word.substr(startIndex, endIndex - startIndex + 1);
}

void Task1()
{
    ifstream file("file1.txt");
    if (!file.is_open())
    {
        cout << "Input error" << endl;
        return;
    }

    string word;
    map<string, int> wordCount;
    while (file >> word)
    {
        CleanWord(word);

        auto insertResult = wordCount.insert(make_pair(word, 1));
        if (!insertResult.second)
            insertResult.first->second++;
    }

    file.close();

    for (auto x : wordCount)
        cout << x.first << ": " << x.second << endl;
}

void Task2()
{
    ifstream file("task1.txt");
    if (!file.is_open())
    {
	    cout << "File is not open" << endl;
        return;
    }

    char ch;
    map<char, int> wordCount;

    while(true)
    {
        ch = file.get();
	    if(!isdigit(ch) && !isalpha(ch) || ch == ' ')
	    {
		    auto insertResult = wordCount.insert(make_pair(ch, 1));
            if (!insertResult.second)
                insertResult.first->second++;
	    }
        if(file.eof())
            break;
    }
    file.close();

    for (auto x : wordCount)
        cout << x.first << ": " << x.second << endl;

    system("pause");
}


void Task3()
{
    ifstream file("task2.txt");
    if (!file.is_open())
    {
	    cout << "Failed opened" << endl;
        return;
    }

    string number;
    map<int, int> wordCount;
    int totalSum = 0;
    int totalCount = 0;

    while (file >> number)
    {
        auto insertResult = wordCount.insert(make_pair(stoi(number), 1));
        if (!insertResult.second)
            insertResult.first->second++;
        totalSum += stoi(number);
        totalCount++;
    }

    file.close();

    for (auto x : wordCount)
        cout << x.first << ": " << x.second << endl;
    cout << "totalSum = " << totalSum << endl;
    cout << "totalCount = " << totalCount << endl;
    system("pause");
}

void Task4()
{
    ifstream file("task2.txt");
    if (!file.is_open())
    {
        cout << "File not opened" << endl;
        return;
    }

    string number;
    list<int> numbers;
    int totalSum = 0;
    int totalCount = 0;

    while (file >> number)
    {
        numbers.push_back(stoi(number));
    }
	file.close();

	char key ;
    int value = 0;
    ifstream file2("task3.txt");
    if (!file2.is_open())
    {
        cout << "File not opened" << endl;
        return;
    }

    while(file2 >> value >> key)
    {
    	for (auto i = numbers.begin(); i != numbers.end(); ++i)
        {
            if (*i == value)
            {
	            if(key == '-')
	            {
		            i = numbers.erase(++i);
                    if (*i == value)
                        --i;
	            }

            	if(key == '+')
            		i = numbers.insert(++i, 100);
            }
        }
        
    }
    file2.close();

    map<int, int> numberCount;
    for(auto number : numbers)
    {
        auto insertResult = numberCount.insert(make_pair(number, 1));
        if (!insertResult.second)
            insertResult.first->second++;
        totalSum += number;
        totalCount++;
    }

    for (auto x : numberCount)
        cout << x.first << ": " << x.second << endl;

    cout << "totalSum = " << totalSum << endl;
    cout << "totalCount = " << totalCount << endl;

    system("pause");
}

void main()
{
    /*Task1();
    Task2();
    Task3();*/
    Task4();

}