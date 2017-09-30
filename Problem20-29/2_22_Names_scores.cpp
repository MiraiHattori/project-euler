#include <iostream>
#include <fstream>
#include <stack>
#include <array>

std::stack<std::string> readFile();
bool is_right_bigger(std::string a, std::string b);
int worth(char letter);

class name_weight
{
public:
    std::string name;
    int number = 0;
    int weight;
};

int main()
{
    auto name_list = readFile();  //stack<string>型、名前を逆順で保管
    int list_size = (int)name_list.size();
    name_weight lists[list_size];
    for (int cnt1 = 0; cnt1 < list_size; cnt1++) {
        lists[cnt1].name = name_list.top();
        int temp = 0;
        for (int cnt2 = 0; cnt2 < (int)name_list.top().size(); cnt2++) {
            temp += worth(name_list.top().at(cnt2));
        }
        lists[cnt1].weight = temp;
        int seq = 0;
        for (int cnt3 = 0; cnt3 < cnt1; cnt3++) {
            if (is_right_bigger(lists[cnt1].name, lists[cnt3].name) == true) {
                seq++;
                lists[cnt3].number++;
            }
        }
        lists[cnt1].number = cnt1 - seq + 1;
        name_list.pop();
    }
    int kotae = 0;
    for (int cnt1 = 0; cnt1 < list_size; cnt1++) {
        kotae += lists[cnt1].number * lists[cnt1].weight;
    }
    std::cout << kotae << std::endl;
    return 0;
}

std::stack<std::string> readFile()
{
    std::ifstream ifs("p022_names.txt");
    if (ifs.fail()) {
        std::cout << "Can't read the file." << std::endl;
    }
    std::string str;
    ifs >> str;
    std::stack<std::string> names;
    std::string name;
    bool quote_started = false;
    for (int i = 0; i < (int)str.size(); i++) {
        if (str.at(i) == '"') {
            if (quote_started == false) {
                quote_started = true;
                name = "";
                continue;
            } else {
                names.push(name);
                quote_started = false;
            }
        } else {
            if (quote_started == true) {
                name.append(1, str.at(i));
            }
        }
    }
    return names;
}

bool is_right_bigger(std::string a, std::string b)
{
    if (a == b) {
        std::cout << "例外がis_right_biggerで発生" << std::endl;
    }
    int min_size_is;
    if (a.size() <= b.size()) {
        min_size_is = (int)a.size();
    } else {
        min_size_is = (int)b.size();
    }
    int i = 0;
    while (i < min_size_is) {
        if (worth((char)a.at(i)) < worth((char)b.at(i))) {
            return true;
        } else if (worth((char)a.at(i)) > worth((char)b.at(i))) {
            return false;
        } else if (worth((char)a.at(i)) == worth((char)b.at(i))) {
            i++;
            continue;
        }
    }
    if (min_size_is == (int)a.size()) {
        return true;
    } else {
        return false;
    }
    std::cout << "例外がis_right_biggerで発生" << std::endl;
    return 0;
}

int worth(char letter)
{
    if (letter == 'A') {
        return 1;
    } else if (letter == 'B') {
        return 2;
    } else if (letter == 'C') {
        return 3;
    } else if (letter == 'D') {
        return 4;
    } else if (letter == 'E') {
        return 5;
    } else if (letter == 'F') {
        return 6;
    } else if (letter == 'G') {
        return 7;
    } else if (letter == 'H') {
        return 8;
    } else if (letter == 'I') {
        return 9;
    } else if (letter == 'J') {
        return 10;
    } else if (letter == 'K') {
        return 11;
    } else if (letter == 'L') {
        return 12;
    } else if (letter == 'M') {
        return 13;
    } else if (letter == 'N') {
        return 14;
    } else if (letter == 'O') {
        return 15;
    } else if (letter == 'P') {
        return 16;
    } else if (letter == 'Q') {
        return 17;
    } else if (letter == 'R') {
        return 18;
    } else if (letter == 'S') {
        return 19;
    } else if (letter == 'T') {
        return 20;
    } else if (letter == 'U') {
        return 21;
    } else if (letter == 'V') {
        return 22;
    } else if (letter == 'W') {
        return 23;
    } else if (letter == 'X') {
        return 24;
    } else if (letter == 'Y') {
        return 25;
    } else if (letter == 'Z') {
        return 26;
    }
    std::cout << "例外がworthで発生" << std::endl;
    return 0;
}
