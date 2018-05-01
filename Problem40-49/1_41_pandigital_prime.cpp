#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

/*
 * 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45よりn != 9
 * 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 = 36よりn != 8
 * 1 + 2 + 3 + 4 + 5 + 6 = 21よりn != 6
 * 1 + 2 + 3 + 4 + 5 = 15よりn != 5
 * n == 4は2143が素数なので存在する
 * n == 7から探索する
 */

bool judgePrime(int number)
{
    if (number <= 1) {
        return false;
    }
    bool list[number];
    for (int i = 0; i < number; i++) {
        list[i] = true;
    }
    list[0] = false;
    int prime = 2;
    while (prime <= static_cast<int>(std::sqrt(number))) {
        int cnt1 = prime - 1;
        int cnt2 = prime;
        while (cnt1 < number) {
            list[cnt1] = false;
            cnt1 += prime;
        }
        for (int i = prime - 1; i < static_cast<int>(std::sqrt(number)); i++) {
            if (list[i]) {
                prime = i + 1;
                break;
            }
        }
        if (prime == cnt2) {
            break;
        }
    }
    return list[number - 1];
}
int getDigitDec(int num)
{
    return std::to_string(num).size();
}

int main()
{
    // n = 7前提
    std::array<int, 8> digit;
    // 桁数とat()の引数を揃えるため0番を捨てる
    digit.at(0) = 0;
    for (digit.at(7) = 7; digit.at(7) >= 1; digit.at(7)--) {
        for (digit.at(6) = 7; digit.at(6) >= 1; digit.at(6)--) {
            if (digit.at(6) == digit.at(7)) {
                continue;
            }
            for (digit.at(5) = 7; digit.at(5) >= 1; digit.at(5)--) {
                if (digit.at(5) == digit.at(6) or digit.at(5) == digit.at(7)) {
                    continue;
                }
                for (digit.at(4) = 7; digit.at(4) >= 1; digit.at(4)--) {
                    if (digit.at(4) == digit.at(5) or digit.at(4) == digit.at(6) or digit.at(4) == digit.at(7)) {
                        continue;
                    }
                    for (digit.at(3) = 7; digit.at(3) >= 1; digit.at(3)--) {
                        if (digit.at(3) == digit.at(4) or digit.at(3) == digit.at(5) or digit.at(3) == digit.at(6) or digit.at(3) == digit.at(7)) {
                            continue;
                        }
                        for (digit.at(2) = 7; digit.at(2) >= 1; digit.at(2)--) {
                            if (digit.at(2) == digit.at(3) or digit.at(2) == digit.at(4) or digit.at(2) == digit.at(5) or digit.at(2) == digit.at(6) or digit.at(2) == digit.at(7)) {
                                continue;
                            }
                            for (digit.at(1) = 7; digit.at(1) >= 1; digit.at(1)--) {
                                if (digit.at(1) == digit.at(2) or digit.at(1) == digit.at(3) or digit.at(1) == digit.at(4) or digit.at(1) == digit.at(5) or digit.at(1) == digit.at(6) or digit.at(1) == digit.at(7)) {
                                    continue;
                                }
                                int num = digit.at(7) * 1000000 + digit.at(6) * 100000 + digit.at(5) * 10000 + digit.at(4) * 1000 + digit.at(3) * 100 + digit.at(2) * 10 + digit.at(1);
                                if (judgePrime(num)) {
                                    std::cout << num << std::endl;
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
