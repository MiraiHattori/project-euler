#include <iostream>

/*
 * 91827365はpandigitalより、最高位は9
 * 続けた文字は掛け算ではなく10進数での数字
 * a=1,b=2 -> ab=12
 * 1.
 *  9bcd * 1 = 9bcd
 *  9bcd * 2 = 1fghi
 * 2.
 *  9bc * 1 = 9bc
 *  9bc * 2 = efg -> ありえない
 *  9bc * 3 = hij
 * 3.
 *  9b * 1 = 9b
 *  9b * 2 = cd -> ありえない
 *  9b * 3 = ef
 *  9b * 4 = 1hi
 * 4.
 *  9 * 1 = 9
 *  9 * 2 = 18
 *  9 * 3 = 27
 *  9 * 4 = 36
 *  9 * 5 = 45
 * 以上より、9bcd * 2 = 1fghiなるもので、918273645以上のものを見つける
 */

int main()
{
    for (int b : {2, 3, 4, 5, 6, 7, 8}) {
        for (int c : {2, 3, 4, 5, 6, 7, 8}) {
            if (c != b) {
                for (int d : {2, 3, 4, 6, 7, 8}) {
                    if (d != c and d != b) {
                        int num = 9000 + b * 100 + c * 10 + d;
                        int num_double = num * 2;
                        bool is_conflict_with_num = false;
                        for (int i = 0; i < 5; i++) {
                            int digit = num_double % 10;
                            if (digit == b or digit == c or digit == d or digit == 9) {
                                is_conflict_with_num = true;
                            }
                            num_double = (num_double - digit) / 10;
                        }
                        if (not is_conflict_with_num) {
                            std::cout << num << " " << num * 2 << std::endl;
                        }
                    }
                }
            }
        }
    }
    std::cout << "この中から数字が被ってないやつを選べ。935218704がそれに該当する" << std::endl;
    return 0;
}
