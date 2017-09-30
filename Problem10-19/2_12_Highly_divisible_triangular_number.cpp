#include <iostream>
#include <cmath>

static int sum(int n);
static int cntDivisor(int n);
static void findTriangleN();

int main()
{
    findTriangleN();
    return 0;
}

static int sum(int n) {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += i;
    }
    return result;
}

static int cntDivisor(int n) {
    int result = 0;
    for (int i = 1; i < (int)(std::sqrt(n)); i++) {
        if (n % i == 0) {
            result += 2;
        }
    }
    if (std::sqrt(n) - (int)(std::sqrt(n)) == 0) {
        result++;
    }
    return result;
}

static void findTriangleN() {
    int i = 0;
    bool loop = true;
    int result;
    while (loop) {
        if (cntDivisor(sum(i)) <= 500) {
            i++;
        } else {
            result = sum(i);
            break;
        }
    }
    std::cout << result << std::endl;
}
