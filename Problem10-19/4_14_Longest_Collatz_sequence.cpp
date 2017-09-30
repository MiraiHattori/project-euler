#include <iostream>

void recursive();
void subRecursive(unsigned long long n);

int answer_num = 0;
unsigned long long answer = 0;

namespace recursively {
    int result = 0;
}

int main()
{
    recursive();
    return 0;
}

void recursive() {
    for (unsigned long long i = 1; i <= 1000000; i++) {
        if (i == 1) {
        } else {
            std::cout << i << " ";
        }
        unsigned long long n = i;
        subRecursive(n);
        if (answer_num < recursively::result) {
            answer_num = recursively::result;
            answer = n;
        }
        std::cout << recursively::result << std::endl;
        recursively::result = 0;
    }
    std::cout << answer << std::endl;
}

void subRecursive(unsigned long long n) {
    if (n == 1) {
//        std::cout << std::endl;
        recursively::result++;
    } else if (n % 2 == 0) {
//        std::cout << n / 2 << " ";
        recursively::result++;
        subRecursive(n / 2);
    } else if (n % 2 == 1) {
//        std::cout << 3 * n + 1 << " ";
        recursively::result++;
        subRecursive(3 * n + 1);
    } else {
        std::cout << "Abort." << std::endl;
        return;
    }
}
