#include <iostream>
#define DIAGONAL_SIZE 1001

int main()
{
    long answer = 1;
    for (int i = 1; i <= (DIAGONAL_SIZE - 1) / 2; i++) {
        answer += (2 * i + 1) * (2 * i + 1) * 4 - 12 * i;
    }
    std::cout << answer << std::endl;
    return 0;
}
