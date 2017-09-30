#include <iostream>
#include <stack>
#include <cmath>
bool judgePrime(long number);
int main(void)
{
    int answer = 0;
    int kotae_i;
    int kotae_j;
    for (int i = -1000; i <= 1000; i++) {
        for (int j = -1000; j <= 1000; j++) {
            int n = 0;
            while (n * n + i * n + j > 1 && judgePrime(n * n + i * n + j) == true) {
                n++;
            }
            if (n > answer) {
                answer = n;
                kotae_i = i;
                kotae_j = j;
            }
            //            std::cout << i << " " << j << std::endl;
        }
    }
    //    std::cout << answer << "個の素数、iは" << kotae_i << "、jは" << kotae_j << "。" << std::endl;
    std::cout << kotae_i* kotae_j << std::endl;
    return 0;
}

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
