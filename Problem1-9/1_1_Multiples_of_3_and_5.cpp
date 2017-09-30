#include <iostream>

int sum(int diff);

int main()
{
	std::cout << sum(3) + sum(5) - sum(15) << std::endl;
	return 0;
}

int sum(int diff) {
	int i = 0;
	int seq = 0;
	int tot_sum = 0;
	while (seq < 1000 - diff) {
		i++;
		seq += diff;
		tot_sum += seq;
	}
	return tot_sum;
}
