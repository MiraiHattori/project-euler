#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>


/*
1 + 1 / 2 = 3 / 2
1 + 1 / (1 + 3 / 2) = 1 + 1 / (5 / 2) = 1 + 2 / 5 = 7 / 5
1 + 1 / (1 + 7 / 5) = 1 + 1 / (12 / 5) = 1 + 5 / 12 = 17 / 12
1 + 1 / (1 + n / d) = 1 + 1 / ((d + n) / d) = 1 + d / (d + n) = (2 * d + n) / (d + n)
*/

int main()
{
    int result = 0;
    boost::multiprecision::cpp_int numerator = 3;
    boost::multiprecision::cpp_int denominator = 2;
    for (int i = 2; i <= 1000; i++) {
        boost::multiprecision::cpp_int numerator_copy = numerator;
        boost::multiprecision::cpp_int denominator_copy = denominator;
        numerator = 2 * denominator_copy + numerator_copy;
        denominator = denominator_copy + numerator_copy;
        if (numerator.str().size() > denominator.str().size()) {
            result++;
        }
    }
    std::cout << result << std::endl;
    return 0;
}
