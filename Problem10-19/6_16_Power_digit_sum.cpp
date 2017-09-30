#include <iostream>


namespace {
    int answer[500] = {0};
    int temp[500] = {0};
}

int main()
{
    ::answer[0] = 1;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 400; j++) {
            ::temp[j] = ::answer[j] * 2;
        }
        for (int j = 0; j < 400; j++) {
            if (::temp[j] >= 20) {
                ::temp[j] -= 20;
                ::temp[j + 1] += 2;
            } else if (::temp[j] >= 10) {
                ::temp[j] -= 10;
                ::temp[j + 1] += 1;
            }
        }
        for (int j = 0; j < 500; j++) {
            ::answer[j] = ::temp[j];
        }
    }
    int kotae = 0;
    for (int i = 0; i < 400; i++) {
        kotae += ::answer[i];
    }
    std::cout << kotae << std::endl;
    return 0;
}
