#include <iostream>
#include <stack>
#include <sys/time.h>

void primeNumber(int number);

double gettimeofday_sec();


int main(void)
{
    double t1, t2;
    t1 = gettimeofday_sec();
    primeNumber(10001);
    t2 = gettimeofday_sec();
    std::cout << "The elasped time is " << t2 - t1 << " sec." << std::endl;

    return 0;
}

void primeNumber(int number) {
    std::stack<int> seq;
    std::cout << seq.size() << " :seq.size()" << std::endl;
	int result;
    if (number == 1) {
        result = 2;
    } else if (number == 2) {
        result = 3;
    } else if (number == 3) {
        result = 5;
    } else {
        seq.push(2);
        seq.push(3);
        seq.push(5);
        int i = 4;
        result = 7;
        while (i <= number) {
            auto temp = seq;
            bool is_prime = true;
            for (int j = 0; j < (int)seq.size(); j++) {
                if (result % temp.top() == 0) {
                    is_prime = false;
                }
                temp.pop();
            }
            if (is_prime == true) {
                seq.push(result);
                i++;
            }
            result += 2;
        }
        result = seq.top();
    }
    std::cout << result << std::endl;
}

double gettimeofday_sec()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec * 1e-6;
}
