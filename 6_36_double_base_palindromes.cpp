#include <algorithm>
#include <iostream>
#include <string>

template <typename T>
inline std::string toBinStr(T n)
{
    std::string str;
    while (n > 0) {
        str.push_back(static_cast<char>('0' + (n & 1)));
        n >>= 1;
    }
    std::reverse(str.begin(), str.end());
    return str;
}

long getDigitDec(long long num)
{
    return std::to_string(num).size();
}

long getDigitBin(long long num)
{
    long long temp = num;
    long digit = 0;
    while ((temp >> digit) > 0) {
        digit++;
    }
    return digit;
}

long long power(long long num, long long power)
{
    long long answer = 1;
    for (long long i = 0; i < power; i++) {
        answer *= num;
    }
    return answer;
}

// 10進数で回文か
bool isPalindromeDec(long long num)
{
    long digit = getDigitDec(num);
    // 回文かどうかの判断のため最上位と最下位を消していく
    long long temp = num;
    // 最下位が0なら間違いなく回文ではない
    if (temp % 10 == 0) {
        return false;
    }
    for (int i = 0; i < digit / 2; i++) {
        // 最上位
        long long a = temp / power(10, digit - i * 2 - 1);
        // 最下位
        long long b = temp % 10;
        if (a == b) {
            temp -= a * (power(10, digit - i * 2 - 1) + 1);
            temp /= 10;
        } else {
            return false;
        }
    }
    return true;
}
// 2進数で回文か
bool isPalindromeBin(long long num)
{
    long digit = getDigitBin(num);
    // 回文かどうかの判断のため最上位と最下位を消していく
    long long temp = num;
    // 最下位が0なら間違いなく回文ではない
    if (temp % 2 == 0) {
        return false;
    }
    for (int i = 0; i < digit / 2; i++) {
        // 最上位
        long long a = temp / power(2, digit - i * 2 - 1);
        // 最下位
        long long b = temp % 2;
        if (a == b) {
            temp -= a * (power(2, digit - i * 2 - 1) + 1);
            temp /= 2;
        } else {
            return false;
        }
    }
    return true;
}

int main()
{
    int answer = 0;
    for (long long i = 0; i < 1000000; i++) {
        if (isPalindromeDec(i) and isPalindromeBin(i)) {
            std::cout << i << " : " << toBinStr(i) << std::endl;
            answer += i;
        }
    }
    std::cout << "The answer is " << answer << "." << std::endl;
    return 0;
}
