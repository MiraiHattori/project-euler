#!/usr/bin/env python3


def is_prime(num):
    for i in range(num):
        if i != 0 and i != 1 and num % i == 0:
            return False
    return True

with open("txt", "r") as f:
    for line in f:
        line = line.rstrip()
        print("{} {}".format(line, is_prime(int(line))))
