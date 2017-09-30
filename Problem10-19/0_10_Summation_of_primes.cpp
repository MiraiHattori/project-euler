#include <iostream>
#include <stack>
#include <sys/time.h>
#include <array>
#include <cmath>

#define NUMBER 2000000

double gettimeofday_sec();

void sumPrime();
int main(void)
{
    double t1, t2;
    t1 = gettimeofday_sec();
    sumPrime();
    t2 = gettimeofday_sec();
    printf("%f\n", t2 - t1);
    return 0;
}

double gettimeofday_sec()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec * 1e-6;
}

void sumPrime()
{
    std::array<int, NUMBER> list;
    for (int i = 0; i < NUMBER; i++) {
        list[i] = i + 1;
    }
    list[0] = 0;
    int prime = 2;
    bool end = false;
    while (end == false) {
        int i1 = prime - 1;
        while (i1 + prime - 1 < NUMBER) {
            list[i1 + prime] = 0;
            i1 += prime;
        }
        end = true;
        for (int i = 0; i < (int)sqrt(NUMBER) + 1; i++) {
            if (list[i] > prime) {
                prime = list[i];
                end = false;
                break;
            }
        }
    }
    unsigned long long result = 0;
    for (int temp = 0; temp < NUMBER; temp++) {
        result += list[temp];
    }
    std::cout << result << std::endl;
}
