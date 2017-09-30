#include <iostream>
#include <string>
#include <cmath>

bool judgePrime(long number)
{
    long list[number];
    for (long i = 0; i < number; i++) {
        list[i] = i + 1;
    }
    list[0] = 0;
    long prime = 2;
    while (prime <= std::sqrt(number)) {
        long cnt1 = prime - 1;
        long cnt2 = prime;
        while (cnt1 < number) {
            list[cnt1] = 0;
            cnt1 += prime;
        }
        for (long i = prime - 1; i < std::sqrt(number); i++) {
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

unsigned long getDigit(long number)
{
    return std::to_string(number).size();
}


unsigned long power(unsigned long num, unsigned long power)
{
    unsigned long a = 1;
    for (unsigned long i = 0; i < power; i++) {
        a *= num;
    }
    return a;
}

int main()
{
    for (long i = 0; i < 1000000; i++) {
        if (judgePrime(i)) {
            bool is_circle = true;
            long a = i;
            for (unsigned long j = 1; j < getDigit(i) and is_circle; j++) {
                long b = a % 10;
                long c = b / 10;
                a = b * power(10, getDigit(i)) + c;
                if (not judgePrime(a)) {
                    is_circle = false;
                }
            }
            if (is_circle) {
                std::cout << i << std::endl;
            }
        }
    }

    return 0;
}
