#include <iostream>
#include <cmath>

void judgePrimeNumber(long number);

int main()
{
    judgePrimeNumber(600851475143);
    judgePrimeNumber(2867);
    judgePrimeNumber(901);
    return 0;
}

void judgePrimeNumber(long number)
{
    long original_number = number;
    std::cout << original_number << " を素因数分解" << std::endl;
    long result = 1;
    if (!(number > 0) || number % 1 != 0) {
        std::cout << "The number should be an integer more than zero." << std::endl;
    }
    while (number % 2 == 0) {
        number /= 2;
        result = 2;
        std::cout << 2 << std::endl;
    }
    while (number % 3 == 0) {
        number /= 3;
        result = 3;
        std::cout << 3 << std::endl;
    }
    while (number % 5 == 0) {
        number /= 5;
        result = 5;
        std::cout << 5 << std::endl;
    }

    long prime = 7;
    while (prime < static_cast<long>(sqrt(static_cast<long>(number)))) {
        while (number % prime == 0) {
            number /= prime;
            result = prime;
            std::cout << prime << std::endl;
        }
        prime += 4;

        while (number % prime == 0) {
            number /= prime;
            result = prime;
            std::cout << prime << std::endl;
        }
        prime += 2;
    }
    if (number > prime) {
        result = static_cast<long>(number);
    }
    std::cout << "The answer is " << result << "." << std::endl;
    std::cout << original_number << " を素因数分解終了" << std::endl;
}
