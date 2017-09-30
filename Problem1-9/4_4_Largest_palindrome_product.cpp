#include <iostream>

void palindromicNumber();

int main() {
	palindromicNumber();
	return 0;
}

void palindromicNumber() {
	int result = 0;
	for (int i = 100; i < 1000;i++) {
		for (int j = i; j < 1000; j++) {
			int mul = i * j;
			if (result > mul) {
				continue;
			}
			if (mul >= 10000 && mul < 100000) { //5Œ…‚ÌŽž ABCBA
				if ((mul - mul % 10000) / 10000 == mul % 10) { //–œ‚ÌˆÊ‚Æˆê‚ÌˆÊ‚ªˆê’v
					int mul_temp = (mul - (mul % 10) * (10001)) / 10; //BCB
					if ((mul_temp - mul_temp % 100) / 100 == mul_temp % 10) { //ç‚ÌˆÊ‚Æ\‚ÌˆÊ‚ªˆê’v
						result = mul;
					}
				}
			} else if (mul >= 100000 &&  mul < 1000000) { //6Œ…‚ÌŽž ABCCBA
				if ((mul - mul % 100000) / 100000 == mul % 10) { //\–œ‚ÌˆÊ‚Æˆê‚ÌˆÊ‚ªˆê’v
					int mul_temp = (mul - (mul % 10) * (100001)) / 10; //BCCB
					if ((mul_temp - mul_temp % 1000) / 1000 == mul_temp % 10) { //–œ‚ÌˆÊ‚Æ\‚ÌˆÊ‚ªˆê’v
						int mul_tempo = mul_temp - (mul_temp % 10) * (1001); //CC
						if (mul_tempo % 11 == 0) {
							result = mul;
						}
					}
				}
			} else {
				std::cout << "invalid number" << std::endl;
			}
		}
	}

	std::cout << result << std::endl;
}
