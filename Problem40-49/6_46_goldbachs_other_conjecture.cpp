#include <cmath>
#include <iostream>

bool judgePrime(long number)
{
    if (number <= 1) {
        return false;
    }
    bool list[number];
    for (long i = 0; i < number; i++) {
        list[i] = true;
    }
    list[0] = false;
    long prime = 2;
    while (prime <= static_cast<long>(std::sqrt(number))) {
        long cnt1 = prime - 1;
        long cnt2 = prime;
        while (cnt1 < number) {
            list[cnt1] = false;
            cnt1 += prime;
        }
        for (long i = prime - 1; i < static_cast<long>(std::sqrt(number)); i++) {
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
long getDigitDec(long num)
{
    return std::to_string(num).size();
}

int main()
{
    for (long i = 9;; i += 2) {
        long j = 0;
        while (true) {
            if (judgePrime(i - 2 * j * j)) {
                break;
            }
            if (i - 2 * j * j < 0) {
                std::cout << "The answer is " << i << "." << std::endl;
                return 0;
            }
            j++;
        }
    }
    return 0;
}
