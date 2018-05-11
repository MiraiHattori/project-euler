#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <vector>

/*
    xor
        1 1 -> 0
        1 0 -> 1
        0 1 -> 1
        0 0 -> 0
    1000001
    xor
     101010
    =
    1101011

    1101011
    xor
     101010
    =
    1000001
*/

int main()
{
    std::ifstream ifs("p059_cipher.txt");
    std::string str;
    {
        std::string s;
        while (std::getline(ifs, s)) {
            if (s != "") {
                str = s;
            }
        }
    }
    std::vector<int> encrypted{};
    {
        std::string s;
        for (const auto& c : str) {
            if (c == ',') {
                encrypted.emplace_back(std::stoi(s));
                s = "";
            } else {
                s += c;
            }
        }
        encrypted.emplace_back(std::stoi(s));
        s = "";
    }
    //for (const auto& n : encrypted) {
    //std::cout << n << std::endl;
    //}
    std::array<int, 128> histogram{};
    for (const auto& n : encrypted) {
        histogram.at(n)++;
    }
    for (int i = 0; i < 128; i++) {
        std::cout << i << " " << histogram.at(i) << std::endl;
    }

    return 0;
}
