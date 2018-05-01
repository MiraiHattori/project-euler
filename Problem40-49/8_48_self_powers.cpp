#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>


/*
 * last ten digits of 1^1 + 2^2 + ... + 1000^1000
 * Normally we need 1 + 2 + ... + 1000 = 500500 multiplication and 1000 - 1 summation. and mods
 */

namespace CppInt
{
namespace mp = boost::multiprecision;
using mint = mp::cpp_int;
mint pow(mint num, mint p)
{
    mint n = 1;
    for (mint i = 0; i < p; i++) {
        n *= num;
    }
    return n;
}
}  // namespace CppInt

int main()
{
    namespace mp = boost::multiprecision;
    using mint = mp::cpp_int;
    mint result = 0;
    for (mint i = 1; i <= 1000; i++) {
        result += CppInt::pow(i, i);
    }

    std::cout << (static_cast<mint>(result % 10000000000)).str() << std::endl;
    return 0;
}
