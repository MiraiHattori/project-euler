#include <iostream>

#define MAX_SUM 200


int num_1p = 0;
int num_2p = 0;
int num_5p = 0;
int num_10p = 0;
int num_20p = 0;
int num_50p = 0;
int num_100p = 0;
int num_200p = 0;

int num = 0;

int sum()
{
    return num_1p * 1
           + num_2p * 2
           + num_5p * 5
           + num_10p * 10
           + num_20p * 20
           + num_50p * 50
           + num_100p * 100
           + num_200p * 200;
}

int main()
{
    while (sum() <= MAX_SUM) {
        while (sum() <= MAX_SUM) {
            while (sum() <= MAX_SUM) {
                while (sum() <= MAX_SUM) {
                    while (sum() <= MAX_SUM) {
                        while (sum() <= MAX_SUM) {
                            while (sum() <= MAX_SUM) {
                                while (sum() <= MAX_SUM) {
                                    while (sum() <= MAX_SUM) {
                                        if (sum() == MAX_SUM) {
                                            num++;
                                        }
                                        num_1p++;
                                    }
                                    num_1p = 0;
                                    num_2p++;
                                }
                                num_2p = 0;
                                num_5p++;
                            }
                            num_5p = 0;
                            num_10p++;
                        }
                        num_10p = 0;
                        num_20p++;
                    }
                    num_20p = 0;
                    num_50p++;
                }
            }
            num_50p = 0;
            num_100p++;
        }
        num_100p = 0;
        num_200p++;
    }

    std::cout << num << std::endl;

    return 0;
}
