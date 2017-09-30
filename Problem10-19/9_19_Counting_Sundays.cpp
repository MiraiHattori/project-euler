#include <iostream>

bool countSunday(int year, int month, int day);
//1901/1/1は月曜日
bool isLeapYear(int year);


int main()
{
    int result = 0;
    for (int i = 1901; i <= 2000; i++) {
        for (int j = 1; j <= 12; j++) {
            if (countSunday(i, j, 1) == true) {
                result++;
                std::cout << i << " " << j << std::endl;
            }
        }
    }
    std::cout << result << std::endl;
    return 0;
}

bool countSunday(int year, int month, int day)
{
    int days = 0;
    for (int i = 1901; i < year; i++) {
        if (isLeapYear(i) == true) {
            days += 366;
        } else {
            days += 365;
        }
    }
    for (int i = 1; i < month; i++) {
        if (i == 4 || i == 6 || i == 9 || i == 11) {
            days += 30;
        } else if (i == 2) {
            if (isLeapYear(year) == true) {
                days += 29;
            } else {
                days += 28;
            }
        } else {
            days += 31;
        }
    }
    days += day;
    if (days % 7 == 6) {
        return true;
    } else {
        return false;
    }
}

bool isLeapYear(int year)
{
    bool is_leap_year;
    if (year % 400 == 0) {
        is_leap_year = true;
    } else if (year % 100 == 0) {
        is_leap_year = false;
    } else if (year % 4 == 0) {
        is_leap_year = true;
    } else {
        is_leap_year = false;
    }
    if (is_leap_year == true) {
        return true;
    } else {
        return false;
    }
}
