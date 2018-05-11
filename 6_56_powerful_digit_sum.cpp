#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <string>

using bmint = boost::multiprecision::cpp_int;

int digitalSum(int a, int b)
{
    bmint power = 1;
    for (int i = 0; i < b; i++) {
        power *= a;
    }
    int result = 0;
    for (const auto& c : power.str()) {
        result += c - '0';
    }
    return result;
}

int main()
{
    std::array<int, 10000> sum;
    for (int a = 0; a < 100; a++) {
        for (int b = 0; b < 100; b++) {
            sum.at(a * 100 + b) = digitalSum(a, b);
        }
    }
    std::cout << *std::max_element(sum.begin(), sum.end()) << std::endl;
    return 0;
}
