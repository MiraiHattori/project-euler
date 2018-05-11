#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

template <typename T>
T factorial(T n)
{
    T result = 1;
    for (T i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

template <typename T>
T nCr(T n, T r)
{
    if (n < r) {
        std::cerr << "Value n has to be equal or greator than value r." << std::endl;
        return EXIT_FAILURE;
    }
    return factorial<T>(n) / factorial<T>(r) / factorial<T>(n - r);
}

int main()
{
    int result = 0;
    for (int n = 1; n <= 100; n++) {
        for (int r = 1; r <= n; r++) {
            if (nCr<boost::multiprecision::cpp_int>(n, r) > 1000000) {
                result++;
            }
        }
    }
    std::cout << result << std::endl;
    return 0;
}
