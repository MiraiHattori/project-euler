#include <iostream>
#include <string>

std::string coutNumber(int n);

int main()
{
    int kotae = 0;
    for (int i = 1; i <= 1000;i++) {
        kotae += (int)coutNumber(i).size();
    }
    std::cout << kotae << std::endl;
    return 0;
}


std::string coutNumber(int n) {
    std::string result;
    switch (n / 100) {
        case 0:
            result = "";
            break;
        case 1:
            if (n % 100 != 0) {
                result = "onehundredand";
            } else {
                result = "onehundred";
            }
            break;
        case 2:
            if (n % 100 != 0) {
                result = "twohundredand";
            } else {
                result = "twohundred";
            }
            break;
        case 3:
            if (n % 100 != 0) {
                result = "threehundredand";
            } else {
                result = "threehundred";
            }
            break;
        case 4:
            if (n % 100 != 0) {
                result = "fourhundredand";
            } else {
                result = "fourhundred";
            }
            break;
        case 5:
            if (n % 100 != 0) {
                result = "fivehundredand";
            } else {
                result = "fivehundred";
            }
            break;
        case 6:
            if (n % 100 != 0) {
                result = "sixhundredand";
            } else {
                result = "sixhundred";
            }
            break;
        case 7:
            if (n % 100 != 0) {
                result = "sevenhundredand";
            } else {
                result = "sevenhundred";
            }
            break;
        case 8:
            if (n % 100 != 0) {
                result = "eighthundredand";
            } else {
                result = "eighthundred";
            }
            break;
        case 9:
            if (n % 100 != 0) {
                result = "ninehundredand";
            } else {
                result = "ninehundred";
            }
            break;
        case 10:
            result = "onethousand";
            break;
        default:
            std::cout << "Error1." << std::endl;
            break;
    }
    switch ((n % 100) / 10) {
        case 0:
            switch (n % 10) {
                case 0:
                    result += "";
                    break;
                case 1:
                    result += "one";
                    break;
                case 2:
                    result += "two";
                    break;
                case 3:
                    result += "three";
                    break;
                case 4:
                    result += "four";
                    break;
                case 5:
                    result += "five";
                    break;
                case 6:
                    result += "six";
                    break;
                case 7:
                    result += "seven";
                    break;
                case 8:
                    result += "eight";
                    break;
                case 9:
                    result += "nine";
                    break;
                default:
                    std::cout << "Error3." << std::endl;
                break;
            }
            break;
        case 1:
            switch (n % 10) {
                case 0:
                    result += "ten";
                    break;
                case 1:
                    result += "eleven";
                    break;
                case 2:
                    result += "twelve";
                    break;
                case 3:
                    result += "thirteen";
                    break;
                case 4:
                    result += "fourteen";
                    break;
                case 5:
                    result += "fifteen";
                    break;
                case 6:
                    result += "sixteen";
                    break;
                case 7:
                    result += "seventeen";
                    break;
                case 8:
                    result += "eighteen";
                    break;
                case 9:
                    result += "nineteen";
                    break;
                default:
                    std::cout << "Error4." << std::endl;
                    break;
            }
            break;
        case 2:
            result += "twenty";
            switch (n % 10) {
                case 0:
                    result += "";
                    break;
                case 1:
                    result += "one";
                    break;
                case 2:
                    result += "two";
                    break;
                case 3:
                    result += "three";
                    break;
                case 4:
                    result += "four";
                    break;
                case 5:
                    result += "five";
                    break;
                case 6:
                    result += "six";
                    break;
                case 7:
                    result += "seven";
                    break;
                case 8:
                    result += "eight";
                    break;
                case 9:
                    result += "nine";
                    break;
                default:
                    std::cout << "Error4." << std::endl;
                break;
            }
            break;
        case 3:
            result += "thirty";
            switch (n % 10) {
                case 0:
                    result += "";
                    break;
                case 1:
                    result += "one";
                    break;
                case 2:
                    result += "two";
                    break;
                case 3:
                    result += "three";
                    break;
                case 4:
                    result += "four";
                    break;
                case 5:
                    result += "five";
                    break;
                case 6:
                    result += "six";
                    break;
                case 7:
                    result += "seven";
                    break;
                case 8:
                    result += "eight";
                    break;
                case 9:
                    result += "nine";
                    break;
                default:
                    std::cout << "Error5." << std::endl;
                break;
            }
            break;
        case 4:
            result += "forty";
            switch (n % 10) {
                case 0:
                    result += "";
                    break;
                case 1:
                    result += "one";
                    break;
                case 2:
                    result += "two";
                    break;
                case 3:
                    result += "three";
                    break;
                case 4:
                    result += "four";
                    break;
                case 5:
                    result += "five";
                    break;
                case 6:
                    result += "six";
                    break;
                case 7:
                    result += "seven";
                    break;
                case 8:
                    result += "eight";
                    break;
                case 9:
                    result += "nine";
                    break;
                default:
                    std::cout << "Error6." << std::endl;
                break;
            }
            break;
        case 5:
            result += "fifty";
            switch (n % 10) {
                case 0:
                    result += "";
                    break;
                case 1:
                    result += "one";
                    break;
                case 2:
                    result += "two";
                    break;
                case 3:
                    result += "three";
                    break;
                case 4:
                    result += "four";
                    break;
                case 5:
                    result += "five";
                    break;
                case 6:
                    result += "six";
                    break;
                case 7:
                    result += "seven";
                    break;
                case 8:
                    result += "eight";
                    break;
                case 9:
                    result += "nine";
                    break;
                default:
                    std::cout << "Error7." << std::endl;
                break;
            }
            break;
        case 6:
            result += "sixty";
            switch (n % 10) {
                case 0:
                    result += "";
                    break;
                case 1:
                    result += "one";
                    break;
                case 2:
                    result += "two";
                    break;
                case 3:
                    result += "three";
                    break;
                case 4:
                    result += "four";
                    break;
                case 5:
                    result += "five";
                    break;
                case 6:
                    result += "six";
                    break;
                case 7:
                    result += "seven";
                    break;
                case 8:
                    result += "eight";
                    break;
                case 9:
                    result += "nine";
                    break;
                default:
                    std::cout << "Error8." << std::endl;
                break;
            }
            break;
        case 7:
            result += "seventy";
            switch (n % 10) {
                case 0:
                    result += "";
                    break;
                case 1:
                    result += "one";
                    break;
                case 2:
                    result += "two";
                    break;
                case 3:
                    result += "three";
                    break;
                case 4:
                    result += "four";
                    break;
                case 5:
                    result += "five";
                    break;
                case 6:
                    result += "six";
                    break;
                case 7:
                    result += "seven";
                    break;
                case 8:
                    result += "eight";
                    break;
                case 9:
                    result += "nine";
                    break;
                default:
                    std::cout << "Error9." << std::endl;
                break;
            }
            break;
        case 8:
            result += "eighty";
            switch (n % 10) {
                case 0:
                    result += "";
                    break;
                case 1:
                    result += "one";
                    break;
                case 2:
                    result += "two";
                    break;
                case 3:
                    result += "three";
                    break;
                case 4:
                    result += "four";
                    break;
                case 5:
                    result += "five";
                    break;
                case 6:
                    result += "six";
                    break;
                case 7:
                    result += "seven";
                    break;
                case 8:
                    result += "eight";
                    break;
                case 9:
                    result += "nine";
                    break;
                default:
                    std::cout << "Error10." << std::endl;
                break;
            }
            break;
        case 9:
            result += "ninety";
            switch (n % 10) {
                case 0:
                    result += "";
                    break;
                case 1:
                    result += "one";
                    break;
                case 2:
                    result += "two";
                    break;
                case 3:
                    result += "three";
                    break;
                case 4:
                    result += "four";
                    break;
                case 5:
                    result += "five";
                    break;
                case 6:
                    result += "six";
                    break;
                case 7:
                    result += "seven";
                    break;
                case 8:
                    result += "eight";
                    break;
                case 9:
                    result += "nine";
                    break;
                default:
                    std::cout << "Error11." << std::endl;
                break;
            }
            break;
    }

    return result;
}
