#include <iostream>
#include <cmath>

static int sumDivisor(int n);

int main()
{
    int kotae = 0;
    for (int i = 1; i <= 10000; i++) {
        for (int j = i + 1; j <= 10000; j++) {
            if (sumDivisor(i) == j && sumDivisor(j) == i) {
                kotae += i + j;
            }
        }
    }
    std::cout << kotae << std::endl;
    return 0;
}


static int sumDivisor(int n)
{
    if (n != 1) {
        int result = 1;  //1とnがペアだからnを除く
        for (int i = 2; i < std::sqrt(n); i++) {
            if (n % i == 0) {
                result += i + n / i;
            }
        }
        if (std::sqrt(n) - (int)(std::sqrt(n)) == 0) {
            result += (int)std::sqrt(n);
        }
        return result;
    } else {
        return 0;
    }
}
