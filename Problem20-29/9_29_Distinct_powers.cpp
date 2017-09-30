#include <iostream>
#include <list>
#include <cmath>
#include <string>
#include <stack>
std::string largeSum(std::string a, std::string b);
int max(int a, int b);
std::string power(int a, int b);


int main()
{
    std::list<std::string> data;
    for (int i = 2; i <= 100; i++) {
        for (int j = 2; j <= 100; j++) {
            data.push_back(power(i, j));
            std::cout << "i : " << i << ", j : " << j << std::endl;
        }
    }
    data.sort();
    data.unique();
    for (auto it = data.begin(); it != data.end(); it++) {
        std::cout << *it << std::endl;
    }
    std::cout << "size" << data.size() << std::endl;
    return 0;
}


std::string largeSum(std::string a, std::string b)
{
    int a_size = (int)a.size();  //50になるはず
    int b_size = (int)b.size();  //50になるはず

    std::stack<int> a_number;
    if (a_size < b_size) {
        for (int i = 0; i < b_size - a_size; i++) {
            a_number.push(0);
        }
    }
    for (int i = 0; i < a_size; i++) {
        a_number.push((int)(a[i] - 48));  //整数値に変換
    }

    std::stack<int> b_number;
    if (b_size < a_size) {
        for (int i = 0; i < a_size - b_size; i++) {
            b_number.push(0);
        }
    }
    for (int i = 0; i < b_size; i++) {
        b_number.push((int)(b[i] - 48));
    }

    std::stack<int> result_temp;
    for (int i = 0; i < max(a_size, b_size) - 1; i++) {
        if (a_number.top() + b_number.top() < 10) {
            result_temp.push(a_number.top() + b_number.top());
            a_number.pop();
            b_number.pop();
        } else if (a_number.top() + b_number.top() >= 10) {
            result_temp.push(a_number.top() + b_number.top() - 10);
            a_number.pop();
            b_number.pop();
            int temp = a_number.top() + 1;
            a_number.pop();
            a_number.push(temp);
        }
    }
    if (a_number.top() + b_number.top() >= 10) {
        result_temp.push(a_number.top() + b_number.top() - 10);
        a_number.pop();
        b_number.pop();
        result_temp.push(1);
    } else {
        result_temp.push(a_number.top() + b_number.top());
        a_number.pop();
        b_number.pop();
    }
    int result_length = (int)result_temp.size();
    std::string result;
    for (int i = 0; i < result_length; i++) {
        result += std::to_string(result_temp.top());
        result_temp.pop();
    }
    return result;
}

int max(int a, int b)
{
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

std::string power(int a, int b)
{
    std::string answer = "1";
    for (int i = 0; i < b; i++) {
        std::string temp = answer;
        for (int j = 0; j < a - 1; j++) {
            answer = largeSum(temp, answer);
        }
    }
    return answer;
}
