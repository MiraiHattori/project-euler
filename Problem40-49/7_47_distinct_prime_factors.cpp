#include <algorithm>
#include <array>
#include <iostream>
#include <vector>


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

template <class T>
bool isFourDistinctPrime(T num, const std::vector<T>& prime_list)
{
    int prime_num = 0;
    T i{0};
    T n = num;
    bool result = false;
    while (true) {
        if (i == prime_list.size()) {
            break;
        }
        if (n % prime_list.at(i) == 0) {
            prime_num++;
            while (n % prime_list.at(i) == 0) {
                n /= prime_list.at(i);
            }
        }
        i++;
        if (prime_num == 4 and n == 1) {
            result = true;
            break;
        } else if (prime_num > 4) {
            break;
        }
    }
    return result;
}


int main()
{
    uint64_t i = 1;
    std::array<bool, 4 - 1> pre_ok;
    while (true) {
        bool is_ok = isFourDistinctPrime<uint64_t>(i, primeList<uint64_t, 100000>());
        if (pre_ok.at(0) and pre_ok.at(1) and pre_ok.at(2) and is_ok) {
            std::cout << i - 4 + 1 << std::endl;
            break;
        }
        pre_ok.at(2) = pre_ok.at(1);
        pre_ok.at(1) = pre_ok.at(0);
        pre_ok.at(0) = is_ok;
        i++;
    }

    return 0;
}
