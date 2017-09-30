#include <iostream>

int culcSumOfSquare(int number);
int culcSquareOfSum(int number);

int main()
{
    std::cout << culcSquareOfSum(100) - culcSumOfSquare(100) << std::endl;
    return 0;
}

int culcSumOfSquare(int number) {
    int result = 0;
    for (int i = 1; i <= number; i++) {
        result += i * i;
    }
    return result;
}

int culcSquareOfSum(int number) {
    int result = 0;
    for (int i = 1; i <= number; i++) {
        result += i;
    }
    result = result * result;
    return result;
}
