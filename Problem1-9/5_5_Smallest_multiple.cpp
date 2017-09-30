#include <iostream>
#include <stack>
#include <cmath>

void primeNumber(int number, int num);
void minimum(int max);

namespace seq {
    std::stack<int> seq;
}

int main()
{
	minimum(20);
	return 0;
}

void primeNumber(int number) {
	while(seq::seq.size() != 0) {
		seq::seq.pop();
	}
	if (number > 0 && number % 1 == 0) {
		if (number % 2 == 0) {
			seq::seq.push(2);
			int i = 0;
			while (number % 2 == 0) {
				number /= 2;
				i++;
			}
			//std::cout << 2 << "の" << i << "乗を因数に持ちます" << std::endl;
			seq::seq.push(i);
		}
		if (number % 3 == 0) {
			seq::seq.push(3);
		    int i = 0;
			while (number % 3 == 0) {
				number /= 3;
				i++;
			}
			//std::cout << 3 << "の" << i << "乗を因数に持ちます" << std::endl;
			seq::seq.push(i);
		}
		if (number % 5 == 0) {
			seq::seq.push(5);
			int i = 0;
			while (number % 5 == 0) {
				number /= 5;
				i++;
			}
			//std::cout << 5 << "の" << i << "乗を因数に持ちます" << std::endl;
			seq::seq.push(i);
		}
		int prime = 7;
		while (prime <= (int)sqrt(number)) {
			if (number % prime == 0) {
				seq::seq.push(prime);
				int i = 0;
				while (number % prime == 0) {
					number /= prime;
					i++;
				}
			    //std::cout << prime << "の" << i << "乗を因数に持ちます" << std::endl;
				seq::seq.push(i);
			}
			prime += 4;
			if (number % prime == 0) {
				seq::seq.push(prime);
				int i = 0;
				while (number % prime == 0) {
					number /= prime;
					i++;
				}
			    //std::cout << prime << "の" << i << "乗を因数に持ちます" << std::endl;
				seq::seq.push(i);
			}
			prime += 2;
		}
		if (prime <= number) {
			seq::seq.push(number);
			    //std::cout << number << "の" << 1 << "乗を因数に持ちます" << std::endl;
			seq::seq.push(1);
		}
	} else {
		//std::cout << "Invalid Number" << std::endl;
	}
}

void minimum(int max) {
	std::cout << "minimum" << std::endl;
	int result = 1;
	for (int i = 1; i <= max; i++) {
	    primeNumber(i);
        int size = (int)(seq::seq.size()) / 2;
        std::cout << "\n" << size<< "seqのサイズ" << std::endl;
		for (int j = 0; j < size; j++) {
			int times = seq::seq.top();
			seq::seq.pop();
			int kazu = seq::seq.top();
			seq::seq.pop();
            std::cout << kazu << "の" << times << "乗を評価" << std::endl;
            int temp = result;
			int k = 0;
			while (temp % kazu == 0) {
			    temp /= kazu;
				k++;
            }
            for (int cnt = 0; cnt < times - k; cnt++) {
                result *= kazu;
            }
	        std::cout << "result" << result << std::endl;
		}
	}
}
