#include <iostream>
#include <cmath>

void pythagoreanTriplet(int number);
int main()
{
    pythagoreanTriplet(1000);
    return 0;
}

void pythagoreanTriplet(int number) {
    for (int c = (int)(number / (2 + sqrt(2))); c < number; c++) {
        for (int a = 1; a < (number - c) / 2; a++) {
            if (a * a + (number - a - c) * (number - a - c) == c * c) {
                std::cout << a << ":a " << number - a - c << ":b " << c << ":c " << a * (number - a - c) * c << ": result" << std::endl;
            }
        }
    }
}
