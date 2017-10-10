#include <array>
#include <iostream>

/*
 * 3 <= p <= 1000
 * a + b + c = pとして、1 <= a <= b <= c < p / 2
 */

int main()
{
    std::array<int, 1000> num_list{};
    for (int p = 3; p <= 1000; p++) {
        for (int i = 1; i <= p / 3; i++) {
            for (int j = i; j <= p / 2; j++) {
                if (i * i + j * j == (p - i - j) * (p - i - j)) {
                    // std::cout << i << " " << j << " " << p - i - j << std::endl;
                    num_list.at(p - 1)++;
                }
            }
        }
    }
    int max = -1;
    int answer = -1;
    for (int i = 0; i < 1000; i++) {
        if (num_list.at(i) > max) {
            max = num_list.at(i);
            answer = i + 1;
        }
    }
    std::cout << "The answer is " << answer << "." << std::endl;
    return 0;
}
