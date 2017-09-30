#include <iostream>
#include <cmath>


namespace hoge
{
int ab_list[6965] = {};  //list of abundant numbers less than 28124
};

using namespace hoge;
static void makeAbList();
static int sumDivisor(int n);
static void isSumTwo();

int main()
{
    makeAbList();
    isSumTwo();
    return 0;
}


static void makeAbList()
{
    for (int i = 1; i <= 28123; i++) {
        if (sumDivisor(i) > i) {
            int j = 0;
            while (ab_list[j] != 0) {
                j++;
            }
            ab_list[j] = i;
        }
    }
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
static void isSumTwo()
{
    int kotae = 0;
    for (int i = 1; i <= 28123; i++) {
        bool is_sum = false;
        for (int j = 0; j < 6965; j++) {
            if (ab_list[j] == 0) {
                break;
            }
            if (i - ab_list[j] > 0) {
                if (sumDivisor(i - ab_list[j]) > i - ab_list[j]) {
                    is_sum = true;
                    break;
                }
            }
        }
        if (is_sum == false) {
            kotae += i;
        }
    }
    std::cout << kotae << std::endl;
}
