#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

template <typename T>
bool is_prime(const T n)
{
    if (n < 4)
        return n == 2 or n == 3;
    if (n % 2 == 0 or n % 3 == 0 or (n % 6 != 1 and n % 6 != 5))
        return false;
    for (T i = 5; i * i <= n; i += 6)
        if (n % i == 0 or n % (i + 2) == 0)
            return false;
    return true;
}

template <typename T, T MAX_NUM>
std::vector<T> primeList()
{
    std::vector<T> prime_list;
    std::array<bool, MAX_NUM + 1> prime{false};
    for (T i = 2; i <= MAX_NUM; i++) {
        if (not prime.at(i)) {
            prime.at(i) = true;
            prime_list.emplace_back(i);
            for (T j = 0; j <= MAX_NUM; j += i) {
                if (j != 0) {
                    prime.at(j) = true;
                }
            }
        }
    }
    return prime_list;
}

template <class T>
std::vector<std::vector<T>> primeListByEachDigit(const std::vector<T>& prime_list)
{
    std::vector<std::vector<T>> result;
    if (prime_list.size() <= 0) {
        std::cerr << "Invalid prime_list size" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    std::size_t digit_pre = 1;
    std::vector<T> prime_in_one_digit_group;
    for (const auto& prime : prime_list) {
        std::size_t digit_now = std::to_string(prime).size();
        if (digit_now > digit_pre) {
            result.emplace_back(prime_in_one_digit_group);
            prime_in_one_digit_group.clear();
            digit_pre = digit_now;
        }
        prime_in_one_digit_group.emplace_back(prime);
    }
    result.emplace_back(prime_in_one_digit_group);
    return result;
}


template <typename T>
std::vector<T> permutations(std::vector<T> str, std::size_t size)
{
    std::vector<T> result;
    return result;
}

int main()
{
    std::vector<uint64_t> prime_list = primeList<uint64_t, 1000000>();
    // prime list is divided into vectors by digits
    std::vector<std::vector<uint64_t>> prime_list_by_digit = primeListByEachDigit<uint64_t>(prime_list);
    // searching by each digit (iteration is minus 1)
    for (std::size_t digit = 1; digit <= prime_list_by_digit.size(); digit++) {
        for (const auto& p : prime_list_by_digit.at(digit - 1)) {
            // how many digit numbers we replace
            // eight out of 0123456789
            // 0, 1, 2 are the candidate num of smallest nums
            std::string s = std::to_string(p);
            for (const int& num : {0, 1, 2}) {
                // Var to store where the specific 'num's are.
                std::vector<std::size_t> num_places{};
                for (std::size_t i = 0; i < s.size(); i++) {
                    if (s.at(i) == std::to_string(num).at(0)) {
                        num_places.emplace_back(i);
                    }
                }
                if (num_places.size() == 0) {
                    continue;
                }

                // how many digit numbers we should increment
                for (std::size_t i = 1; i <= num_places.size(); i++) {
                    // ex) if s is 121187 and num_places are {0, 2, 3} and this var is {0, 2}, then we will evaluate *2*187
                    auto num_places_copy = num_places;
                    std::vector<int> latest{};
                    do {
                        std::vector<int> top{};
                        for (std::size_t j = 0; j < i; j++) {
                            top.emplace_back(num_places_copy.at(j));
                        }
                        if (latest != top) {
                            // cand num
                            int countdown = 8;
                            std::string s_copy = s;
                            for (int n = num; n <= 9; n++) {
                                for (const auto& place : num_places_copy) {
                                    s_copy.at(place) = std::to_string(n).at(0);
                                }
                                if (prime_list_by_digit.at(digit - 1).end() != std::find(prime_list_by_digit.at(digit - 1).begin(), prime_list_by_digit.at(digit - 1).end(), std::stoi(s_copy))) {
                                    countdown--;
                                }
                            }
                            if (countdown == 0) {
                                std::cout << s << " " << num << " ";
                                for (const auto& place : num_places) {
                                    std::cout << place << " ";
                                }
                                std::cout << std::endl;
                                return;
                            }
                        }
                        latest = top;
                    } while (std::next_permutation(num_places_copy.begin(), num_places_copy.end()));
                }
            }
        }
    }

    return 0;
}
