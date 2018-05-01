#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

template <class T>
bool is_prime(const T n)
{
    if (n < 4)
        return n == 2 || n == 3;
    if (n % 2 == 0 || n % 3 == 0 || (n % 6 != 1 && n % 6 != 5))
        return false;
    for (T i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}


int main()
{
    boost::multiprecision::cpp_int a{"91394823428793401284302476871103"};
    std::cout << is_prime<boost::multiprecision::cpp_int>(a) << std::endl;
    return 0;
}
