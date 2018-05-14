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
    std::string pass = "god";
    std::cout << "#############################  " << static_cast<char>(pass.at(0)) << std::endl;
    int sum = 0;
    for (std::size_t i = 0; i < encrypted.size(); i++) {
        std::cout << static_cast<char>(encrypted.at(i) ^ pass.at(i % 3));
        sum += static_cast<int>(encrypted.at(i) ^ pass.at(i % 3));
    }
    std::cout << std::endl;
    std::cout << "The answer is " << sum << std::endl;
    /*
    std::array<int, 128> histogram{};
    for (const auto& n : encrypted) {
        histogram.at(n)++;
    }
    for (int i = 0; i < 128; i++) {
        std::cout << i << " " << histogram.at(i) << std::endl;
    }
    */

    return 0;
}
