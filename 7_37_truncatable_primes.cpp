#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

bool judgePrime(long number)
{
    if (number <= 1) {
        return false;
    }
    long list[number];
    for (long i = 0; i < number; i++) {
        list[i] = i + 1;
    }
    list[0] = 0;
    long prime = 2;
    while (prime <= static_cast<long>(std::sqrt(number))) {
        long cnt1 = prime - 1;
        long cnt2 = prime;
        while (cnt1 < number) {
            list[cnt1] = 0;
            cnt1 += prime;
        }
        for (long i = prime - 1; i < static_cast<long>(std::sqrt(number)); i++) {
            if (list[i] != 0) {
                prime = i + 1;
                break;
            }
        }
        if (prime == cnt2) {
            break;
        }
    }
    return list[number - 1] != 0;
}

long getDigitDec(long long num)
{
    return std::to_string(num).size();
}

long power(long num, long power)
{
    long answer = 1;
    for (long long i = 0; i < power; i++) {
        answer *= num;
    }
    return answer;
}

bool isRightTruncatable(long long num)
{
    long digit = getDigitDec(num);
    for (long i = 1; i < digit; i++) {
        if (not judgePrime(num / power(10, i))) {
            return false;
        }
    }
    return true;
}

int main()
{
    long answer = 0;
    // digit, num
    std::vector<std::vector<long long>> num_lists;
    std::vector<long long> num_list;
    //num_list.emplace_back(2);
    num_list.emplace_back(3);
    //num_list.emplace_back(5);
    num_list.emplace_back(7);
    num_lists.emplace_back(num_list);
    long digit = 1;
    long found_num_num = 0;
    while (found_num_num < 11) {
        std::vector<long long> num_list;
        for (long num : num_lists.at(digit - 1)) {
            for (long i = 1; i < 10; i++) {
                long long candidate = num + i * power(10, digit);
                //std::cout << candidate << std::endl;
                if (judgePrime(candidate)) {
                    num_list.emplace_back(candidate);
                    if (isRightTruncatable(candidate)) {
                        std::cout << "this is one of the answer: " << candidate << std::endl;
                        answer += candidate;
                        found_num_num++;
                    }
                }
            }
        }
        num_lists.emplace_back(num_list);
        digit++;
    }
    std::cout << "The answer is " << answer << std::endl;
    return 0;
}
