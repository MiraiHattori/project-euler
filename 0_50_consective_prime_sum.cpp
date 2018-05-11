#include <array>
#include <iostream>
#include <vector>

/*
 * Find the prime number below one-million that can be written as the sum of most consecutive primes.
 */

template <class T>
bool is_prime(const T n)
{
    if (n < 4)
        return n == 2 || n == 3;
    if (n % 2 == 0 || n % 3 == 0 || (n % 6 != 1 && n % 6 != 5))
        return false;
    for (T i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

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
int main()
{
    constexpr uint64_t ONE_MILLION = 1000000;
    std::vector<uint64_t> prime_list = primeList<uint64_t, ONE_MILLION>();
    uint64_t max_consecutive_num = 0;
    // finding max_consecutive_num
    {
        uint64_t sum = 0;
        for (uint64_t i = 0; i < prime_list.size(); i++) {
            sum += prime_list.at(i);
            if (sum < ONE_MILLION) {
                max_consecutive_num = i;
            }
        }
    }

    uint64_t result;
    for (uint64_t i = 3; i < max_consecutive_num; i++) {
        for (uint64_t j = 0; j < prime_list.size(); j++) {
            uint64_t sum = 0;
            bool is_over = false;
            for (uint64_t k = 0; k < i; k++) {
                if (sum > ONE_MILLION) {
                    is_over = true;
                } else if (j + k < prime_list.size()) {
                    sum += prime_list.at(j + k);
                } else {
                    is_over = true;
                    break;
                }
                if (k == i - 1 and sum > ONE_MILLION) {
                    is_over = true;
                }
            }
            if (is_over) {
                break;
            }
            if (is_prime<uint64_t>(sum)) {
                result = sum;
                // std::cout << sum << std::endl;
                //std::cout << j << " " << i << std::endl;
            }
        }
    }
    std::cout << result << std::endl;

    return 0;
}
