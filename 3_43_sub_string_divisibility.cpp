#include <array>
#include <iostream>
#include <vector>

/*
 * 0123456789
 */
int getDigitDec(int num)
{
    return static_cast<int>(std::to_string(num).size());
}

int power(int num, int power)
{
    int answer = 1;
    for (int i = 0; i < power; i++) {
        answer *= num;
    }
    return answer;
}

// 指定桁目を返す
int getDigitNumDec(int num, int digit)
{
    return (num % power(10, digit)) / power(10, digit - 1);
}

int main()
{
    // 下3桁
    std::vector<int> temp_17list;
    for (int i = 0; i * 17 < 1000; i++) {
        std::array<int, 3> digits;
        digits.at(2) = getDigitNumDec(i * 17, 3);
        digits.at(1) = getDigitNumDec(i * 17, 2);
        digits.at(0) = getDigitNumDec(i * 17, 1);
        if (digits.at(0) != digits.at(1) and digits.at(1) != digits.at(2) and digits.at(2) != digits.at(0)) {
            temp_17list.emplace_back(i * 17);
        }
    }
    std::vector<int> temp_13list;
    for (int i : {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}) {
        for (int temp_13 : temp_13list) {
            int temp = i * 100 + getDigitNumDec(temp_17, 3) * 10
                       + getDigitNumDec(temp_17, 2);
            if (temp % 13 == 0) {
                std::cout << i * 1000 + temp_17 << std::endl;
            }
        }
    }
    return 0;
}
