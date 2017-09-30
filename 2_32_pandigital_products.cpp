#include <iostream>
#include <array>

bool isPandigital(int a_1, int a_2, int a_3, int a_4, int a_5, int a_6, int a_7, int a_8, int a_9)
{
    std::array<int, 10> digits{0};
    digits.at(a_1)++;
    digits.at(a_2)++;
    digits.at(a_3)++;
    digits.at(a_4)++;
    digits.at(a_5)++;
    digits.at(a_6)++;
    digits.at(a_7)++;
    digits.at(a_8)++;
    digits.at(a_9)++;
    int a = 1;
    for (int i = 1; i < 10; i++) {
        a *= digits.at(i);
    }
    if (a == 1) {
        return true;
    } else {
        return false;
    }
}


constexpr int power()
{
    return 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
}


int main()
{
    std::array<int, 10> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (const auto& num_1 : nums) {
        for (const auto& num_2 : nums) {
            for (const auto& num_3 : nums) {
                for (const auto& num_4 : nums) {
                    for (const auto& num_5 : nums) {
                        int num = num_1 * (num_2 * 1000 + num_3 * 100 + num_4 * 10 + num_5);
                        if (num >= 10000) {
                        } else if (num < 1000) {
                        } else {
                            int thousand = num / 1000;
                            int hundred = (num % 1000) / 100;
                            int ten = (num % 100) / 10;
                            int one = num % 10 / 1;
                            if (isPandigital(num_1, num_2, num_3, num_4, num_5, thousand, hundred, ten, one)) {
                                std::cout << num_1 << " " << num_2 << num_3 << num_4 << num_5 << " " << num << std::endl;
                            }
                        }
                        int num2 = (num_1 * 10 + num_2) * (num_3 * 100 + num_4 * 10 + num_5);
                        if (num2 >= 10000) {
                        } else if (num2 < 1000) {
                        } else {
                            int thousand = num2 / 1000;
                            int hundred = (num2 % 1000) / 100;
                            int ten = (num2 % 100) / 10;
                            int one = num2 % 10 / 1;
                            if (isPandigital(num_1, num_2, num_3, num_4, num_5, thousand, hundred, ten, one)) {
                                std::cout << num_1 << " " << num_2 << num_3 << num_4 << num_5 << " " << num2 << std::endl;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
