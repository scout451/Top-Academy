#include <iostream>

class Date
{
    int day;
    int month;
    int year;

public:

    Date() : day(1), month(1), year(2000) {}

    Date(int day, int month, int year) : day(day), month(month), year(year) {}

    void incrementDay() {
        ++day;
    }

    // Перегрузка операторов ++, --
    Date& operator++() 
    {
        ++day;
        return *this;
    }

    Date operator++(int) 
    {
        Date temp = *this;
        ++(*this);
        return temp;
    }

    Date& operator--() 
    {
        --day;
        return *this;
    }

    Date operator--(int) 
    {
        Date temp = *this;
        --(*this);
        return temp;
    }

    // Перегрузка операторов сравнения !=, ==, >, <
    bool operator!=(const Date& other) const 
    {
        return !(*this == other);
    }

    bool operator==(const Date& other) const 
    {
        return day == other.day && month == other.month && year == other.year;
    }

    bool operator>(const Date& other) const 
    {
        if (year != other.year) 
            return year > other.year;
        if (month != other.month) 
            return month > other.month;
        return day > other.day;
    }

    bool operator<(const Date& other) const 
    {
        return !(*this == other || *this > other);
    }

    // Перегрузка операторов ввода/вывода >>, <<
    friend std::istream& operator>>(std::istream& is, Date& date) 
    {
        is >> date.day >> date.month >> date.year;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Date& date) 
    {
        os << date.day << "/" << date.month << "/" << date.year;
        return os;
    }

    // Перегрузка операторов присваивания =, +=, -=
    Date& operator=(const Date& other) 
    {
        if (this != &other) {
            day = other.day;
            month = other.month;
            year = other.year;
        }
        return *this;
    }

    Date& operator+=(int days) 
    {
        day += days;
        return *this;
    }

    Date& operator-=(int days) 
    {
        day -= days;
        return *this;
    }

    int operator()() const 
    {
        return day;
    }
};

int main() {
    Date today(25, 5, 2024);
    std::cout << "Today is: " << today << std::endl;

    ++today;
    std::cout << "Tomorrow is: " << today << std::endl;

    --today;
    std::cout << "Back to today: " << today << std::endl;

    Date anotherDay = today;
    anotherDay += 5;
    std::cout << "Another day: " << anotherDay << std::endl;

    std::cout << "Today's day: " << today() << std::endl;

    return 0;
}
