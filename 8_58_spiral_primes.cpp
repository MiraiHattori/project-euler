#include <array>
#include <iostream>
#include <vector>

template <class T>
bool isPrime(const T n)
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

int main()
{
    int side_length = 1;
    int candidate_num = 1;
    int prime_num = 0;
    while (true) {
        side_length += 2;
        candidate_num += 4;
        prime_num += static_cast<int>(isPrime<int>(side_length * side_length - (side_length - 1) * 0))
                     + static_cast<int>(isPrime<int>(side_length * side_length - (side_length - 1) * 1))
                     + static_cast<int>(isPrime<int>(side_length * side_length - (side_length - 1) * 2))
                     + static_cast<int>(isPrime<int>(side_length * side_length - (side_length - 1) * 3));
        if (prime_num * 10 < candidate_num) {
            break;
        }
    }
    std::cout << side_length << std::endl;
    return 0;
}
