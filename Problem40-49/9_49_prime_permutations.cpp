#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>


/*
 * Find arithmetic sequence as below.
 * There are three terms in a sequence.
 * Three terms form an arithmetic sequence.
 * Each of three terms are prime.
 * Each of the 12-digit numbers are permutations of one another.
 */

template <class T, T MAX_NUM>
std::vector<T> primeList()
{
    std::vector<T> primes;
    std::array<bool, MAX_NUM + 1> prime{false};
    for (T i = 2; i <= MAX_NUM; i++) {
        if (not prime.at(i)) {
            prime.at(i) = true;
            primes.emplace_back(i);
            for (T j = 0; j <= MAX_NUM; j += i) {
                if (j != 0) {
                    prime.at(j) = true;
                }
            }
        }
    }
    return primes;
}

namespace MyUtil
{
std::string sort(uint64_t num)
{
    std::string s = std::to_string(num);
    std::string str = "";
    std::vector<char> chars;
    for (const auto& c : s) {
        chars.emplace_back(c);
    }
    std::sort(chars.begin(), chars.end());
    for (const auto& c : chars) {
        str += c;
    }
    return str;
}
}


int main()
{
    std::vector<uint64_t> prime_list = primeList<uint64_t, 10000>();
    for (uint16_t i = 0; i < prime_list.size(); i++) {
        for (uint16_t j = i + 1; j < prime_list.size(); j++) {
            decltype(prime_list)::iterator it
                = std::find(prime_list.begin(), prime_list.end(), prime_list.at(j) * 2 - prime_list.at(i));
            if (it != prime_list.end()) {
                uint64_t first = prime_list.at(i);
                uint64_t second = prime_list.at(j);
                uint64_t third = *it;
                if (MyUtil::sort(first) == MyUtil::sort(second) and MyUtil::sort(second) == MyUtil::sort(third)) {
                    std::cout << first << second << third << std::endl;
                }
            }
        }
    }
    return 0;
}
