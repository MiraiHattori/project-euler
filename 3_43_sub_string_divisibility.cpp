#include <algorithm>
#include <array>
#include <iostream>
#include <list>
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


std::vector<int> numList(int digit, int divisor, std::vector<int> temp_list)
{
    // 結果の代入
    std::vector<int> result_list;
    for (int temp : temp_list) {
        std::list<int> digit_num_list = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 0; i < digit; i++) {
            digit_num_list.remove(getDigitNumDec(temp, i + 1));
        }
        for (int digit_num : digit_num_list) {
            int candidate = digit_num * power(10, 2) + getDigitNumDec(temp, digit) * 10 + getDigitNumDec(temp, digit - 1);
            if (candidate % divisor == 0) {
                result_list.emplace_back(digit_num * power(10, digit) + temp);
            }
        }
    }
    return result_list;
}

int main()
{
    // 下3桁
    std::vector<int> temp_17list;
    for (int i = 0; i * 17 < 1000; i++) {
        std::array<int, 3> digits;
        for (int j = 0; j < 3; j++) {
            digits.at(j) = getDigitNumDec(i * 17, j + 1);
        }
        if (digits.at(0) != digits.at(1) and digits.at(1) != digits.at(2) and digits.at(2) != digits.at(0)) {
            temp_17list.emplace_back(i * 17);
        }
    }
    std::vector<int> temp_13list = numList(3, 13, temp_17list);
    std::vector<int> temp_11list = numList(4, 11, temp_13list);
    std::vector<int> temp_7list = numList(5, 7, temp_11list);
    std::vector<int> temp_5list = numList(6, 5, temp_7list);
    std::vector<int> temp_3list = numList(7, 3, temp_5list);
    std::vector<int> temp_2list = numList(8, 2, temp_3list);
    std::sort(temp_2list.begin(), temp_2list.end(), [](int a, int b) { return a > b; });
    long long answer = 0;
    for (int temp : temp_2list) {
        std::list<int> digit_num_list = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 0; i < 9; i++) {
            digit_num_list.remove(getDigitNumDec(temp, i + 1));
        }
        for (int digit_num : digit_num_list) {
            answer += static_cast<long long>(digit_num) * static_cast<long long>(power(10, 9)) + static_cast<long long>(temp);
        }
    }
    std::cout << "The answer is " << answer << "." << std::endl;

    return 0;
}
