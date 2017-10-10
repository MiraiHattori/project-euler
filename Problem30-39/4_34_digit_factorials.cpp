#include <iostream>

int power(int num)
{
    if (num == 0) {
        return 1;
    } else if (num == 1) {
        return 1;
    } else if (num == 2) {
        return 2;
    } else if (num == 3) {
        return 6;
    } else if (num == 4) {
        return 24;
    } else if (num == 5) {
        return 120;
    } else if (num == 6) {
        return 720;
    } else if (num == 7) {
        return 5040;
    } else if (num == 8) {
        return 40320;
    } else if (num == 9) {
        return 362280;
    } else {
        std::cout << "error in line" << __LINE__ << std::endl;
        return 0;
    }
}

int isBigEnough(int num, int thresh)
{
    return num < thresh ? 0 : 1;
}


int main()
{
    for (int i = 0; i < 100000000; i++) {
        if (0
                + power(i % 100000000 / 10000000) * isBigEnough(i, 10000000)
                + power(i % 10000000 / 1000000) * isBigEnough(i, 1000000)
                + power(i % 1000000 / 100000) * isBigEnough(i, 100000)
                + power(i % 100000 / 10000) * isBigEnough(i, 10000)
                + power(i % 10000 / 1000) * isBigEnough(i, 1000)
                + power(i % 1000 / 100) * isBigEnough(i, 100)
                + power(i % 100 / 10) * isBigEnough(i, 10)
                + power(i % 10 / 1) * isBigEnough(i, 1)
            == i) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}
