#include <iostream>

void conbination(int n, int r);

int main() {
    conbination(40, 20);
    return 0;
}

void conbination(int n, int r) {
    double answer = 1;
    if (n <= r || n <= 0) {
        std::cout << "考えていない" << std::endl;
    }
    
    for (int i = 0; i < r; i++) {
        answer *= (double)(n - i) / (double)(i + 1);
    }
    std::cout << (unsigned long long)answer << std::endl;
}

