#include <iostream>


void sumOfEvenFibbonacciNumber(int maximum);

int main()
{
	sumOfEvenFibbonacciNumber(4000000);	
	return 0;
}

void sumOfEvenFibbonacciNumber(int maximum) {
	int an = 1;
	int anp1 = 2;
	int temp;
	int answer = 0;
	while (an <= maximum) {
		if (an % 2 == 0) {
			answer += an;
		}
		temp = an;
		an = anp1;
		anp1 += temp;
	}
	std::cout << answer << std::endl;
}
