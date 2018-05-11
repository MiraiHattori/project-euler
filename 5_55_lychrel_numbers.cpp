#include <boost/multiprecision/cpp_int.hpp>
#include <algorithm>
#include <iostream>
#include <string>
template <typename T>
bool isPalindrome(T num)
{
    std::string str = num.str();
    bool is_palindrome = true;
    for (std::size_t i = 0; i < str.size() / 2; i++) {
        if (str.at(i) != str.at(str.size() - i - 1)) {
            is_palindrome = false;
        }
    }
    return is_palindrome;
}

int main()
{
    int result = 0;
    for (int i = 1; i < 10000; i++) {
        bool is_lycherel = true;
        boost::multiprecision::cpp_int pre_num = i;
        boost::multiprecision::cpp_int next_num;
        for (int j = 0; j < 50; j++) {
            std::string num_s = pre_num.str();
            std::reverse(num_s.begin(), num_s.end());
            while (num_s.at(0) == '0') {
                num_s.erase(num_s.begin());
            }
            next_num = pre_num + boost::multiprecision::cpp_int(num_s);
            if (isPalindrome(next_num)) {
                is_lycherel = false;
                break;
            }
            pre_num = next_num;
        }
        if (is_lycherel) {
            result++;
        }
    }
    std::cout << result << std::endl;
    return 0;
}
