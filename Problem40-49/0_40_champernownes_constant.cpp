#include <iostream>
#include <string>

/*
 * 123456789101112131415161718192021...
 */
int ctoi(char c)
{
    switch (c) {
    case '0':
        return 0;
        break;
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    default:
        return 0;
        break;
    }
}

int main()
{
    std::string str{};
    for (int i = 1; str.size() < 1000000; i++) {
        str += std::to_string(i);
    }
    std::cout << str.at(1 - 1) << std::endl;
    std::cout << str.at(10 - 1) << std::endl;
    std::cout << str.at(100 - 1) << std::endl;
    std::cout << str.at(1000 - 1) << std::endl;
    std::cout << str.at(10000 - 1) << std::endl;
    std::cout << str.at(100000 - 1) << std::endl;
    std::cout << str.at(1000000 - 1) << std::endl;
    std::cout << "The answer is "
              << ctoi(str.at(1 - 1))
                     * ctoi(str.at(10 - 1))
                     * ctoi(str.at(100 - 1))
                     * ctoi(str.at(1000 - 1))
                     * ctoi(str.at(10000 - 1))
                     * ctoi(str.at(100000 - 1))
                     * ctoi(str.at(1000000 - 1))
              << "."
              << std::endl;
    return 0;
}
