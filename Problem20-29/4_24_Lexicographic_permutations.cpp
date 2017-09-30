#include <iostream>
#include <array>
#include <stack>

int main()
{
    std::array<int, 10> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 1; i < 1000000; i++) {
        int j = 0;
        while (j < 9 && numbers.at(8 - j) > numbers.at(9 - j)) {
            j++;
        }

        int cnt = 0;
        while (cnt < 9 && numbers.at(8 - j) == numbers.at(9 - j) + 1) {
            cnt++;
        }
        if (cnt == j && numbers.at(8 - j) == 8 - j) {
            numbers.at(8 - j) = 9 - j;
            numbers.at(9 - j) = 8 - j;
            for (int k = 10 - j; k < 10; k++) {
                numbers.at(k) = k;
            }
        } else {
            //std::cout << j << std::endl;
            int temp_k = 9;
            for (int k = 8 - j; k < 10; k++) {
                if (numbers.at(k) > numbers.at(8 - j) && numbers.at(k) <= temp_k) {
                    temp_k = numbers.at(k);
                }
            }
            int temp_n = numbers.at(8 - j);
            numbers.at(8 - j) = temp_k;
            std::stack<int> temp;
            for (int k = 9 - j; k < 10; k++) {
                if (numbers.at(k) == temp_k) {
                    temp.push(temp_n);
                } else {
                    temp.push(numbers.at(k));
                }
            }
            for (int k = 9 - j; k < 10; k++) {
                numbers.at(k) = temp.top();
                temp.pop();
            }
        }
    }
    for (int k = 0; k < 10; k++) {
        std::cout << numbers.at(k);
    }
    std::cout << std::endl;
    return 0;
}
