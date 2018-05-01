#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int charToNum(char c)
{
    return int(c - 'A' + 1);
}


int main()
{
    std::string filename = "p042_words.txt";
    std::ifstream ifs(filename);
    if (not ifs) {
        std::cerr << "file " << filename << " open failed" << std::endl;
        std::exit(1);
    }
    std::string str;
    ifs >> str;
    // "は2回に1回ずつ単語の始まりを表す
    bool switch_bool = true;
    std::vector<std::string> word_list;
    for (unsigned int i = 0; i < str.size(); i++) {
        if (str.at(i) == '"' and switch_bool) {
            switch_bool = not switch_bool;
            // 単語の始まり
            word_list.emplace_back("");
        } else if (str.at(i) == '"' and not switch_bool) {
            switch_bool = not switch_bool;
        } else if (str.at(i) == ',') {
            // do nothing
        } else {
            word_list.at(word_list.size() - 1).push_back(str.at(i));
        }
    }
    unsigned long int max_length = 0;
    for (std::string str : word_list) {
        if (str.size() > max_length) {
            max_length = str.size();
        }
    }
    int max_num = charToNum('Z');
    int max_word_value = static_cast<int>(max_length) * max_num;
    int n = 1;
    std::vector<int> triangle_num_list;
    while (n * (n + 1) / 2 <= max_word_value) {
        triangle_num_list.emplace_back(n * (n + 1) / 2);
        n++;
    }
    int answer = 0;
    for (const std::string& str : word_list) {
        int sum = 0;
        for (const char& c : str) {
            sum += charToNum(c);
        }
        for (const int& num : triangle_num_list) {
            if (sum == num) {
                std::cout << str << " " << num << std::endl;
                answer++;
            }
        }
    }
    std::cout << "The answer is " << answer << "." << std::endl;
    return 0;
}
