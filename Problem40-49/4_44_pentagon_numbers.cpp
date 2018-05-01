#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<long long> num_list;
    int i = 0;
    while (true) {
        i++;
        long long cand = i * (3 * i - 1) / 2;
        for (const long long& num : num_list) {
            std::vector<long long>::iterator itr = std::find(num_list.begin(), num_list.end(), cand - num);
            if (itr != num_list.end()) {
                std::vector<long long>::iterator itr2 = std::find(num_list.begin(), num_list.end(), cand - num - num);
                if (itr2 != num_list.end()) {
                    std::cout << num << " " << cand << " " << cand - num << " " << cand - num - num << std::endl;
                    std::cout << "The answer is " << cand - num - num << std::endl;
                    return 0;
                }
            }
        }
        num_list.emplace_back(cand);
    }
    return 0;
}
