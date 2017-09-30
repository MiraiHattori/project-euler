#include <iostream>
#include <stack>
#include <cmath>


int digit(int n);

int main()
{
    int result = 0;
    for (int i = 1; i <= 1000; i++) {
        int temp = (int)pow(10, digit(i));
        int list[1000] = {0};
        int list_cnt = 0;
        bool reputation = false;
        for (int j = 0; j < 1000; j++) {
            temp = temp % i;
            if (temp % i == 0 || reputation == true) {
                break;
            } else {
                for (int cnt1 = 0; cnt1 < 1000; cnt1++) {
                    if (temp == list[cnt1]) {
                        reputation = true;
                        break;
                    }
                }
                if (reputation == false) {
                    list[list_cnt] = temp;
                    list_cnt++;
                }
            }
            temp *= 10;
        }
        int p = 0;
        int answer = 0;
        while (list[p] != 0) {
            answer++;
            p++;
        }
        if (answer > result) {
            result = i;
        }
    }
    std::cout << result << std::endl;
    return 0;
}
int digit(int n)
{
    int result = 0;
    int temp = 1;  //10^answer
    while (temp <= n) {
        temp *= 10;
        result++;
    }
    return result;
}
