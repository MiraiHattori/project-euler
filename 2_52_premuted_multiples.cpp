#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


std::vector<char> strToCharVector(const std::string str)
{
    std::vector<char> cs;
    for (const char& c : str) {
        cs.emplace_back(c);
    }
    return cs;
}

std::string charVectorToStr(const std::vector<char> cs)
{
    std::string str{};
    for (const char& c : cs) {
        str += c;
    }
    return str;
}


int main()
{
    while (true) {
        // 0 and 1 do not satisfy the situation.
        static int num = 2;
        num++;
        if (num % 1000000 == 0) {
            std::cout << "progress : " << num << std::endl;
        }
        std::vector<char> pre{};
        bool satisfied = true;
        for (const auto& mul : {1, 2, 3, 4, 5, 6}) {
            std::string s = std::to_string(num * mul);
            std::vector<char> cs = strToCharVector(s);
            std::sort(cs.begin(), cs.end());
            if (not pre.empty() and pre != cs) {
                satisfied = false;
                break;
            }
            pre = cs;
        }
        if (not satisfied) {
            continue;
        }
        std::cout << num << std::endl;
        break;
    }
    return 0;
}
