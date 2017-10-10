#include <iostream>
#include <array>

int main()
{
    std::array<int, 10> ones{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 9> tens{1, 2, 3, 4, 5, 6, 7, 8, 9};
    //denominator : 分母
    //numerator : 分子
    for (auto one_deno : ones) {
        for (auto ten_deno : tens) {
            for (auto one_nume : ones) {
                for (auto ten_nume : tens) {
                    if (one_deno == ten_nume and one_deno != ten_deno and one_nume != ten_nume) {
                        if ((ten_nume * 10 + one_nume) * ten_deno == one_nume * (ten_deno * 10 + ten_deno)) {
                            std::cout << (ten_nume * 10 + one_nume) << "/" << (ten_deno * 10 + one_deno) << std::endl;
                        }
                    }
                    if (one_nume == ten_deno and one_deno != ten_deno and one_nume != ten_nume) {
                        if ((ten_nume * 10 + one_nume) * one_deno == ten_nume * (ten_deno * 10 + one_deno)) {
                            std::cout << (ten_nume * 10 + one_nume) << "/" << (ten_deno * 10 + one_deno) << std::endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
